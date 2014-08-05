#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <errno.h>
#include "menu.h"

void menu() {

    int choice;

    while ( choice != 'Q' ) {
    
        printf("\nA - Add | S = Search | E = Edit | D - Delete | P - Print | Q - Quit -> ");
        scanf(" %c", &choice);
        switch (toupper(choice)) {
            case 'A':
                add();
                break;
            case 'S':
                search();
                break;
            case 'E':
                edit();
                break;
            case 'P':
                print();
                break;
            case 'D':
                delete();
                break;
            case 'Q':
                return;
            default:
                printf("%c is an invalid choice\n", choice);
                break;
        }
    }

}
