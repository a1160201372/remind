// tab_mysql.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "tab_mysql.h"
#include "afxdialogex.h"
#include <stdio.h>
#include <tchar.h>
#include"mysqlDlg.h"
#include"mysql.h"
// tab_mysql 对话框
extern MYSQL mysql; //mysql连接
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
	ON_BN_CLICKED(IDC_BUTTON1, &tab_mysql::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_SQL_BUTTON_TEST, &tab_mysql::OnBnClickedSqlButtonTest)
	ON_BN_CLICKED(IDC_BUTTON2, &tab_mysql::OnBnClickedButton2)
END_MESSAGE_MAP()


// tab_mysql 消息处理程序
void tab_mysql::init()
{
	//读取exe地址

	mysql_data.ReadMysql();//配置文件读到公共
	//mysql_data.GetMysql();//公共
	CString str1(mysql_data.pws_Boot);
	CString str2(_T("yes"));
	//判断配置文件中的记住密码的状态
	if (0 == str1.CompareNoCase(str2)) {
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(1);
		SetDlgItemText(IDC_TAB_M_pws, mysql_data.password);
	}
	else{//不打勾
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(0);
		SetDlgItemText(IDC_TAB_M_pws, NULL);
	}
	//显示到文字栏
	SetDlgItemText(IDC_TAB_M_ip, mysql_data.HostName);
	SetDlgItemText(IDC_TAB_M_base, mysql_data.databases);
	SetDlgItemText(IDC_TAB_M_prot, mysql_data.Port);
	SetDlgItemText(IDC_TAB_M_user, mysql_data.UserName);
}

void tab_mysql::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int win_flag;
	win_flag =AfxMessageBox(_T("是否应用当前设置？"), (MB_OKCANCEL | MB_ICONINFORMATION));
	switch (win_flag)
	{
		case IDOK:
		{
			//定义变量
			CString HostName, UserName, password, databases, Port, Boot;
			bool flag_pws = 0;
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
			if (state == 1) {//打勾
				WritePrivateProfileString(_T("MYSQL"), _T("password_Boot"), _T("yes"), _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
				flag_pws = 1;
			}
			else {//不打勾
				WritePrivateProfileString(_T("MYSQL"), _T("password_Boot"), _T("no"), _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
				flag_pws = 0;
			}
			mysql_data.SetMysql();//传到私人变量
			//加密配置文件，函数

			//将私人变量，存储到配置文件
			mysql_data.SaveMysql(flag_pws); 
			AfxMessageBox(_T("设置成功"), (MB_ICONINFORMATION | MB_OK));

			break;
		}
		default:
		{
			break;
		}
	}
	
}

void tab_mysql::OnOK()
{ //里面什么也不写
}


void tab_mysql::OnBnClickedSqlButtonTest()
{
	// TODO: 在此添加控件通知处理程序代码
	//读取信息
	CString HostName, UserName, password, databases, Port, Boot;
	//bool flag_pws = 0;

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

	//连接数据库
	if (mysql_data.ConnectDatabase(mysql_data.HostName, mysql_data.UserName, mysql_data.password, mysql_data.databases, mysql_data.Port) == 1)
	{//连接成功
		AfxMessageBox(_T("连接数据库成功"), (MB_ICONINFORMATION | MB_OK));
		mysql_close(&mysql);	 //关闭一个服务器连接。
	}
	else {//连接失败
	
		TCHAR Name[100];	//定义TCHAR临时变量，
		//拼接内容
		MultiByteToWideChar(CP_ACP, 0, mysql_error(&mysql), -1, Name, 100);//转换格式
		AfxMessageBox(Name, (MB_OK| MB_ICONSTOP));

	}
}


void tab_mysql::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int win_flag;
	win_flag = AfxMessageBox(_T("是否应用当前设置？"), (MB_OKCANCEL | MB_ICONINFORMATION));
	switch (win_flag)
	{
	case IDOK:
	{

		//读取配置文件
		mysql_data.ReadMysql();
		//显示
		CString str1(mysql_data.pws_Boot);
		CString str2(_T("yes"));
		if (0 == str1.CompareNoCase(str2)) {
			((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(1);
			SetDlgItemText(IDC_TAB_M_pws, mysql_data.password);
		}
		else {//不打勾
			((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(0);
			SetDlgItemText(IDC_TAB_M_pws, NULL);
		}
		//显示到文字栏
		SetDlgItemText(IDC_TAB_M_ip, mysql_data.HostName);
		SetDlgItemText(IDC_TAB_M_base, mysql_data.databases);
		SetDlgItemText(IDC_TAB_M_prot, mysql_data.Port);
		SetDlgItemText(IDC_TAB_M_user, mysql_data.UserName);
		win_flag = AfxMessageBox(_T("恢复成功"), (MB_ICONINFORMATION | MB_OK));
		}
	}
}
