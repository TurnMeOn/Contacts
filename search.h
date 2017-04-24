#include<stdio.h>
#include<string.h>
#define CHOICES "0123"

int search_menu()   //打印搜索菜单,返回用户的选择值
{
	printf("------------查找------------\n\n");
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

struct Contact* search_by_name(char name[],struct Contact* head)    //传入链表头指针和字符串，找到文件中name成员的值与字符串相同的结构体，并返回其地址,若不存在则返回NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->name,name)==0)return head;
		head=head->next;
	}
	printf("\n内容不存在.\n\n");
    return NULL;
}

struct Contact* search_by_tel(char tel[],struct Contact* head)  //传入链表头指针和字符串，找到文件中tel成员的值与字符串相同的结构体，并返回其地址，若不存在则返回NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->tel,tel)==0)return head;
		head=head->next;
	}
	printf("\n内容不存在.\n\n");
    return NULL;
}

struct Contact* search_by_email(char email[],struct Contact* head)  //传入链表头指针和字符串，找到文件中email成员的值与字符串相同的结构体，并返回其地址，若不存在则返回NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->email,email)==0)return head;
		head=head->next;
	}
	printf("\n内容不存在.\n\n");
    return NULL;
}

struct Contact* findc() //调用以上四个函数实现查找功能
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
		printf("请输入E-mail: ");
		gets(s);
        return search_by_email(s,head);
	}
}

void showc(struct Contact* p)   //传入结构体指针，将该指针指向的结构体的成员以表格的形式打印
{
    if(p!=NULL)
    {
        printf(" _________________________________________\n");
        printf("|%-10s|%-30s|\n","姓名",p->name);
        printf("|%-10s|%-30s|\n","性别",p->gender);
        printf("|%-10s|%-30s|\n","电话",p->tel);
        printf("|%-10s|%-30s|\n","E-mail",p->email);
        printf("|__________|______________________________|\n\n");
    }
}
