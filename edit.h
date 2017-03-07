
int edit_menu()
{
	printf("-------------EDIT-------------\n\n");
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

int edit_menu2()
{
	printf("------------EDIT------------\n\n");
	printf("0 - 取消.\n");
	printf("1 - 编辑姓名.\n");
	printf("2 - 编辑性别.\n");
	printf("3 - 编辑电话.\n");
	printf("4 - 编辑E-mail.\n");
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
	//sleep(1);
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
	//sleep(1);
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
	//sleep(1);
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
		printf("请输入姓名：");
		gets(s);
        return edit_by_name(s,head);
	}
	else if (c == 2)
	{
		printf("请输入电话：");
		gets(s);
        return edit_by_tel(s,head);
	}
	else if (c == 3)
	{
		printf("请输入E-mail：");
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
       printf("输入新的姓名：");
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
            printf("输入新的性别 [0(男)/1(女)]:");
            gets(s);
        }while(strcmp(s,"0")&&strcmp(s,"1"));
        if(strcmp(s,"0")==0)strcpy(p->gender,"男");
        else if(strcmp(s,"1")==0)strcpy(p->gender,"女");
        writec(head,"wb");
        printf("更改成功！\n\n");
        //sleep(1);
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
    else if(c==3)
    {
        printf("输入新的电话：");
        gets(s);
        strcpy(p->tel,s);
        writec(head,"wb");
        printf("更改成功！\n\n");
        //sleep(1);
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
    else if(c==4)
    {
        printf("输入新的E-mail：");
        gets(s);
        strcpy(p->email,s);
        writec(head,"wb");
        printf("更改成功！\n\n");
        //sleep(1);
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
}
