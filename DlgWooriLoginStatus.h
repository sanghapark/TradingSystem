#pragma once


// CDlgWooriLoginStatus dialog

class CDlgWooriLoginStatus : public CDialog
{
	DECLARE_DYNAMIC(CDlgWooriLoginStatus)

public:
	CDlgWooriLoginStatus(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgWooriLoginStatus();

// Dialog Data
	enum { IDD = IDD_DIALOG_WOORI_LOGIN_STATUS_BAR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
