#include "library.h"

static void read_text(const char *msg, char *buf, int size)
{
    printf("%s", msg);
    if (!fgets(buf, size, stdin)) { buf[0]='\0'; return; }
    buf[strcspn(buf, "\n")] = '\0';
}

static int read_positive(const char *msg)
{
    int n;
    while (1) {
        printf("%s", msg);
        if (scanf("%d", &n) == 1 && n > 0) {
            while (getchar() != '\n');
            return n;
        }
        printf("Invalid input. Enter a positive number.\n");
        while (getchar() != '\n');
    }
}

void add_new_book(Book **head)
{
    char name[NAME_LEN], author[AUTHOR_LEN];
    int pages;
    Book *new_book, *temp;

    read_text("Enter book name   : ", name, NAME_LEN);
    if (!name[0]) { printf("Book name cannot be empty.\n"); return; }

    read_text("Enter author name : ", author, AUTHOR_LEN);
    if (!author[0]) { printf("Author name cannot be empty.\n"); return; }

    if (exact_book_exists(*head, name, author)) {
        printf("Duplicate book entry. Same book and author already exist.\n");
        return;
    }

    pages = read_positive("Enter number of pages: ");
    new_book = create_book(name, author, pages, 1);
    if (!new_book) return;

    if (!*head) *head = new_book;
    else {
        temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = new_book;
    }
    printf("Book added successfully.\n");
}
