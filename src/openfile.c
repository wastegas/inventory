#include <stdio.h>
#include <stdlib.h>
#include "openfile.h"

FILE *openFile(const char *file)
{
    FILE *inFile;

    if ((inFile = fopen(file, "rb+")) == NULL) {
        fprintf (stderr, "Con't open %s for read/write.\n", file);
        exit (EXIT_FAILURE);
    }

    return inFile;
}
