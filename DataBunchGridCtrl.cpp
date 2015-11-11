// DataCollectionListCtrl.cpp
// 

#include "DataBunchGridCtrl.h"
#include "TradingSystemManager.h"
#include "DataConverter.h"
#include "NewCellTypes/GridCellCheck.h"
#include "DlgDataFeedingModule.h"

BEGIN_MESSAGE_MAP(CDataBunchGridCtrl, CGridCtrl)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGED, &CDataBunchGridCtrl::OnSelectItem)
END_MESSAGE_MAP()


CDataBunchGridCtrl::CDataBunchGridCtrl(CWnd* pParent)
	:columnCount(4),
	fixedRow(1),
	fixedColumn(1),
	columnIndexCheckBox(this->columnCount-1){
	this->parentDlg = (CDlgDataFeedingModule*)pParent;
	COLORREF black = RGB(0, 0, 0);
	this->SetListMode(TRUE);
	this->SetGridLines(GVL_BOTH);
	this->SetGridLineColor(black);
	this->SetSingleRowSelection(TRUE);
	this->SetSingleColSelection(TRUE);
	this->SetFixedRowSelection(FALSE);
	this->SetFixedColumnSelection(FALSE);
}



CDataBunchGridCtrl::~CDataBunchGridCtrl(){
}



void CDataBunchGridCtrl::InitGrid(int rowCount){
	this->DeleteAllItems();
	this->SetRowCount(rowCount + 1);
	this->SetColumnCount(this->columnCount);
	this->SetFixedRowCount(this->fixedRow);
	this->SetFixedColumnCount(this->fixedColumn);
	this->InitHeader();
}


void CDataBunchGridCtrl::InitHeader(){
	const TCHAR* columns[] = {TEXT("#"), TEXT("Name"), TEXT("Save"), TEXT("Directory/FileName")};
	const COLORREF 	GREY = RGB(160, 160, 160);
	int colCount = this->GetColumnCount();
	for (int i = 0; i < colCount; i++){
		GV_ITEM item;
		item.mask = GVIF_TEXT;
		item.row = 0;
		item.col = i;
		item.crBkClr = GREY;
		item.strText = columns[i];
		BOOL temp = this->SetItem(&item);
		temp;
	}
}

void CDataBunchGridCtrl::SetSelectedRow(int rowIndex){
	this->SetSelectedRange(rowIndex, 1, 1, 1);
	this->SetSelectedRange(rowIndex, 0, rowIndex, this->columnCount - 1);
}


void CDataBunchGridCtrl::InsertDataBunchList(const DataBunchList& dataBunchList){
	for (int i = 0; i < dataBunchList.GetLength(); i++){
		DataBunch dataBunch = const_cast<DataBunchList&>(dataBunchList).GetAt(i);
		this->InsertDataBunch(i+1, dataBunch, dataBunchList.GetDirectoryForSaving());
	}
}


void CDataBunchGridCtrl::InsertDataBunch(int rowIndex, const DataBunch& dataBunch, const tstring& baseDirectory){
	DataConverter converter;

	GV_ITEM item;
	item.mask = GVIF_TEXT;
	item.row = rowIndex;

	int colIndex = 0;

	item.col = colIndex;
	item.strText = converter.ConvertIntToString(rowIndex).c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, colIndex, GVIS_READONLY);
	colIndex++;

	item.col = colIndex;
	item.strText = dataBunch.GetName().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, colIndex, GVIS_READONLY);
	colIndex++;

	CGridCellCheck* pCheckBoxCell = NULL;
	this->SetCellType(rowIndex, colIndex, RUNTIME_CLASS(CGridCellCheck));
	pCheckBoxCell = (CGridCellCheck*)this->GetCell(rowIndex, colIndex);
	if (dataBunch.GetSaveYN() == TRUE){
		pCheckBoxCell->SetCheck(TRUE);
	}
	else{
		pCheckBoxCell->SetCheck(FALSE);
	}
	colIndex++;

	tstring fullDirectoryWithFileName = baseDirectory + TEXT("\\") + dataBunch.GetName() + TEXT("\\");
	item.col = colIndex;
	item.strText = fullDirectoryWithFileName.c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, colIndex, GVIS_READONLY);
}


void CDataBunchGridCtrl::DeleteItems(){

}



void CDataBunchGridCtrl::OnSelectItem(NMHDR* pNMHDR, LRESULT* pResult){

	CCellRange& selectedCellRange = this->GetSelectedCellRange();
	int selectedIndex = selectedCellRange.GetMinRow();

	tstring dataBunchName = this->GetCell(selectedIndex, 1)->GetText();
	int listIndex = this->parentDlg->pDataFeedingInfoManager->GetDataBunchList().FindDataBunch(dataBunchName);

	DataBunch& dataBunch1 = this->parentDlg->pDataFeedingInfoManager->GetDataBunchList().GetAt(0);
	DataBunch& dataBunch2 = this->parentDlg->pDataFeedingInfoManager->GetDataBunchList().GetAt(1);


	if (listIndex >= 0){
		DataBunch& dataBunch = this->parentDlg->pDataFeedingInfoManager->GetDataBunchList().GetAt(listIndex);
		this->parentDlg->GetDataBunchItemGridCtrl().DeleteNonFixedRows();
		this->parentDlg->GetDataBunchItemGridCtrl().SetRowCount(dataBunch.GetLength()+1);
		this->parentDlg->GetDataBunchItemGridCtrl().InsertDataBunch(dataBunch);
	}	
}