/***************************************************************
** File: smallsh.c
** Name: Brendan Jang
** Date: 07/21/2020
** Description: Main implementation file for smallsh.
****************************************************************/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

#define BUFFER 2048

int backg = 1;

void cmd_input(char* [], int*, char[], char[], int);
void run_cmd(char* [], int*, struct sigaction, int*, char[], char[]);
void catch_SIGTSTP(int);
void show_status(int);

int main() {

    // Declare necessary variables
    int pid = getpid();
    int val = 1;
    int status, bg, i = 0;
    char inFile[256] = "";
    char outFile[256] = "";
    char* input[512];

    // initialize elements of declared array with null
    for (i = 0; i < 512; i++) {
        input[i] = NULL;
    }

    // Signal handlers structure referenced from modules
    // Ignore Ctrl - C
    // Transfer CTRL - Z to catch_SIGTSTP
    struct sigaction SIGINT_action = { 0 }, SIGTSTP_action = { 0 };

    SIGINT_action.sa_handler = SIG_IGN;
    SIGINT_action.sa_flags = 0;
    sigfillset(&SIGINT_action.sa_mask);
    sigaction(SIGINT, &SIGINT_action, NULL);

    SIGTSTP_action.sa_handler = catch_SIGTSTP;
    SIGTSTP_action.sa_flags = 0;
    sigfillset(&SIGTSTP_action.sa_mask);
    sigaction(SIGTSTP, &SIGTSTP_action, NULL);

    do {
        // call input function to get user input
        cmd_input(input, &bg, inFile, outFile, pid);

        // if user input is # or blank do nothing
        if (input[0][0] == '#' || input[0][0] == '\0') {
            continue;
        }

        // if user inputs cd command
        else if (strcmp(input[0], "cd") == 0) {
            // change directory to user specified directory
            if (input[1]) {
                if (chdir(input[1]) == -1) {
                    printf("Directory not found.\n");
                    fflush(stdout);
                }
            }
            else {
                // default to ~ if no directory specified
                chdir(getenv("HOME"));
            }
        }

        // if user inputs status command
        else if (strcmp(input[0], "status") == 0) {
            show_status(status);
        }

        // if user inputs exit command
        else if (strcmp(input[0], "exit") == 0) {
            val = 0;
        }

        // if user inputs any other command
        else {
            run_cmd(input, &status, SIGINT_action, &bg, inFile, outFile);
        }

        // reset variables 0
        for (i = 0; input[i]; i++) {
            input[i] = NULL;
        }
        bg = 0;
        inFile[0] = '\0';
        outFile[0] = '\0';
    } 
    while (val);
    return 0;
}


/**************************************************************
** Prompt the user for input and parse their response into arr.
** @param arr
** @param bg
** @param in
** @param out
** @param pid
** @return none
***************************************************************/

void cmd_input(char* arr[], int* bg, char in[], char out[], int pid) {

    char input[BUFFER];
    const char s[2] = " ";
    char* token;

    // First we get input from user and then get rid of the newline char.
    printf(": ");
    fflush(stdout);
    fgets(input, BUFFER, stdin);
    int i, j;
    int num = 0;
    for (i = 0; i < BUFFER && !num; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            num = 1;
        }
    }

    // We return nothing if the user input is nothing
    if (!strcmp(input, "")) {
        arr[0] = strdup("");
        return;
    }

    // Disassemble the string into series of strings referenced from
    // https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
    token = strtok(input, s);
    for (i = 0; token; i++) {
        // Check the necessary characters (&, <, and >) for proper functionality.
        // & should be background process, < implies source file, and 
        //> implies target file
        if (!strcmp(token, "&")) {
            *bg = 1;
        }
        else if (!strcmp(token, "<")) {
            token = strtok(NULL, s);
            strcpy(in, token);
        }
        else if (!strcmp(token, ">")) {
            token = strtok(NULL, s);
            strcpy(out, token);
        } else {
            arr[i] = strdup(token);
            // Make $$ show pid
            for (j = 0; arr[i][j]; j++) {
                if (arr[i][j] == '$' && arr[i][j + 1] == '$') {
                    arr[i][j] = '\0';
                    snprintf(arr[i], 256, "%s%d", arr[i], pid);
                }
            }
        }
        token = strtok(NULL, s);
    }
}

/**************************************************************
** Runs the command that has been parsed into array arr.
** @param arr
** @param exit_status
** @param sig_action
** @param bg
** @param in
** @param out
** @return none
***************************************************************/

void run_cmd(char* arr[], int* exit_status, struct sigaction sig_action, int* bg, char in[], char out[]) {
    int sourceFD, targetFD;

    // Fork structure referenced from modules
    pid_t spawnPid = fork();
    switch (spawnPid) {
        case -1:
            perror("fork() failed!");
            exit(1);
            break;

        case 0:
            sig_action.sa_handler = SIG_DFL;
            sigaction(SIGINT, &sig_action, NULL);

            // Handling source and target files referenced from modules
            if (strcmp(in, "")) {
                sourceFD = open(in, O_RDONLY);
                if (sourceFD == -1) {
                    perror("No such file or directory\n");
                    exit(1);
                }
                int result = dup2(sourceFD, 0);
                if (result == -1) {
                    perror("Unable to assign source file\n");
                    exit(2);
                }
                // Close
                fcntl(sourceFD, F_SETFD, FD_CLOEXEC);
            }

            if (strcmp(out, "")) {
                targetFD = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (targetFD == -1) {
                    perror("No such file or directory\n");
                    exit(1);
                }
                int result = dup2(targetFD, 1);
                if (result == -1) {
                    perror("Unable to assign target file\n");
                    exit(2);
                }
                // Close
                fcntl(targetFD, F_SETFD, FD_CLOEXEC);
            }

            // Run
            if (execvp(arr[0], (char* const*)arr)) {
                printf("%s: no such file or directory\n", arr[0]);
                fflush(stdout);
                exit(2);
            }
            break;

        default:
            // Process allowed on the background only if backg
            if (*bg && backg) {
                pid_t rPid = waitpid(spawnPid, exit_status, WNOHANG);
                printf("background pid is %d\n", spawnPid);
                fflush(stdout);
            }
            else {
                // If not backg
                pid_t rPid = waitpid(spawnPid, exit_status, 0);
            }
            // Check for any background processes that may be termianted.
        while ((spawnPid = waitpid(-1, exit_status, WNOHANG)) > 0) {
            printf("child %d terminated\n", spawnPid);
            show_status(*exit_status);
            fflush(stdout);
        }
    }
}

/**************************************************************
** Set backg to opposite of what it is currently set to and
** display proper message.
** @param signo
** @return none
***************************************************************/

void catch_SIGTSTP(int signo) {

    // If backg == 1
    if (backg == 1) {
        char* msg = "\nEntering foreground-only mode (& is now ignored)\n";
        write(1, msg, 49);
        fflush(stdout);
        backg = 0;
    }
    else {
        // If backg == 0
        char* msg = "\nExiting foreground-only mode\n";
        write(1, msg, 29);
        fflush(stdout);
        backg = 1;
    }
}

/**************************************************************
** Dispaly the exit status to console.
** @param status
** @return none
***************************************************************/

void show_status(int status) {
    if (WIFEXITED(status)) {
        printf("exit value %d\n", WEXITSTATUS(status));
    }
    else {
        printf("termianted by signal %d\n", WTERMSIG(status));
    }
}
