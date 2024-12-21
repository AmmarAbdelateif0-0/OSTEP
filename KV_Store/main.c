#include "hashmap.h"
#include "file_io.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("ERROR: Enter Your Command -> p,g,a,c,d\n");
        exit(EXIT_FAILURE);
    }

    struct mp *map = init_mp(SIZE);
    import_data(map);

    for (int i = 1; i < argc; i++) {
        parsing_command(map, argv[i]);
    }

    save_data(map);
    clear(map);
    free(map);

    return 0;
}
