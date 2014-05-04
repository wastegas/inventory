#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "delete.h"
#include "openfile.h"

void delete()
{
    unsigned int id;
    int found = 0;

    Product* _p = malloc(sizeof(*_p));
    if (_p == NULL) {
        fprintf(stderr, "%s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    FILE* fp = openFile("data.dat", READING);
    FILE* fp_tmp = openFile("tmp.dat", APPENDING);

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
