// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"
#include "mysqlDlg.h"
#include "mysql.h"
#include <iostream>
// 当使用预编译的头时，需要使用此源文件，编译才能成功。
int user_num;//快到期用户个数
int DisplayResourceNAMessageBox(LPCWSTR text, LPCWSTR title)
{
	int msgboxID = MessageBox(
		NULL,
		//(LPCWSTR)L"Resource not available\nDo you want to try again?",
		title,
		text,
		MB_ICONEXCLAMATION | MB_OKCANCEL | MB_DEFBUTTON1
	);

	switch (msgboxID)
	{
	case IDYES:
	{
		// TODO: add code
		int a;
		a = 10;
		a++;
		break;
	}
	case IDCANCEL:{
		// TODO: add code
		int a;
		a = 10;
		a++;
		break;
	}
	case IDCONTINUE:{
		int a;
		a = 10;
		a++;
		// TODO: add code
		break;
}
	}
	return msgboxID;
}

 mysqlDlg mysql_data;
 MYSQL mysql; //mysql连接
 MYSQL_FIELD* fd;  //字段列数组

 MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
 MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
 char* ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn)
{
	LPSTR pszOut = NULL;

		if (lpwszStrIn != NULL)
		{
			int nInputStrLen = wcslen(lpwszStrIn);
 
			// Double NULL Termination  
			int nOutputStrLen = WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL, 0, 0, 0) + 2;
			pszOut = new char[nOutputStrLen];
 
			if (pszOut)
			{
				memset(pszOut, 0x00, nOutputStrLen);
				WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut, nOutputStrLen, 0, 0);
			}
		}

 
	return pszOut;
}

 using namespace std;
 //IsLeap函数判断一个年份是否为闰年，方法如下:
 bool IsLeap(int year)
 {
	 return (year % 4 == 0 || year % 400 == 0) && (year % 100 != 0);
 }
 //计算日期差值
 int DayInYear(int year, int month, int day)
 {
	 //int _day = 0;
	 int DAY[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	 if (IsLeap(year))
		 DAY[1] = 29;
	 for (int i = 0; i < month - 1; ++i)
	 {
		 day += DAY[i];
	 }
	 return day;
 }
 int DaysBetween2Date(int year1, int month1, int day1, int year2, int month2, int day2)
 {
	 //取出日期中的年月日
	 //int year1, month1, day1;
	 //int year2, month2, day2;
	 if (year1 == year2 && month1 == month2)
	 {
		 //return day2 - day1;
		 return day1 > day2 ? -(day1 - day2) : day2 - day1;

		 //如果年相同
	 }
	 else if (year1 == year2)
	 {
		 int d1, d2;
		 d1 = DayInYear(year1, month1, day1);
		 d2 = DayInYear(year2, month2, day2);
		 return d1 > d2 ? -(d1 - d2) : d2 - d1;
		 //return d2 - d1;

		 //年月都不相同
	 }
	 else {
		 //确保year1年份比year2早
		 /*if (year1 > year2)  // 1比2小
		 {
			 //swap进行两个值的交换
			 swap(year1, year2);
			 swap(month1, month2);
			 swap(day1, day2);
		 }*/
		 int d1, d2, d3;
		 if (IsLeap(year1))
			 d1 = 366 - DayInYear(year1, month1, day1); //取得这个日期在该年还于下多少天
		 else
			 d1 = 365 - DayInYear(year1, month1, day1);
		 d2 = DayInYear(year2, month2, day2); //取得在当年中的第几天
		 //cout << "d1:" << d1 << ", d2:" << d2;

		 d3 = 0;
		 for (int year = year1 + 1; year < year2; year++)
		 {
			 if (IsLeap(year))
				 d3 += 366;
			 else
				 d3 += 365;
		 }
		 return d1 + d2 + d3;
	 }
 }

 int char2int(const char* str) {
	 const char* p = str;
	 bool neg = false;
	 int res = 0;
	 if (*str == '-' || *str == '+') {
		 str++;
	 }

	 while (*str != 0) {
		 if (*str < '0' || *str > '9') {
			 break;
		 }
		 res = res * 10 + *str - '0';
		 str++;
	 }

	 if (*p == '-') {
		 res = -res;
	 }
	 return res;
 }