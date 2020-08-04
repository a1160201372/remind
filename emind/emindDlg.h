
// emindDlg.h: 头文件
//

#pragma once


// CemindDlg 对话框
class CemindDlg : public CDialogEx
{
// 构造
public:
	CemindDlg(CWnd* pParent = nullptr);	// 标准构造函数
	CMenu m_Menu;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EMIND_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void menu_set();
};
