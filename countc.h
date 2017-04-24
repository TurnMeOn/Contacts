#include<stdio.h>

int count_total()   //从文件中获取链表，返回链表中结构体的数目
{
    FILE *con;
    extern char FILENAME[20];
    con=fopen(FILENAME,"rb");
    int total=0;
    struct Contact* p;
    p=(struct Contact*)malloc(LEN);
    while(fread(p,LEN,1,con)==1)
    {
        total+=1;
    }
    fclose(con);
    return total;
}

int count_male()    //从文件中获取链表，返回链表中成员gender为"Male"的结构体的数目
{
    FILE *con;
    extern char FILENAME[20];
    con=fopen(FILENAME,"rb");
    int male=0;
    struct Contact* p;
    p=(struct Contact*)malloc(LEN);
    while(fread(p,LEN,1,con)==1)
    {
        if(strcmp(p->gender,"Male")==0)male+=1;
    }
    fclose(con);
    return male;
}

void print_total()  //以表格的形式打印出文件中结构体的信息
{
    int total=count_total(),male=count_male();
    printf(" ___________________\n");
    printf("|%-10s|%8d|\n","总数",total);
    printf("|%-10s|%8d|\n","女性",total-male);
    printf("|%-10s|%8d|\n","男性",male);
    printf("|__________|________|\n\n");
    char t[5];
    printf("Press enter to continue...\n");
    gets(t);
}
