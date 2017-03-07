#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define CHOICES "0123"

int search_menu()
{
	printf("------------SEARCH------------\n\n");
	printf("0 - 返回.\n");
	printf("1 - 按姓名查找.\n");
	printf("2 - 按电话查找.\n");
	printf("3 - 按E-mail查找.\n");
	char c[10];
	do
	{
		printf("\nChoice:");
		gets(c);
	} while (strlen(c)!=1||strchr(CHOICES, c[0])==NULL);
	printf("\n");
	return c[0] - '0';
}

struct Contact* search_by_name(char name[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(strcmp(head->name,name)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such content in the contacts.\n\n");
    return NULL;
}

struct Contact* search_by_tel(char tel[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(strcmp(head->tel,tel)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such content in the contacts.\n\n");
    return NULL;
}

struct Contact* search_by_email(char email[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(strcmp(head->email,email)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such content in the contacts.\n\n");
    return NULL;
}

struct Contact* findc() //·µ»ØÖ¸Õë
{
	int c;
	char s[30];
	c=search_menu();
	struct Contact* head;
	head=copyc();
	if (c == 0)return NULL;
    else if (c == 1)
	{
		printf("请输入姓名：");
		gets(s);
        return search_by_name(s,head);
	}
	else if (c == 2)
	{
		printf("请输入电话：");
		gets(s);
        return search_by_tel(s,head);
	}
	else if (c == 3)
	{
		printf("请输入E-mail：");
		gets(s);
        return search_by_email(s,head);
	}
}

void showc(struct Contact* p)
{
    if(p!=NULL)
    {
        printf(" _________________________________________\n");
        printf("|%-10s|%-30s|\n","Name",p->name);
        printf("|%-10s|%-30s|\n","Gender",p->gender);
        printf("|%-10s|%-30s|\n","Tel",p->tel);
        printf("|%-10s|%-30s|\n","E-mail",p->email);
        printf("|__________|______________________________|\n\n");
    }
}

