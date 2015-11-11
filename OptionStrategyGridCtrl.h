// OptionStrategyGridCtrl.h


#pragma once

#include "GridCtrl_src\GridCtrl.h"
#include "OptionStrategyList.h"

class CDlgOptionStrategy;

class COptionStrategyGridCtrl : public CGridCtrl{
public:
	COptionStrategyGridCtrl(CWnd* pParent=NULL);
	virtual ~COptionStrategyGridCtrl();

protected:
	DECLARE_MESSAGE_MAP()

public:
	void InitHeader();
	void RefreshOptionStrategy(OptionStrategyList& optionStrategyList);
	void DeleteAll();
	void DeleteOptionStrategy(int rowIndex);
	CString GetStrategyName(int rowIndex);

private:
	CDlgOptionStrategy* parentDlg;
	const int countCol;
	const int fixedRow;
	const int fixedCol;
	const int fontSize;
};