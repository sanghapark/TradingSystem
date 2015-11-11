// COptionListGridCtrl.cpp

#include "OptionListGridCtrl.h"
#include "DataConverter.h"
#include "Constants.h"

BEGIN_MESSAGE_MAP(COptionListGridCtrl, CGridCtrl)
END_MESSAGE_MAP()

COptionListGridCtrl::COptionListGridCtrl(CWnd* pParent)
	:countColumn(22),
	fixedRow(2),
	fixedColumn(1),
	fontSize(13){
	this->parentDlg = (CDlgOptionStrategy*)pParent;
	COLORREF black = RGB(0, 0, 0);
	this->SetListMode(FALSE);
	this->SetGridLines(GVL_BOTH);
	this->SetGridLineColor(black);
	this->SetFixedRowSelection(FALSE);
	this->SetFixedColumnSelection(FALSE);
	this->SetSingleColSelection(FALSE);
	this->SetColumnCount(this->countColumn);
	this->SetFixedRowCount(this->fixedRow);
	this->SetFixedColumnCount(this->fixedColumn);
	this->SetColumnResize(FALSE);
	this->SetRowResize(FALSE);
	this->InitHeader();

	this->preSelectedCol = -1;
	this->preSelectedRow = -1;
}


COptionListGridCtrl::~COptionListGridCtrl(){

}




void COptionListGridCtrl::InitHeader(){

	const COLORREF 	GREY = RGB(0, 0, 0);

	GV_ITEM item;
	item.mask = GVIF_TEXT|GVIF_FORMAT;
	item.nFormat = DT_VCENTER|DT_SINGLELINE|DT_CENTER;
	item.row = 0;
	item.col = 10;
	item.crBkClr = GREY;
	item.strText = _T("콜옵션");
	BOOL temp = this->SetItem(&item);

	CGridCellBase* cellBase = this->GetCell(0, 4);
	LOGFONT* tempLogFont = cellBase->GetFont();
	tempLogFont->lfHeight= this->fontSize;;
	cellBase->SetFont(tempLogFont);

	item.mask = GVIF_TEXT|GVIF_FORMAT;
	item.row = 0;
	item.col = 12;
	item.crBkClr = GREY;
	item.strText = _T("풋옵션");
	temp = this->SetItem(&item);

	cellBase = this->GetCell(0, 6);
	tempLogFont = cellBase->GetFont();
	tempLogFont->lfHeight= this->fontSize;;
	cellBase->SetFont(tempLogFont);

	const TCHAR* columnTitles[] = {COUNT, 
									MP_TSTP, MP_TP, TSTV, TTV, MTV, INV, TSTP, TP, MP, CODE, 
									SP, 
									CODE, MP, TP, TSTP, INV, MTV, TTV, TSTV, MP_TP, MP_TSTP};
	int colCount = this->GetColumnCount();
	for (int i = 0; i < colCount; i++){
		GV_ITEM item;
		item.mask = GVIF_TEXT|GVIF_FORMAT;
		item.nFormat = DT_VCENTER|DT_SINGLELINE|DT_CENTER;
		item.row = 1;
		item.col = i;
		this->SetItemBkColour(1, i, RGB(224, 224, 224));
		this->SetItemBkColour(0, i, RGB(224, 224, 224));
		item.strText = columnTitles[i];
		BOOL temp = this->SetItem(&item);

		CGridCellBase* cellBase = this->GetCell(0, i);
		LOGFONT* tempLogFont = cellBase->GetFont();
		tempLogFont->lfHeight= this->fontSize;;
		cellBase->SetFont(tempLogFont);

		cellBase = this->GetCell(1, i);
		tempLogFont = cellBase->GetFont();
		tempLogFont->lfHeight= this->fontSize;;
		cellBase->SetFont(tempLogFont);
	}
}


void COptionListGridCtrl::ResetOptionPriceBoardGridCtrl(const OptionPriceBoard& board){
	//this->DeleteList();
	
	const COLORREF 	GREY = RGB(224, 224, 224);
	const COLORREF 	RED = RGB(255, 204, 204);
	const COLORREF 	BLUE = RGB(204, 229, 255);
	const COLORREF 	WHITE = RGB(255, 255, 255);
	const COLORREF 	GREEN = RGB(0, 204, 0);

	int count = board.GetNumStrikePrices();
	this->SetRowCount(count+2);
	for(int i=0; i<count; i++){
		int rowIndex = i+2;
		int columnIndex = 0;

		OptionInfo callOptionInfo = board.GetCallOptions().GetAt(i);
		OptionInfo putOptionInfo = board.GetPutOptions().GetAt(i);

		double strikePrice = callOptionInfo.GetStrikePrice();
		double callOptionMarketPrice = callOptionInfo.GetMarketPrice();
		double putOptionMarketPrice = putOptionInfo.GetMarketPrice();


		GV_ITEM item;
		item.mask = GVIF_TEXT|GVIF_FORMAT;
		item.nFormat = DT_VCENTER|DT_SINGLELINE|DT_RIGHT;
		item.row = rowIndex;
		
		// 1. # 
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, GREY);
		item.strText = DataConverter::ConvertIntToString(rowIndex-1).c_str();
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		double gap = 0.0;
		// 2. MP-TSTP
		item.col = columnIndex;
		gap = callOptionMarketPrice - callOptionInfo.GetOption().GetOptionValue().GetValue();
		if(gap>0){
			this->SetItemBkColour(rowIndex, columnIndex, RED);
		}
		else{
			this->SetItemBkColour(rowIndex, columnIndex, BLUE);
		}
		item.strText.Format(_T("%.2f"), gap);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 3. MP-TP
		item.col = columnIndex;
		gap = callOptionMarketPrice - callOptionInfo.GetBrokerOptionValue().GetValue();
		if(gap>0){
			this->SetItemBkColour(rowIndex, columnIndex, RED);
		}
		else{
			this->SetItemBkColour(rowIndex, columnIndex, BLUE);
		}
		item.strText.Format(_T("%.2f"), gap);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 4. TSTV
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), callOptionInfo.GetOption().GetOptionValue().GetTimeValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 5. TTV
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), callOptionInfo.GetBrokerOptionValue().GetValue() - callOptionInfo.GetBrokerOptionValue().GetIntrinsicValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 6. MTV
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), callOptionMarketPrice - callOptionInfo.GetBrokerOptionValue().GetIntrinsicValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 7. INV
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), callOptionInfo.GetBrokerOptionValue().GetIntrinsicValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 8. TSTP
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), callOptionInfo.GetOption().GetOptionValue().GetValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 9. TP
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), callOptionInfo.GetBrokerOptionValue().GetValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 10. MP
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), callOptionMarketPrice);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 11. CODE
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText = callOptionInfo.GetOption().GetOptionCode().c_str();
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 12. SP
		// 등가격인지 확인
		BOOL atm  = FALSE;
		double* strikePricesATM = board.GetStrikePricesATM();
		for(int i=0; i<board.GetCountATM(); i++){
			if(strikePrice == strikePricesATM[i]){
				atm = TRUE;
			}
		}
		if(atm==TRUE){
			this->SetItemBkColour(rowIndex, columnIndex, GREEN);
		}
		else{
			this->SetItemBkColour(rowIndex, columnIndex, GREY);
		}
		item.col = columnIndex;
		item.nFormat = DT_VCENTER|DT_SINGLELINE|DT_CENTER;
		item.strText.Format(_T("%.2f"), strikePrice);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;


		// 13. 풋옵션
		//풋옵션코드
		item.col = columnIndex;
		item.nFormat = DT_VCENTER|DT_SINGLELINE|DT_RIGHT;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText = putOptionInfo.GetOption().GetOptionCode().c_str();
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 14. MP
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), putOptionMarketPrice);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 15. TP
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), putOptionInfo.GetBrokerOptionValue().GetValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 16. TSTP
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), putOptionInfo.GetOption().GetOptionValue().GetValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 17. INV
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), putOptionInfo.GetBrokerOptionValue().GetIntrinsicValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 18. MTV
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), putOptionMarketPrice - putOptionInfo.GetBrokerOptionValue().GetIntrinsicValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 19. TTV
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), putOptionInfo.GetBrokerOptionValue().GetValue() - putOptionInfo.GetBrokerOptionValue().GetIntrinsicValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 20. TSTV
		item.col = columnIndex;
		this->SetItemBkColour(rowIndex, columnIndex, WHITE);
		item.strText.Format(_T("%.2f"), putOptionInfo.GetOption().GetOptionValue().GetTimeValue());
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		// 21. MP-TP
		item.col = columnIndex;
		gap = putOptionMarketPrice - putOptionInfo.GetBrokerOptionValue().GetValue();
		if(gap>0){
			this->SetItemBkColour(rowIndex, columnIndex, RED);
		}
		else{
			this->SetItemBkColour(rowIndex, columnIndex, BLUE);
		}
		item.strText.Format(_T("%.2f"), gap);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
		columnIndex++;

		//22. MP-TSTP
		item.col = columnIndex;
		gap = putOptionMarketPrice - putOptionInfo.GetOption().GetOptionValue().GetValue();
		if(gap>0){
			this->SetItemBkColour(rowIndex, columnIndex, RED);
		}
		else{
			this->SetItemBkColour(rowIndex, columnIndex, BLUE);
		}
		item.strText.Format(_T("%.2f"), gap);
		this->SetItem(&item);
		this->SetItemState(rowIndex, columnIndex, GVIS_READONLY);
	}
}


void COptionListGridCtrl::DeleteList(){
	for (int i = 2; i<this->GetRowCount(); i++){
		this->DeleteRow(i);
	}
}


void COptionListGridCtrl::SetSelectedOptionRange(int row, int col){

	if(row>1){
		if(col >=1 && col<=10){
			this->SetSelectedRange(row, 1, row, 10);
		}
		else if(col>=12 && col <= 21){
			this->SetSelectedRange(row, 12, row, 21);
		}
		else{
			//this->gridCtrlOptionList.SetSelectedRange(nRow, 0, nRow, 19);
		}
	}

	this->preSelectedRow = row;
	this->preSelectedCol = col;
}



CString COptionListGridCtrl::GetOptionCode(int row, int col){
	CString cstrCode;

	if(row>1){
		if(col >=1 && col<=10){
			cstrCode = this->GetItemText(row, 10); 
		}
		else if(col>=12 && col <= 21){
			cstrCode = this->GetItemText(row, 12); 
		}
		else{
			//this->gridCtrlOptionList.SetSelectedRange(nRow, 0, nRow, 19);
		}
	}

	return cstrCode;
}