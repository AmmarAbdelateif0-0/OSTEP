#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdlib.h>
#include <string.h>

// Define constants
#define SIZE 100

// Data structures
struct Key_Value {
    char *key;
    char *value;
};

struct mp {
    int length;
    struct Key_Value **key_value;
};

// Function declarations
struct mp *init_mp(int length);
void put(struct mp *map, char *key, char *value);
void get(struct mp *map, char *key);
void all(struct mp *map);
void delete_key(struct mp *map, char *key);
void clear(struct mp *map);
unsigned int hash_function(const char *key, int length);

#endif
