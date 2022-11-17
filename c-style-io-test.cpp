#include <stdio.h>

struct Emp
{
    int num;
    char const *str;
};

void fprintEmp(Emp& emp){
    printf_s("%d %s", emp.num, emp.str);
}

int main()
{
    Emp a;
    a.num = 5;
    a.str = "Hi";
    a.str = "jj";
    fprintEmp(a);   
}