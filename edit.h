
int edit_menu()
{
	printf("-------------�༭-------------\n\n");   //��ӡ�༭�˵��������û�ѡ��ֵ
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

int edit_menu2()    //��ӡ�༭�����˵��������û�ѡ��ֵ
{
	printf("------------�༭------------\n\n");
	printf("0 - ȡ��.\n");
	printf("1 - ��������.\n");
	printf("2 - �����Ա�.\n");
	printf("3 - ���ĵ绰.\n");
	printf("4 - ����E-mail.\n");
	char c[10];
	do
	{
		printf("\nChoice:");
		gets(c);
	} while (strlen(c)!=1||strchr(CHOICES, c[0])==NULL);
	printf("\n");
	return c[0] - '0';
}

struct Contact* edit_by_name(char name[],struct Contact* head)   //��������ͷָ����ַ������ҵ��ļ���name��Ա��ֵ���ַ�����ͬ�Ľṹ�壬���������ַ,���������򷵻�NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->name,name)==0)return head;
		head=head->next;
	}
	printf("���ݲ�����.\n\n");
    return NULL;
}

struct Contact* edit_by_tel(char tel[],struct Contact* head)     //��������ͷָ����ַ������ҵ��ļ���tel��Ա��ֵ���ַ�����ͬ�Ľṹ�壬���������ַ,���������򷵻�NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->tel,tel)==0)return head;
		head=head->next;
	}
	printf("���ݲ�����.\n\n");
    return NULL;
}

struct Contact* edit_by_email(char email[],struct Contact* head)     //��������ͷָ����ַ������ҵ��ļ���email��Ա��ֵ���ַ�����ͬ�Ľṹ�壬���������ַ,���������򷵻�NULL
{
	while(head!=NULL)
	{
		if(strcmp(head->email,email)==0)return head;
		head=head->next;
	}
	printf("���ݲ�����.\n\n");
    return NULL;
}

struct Contact* editc(struct Contact* head) //�������Ϻ���ʵ�ֱ༭����
{
	int c;
	char s[30];
	c=edit_menu();
	if (c == 0)return NULL;
    else if (c == 1)
	{
		printf("������������");
		gets(s);
        return edit_by_name(s,head);
	}
	else if (c == 2)
	{
		printf("������绰��");
		gets(s);
        return edit_by_tel(s,head);
	}
	else if (c == 3)
	{
		printf("������E-mail: ");
		gets(s);
        return edit_by_email(s,head);
	}
}

void edit() //��ɾ��������˵�������
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
       printf("�������µ�������");
       gets(s);
       strcpy(p->name,s);
       writec(head,"wb");
       printf("���ĳɹ���\n\n");
       char t[5];
       printf("Press enter to continue...");
       gets(t);
    }
    else if(c==2)
    {
        do
        {
            printf("�������µ��Ա�[0(��)/1(Ů)]��");
            gets(s);
        }while(strcmp(s,"0")&&strcmp(s,"1"));
        if(strcmp(s,"0")==0)strcpy(p->gender,"��");
        else if(strcmp(s,"1")==0)strcpy(p->gender,"Ů");
        writec(head,"wb");
        printf("���ĳɹ���\n\n");
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
    else if(c==3)
    {
        printf("�������µĵ绰��");
        gets(s);
        strcpy(p->tel,s);
        writec(head,"wb");
        printf("���ĳɹ���\n\n");
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
    else if(c==4)
    {
        printf("�������µ�E-mail��");
        gets(s);
        strcpy(p->email,s);
        writec(head,"wb");
        printf("���ĳɹ���\n\n");
        char t[5];
        printf("Press enter to continue...");
        gets(t);
    }
}
