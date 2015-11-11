// InstrumentGridCtrl.cpp

#include "InstrumentGridCtrl.h"
#include "DataConverter.h"


BEGIN_MESSAGE_MAP(CInstrumentGridCtrl, CGridCtrl)
END_MESSAGE_MAP()


CInstrumentGridCtrl::CInstrumentGridCtrl(CWnd* pParent)
	:columnCount(5),
	fixedRow(1),
	fixedColumn(1),
	fontSize(13){
	this->parentDlg = (CDlgInstrumentManager*)pParent;

	COLORREF black = RGB(0, 0, 0);
	this->SetListMode(TRUE);
	this->SetGridLines(GVL_BOTH);
	this->SetGridLineColor(black);
	this->SetSingleRowSelection(TRUE);
	this->SetSingleColSelection(TRUE);
}


CInstrumentGridCtrl::~CInstrumentGridCtrl(){
}


void CInstrumentGridCtrl::InitGrid(int itemCount){
	this->DeleteAllItems();
	this->SetRowCount(itemCount+1);
	this->SetColumnCount(this->columnCount);
	this->SetFixedRowCount(this->fixedRow);
	this->SetFixedColumnCount(this->fixedColumn);
	this->InitHeader();
}


void CInstrumentGridCtrl::InsertInstrumentList(const InstrumentList& instrumentList){
	int rowIndex=0;
	for(int i=0; i<instrumentList.GetLength(); i++){
		rowIndex = i+1;
		Instrument& instrument = const_cast<InstrumentList&>(instrumentList).GetAt(i);
		this->InsertInstrument(rowIndex, instrument);
	}
}


void CInstrumentGridCtrl::InitHeader(){
	const tchar* columnTitles[] = {_T("Type"), _T("Name"), _T("Code"), _T("Contract"), _T("LimitOrderBook")};
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


void CInstrumentGridCtrl::InsertInstrument(int rowIndex, const Instrument& instrument){
	int columnIndex = 0;

	GV_ITEM item;
	item.mask = GVIF_TEXT;
	item.row = rowIndex;

	item.col = columnIndex;
	item.strText = DataConverter::ConvertIntToString(rowIndex).c_str();
	this->SetItem(&item);
	columnIndex++;

	item.col = columnIndex;
	item.strText = instrument.GetInstrumentType().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = instrument.GetInstrumentName().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = instrument.GetInstrumentCode().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = DataConverter::ConvertIntToString(instrument.GetContract().GetFeedingSourceID()).c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = DataConverter::ConvertIntToString(instrument.GetLimitOrderBook().GetFeedingSourceID()).c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	for(int i=0; i<this->columnCount; i++){
		CGridCellBase* cellBase = this->GetCell(rowIndex, i);
		LOGFONT* tempLogFont = cellBase->GetFont();
		tempLogFont->lfHeight= this->fontSize;
		cellBase->SetFont(tempLogFont);
	}
}


void CInstrumentGridCtrl::DeleteAllInstruments(){
	for(int i=0; i<this->GetRowCount(); i++){
		this->DeleteRow(i);
	}
}