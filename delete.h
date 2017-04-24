#include<stdio.h>
#include<stdlib.h>


int delete_menu()
{
	printf("------------删除------------\n\n");   //打印删除菜单并返回用户的选择值
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

int confirm()   //提示是否确认删除操作
{
    char s[10];
    printf("确认删除?(Y/N) ");
    gets(s);
    if(strcmp(s,"Y")&&strcmp(s,"y"))
    {
        printf("\n取消删除.\n");
        return 0;
    }
    else return 1;
}


struct Contact* delete_by_name(char name[],struct Contact* head)    //传入链表的头指针，删除name成员名与传入的字符串相同的结构体
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->name,name)==0)return head;
		head=head->next;
	}
	printf("内容不存在.\n\n");
    return NULL;
}

struct Contact* delete_by_tel(char tel[],struct Contact* head)  ////传入链表的头指针，删除tel成员名与传入的字符串相同的结构体
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->tel,tel)==0)return head;
		head=head->next;
	}
	printf("内容不存在.\n\n");
    return NULL;
}

struct Contact* delete_by_email(char email[],struct Contact* head)  //传入链表的头指针，删除email成员名与传入的字符串相同的结构体
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->email,email)==0)return head;
		head=head->next;
	}
	printf("内容不存在.\n\n");
    return NULL;
}

struct Contact* deletec(struct Contact *head) //调用以上三个函数实现删除
{
	int c;
	char s[30];
	c=delete_menu();
	if (c == 0)return NULL;
    else if (c == 1)
	{
		printf("请输入姓名: ");
		gets(s);
        if(strcmp(s,head->name)!=0)return delete_by_name(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("删除成功!\n\n");
        return NULL;
	}
	else if (c == 2)
	{
		printf("请输入电话: ");
		gets(s);
        if(strcmp(s,head->tel)!=0)return delete_by_tel(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("删除成功!\n\n");
        return NULL;
	}
	else if (c == 3)
	{
		printf("请输入E-mail: ");
		gets(s);
        if(strcmp(s,head->email)!=0)return delete_by_email(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("删除成功！\n\n");
        return NULL;
	}
}

void removec()  //将菜单界面与删除操作结合
{
    struct Contact *head,*p1,*p2;
    head=copyc();
    p1=deletec(head);
    if(p1==NULL)return;
    showc(p1->next);
    if(!confirm())return;
    p2=p1->next;
    (p1->next)=(p2->next);
    writec(head,"wb");
    printf("删除成功！\n\n");
}
