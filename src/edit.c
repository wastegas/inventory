#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include "edit.h"
#include "openfile.h"


static bool editval();

void edit()
{

    unsigned int    id;         // product id
    char            name[25];   // product name
    double          p;          // product price
    double          q;          // product quantity
    int             found = 0;
    long            pos = 0;    // file position

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

    getchar();

    if (found) {


        printf("Product name : (%s) Edit(y/n)? ", _p->pname);
        if (editval()) {
            printf("Enter new value: ");
            scanf("%s", name);
            if (strcmp(name, _p->pname) != 0) {
                strcpy(_p->pname, name);
            }
        }
        getchar();
        printf("Product Price: (%4.2f) Edit(y/n)? ", _p->price);
        if (editval()) {
            printf("Enter new value: ");
            scanf("%lf", &p);
            _p->price = p;
        }
        getchar();
        printf("Product Qty  : (%4.2f) Edit(y/n)? ", _p->qty);
        if (editval()) {
            printf("Enter new value: ");
            scanf("%lf", &q);
            _p->qty = q;
        }

        fseek(fp, pos - sizeof(Product), SEEK_SET); 
        fwrite(_p, sizeof(Product), 1, fp);
    } else {

        printf("record was not found for editing\n");

    }

    fclose(fp);
    free(_p);

}

static bool editval()
{
    int y;
    y = getchar();
    if (y == 'y' || y == 'Y') {
        getchar();
        return true;
    } 
        return false;
}
