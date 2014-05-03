#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "edit.h"
#include "openfile.h"

void edit()
{

    unsigned int    id;
    char            name[25];
    double          p;
    double          q;
    int             found = 0;
    long            pos = 0;
   
    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL) {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
/*
    FILE* fp = fopen("data.dat", "r+b");
    if (!fp) {
        fprintf(stderr, "unable top open file for reading, %s\n", 
                strerror(errno));
        exit(EXIT_FAILURE);
    }
*/
    FILE *fp = openFile("data.dat", WRITING);

    printf("Enter product id to edit:");
    scanf("%d", &id);

    while (fread(_p, sizeof(Product), 1, fp)) {

        if (_p->pid == id) {
            pos = ftell(fp);
            found = 1;
            break;
        }

    }

    if (found) {

        fseek(fp, pos - sizeof(Product), SEEK_SET); 

        printf("Product name : (%s) ", _p->pname);
        scanf("%s", name);
        if (strcmp(name, _p->pname) != 0) {
            strcpy(_p->pname, name);
        }
        printf("Product Price: (%4.2f) ", _p->price);
        scanf("%lf", &p);
        if (_p->price != p) {
            _p->price = p;
        }
        printf("Product Qty  : (%4.2f) ", _p->qty);
        scanf("%lf", &q);
        if (_p->qty != q) {
            _p->qty = q;
        }

        fwrite(_p, sizeof(Product), 1, fp);
    } else {

        printf("record was not found for editing\n");

    }

    fclose(fp);
    free(_p);

}
