#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "print.h"

void print() {
    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL) {
        fprintf(stderr, "malloc() error %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE* fp = fopen("data.dat", "rb");
    if(!fp) {
        fprintf(stderr, "unable to open data.dat for reading %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("\n%3s\t%-15s\t%9s\t%9s\n","ID", "Name", "Price", "Qty");
    while ( fread(_p, sizeof(Product), 1, fp) != 0 ) {
    /*
        printf("\nProduct ID   :\t%d\n", _p->pid);
        printf("Product Name :\t%s\n", _p->pname);
        printf("Product price:\t%4.2f\n", _p->price);
        printf("Product Qty  :\t%4.2f\n", _p->qty);
     */
        printf("%3d\t%-15s\t%9.2f\t%9.2f\n", _p->pid, _p->pname, _p->price, _p->qty);
    }

    fclose(fp);
    free(_p);
}
