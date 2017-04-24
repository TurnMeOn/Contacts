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

char FILENAME[20];

void print_menu()   //打印主菜单
{
    printf("------------通讯录------------\n\n");
    //printf("Contacts\n\n");
    printf("0 - 退出.\n");
    printf("1 - 添加.\n");
    printf("2 - 删除.\n");
    printf("3 - 编辑.\n");
    printf("4 - 查找.\n");
    printf("5 - 排序.\n");
    printf("6 - 统计.\n");
    printf("7 - 显示.\n");
}

int selectc()   //向用户询问选项并将其返回
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

void func() //调用各项功能
{
    while(1)
    {
        int choice;
        choice=selectc();
        printf("\n");
        if(choice==0)break;
        else if(choice==1)writec(add(),"ab+");
        else if(choice==2)removec();
        else if(choice==3)edit();
        else if(choice==4)
        {
            showc(findc());
            char t[5];
            printf("按回车继续...");
            gets(t);
        }
        else if(choice==5)sortsort();
        else if(choice==6)print_total();
        else if(choice==7)readc();
    }
}
