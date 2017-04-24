#include<stdio.h>


int sort_menu()
{
  printf("0 - 返回\n");
  printf("1 - 按姓名排序.\n");
  printf("2 - 按电话排序.\n");
  char c[10];
	do
	{
		printf("\nChoice:");
		gets(c);
	} while (strlen(c)!=1||strchr("012", c[0])==NULL);
	printf("\n");
	return c[0] - '0';
}

int print_sort()    //确认是否倒序排序
{
    char c[10];
    printf("倒序?(Y/N):");
    gets(c);
    if(strcmp(c,"y")==0||strcmp(c,"Y")==0)return 1;
    else return 0;
}

void sortc()    //排序功能
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
    printf("\n排序完成.\n\n");
}


void sorttel()    //排序功能
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
                if(strcmp(c[i].tel,c[j].tel)>0)
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
                if(strcmp(c[i].tel,c[j].tel)<0)
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
    printf("\n排序完成.\n\n");
}

void sortsort()
{
  int i;
  i=sort_menu();
  if(i==0)return;
  else if(i==1)sortc();
  else if(i==2)sorttel();
}
