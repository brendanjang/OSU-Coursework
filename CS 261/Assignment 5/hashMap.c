/*
 * CS 261 Data Structures
 * Assignment 5
 * Name: Brendan Jang
 * Date: 6/1/2019
 */

#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

int hashFunction1(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += key[i];
    }
    return r;
}

int hashFunction2(const char* key)
{
    int r = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        r += (i + 1) * key[i];
    }
    return r;
}

/**
 * Creates a new hash table link with a copy of the key string.
 * @param key Key string to copy in the link.
 * @param value Value to set in the link.
 * @param next Pointer to set as the link's next.
 * @return Hash table link allocated on the heap.
 */
HashLink* hashLinkNew(const char* key, int value, HashLink* next)
{
    HashLink *link = malloc(sizeof(HashLink));
    link->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy(link->key, key);
    link->value = value;
    link->next = next;
    return link;
}

/**
 * Free the allocated memory for a hash table link created with hashLinkNew.
 * @param link
 */
static void hashLinkDelete(HashLink* link)
{
    free(link->key);
    free(link);
}

/**
 * Initializes a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param map
 * @param capacity The number of table buckets.
 */
void hashMapInit(HashMap* map, int capacity)
{
    map->capacity = capacity;
    map->size = 0;
    map->table = malloc(sizeof(HashLink*) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        map->table[i] = NULL;
    }
}

/**
 * Removes all links in the map and frees all allocated memory. You can use
 * hashLinkDelete to free the links.
 * @param map
 */
void hashMapCleanUp(HashMap* map) {
    // FIXME: implement
	assert(map != NULL);
	HashLink *next;
	HashLink *curr;
	for (int i = 0; i < map->capacity; i++) {
		curr = map->table[i];
		while (curr != NULL) {
			next = curr->next;
			hashLinkDelete(curr);
			curr = next;
		}
	}
	free(map->table);
	map->size = 0;
}

/**
 * Creates a hash table map, allocating memory for a link pointer table with
 * the given number of buckets.
 * @param capacity The number of buckets.
 * @return The allocated map.
 */
HashMap* hashMapNew(int capacity)
{
    HashMap* map = malloc(sizeof(HashMap));
    hashMapInit(map, capacity);
    return map;
}

/**
 * Removes all links in the map and frees all allocated memory, including the
 * map itself.
 * @param map
 */
void hashMapDelete(HashMap* map)
{
    hashMapCleanUp(map);
    free(map);
}

/**
 * Returns a pointer to the value of the link with the given key  and skip traversing as well. Returns NULL
 * if no link with that key is in the table.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return Link value or NULL if no matching link.
 */
int* hashMapGet(HashMap* map, const char* key) {
    // FIXME: implement
	assert(map != NULL);
	assert(key != NULL);
	int idx = HASH_FUNCTION(key) % hashMapCapacity(map);
	HashLink *curr = map->table[idx];
	while (curr != NULL) {
		if (strcmp(curr->key, key) == 0) {
			return &(curr->value);
		}
		curr = curr->next;
	}
    return NULL;
}

/**
 * Resizes the hash table to have a number of buckets equal to the given 
 * capacity (double of the old capacity). After allocating the new table, 
 * all of the links need to rehashed into it because the capacity has changed.
 * 
 * Remember to free the old table and any old links if you use hashMapPut to
 * rehash them.
 * 
 * @param map
 * @param capacity The new number of buckets.
 */
void resizeTable(HashMap* map, int capacity) {
    // FIXME: implement
	int oldCap = hashMapCapacity(map);
	HashMap *temp = hashMapNew(capacity);
	for (int i = 0; i < oldCap; i++) {
		HashLink *curr = map->table[i];
		while (curr) {
			hashMapPut(temp, curr->key, curr->value);
			curr = curr->next;
		}
	}
	hashMapCleanUp(map);
	map->capacity = temp->capacity;
	map->size = temp->size;
	map->table = temp->table;
	temp->table = NULL;
	free(temp);
}

/**
 * Updates the given key-value pair in the hash table. If a link with the given
 * key already exists, this will just update the value and skip traversing. Otherwise, it will
 * create a new link with the given key and value and add it to the table
 * bucket's linked list. You can use hashLinkNew to create the link.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket.
 * 
 * @param map
 * @param key
 * @param value
 */
void hashMapPut(HashMap* map, const char* key, int value) {
    // FIXME: implement
	float load;
	int cap = hashMapCapacity(map);
	int idx = HASH_FUNCTION(key) % hashMapCapacity(map);
	if (idx < 0) {
		idx += hashMapCapacity(map);
	}
	if (hashMapContainsKey(map, key)) {
		int *val = hashMapGet(map, key);
		(*val) += value;
	}
	else {
		HashLink *newLink = hashLinkNew(key, value, NULL);
		assert(newLink != NULL);
		if (map->table[idx] == NULL) {
			map->table[idx] = newLink;
		}
		else {
			HashLink *curr = map->table[idx];
			while (curr->next) {
				curr = curr->next;
			}
			curr->next = newLink;
		}
		map->size++;
	}
	load = hashMapTableLoad(map);
	if (load >= MAX_TABLE_LOAD) {
		resizeTable(map, 2 * cap);
	}
}

/**
 * Removes and frees the link with the given key from the table. If no such link
 * exists, this does nothing. Remember to search the entire linked list at the
 * bucket. You can use hashLinkDelete to free the link.
 * @param map
 * @param key
 */
void hashMapRemove(HashMap* map, const char* key) {
	// FIXME: implement
	assert(map != NULL);
	assert(key != NULL);
	int idx = HASH_FUNCTION(key) % hashMapCapacity(map);
	HashLink *curr = map->table[idx];
	HashLink *prev = NULL;
	if (curr != NULL) {
		if (strcmp(curr->key, key) == 0) {
			map->table[idx] = curr->next;
		}
		else {
			while (strcmp(curr->key, key) != 0) {
				prev = curr;
				curr = curr->next;
			}
			if (prev) {
				prev->next = curr->next;
			}
		}
		hashLinkDelete(curr);
		map->size--;
	}
}

/**
 * Returns 1 if a link with the given key is in the table and 0 otherwise.
 * 
 * Use HASH_FUNCTION(key) and the map's capacity to find the index of the
 * correct linked list bucket. Also make sure to search the entire list.
 * 
 * @param map
 * @param key
 * @return 1 if the key is found, 0 otherwise.
 */
int hashMapContainsKey(HashMap* map, const char* key) {
    // FIXME: implement
	assert(map != NULL);
	assert(key != NULL);
	int cap = hashMapCapacity(map);
	int idx = HASH_FUNCTION(key) % cap;
	if (idx < 0) {
		idx += cap;
	}
	HashLink *curr = map->table[idx];
	while (curr) {
		if (strcmp(curr->key, key) == 0) {
			return 1;
		}
		curr = curr->next;
	}
    return 0;
}

/**
 * Returns the number of links in the table.
 * @param map
 * @return Number of links in the table.
 */
int hashMapSize(HashMap* map) {
    // FIXME: implement
	assert(map != 0);
    return map->size;
}

/**
 * Returns the number of buckets in the table.
 * @param map
 * @return Number of buckets in the table.
 */
int hashMapCapacity(HashMap* map) {
    // FIXME: implement
	assert(map != 0);
	return map->capacity;
}

/**
 * Returns the number of table buckets without any links.
 * @param map
 * @return Number of empty buckets.
 */
int hashMapEmptyBuckets(HashMap* map) {
    // FIXME: implement
	int total = 0;
	int cap = hashMapCapacity(map);
	for (int i = 0; i < cap; i++) {
		if (map->table[i] == NULL) {
			total++;
		}
	}
    return total;
}

/**
 * Returns the ratio of (number of links) / (number of buckets) in the table.
 * Remember that the buckets are linked lists, so this ratio tells you nothing
 * about the number of empty buckets. Remember also that the load is a floating
 * point number, so don't do integer division.
 * @param map
 * @return Table load.
 */
float hashMapTableLoad(HashMap* map) {
    // FIXME: implement
	assert(map != NULL);
	float size = (float)hashMapSize(map);
	float cap = (float)hashMapCapacity(map);
	float load = size / cap;
    return load;
}

/**
 * Prints all the links in each of the buckets in the table.
 * @param map
 */
void hashMapPrint(HashMap* map) {
  // FIXME: implement
	assert(map != NULL);
	for (int i = 0; i < map->capacity; i++) {
		HashLink *link = map->table[i];
		if (link != NULL) {
			printf("\nBucket %i ->", i);
			while (link != NULL) {
				printf("(%s: %d) ->", link->key, link->value);
				link = link->next;
			}
		}
	}
	printf("\n");   
}