#include "library.h"

Book *create_book(const char *name, const char *author, int pages, int available)
{
    Book *b = malloc(sizeof(Book));
    if (!b) { perror("malloc"); return NULL; }

    strncpy(b->name, name, NAME_LEN-1);
    b->name[NAME_LEN-1] = '\0';
    strncpy(b->author, author, AUTHOR_LEN-1);
    b->author[AUTHOR_LEN-1] = '\0';
    b->pages = pages;
    b->available = available;
    b->next = NULL;
    return b;
}

int exact_book_exists(Book *head, const char *name, const char *author)
{
    while (head) {
        if (!strcmp(head->name, name) && !strcmp(head->author, author))
            return 1;
        head = head->next;
    }
    return 0;
}

void free_books(Book *head)
{
    Book *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
