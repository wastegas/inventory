#include "menu.h"

enum {
    ADD = 1,
    PRINT,
    QUIT
};

void menu() {

    int choice;

    while ( choice != QUIT ) {

        printf("1 - Add | 2 - Print | 3 - Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case ADD:
                add();
                break;
            case PRINT:
                choice=' ';
                print();
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
