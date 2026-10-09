#include "library.h"

static void display_menu(void)
{
    printf("\n------------------ MENU ------------------\n");
    printf("a/A : Add a new book to library\n");
    printf("l/L : List available books\n");
    printf("c/C : Display count of specific book\n");
    printf("e/E : Edit book information\n");
    printf("t/T : Take a book from library\n");
    printf("f/F : Find book in library\n");
    printf("s/S : Save books information\n");
    printf("q/Q : Quit\n");
    printf("-------------------------------------------\n");
    printf("Enter choice: ");
}

int main(void)
{
    Book *head=NULL;
    char input[20];
    char choice;

    if(load_books(&head))
        printf("Library data loaded successfully.\n");
    else
        printf("Warning: previous library data could not be loaded.\n");

    while(1) {
        display_menu();
        if(!fgets(input,sizeof(input),stdin)) break;
        choice=input[0];

        switch(choice) {
        case 'a': case 'A': add_new_book(&head); break;
        case 'l': case 'L': list_books(head); break;
        case 'c': case 'C': count_book(head); break;
        case 'e': case 'E': edit_book(head); break;
        case 't': case 'T': take_book(head); break;
        case 'f': case 'F': find_book(head); break;
        case 's': case 'S': save_books(head); break;
        case 'q': case 'Q':
            save_books(head);
            free_books(head);
            printf("Library application closed.\n");
            return 0;
        default: printf("Invalid option. Please try again.\n");
        }
    }

    save_books(head);
    free_books(head);
    return 0;
}
