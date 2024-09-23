/*
 * Starter code
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    char *fname = NULL;
    int mode = 0; // 0 - normal, 1 - verbose

    if (argc < 3 ) {
        printf("Not enough arguments. Need mode and filename, e.g.: 0 caps.txt\n");
        return 0;
    }
    else {
        fname = argv[2];
        mode = atoi(argv[1]);
    }

    printf("mode: %d  file: %s\n", mode, fname);  // KEEP THIS LINE

    return 0;
}
