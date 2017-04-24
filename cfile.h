#include<stdio.h>
#include"type.h"
//#define FILENAME "contacts.dat"
#define LEN sizeof(struct Contact)

FILE * open_c(char s[]) //打开FILENAME文件并返回FILE*类型，打开方式取决于传入的字符串
{
    extern char FILENAME[20];
    return fopen(FILENAME,s);
}



struct Contact* copyc() //打开文件，并在内存中克隆出一个相同的结构体
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
