#include<stdio.h>
#include<string.h>

//�����û��ṹ��
struct usr
{
    char username[20];
    char psd[20];
    struct usr* next;
};

char FILENAME[20];

//��½��������½�ɹ�����1�����򷵻�0
int sign_in()
{
    char usr[20],password[20];
    printf("�û�����");
    gets(usr);
    printf("���룺");
    gets(password);

    FILE* info;
    info=fopen("log.dat","rb");
    if(info==NULL)
    {
        printf("����ע��\n\n");
        return 0;
    }
    struct usr* p;
    p=(struct usr*)malloc(sizeof(struct usr));
    while(fread(p,sizeof(struct usr),1,info)==1)
    {
        if(strcmp(p->username,usr)==0&&strcmp(p->psd,password)==0)
        {
            strcpy(FILENAME,usr);
            printf("\n");
            return 1;
        }
    }
	printf("�������.\n\n");
	return 0;

}

//ע�ắ��
int sign_up()
{
    char username[20],password[20];
    printf("�û�����");
    gets(username);
    printf("���룺");
    gets(password);
    struct usr newone;
    strcpy(newone.username,username);
    strcpy(newone.psd,password);
    newone.next=NULL;
    //write information
    FILE* info;
    struct usr* p;
    info=fopen("log.dat","rb");
    p=(struct usr*)malloc(sizeof(struct usr));
    while(fread(p,sizeof(struct usr),1,info)==1)
    {
        if(strcmp(p->username,newone.username)==0)
        {
            printf("�û����Ѵ���\n\n");
            fclose(info);
            return 0;
        }
    }
    info=fopen("log.dat","ab");
    fwrite(&newone,sizeof(struct usr),1,info);
    fclose(info);
    printf("\n");
    return 0;
}


//��½��ע��
int login()
{
    printf("0 - �˳�.\n");
    printf("1 - ��½.\n");
    printf("2 - ע��.\n");
    char c[6];
    char ch[]="012";
    do
    {
        printf("Choice: ");
        gets(c);
    }while(strlen(c)!=1||strchr(ch,c[0])==NULL);
    if(c[0]=='0')
    {
        printf("\n");
        exit(0);
    }
    else if(c[0]=='1')
    {
        printf("\n");
        return sign_in();
    }
    else if(c[0]=='2')
    {
        printf("\n");
        return sign_up();
    }
}
