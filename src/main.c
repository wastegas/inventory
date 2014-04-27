#include <stdio.h>
#include <stdlib.h>

#include "product.h"
#include "add.h"
#include "print.h"

int main(void) {
    Product* _p = malloc(sizeof(*_p));

    if ( _p == NULL ) {
        printf("malloc() failed in file %s", __FILE__);
        exit(1);
    }


    FILE* file = fopen("output", "ab");
    if ( file != NULL ) {
        add(_p, 1, "test", 3.00, 1);
        fwrite(_p, sizeof(Product), 1, file);
        fclose(file);
    }

    free(_p);

    Product* _o = malloc(sizeof(*_o));
    FILE* infile = fopen("output", "rb");
    if (infile != NULL) {
        fread(_o, sizeof(Product), 1, infile);
        fclose(infile);
    }

    print(_o);

    free(_o);

    return 0;
}
