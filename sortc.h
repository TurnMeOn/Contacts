#include<stdio.h>


int print_sort()
{
    char c[10];
    printf("Reverse?(Y/N):");
    gets(c);
    if(strcmp(c,"y")==0||strcmp(c,"Y")==0)return 1;
    else return 0;
}

void sortc()
{
    int tot=count_total();
    FILE *con=NULL;
    con=open_c("rb");
    struct Contact c[tot];
    struct Contact tem;
    int i,j;
    for(i=0;i<tot;i++)
    {
        fread(c+i,LEN,1,con);
    }
    fclose(con);
    con=NULL;
    if(print_sort()==0)
    {
        for(i=0;i<tot;i++)
        {
            for(j=i+1;j<tot;j++)
            {
                if(strcmp(c[i].name,c[j].name)>0)
                {
                    tem=c[i];
                    c[i]=c[j];
                    c[j]=tem;
                }
            }
        }
    }
    else
    {
        for(i=0;i<tot;i++)
        {
            for(j=i+1;j<tot;j++)
            {
                if(strcmp(c[i].name,c[j].name)<0)
                {
                    tem=c[i];
                    c[i]=c[j];
                    c[j]=tem;
                }
            }
        }
    }
    con=open_c("wb");
    for(i=0;i<tot;i++)
    {
        fwrite(c+i,LEN,1,con);
    }
    fclose(con);
    printf("\nÅÅÐòÍê³É.\n\n");
}

