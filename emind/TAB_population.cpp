// TAB_population.cpp: 实现文件
//

#include "pch.h"
#include "emind.h"

#include "afxdialogex.h"
#include "tab_mysql.h"
#include"query.h"
#include "TAB_population.h"
#include"tab_routine.h"
#include"mysqlDlg.h"
tab_mysql user_tab_mysql;//
tab_query user_tab_query;
tab_routine user_tab_routine;
extern mysqlDlg mysql_data;
// TAB_population 对话框



IMPLEMENT_DYNAMIC(TAB_population, CDialogEx)

TAB_population::TAB_population(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_population, pParent)
{

}

// CemindDlg 消息处理程序

BOOL TAB_population::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//打开设置界面

	m_tab.InsertItem(0, _T("MYSQL属性"));
	m_tab.InsertItem(1, _T("查询属性"));
	m_tab.InsertItem(2, _T("常规"));
	//创建两个对话框
	user_tab_mysql.Create(IDD_TAB_MYSQL, &m_tab);
	user_tab_query.Create(IDD_TAB_query, &m_tab);
	user_tab_routine.Create(IDD_TAB_routine, &m_tab);
	//设定在Tab内显示的范围
	CRect tabRect;
	m_tab.GetClientRect(tabRect);
	tabRect.left += 0;
	tabRect.right += 10;
	tabRect.top += 20;
	tabRect.bottom += 100;
	user_tab_mysql.MoveWindow(&tabRect);
	user_tab_query.MoveWindow(&tabRect);
	user_tab_routine.MoveWindow(&tabRect);

	user_tab_mysql.ShowWindow(SW_SHOW);
	user_tab_query.ShowWindow(SW_HIDE);
	user_tab_routine.ShowWindow(SW_HIDE);
	user_tab_mysql.init();//初始化mysql界面

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

TAB_population::~TAB_population()
{
}

void TAB_population::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(TAB_population, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &TAB_population::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// TAB_population 消息处理程序


void TAB_population::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	switch (m_tab.GetCurSel())//处理TAB界面
	{
	case 0:
		user_tab_mysql.ShowWindow(SW_SHOW);
		user_tab_query.ShowWindow(SW_HIDE);
		user_tab_routine.ShowWindow(SW_HIDE);
		user_tab_mysql.init();//初始化mysql界面
		break;
	case 1:
		user_tab_mysql.ShowWindow(SW_HIDE);
		user_tab_query.ShowWindow(SW_SHOW);
		user_tab_routine.ShowWindow(SW_HIDE);
		user_tab_query.init();//初始化查询界面
		break;
	case 2:
		user_tab_mysql.ShowWindow(SW_HIDE);
		user_tab_query.ShowWindow(SW_HIDE);
		user_tab_routine.ShowWindow(SW_SHOW);
		user_tab_routine.init();//初始化常规界面
		break;
	default:break;
	}
}
