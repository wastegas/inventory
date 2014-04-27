#include <stdio.h>
#include <stdlib.h>
#include "print.h"

void print(Product* p) {
    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL) {
        perror("malloc() error\n");
        exit(1);
    }

    FILE* fp = fopen("data.dat", "rb");
    if(!fp) {
        perror("unable to open data.dat for reading\n");
        exit(1);
    }

    while ( fread(_p, sizeof(Product), 1, fp) != 0 ) {

        printf("\nProduct ID   :\t%d\n", _p->pid);
        printf("Product Name :\t%s\n", _p->pname);
        printf("Product price:\t%4.2f\n", _p->price);
        printf("Product Qty  :\t%4.2f\n", _p->qty);
    }

    fclose(fp);
    free(_p);
}
