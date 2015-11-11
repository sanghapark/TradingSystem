#pragma once

#include "DlgETradeLoginStatus.h"
#include "DlgWooriLoginStatus.h"
#include "LoginInfoManager.h"

// CDlgLoginStatusTabBar dialog

class CDlgLoginStatusTabBar : public CDialogBar{
	DECLARE_DYNAMIC(CDlgLoginStatusTabBar)

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	public:
		enum { IDD = IDD_DIALOG_LOGIN_STATUS_TAB_BAR };

	public:
		CDlgLoginStatusTabBar(CWnd* pParent = NULL);   // standard constructor
		virtual ~CDlgLoginStatusTabBar();
		void AddETradeLoginInfoTab(CTabCtrl* tabCtrl);
		void AddWooriLoginInfoTab(CTabCtrl* tabCtrl);
		void Login();

	public:
		CDlgETradeLoginStatus eTradeLoginStatusTab;
		CDlgWooriLoginStatus wooriLoginStatusTab;
		CWnd* m_pwndShow;

		LoginInfoManager* pLoginInfoManager;

	protected:

		DECLARE_MESSAGE_MAP()
		afx_msg LRESULT InitDialogTabBar(WPARAM wParam, LPARAM IPAram);
		afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
		afx_msg void OnTcnSelchangingTab1(NMHDR* pNMHDR, LRESULT* pResult);
		afx_msg void OnUpdateCmdUI(CCmdUI* pCmdUI);
		afx_msg void OnEditButtonClicked();
		afx_msg void OnSaveButtonClicked();
		afx_msg void OnResetButtonClicked();
		afx_msg void OnLoginButtonClicked();
		afx_msg void OnLogoutButtonClicked();


	private:
};


