// tab_routine.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"
#include "tab_routine.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// tab_routine 消息处理程序
void tab_routine::init()
{
	//定义
	int day, interval_time, set_Boot;

	TCHAR day_t[10];
	char day_c[10];

	TCHAR interval_time_t[10];
	char interval_time_c[10];

	day = GetPrivateProfileInt(_T("set"), _T("day"), 0, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	interval_time = GetPrivateProfileInt(_T("set"), _T("interval_time"), 0, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	set_Boot = GetPrivateProfileInt(_T("set"), _T("set_Boot"), 0, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	//转换格式
	sprintf_s(day_c, 10, "%d", day);
	MultiByteToWideChar(CP_ACP, 0, day_c, -1, day_t, 10);//转换格式
	sprintf_s(interval_time_c, 10, "%d", interval_time);
	MultiByteToWideChar(CP_ACP, 0, interval_time_c, -1, interval_time_t, 10);//转换格式

	//设置按钮状态
	if (set_Boot == 0)//打勾
		((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(0);
	else//不打勾
		((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(1);


	SetDlgItemText(IDC_TAB_R_day, day_t);
	SetDlgItemText(IDC_TAB_R_minute, interval_time_t);
	
}

void tab_routine::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
}
