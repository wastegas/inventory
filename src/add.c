#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "add.h"

void add() {

    char name[25];
    Product* _p = malloc(sizeof(*_p));
    if ( _p == NULL ) {
        printf("malloc() failed\n");
        exit(1);
    }

    printf("\nProduct ID\t:");
    scanf("%u", &(_p->pid));
    printf("Product Name:\t");
    scanf("%s", name);
    strcpy(_p->pname, name);
    printf("Product Price:\t");
    scanf("%lf", &(_p->price));
    printf("Product Qty:\t");
    scanf("%lf", &(_p->qty));

    FILE* fp = fopen("data.dat", "ab");
    if (!fp) {
       perror("unable to open 'data.dat' for writing\n");
       exit(1);
    }
    
    fwrite(_p, sizeof(Product), 1, fp);
    fclose(fp);
    free(_p);
}
