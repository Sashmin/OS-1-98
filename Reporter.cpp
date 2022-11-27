#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Employee.h"

int binFileSize(std::string binFile)
{
    const char* ch = binFile.c_str();
    FILE *fin = fopen(ch, "r+b");
    fseek(fin, 0, SEEK_END);
    int answer = ftell(fin);
    fseek(fin, 0, SEEK_SET);
    return answer;
}

int main(int argc, char* argv[])
{
    FILE *fin = fopen(argv[1], "rb");
    FILE *fout = fopen(argv[2], "w");
    //int numOfEmployees = binFileSize(argv[1]) / sizeof(Employee);

    fprintf(fout, "Report from %s\n", argv[1]);
    fprintf(fout, "                  ID                NAME               HOURS        TOTAL SALARY\n");

    for (int i = 0; i < binFileSize(argv[1]) / sizeof(Employee); i++)
    {
        Employee temp;
        fread(&temp, sizeof(Employee), 1, fin);
        writeEmpToTxtFile(temp, fout);
        fprintf(fout, "%20.f\n", temp.hours * atoi(argv[3]));
    }
    fclose(fout);
    fclose(fin);
}