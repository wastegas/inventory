#include "menu.h"

void menu() {

    char choice;

    while ( choice != 'q' || choice != 'Q' ) {

        printf("A - Add | S = Search | E = Edit | D - Delete | P - Print | Q - Quit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
            case 'A':
                add();
                break;
            case 's':
            case 'S':
                search();
                break;
            case 'e':
            case 'E':
                edit();
                break;
            case 'p':
            case 'P':
                print();
                break;
            case 'd':
            case 'D':
                delete();
                break;
            case 'q':
            case 'Q':
                return;
            default:
                printf("%c is an invalid choice\n", choice);
                break;
        }
    }

}
