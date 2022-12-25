#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string>
#include "..\Employee\Employee.h"

const int MAX_STR_SIZE = 200;

void outputBinaryFile(char fileName[], int numOfEntries)
{
	FILE* fin;
	errno_t finStream = fopen_s(&fin, fileName, "rb");
	fprintf(stdout, "%s:\n", fileName);
	fprintf(stdout, "%20s%20s%20s\n", "ID", "NAME", "HOURS");

	Employee temp;
	for (int i = 0; i < numOfEntries; i++)
	{
		fread(&temp, sizeof(Employee), 1, fin);
		writeEmpToTxtFile(temp, stdout);
		fprintf(stdout, "\n");
	}
}

void outputReport(char fileName[], int numOfEntries)
{
	FILE* fin;
	errno_t file = fopen_s(&fin, fileName, "r");

	char temp[MAX_STR_SIZE + 1];
	for (int i = 0; i < numOfEntries + 1; i++)
	{
		fgets(temp, MAX_STR_SIZE, fin);
		printf("%s", temp);
	}
}


int main()
{
	char binFileName[MAX_STR_SIZE + 1] = "";
	int numOfEntries = 0;

	printf("Enter name of the file (without extension): ");
	scanf_s("%s", binFileName, MAX_STR_SIZE);
	strcat_s(binFileName, ".bin");

	printf("Enter number of entries: ");
	scanf_s("%d", &numOfEntries);
	char lpwCommandLineRequest[MAX_STR_SIZE + 1] = "";

	
	sprintf_s(lpwCommandLineRequest, "Creator.exe %s %d", binFileName, numOfEntries);

	STARTUPINFOA si;
	PROCESS_INFORMATION piApp;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	CreateProcessA(NULL, lpwCommandLineRequest, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp);

	WaitForSingleObject(piApp.hProcess, INFINITE);

	CloseHandle(piApp.hProcess);

	printf("\n");
	outputBinaryFile(binFileName, numOfEntries);
	printf("\n");

	char txtFileName[MAX_STR_SIZE + 1] = "";
	int hourlySalary = 0;

	printf("Enter text report file name (without extension): ");
	scanf_s("%s", txtFileName, MAX_STR_SIZE);
	strcat_s(txtFileName, ".txt");

	printf("Enter hourly salary: ");
	scanf_s("%d", &hourlySalary);

	sprintf_s(lpwCommandLineRequest, "Reporter.exe %s %s %d", binFileName, txtFileName, hourlySalary);

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	CreateProcessA(NULL, lpwCommandLineRequest, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp);

	WaitForSingleObject(piApp.hProcess, INFINITE);

	std::cout << '\n';
	outputReport(txtFileName, numOfEntries);
	std::cout << '\n';

	CloseHandle(piApp.hProcess);



}

