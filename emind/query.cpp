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
	//定义变量
	LPWSTR time_table, time_end, time_ipid, time_userid;
	LPWSTR ip_table, ip_ip, ip_id;
	LPWSTR user_table, user_name, user_id;
	//分配空间
	time_table = new wchar_t[10];
	time_end = new wchar_t[10];
	time_ipid = new wchar_t[10];
	time_userid = new wchar_t[10];

	ip_table = new wchar_t[10];
	ip_ip = new wchar_t[10];
	ip_id = new wchar_t[10];

	user_table = new wchar_t[10];
	user_name = new wchar_t[10];
	user_id = new wchar_t[10];
	//读取配置文件
	GetPrivateProfileString(_T("TIME"), _T("time_table"), _T("error"), time_table, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_end"), _T("error"), time_end, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_ipid"), _T("error"), time_ipid, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_userid"), _T("error"), time_userid, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));

	GetPrivateProfileString(_T("IP"), _T("ip_table"), _T("error"), ip_table, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_ip"), _T("error"), ip_ip, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_id"), _T("error"), ip_id, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));

	GetPrivateProfileString(_T("USERS"), _T("user_table"), _T("error"), user_table, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_name"), _T("error"), user_name, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_id"), _T("error"), user_id, 10, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));


	SetDlgItemText(IDC_TAB_Q_time_table, time_table);
	SetDlgItemText(IDC_TAB_Q_time_end, time_end);
	SetDlgItemText(IDC_TAB_Q_time_ipid, time_ipid);
	SetDlgItemText(IDC_TAB_Q_time_userid, time_userid);
	SetDlgItemText(IDC_TAB_Q_ip_table, ip_table);
	SetDlgItemText(IDC_TAB_Q_ip_ip, ip_ip);
	SetDlgItemText(IDC_TAB_Q_ip_id, ip_id);
	SetDlgItemText(IDC_TAB_Q_user_table, user_table);
	SetDlgItemText(IDC_TAB_Q_user_name, user_name);
	SetDlgItemText(IDC_TAB_Q_user_id, user_id);
	//释放空间
	delete[] time_table;
	delete[] time_end;
	delete[] time_ipid;
	delete[] time_userid;

	delete[] ip_table;
	delete[] ip_ip;
	delete[] ip_id;

	delete[] user_table;
	delete[] user_name;
	delete[] user_id;
}