#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 100
#define AUTHOR_LEN 100
#define DATA_FILE "library.dat"

typedef struct Book {
    char name[NAME_LEN];
    char author[AUTHOR_LEN];
    int pages;
    int available;
    struct Book *next;
} Book;

typedef enum {
    ADD_BOOK=1, LIST_BOOKS, COUNT_BOOK, EDIT_BOOK,
    TAKE_BOOK, FIND_BOOK, SAVE_BOOKS, QUIT
} MenuOption;

Book *create_book(const char *, const char *, int, int);
int exact_book_exists(Book *, const char *, const char *);
void free_books(Book *);
void add_new_book(Book **);
void list_books(Book *);
void count_book(Book *);
void edit_book(Book *);
void take_book(Book *);
void find_book(Book *);
int save_books(Book *);
int load_books(Book **);
#endif
