/*******************************************************************
 * Name:	Brendan Jang
 * Date:	enc_client.c
 * Date:	08/04/2020
 * Description: This program connects to enc_server and asks it to
 * perform one time pad style encryption. Comments may be sparse
 * due to similarities with other source files.
 ******************************************************************/

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
#define MARK "ENC"
#define SLEEPING_TIME 1

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
    if (argc < 4)
    {
        fprintf(stderr, "enc_client plaintext key port\n");
        return 1;
    }

    char *text = readFile(argv[1]);
    if (text == NULL)
    {
        fprintf(stderr, "enc_client error: invalid input\n");
        exit(1);
    }
    char *key = readFile(argv[2]);
    if (key == NULL)
    {
        fprintf(stderr, "enc_client error: invalid key\n");
        // free(text);
        exit(1);
    }

    if (strlen(text) > strlen(key))
    {
        fprintf(stderr, "Error: key '%s' is too short\n", argv[2]);
        // free(text);
        // free(key);
        exit(1);
    }
    // enc_client error: input contains bad characters

    if (bad_character(text) == 1)
    {
        fprintf(stderr, "enc_client error: input contains bad characters\n");
        // free(text);
        // free(key);
        exit(1);
    }

    int s_port = atoi(argv[3]);
    int sd = init_sockfd(s_port);

    checking(sd);

    sending(sd, text);
    sending(sd, key);

    char *result = get_message(sd);

    fprintf(stdout, "%s\n", result);

    // free(text);
    // free(key);
    // free(result);

    close(sd);
    return 0;
}

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

char *get_message(int sd)
{
    int i, l = 1;
    char msg[BUFFERSIZE];

    int size = get_message_length(sd);
    // printf("size %d\n", size);
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
            printf("l = 0\n");
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
    // printf("%s\n", msg);
    return atoi(msg);
}

void sending(int sd, char *buff)
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

void checking(int sd)
{
    char msg[BUFFERSIZE];
    int l;
    sprintf(msg, "%s", MARK);
    write(sd, msg, strlen(msg));
    my_sleep(SLEEPING_TIME);
    l = read(sd, msg, BUFFERSIZE - 1);
    msg[l] = 0;
    if (msg[0] == '2')
    {
        close(sd);
        exit(2);
    }
    my_sleep(SLEEPING_TIME);
}

char *readFile(char *file)
{
    FILE *infile = fopen(file, "r");
    if (infile == NULL)
    {
        return NULL;
    }

    fseek(infile, 0L, SEEK_END);
    int numbytes = ftell(infile);

    fseek(infile, 0L, SEEK_SET);

    char *buffer = (char *)calloc(numbytes, sizeof(char));

    if (buffer == NULL)
    {
        fclose(infile);
        return NULL;
    }
    fread(buffer, sizeof(char), numbytes, infile);
    fclose(infile);
    buffer[numbytes - 1] = 0;
    return buffer;
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
