// OptionStrategyGridCtrl.cpp

#include "OptionStrategyGridCtrl.h"
#include "DlgOptionStrategy.h"

BEGIN_MESSAGE_MAP(COptionStrategyGridCtrl, CGridCtrl)
END_MESSAGE_MAP()




COptionStrategyGridCtrl::COptionStrategyGridCtrl(CWnd* pParent)
	:countCol(2),
	fixedRow(1),
	fixedCol(1),
	fontSize(13){
		this->parentDlg = (CDlgOptionStrategy*)pParent;
		COLORREF black = RGB(0, 0, 0);
		this->SetListMode(TRUE);
		this->SetGridLines(GVL_BOTH);
		this->SetGridLineColor(black);
		this->SetSingleRowSelection(TRUE);
		this->SetColumnCount(this->countCol);
		this->SetFixedRowCount(this->fixedRow);
		this->SetFixedColumnCount(this->fixedCol);
		this->SetColumnResize(FALSE);
		this->SetRowResize(FALSE);
		this->InitHeader();
}


COptionStrategyGridCtrl::~COptionStrategyGridCtrl(){
}


void COptionStrategyGridCtrl::InitHeader(){
	const TCHAR* columnTitles[] = { _T("#"), _T("Strategy Name")};
	const COLORREF 	GREY = RGB(160, 160, 160);
	int colCount = this->GetColumnCount();
	for (int i = 0; i < colCount; i++){
		GV_ITEM item;
		item.mask = GVIF_TEXT;
		item.row = 0;
		item.col = i;
		item.crBkClr = GREY;
		item.strText = columnTitles[i];
		BOOL temp = this->SetItem(&item);

		CGridCellBase* cellBase = this->GetCell(0, i);
		LOGFONT* tempLogFont = cellBase->GetFont();
		tempLogFont->lfHeight= this->fontSize;;
		cellBase->SetFont(tempLogFont);
	}
}



void COptionStrategyGridCtrl::RefreshOptionStrategy(OptionStrategyList& optionStrategyList){
	this->DeleteAll();
	this->SetRowCount(optionStrategyList.GetLength()+1);

	for(int i=0; i<optionStrategyList.GetLength(); i++){
		int rowIndex = i+1;
		int columnIndex = 0;
		//Position* position = optionStrategyList.GetAt(i);
		
		PositionList* pPositionList = &(optionStrategyList.GetAt(i));
		
		GV_ITEM item;
		item.mask = GVIF_TEXT;
		item.row = rowIndex;

		item.col = columnIndex;
		item.strText.Format(_T("%d"), rowIndex);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText = pPositionList->GetName().c_str();
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);

	}
	this->AutoSize();
	this->ExpandColumnsToFit();
}



void COptionStrategyGridCtrl::DeleteAll(){
	for (int i = 1; i<this->GetRowCount(); i++){
		this->DeleteRow(i);
	}
}



void COptionStrategyGridCtrl::DeleteOptionStrategy(int rowIndex){
	this->DeleteRow(rowIndex);
}



CString COptionStrategyGridCtrl::GetStrategyName(int rowIndex){
	CString cstrName;

	int rowCount = this->GetRowCount();
	if(rowIndex > 0 && rowIndex < rowCount){
		cstrName = this->GetItemText(rowIndex, 1);
	}

	return cstrName;
}