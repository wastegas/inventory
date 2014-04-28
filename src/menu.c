#include "menu.h"

enum {
    ADD = 1,
    DELETE,
    PRINT,
    QUIT
};

void menu() {

    int choice;

    while ( choice != QUIT ) {

        printf("1 - Add | 2 = Delete | 3 - Print | 4 - Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case ADD:
                add();
                break;
            case PRINT:
                print();
                break;
            case DELETE:
                delete();
                break;
            case QUIT:
                return;
            default:
                printf("%d is an invalid choice\n", choice);
                break;
        }
        getchar();
    }

}
