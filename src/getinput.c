#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getinput.h"

char *getstr(char* str)
{
    //char input[25];
    //scanf("%s", input);
    size_t read_bytes = 0;
    char *input;
    size_t size = 25;
    input = (char *)malloc(size + 1);
    freopen("/dev/tty", "rw", stdin);
    getline(&input, &size, stdin);
    if (read_bytes == -1) {
      puts("input error");
      return NULL;
    }
    strcpy(str, input);
    free(input);
    return str;
}

double *getdouble(double *input)
{
    while (1) {
        if (scanf("%lf", input) == 1 ) {
            getchar();
            return input;
        } else {
            printf("Invalid input...\n");
            getchar();
        }
    }
}

unsigned int *getint(unsigned int *input)
{
    while (1) {
        if (scanf("%ud", input) == 1 ) {
            return input;
        } else {
            printf("Invalid input...\n");
            getchar();
        }
    }
}
