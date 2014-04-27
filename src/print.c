#include "print.h"

void print(Product* p) {
    printf("Product ID   :\t%d\n", p->pid);
    printf("Product Name :\t%s\n", p->pname);
    printf("Product price:\t%f\n", p->price);
    printf("Product Qty  :\t%f\n", p->qty);
}
