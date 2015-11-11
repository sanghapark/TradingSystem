// DataBunchItemGridCtrl.h

#pragma once

#include "GridCtrl_src/GridCtrl.h"
#include "DataBunch.h"

class CDlgDataFeedingModule;
class DataFeedingItemInfo;

class CDataBunchItemGridCtrl : public CGridCtrl{
public:
	CDataBunchItemGridCtrl(CWnd* pParent = NULL);
	virtual ~CDataBunchItemGridCtrl();

	void InitGrid(int rowCount);
	void InsertDataBunch(const DataBunch& dataBunch);

	void DisplayFeedingResult();

protected:
	DECLARE_MESSAGE_MAP()

private:
	void InitHeader();
	void InsertData(int rowIndex, DataFeedingItemInfo* data);

public:
	CDlgDataFeedingModule* parentDlg;


private:
	const int columnCount;
	const int fixedRow;
	const int fixedColumn;
};