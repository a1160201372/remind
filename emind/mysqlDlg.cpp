#include"pch.h"
#include"mysqlDlg.h"


bool mysqlDlg::ConnectDatabase(char host[], char user[], char psw[], char table[], int port, char* error[])
{
	return 0;
}
void mysqlDlg::init()
{


}

void mysqlDlg::GetMysql()
{
	//分配空间
	HostName = new wchar_t[10];
	UserName = new wchar_t[10];
	password = new wchar_t[10];
	databases = new wchar_t[10];
	Port= new wchar_t[10];
	pws_Boot= new wchar_t[10];
	//读取配置文件
	GetPrivateProfileString(_T("MYSQL"), _T("HostName"), _T("error"), HostName, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("UserName"), _T("error"), UserName, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password"), _T("error"), password, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("databases"), _T("error"), databases, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("Port"), _T("error"), Port, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password_Boot"), _T("error"), pws_Boot, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	
	
}
void mysqlDlg::SetMysql()
{
	HostName_tmp = HostName;
	UserName_tmp = UserName;
	password_tmp = password;
	databases_tmp = databases;
	Port_tmp = Port;
	Boot_tmp = pws_Boot;
}
void mysqlDlg::SaveMysql(bool falg)
{
	WritePrivateProfileString(_T("MYSQL"), _T("HostName"), HostName_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("UserName"), UserName_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("databases"), databases_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("Port"), Port_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	if(falg==1)
		WritePrivateProfileString(_T("MYSQL"), _T("password"), password_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	else
		WritePrivateProfileString(_T("MYSQL"), _T("password"), _T(" "), _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));

}

void mysqlDlg::freeMysql()
{
	delete[] HostName;
	delete[] UserName;
	delete[] password;
	delete[] databases;
}