#include<stdio.h>

int count_total()   //���ļ��л�ȡ�������������нṹ�����Ŀ
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

int count_male()    //���ļ��л�ȡ�������������г�ԱgenderΪ"Male"�Ľṹ�����Ŀ
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

void print_total()  //�Ա�����ʽ��ӡ���ļ��нṹ�����Ϣ
{
    int total=count_total(),male=count_male();
    printf(" ___________________\n");
    printf("|%-10s|%8d|\n","����",total);
    printf("|%-10s|%8d|\n","Ů��",total-male);
    printf("|%-10s|%8d|\n","����",male);
    printf("|__________|________|\n\n");
    char t[5];
    printf("Press enter to continue...\n");
    gets(t);
}
