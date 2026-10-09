#include "library.h"

static void read_line(char *s,int n)
{
    if(fgets(s,n,stdin)) s[strcspn(s,"\n")]='\0';
}

void take_book(Book *head)
{
    char name[NAME_LEN];
    Book *p,*selected=NULL;
    int count=0,choice;

    printf("Enter book name: ");
    read_line(name,NAME_LEN);

    p=head;
    while(p) {
        if(!strcmp(p->name,name)) {
            count++;
            printf("%d. Author: %s | Pages: %d | Available: %d\n",
                   count,p->author,p->pages,p->available);
        }
        p=p->next;
    }

    if(!count) { printf("Book not found.\n"); return; }

    printf("\nSelect author:\n");
    p=head; count=0;
    while(p) {
        if(!strcmp(p->name,name)) {
            count++;
            printf("%d. %s\n",count,p->author);
        }
        p=p->next;
    }

    printf("Enter choice: ");
    if(scanf("%d",&choice)!=1) {
        while(getchar()!='\n'); printf("Invalid choice.\n"); return;
    }
    while(getchar()!='\n');

    p=head; count=0;
    while(p) {
        if(!strcmp(p->name,name)) {
            count++;
            if(count==choice) { selected=p; break; }
        }
        p=p->next;
    }

    if(!selected) { printf("Invalid author choice.\n"); return; }

    if(selected->available<=0) {
        printf("No copy of \"%s\" by %s is available.\n",
               selected->name,selected->author);
        return;
    }

    selected->available--;
    printf("Book taken successfully.\n");
    printf("Book   : %s\nAuthor : %s\nRemaining copies: %d\n",
           selected->name,selected->author,selected->available);
}
