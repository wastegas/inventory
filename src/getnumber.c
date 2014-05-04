#include <stdio.h>
#include <stdlib.h>
#include "getnumber.h"

double getnumber()
{
    double input;
    while (1) {
        printf("Enter new value: ");
        if (scanf("%lf", &input) == 1 ) {
            return input;
        } else {
            printf("Invalid input...\n");
            getchar();
        }
    }
}


