// DlgInstrumentManager.cpp


#include "DlgInstrumentManager.h"
#include "ModuleRelationView.h"
#include "TradingSystem.h"
#include "TradingSystemManager.h"

IMPLEMENT_DYNCREATE(CDlgInstrumentManager, CDialog)

BEGIN_MESSAGE_MAP(CDlgInstrumentManager, CDialog)
END_MESSAGE_MAP()

CDlgInstrumentManager::CDlgInstrumentManager(CWnd* pParent)
	:CDialog(CDlgInstrumentManager::IDD, pParent),
	instrumentGridCtrl(this){
	this->pParentView = 0;

	//CTradingSystemApp* app = (CTradingSystemApp*)AfxGetApp();
	this->pInstrumentManager = &(theApp.tradingSystemManager->GetInstrumentManager());
}


CDlgInstrumentManager::~CDlgInstrumentManager(){
	this->pParentView->p_DlgInstrumentManager = 0;
}


BOOL CDlgInstrumentManager::OnInitDialog(){
	CDialog::OnInitDialog();
	this->InitComboBoxInstrumentType();
	int length = this->pInstrumentManager->GetInstrumentList().GetLength();
	this->instrumentGridCtrl.InitGrid(length);
	return TRUE;
}


void CDlgInstrumentManager::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_CUSTOM_INSTRUMENT_LIST, this->instrumentGridCtrl);
	DDX_Control(pDX, IDC_COMBO_INSTRUMENT_TYPE, this->comboBoxInstrumentType);
}


void CDlgInstrumentManager::InitComboBoxInstrumentType(){
	int index =0;
	this->comboBoxInstrumentType.ResetContent();
	index = this->comboBoxInstrumentType.AddString(_T("All"));
	index = this->comboBoxInstrumentType.AddString(_T("Stock"));
	index = this->comboBoxInstrumentType.AddString(_T("ETF"));
	index = this->comboBoxInstrumentType.AddString(_T("Futures"));
	index = this->comboBoxInstrumentType.AddString(_T("Option"));
	index = this->comboBoxInstrumentType.SetCurSel(0);
}
