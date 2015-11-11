// ModuleRelationView.cpp : implementation file
//

#include "stdafx.h"
#include "TradingSystem.h"
#include "ModuleRelationView.h"
#include "DlgDataFeedingModule.h"
#include "DlgInstrumentManager.h"
#include "DlgOptionStrategy.h"


// CModuleRelationView

IMPLEMENT_DYNCREATE(CModuleRelationView, CView)

CModuleRelationView::CModuleRelationView(){
	this->p_DlgDataFeedingModule = 0;
	this->p_DlgInstrumentManager = 0;
	this->p_DlgOptionStrategy = 0;
}

CModuleRelationView::~CModuleRelationView()
{
}

BEGIN_MESSAGE_MAP(CModuleRelationView, CView)
	ON_MESSAGE(WMU_READVISE_DATA_FEEDING, &CModuleRelationView::ReadviseDataFeeding)
END_MESSAGE_MAP()


// CModuleRelationView drawing

void CModuleRelationView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


CDialog* CModuleRelationView::CreateManagerDialog(CRuntimeClass* pClass, UINT uID){
	CDialog* pDlg = (CDialog*)pClass->CreateObject();
	BOOL created = pDlg->Create(uID, this);
	if (created == TRUE){
		pDlg->ShowWindow(SW_SHOW);
	}
	else{
		AfxMessageBox(_T("Could Not Create GUI"));
	}
	return pDlg;
}


CDlgDataFeedingModule* CModuleRelationView::CreateDlgDataFeedingModule(){
	if(this->p_DlgDataFeedingModule == 0){
		this->p_DlgDataFeedingModule = (CDlgDataFeedingModule*)this->CreateManagerDialog(RUNTIME_CLASS(CDlgDataFeedingModule), IDD_DIALOG1);
		this->p_DlgDataFeedingModule->pParentView = this;
	}
	else{
		AfxMessageBox(_T("DataFeedingModule Dialog already exists."));
		this->p_DlgDataFeedingModule->ShowWindow(SW_SHOW);
		//this->p_DlgDataFeedingModule->SetForegroundWindow();
	}
	return this->p_DlgDataFeedingModule;
}


LRESULT CModuleRelationView::ReadviseDataFeeding(WPARAM wParam, LPARAM lParam){
	//this->p_DlgDataFeedingModule->StartETradeDataFeeding();
	if(this->p_DlgDataFeedingModule!=0){
		this->p_DlgDataFeedingModule->SendMessage(WMU_READVISE_DATA_FEEDING, NULL, NULL);
	}
	return 0L;
}



CDlgInstrumentManager* CModuleRelationView::CreateDlgInstrumentManager(){
	if(this->p_DlgInstrumentManager==0){
		this->p_DlgInstrumentManager = (CDlgInstrumentManager*)this->CreateManagerDialog(RUNTIME_CLASS(CDlgInstrumentManager), IDD_DIALOG_INSTRUMENT_MANAGER);
		this->p_DlgInstrumentManager->pParentView = this;
	}
	else{
		AfxMessageBox(_T("Instrument Manager Dialog already exists."));
		this->p_DlgInstrumentManager->ShowWindow(SW_SHOW);
	}
	return this->p_DlgInstrumentManager;
}


CDlgOptionStrategy* CModuleRelationView::CreateDlgOptionStrategy(){
	if(this->p_DlgOptionStrategy==0){
		this->p_DlgOptionStrategy = (CDlgOptionStrategy*)this->CreateManagerDialog(RUNTIME_CLASS(CDlgOptionStrategy), IDD_DIALOG_OPTION_STRATEGY);
		this->p_DlgOptionStrategy->pParentView = this;
	}
	else{
		AfxMessageBox(_T("Option Strategy Dialog already exists."));
		this->p_DlgOptionStrategy->ShowWindow(SW_SHOW);
	}
	return this->p_DlgOptionStrategy;
}



// CModuleRelationView diagnostics

#ifdef _DEBUG
void CModuleRelationView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CModuleRelationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CModuleRelationView message handlers
