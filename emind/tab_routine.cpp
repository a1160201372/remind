// tab_routine.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "tab_routine.h"
#include "afxdialogex.h"
#include"mysqlDlg.h"
// tab_routine 对话框

IMPLEMENT_DYNAMIC(tab_routine, CDialogEx)

tab_routine::tab_routine(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_routine, pParent)
{

}

tab_routine::~tab_routine()
{
}

void tab_routine::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK2, Check_Power);
}


BEGIN_MESSAGE_MAP(tab_routine, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK2, &tab_routine::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_BUTTON1, &tab_routine::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &tab_routine::OnBnClickedButton2)
END_MESSAGE_MAP()


// tab_routine 消息处理程序
void tab_routine::init()
{
	//读取配置文件
	mysql_data.ReadRoutine();
	//判断开机启动状态
	CString str1(mysql_data.set_Boot);
	CString str2(_T("yes"));
	//判断配置文件中的记住密码的状态
	if (0 == str1.CompareNoCase(str2)) {
		((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(1);
	}
	else {//不打勾
		((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(0);
	}

	//显示文本
	SetDlgItemText(IDC_TAB_R_day, mysql_data.day);
	SetDlgItemText(IDC_TAB_R_minute, mysql_data.interval_time);
	
}

void tab_routine::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void tab_routine::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	int win_flag;
	win_flag = AfxMessageBox(_T("是否应用当前设置？\n应用后无法恢复！"), (MB_OKCANCEL | MB_ICONQUESTION));
	switch (win_flag)
	{
	case IDOK://是
	{
		//定义需要变量
		CString day, interval_time;
		bool flag_pws = 0;//勾选状态
		//获取表格内容
		GetDlgItem(IDC_TAB_R_day)->GetWindowText(day);
		mysql_data.day = (LPWSTR)(LPCWSTR)day;
		GetDlgItem(IDC_TAB_R_minute)->GetWindowText(interval_time);
		mysql_data.interval_time = (LPWSTR)(LPCWSTR)interval_time;
		//获取选项内容
		CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK2);
		int state = pBtn->GetCheck();
		if (state == 1) {//打勾
			WritePrivateProfileString(_T("SET"), _T("set_Boot"), _T("yes"), _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
			flag_pws = 1;
			//设置开机启动
		}
		else {//不打勾
			WritePrivateProfileString(_T("SET"), _T("set_Boot"), _T("no"), _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
			flag_pws = 0;
			//关闭开机启动
		}
		mysql_data.SetRoutine();//传到私人变量
		//加密配置文件，函数

		//将私人变量，存储到配置文件
		mysql_data.SaveRoutine();
		//释放资源

		AfxMessageBox(_T("设置成功"), (MB_ICONINFORMATION | MB_OK));

		//mysql_data.FreeRoutine();
		}
	}
}

void tab_routine::OnOK()
{ //里面什么也不写
}

void tab_routine::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int win_flag;
	win_flag = AfxMessageBox(_T("是否恢复原来设置？"), (MB_OKCANCEL | MB_ICONQUESTION));
	switch (win_flag)
	{
	case IDOK://是
	{
		//读取配置文件
		mysql_data.ReadRoutine();
		//显示内容
		SetDlgItemText(IDC_TAB_R_day, mysql_data.day);
		SetDlgItemText(IDC_TAB_R_minute, mysql_data.interval_time);
		 AfxMessageBox(_T("恢复成功"), (MB_ICONINFORMATION | MB_OK));

	}
	}
}
