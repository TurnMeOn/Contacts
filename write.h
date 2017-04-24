#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cfile.h"
#define LEN sizeof(struct Contact)



struct Contact* add()   //在内存中构造出动态链表，并向其中添加元素，返回新链表的头指针
{
    char sex[5];
    struct Contact *head=NULL,*p1,*p2;
    p1=(struct Contact*)malloc(sizeof(struct Contact));
    p2=p1;
    printf("*Input will be finished when name is 0.\n\n");
    printf("姓名：");
    gets(p1->name);
    if(strcmp(p1->name,"0")==0)return NULL;
    do
    {
        printf("性别[0(男)/1(女)]：");
        gets(sex);
    }while(strcmp(sex,"0")&&strcmp(sex,"1"));
    if(strcmp(sex,"0")==0)strcpy(p1->gender,"男");
    else strcpy(p1->gender,"女");
    printf("电话：");
    gets(p1->tel);
    printf("E-mail:");
    gets(p1->email);
    printf("\n");
    int n=0;
    while(strcmp(p1->name,"0")!=0)
    {
        n++;
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        p1=(struct Contact*)malloc(sizeof(struct Contact));
        printf("姓名：");
        gets(p1->name);
        if(strcmp(p1->name,"0")==0)break;
        do
        {
            printf("性别[0(男)/1(女)]：");
            gets(sex);
        }while(strcmp(sex,"0")&&strcmp(sex,"1"));
        if(strcmp(sex,"0")==0)strcpy(p1->gender,"男");
        else strcpy(p1->gender,"女");
        printf("电话：");
        gets(p1->tel);
        printf("E-mail:");
        gets(p1->email);
        printf("\n");
    }
    p2->next=NULL;
    return head;
}

void writec(struct Contact* head,char s[]) // 传入头指针，将结构体数据写入文件中，写入方式由传入的字符串决定
{
    FILE *con;
    extern char FILENAME[20];
    con=fopen(FILENAME,s);
    while(head!=NULL)
    {
        fwrite(head,LEN,1,con);
        head=head->next;
    }
    fclose(con);
    printf("\n");
}
