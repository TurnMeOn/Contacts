#include<stdio.h>
#include<stdlib.h>


int delete_menu()
{
	printf("------------DELETE------------\n\n");
	printf("0 - Back.\n");
	printf("1 - Search by name.\n");
	printf("2 - Search by tel.\n");
	printf("3 - Search by E-mail.\n");
	char c[10];
	do
	{
		printf("\nChoice:");
		gets(c);
	} while (strlen(c)!=1||strchr(CHOICES, c[0])==NULL);
	printf("\n");
	return c[0] - '0';
}

int confirm()
{
    char s[10];
    printf("Are you SURE to remove the contact?(Y/N) ");
    gets(s);
    if(strcmp(s,"Y")&&strcmp(s,"y"))
    {
        printf("\nDelete canceled.\n");
        return 0;
    }
    else return 1;
}


struct Contact* delete_by_name(char name[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->name,name)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such content in the contacts.\n\n");
    return NULL;
}

struct Contact* delete_by_tel(char tel[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->tel,tel)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such content in the contacts.\n\n");
    return NULL;
}

struct Contact* delete_by_email(char email[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(head->next==NULL)break;
		if(strcmp((head->next)->email,email)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such countent in the contacts.\n\n");
    return NULL;
}

struct Contact* deletec(struct Contact *head) //·µ»ØÖ¸Õë
{
	int c;
	char s[30];
	c=delete_menu();
	if (c == 0)return NULL;
    else if (c == 1)
	{
		printf("Please enter the name: ");
		gets(s);
        if(strcmp(s,head->name)!=0)return delete_by_name(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("Delete successfully!\n\n");
        return NULL;
	}
	else if (c == 2)
	{
		printf("Please enter the tel: ");
		gets(s);
        if(strcmp(s,head->tel)!=0)return delete_by_tel(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("Delete successfully!\n\n");
        return NULL;
	}
	else if (c == 3)
	{
		printf("Please enter the e-mail: ");
		gets(s);
        if(strcmp(s,head->email)!=0)return delete_by_email(s,head);
        showc(head);
        if(!confirm())return NULL;
        head=head->next;
        writec(head,"wb");
        printf("Delete successfully!\n\n");
        return NULL;
	}
}

void removec()
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
    printf("Delete successfully!\n\n");
}


