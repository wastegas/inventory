#include <stdlib.h>
#include <string.h>
#include "add.h"

void add(Product* p, unsigned int id, char* name, double pc, double q) {
    p->pid = id;
    strcpy(p->pname, name);
    p->price = pc;
    p->qty = q;
}
