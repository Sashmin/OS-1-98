#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <fstream>
#include <iomanip>

struct Employee
{
    int num;
    char name[10];
    double hours;
};

// std::istream& operator>>(std::istream& fin, Employee& emp)
// {
//     return fin >> emp.num >> emp.name >> emp.hours;
// }

// std::ostream& operator<<(std::ostream& fout, const Employee& emp)
// {
//     return fout << emp.num << std::setw(20) << emp.name << std::setw(20) << emp.hours;
// }



#endif