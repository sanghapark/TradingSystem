// OptionPositionGridCtrl.cpp

#include "OptionPositionGridGtrl.h"
#include "DlgOptionStrategy.h"
#include "OptionParameter.h"
#include "DataConverter.h"

BEGIN_MESSAGE_MAP(COptionPositionGridCtrl, CGridCtrl)
END_MESSAGE_MAP()


COptionPositionGridCtrl::COptionPositionGridCtrl(CWnd* pParent)
	:countColumn(10),
	fixedRow(1),
	fixedColumn(1),
	fontSize(13){
	this->parentDlg = (CDlgOptionStrategy*)pParent;
	COLORREF black = RGB(0, 0, 0);
	this->SetListMode(TRUE);
	this->SetGridLines(GVL_BOTH);
	this->SetGridLineColor(black);
	this->SetSingleRowSelection(TRUE);
	this->SetColumnCount(this->countColumn);
	this->SetFixedRowCount(this->fixedRow);
	this->SetFixedColumnCount(this->fixedColumn);
	this->SetColumnResize(FALSE);
	this->SetRowResize(FALSE);
	this->InitHeader();
}


COptionPositionGridCtrl::~COptionPositionGridCtrl(){
}


void COptionPositionGridCtrl::InitHeader(){
	const TCHAR* columnTitles[] = { _T("#"), _T("포지션 #"), _T("옵션코드"), _T("타입"), _T("포지션"), _T("계약수"), _T("행사가"), _T("프리미엄"), _T("현재청산손익(pt)") , _T("현재청산손익(원)")};
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


void COptionPositionGridCtrl::InsertOptionPosition(int rowIndex, const OptionParameter& optionInfo){
	DataConverter converter;
	int columnIndex = 0;

	GV_ITEM item;
	item.mask = GVIF_TEXT;
	item.row = rowIndex;

	item.col = columnIndex;
	item.strText = converter.ConvertIntToString(rowIndex).c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = optionInfo.GetOptionCode().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = optionInfo.GetOptionType().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = optionInfo.GetPosition().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText.Format(_T("%d"), optionInfo.GetNumContract());
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText.Format(_T("%.2f"), optionInfo.GetStrikePrice());;
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText.Format(_T("%.2f"), optionInfo.GetPremium());;
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
}


void COptionPositionGridCtrl::RefreshOptionPositions(PositionList& positionList){
	this->DeleteAllPositions();
	this->SetRowCount(positionList.GetLength()+1);

	DataConverter converter;

	for(int i=0; i<positionList.GetLength(); i++){
		int rowIndex = i+1;
		int columnIndex = 0;
		Position* position = positionList.GetAt(i);
		GV_ITEM item;
		item.mask = GVIF_TEXT;
		item.row = rowIndex;

		item.col = columnIndex;
		item.strText.Format(_T("%d"), rowIndex);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText.Format(_T("%d"), position->GetPositionNumber());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText = position->GetOption().GetOptionCode().c_str();
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText = position->GetOption().GetOptionType().c_str();
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText = position->GetPositionType().c_str();
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;


		item.col = columnIndex;
		item.strText.Format(_T("%d"), position->GetNumContract());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText.Format(_T("%.2f"), position->GetOption().GetStrikePrice());;
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText.Format(_T("%.2f"), position->GetPremium());;
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText.Format(_T("%d"), _T(""));;
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		item.col = columnIndex;
		item.strText.Format(_T("%.2f"), position->GetPremium());;
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	}
	this->AutoSize();
	this->ExpandColumnsToFit();
}




void COptionPositionGridCtrl::DeleteAllPositions(){
	for (int i = 1; i<this->GetRowCount(); i++){
		this->DeleteRow(i);
	}
}


void COptionPositionGridCtrl::DeletePosition(int rowIndex){
	this->DeleteRow(rowIndex);
}


CString COptionPositionGridCtrl::GetOptionCode(int selectedRow){
	CString cstrCode;

	if(selectedRow > 0){
		cstrCode = this->GetItemText(selectedRow, 1);
	}

	return cstrCode;
}


int COptionPositionGridCtrl::GetPositionNumber(int selectedRow){
	CString cstrPositionNumber;
	int positionNumber = -1;
	if(selectedRow > 0){
		cstrPositionNumber = this->GetItemText(selectedRow, 1);
		positionNumber = _ttoi(cstrPositionNumber);
	}
	return positionNumber;
}