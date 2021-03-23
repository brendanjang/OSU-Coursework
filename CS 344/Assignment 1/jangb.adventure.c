
/* 
 * File:   jangb.adventure.c
 * Author: Brendan Jang
 * Date:   07/07/2020  
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
#include <wchar.h>
#include <sys/stat.h>
#include <stddef.h>
#include <string.h>

#define MIN_RAND_VAL 0
#define MAX_RAND_VAL 100000

#define MAX_DIRECTORY_NAME_LENGTH 128
#define MAX_LINE_LENGTH 512

#define MAX_ROM_NAME_LENGTH 9
#define MAX_ROM_TYPE_LENGTH 13

#define ROOM_NAME_NUM 10
#define ROOM_NUM 7

#define MIN_BOUND 3
#define MAX_BOUND 6

/**
 * Room structure
 */
struct Room {
    char name[MAX_ROM_NAME_LENGTH];
    char type[MAX_ROM_TYPE_LENGTH];
    struct Room * adj[MAX_BOUND];
    int bound_num;
};
typedef struct Room Room;

/**
 * get the most recent directory
 * @return 
 */
char * get_recent_directory();

/**
 * read a room from file
 * @param path
 * @return 
 */
Room * read_room(char * path);

/**
 * read all room from directory
 * @param directory
 * @param rooms
 * @return 
 */
bool read_rooms(char * directory, Room ** rooms);

/**
 * look for a room with name
 * @param rooms
 * @param name
 * @return 
 */
Room * look_for(Room ** rooms, char * name);

/**
 * setup a room
 * @param path
 * @param rooms
 * @param room
 */
void setup_room(char * path, Room ** rooms, Room * room);

/**
 * setup all rooms
 * @param directory
 * @param rooms
 */
void setup_rooms(char * directory, Room ** rooms);

/**
 * initialize all rooms in the game
 * @param directory
 * @param rooms
 * @return 
 */
bool init(char * directory, Room ** rooms);

/**
 * get the start room
 * @param rooms
 * @return 
 */
Room * get_start_room(Room ** rooms);

/**
 * print the current room
 * @param room
 */
void print_current_state(Room * room);

/**
 * get t5he next room by name
 * @param room
 * @param name
 * @return 
 */
Room * get_next_room(Room * room, char * name);

/**
 * free memory of all rooms 
 * @param rooms
 */
void free_rooms(Room ** rooms);

/**
 * play the game
 * @param directory
 */
void play(char * directory);


int main(int argc, char** argv) {
    char * directory = get_recent_directory();

    if (directory == NULL
            || strlen(directory) == 0) {
        printf("There isn't any directory\n");
    } else {
        play(directory);
    }
    
    free(directory);
    return (EXIT_SUCCESS);
}

void play(char * directory) {
    
    // create and initialize all rooms
    Room * rooms[ROOM_NUM];
    if (init(directory, rooms) == false) {     
        return;
    }    
    // get start room
    Room * room = get_start_room(rooms);
    if (room == NULL) {        
        return;
    }
    
    // prepare for the game
    char name[MAX_ROM_NAME_LENGTH];
    Room * next;
    int capacity = ROOM_NUM;
    int step = 0;
    char ** path = (char **) calloc(capacity, sizeof (char *));
    int j;
    char ** tmp;

    // while we haven't reach the end room
    while (strcmp(room->type, "END_ROOM") != 0) {
        // print current room
        print_current_state(room);
        // get name of the next room
        scanf("%s", name);
        printf("\n");
        
        // get the room
        next = get_next_room(room, name);
        if (next == NULL) {
            // bad case 
            printf("HUH? I DON'T UNDERSTAND THAT ROOM. TRY AGAIN.\n\n");
        } else {
            
            room = next;
            
            // resize the array if it is needed
            if (step >= capacity) {
                capacity += ROOM_NUM;
                char ** tmp = (char **) calloc(capacity, sizeof (char *));
                for (j = 0; j < step; j++) {
                    tmp[j] = path[j];
                }
                free(path);
                path = tmp;
            }
            // put name of the next room to the path
            path[step] = strdup(name);
            step++;
        }
    }
    
    // show final result
    printf("YOU HAVE FOUND THE END ROOM. CONGRATULATIONS!\n");
    printf("YOU TOOK %d STEPS, YOUR PATH TO VICTORY WAS:\n", step);
    int i;
    for (i = 0; i < step; i++) {
        printf("%s\n", path[i]);
        free(path[i]);
    }
    free(path);
    free_rooms(rooms);
}

void free_rooms(Room ** rooms) {
    int i;
    for (i = 0; i < ROOM_NUM; i++) {
        if (rooms[i] != NULL) {
            free(rooms[i]);
        }
    }
}

Room * get_next_room(Room * room, char * name) {
    int i;
    for (i = 0; i < room->bound_num; i++) {
        // return address of the room which its name meets the requirement
        if (strcmp(room->adj[i]->name, name) == 0) {
            return room->adj[i];
        }
        //printf("%s\n", room->adj[i]->name);
    }
    return NULL;
}

void print_current_state(Room * room) {
    printf("CURRENT LOCATION: %s\n", room->name);
    printf("POSSIBLE CONNECTIONS: %s", room->adj[0]->name);
    int i;
    for (i = 1; i < room->bound_num; i++) {
        printf(", %s", room->adj[i]->name);
    }
    printf("\nWHERE TO? >");

}

Room * get_start_room(Room ** rooms) {
    int i;
    Room * room;
    for (i = 0; i < ROOM_NUM; i++) {
        room = rooms[i];
        // find the room whose type is START_ROOM
        if (room != NULL
                && strcmp(room->type, "START_ROOM") == 0) {
            return room;
        }
    }
    return NULL;
}

bool init(char * directory, Room ** rooms) {
    if (read_rooms(directory, rooms) == false) {
        return false;
    }
    setup_rooms(directory, rooms);
    return true;
}

void setup_rooms(char * directory, Room ** rooms) {
    struct dirent *dire;
    // ope directory 
    DIR *dir = opendir(directory);
    struct stat stats;
    int index = 0;
    char path[MAX_LINE_LENGTH];
    Room * room;
    // get each file in the directory
    while ((dire = readdir(dir)) != NULL
            && index < ROOM_NUM) {
        
        // skip special files
        if (strcmp(".", dire->d_name) != 0
                && strcmp("..", dire->d_name) != 0) {
            // read normal files 
            snprintf(path, MAX_LINE_LENGTH, "%s/%s", directory, dire->d_name);
            room = rooms[index];
            setup_room(path, rooms, room);
            index++;
        }
    }
    closedir(dir);
}

void setup_room(char * path, Room ** rooms, Room * room) {
    FILE * file = fopen(path, "r");
    if (file == NULL) {
        return;
    }
    char line [MAX_LINE_LENGTH];
    char * parts[3];
    int i;
    for (i = 0; i < 3; i++) {
        parts[i] = (char *) calloc(MAX_ROM_TYPE_LENGTH, sizeof (char));
    }
    room->bound_num = 0;
    Room * next;
    
    // read each line
    // try to connect this room to otehr room
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        sscanf(line, "%s %s %s", parts[0], parts[1], parts[2]);
        if (strcmp("CONNECTION", parts[0]) == 0) {
            next = look_for(rooms, parts[2]);
            if (next != NULL) {
                room->adj[room->bound_num] = next;
                room->bound_num++;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        free(parts[i]);
    }
    fclose(file);
}

/**
 * look for a room 
 * @param rooms
 * @param name
 * @return 
 */
Room * look_for(Room ** rooms, char * name) {
    int i;
    Room * room;
    for (i = 0; i < ROOM_NUM; i++) {
        room = rooms[i];
        if (room != NULL
                && strcmp(name, room->name) == 0) {
            return room;
        }
    }
    return NULL;
}

bool read_rooms(char * directory, Room ** rooms) {
    struct dirent *dire;
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        printf("Could not open current directory");
        return false;
    }
    struct stat stats;
    int index = 0;
    char path[MAX_LINE_LENGTH];
    Room * room;
    while ((dire = readdir(dir)) != NULL
            && index < ROOM_NUM) {
        if (strcmp(".", dire->d_name) != 0
                && strcmp("..", dire->d_name) != 0) {
            snprintf(path, MAX_LINE_LENGTH, "%s/%s", directory, dire->d_name);
            
            room = read_room(path);
            if (room == NULL) {              
                closedir(dir);
                return false;
            }
            rooms[index] = room;
            index++;
        }
    }
    closedir(dir);
    return true;
}

Room * read_room(char * path) {
    FILE * file = fopen(path, "r");
    if (file == NULL) {
        return NULL;
    }
    Room * room = (Room *) malloc(sizeof (Room));
    char line [MAX_LINE_LENGTH];
    char * parts[3];
    int i;
    for (i = 0; i < 3; i++) {
        parts[i] = (char *) calloc(MAX_ROM_TYPE_LENGTH, sizeof (char));
    }

    room->bound_num = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        sscanf(line, "%s %s %s", parts[0], parts[1], parts[2]);
        if (strcmp("NAME:", parts[1]) == 0) {
            strncpy(room->name, parts[2], MAX_ROM_NAME_LENGTH);
        } else if (strcmp("CONNECTION", parts[0]) == 0) {
            // do nothing
        } else {
            strncpy(room->type, parts[2], MAX_ROM_TYPE_LENGTH);
        }

    }
    for (i = 0; i < 3; i++) {
        free(parts[i]);
    }
    fclose(file);
    return room;
}

char * get_recent_directory() {
    struct dirent *dire;
    DIR *dir = opendir(".");
    if (dir == NULL) {
        printf("Could not open current directory");
        return NULL;
    }
    char *path = (char *) calloc(MAX_DIRECTORY_NAME_LENGTH, sizeof (char));
    path[0] = '\0';
    struct stat stats;
    time_t mtime = 0;
    while ((dire = readdir(dir)) != NULL) {
        if (strcmp(".", dire->d_name) != 0
                && strcmp("..", dire->d_name) != 0) {
            if (stat(dire->d_name, &stats) == 0) {
                // the file should be a directory
                if (S_ISDIR(stats.st_mode)) {
                    // it should be the youngest 
                    if (stats.st_mtime > mtime) {
                        mtime = stats.st_mtime;
                        strncpy(path, dire->d_name, MAX_DIRECTORY_NAME_LENGTH);
                    }
                }
            }
        }
    }

    closedir(dir);
    return path;
}
