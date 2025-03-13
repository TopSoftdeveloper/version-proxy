#include "Utils.h"
#include <windows.h>
#include <fstream>

using namespace std;

void WriteLog(int str)
{
#ifndef DEBUG
#else
	char szTemp[MAX_PATH] = { 0 };
	DWORD processID = GetCurrentProcessId();
	UINT result = GetWindowsDirectoryA(szTemp, sizeof(szTemp));
	if (result == 0)
	{
		return;
	}
	strcat(szTemp, "\\Temp\\windowsdump.log");

	ofstream outfile;
	outfile.open(szTemp, ios::app);
	outfile << processID << ":" << str << endl;
	outfile.close();
#endif
}

void WriteLog(char* str)
{
#ifndef DEBUG
#else
	if (strlen(str) == 0 ) return;
	DWORD processID = GetCurrentProcessId();

	char szTemp[MAX_PATH] = { 0 };
	UINT result = GetWindowsDirectoryA(szTemp, sizeof(szTemp));
	if (result == 0)
	{
		return;
	}
	strcat(szTemp, "\\Temp\\windowsdump.log");

	CHAR szDLLFile[MAX_PATH] = { 0 };
	CHAR szDLLName[MAX_PATH] = { 0 };

	ofstream outfile;
	outfile.open(szTemp, ios::app);
	outfile << processID << ":" << str << endl;
	outfile.close();
#endif
}

void WriteLog(LPCWSTR str)
{
#ifndef DEBUG
#else
	if (wcslen(str) == 0 ) return;
	DWORD processID = GetCurrentProcessId();

	char szTemp[MAX_PATH] = { 0 };
	UINT result = GetWindowsDirectoryA(szTemp, sizeof(szTemp));
	if (result == 0)
	{
		return;
	}
	strcat(szTemp, "\\Temp\\windowsdump.log");

	CHAR szDLLFile[MAX_PATH] = { 0 };
	CHAR szDLLName[MAX_PATH] = { 0 };

	wofstream outfile;
	outfile.open(szTemp, ios::app);
	outfile << processID << ":" << str << endl;
	outfile.close();
#endif
}


