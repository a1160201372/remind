// query.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "query.h"
#include "afxdialogex.h"
#include "mysqlDlg.h"
#include"mysql.h"
extern mysqlDlg mysql_data;
extern MYSQL mysql; //mysql连接
// query 对话框
extern TCHAR error_flag[50];
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
	ON_BN_CLICKED(IDC_BUTTON3, &tab_query::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &tab_query::OnBnClickedButton1)
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
	int win_flag;
	win_flag = AfxMessageBox(_T("是否应用当前设置？\n应用后无法恢复！"), (MB_OKCANCEL | MB_ICONQUESTION));
	switch (win_flag)
	{
	case IDOK://是
	{

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
		break;
	}
	case IDNO://否
	{
		break;
	}
	}
		
}

void tab_query::OnOK()
{}

void tab_query::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int win_flag;
	win_flag = AfxMessageBox(_T("是否恢复原来设置？"), (MB_OKCANCEL | MB_ICONQUESTION));
	switch (win_flag)
	{
		case IDOK://是
		{
			//读取配置文件
			mysql_data.ReadQuery();
			//显示
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
			break;
		}
		case IDNO://否
		{
			break;
		}
	}
	
}

//查询测试
void tab_query::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取文本内容
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
	if (mysql_data.ConnectDatabase(mysql_data.HostName, mysql_data.UserName, mysql_data.password, mysql_data.databases, mysql_data.Port) == 1)
	{//连接成功
	//查询数据
		if (mysql_data.QueryDatabase2(mysql_data.time_table, mysql_data.day,
			mysql_data.time_end, mysql_data.time_ipid, mysql_data.time_userid,
			mysql_data.ip_table, mysql_data.ip_id, mysql_data.ip_ip,
			mysql_data.user_table, mysql_data.user_id, mysql_data.user_name) == 1)
		{//
			AfxMessageBox(_T("查询成功"), (MB_OK | MB_ICONINFORMATION));
		}
		else//查询失败
		{
			AfxMessageBox(error_flag, (MB_OK | MB_ICONSTOP));
			//AfxMessageBox(error_flag, (MB_YESNO | MB_ICONQUESTION));
			
		}
	}
	else {//连接失败
		TCHAR Name[100];	//定义TCHAR临时变量，
		//拼接内容
		MultiByteToWideChar(CP_ACP, 0, mysql_error(&mysql), -1, Name, 100);//转换格式
		//DisplayResourceNAMessageBox(_T("连接数据库失败"), Name);
		AfxMessageBox(Name, (MB_OK | MB_ICONSTOP));

	}


	
}
