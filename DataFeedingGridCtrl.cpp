// CDataFeedingGridCtrl.cpp

#include "DataFeedingGridCtrl.h"
#include "Constants.h"
#include "NewCellTypes//GridCellCheck.h"
#include "DataConverter.h"
#include "DlgDataFeedingModule.h"


BEGIN_MESSAGE_MAP(CDataFeedingGridCtrl, CGridCtrl)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



CDataFeedingGridCtrl::CDataFeedingGridCtrl(CWnd* pParent)
	:countColumn(9),
	fixedRow(1),
	fixedColumn(1),
	columnIndexCheckBox(countColumn-1),
	fontSize(13){
	this->parentDlg = (CDlgDataFeedingModule*)pParent;
	COLORREF black = RGB(0, 0, 0);
	this->SetListMode(TRUE);
	this->SetGridLines(GVL_BOTH);
	this->SetGridLineColor(black);
	this->SetSingleRowSelection(TRUE);
	this->SetSingleColSelection(TRUE);
	this->changed = FALSE;
}


CDataFeedingGridCtrl::~CDataFeedingGridCtrl(){
}


void CDataFeedingGridCtrl::InitDataFeedingInfoGrid(int itemCount){
	this->DeleteAllItems();
	this->SetRowCount(itemCount + 1); // because Headers
	this->SetColumnCount(this->countColumn);
	this->SetFixedRowCount(this->fixedRow);
	this->SetFixedColumnCount(this->fixedColumn);
	this->InitDataFeedingInfoGridHeader();
}


void CDataFeedingGridCtrl::InitDataFeedingInfoGridHeader(){
	const TCHAR* columnTitles[] = { COUNT, ITEMID, BROKER, INSTRUMENT, NAME, CODE, TRTYPE, TRCODE, AUTO };
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

		/*LOGFONT* logFont = const_cast<LOGFONT*>(GetItemFont(0, i));
		LOGFONT tempLogFont;
		memcpy(&tempLogFont, logFont, sizeof(LOGFONT));
		tempLogFont.lfHeight = 10;
		this->SetItemFont(0, i, &tempLogFont);*/
	}
}


void CDataFeedingGridCtrl::InsertDataFeedingInfo(const DataFeedingInfoItemListInGrid& list){
	for (int i = 0; i < list.GetLength(); i++){
		DataFeedingItemInfo& itemInfo = *(const_cast<DataFeedingInfoItemListInGrid&>(list).GetAt(i));
		this->InsertItem(itemInfo.GetRowIndex(), itemInfo);
		itemInfo.SetRowIndex(i+1);
	}
}


void CDataFeedingGridCtrl::InsertItem(int rowIndex, const DataFeedingItemInfo& itemInfo){
	int columnIndex = 0;
	
	GV_ITEM item;
	item.mask = GVIF_TEXT;
	item.row = rowIndex;

	item.col = columnIndex;
	tstring tempRowIndex;
	if (itemInfo.GetSaveSatus() == FALSE){
		tempRowIndex = DataConverter::ConvertIntToString(rowIndex) + TEXT("*");
	}
	else{
		tempRowIndex = DataConverter::ConvertIntToString(rowIndex).c_str();
	}
	item.strText = tempRowIndex.c_str();
	this->SetItem(&item);
	columnIndex++;
	
	item.col = columnIndex;
	item.strText = DataConverter::ConvertIntToString(itemInfo.GetID()).c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = itemInfo.GetBroker().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;
	
	item.col = columnIndex;
	item.strText = itemInfo.GetInstrumentType().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = itemInfo.GetInstrumentName().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = itemInfo.GetInstrumentCode().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = itemInfo.GetTRType().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;

	item.col = columnIndex;
	item.strText = itemInfo.GetTRCode().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	columnIndex++;
	
	CGridCellCheck* pCheckBoxCell;
	this->SetCellType(rowIndex, columnIndex, RUNTIME_CLASS(CGridCellCheck));
	pCheckBoxCell = (CGridCellCheck*)this->GetCell(rowIndex, columnIndex);
	if (itemInfo.GetAutoYN() == TRUE){
		pCheckBoxCell->SetCheck(TRUE);
	}
	else{
		pCheckBoxCell->SetCheck(FALSE);
	}


	for(int i=0; i<this->countColumn; i++){
		CGridCellBase* cellBase = this->GetCell(rowIndex, i);
		LOGFONT* tempLogFont = cellBase->GetFont();
		tempLogFont->lfHeight= this->fontSize;
		cellBase->SetFont(tempLogFont);
	}

}



void CDataFeedingGridCtrl::DeleteAllDataFeedingItem(){
	for (int i = 1; i<this->GetRowCount(); i++){
		this->DeleteRow(i);
	}
}




//void CDataFeedingGridCtrl::NotifyFeedingResult(const DataFeedingInfoItemListInGrid& itemList){
//	COLORREF green = RGB(0, 255, 0);
//	COLORREF red = RGB(255, 0, 0);
//	COLORREF white = RGB(255, 255, 255);
//
//	for (int i = 0; i < itemList.GetLength(); i++){
//		DataFeedingItemInfo& item = *(const_cast<DataFeedingInfoItemListInGrid&>(itemList).GetAt(i));
//		if (item.GetFeedingStatus() == 1){
//			this->SetItemBkColour(item.GetRowIndex(), this->columnIndexCheckBox, green);
//			this->GetCell(item.GetRowIndex(), this->columnIndexCheckBox)->SetText(TEXT("On"));
//		}
//		else if (item.GetFeedingStatus() == 0){
//			this->SetItemBkColour(item.GetRowIndex(), this->columnIndexCheckBox, red);
//			this->GetCell(item.GetRowIndex(), this->columnIndexCheckBox)->SetText(TEXT("Failed"));
//		}
//		else{
//			this->SetItemBkColour(item.GetRowIndex(), this->columnIndexCheckBox, white);
//			this->GetCell(item.GetRowIndex(), this->columnIndexCheckBox)->SetText(TEXT(""));
//		}
//	}
//	this->AutoSizeColumn(this->columnIndexCheckBox);
//}

void CDataFeedingGridCtrl::DisplayFeedingResult(){
	COLORREF green = RGB(0, 255, 0);
	COLORREF red = RGB(255, 0, 0);
	COLORREF white = RGB(255, 255, 255);

	DataFeedingInfoItemListInGrid& listForGrid = this->parentDlg->pDataFeedingInfoManager->GetListForGrid();

	for (int i = 0; i < listForGrid.GetLength(); i++){
		DataFeedingItemInfo& item = *(const_cast<DataFeedingInfoItemListInGrid&>(listForGrid).GetAt(i));
		if (item.GetFeedingStatus() == 1){
			this->SetItemBkColour(item.GetRowIndex(), this->columnIndexCheckBox, green);
			this->GetCell(item.GetRowIndex(), this->columnIndexCheckBox)->SetText(TEXT("On"));
		}
		else if (item.GetFeedingStatus() == 0){
			this->SetItemBkColour(item.GetRowIndex(), this->columnIndexCheckBox, red);
			this->GetCell(item.GetRowIndex(), this->columnIndexCheckBox)->SetText(TEXT("Failed"));
		}
		else{
			this->SetItemBkColour(item.GetRowIndex(), this->columnIndexCheckBox, white);
			this->GetCell(item.GetRowIndex(), this->columnIndexCheckBox)->SetText(TEXT("Off"));
		}
	}
	this->AutoSizeColumn(this->columnIndexCheckBox);
	this->Refresh();
}

void CDataFeedingGridCtrl::OnLButtonUp(UINT nFlags, CPoint point){
	
	
	CGridCtrl::OnLButtonUp(nFlags, point);
	
	int row = this->m_idCurrentCell.row;
	int col = this->m_idCurrentCell.col;
	int listIndex = row - 1;

	if (row > 0 && col == this->columnIndexCheckBox){
		BOOL inCheckBoxArea = FALSE;
		CGridCellCheck* pCell = (CGridCellCheck*)this->GetCell(row, col);
		
		if (pCell != 0){
			CRect rectCell = pCell->GetCheckBoxRect();;
			inCheckBoxArea = rectCell.PtInRect(point);
			if (inCheckBoxArea == TRUE){
				DataFeedingItemInfo& item = *(this->parentDlg->pDataFeedingInfoManager->GetListForGrid().GetAt(row-1));
				BOOL preState = item.GetAutoYN();
				BOOL curState = pCell->GetCheck();
				if (preState != curState){
					DataConverter converter;
					item.SetSaveStatus(FALSE);
					item.SetAutoYN(curState);
					tstring rowNumber = converter.ConvertIntToString(row) + TEXT("*");
					this->GetCell(row, 0)->SetText(rowNumber.c_str());
					this->AutoSize();
					this->ExpandColumnsToFit();
					this->Refresh();
					this->changed = TRUE;
				}
			}
		}
	}
}
