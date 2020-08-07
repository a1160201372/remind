﻿// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H



// 添加要在此处预编译的标头
#include "framework.h"
#include "mysqlDlg.h"
#define WM_SHOWTASK (WM_USER+300) //注意n换成数字，n的大小应大于100
int DisplayResourceNAMessageBox(LPCWSTR text, LPCWSTR title);

extern mysqlDlg mysql_data;
extern int user_num;
char* ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn);
int DaysBetween2Date(int year1, int month1, int day1, int year2, int month2, int day2);
int char2int(const char* str);
#endif //PCH_H
