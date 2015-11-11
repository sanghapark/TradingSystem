 // DlgLoginStatusTabBar.cpp : implementation file
//

#include "stdafx.h"
#include "TradingSystem.h"
#include "DlgLoginStatusTabBar.h"
#include "afxdialogex.h"
#include "TradingSystemManager.h"

// CDlgLoginStatusTabBar dialog

IMPLEMENT_DYNAMIC(CDlgLoginStatusTabBar, CDialogBar)

CDlgLoginStatusTabBar::CDlgLoginStatusTabBar(CWnd* pParent /*=NULL*/){

	//CTradingSystemApp* app = (CTradingSystemApp*)AfxGetApp();
	this->pLoginInfoManager = &(theApp.tradingSystemManager->GetLoginInfoManager());

	ETradeLoginInfo temp = this->pLoginInfoManager->LoadETradeLoginInfo();
	this->eTradeLoginStatusTab.SetLoginInfo(temp);
}

CDlgLoginStatusTabBar::~CDlgLoginStatusTabBar()
{
}

void CDlgLoginStatusTabBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLoginStatusTabBar, CDialogBar)
	ON_MESSAGE(WM_INITDIALOG, InitDialogTabBar)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_LOGIN_STATUS, OnTcnSelchangeTab1)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB_LOGIN_STATUS, OnTcnSelchangingTab1)
	ON_UPDATE_COMMAND_UI(IDC_BUTTON_LOGIN_STATUS_EDIT, OnUpdateCmdUI)
	ON_UPDATE_COMMAND_UI(IDC_BUTTON_LOGIN_STATUS_SAVE, OnUpdateCmdUI)
	ON_UPDATE_COMMAND_UI(IDC_BUTTON_LOGIN_STATUS_RESET, OnUpdateCmdUI)
	ON_UPDATE_COMMAND_UI(IDC_BUTTON_LOGIN_STATUS_LOGIN, OnUpdateCmdUI)
	ON_UPDATE_COMMAND_UI(IDC_BUTTON_LOGIN_STATUS_LOGOUT, OnUpdateCmdUI)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_STATUS_EDIT, OnEditButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_STATUS_SAVE, OnSaveButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_STATUS_RESET, OnResetButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_STATUS_LOGIN, OnLoginButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN_STATUS_LOGOUT, OnLogoutButtonClicked)
END_MESSAGE_MAP()


// CDlgLoginStatusTabBar message handlers

//여기서 LoginInfo.xml에서 읽어서 Tab들을 설정해준다.
LRESULT CDlgLoginStatusTabBar::InitDialogTabBar(WPARAM wParam, LPARAM IPAram){
	CTabCtrl* tabCtrl = (CTabCtrl*)(this->GetDlgItem(IDC_TAB_LOGIN_STATUS));
	tabCtrl->InsertItem(0, TEXT("E*Trade"));
	//tabCtrl->InsertItem(1, TEXT("Woori"));
	this->AddETradeLoginInfoTab(tabCtrl);
	//this->AddWooriLoginInfoTab(tabCtrl);
	tabCtrl->SetCurSel(0);
	this->eTradeLoginStatusTab.WriteLoginInfoText(this->pLoginInfoManager->LoadETradeLoginInfo());
	this->eTradeLoginStatusTab.ShowWindow(SW_SHOW);

	return 1;
}


void CDlgLoginStatusTabBar::AddETradeLoginInfoTab(CTabCtrl* tabCtrl){
	CRect rect;
	this->eTradeLoginStatusTab.Create(IDD_DIALOG_ETRADE_LOGIN_STATUS_BAR, tabCtrl);
	this->eTradeLoginStatusTab.GetWindowRect(&rect);
	this->eTradeLoginStatusTab.MoveWindow(5,25, rect.Width(), rect.Height());
	this->eTradeLoginStatusTab.ShowWindow(SW_HIDE);
}

void CDlgLoginStatusTabBar::AddWooriLoginInfoTab(CTabCtrl* tabCtrl){
	CRect rect;
	this->wooriLoginStatusTab.Create(IDD_DIALOG_WOORI_LOGIN_STATUS_BAR, tabCtrl);
	this->wooriLoginStatusTab.GetWindowRect(&rect);
	this->wooriLoginStatusTab.MoveWindow(5,25, rect.Width(), rect.Height());
	this->wooriLoginStatusTab.ShowWindow(SW_HIDE);
}



void CDlgLoginStatusTabBar::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult){
	CTabCtrl* tabCtrl = (CTabCtrl*)(this->GetDlgItem(IDC_TAB_LOGIN_STATUS));
	int curSelTab = tabCtrl->GetCurSel();

	switch(curSelTab){
		case 0:
			this->eTradeLoginStatusTab.ShowWindow(SW_SHOW);
			break;
		case 1:
			this->wooriLoginStatusTab.ShowWindow(SW_SHOW);
			break;
	}
}

void CDlgLoginStatusTabBar::OnTcnSelchangingTab1(NMHDR* pNMHDR, LRESULT* pResult){
	CTabCtrl* tabCtrl = (CTabCtrl*)(this->GetDlgItem(IDC_TAB_LOGIN_STATUS));
	int curSelTab = tabCtrl->GetCurSel();

	switch(curSelTab){
	case 0:
		this->eTradeLoginStatusTab.ShowWindow(SW_HIDE);
		break;
	case 1:
		this->wooriLoginStatusTab.ShowWindow(SW_HIDE);
		break;
	}
}


void CDlgLoginStatusTabBar::OnUpdateCmdUI(CCmdUI* pCmdUI){
	pCmdUI->Enable(TRUE);
}



void CDlgLoginStatusTabBar::OnEditButtonClicked(){
	// 선택된 탭 찾는다. 그에 해당하는거 
	CTabCtrl* tabCtrl = (CTabCtrl*)this->GetDlgItem(IDC_TAB_LOGIN_STATUS);
	int curSelTab = tabCtrl->GetCurSel();

	switch(curSelTab){
		case 0:
			this->eTradeLoginStatusTab.EnableLoginInfo();
			break;
		case 1:
			break;
		default:
			break;
	}
}

void CDlgLoginStatusTabBar::OnSaveButtonClicked(){
	// 선택된 탭 찾는다. 그에 해당하는거 
	CTabCtrl* tabCtrl = (CTabCtrl*)this->GetDlgItem(IDC_TAB_LOGIN_STATUS);
	int curSelTab = tabCtrl->GetCurSel();
	
	switch(curSelTab){
	case 0:
		this->pLoginInfoManager->SaveETradeLoginInfo(this->eTradeLoginStatusTab.GetLoginInfo());
		break;
	case 1:
		break;
	default:
		break;
	}
}

void CDlgLoginStatusTabBar::OnResetButtonClicked(){
	// 선택된 탭 찾는다. 그에 해당하는거 
	CTabCtrl* tabCtrl = (CTabCtrl*)this->GetDlgItem(IDC_TAB_LOGIN_STATUS);
	int curSelTab = tabCtrl->GetCurSel();

	BOOL editable = FALSE;

	switch(curSelTab){
	case 0:
		editable = this->eTradeLoginStatusTab.GetEditable();
		break;
	case 1:
		break;
	default:
		break;
	}

	if(editable==TRUE){
		switch(curSelTab){
		case 0:
			this->eTradeLoginStatusTab.WriteLoginInfoText(this->pLoginInfoManager->LoadETradeLoginInfo());
			break;
		case 1:
			break;
		default:
			break;
		}
	}
}

void CDlgLoginStatusTabBar::OnLoginButtonClicked(){
	// 선택된 탭 찾는다. 그에 해당하는거 
	CTabCtrl* tabCtrl = (CTabCtrl*)this->GetDlgItem(IDC_TAB_LOGIN_STATUS);
	int curSelTab = tabCtrl->GetCurSel();
	BOOL logged = FALSE;
	switch(curSelTab){
	case 0:
		this->eTradeLoginStatusTab.LogIn();
		break;
	case 1:
		break;
	default:
		break;
	}
}

void CDlgLoginStatusTabBar::OnLogoutButtonClicked(){
	// 선택된 탭 찾는다. 그에 해당하는거 
	CTabCtrl* tabCtrl = (CTabCtrl*)this->GetDlgItem(IDC_TAB_LOGIN_STATUS);
	int curSelTab = tabCtrl->GetCurSel();

	switch(curSelTab){
	case 0:
		this->eTradeLoginStatusTab.LogOut();
		break;
	case 1:
		break;
	default:
		break;
	}
}