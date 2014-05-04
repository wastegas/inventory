#include <stdio.h>
#include <stdlib.h>
#include "getnumber.h"

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
        //printf("->");
        if (scanf("%d", &input) == 1 ) {
            return input;
        } else {
            printf("Invalid input...\n");
            getchar();
        }
    }
}


