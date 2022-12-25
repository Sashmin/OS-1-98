#include <iostream>
#include <fstream>
#include "..\Employee\Employee.h"
#pragma warning(disable: 4996)

int main(int argc, char* argv[])
{
	FILE* binOutputFile = fopen(argv[1], "wb");
	Employee temp;
	for (int i = 0; i < atoi(argv[2]); i++)
	{
		printf_s("%d:\n", i + 1);
		scanf_s("%d", &temp.num);
		scanf_s("%s", temp.name, 10);
		scanf_s("%lf", &temp.hours);

		fwrite(&temp,
			 sizeof(Employee),
			 1,
			 binOutputFile);
	}
	fclose(binOutputFile);
}
