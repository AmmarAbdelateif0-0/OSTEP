#include "utils.h"
#include <stdio.h>
#include <string.h>

void parsing_command(struct mp *map, char *input) {
    char *command = strtok(input, ",");
    char *key = strtok(NULL, ",");
    char *value = strtok(NULL, ",");

    if (command[0] == 'p') {
        if (key == NULL || value == NULL) {
            printf("ERROR: MUST -> p,key,value\n");
            return;
        }
        put(map, key, value);
    } else if (command[0] == 'g') {
        if (key == NULL) {
            printf("ERROR: MUST -> g,key\n");
            return;
        }
        get(map, key);
    } else if (command[0] == 'a') {
        all(map);
    } else if (command[0] == 'd') {
        if (key == NULL) {
            printf("ERROR: MUST -> d,key\n");
            return;
        }
        delete_key(map, key);
    } else if (command[0] == 'c') {
        clear(map);
    } else {
        printf("ERROR: Invalid Command\n");
    }
}
