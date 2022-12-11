#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "..\Employee\Employee.h"
#pragma warning(disable: 4996)

int binFileSize(std::string binFile)
{
	const char* ch = binFile.c_str();
	//FILE *fin = fopen(ch, "r+b");
	FILE* fin = fopen("input.bin", "rb");
	if (!fin) perror("failed to open");
	fseek(fin, 0, SEEK_END);
	int answer = ftell(fin);
	fseek(fin, 0, SEEK_SET);
	return answer;
	if (answer == 72) return answer;
	return 48;
}

int main(int argc, char* argv[])
{
	FILE *fin = fopen(argv[1], "rb");
	FILE *fout = fopen(argv[2], "w");
	if (!fin) perror("failed to open");
	//int numOfEmployees = binFileSize(argv[1]) / sizeof(Employee);

	//fprintf(fout, "                  ID                NAME               HOURS        TOTAL SALARY\n");
	fprintf(fout, "%20s%20s%20s%20s\n", "ID", "NAME", "HOURS", "TOTAL SALARY");

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