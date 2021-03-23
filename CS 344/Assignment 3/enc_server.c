/******************************************************************
 * Name:	Brendan Jang
 * File:	enc_server.c
 * Date:	08/04/2020
 * Description: Source code for enc.server.c. Its function is to
 * perform the actual encoding. Comments may be sparse due to
 * similarities to other source files.*
 ******************************************************************/

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

// function prototypes
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
void encrypt(char *text, char *key);

int getALoad(char *buff, int start, char msg[]);
void send_message(int sd, char *text);
void do_service(int sd);

int main(int argc, char *argv[])
{
    struct sockaddr_in c_add;
    int base_sd, curr_sd;
    socklen_t addrlen;
    int myport;
    int err = 0;
    int ch;

    int ShmID;
    int *ShmPTR;

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

    myport = atoi(argv[1]);

    base_sd = init_sd(myport);

    signal(SIGCHLD, sig_child);

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
    *ShmPTR = 0;

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

    while (!err)
    {
        while (1 > 0)
        {
            sem_lock(sem_set_id);
            locking = (*ShmPTR);
            sem_unlock(sem_set_id);
            if (locking >= 5)
            {
                //printf("Stop locking %d\n", locking);
                //my_sleep(SLEEPING_TIME);
            } else{
                break;
            }
        }
        curr_sd = accept(base_sd, (struct sockaddr *)(&c_add), &addrlen);
        if (curr_sd < 0)
        {
            fprintf(stderr, "accept failed!");
        }
        else
        {
            //printf("accept\n");
            ch = fork();
            if (ch == 0)
            {
                //printf("Run locking %d pid %d\n", locking, getpid());
                sem_lock(sem_set_id);
                *ShmPTR = (*ShmPTR) + 1;
                sem_unlock(sem_set_id);

                do_service(curr_sd);
                close(curr_sd);

                sem_lock(sem_set_id);
                *ShmPTR = (*ShmPTR) - 1;
                sem_unlock(sem_set_id);
                //printf("Stop pid %d\n", getpid());

                exit(0);
            }
        }
    }
    close(base_sd);

    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);
    return 0;
}

void do_service(int sd)
{
    int i, l = 1;
    char msg[BUFFERSIZE];

    if (check_client_type(sd) == FALSE)
    {
        //printf("refuse\n");
        strcpy(msg, "2");
        write(sd, msg, strlen(msg));
        return;
    }
    //printf("ok\n");
    strcpy(msg, "0");
    write(sd, msg, strlen(msg));

    char *text = get_message(sd);

    char *key = get_message(sd);

    // printf("text: %s--\n\n", text);
    // printf("key: %s--\n\n", key);
    encrypt(text, key);

    send_message(sd, text);

    // free(key);
    // free(text);
}

void send_message(int sd, char *buff)
{
    char msg[BUFFERSIZE];
    int l;
    int index = 0;
    int size = strlen(buff);

    my_sleep(SLEEPING_TIME);
    sprintf(msg, "%d", size);
    write(sd, msg, strlen(msg));
    my_sleep(SLEEPING_TIME);
    l = read(sd, msg, BUFFERSIZE - 1);
    msg[l] = 0;
    my_sleep(SLEEPING_TIME);

    while (index < size)
    {
        
        index = getALoad(buff, index, msg);
        //printf("sending: %s\n\n", msg);
        write(sd, msg, strlen(msg));
    }
    my_sleep(SLEEPING_TIME);
}

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

void encrypt(char *text, char *key)
{
    int size = strlen(text);
    int i;
    for (i = 0; i < size; i++)
    {
        text[i] = mix(text[i], key[i]);
    }
}

char mix(char text, char key)
{
    int t = charToInt(text);
    int k = charToInt(key);
    int result = (t + k) % 27;
    return intToChar(result);
}

char intToChar(int val)
{
    if (val == 26)
    {
        return ' ';
    }
    return 'A' + val;
}

int charToInt(char ch)
{
    if (ch == ' ')
    {
        return 26;
    }
    return ch - 'A';
}

char *get_message(int sd)
{
    int i, l = 1;
    char msg[BUFFERSIZE];

    int size = get_message_length(sd);
    //printf("size %d\n", size);
    sprintf(msg, "%d", size);
    write(sd, msg, strlen(msg));

    if (size <= 0)
    {
        return NULL;
    }

    char *text = (char *)calloc(size, sizeof(char));
    int index = 0;

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
    text[index] = 0;
    return text;
}

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

int check_client_type(int sd)
{
    int l = 1;
    char msg[BUFFERSIZE];
    l = read(sd, msg, BUFFERSIZE - 1);
    if (l == 0)
        return FALSE;
    msg[l] = 0;
    //printf("%s\n", msg);
    char client_type[] = "ENC";
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

    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
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
    if (listen(sd, 6) < 0)
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
