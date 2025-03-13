#pragma once
#include <windows.h>

#ifndef __UTILS__H__
#define __UTILS__H__

#define DEBUG

void WriteLog(char* str);
void WriteLog(int str);
void WriteLog(LPCWSTR str);

#endif
