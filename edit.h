
int edit_menu()
{
	printf("-------------EDIT-------------\n\n");
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

int edit_menu2()
{
	printf("------------EDIT------------\n\n");
	printf("0 - Cancel.\n");
	printf("1 - Edit name.\n");
	printf("2 - Edit gender.\n");
	printf("3 - Edit tel.\n");
	printf("4 - Edit e-mail.\n");
	char c[10];
	do
	{
		printf("\nChoice:");
		gets(c);
	} while (strlen(c)!=1||strchr(CHOICES, c[0])==NULL);
	printf("\n");
	return c[0] - '0';
}

struct Contact* edit_by_name(char name[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(strcmp(head->name,name)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such content in the contacts.\n\n");
	sleep(1);
    return NULL;
}

struct Contact* edit_by_tel(char tel[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(strcmp(head->tel,tel)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such content in the contacts.\n\n");
	sleep(1);
    return NULL;
}

struct Contact* edit_by_email(char email[],struct Contact* head)
{
	while(head!=NULL)
	{
		if(strcmp(head->email,email)==0)return head;
		head=head->next;
	}
	printf("Sorry,no such content in the contacts.\n\n");
	sleep(1);
    return NULL;
}

struct Contact* editc(struct Contact* head) //·µ»ØÖ¸Õë
{
	int c;
	char s[30];
	c=edit_menu();
	if (c == 0)return NULL;
    else if (c == 1)
	{
		printf("Please enter the name: ");
		gets(s);
        return edit_by_name(s,head);
	}
	else if (c == 2)
	{
		printf("Please enter the tel: ");
		gets(s);
        return edit_by_tel(s,head);
	}
	else if (c == 3)
	{
		printf("Please enter the e-mail: ");
		gets(s);
        return edit_by_email(s,head);
	}
}

void edit()
{
    struct Contact *head,*p;
    char s[30];
    int c;
    head=copyc();
    p=editc(head);
    if(p==NULL)return;
    showc(p);
    c=edit_menu2();
    if(c==0)return;
    else if(c==1)
    {
       printf("Enter the new name:");
       gets(s);
       strcpy(p->name,s);
       writec(head,"wb");
       printf("Update successfully!\n\n");
       //sleep(1);
       char t[5];
       printf("Press enter to continue...");
       gets(t);
    }
    else if(c==2)
    {
        do
        {
            printf("Enter the new gender [0(Male)/1(Female)]:");
            gets(s);
        }while(strcmp(s,"0")&&strcmp(s,"1"));
        if(strcmp(s,"0")==0)strcpy(p->gender,"Male");
        else if(strcmp(s,"1")==0)strcpy(p->gender,"Female");
        writec(head,"wb");
        printf("Update successfully!\n\n");
        //sleep(1);
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
    else if(c==3)
    {
        printf("Enter the new tel:");
        gets(s);
        strcpy(p->tel,s);
        writec(head,"wb");
        printf("Update successfully!\n\n");
        //sleep(1);
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
    else if(c==4)
    {
        printf("Enter the new e-mail:");
        gets(s);
        strcpy(p->email,s);
        writec(head,"wb");
        printf("Update successfully!\n\n");
        //sleep(1);
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
}
