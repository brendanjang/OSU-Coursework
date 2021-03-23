/*********************************************************************
 * Name:	Brendan Jang
 * File:	dec_client.c
 * Date:	08/04/2020
 * Description:	Source code for dec_client.c. Will connect to dec_server
 * and will ask it to decrypt ciphertext using parsed in text and key.
 * Similar to enc_client so comments may be redundant and sparse.
 ********************************************************************/

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <netdb.h>

#include <time.h>

#define BUFFERSIZE 2000
#define MARK "DEC"
#define SLEEPING_TIME 1


void my_sleep(int milisec );
int init_sockfd(int s_port);
char *readFile(char *file);
int getALoad(char *buff, int start, char msg[]);

void checking(int sd);
void sending(int sd, char *text);

int get_message_length(int sd);
char *get_message(int sd);

int bad_character(char *buff);

int main(int argc, char *argv[])
{
	// check number of args
    if (argc < 4)
    {
        fprintf(stderr, "enc_client plaintext key port\n");
        return 1;
    }
	
	// get the text
    char *text = readFile(argv[1]);

	// check for bad text file
    if (text == NULL)
    {
        fprintf(stderr, "dec_client error: invalid input\n");
        exit(1);
    }
	
	
	// check for bad key file
    char *key = readFile(argv[2]);
    if (key == NULL)
    {
        fprintf(stderr, "dec_client error: invalid key\n");
        // free(text);
        exit(1);
    }
	
	// check for bad key length
    if (strlen(text) > strlen(key))
    {
        fprintf(stderr, "Error: key '%s' is too short\n", argv[2]);
        // free(text);
        // free(key);
        exit(1);
    }
	
	// check for bad text
    if (bad_character(text) == 1)
    {
        fprintf(stderr, "dec_client error: input contains bad characters\n");
        // free(text);
        // free(key);
        exit(1);
    }
	
	// get a port
    int s_port = atoi(argv[3]);

	// set up socket
    int sd = init_sockfd(s_port);
	
	// check for the right server
    checking(sd);    
	
	// send text and key away
    sending(sd, text);
    sending(sd, key);
	
	// get result back
    char * result = get_message(sd);
	
	// show results on screen
    printf("%s\n", result);

    // free(text);
    // free(key);
    // free(result);

    close(sd);
}

/**
 *
 * @param buff
 * #return 0 if the text is legal
 */
int bad_character(char *buff)
{
    int size = strlen(buff);
    int i;
    char ch;
    int val;
    for (i = 0; i < size; i++)
    {
        ch = buff[i];
        if (ch != ' ')
        {
            val = ch - 'A';
            if (val < 0 || val > 25)
            {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * get message from server
 * @param sd
 * @return
 */
char *get_message(int sd)
{
    int i, l = 1;
    char msg[BUFFERSIZE];
	
	// get size of message
    int size = get_message_length(sd);
    // printf("size %d\n", size);
	// send a message back to confirm the delivery
    sprintf(msg, "%d", size);
    write(sd, msg, strlen(msg));
	
	// bad acase
    if (size <= 0)
    {
        return NULL;
    }
	
	// allocate memory
    char *text = (char *)calloc(size, sizeof(char));
    int index = 0;
	
	// get chucks of text and put them together
    while (index < size)
    {	
		// get a chunk
        //printf("from %d\n", index);
        l = read(sd, msg, BUFFERSIZE - 1);
        if (l == 0)
        {
            printf("l = 0\n");
            break;
        }
        msg[l] = 0;
		// put them together
        // printf("getting:  %s\n", msg);
        for (i = 0; i < l; i++)
        {
            text[index] = msg[i];
            index++;
        }
    }
	// mark the end of the text
    text[index] = 0;
    return text;
}

/**
 * get length of the message
 * @param sd
 * @return
 */
int get_message_length(int sd)
{
    int l = 1;
    char msg[BUFFERSIZE];

	// get a message
    l = read(sd, msg, BUFFERSIZE - 1);

	// bad case
    if (l == 0)
        return 0;
	// mark its end
    msg[l] = 0;
    // printf("%s\n", msg);
	// convert it to a number
    return atoi(msg);
}
/**
 * send text away
 * @param sd sock_fd
 * @param buff the text
 */
void sending(int sd, char *buff)
{
    char msg[BUFFERSIZE];
    int l;
    int index = 0;
    int size = strlen(buff);
	
	// sleep to prevent data conflict
    my_sleep(SLEEPING_TIME);

	// send size of the message
    sprintf(msg, "%d", size);
    write(sd, msg, strlen(msg));

	// sleep to avoid conflict
    my_sleep(SLEEPING_TIME);
    l = read(sd, msg, BUFFERSIZE - 1);
    msg[l] = 0;

	// sleep to avoid data conflcit
    my_sleep(SLEEPING_TIME);

	// send each chunk of the text
    while (index < size)
    {        
        index = getALoad(buff, index, msg);
        //printf("sending: %s\n\n", msg);
        write(sd, msg, strlen(msg));        
    }
    my_sleep(SLEEPING_TIME);
}

/**
 * check the other end
 * to be sure that it's the right companion
 * @param sd
 */
void checking(int sd)
{
    char msg[BUFFERSIZE];
    int l;

	// send the mark
    sprintf(msg, "%s", MARK);
    write(sd, msg, strlen(msg));

	// sleep to prevent data conflict
    my_sleep(SLEEPING_TIME);

	// get response
    l = read(sd, msg, BUFFERSIZE - 1);
    msg[l] = 0;

	// bad case
    if (msg[0] == '2')
    {
        close(sd);
        exit(2);
    }
	// sleep to prevent data conflict
    my_sleep(SLEEPING_TIME);
}

/**
 * read file from disk
 * @param file file name
 * @return content of the file
 */
char *readFile(char *file)
{
    FILE *infile = fopen(file, "r");
    if (infile == NULL)
    {
        return NULL;
    }
	
	// get size of file
    fseek(infile, 0L, SEEK_END);
    int numbytes = ftell(infile);

    fseek(infile, 0L, SEEK_SET);
	
	// allocate memory
    char *buffer = (char *)calloc(numbytes, sizeof(char));

    if (buffer == NULL)
    {
        fclose(infile);
        return NULL;
    }

	// read all content of the file into the buffer
    fread(buffer, sizeof(char), numbytes, infile);
    fclose(infile);

	// remove the last character which is the new line character
    buffer[numbytes - 1] = 0;
    return buffer;
}

/**
 * get a chunk of the text
 * @param buff the text
 * @param start start index
 * @param msg place to store the chunk
 * @return index of the next start
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
 * set up connection
 * @param s_port
 * @return
 */
int init_sockfd(int s_port)
{
    struct sockaddr_in s_addr;
    struct hostent *server;
    int sd;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&s_addr, sizeof(struct sockaddr_in));
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(s_port);
    server = gethostbyname("127.0.0.1");

    /**
     * https://www.gnu.org/software/libc/manual/html_node/Host-Names.html
     */
    bcopy((char *)server->h_addr_list[0], (char *)&s_addr.sin_addr.s_addr,
          server->h_length);
    if (connect(sd, (struct sockaddr *)(&s_addr),
                sizeof(struct sockaddr_in)) < 0)
    {
        fprintf(stderr, "connect failed!");
        exit(1);
    }
    return sd;
}

void my_sleep(int milisec ){
    struct timespec req = {0};
    req.tv_sec = 0;
    req.tv_nsec = milisec * 1000000L;
    nanosleep(&req, (struct timespec *)NULL);
}
