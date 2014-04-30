#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "search.h"
#include "printone.h"

void search() {

    unsigned int    id;
    int             found = 0;

    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL) {

        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);

    }

    FILE* fp = fopen("data.dat", "rb");
    if (!fp) {

        fprintf(stderr, "unable top open file for reading, %s\n", strerror(errno));
        exit(EXIT_FAILURE);

    }

    printf("Enter product id to display:");
    scanf("%d", &id);

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
