#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include"write.h"
#include"search.h"
#include"delete.h"
#include"countc.h"
#include"read.h"
#include"edit.h"
#include"sortc.h"
#define CHOICES0 "01234567"

void print_menu()
{
    printf("\n\t============================================通讯录管理系统============================================\n\n");
    printf("\t\t\t\t\t\t\tContacts\n\n");
    printf("\t\t\t\t\t\t0 - 退出.\n");
    printf("\t\t\t\t\t\t1 - 添加通讯录.\n");
    printf("\t\t\t\t\t\t2 - 删除通讯录.\n");
    printf("\t\t\t\t\t\t3 - 编辑通讯录.\n");
    printf("\t\t\t\t\t\t4 - 查找通讯录.\n");
    printf("\t\t\t\t\t\t5 - 排序.\n");
    printf("\t\t\t\t\t\t6 - 统计.\n");
    printf("\t\t\t\t\t\t7 - 显示通讯录.\n");
}

int selectc()
{
    print_menu();
    char c[10];
    do
    {
        printf("\nChoice:");
        gets(c);
    }while(strlen(c)!=1||strchr(CHOICES0,c[0])==NULL);
    return c[0]-'0';
}

void func()
{
    int choice;
    choice=selectc();
    printf("\n");
    if(choice==0)exit(0);
    else if(choice==1)writec(add(),"ab");
    else if(choice==2)removec();
    else if(choice==3)edit();
    else if(choice==4)
    {
        showc(findc());
        //system("pause");
        //sleep(2);
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
    else if(choice==5)sortc();
    else if(choice==6)print_total();
    else if(choice==7)readc();
}

