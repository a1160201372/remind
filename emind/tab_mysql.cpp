// tab_mysql.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "tab_mysql.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <tchar.h>
#include"mysqlDlg.h"
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

mysqlDlg mysql_data;

BEGIN_MESSAGE_MAP(tab_mysql, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &tab_mysql::OnBnClickedButton1)
END_MESSAGE_MAP()


// tab_mysql 消息处理程序
void tab_mysql::init()
{

	LPWSTR HostName, UserName, password, databases;
	TCHAR tmp[10];
	char prot[10];
	int prot_tmp = 0, Boot;

	//读取exe地址

	mysql_data.GetMysql();

	CString str1(mysql_data.pws_Boot);

	CString str2(_T("yes"));

	if (0 == str1.CompareNoCase(str2)) {
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(1);
		SetDlgItemText(IDC_TAB_M_pws, _T("      "));
	}
	else{//不打勾
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(0);
	SetDlgItemText(IDC_TAB_M_pws, NULL);
}
	//
	

	SetDlgItemText(IDC_TAB_M_ip, mysql_data.HostName);
	SetDlgItemText(IDC_TAB_M_base, mysql_data.databases);
	SetDlgItemText(IDC_TAB_M_prot, mysql_data.Port);
	SetDlgItemText(IDC_TAB_M_user, mysql_data.UserName);


	//分配空间
	/**
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
	delete[] databases;*/
}

void tab_mysql::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//定义变量
	CString HostName, UserName, password,databases,Port,Boot;
	bool flag_pws=0;
	//获取表格内容
	GetDlgItem(IDC_TAB_M_ip)->GetWindowText(HostName);
	mysql_data.HostName = (LPWSTR)(LPCWSTR)HostName;
	GetDlgItem(IDC_TAB_M_user)->GetWindowText(UserName);
	mysql_data.UserName = (LPWSTR)(LPCWSTR)UserName;
	GetDlgItem(IDC_TAB_M_base)->GetWindowText(databases);
	mysql_data.databases = (LPWSTR)(LPCWSTR)databases;
	GetDlgItem(IDC_TAB_M_prot)->GetWindowText(Port);
	mysql_data.Port = (LPWSTR)(LPCWSTR)Port;
	GetDlgItem(IDC_TAB_M_pws)->GetWindowText(password);
	mysql_data.password = (LPWSTR)(LPCWSTR)password;
	//获取选项内容
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	int state = pBtn->GetCheck();
	if (state == 1){//打勾
		WritePrivateProfileString(_T("MYSQL"), _T("password_Boot"), _T("yes"), _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
		flag_pws = 1;
	}
	else{//不打勾
		WritePrivateProfileString(_T("MYSQL"), _T("password_Boot"), _T("no"), _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
		flag_pws = 0;
	}


	mysql_data.SetMysql();//隐私赋值
	//加密配置文件
	mysql_data.SaveMysql(flag_pws);//存储到配置文件
}
