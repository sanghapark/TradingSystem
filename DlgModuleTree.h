#pragma once
#include "ModuleList.h"

// CDlgModuleTree dialog

class CDlgModuleTree : public CDialogBar
{
	DECLARE_DYNAMIC(CDlgModuleTree)

public:
	CDlgModuleTree(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgModuleTree();
	
	void SetLogInManager(HTREEITEM* root);
	void SetDataFeeder(HTREEITEM* root);
	void SetInstrumentManager(HTREEITEM* root);
	void SetDataManufacturingManager(HTREEITEM* root);
	void SetStrategyManager(HTREEITEM* root);
	void SetTraderManager(HTREEITEM* root);

	void ExpandAllItems();
	HTREEITEM GetNextTreeItem(HTREEITEM hItem);

// Dialog Data
	enum { IDD = IDD_DIALOG_MODULE_TREE_TEMP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

private:
	CTreeCtrl* treeCtrl;
	ModuleList moduleList;

	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnInitDialog(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDblckkTreeTr(NMHDR* pNMHDR, LRESULT* pResult);
};
