// COptionPositionGridCtrl.h

#pragma once

#include "GridCtrl_src/GridCtrl.h"
#include "PositionList.h"

class CDlgOptionStrategy;

class COptionPositionGridCtrl : public CGridCtrl{

public:
	COptionPositionGridCtrl(CWnd* pParent=NULL);
	virtual ~COptionPositionGridCtrl();

protected:
	DECLARE_MESSAGE_MAP()

public:
	void InitHeader();
	void InsertOptionPosition(int rowIndex,  const OptionParameter& optionInfo);
	void RefreshOptionPositions(PositionList& positionList);
	void DeleteAllPositions();
	void DeletePosition(int rowIndex);
	CString GetOptionCode(int selectedRow);
	int GetPositionNumber(int selectedRow);



public:
	CDlgOptionStrategy* parentDlg;
	const int countColumn;
	const int fixedRow;
	const int fixedColumn;
	const int fontSize;
};