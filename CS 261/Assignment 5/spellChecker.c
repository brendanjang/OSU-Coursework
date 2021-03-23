#include "hashMap.h"
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Allocates a string for the next word in the file and returns it. This string
 * is null terminated. Returns NULL after reaching the end of the file.
 * @param file
 * @return Allocated string or NULL.
 */
char* nextWord(FILE* file)
{
    int maxLength = 16;
    int length = 0;
    char* word = malloc(sizeof(char) * maxLength);
    while (1)
    {
        char c = fgetc(file);
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == '\'')
        {
            if (length + 1 >= maxLength)
            {
                maxLength *= 2;
                word = realloc(word, maxLength);
            }
            word[length] = c;
            length++;
        }
        else if (length > 0 || c == EOF)
        {
            break;
        }
    }
    if (length == 0)
    {
        free(word);
        return NULL;
    }
    word[length] = '\0';
    return word;
}

/**
 * Loads the contents of the file into the hash map.
 * @param file
 * @param map
 */
void loadDictionary(FILE* file, HashMap* map) {
    // FIXME: implement
	char *word = nextWord(file);
	while (word != NULL) {
		hashMapPut(map, word, 1);
		free(word);
		word = nextWord(file);
	}
}

/**
* Calculates the Levenshtein Distance.
* Referenced https://en.wikipedia.org/wiki/Levenshtein_distance
*			 https://www.lemoda.net/c/levenshtein/
* @param str1
* @param len1
* @param str2
* @param len2
* @return dist
*/
int calcLevenshtein(const char * word1, int len1, const char * word2, int len2) {
	int rows = len1 + 1;
	int columns = len2 + 1;
	int **matrix = (int**)malloc(rows * sizeof(int*));

	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*)malloc(columns * sizeof(int*));
	}
	for (int i = 0; i <= len1; i++) {
		matrix[i][0] = i;
	}
	for (int i = 0; i <= len2; i++) {
	matrix[0][i] = i;
	}
	for (int i = 1; i <= len1; i++) {
		char c1 = word1[i - 1];
		for (int j = 1; j <= len2; j++) {
			char c2 = word2[j - 1];
			if (c1 == c2) {
				matrix[i][j] = matrix[i - 1][j - 1];
			}
			else {
				int ins = matrix[i][j - 1] + 1;
				int del = matrix[i - 1][j] + 1;
				int subs = matrix[i - 1][j - 1] + 1;
				int min = del;
				if (ins < min) {
					min = ins;
				}
				if (subs < min) {
					min = subs;
				}
				matrix[i][j] = min;
			}
		}
	}
	int dist = matrix[len1][len2]; 
	for (int i = 0; i < rows; i++) {
		free(matrix[i]);
	}
	free(matrix);
	return dist;
}


/**
 * Prints the concordance of the given file and performance information. Uses
 * the file input1.txt by default or a file name specified as a command line
 * argument.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char** argv)
{
    // FIXME: implement
    HashMap* map = hashMapNew(1000);
    
    FILE* file = fopen("dictionary.txt", "r");
    clock_t timer = clock();
    loadDictionary(file, map);
    timer = clock() - timer;
    printf("Dictionary loaded in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
    fclose(file);
    
    char inputBuffer[256];
    int quit = 0;
    while (!quit)
    {
        printf("Enter a word or \"quit\" to quit: ");
        scanf("%s", inputBuffer);
        
        // Implement the spell checker code here..
        if (strcmp(inputBuffer, "quit") == 0)
        {
            quit = 1;
        }
		else {
			if (hashMapContainsKey(map, inputBuffer)) {
				printf("\nThe word was spelled correctly.\n");
			}
			else {
				printf("\nThe word was spelled incorrectly.\n");
				// count of close matches
				int close = 0;
				// array to hold close matches
				char *matches[6];
				for (int i = 0; i < 6; i++) {
					matches[i] = NULL;
				}
				// start with words that are off by 1 character
				int likeness = 1;
				// while there are less than 5 matches
				while (close < 5) {
					// loop through the buckets
					for (int i = 0; i < map->capacity; i++) {
						// iterator points to the first link in the bucket
						HashLink *itr = map->table[i];
						// move through the list until the iterator is null or 5 close matches are found
						while (itr != NULL && close < 5) {
							// get word to compare to inputted word
							char *comp = itr->key;
							// find distance between two words (input & dictionary word)
							int similarity = calcLevenshtein(inputBuffer, strlen(inputBuffer), comp, strlen(comp));
							if (similarity == likeness) {
								// add to the array of close matches
								matches[close] = itr->key;
								// increment by 1;
								close++;
							}
							// move to next link
							itr = itr->next;
						}
					}
					// if still less than 5 matches, increase distance
					likeness++;
				}
				// loop through array and output to user
				for (int i = 0; i < close; i++) {
					printf("\nDid you mean %s?", matches[i]);
				}
				printf("\n");
			}
		}
	}
	hashMapDelete(map);
	return 0;
}