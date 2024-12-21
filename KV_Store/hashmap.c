#include "hashmap.h"
#include <stdio.h>

// Initialize the map
struct mp *init_mp(int length) {
    struct mp *map = malloc(sizeof(struct mp));
    if (!map) {
        perror("ERROR: Failed to allocate memory for map");
        exit(EXIT_FAILURE);
    }
    map->length = length;
    map->key_value = calloc(length, sizeof(struct Key_Value *));
    if (!map->key_value) {
        perror("ERROR: Failed to allocate memory for key-value pairs");
        free(map);
        exit(EXIT_FAILURE);
    }
    return map;
}

// Insert a key-value pair into the map
void put(struct mp *map, char *key, char *value) {
    unsigned int idx = hash_function(key, map->length);
    if (map->key_value[idx] != NULL) {
        free(map->key_value[idx]->key);
        free(map->key_value[idx]->value);
        free(map->key_value[idx]);
    }

    struct Key_Value *pair = malloc(sizeof(struct Key_Value));
    pair->key = strdup(key);
    pair->value = strdup(value);
    map->key_value[idx] = pair;
}

// Retrieve a value by key
void get(struct mp *map, char *key) {
    unsigned int idx = hash_function(key, map->length);
    if (map->key_value[idx] == NULL) {
        printf("ERROR: Key Not Found\n");
        return;
    }
    printf("Key: %s, Value: %s\n", map->key_value[idx]->key, map->key_value[idx]->value);
}

// Display all key-value pairs
void all(struct mp *map) {
    for (int i = 0; i < map->length; i++) {
        if (map->key_value[i] != NULL) {
            printf("Key: %s, Value: %s\n", map->key_value[i]->key, map->key_value[i]->value);
        }
    }
}

// Delete a key-value pair
void delete_key(struct mp *map, char *key) {
    unsigned int idx = hash_function(key, map->length);
    if (map->key_value[idx] != NULL) {
        free(map->key_value[idx]->key);
        free(map->key_value[idx]->value);
        free(map->key_value[idx]);
        map->key_value[idx] = NULL;
    }
}

// Clear all key-value pairs
void clear(struct mp *map) {
    for (int i = 0; i < map->length; i++) {
        if (map->key_value[i] != NULL) {
            free(map->key_value[i]->key);
            free(map->key_value[i]->value);
            free(map->key_value[i]);
        }
    }
}

// Simple hash function
unsigned int hash_function(const char *key, int length) {
    unsigned int hash = atoi(key);
    return hash % length;
}
