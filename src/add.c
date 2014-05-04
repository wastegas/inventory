#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "add.h"
#include "openfile.h"
#include "getinput.h"

static void writerecord(Product*);
static Product *dataEntry(Product*);

void add()
{

    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL ){
        fprintf(stderr, "malloc() failed %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    writerecord(dataEntry(_p));

    free(_p);
}

static Product *dataEntry(Product *_p)
{
    char name[25];

    printf("\nProduct ID\t:");
    _p->pid = getint();
    printf("Product Name\t:");
    getstr(name);
    strcpy(_p->pname, name);
    printf("Product Price\t:");
    _p->price = getdouble();
    printf("Product Qty\t:");
    _p->qty = getdouble();

   return _p;
}

static void writerecord(Product* _p)
{
    FILE *fp = openFile("data.dat", APPENDING);
    
    if ((fwrite(_p, sizeof(Product), 1, fp)) < 1) {
        fprintf (stderr, "error appending record");
        free(_p);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}
