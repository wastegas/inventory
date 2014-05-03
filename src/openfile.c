#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "openfile.h"

FILE *openFile(const char *file, int option)
{
    FILE *inFile;
    char *mode = " ";

    switch (option) {
    case APPENDING:
        mode = malloc(strlen("ab") + 1);
        strcpy (mode, "ab");
        break;
    case READING:
        mode = malloc(strlen("rb") + 1);
        strcpy (mode, "rb");
        break;
    case WRITING:
        mode = malloc(strlen("rb+") + 1);
        strcpy (mode, "rb+");
        break;
    default:
        fprintf (stderr, "Invalid file mode operation\n");
        exit (EXIT_FAILURE);
        break;
    }

    printf("mode is %s\n", mode);

    if ((inFile = fopen(file, mode)) == NULL) {
        fprintf (stderr, "Con't open %s for read/write.\n", file);
        exit (EXIT_FAILURE);
    } else {
        printf("file opened successfuly\n");
    }

    free(mode);
    return inFile;
}
