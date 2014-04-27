#ifndef _PRODUCT_H_
#define _PRODUCT_H_

typedef struct {
    unsigned int pid;
    char pname[25];
    double price;
    double qty;
} Product;

#endif
