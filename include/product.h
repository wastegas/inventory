#ifndef _PRODUCT_H_
#define _PRODUCT_H_

typedef struct {
    unsigned int pid;
    char pname[15];
    double price;
    double qty;
} Product;

#endif
