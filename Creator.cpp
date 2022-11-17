#include <iostream>
#include <fstream>
#include "Employee.h"

int main(int argc, char* argv[])
{
    std::ofstream fout(argv[1], std::ios::binary);
    Employee temp;
    for (int i = 0; i < atoi(argv[2]); i++)
    {
        std::cin >> temp;
        fout.write((char*)&temp, sizeof(Employee));
    }

    fout.close();
}
