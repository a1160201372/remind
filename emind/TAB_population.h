#pragma once


// TAB_population 对话框

class TAB_population : public CDialogEx
{
	DECLARE_DYNAMIC(TAB_population)

public:
	TAB_population(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TAB_population();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_population };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持



	// 生成的消息映射函数
	HICON m_hIcon;
	CMenu m_Menu;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
