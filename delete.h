#include<stdio.h>
#include<stdlib.h>


int delete_menu()
{
	printf("------------ɾ��------------\n\n");   //��ӡɾ���˵��������û���ѡ��ֵ
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

int confirm()   //��ʾ�Ƿ�ȷ��ɾ������
{
    char s[10];
    printf("ȷ��ɾ��?(Y/N) ");
    gets(s);
    if(strcmp(s,"Y")&&strcmp(s,"y"))
    {
        printf("\nȡ��ɾ��.\n");
        return 0;
    }
    else return 1;
}


struct Contact* delete_by_name(char name[],struct Contact* head)    //���������ͷָ�룬ɾ��name��Ա���봫����ַ�����ͬ�Ľṹ��
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->name,name)==0)return head;
		head=head->next;
	}
	printf("���ݲ�����.\n\n");
    return NULL;
}

struct Contact* delete_by_tel(char tel[],struct Contact* head)  ////���������ͷָ�룬ɾ��tel��Ա���봫����ַ�����ͬ�Ľṹ��
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->tel,tel)==0)return head;
		head=head->next;
	}
	printf("���ݲ�����.\n\n");
    return NULL;
}

struct Contact* delete_by_email(char email[],struct Contact* head)  //���������ͷָ�룬ɾ��email��Ա���봫����ַ�����ͬ�Ľṹ��
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->email,email)==0)return head;
		head=head->next;
	}
	printf("���ݲ�����.\n\n");
    return NULL;
}

struct Contact* deletec(struct Contact *head) //����������������ʵ��ɾ��
{
	int c;
	char s[30];
	c=delete_menu();
	if (c == 0)return NULL;
    else if (c == 1)
	{
		printf("����������: ");
		gets(s);
        if(strcmp(s,head->name)!=0)return delete_by_name(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("ɾ���ɹ�!\n\n");
        return NULL;
	}
	else if (c == 2)
	{
		printf("������绰: ");
		gets(s);
        if(strcmp(s,head->tel)!=0)return delete_by_tel(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("ɾ���ɹ�!\n\n");
        return NULL;
	}
	else if (c == 3)
	{
		printf("������E-mail: ");
		gets(s);
        if(strcmp(s,head->email)!=0)return delete_by_email(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("ɾ���ɹ���\n\n");
        return NULL;
	}
}

void removec()  //���˵�������ɾ���������
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
    printf("ɾ���ɹ���\n\n");
}
