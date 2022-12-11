#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string>
#include "..\Employee\Employee.h"

void outputBinaryFile(std::string fileName, int numOfEntries)
{
    //std::ifstream fin(fileName, std::ios::binary);
    FILE* fin;
    errno_t finStream = fopen_s(&fin, fileName.c_str(), "rb");
    //std::cout << fileName << ":\n";
    fprintf(stdout, "%s:\n", fileName.c_str());
    fprintf(stdout, "%20s%20s%20s\n", "ID", "NAME", "HOURS");

    Employee temp;
    for (int i = 0; i < numOfEntries; i++)
    {
        //fin.read((char*)&temp, sizeof(Employee));
        fread(&temp, sizeof(Employee), 1, fin);
        //std::cout << temp << '\n';
        writeEmpToTxtFile(temp, stdout);
        fprintf(stdout, "\n");
    }
}

void outputReport(std::string fileName, int numOfEntries)
{
    FILE* fin;
    errno_t file = fopen_s(&fin, fileName.c_str(), "r");

    char temp[100];
    for (int i = 0; i < numOfEntries + 1; i++)
    {
        fgets(temp, 99, fin);
        printf("%s", temp);
    }
}


int main()
{
    std::string binFileName;
    int numOfEntries;

    std::cout << "Enter name of the file: ";
    std::cin >> binFileName;
    std::cout << "Enter number of entries: ";
    std::cin >> numOfEntries;
    std::string commandLineRequest;
    LPSTR lpwCommandLineRequest;

    commandLineRequest = "Creator.exe";
    commandLineRequest += " " + binFileName + " " + std::to_string(numOfEntries);
    // std::wstring wCommandLineRequest = std::wstring(commandLineRequest.begin(), commandLineRequest.end());
    lpwCommandLineRequest = &commandLineRequest[0];

    STARTUPINFOA si;
    PROCESS_INFORMATION piApp;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    CreateProcessA(NULL, lpwCommandLineRequest, NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp);

    WaitForSingleObject(piApp.hProcess, INFINITE);

    CloseHandle(piApp.hProcess);

    std::cout << '\n';
    outputBinaryFile(binFileName, numOfEntries);
    std::cout << '\n';

    std::string txtFileName;
    int hourlySalary;

    std::cout << "Enter text report file: ";
    std::cin >> txtFileName;
    std::cout << "Enter hourly salary: ";
    std::cin >> hourlySalary;

    commandLineRequest = "Reporter.exe";
    commandLineRequest += " " + binFileName + " " + txtFileName + " " + std::to_string(hourlySalary);
    lpwCommandLineRequest = &commandLineRequest[0];

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

