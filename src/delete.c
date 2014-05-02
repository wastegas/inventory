#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "delete.h"

void delete()
{
    unsigned int id;
    int found = 0;

    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL) {
        fprintf(stderr, "%s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE* fp;
    FILE* fp_tmp;

    fp = fopen("data.dat", "rb");
    if (!fp) {
        fprintf(stderr, "unable to open file for reading, %s\n", 
                strerror(errno));
        exit(EXIT_FAILURE);
    }

    fp_tmp = fopen("tmp.dat", "ab");
    if (!fp_tmp) {
        fprintf(stderr, "unable to open temp file for writing, %s\n", 
                strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Enter product id to delete:");
    scanf("%d", &id);

    while (fread(_p, sizeof(Product), 1, fp)) {
        if (_p->pid == id) {
            printf("A record with id %d was found and deleted.\n", id);
            found = 1;
        } else {
            fwrite(_p, sizeof(Product), 1, fp_tmp);
        }
    }
    if (!found) {
        printf("No record(s) found with id %d for deletion\n", id);
    }

    fclose(fp);
    fclose(fp_tmp);
    free(_p);

    remove("data.dat");
    rename("tmp.dat", "data.dat");

}
