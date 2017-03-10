#include<stdio.h>

int count_total()
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

int count_male()
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

void print_total()
{
    int total=count_total(),male=count_male();
    printf(" ___________________\n");
    printf("|%-10s|%8d|\n","Total",total);
    printf("|%-10s|%8d|\n","Female",total-male);
    printf("|%-10s|%8d|\n","Male",male);
    printf("|__________|________|\n\n");
    char t[5];
    printf("Press enter to continue...\n");
    gets(t);
}
