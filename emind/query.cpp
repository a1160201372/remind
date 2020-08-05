// query.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "query.h"
#include "afxdialogex.h"
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

//初始化函数
void tab_query::init()
{
	SetDlgItemText(IDC_TAB_Q_time_table, _T("请输入帐号1"));
	SetDlgItemText(IDC_TAB_Q_time_end, _T("请输入帐号2"));
	SetDlgItemText(IDC_TAB_Q_time_ipid, _T("请输入帐号3"));
	SetDlgItemText(IDC_TAB_Q_time_userid, _T("请输入帐号4"));
	SetDlgItemText(IDC_TAB_Q_ip_table, _T("请输入帐号5"));
	SetDlgItemText(IDC_TAB_Q_ip_ip, _T("请输入帐号6"));
	SetDlgItemText(IDC_TAB_Q_ip_id,_T("请输入帐号7"));
	SetDlgItemText(IDC_TAB_Q_user_table, _T("请输入帐号8"));
	SetDlgItemText(IDC_TAB_Q_user_name, _T("请输入帐号9"));
	SetDlgItemText(IDC_TAB_Q_user_id, _T("请输入帐号0"));
}