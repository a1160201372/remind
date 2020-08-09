
// emindDlg.h: 头文件
//

#pragma once


// CemindDlg 对话框
class CemindDlg : public CDialogEx
{
// 构造
public:
	CemindDlg(CWnd* pParent = nullptr);	// 标准构造函数
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EMIND_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CMenu m_Menu;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnCancel();//最小化响应
	afx_msg void OnClose();//关闭询问
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnShowTask(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void menu_set();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonDatabase();
	afx_msg void OnBnClickedButtonuser();
	afx_msg void OnBnClickedButtonnow();
};
