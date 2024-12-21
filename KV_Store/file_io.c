#include "file_io.h"
#include <stdio.h>
#include <string.h>

// Import data from file
void import_data(struct mp *data) {
    FILE *fd = fopen("database.txt", "r");
    if (fd == NULL) {
        perror("ERROR: Could not open database.txt");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fd) != NULL) {
        char *key = strtok(line, ",");
        char *value = strtok(NULL, ",\n");
        if (key && value) {
            put(data, key, value);
        }
    }

    fclose(fd);
}

// Save data to file
void save_data(struct mp *data) {
    FILE *fd = fopen("database.txt", "w");
    if (fd == NULL) {
        perror("ERROR: Could not open database.txt");
        return;
    }

    for (int i = 0; i < data->length; i++) {
        if (data->key_value[i] != NULL) {
            fprintf(fd, "%s,%s\n", data->key_value[i]->key, data->key_value[i]->value);
        }
    }

    fclose(fd);
}
