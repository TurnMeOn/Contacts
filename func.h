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
#define CHOICES0 "01234567"

void print_menu()
{
    printf("------------MENU------------\n\n");
    printf("Contacts\n\n");
    printf("0 - Quit.\n");
    printf("1 - Add contact(s).\n");
    printf("2 - Remove a contact.\n");
    printf("3 - Edit a contact.\n");
    printf("4 - Search a contact.\n");
    printf("5 - Sort contacts.\n");
    printf("6 - Count contacts.\n");
    printf("7 - Show contacts.\n");
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
    else if(choice==5)printf("PASS\N");
    else if(choice==6)print_total();
    else if(choice==7)readc();
}

