#include "library.h"

static void read_line(char *s,int n)
{
    if(fgets(s,n,stdin)) s[strcspn(s,"\n")]='\0';
}

static void find_by_name(Book *head)
{
    char name[NAME_LEN];
    int found=0;
    printf("Enter book name: "); read_line(name,NAME_LEN);

    while(head) {
        if(!strcmp(head->name,name)) {
            printf("Book: %s\nAuthor: %s\nPages: %d\nCopies: %d\n\n",
                   head->name,head->author,head->pages,head->available);
            found=1;
        }
        head=head->next;
    }
    if(!found) printf("Book not found.\n");
}

static void find_by_author(Book *head)
{
    char author[AUTHOR_LEN];
    int found=0;
    printf("Enter author name: "); read_line(author,AUTHOR_LEN);

    while(head) {
        if(!strcmp(head->author,author)) {
            printf("Book: %s\nAuthor: %s\nPages: %d\nCopies: %d\n\n",
                   head->name,head->author,head->pages,head->available);
            found=1;
        }
        head=head->next;
    }
    if(!found) printf("No books found for this author.\n");
}

void find_book(Book *head)
{
    int choice;
    printf("\n1. Find by book name\n2. Find by author\nEnter choice: ");
    if(scanf("%d",&choice)!=1) {
        while(getchar()!='\n'); printf("Invalid choice.\n"); return;
    }
    while(getchar()!='\n');

    if(choice==1) find_by_name(head);
    else if(choice==2) find_by_author(head);
    else printf("Invalid choice.\n");
}
