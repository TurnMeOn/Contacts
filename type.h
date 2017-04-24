

struct Contact  //定义结构体
{
    char name[10];
    char gender[10];
    char tel[20];
    char email[30];
    struct Contact *next;
};
