#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "search.h"
#include "openfile.h"
#include "getinput.h"

static void printone(Product*);

void search()
{

    unsigned int    id;
    int             found = 0;

    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE *fp = openFile("data.dat", READING);

    printf("Enter product id to display:");
    id = getint();

    while (fread(_p, sizeof(Product), 1, fp)) {
        if (_p->pid == id) {
            found = 1;
            fclose(fp);
            break;
        }
    }

    if (found) {
        printone(_p);
    } else {
        printf("No record found for product id %d\n", id);
    }

    free(_p);

}

static void printone(Product* _p) {

        printf("\nProduct ID   :\t%d\n", _p->pid);
        printf("Product Name :\t%s\n", _p->pname);
        printf("Product price:\t%4.2f\n", _p->price);
        printf("Product Qty  :\t%4.2f\n", _p->qty);

}
