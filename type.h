#include<stdio.h>


struct Contact
{
    char name[10];
    char gender[10];
    char tel[20];
    char email[30];
    struct Contact *next;
};

