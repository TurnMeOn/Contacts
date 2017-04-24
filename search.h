#include<stdio.h>
#include<string.h>
#define CHOICES "0123"

int search_menu()   //��ӡ�����˵�,�����û���ѡ��ֵ
{
	printf("------------����------------\n\n");
	printf("0 - ����.\n");
	printf("1 - ����������.\n");
	printf("2 - ���绰����.\n");
	printf("3 - ��E-mail����.\n");
	char c[10];
	do
	{
		printf("\nChoice:");
		gets(c);
	} while (strlen(c)!=1||strchr(CHOICES, c[0])==NULL);
	printf("\n");
	return c[0] - '0';
}

struct Contact* search_by_name(char name[],struct Contact* head)    //��������ͷָ����ַ������ҵ��ļ���name��Ա��ֵ���ַ�����ͬ�Ľṹ�壬���������ַ,���������򷵻�NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->name,name)==0)return head;
		head=head->next;
	}
	printf("\n���ݲ�����.\n\n");
    return NULL;
}

struct Contact* search_by_tel(char tel[],struct Contact* head)  //��������ͷָ����ַ������ҵ��ļ���tel��Ա��ֵ���ַ�����ͬ�Ľṹ�壬���������ַ�����������򷵻�NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->tel,tel)==0)return head;
		head=head->next;
	}
	printf("\n���ݲ�����.\n\n");
    return NULL;
}

struct Contact* search_by_email(char email[],struct Contact* head)  //��������ͷָ����ַ������ҵ��ļ���email��Ա��ֵ���ַ�����ͬ�Ľṹ�壬���������ַ�����������򷵻�NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->email,email)==0)return head;
		head=head->next;
	}
	printf("\n���ݲ�����.\n\n");
    return NULL;
}

struct Contact* findc() //���������ĸ�����ʵ�ֲ��ҹ���
{
	int c;
	char s[30];
	c=search_menu();
	struct Contact* head;
	head=copyc();
	if (c == 0)return NULL;
    else if (c == 1)
	{
		printf("������������");
		gets(s);
        return search_by_name(s,head);
	}
	else if (c == 2)
	{
		printf("������绰��");
		gets(s);
        return search_by_tel(s,head);
	}
	else if (c == 3)
	{
		printf("������E-mail: ");
		gets(s);
        return search_by_email(s,head);
	}
}

void showc(struct Contact* p)   //����ṹ��ָ�룬����ָ��ָ��Ľṹ��ĳ�Ա�Ա�����ʽ��ӡ
{
    if(p!=NULL)
    {
        printf(" _________________________________________\n");
        printf("|%-10s|%-30s|\n","����",p->name);
        printf("|%-10s|%-30s|\n","�Ա�",p->gender);
        printf("|%-10s|%-30s|\n","�绰",p->tel);
        printf("|%-10s|%-30s|\n","E-mail",p->email);
        printf("|__________|______________________________|\n\n");
    }
}
