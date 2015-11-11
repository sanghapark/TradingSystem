// DataBunchListCtrl.h
// 
#pragma once

#include "GridCtrl_src/GridCtrl.h"
#include "DataBunchList.h"

class CDlgDataFeedingModule;

class CDataBunchGridCtrl : public CGridCtrl{
public:
	CDataBunchGridCtrl(CWnd* pParent = NULL);
	virtual ~CDataBunchGridCtrl();

	void InitGrid(int rowCount);
	void InsertDataBunchList(const DataBunchList& dataBunchList);
	void SetSelectedRow(int rowIndex);

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSelectItem(NMHDR* pNMHDR, LRESULT* pResult);
	
private:
	void InitHeader();
	void InsertDataBunch(int rowIndex, const DataBunch& dataBunch, const tstring& baseDirectory);
	void DeleteItems();

public:
	CDlgDataFeedingModule* parentDlg;


private:
	const int columnCount;
	const int fixedRow;
	const int fixedColumn;
	const int columnIndexCheckBox;
};


