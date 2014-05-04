#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getinput.h"

char *getstr(char* str)
{
    char input[25];
    scanf("%s", input);
    strcpy(str, input);
    return str;
}

double getdouble()
{
    double input;
    while (1) {
        //printf("->");
        if (scanf("%lf", &input) == 1 ) {
            return input;
        } else {
            printf("Invalid input...\n");
            getchar();
        }
    }
}

int getint()
{
    int input;
    while (1) {
        if (scanf("%d", &input) == 1 ) {
            return input;
        } else {
            printf("Invalid input...\n");
            getchar();
        }
    }
}


