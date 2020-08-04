#pragma once


// query 对话框

class tab_query : public CDialogEx
{
	DECLARE_DYNAMIC(tab_query)

public:
	tab_query(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~tab_query();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_query };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
