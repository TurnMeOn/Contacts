
void print_title()  //��ӡ���ĵ�һ��
{
    printf(" ____________________________________________________________________\n");
    printf("|%-10s|%-10s|%-15s|%-30s|\n","����","�Ա�","�绰","E-mail");
}
void readc()    //���ļ��ж�ȡ�ṹ�壬���Ա�����ʽ��ӡ����
{
    FILE *con;
    struct Contact *p;
    p=(struct Contact*)malloc(LEN);
    extern char FILENAME[20];
    con=fopen(FILENAME,"rb");
    if(con==NULL)
    {
        printf("���Ƚ���ͨѶ¼.\n\n");
        return ;
    }

    print_title();
    while(fread(p,LEN,1,con)==1)
    {
        printf("|%-10s|%-10s|%-15s|%-30s|\n",p->name,p->gender,p->tel,p->email);
    }

    fclose(con);
    printf("|__________|__________|_______________|______________________________|\n");
    printf("\n");
    char t[5];
    printf("���س�������...\n");
    gets(t);
}
