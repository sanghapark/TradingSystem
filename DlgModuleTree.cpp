// DlgModuleTree.cpp : implementation file
//

#include "stdafx.h"
#include "TradingSystem.h"
#include "DlgModuleTree.h"
#include "afxdialogex.h"
#include "Constants.h"

// CDlgModuleTree dialog

IMPLEMENT_DYNAMIC(CDlgModuleTree, CDialogBar)

BEGIN_MESSAGE_MAP(CDlgModuleTree, CDialogBar)
	ON_WM_CREATE()
	ON_MESSAGE(WM_INITDIALOG, OnInitDialog)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_MODULE_TEMP, OnDblckkTreeTr)
END_MESSAGE_MAP()


CDlgModuleTree::CDlgModuleTree(CWnd* pParent /*=NULL*/)
: CDialogBar(){
}

CDlgModuleTree::~CDlgModuleTree()
{
}

int CDlgModuleTree::OnCreate(LPCREATESTRUCT lpCreateStruct){
	int ret = CDialogBar::OnCreate(lpCreateStruct);
	return ret;
}

LRESULT CDlgModuleTree::OnInitDialog(WPARAM wParam, LPARAM lParam){
	HandleInitDialog(wParam, lParam);
	this->treeCtrl = (CTreeCtrl*)(this->GetDlgItem(IDC_TREE_MODULE_TEMP));
	this->treeCtrl->SetDlgCtrlID(IDC_TREE_MODULE_TEMP); // ON_NOTIFY에서 더블클릭 이벤트 처리하기 위해 TreeCtrl에 아이디 등록
	this->treeCtrl->ModifyStyle(NULL, TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS);

	// ModuleList.xml에서 읽어와서 넣는다.
	this->moduleList.LoadModuleList();

	TVINSERTSTRUCT tvi;
	tvi.hParent = TVI_ROOT;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = MODULE_LIST;
	HTREEITEM hrootItem = this->treeCtrl->InsertItem(&tvi);


	// 모듈 트리에서 로그인 할 브로커 리스트
	this->SetLogInManager(&hrootItem);
	// 모튤 트리에서 데이터피딩 받을 브로커 리스트
	this->SetDataFeeder(&hrootItem);
	// 상품 리스트
	this->SetInstrumentManager(&hrootItem);
	// 데이터가공공자 리스트
	this->SetDataManufacturingManager(&hrootItem);
	// 전략 리스트
	this->SetStrategyManager(&hrootItem);
	// 트레이더 리스트
	this->SetTraderManager(&hrootItem);
	

	this->ExpandAllItems();

	return 1;
}

void CDlgModuleTree::SetLogInManager(HTREEITEM* root){
	TVINSERTSTRUCT tvi;
	tvi.hParent = *root;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = LOGIN_MANAGER;
	HTREEITEM loginItem = this->treeCtrl->InsertItem(&tvi);

	LPTSTR s = TEXT("E*Trade Login");
	tvi.hParent = loginItem;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = s;
	this->treeCtrl->InsertItem(&tvi);
}


void CDlgModuleTree::SetDataFeeder(HTREEITEM* root){
	// DataFeeder
	TVINSERTSTRUCT tvi;
	tvi.hParent = *root;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = DATA_FEEDING_MANAGER;
	HTREEITEM dataFeederItem = this->treeCtrl->InsertItem(&tvi);

	// Real-time Feeding
	tvi.hParent = dataFeederItem;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = REAL_TIME_FEEDING;
	HTREEITEM realTimeFeeding = this->treeCtrl->InsertItem(&tvi);

	// Broker
	//tvi.hParent = realTimeFeeding;
	//tvi.hInsertAfter = TVI_LAST;
	//tvi.item.mask = TVIF_TEXT;
	//tvi.item.pszText = BROKERS;
	//HTREEITEM broker = this->treeCtrl->InsertItem(&tvi);
	

	for (int i = 0; i < this->moduleList.GetDataFeederList().GetLength(); i++){
		LPTSTR s = const_cast<TCHAR*>(this->moduleList.GetDataFeederList().GetAt(i).c_str());
		tvi.hParent = realTimeFeeding;
		tvi.hInsertAfter = TVI_LAST;
		tvi.item.mask = TVIF_TEXT;
		tvi.item.pszText = s;
		this->treeCtrl->InsertItem(&tvi);
	}

	// Virtual Feeding
	tvi.hParent = dataFeederItem;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = VIRTUAL_FEEDING;
	HTREEITEM virtualFeeding = this->treeCtrl->InsertItem(&tvi);
}


void CDlgModuleTree::SetInstrumentManager(HTREEITEM* root){
	TVINSERTSTRUCT tvi;
	tvi.hParent = *root;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = _T("Instrument Manager");
	HTREEITEM instrumentManagerItem = this->treeCtrl->InsertItem(&tvi);

	
	//// Stock
	//tvi.hParent = instrumentManagerItem;
	//tvi.hInsertAfter = TVI_LAST;
	//tvi.item.mask = TVIF_TEXT;
	//tvi.item.pszText = _T("Stock");
	//HTREEITEM stockItem = this->treeCtrl->InsertItem(&tvi);

	//// ETF
	//tvi.hParent = instrumentManagerItem;
	//tvi.hInsertAfter = TVI_LAST;
	//tvi.item.mask = TVIF_TEXT;
	//tvi.item.pszText = _T("ETF");
	//HTREEITEM etfItem = this->treeCtrl->InsertItem(&tvi);

	//// Futures
	//tvi.hParent = instrumentManagerItem;
	//tvi.hInsertAfter = TVI_LAST;
	//tvi.item.mask = TVIF_TEXT;
	//tvi.item.pszText = _T("Futures");
	//HTREEITEM futuresItem = this->treeCtrl->InsertItem(&tvi);

	//// Option
	//tvi.hParent = instrumentManagerItem;
	//tvi.hInsertAfter = TVI_LAST;
	//tvi.item.mask = TVIF_TEXT;
	//tvi.item.pszText = _T("Option");
	//HTREEITEM optionItem = this->treeCtrl->InsertItem(&tvi);
}


void CDlgModuleTree::SetDataManufacturingManager(HTREEITEM* root){
	TVINSERTSTRUCT tvi;
	tvi.hParent = *root;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = _T("Data Manufacturing Manager");
	HTREEITEM dataManufacturingManagerItem = this->treeCtrl->InsertItem(&tvi);

	// Indicator Factory
	tvi.hParent = dataManufacturingManagerItem;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = _T("Indicator Factory");
	HTREEITEM indicatorFactoryItem = this->treeCtrl->InsertItem(&tvi);
}


void CDlgModuleTree::SetStrategyManager(HTREEITEM* root){
	TVINSERTSTRUCT tvi;
	tvi.hParent = *root;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = _T("Strategy Manager");
	HTREEITEM strategyManagerItem = this->treeCtrl->InsertItem(&tvi);

	tvi.hParent = strategyManagerItem;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = _T("Option Strategy");
	HTREEITEM optionStrategyItem = this->treeCtrl->InsertItem(&tvi);
}


void CDlgModuleTree::SetTraderManager(HTREEITEM* root){
	TVINSERTSTRUCT tvi;
	tvi.hParent = *root;
	tvi.hInsertAfter = TVI_LAST;
	tvi.item.mask = TVIF_TEXT;
	tvi.item.pszText = _T("Trader Manager");
	HTREEITEM traderManagerItem = this->treeCtrl->InsertItem(&tvi);
}



void CDlgModuleTree::ExpandAllItems(){
	HTREEITEM hRootItem = this->treeCtrl->GetRootItem();
	HTREEITEM hItem = hRootItem;

	while (hItem){
		CString temp = this->treeCtrl->GetItemText(hItem);
		if (this->treeCtrl->ItemHasChildren(hItem)){
			this->treeCtrl->Expand(hItem, TVE_EXPAND);
		}
		hItem = GetNextTreeItem(hItem);
	}
}

HTREEITEM CDlgModuleTree::GetNextTreeItem(HTREEITEM hItem){
	HTREEITEM ret = NULL;
	// has this item got any children
	if (this->treeCtrl->ItemHasChildren(hItem)){
		ret= this->treeCtrl->GetNextItem(hItem, TVGN_CHILD);
	}
	else if (this->treeCtrl->GetNextItem(hItem, TVGN_NEXT) != NULL){
		// the next item at this level
		ret= this->treeCtrl->GetNextItem(hItem, TVGN_NEXT);
	}
	else{
		// return the next item after our parent
		hItem = this->treeCtrl->GetParentItem(hItem);

		if (hItem != NULL){
			// no parent
			while (this->treeCtrl->GetNextItem(hItem, TVGN_NEXT) == NULL && hItem != NULL){
				hItem = this->treeCtrl->GetParentItem(hItem);
			}
			// next item that follows our parent
			ret = this->treeCtrl->GetNextItem(hItem, TVGN_NEXT);
		}		
	}
	return ret;
}


void CDlgModuleTree::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
}


void CDlgModuleTree::OnDblckkTreeTr(NMHDR* pNMHDR, LRESULT* pResult){
	this->treeCtrl = (CTreeCtrl*)(this->GetDlgItem(IDC_TREE_MODULE_TEMP));
	HTREEITEM hItem = this->treeCtrl->GetSelectedItem();
	if (hItem != NULL){
		CString moduleName = this->treeCtrl->GetItemText(hItem);
		// 여기서 부터 개발
		AfxGetMainWnd()->SendMessage(WMU_SELECT_MODULE_TREE_ITEM, (WPARAM)(LPCTSTR)moduleName, NULL);
	}
}



// CDlgModuleTree message handlers
