// tab_mysql.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "tab_mysql.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <tchar.h>

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

	LPWSTR HostName,UserName, password, databases;
	TCHAR tmp[10];
	char prot[10];
	int prot_tmp, Boot;

	//读取exe地址


	//分配空间
	HostName = new wchar_t[10];
	UserName = new wchar_t[10];
	password = new wchar_t[10];
	databases = new wchar_t[10];
	//读取配置文件
	//字符串
	GetPrivateProfileString(_T("MYSQL"), _T("HostName"), _T("error"), HostName, 10,_T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("UserName"), _T("error"), UserName, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password"), _T("error"), password, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("databases"), _T("error"), databases, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));

	//端口数字
	prot_tmp = GetPrivateProfileInt(_T("MYSQL"), _T("Port"), 3306, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	Boot = GetPrivateProfileInt(_T("MYSQL"), _T("password_Boot"), 0, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));

	sprintf_s(prot, 10, "%d", prot_tmp);
	MultiByteToWideChar(CP_ACP, 0, prot, -1, tmp, 10);//转换格式
	//设置按钮状态
	if(Boot==0)//打勾
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(0);
	else//不打勾
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(1);
	
	//显示内容
	SetDlgItemText(IDC_TAB_M_ip, HostName);
	SetDlgItemText(IDC_TAB_M_base, databases);
	SetDlgItemText(IDC_TAB_M_prot, tmp);
	SetDlgItemText(IDC_TAB_M_user, UserName);
	SetDlgItemText(IDC_TAB_M_pws, _T("      "));
	//释放资源
	delete[] HostName;
	delete[] UserName;
	delete[] password;
	delete[] databases;
}