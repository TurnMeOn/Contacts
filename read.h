
void print_title()  //打印表格的第一行
{
    printf(" ____________________________________________________________________\n");
    printf("|%-10s|%-10s|%-15s|%-30s|\n","姓名","性别","电话","E-mail");
}
void readc()    //从文件中读取结构体，并以表格的形式打印出来
{
    FILE *con;
    struct Contact *p;
    p=(struct Contact*)malloc(LEN);
    extern char FILENAME[20];
    con=fopen(FILENAME,"rb");
    if(con==NULL)
    {
        printf("请先建立通讯录.\n\n");
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
    printf("按回车键继续...\n");
    gets(t);
}
