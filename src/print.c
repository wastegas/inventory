#include "print.h"

void print(Product* p) {
    printf("Product ID   :\t%d\n", p->pid);
    printf("Product Name :\t%s\n", p->pname);
    printf("Product price:\t%4.2f\n", p->price);
    printf("Product Qty  :\t%4.2f\n", p->qty);
}
