
/* 
 * File:   buildrooms.c
 * Author: Brendan Jang
 * Date:   07/07/2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <string.h>
#include <stdbool.h>
#include <wchar.h>

#define STUDENT_ID "jangb"

#define MIN_RAND_VAL 0
#define MAX_RAND_VAL 100000

#define MAX_DIRECTORY_NAME_LENGTH 128

#define MAX_ROM_NAME_LENGTH 9
#define MAX_ROM_TYPE_LENGTH 13

#define ROOM_NAME_NUM 10
#define ROOM_NUM 7

#define MIN_BOUND 3
#define MAX_BOUND 6

/**
 * room structure 
 */
struct Room {
    char name[MAX_ROM_NAME_LENGTH];
    char type[MAX_ROM_TYPE_LENGTH];
    struct Room * adj[MAX_BOUND];
    int bound_num;
};
typedef struct Room Room;


/**
 * get a random number
 * @param min min value
 * @param max max value
 * @return a random number
 */
int random_number(int min, int max);

/**
 * create a directory name
 * @param a_random_number a number
 * @return a new string
 */
char * directory_name(int a_random_number);

/**
 * create a directory
 * @param a_directory_name
 */
void create_diretory(char * a_directory_name);

/**
 * hard code name of 10 rooms
 * @param rooms
 */
void hard_code_room_name(char ** rooms);

/**
 * free all allocated memory of name of rooms
 * @param rooms
 */
void free_all_room_name(char ** rooms);

/**
 * write a room to file
 * @param room
 * @param stream
 */
void write_room(Room * room, FILE * stream);

/**
 * shuffle array of names of rooms 
 * @param room_names
 */
void shuffle_room_names(char ** room_names);

/**
 * create rooms
 * @param rooms array of rooms
 * @param room_names arrary of names 
 */
void create_rooms(Room ** rooms, char ** room_names);

/**
 * free room from allocated memory 
 * @param rooms
 */
void free_rooms(Room ** rooms);

/**
 * provided prototypes
 */
bool IsSameRoom(Room *x, Room *y);
void ConnectRoom(Room *x, Room *y);
bool ConnectionAlreadyExists(Room *x, Room *y);
bool CanAddConnectionFrom(Room *x);
Room * GetRandomRoom(Room ** rooms);
void AddRandomConnection(Room ** rooms);
bool IsGraphFull(Room ** rooms);

/**
 * connect rooms together
 * @param rooms
 */
void connect_rooms(Room ** rooms);

/**
 * set type to all rooms
 * @param rooms
 */
void set_type_of_rooms(Room ** rooms);

/**
 * set up all rooms 
 * @param rooms
 */
void setup_rooms(Room ** rooms);

/**
 * write a room to file 
 * @param room
 * @param a_directory_name
 */
void write_to_file(Room * room, char * a_directory_name);

/**
 * write all rooms to file 
 * @param rooms
 * @param a_directory_name
 */
void write_to_files(Room ** rooms, char * a_directory_name);

int main(int argc, char** argv) {
    // init all 
    int a_random_number = random_number(MIN_RAND_VAL, MAX_RAND_VAL);
    char * a_directory_name = directory_name(a_random_number);
    
    // create diretory
    create_diretory(a_directory_name);
    
    // set up name of rooms
    char * room_names[ROOM_NAME_NUM];
    hard_code_room_name(room_names);
    shuffle_room_names(room_names);
    
    // set up rooms
    Room * rooms[ROOM_NUM];
    create_rooms(rooms, room_names);
    setup_rooms(rooms);
    
    // write room to files 
    write_to_files(rooms, a_directory_name);
    

    // free all allocated memory
    free_rooms(rooms);
    free_all_room_name(room_names);
    free(a_directory_name);
    return (EXIT_SUCCESS);
}

void write_to_files(Room ** rooms, char * a_directory_name) {
    int i;
    for (i = 0; i < ROOM_NUM; i++) {
        write_to_file(rooms[i], a_directory_name);
    }
}

void write_to_file(Room * room, char * a_directory_name) {
    char path[MAX_DIRECTORY_NAME_LENGTH];
    // set up the path
    sprintf(path, "%s/%s", a_directory_name, room->name);
    FILE * file = fopen(path, "w");    
    if (file == NULL) {
        return;
    }
    
    write_room(room, file);
    fclose(file);
}

void setup_rooms(Room ** rooms) {
    connect_rooms(rooms);
    set_type_of_rooms(rooms);
}

void set_type_of_rooms(Room ** rooms) {
    
    // set up a random start room
    int index = rand() % ROOM_NUM;
    strncpy(rooms[index]->type, "START_ROOM", MAX_ROM_TYPE_LENGTH);


    // set up a random end room
    int start_room = index;
    while (index == start_room) {
        index = rand() % ROOM_NUM;
    }
    strncpy(rooms[index]->type, "END_ROOM", MAX_ROM_TYPE_LENGTH);
    int end_room = index;
    
    // other room are mid rooms 
    int i;
    for (i = 0; i < ROOM_NUM; i++) {
        if (i != end_room && i != start_room) {
            strncpy(rooms[i]->type, "MID_ROOM", MAX_ROM_TYPE_LENGTH);
        }
    }
}

void connect_rooms(Room ** rooms) {
    while (IsGraphFull(rooms) == false) {
        AddRandomConnection(rooms);
    }
}


bool IsGraphFull(Room ** rooms) {
    int i;
    for (i = 0; i < ROOM_NUM; i++) {
        if (rooms[i]->bound_num < MIN_BOUND) {
            return false;
        }
    }
    return true;
}

void AddRandomConnection(Room ** rooms) {
    Room * A;
    Room * B;

    while (true) {
        A = GetRandomRoom(rooms);
        if (CanAddConnectionFrom(A) == true) {
            break;
        }
    }

    do {
        B = GetRandomRoom(rooms);
    } while (CanAddConnectionFrom(B) == false
            || IsSameRoom(A, B) == true
            || ConnectionAlreadyExists(A, B) == true);

    ConnectRoom(A, B);
    ConnectRoom(B, A);
}

Room * GetRandomRoom(Room ** rooms) {
    int index = rand() % ROOM_NUM;
    return rooms[index];
}

bool CanAddConnectionFrom(Room *x) {
    if (x->bound_num < MAX_BOUND) {
        return true;
    }
    return false;
}

bool ConnectionAlreadyExists(Room *x, Room *y) {
    int i;
    for (i = 0; i < x->bound_num; i++) {
        if (IsSameRoom(x->adj[i], y) == true) {
            return true;
        }
    }
    return false;
}

void ConnectRoom(Room *x, Room *y) {
    x->adj[x->bound_num] = y;
    x->bound_num++;
}

bool IsSameRoom(Room *x, Room *y) {
    if (x == y) {
        return true;
    }
    return false;
}


void free_rooms(Room ** rooms) {
    int i;
    for (i = 0; i < ROOM_NUM; i++) {
        if (rooms[i] != NULL) {
            free(rooms[i]);
        }
    }
}

void create_rooms(Room ** rooms, char ** room_names) {
    // initialize all rooms
    int i;
    for (i = 0; i < ROOM_NUM; i++) {
        rooms[i] = (Room*) malloc(sizeof (Room));
        rooms[i]->bound_num = 0;
        strncpy(rooms[i]->name, room_names[i], MAX_ROM_NAME_LENGTH);
    }
}

void shuffle_room_names(char ** room_names) {
    int i;
    char * tmp;
    int index;
    for (i = 0; i < ROOM_NAME_NUM; i++) {
        index = rand() % ROOM_NAME_NUM;
        tmp = room_names[i];
        room_names[i] = room_names[index];
        room_names[index] = tmp;
    }
}

void write_room(Room * room, FILE * stream) {
    fprintf(stream, "ROOM NAME: %s\n", room->name);
    int i;
    for (i = 0; i < room->bound_num; i++) {
        fprintf(stream, "CONNECTION %d: %s\n", (i + 1), room->adj[i]->name);
    }
    fprintf(stream, "ROOM TYPE: %s", room->type);
}

void free_all_room_name(char ** rooms) {
    int i;
    for (i = 0; i < ROOM_NAME_NUM; i++) {
        free(rooms[i]);
    }
}

void hard_code_room_name(char ** rooms) {
    // we have 10 names of room
    rooms[0] = (char *) strdup("Crowthen");
    rooms[1] = (char *) strdup("Dungeon");
    rooms[2] = (char *) strdup("PLUGH");
    rooms[3] = (char *) strdup("PLOVER");
    rooms[4] = (char *) strdup("twisty");
    rooms[5] = (char *) strdup("XYZZY");
    rooms[6] = (char *) strdup("Zork");
    rooms[7] = (char *) strdup("NONO");
    rooms[8] = (char *) strdup("YEAHYEAH");
    rooms[9] = (char *) strdup("UPUP");
}

void create_diretory(char * a_directory_name) {
    int check = mkdir(a_directory_name, 0777);
    if (check) {
        free(a_directory_name);
        printf("Unable to create %s\n", a_directory_name);
        exit(1);
    }
}

char * directory_name(int a_random_number) {
    char * directory = (char*) calloc(MAX_DIRECTORY_NAME_LENGTH, sizeof (char));
    // combine student id with the random number
    sprintf(directory, "%s.rooms.%d", STUDENT_ID, a_random_number);
    return directory;
}

int random_number(int min, int max) {
    srand(time(NULL));
    int val = (rand() % abs(max - min)) + min;
    return val;
}
