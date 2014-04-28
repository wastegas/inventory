#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "printone.h"

void printone(Product* _p) {

        printf("\nProduct ID   :\t%d\n", _p->pid);
        printf("Product Name :\t%s\n", _p->pname);
        printf("Product price:\t%4.2f\n", _p->price);
        printf("Product Qty  :\t%4.2f\n", _p->qty);

}
