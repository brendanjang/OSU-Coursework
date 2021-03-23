/***********************************************************************
 * Name:	Brendan Jang
 * File:	dec_server.c
 * Date:	08/04/2020
 * Description: Source code for dec_server.c. Performs like enc_server
 * in syntax and usage. Will decrypt ciphertext it is given. Returns
 * plaintext again to dec_client.
 **********************************************************************/
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <signal.h>
#include <error.h>
#include <errno.h>
#include <sys/wait.h>

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#include <time.h>

#define BUFFERSIZE 2000
#define TRUE 1
#define FALSE 0
#define SLEEPING_TIME 1

#define SEM_ID 250

void my_sleep(int milisec );

void sem_unlock(int sem_set_id);
void sem_lock(int sem_set_id);

void sig_child(int signo);

int init_sd(int myport);

int check_client_type(int sd);
int get_message_length(int sd);
char *get_message(int sd);

int charToInt(char ch);
char intToChar(int val);
char mix(char text, char key);
void decrypt(char *text, char *key);

int getALoad(char *buff, int start, char msg[]);
void send_message(int sd, char *text);
void do_service(int sd);

int main(int argc, char *argv[])
{	
	// connection
    struct sockaddr_in c_add;
    int base_sd, curr_sd;
    socklen_t addrlen;
    int myport;
    int err = 0;
	
	// forking
    int ch;
	
	// share memory
    int ShmID;
    int *ShmPTR;
	
	// semaphore
    int sem_set_id;
    union semun { /* semaphore value, for semctl().     */
        int val;
        struct semid_ds *buf;
        ushort *array;
    } sem_val;
    int rc; /* return value of system calls.      */

    int locking;

    if (argc < 2)
    {
        printf("usage: server <port>");
        return 0;
    }
	
	// set up connection
    myport = atoi(argv[1]);

    base_sd = init_sd(myport);
	
	// catch the exit signal of children and kill all zombies
    signal(SIGCHLD, sig_child);

	// set up shared memory so that all the processes can use the
	// common variable
    ShmID = shmget(IPC_PRIVATE, 1 * sizeof(int), IPC_CREAT | 0666);
    if (ShmID < 0)
    {
        fprintf(stderr, "shmget error \n");
        exit(1);
    }

    ShmPTR = (int *)shmat(ShmID, NULL, 0);
    if (!ShmPTR)
    {
        fprintf(stderr, "shmat error\n");
        exit(1);
    }

	// initialize the shared variable to 0
    *ShmPTR = 0;
	
	// set up semaphore
    sem_set_id = semget(SEM_ID, 1, IPC_CREAT | 0600);
    if (sem_set_id == -1)
    {
        fprintf(stderr, "main: semget");
        exit(1);
    }

    /* intialize the first (and single) semaphore in our set to '1'. */
    sem_val.val = 1;
    rc = semctl(sem_set_id, 0, SETVAL, sem_val);
    if (rc == -1)
    {
        fprintf(stderr, "main: semctl");
        exit(1);
    }
	
	// listen to incoming connection
    while (!err)
    {	
		// keep max number of concurrent connections to 5
        while (1 > 0)
        {
            sem_lock(sem_set_id);
            locking = (*ShmPTR);
            sem_unlock(sem_set_id);
            if (locking >= 5)
            {
                //printf("Stop locking %d\n", locking);
                //my_sleep(SLEEPING_TIME);
            }
            else
            {
                break;
            }
        }

		// accept conncetion
        curr_sd = accept(base_sd, (struct sockaddr *)(&c_add), &addrlen);
        if (curr_sd < 0)
        {
            fprintf(stderr, "accept failed!");
        }
        else
        {	
			// fork a child
            //printf("accept\n");
            ch = fork();
            if (ch == 0)
            {	
				// count up the number of processes
                //printf("Run locking %d pid %d\n", locking, getpid());
                sem_lock(sem_set_id);
                *ShmPTR = (*ShmPTR) + 1;
                sem_unlock(sem_set_id);
				
				// provide service
                do_service(curr_sd);
                close(curr_sd);
				
				// reduce the number of concurrent processes
                sem_lock(sem_set_id);
                *ShmPTR = (*ShmPTR) - 1;
                sem_unlock(sem_set_id);
                //printf("Stop pid %d\n", getpid());

                exit(0);
            }
        }
    }
	// close server socket
    close(base_sd);

    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);
    return 0;
}

/**
 * provide service
 * @param sd
 */
void do_service(int sd)
{
    int i, l = 1;
    char msg[BUFFERSIZE];

    if (check_client_type(sd) == FALSE)
    {
		// send bad message to client
        //printf("refuse\n");
        strcpy(msg, "2");
        write(sd, msg, strlen(msg));
        return;
    }

	// send good message to client
    //printf("ok\n");
    strcpy(msg, "0");
    write(sd, msg, strlen(msg));
	
	// get text
    char *text = get_message(sd);
	
	// get pw
    char *key = get_message(sd);
	
	// decrypt
    // printf("text: %s--\n\n", text);
    // printf("key: %s--\n\n", key);
    decrypt(text, key);
	
	// send it back to the client
    send_message(sd, text);

    //free(key);
    //free(text);
}

/**
 * send message away
 * @param sd socket fd
 * @param buff the text
 */
void send_message(int sd, char *buff)
{
    char msg[BUFFERSIZE];
    int l;
    int index = 0;
    int size = strlen(buff);
	
	// sleep to prevent data conflcit
    my_sleep(SLEEPING_TIME);
	
	// send the size of the text
    sprintf(msg, "%d", size);
    write(sd, msg, strlen(msg));

	// sleep to prevent data conflict
    my_sleep(SLEEPING_TIME);

	// get response message
    l = read(sd, msg, BUFFERSIZE - 1);
    msg[l] = 0;

	// sleep to prevent data conflict
    my_sleep(SLEEPING_TIME);
    while (index < size)
    {
     	// get a chunk of the thext   
        index = getALoad(buff, index, msg);
        //printf("sending: %s\n\n", msg);
		//send it away
        write(sd, msg, strlen(msg));
    }
	// sleep
    my_sleep(SLEEPING_TIME);
}

/**
 * get a chunk of the text
 * @param buff the text
 * @param start start index
 * @param msg place to store that chunk of text
 * @return the next starting index
 */
int getALoad(char *buff, int start, char msg[])
{
    int index = start;
    int size = strlen(buff);
    size_t i;
    for (i = 0; i < BUFFERSIZE - 1 && index < size; i++)
    {
        msg[i] = buff[index];
        index++;
    }
    msg[i] = 0;
    return index;
}

/**
 * decrypt the text
 * @param text
 * @param key
 */
void decrypt(char *text, char *key)
{
    int size = strlen(text);
    int i;
    for (i = 0; i < size; i++)
    {
		// decrypt each letter in the text
        text[i] = mix(text[i], key[i]);
    }
}

/**
 * decrypt a character
 * @param text the text
 * @param key the key
 * @return the result
 */
char mix(char text, char key)
{
    int t = charToInt(text);
    int k = charToInt(key);
    int result = (t - k);
    if (result < 0)
    {
        result += 27;
    }

    return intToChar(result);
}

/**
 * conver from int to char
 * @param val a legal int
 * @return a legal char
 */
char intToChar(int val)
{
    if (val == 26)
    {
        return ' ';
    }
    return 'A' + val;
}

/**
 * convert a character to int
 * @param a legal char
 * @return a legal int
 */
int charToInt(char ch)
{
    if (ch == ' ')
    {
        return 26;
    }
    return ch - 'A';
}

/**
 * get a message from client
 * @param sd socket fd
 * @return a text
 */
char *get_message(int sd)
{
    int i, l = 1;
    char msg[BUFFERSIZE];
	
	// get size of the text
    int size = get_message_length(sd);
    //printf("size %d\n", size);
	//send back a message to confirm
    sprintf(msg, "%d", size);
    write(sd, msg, strlen(msg));
	
	// bad case
    if (size <= 0)
    {
        return NULL;
    }
	
	// allocate memory
    char *text = (char *)calloc(size, sizeof(char));
    int index = 0;
	
	// get each chunk of text then put them together
    while (index < size)
    {
        //printf("from %d\n", index);
        l = read(sd, msg, BUFFERSIZE - 1);
        if (l == 0)
        {
            //printf("l = 0\n");
            break;
        }
        msg[l] = 0;
        // printf("getting:  %s\n", msg);
        for (i = 0; i < l; i++)
        {
            text[index] = msg[i];
            index++;
        }
    }
	// mark end of text
    text[index] = 0;
    return text;
}

/**
 * get message length
 * @param sd socket file descriptor
 * @return size of the message
 */
int get_message_length(int sd)
{
    int l = 1;
    char msg[BUFFERSIZE];
    l = read(sd, msg, BUFFERSIZE - 1);
    if (l == 0)
        return 0;
    msg[l] = 0;
    //printf("%s\n", msg);
    return atoi(msg);
}

/**
 * check type of the client
 * @paran sd sock_fd
 * @return true if the client is the right one
 */
int check_client_type(int sd)
{
    int l = 1;
    char msg[BUFFERSIZE];
    l = read(sd, msg, BUFFERSIZE - 1);
    if (l == 0)
        return FALSE;
    msg[l] = 0;
    //printf("%s\n", msg);
    char client_type[] = "DEC";
    if (strcmp(msg, client_type) == 0)
    {
        return TRUE;
    }
    return FALSE;
}

int init_sd(int myport)
{
    struct sockaddr_in my_addr;
    int sd;
    int opt = 1;
    bzero(&my_addr, sizeof(struct sockaddr_in));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(myport);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    sd = socket(AF_INET, SOCK_STREAM, 0);

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR,
                   &opt, sizeof(opt)))
    {
        fprintf(stderr, "setsockopt");
        exit(1);
    }

    if (bind(sd, (struct sockaddr *)(&my_addr), sizeof(my_addr)) < 0)
    {
        fprintf(stderr, "bind failed!");
        exit(1);
    }
    if (listen(sd, 5) < 0)
    {
        fprintf(stderr, "listen failed!");
        exit(1);
    }

    //printf("Server listening on port %d\n", myport);
    return sd;
}

void sig_child(int signo)
{
    pid_t pid;
    int stat;
    while ((pid = waitpid(-1, &stat, WNOHANG)) > 0)
    {
        //printf("Child %d has fnished\n", pid);
    }
}

void sem_lock(int sem_set_id)
{
    /* structure for semaphore operations.   */
    struct sembuf sem_op;

    /* wait on the semaphore, unless it's value is non-negative. */
    sem_op.sem_num = 0;
    sem_op.sem_op = -1;
    sem_op.sem_flg = 0;
    semop(sem_set_id, &sem_op, 1);
}

void sem_unlock(int sem_set_id)
{
    /* structure for semaphore operations.   */
    struct sembuf sem_op;

    /* signal the semaphore - increase its value by one. */
    sem_op.sem_num = 0;
    sem_op.sem_op = 1;
    sem_op.sem_flg = 0;
    semop(sem_set_id, &sem_op, 1);
}

void my_sleep(int milisec ){
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = milisec * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
}
