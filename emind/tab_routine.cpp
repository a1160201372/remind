// tab_routine.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "tab_routine.h"
#include "afxdialogex.h"


// tab_routine 对话框

IMPLEMENT_DYNAMIC(tab_routine, CDialogEx)

tab_routine::tab_routine(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_routine, pParent)
{

}

tab_routine::~tab_routine()
{
}

void tab_routine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(tab_routine, CDialogEx)
END_MESSAGE_MAP()


// tab_routine 消息处理程序
