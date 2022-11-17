#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Employee.h"

int binFileSize(std::string binFile)
{
    std::ifstream fin(binFile, std::ios::binary);
    fin.seekg(0, std::ios::end);
    return fin.tellg();
}

int main(int argc, char* argv[])
{
    std::ifstream fin(argv[1], std::ios::binary);
    std::ofstream fout(argv[2]);
    int numOfEmployees = binFileSize(argv[1]) / sizeof(Employee);

    fout << "Report from " + std::string(argv[1]) << '\n';
    fout << "ID" << std::setw(20) << "NAME" << std::setw(20) << "HOURS" << std::setw(20) << "TOTAL SALARY" << '\n';

    for (int i = 0; i < numOfEmployees; i++)
    {
        Employee temp;
        fin.read((char*)&temp, sizeof(Employee));
        fout << temp << std::setw(20) << temp.hours * atoi(argv[3]) << '\n';
    }
}