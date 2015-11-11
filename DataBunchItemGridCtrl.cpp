// DataBunchItemGridCtrl.cpp

#include "DataBunchItemGridCtrl.h"
#include "DataFeedingItemInfo.h"
#include "DataConverter.h"
#include "DlgDataFeedingModule.h"

BEGIN_MESSAGE_MAP(CDataBunchItemGridCtrl, CGridCtrl)
END_MESSAGE_MAP()

CDataBunchItemGridCtrl::CDataBunchItemGridCtrl(CWnd* pParent)
	:columnCount(5),
	fixedRow(1),
	fixedColumn(1){
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


CDataBunchItemGridCtrl::~CDataBunchItemGridCtrl(){
}



void CDataBunchItemGridCtrl::InitGrid(int rowCount){
	this->DeleteAllItems();
	this->SetRowCount(rowCount + 1);
	this->SetColumnCount(this->columnCount);
	this->SetFixedRowCount(this->fixedRow);
	this->SetFixedColumnCount(this->fixedColumn);
	this->InitHeader();
}



void CDataBunchItemGridCtrl::InitHeader(){
	const TCHAR* columns[] = { TEXT("#"), TEXT("Broker"), TEXT("Name"), TEXT("Data Type"), TEXT("Feeding") };
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


void CDataBunchItemGridCtrl::InsertDataBunch(const DataBunch& dataBunch){
	for (int i = 0; i < dataBunch.GetLength(); i++){
		int itemId = const_cast<DataBunch&>(dataBunch).GetAt(i).GetItemID();
		int index  = this->parentDlg->pDataFeedingInfoManager->FindItemIndexByID(itemId);
		if(index>=0){
			DataFeedingItemInfo* data = &(this->parentDlg->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(index));
			this->InsertData(i+1, data);
		}
	}
	this->AutoSize();
	this->ExpandColumnsToFit(TRUE);
	this->DisplayFeedingResult();
}

void CDataBunchItemGridCtrl::InsertData(int rowIndex, DataFeedingItemInfo* data){
	DataConverter converter;
	int colIndex = 0;

	GV_ITEM item;
	item.mask = GVIF_TEXT;
	item.row = rowIndex;

	item.col = colIndex;
	item.strText = converter.ConvertIntToString(rowIndex).c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, colIndex, GVIS_READONLY);
	colIndex++;

	item.col = colIndex;
	item.strText = data->GetBroker().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, colIndex, GVIS_READONLY);
	colIndex++;

	item.col = colIndex;
	item.strText = data->GetInstrumentName().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, colIndex, GVIS_READONLY);
	colIndex++;

	item.col = colIndex;
	item.strText = data->GetTRType().c_str();
	this->SetItem(&item);
	this->SetItemState(rowIndex, colIndex, GVIS_READONLY);
	colIndex++;

	item.col = colIndex;
	if (data->GetFeedingStatus() > 0){
		item.strText = TEXT("On");
	}
	else{
		item.strText = TEXT("Off");
	}
	this->SetItem(&item);
	this->SetItemState(rowIndex, colIndex, GVIS_READONLY);
}


void CDataBunchItemGridCtrl::DisplayFeedingResult(){
	COLORREF green = RGB(0, 255, 0);
	COLORREF red = RGB(255, 0, 0);
	COLORREF white = RGB(255, 255, 255);

	CCellRange& selectedDataBunch = this->parentDlg->GetDataBunchGridCtrl().GetSelectedCellRange();
	int selectedIndex = selectedDataBunch.GetMinRow();

	tstring dataBunchName = this->parentDlg->GetDataBunchGridCtrl().GetCell(selectedIndex, 1)->GetText();
	int listIndex = this->parentDlg->pDataFeedingInfoManager->GetDataBunchList().FindDataBunch(dataBunchName);


	DataBunch& dataBunch = this->parentDlg->pDataFeedingInfoManager->GetDataBunchList().GetAt(listIndex);

	int rowCount = this->GetRowCount();
	int itemCount = rowCount-1;
	for(int i=0; i<dataBunch.GetLength(); i++){
		int itemID = dataBunch.GetAt(i).GetItemID();
		int itemIndex = this->parentDlg->pDataFeedingInfoManager->FindItemIndexByID(itemID);
		DataFeedingItemInfo& item = this->parentDlg->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(itemIndex);

		if(item.GetFeedingStatus()==1){
			BOOL ret = this->SetItemBkColour(i+1, 4, green);
			this->GetCell(i+1, 4)->SetText(TEXT("On"));
		}
		else if(item.GetFeedingStatus()==0){
			BOOL ret = this->SetItemBkColour(i+1, 4, red);
			this->GetCell(i+1, 4)->SetText(TEXT("Failed"));
		}
		else{
			BOOL ret = this->SetItemBkColour(i+1, 4, white);
			this->GetCell(i+1, 4)->SetText(TEXT("Off"));
		}
	}
	this->Refresh();
}