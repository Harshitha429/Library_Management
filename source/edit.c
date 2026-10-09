#include "library.h"

static void read_line(char *s, int n)
{
    if (fgets(s,n,stdin)) s[strcspn(s,"\n")]='\0';
}

static Book *find_exact(Book *head, const char *name, const char *author)
{
    while (head) {
        if (!strcmp(head->name,name) && !strcmp(head->author,author))
            return head;
        head=head->next;
    }
    return NULL;
}

void edit_book(Book *head)
{
    char old_name[NAME_LEN], old_author[AUTHOR_LEN];
    char new_name[NAME_LEN], new_author[AUTHOR_LEN];
    int choice, n;
    Book *b;

    printf("Enter current book name: "); read_line(old_name,NAME_LEN);
    printf("Enter current author name: "); read_line(old_author,AUTHOR_LEN);

    b=find_exact(head,old_name,old_author);
    if (!b) { printf("Book not found.\n"); return; }

    printf("\n1. Edit book name\n2. Edit author name\n3. Edit pages\n4. Edit number of books\nEnter choice: ");
    if (scanf("%d",&choice)!=1) {
        while(getchar()!='\n');
        printf("Invalid choice.\n"); return;
    }
    while(getchar()!='\n');

    switch(choice) {
    case 1:
        printf("Enter new book name: "); read_line(new_name,NAME_LEN);
        if (!new_name[0]) { printf("Book name cannot be empty.\n"); return; }
        if (exact_book_exists(head,new_name,b->author) &&
            strcmp(new_name,b->name)!=0) { printf("Duplicate book entry.\n"); return; }
        strcpy(b->name,new_name);
        break;
    case 2:
        printf("Enter new author name: "); read_line(new_author,AUTHOR_LEN);
        if (!new_author[0]) { printf("Author name cannot be empty.\n"); return; }
        if (exact_book_exists(head,b->name,new_author) &&
            strcmp(new_author,b->author)!=0) { printf("Duplicate book entry.\n"); return; }
        strcpy(b->author,new_author);
        break;
    case 3:
        printf("Enter new number of pages: ");
        if (scanf("%d",&n)!=1 || n<=0) {
            while(getchar()!='\n'); printf("Invalid page count.\n"); return;
        }
        while(getchar()!='\n'); b->pages=n; break;
    case 4:
        printf("Enter new number of books: ");
        if (scanf("%d",&n)!=1 || n<0) {
            while(getchar()!='\n'); printf("Invalid book count.\n"); return;
        }
        while(getchar()!='\n'); b->available=n; break;
    default:
        printf("Invalid choice.\n"); return;
    }
    printf("Book information updated successfully.\n");
}
