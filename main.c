#include<stdio.h>
#include"login.h"
#include"func.h"



int main()
{
    while(1)
    {
        while(login())
        {
            func();
        }
    }
    return 0;
}
