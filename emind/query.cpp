// query.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "query.h"
#include "afxdialogex.h"


// query 对话框

IMPLEMENT_DYNAMIC(tab_query, CDialogEx)

tab_query::tab_query(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_query, pParent)
{

}

tab_query::~tab_query()
{
}

void tab_query::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(tab_query, CDialogEx)
END_MESSAGE_MAP()


// query 消息处理程序
