#include <stdio.h>
#include <stdlib.h>

#include "product.h"
#include "add.h"
#include "print.h"

int main(void) {
    Product* _p = malloc(sizeof(*_p));

    add(_p, 1, "test", 3.00, 1);
    print(_p);

    free(_p);

    return 0;
}
