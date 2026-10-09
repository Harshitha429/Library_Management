#include "library.h"

int save_books(Book *head)
{
    FILE *fp=fopen(DATA_FILE,"w");
    if(!fp) { perror("Unable to save library"); return 0; }

    while(head) {
        fprintf(fp,"%s\n%s\n%d\n%d\n",
                head->name,head->author,head->pages,head->available);
        head=head->next;
    }
    fclose(fp);
    printf("Library data saved successfully.\n");
    return 1;
}

int load_books(Book **head)
{
    FILE *fp=fopen(DATA_FILE,"r");
    char name[NAME_LEN],author[AUTHOR_LEN],line[64];
    int pages,available;
    Book *b,*temp;

    if(!fp) return 1; /* First launch: no data file yet. */

    while(fgets(name,sizeof(name),fp)) {
        if(!fgets(author,sizeof(author),fp)) break;
        if(!fgets(line,sizeof(line),fp)) break;
        pages=atoi(line);
        if(!fgets(line,sizeof(line),fp)) break;
        available=atoi(line);

        name[strcspn(name,"\n")]='\0';
        author[strcspn(author,"\n")]='\0';

        if(exact_book_exists(*head,name,author)) continue;

        b=create_book(name,author,pages,available);
        if(!b) { fclose(fp); return 0; }

        if(!*head) *head=b;
        else {
            temp=*head;
            while(temp->next) temp=temp->next;
            temp->next=b;
        }
    }
    fclose(fp);
    return 1;
}
