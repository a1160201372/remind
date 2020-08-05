// tab_mysql.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "tab_mysql.h"
#include "afxdialogex.h"


// tab_mysql 对话框

IMPLEMENT_DYNAMIC(tab_mysql, CDialogEx)

tab_mysql::tab_mysql(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_MYSQL, pParent)
{

}

tab_mysql::~tab_mysql()
{
}

void tab_mysql::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(tab_mysql, CDialogEx)
END_MESSAGE_MAP()


// tab_mysql 消息处理程序
void tab_mysql::init()
{
	//设置按钮状态
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(1);
	//((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(0);
	SetDlgItemText(IDC_TAB_M_ip, _T("请输入帐号1"));
	SetDlgItemText(IDC_TAB_M_prot, _T("请输入帐号2"));
	SetDlgItemText(IDC_TAB_M_user, _T("请输入帐号3"));
	SetDlgItemText(IDC_TAB_M_pws, _T("请输入帐号4"));

}