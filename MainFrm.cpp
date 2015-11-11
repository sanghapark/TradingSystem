
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TradingSystem.h"
#include "ModuleRelationView.h"
#include "OutputView.h"
#include "MainFrm.h"
#include "DlgDataFeedingModule.h"
#include "DlgInstrumentManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_LOGIN_STATUS_TAB_BAR, &CMainFrame::OnViewLoginStatusTabBar)
	ON_MESSAGE(WMU_SELECT_MODULE_TREE_ITEM, &CMainFrame::OnSelectModuleTreeItem)
	ON_MESSAGE(WMU_READVISE_DATA_FEEDING, &CMainFrame::ReadviseDataFeeding)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame construction/destruction

CMainFrame::CMainFrame(){
	this->m_bInitRelationSplitter = FALSE;
}

CMainFrame::~CMainFrame(){
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct){
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC)
		|| !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	if(!this->m_wndLoginStatusTabBar.Create(this, IDD_DIALOG_LOGIN_STATUS_TAB_BAR, CBRS_TOP, IDD_DIALOG_LOGIN_STATUS_TAB_BAR)){
		TRACE0("Failed to create login status bar\n");
		return -1;
	}


	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);
	
	/*
	BOOL ret = this->m_wndModuleTreeList.Create(this, IDD_DIALOG_MODULE_TREE_TEMP, CBRS_LEFT, IDD_DIALOG_MODULE_TREE_TEMP);
	if (ret == FALSE){
		TRACE0("Failed to create ModuleTreeList \n");
		return -1;
	}
	*/
	

	BOOL ret = this->m_wndModuleTree.Create(this, IDD_DIALOG_MODULE_TREE_TEMP, CBRS_LEFT, IDD_DIALOG_MODULE_TREE_TEMP);

	//this->m_wndModuleTreeList.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&(this->m_wndModuleTreeList));
	

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	this->ShowControlBar(&(this->m_wndToolBar), FALSE, FALSE);
	//this->ShowControlBar(&(this->m_wndLoginStatusBar), FALSE, FALSE);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs){
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers


void CMainFrame::OnViewLoginStatusTabBar(){
	CMenu* menu = this->GetMenu();
	if(menu!=NULL && menu->GetMenuItemCount()>0){
		CMenu* subMenu = menu->GetSubMenu(2);
		if(subMenu!=NULL && subMenu->GetMenuItemCount()>0){
			UINT state = subMenu->GetMenuState(ID_VIEW_LOGIN_STATUS_TAB_BAR, MF_BYCOMMAND);
			ASSERT(state!=0xFFFFFFFF);
			if(state==MF_CHECKED){
				subMenu->CheckMenuItem(ID_VIEW_LOGIN_STATUS_TAB_BAR, MF_UNCHECKED | MF_BYCOMMAND);
				this->ShowControlBar(&(this->m_wndLoginStatusTabBar), FALSE, FALSE);
			}
			else{
				subMenu->CheckMenuItem(ID_VIEW_LOGIN_STATUS_TAB_BAR, MF_CHECKED | MF_BYCOMMAND);
				this->ShowControlBar(&(this->m_wndLoginStatusTabBar), TRUE, FALSE);
			}
		}
	}
}


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext){
	BOOL ret = TRUE;	

	ret = this->m_wndRelationSplitter.CreateStatic(this, 2, 1);

	if (ret == FALSE){
		AfxMessageBox(TEXT("Failed to Create Output Splitter1"));
		return FALSE;
	}
	if (this->m_wndRelationSplitter.CreateView(0, 0, RUNTIME_CLASS(CModuleRelationView), CSize(100, 500), pContext) == FALSE ||
		this->m_wndRelationSplitter.CreateView(1, 0, RUNTIME_CLASS(COutputView), CSize(100, 100), pContext) == FALSE){
		AfxMessageBox(TEXT("Failed to Create Output Splitter"));
		return FALSE;
	}
	this->m_bInitRelationSplitter = TRUE;
	return ret;
}


void CMainFrame::OnSize(UINT nType, int cx, int cy){
	CFrameWnd::OnSize(nType, cx, cy);
	if (m_bInitRelationSplitter==TRUE && nType != SIZE_MINIMIZED){
		CRect rect;
		GetClientRect(&rect);
		
		this->m_wndRelationSplitter.SetRowInfo(0, rect.Width(), rect.Height()*(4/5));
		this->m_wndRelationSplitter.SetRowInfo(1, rect.Width(), rect.Height()*(1/5));

		this->m_wndRelationSplitter.RecalcLayout();
	}
}



LRESULT CMainFrame::OnSelectModuleTreeItem(WPARAM wParam, LPARAM lParam){
	CString moduleItem = (LPCTSTR)wParam;
	TRACE(TEXT("Select Module Tree Item : %s\n"), moduleItem);
	CModuleRelationView* view = (CModuleRelationView*)(this->m_wndRelationSplitter.GetPane(0, 0));
	if (moduleItem.Compare(TEXT("E*Trade")) == 0){
		//view->CreateManagerDialog(RUNTIME_CLASS(CDlgDataFeedingModule), IDD_DIALOG1);
		view->CreateDlgDataFeedingModule();
	}
	else if (moduleItem.Compare(TEXT("Instrument Manager")) == 0){
		//view->CreateManagerDialog(RUNTIME_CLASS(CDlgInstrumentManager), IDD_DIALOG_INSTRUMENT_MANAGER);
		view->CreateDlgInstrumentManager();
	}
	else if (moduleItem.Compare(TEXT("Option Strategy")) == 0){
		//view->CreateManagerDialog(RUNTIME_CLASS(CDlgInstrumentManager), IDD_DIALOG_INSTRUMENT_MANAGER);
		
		view->CreateDlgOptionStrategy();
	}
	return 0L;
}


LRESULT CMainFrame::ReadviseDataFeeding(WPARAM wParam, LPARAM lParam){

	CModuleRelationView* view = (CModuleRelationView*)(this->m_wndRelationSplitter.GetPane(0, 0));
	
	view->SendMessage(WMU_READVISE_DATA_FEEDING, NULL, NULL);

	return 0L;
}