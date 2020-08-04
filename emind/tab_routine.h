#pragma once


// tab_routine 对话框

class tab_routine : public CDialogEx
{
	DECLARE_DYNAMIC(tab_routine)

public:
	tab_routine(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~tab_routine();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB_routine };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
