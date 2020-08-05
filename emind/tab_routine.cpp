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



	//设置按钮状态
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(1);
	//((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(0);
	SetDlgItemText(IDC_TAB_R_day, _T("请输入帐号1"));
	SetDlgItemText(IDC_TAB_R_minute, _T("请输入帐号2"));
	//SetDlgItemText(IDC_CHECK2, _T("0"));
	/*UpdateData();
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK2))
	{
		SetDlgItemText(IDC_TAB_R_day, _T("xuan1"));
		SetDlgItemText(IDC_TAB_R_minute, _T("xuan2"));
	}
	else
	{
		SetDlgItemText(IDC_TAB_R_day, _T("weiuan1"));
		SetDlgItemText(IDC_TAB_R_minute, _T("weixuan2"));
	}
	*/
	
}

void tab_routine::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
}
