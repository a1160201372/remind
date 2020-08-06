// pch.cpp: 与预编译标头对应的源文件

#include "pch.h"

// 当使用预编译的头时，需要使用此源文件，编译才能成功。

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