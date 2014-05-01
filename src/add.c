#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "add.h"

static void writerecord(Product*);

void add() {

    char name[25];
    Product* _p = malloc(sizeof(*_p));
    if ( _p == NULL ) {
        fprintf(stderr, "malloc() failed %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("\nProduct ID\t:");
    scanf("%u", &(_p->pid));
    printf("Product Name\t:");
    scanf("%s", name);
    strcpy(_p->pname, name);
    printf("Product Price\t:");
    scanf("%lf", &(_p->price));
    printf("Product Qty\t:");
    scanf("%lf", &(_p->qty));

    writerecord(_p);

    free(_p);
}

static void writerecord(Product* _p) {

    FILE* fp = fopen("data.dat", "ab");
    
    if (!fp) {
       fprintf(stderr, "unable to open 'data.dat' for writing %s\n", strerror(errno));
       exit(EXIT_FAILURE);
    }
    
    fwrite(_p, sizeof(Product), 1, fp);
    fclose(fp);
}
