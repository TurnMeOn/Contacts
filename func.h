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

void print_menu()   //��ӡ���˵�
{
    printf("------------ͨѶ¼------------\n\n");
    //printf("Contacts\n\n");
    printf("0 - �˳�.\n");
    printf("1 - ���.\n");
    printf("2 - ɾ��.\n");
    printf("3 - �༭.\n");
    printf("4 - ����.\n");
    printf("5 - ����.\n");
    printf("6 - ͳ��.\n");
    printf("7 - ��ʾ.\n");
}

int selectc()   //���û�ѯ��ѡ����䷵��
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

void func() //���ø����
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
            printf("���س�����...");
            gets(t);
        }
        else if(choice==5)sortsort();
        else if(choice==6)print_total();
        else if(choice==7)readc();
    }
}
