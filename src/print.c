#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "print.h"
#include "openfile.h"

void print() {
    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL) {
        fprintf(stderr, "malloc() error %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE* fp = openFile("data.dat", READING);

    printf("\n%3s\t%-10s\t%9s\t%9s\t%9s\n",
            "ID", "Name", "Price", "Qty", "Total");
    while ( fread(_p, sizeof(Product), 1, fp) != 0 ) {
       printf("%3d\t%-10s\t%9.2f\t%9.2f\t%9.2f\n", 
              _p->pid, _p->pname,  _p->price, 
              _p->qty, _p->price * _p->qty);
    }

    fclose(fp);
    free(_p);
}
