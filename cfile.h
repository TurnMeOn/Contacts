#include<stdio.h>
#include"type.h"
//#define FILENAME "contacts.dat"
#define LEN sizeof(struct Contact)

FILE * open_c(char s[])
{
    extern char FILENAME[20];
    return fopen(FILENAME,s);
}

void close_c(FILE *fp)
{
    fclose(fp);
}

struct Contact* copyc()
{
    FILE *con;
    extern char FILENAME[20];
    struct Contact* head=NULL,*p1,*p2;
    con=fopen(FILENAME,"rb");
    int n=0;
    p1=(struct Contact*)malloc(LEN);
    p2=p1;
    while(fread(p1,LEN,1,con)==1)
    {
        n++;
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct Contact*)malloc(LEN);
    }
    p2->next=NULL;
    fclose(con);
    return head;
}
