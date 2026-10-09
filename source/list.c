#include "library.h"

void list_books(Book *head)
{
    int count = 0;
    if (!head) { printf("Library is empty.\n"); return; }

    printf("\n%-30s %-25s %-10s %-12s\n",
           "BOOK NAME","AUTHOR","PAGES","AVAILABLE");
    printf("-------------------------------------------------------------------------------\n");

    while (head) {
        printf("%-30s %-25s %-10d %-12d\n",
               head->name, head->author, head->pages, head->available);
        count++;
        head = head->next;
    }
    printf("\nTotal book records: %d\n", count);
}

void count_book(Book *head)
{
    char name[NAME_LEN];
    int total=0, records=0;

    printf("Enter book name: ");
    if (!fgets(name, NAME_LEN, stdin)) return;
    name[strcspn(name,"\n")]='\0';

    while (head) {
        if (!strcmp(head->name,name)) {
            total += head->available;
            records++;
        }
        head=head->next;
    }

    if (!records) printf("Book not found.\n");
    else {
        printf("Book: %s\n",name);
        printf("Number of author records: %d\n",records);
        printf("Total available copies: %d\n",total);
    }
}
