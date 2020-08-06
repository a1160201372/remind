
// emindDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "emind.h"
#include "tab_mysql.h"
#include "TAB_population.h"
#include"query.h"
#include "emindDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
NOTIFYICONDATA m_nid;
// CemindDlg 对话框
bool set_win_flag;
CemindDlg::CemindDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EMIND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CemindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CemindDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_SHOWTASK, OnShowTask)//托盘响应
	ON_COMMAND(ID_32771, &CemindDlg::menu_set)
END_MESSAGE_MAP()


// CemindDlg 消息处理程序

BOOL CemindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//设置菜单项
	m_Menu.LoadMenu(IDR_MENU1);  //  IDR_MENU1
	SetMenu(&m_Menu);
	//增加系统托盘
	m_nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	m_nid.hWnd = this->m_hWnd;
	m_nid.uID = IDR_MAINFRAME;
	m_nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	m_nid.uCallbackMessage = WM_SHOWTASK;             // 自定义的消息名称
	m_nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	wcscpy_s(m_nid.szTip, _T("提醒服务"));//信息提示条为"计划任务提醒"                // 信息提示条为"服务器程序"，VS2008 UNICODE编码用wcscpy_s()函数
	Shell_NotifyIcon(NIM_ADD, &m_nid);                // 在托盘区添加图标



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CemindDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CemindDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CemindDlg::menu_set()
{
	// TODO: 在此添加命令处理程序代码
	TAB_population* pDlg = new TAB_population;//显示窗口
	pDlg->DoModal();//运行设置窗口，并锁定本窗口。
}

LRESULT CemindDlg::OnShowTask(WPARAM wParam, LPARAM lParam)
{
	if (wParam != IDR_MAINFRAME)
		return 1;
	switch (lParam)
	{
		case WM_RBUTTONUP:                                        // 右键起来时弹出菜单
		{
			int id;//定义菜单标志
			CMenu menu, * pMenu;
			menu.LoadMenu(IDR_MENU2);
			pMenu = menu.GetSubMenu(0);
			POINT ptPos;
			::GetCursorPos(&ptPos);
			pMenu->SetDefaultItem(IDR_MENU2);
			SetForegroundWindow();//这一行代码很重要，否则右键菜单工作//不正常。详见msdn说明: http://support.microsoft.com/kb/135788
			id = menu.GetSubMenu(0)->TrackPopupMenu(TPM_RETURNCMD | TPM_LEFTALIGN | TPM_RIGHTBUTTON, ptPos.x, ptPos.y, this);

			switch (id) {
				case 32775://设置
				{
					if (set_win_flag == 0)
					{
						CWnd* set_win = FindWindow(NULL, _T("设置"));//获取设置窗口的句柄
						//判断设置窗口是否打开
						if (set_win == NULL)//未打开
						{
							TAB_population* pDlg = new TAB_population;//显示窗口
							pDlg->DoModal();//运行设置窗口，并锁定本窗口。
						}
					}
					break;
				}
				case 32776://意见反馈
				{
				
					break;
				}
				case 32777://关于提醒
				{
					break;
				}
				case 32778://退出程序
				{
					int a=DisplayResourceNAMessageBox(_T("提醒软件"), _T("您确认退出软件吗？"));
					switch (a)
					{
						case IDOK://确定
						{
							exit(0);//退出程序
							break;
						}
						case IDCANCEL: {//取消
							break;//没动作
						}
					}
					break;
				}
			}
			break;
		}
		case WM_LBUTTONDBLCLK:                                 // 双击左键的处理
		{
			this->ShowWindow(SW_SHOWNORMAL);         // 显示主窗口
			break;
		}
	}
	return 0;
}
