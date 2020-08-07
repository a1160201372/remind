// query.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "query.h"
#include "afxdialogex.h"
#include "mysqlDlg.h"

extern mysqlDlg mysql_data;

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
	ON_BN_CLICKED(IDC_BUTTON2, &tab_query::OnBnClickedButton2)
END_MESSAGE_MAP()


// query 消息处理程序

//初始化函数
void tab_query::init()
{
	mysql_data.ReadQuery();//读到公共

	SetDlgItemText(IDC_TAB_Q_time_table, mysql_data.time_table);
	SetDlgItemText(IDC_TAB_Q_time_end, mysql_data.time_end);
	SetDlgItemText(IDC_TAB_Q_time_ipid, mysql_data.time_ipid);
	SetDlgItemText(IDC_TAB_Q_time_userid, mysql_data.time_userid);
	SetDlgItemText(IDC_TAB_Q_ip_table, mysql_data.ip_table);
	SetDlgItemText(IDC_TAB_Q_ip_ip, mysql_data.ip_ip);
	SetDlgItemText(IDC_TAB_Q_ip_id, mysql_data.ip_id);
	SetDlgItemText(IDC_TAB_Q_user_table, mysql_data.user_table);
	SetDlgItemText(IDC_TAB_Q_user_name1, mysql_data.user_name);
	SetDlgItemText(IDC_TAB_Q_user_id1, mysql_data.user_id);

}

void tab_query::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	//定义需要变量
	CString time_table, time_end, time_ipid, time_userid;
	CString ip_table, ip_ip, ip_id;
	CString user_table, user_name, user_id;
	bool flag_pws = 0;
	//获取表格内容
	GetDlgItem(IDC_TAB_Q_time_table)->GetWindowText(time_table);
	mysql_data.time_table = (LPWSTR)(LPCWSTR)time_table;
	GetDlgItem(IDC_TAB_Q_time_end)->GetWindowText(time_end);
	mysql_data.time_end = (LPWSTR)(LPCWSTR)time_end;
	GetDlgItem(IDC_TAB_Q_time_ipid)->GetWindowText(time_ipid);
	mysql_data.time_ipid = (LPWSTR)(LPCWSTR)time_ipid;
	GetDlgItem(IDC_TAB_Q_time_userid)->GetWindowText(time_userid);
	mysql_data.time_userid = (LPWSTR)(LPCWSTR)time_userid;

	GetDlgItem(IDC_TAB_Q_ip_table)->GetWindowText(ip_table);
	mysql_data.ip_table = (LPWSTR)(LPCWSTR)ip_table;
	GetDlgItem(IDC_TAB_Q_ip_ip)->GetWindowText(ip_ip);
	mysql_data.ip_ip = (LPWSTR)(LPCWSTR)ip_ip;
	GetDlgItem(IDC_TAB_Q_ip_id)->GetWindowText(ip_id);
	mysql_data.ip_id = (LPWSTR)(LPCWSTR)ip_id;

	GetDlgItem(IDC_TAB_Q_user_table)->GetWindowText(user_table);
	mysql_data.user_table = (LPWSTR)(LPCWSTR)user_table;
	GetDlgItem(IDC_TAB_Q_user_name1)->GetWindowText(user_name);
	mysql_data.user_name = (LPWSTR)(LPCWSTR)user_name;
	GetDlgItem(IDC_TAB_Q_user_id1)->GetWindowText(user_id);
	mysql_data.user_id = (LPWSTR)(LPCWSTR)user_id;
	//
	//检测是否有空的


	//传到私人变量
	mysql_data.SetQuery();

	//将私人，存储到配置文件
	mysql_data.SaveQuery(); 

}

void tab_query::OnOK()
{}