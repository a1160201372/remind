#pragma once


// tab_mysql 对话框

class tab_mysql : public CDialogEx
{
	DECLARE_DYNAMIC(tab_mysql)

public:
	tab_mysql(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~tab_mysql();
	void init();
	void OnOK();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_MYSQL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};


