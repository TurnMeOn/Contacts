
void print_title()
{
    printf(" ____________________________________________________________________\n");
    printf("|%-10s|%-10s|%-15s|%-30s|\n","Name","Gender","Tel","E-mail");
}
void readc()
{
    FILE *con;
    struct Contact *p;
    p=(struct Contact*)malloc(LEN);
    con=fopen(FILENAME,"rb");
    if(con==NULL)
    {
        printf("Sorry,your contacts are empty.\n\n");
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
    //system("pause");
    //sleep(1);
    char t[5];
    printf("Press enter to continue...\n");
    gets(t);
}

