#include "stdafx.h"
#include "afx.h"
#include <afxcmn.h>
#include "DlgDataFeedingModule.h"
#include "DlgDataFeedingInfoAdd.h"
#include "DataConverter.h"
#include "Constants.h"
#include "TradingSystem.h"
#include "IXingAPI.h"
#include "./packet/FC0.h"
#include "./packet/FH0.h"
#include "./packet/S3_.h"
#include "./packet/H1_.h"
#include "./packet/OC0.h"
#include "./packet/OH0.h"

#include "ModuleRelationView.h"

#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include "TradingSystemManager.h"


IMPLEMENT_DYNCREATE(CDlgDataFeedingModule, CDialog)


BEGIN_MESSAGE_MAP(CDlgDataFeedingModule, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_BROKER, &CDlgDataFeedingModule::SelectComboBoxBroker)
	ON_CBN_SELCHANGE(IDC_COMBO_INSTRUMENT_TYPE, &CDlgDataFeedingModule::SelectComboBoxInstrumentType)
	ON_CBN_SELCHANGE(IDC_COMBO_TR_TYPE, &CDlgDataFeedingModule::SelectOptions)
	ON_BN_CLICKED(IDC_CHECK_AUTO_CHECKED, &CDlgDataFeedingModule::SelectOptions)
	ON_BN_CLICKED(IDC_BUTTON_BOOK, &CDlgDataFeedingModule::OnButtonCliekedBook)
	ON_BN_CLICKED(IDC_BUTTON_START, &CDlgDataFeedingModule::OnButtonClickedStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CDlgDataFeedingModule::OnButtonClickedStop)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CDlgDataFeedingModule::OnButtonClickedEdit)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgDataFeedingModule::OnButtonClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDlgDataFeedingModule::OnButtonClickedSave)
	ON_MESSAGE(WM_USER + XM_RECEIVE_REAL_DATA, &CDlgDataFeedingModule::OnXMReceiveRealData)
	ON_MESSAGE(WMU_READVISE_DATA_FEEDING, &CDlgDataFeedingModule::ReadviseDataFeeding)
	ON_WM_CLOSE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


CDlgDataFeedingModule::CDlgDataFeedingModule(CWnd* pParent)
	:CDialog(CDlgDataFeedingModule::IDD, pParent),
	gridCtrl(this),
	dataBunchGridCtrl(this),
	dataBunchItemGridCtrl(this){
	this->pParentView = 0;
	// XingAPI 세팅
	//CTradingSystemApp* app = (CTradingSystemApp*)AfxGetApp();
	this->xingAPI = theApp.xingAPI;

	this->pDataFeedingInfoManager = &(theApp.tradingSystemManager->GetDataFeedingInfoManager());
	this->p_InstrumentCodeMaker = &(theApp.tradingSystemManager->GetInstrumentCodeMaker());

	this->dataFeeding = FALSE;

	this->bookDataFeedingID = 0;
	this->bookedDataFeeding = FALSE;
}

CDlgDataFeedingModule::~CDlgDataFeedingModule(){
}

void CDlgDataFeedingModule::PostNcDestroy(){
	CDialog::PostNcDestroy();
	this->pParentView->p_DlgDataFeedingModule =0;
	delete this;
}

void CDlgDataFeedingModule::OnClose(){
	CDialog::OnClose();
	this->StopETradeDataFeeding();
	this->DestroyWindow();
}


BOOL CDlgDataFeedingModule::OnInitDialog(){
	CDialog::OnInitDialog();

	// Initilize TimeCtrl and DateCtrl
	CTime currentTime = CTime::GetCurrentTime();
	CTime timeToSet(currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay(), 8, 50, 0);
	this->dateCtrl.SetTime(&timeToSet);
	this->timeCtrl.SetTime(&timeToSet);
	
	// Initialize ComboBox
	this->InitComboBoxBroker();
	this->InitComboBoxInstrumentType();
	this->InitComboBoxTRType();

	// Initialize List
	//this->gridCtrl.DeleteNonFixedRows();
	this->gridCtrl.DeleteAllItems();
	//this->pDataFeedingInfoManager->ReadDataFeedingItemList();
	if(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetLength()>0){
		// Get Selected Options
		tstring selectedBrokerName = this->GetSelectedBroker();
		tstring selectedInstrumentType = this->GetSelectedInstrumentType();
		tstring selectedTRType = this->GetSelectedTRType();
		int onlyToFeed = this->buttonAutoOnly.GetCheck();
		BOOL arranged = this->pDataFeedingInfoManager->ArrangeListForGrid(selectedBrokerName, selectedInstrumentType, selectedTRType, onlyToFeed);
		if(arranged==TRUE){
			this->gridCtrl.InitDataFeedingInfoGrid(this->pDataFeedingInfoManager->GetListForGrid().GetLength());
			this->ListDataFeedingInfoInGrid(this->pDataFeedingInfoManager->GetListForGrid());
		}
	}


	//DataBunchList
	this->dataBunchGridCtrl.DeleteAllItems();
	//this->pDataFeedingInfoManager->ReadDataBunchList();
	if(this->pDataFeedingInfoManager->GetDataBunchList().GetLength()>0){
		this->dataBunchGridCtrl.InitGrid(this->pDataFeedingInfoManager->GetDataBunchList().GetLength());
		this->ListDataBunchList(this->pDataFeedingInfoManager->GetDataBunchList());
		this->dataBunchGridCtrl.SetSelectedRow(0);
	}

	CCellRange& selectedCellRange = this->dataBunchGridCtrl.GetSelectedCellRange();
	int selectedListIndex = selectedCellRange.GetMinRow()-1;
	this->dataBunchItemGridCtrl.DeleteAllItems();
	this->dataBunchItemGridCtrl.InitGrid(this->pDataFeedingInfoManager->GetDataBunchList().GetAt(selectedListIndex).GetLength());
	DataBunch& dataBunch = this->pDataFeedingInfoManager->GetDataBunchList().GetAt(selectedListIndex);
	this->ListDataBunch(dataBunch);

	
	// 자동 체크 된것들 피딩받기
	//this->StartETradeDataFeeding();
	//this->GetDataBunchItemGridCtrl().DisplayFeedingResult();

	// 자동 세팅되있는거 확인하고 XingAPI에 요청
	//우선 연결 및 로그인 되있는지 확인

	return TRUE;
}


void CDlgDataFeedingModule::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);

	// DataFeedingItemInfoList 관련
	DDX_Control(pDX, IDC_BUTTON_EDIT, this->buttonEdit);
	DDX_Control(pDX, IDC_BUTTON_ADD, this->buttonAdd);
	DDX_Control(pDX, IDC_BUTTON_SAVE, this->buttonSave);
	DDX_Control(pDX, IDC_BUTTON_START, this->buttonStart);
	DDX_Control(pDX, IDC_BUTTON_STOP, this->buttonStop);
	DDX_Control(pDX, IDC_CHECK_AUTO_CHECKED, this->buttonAutoOnly);
	DDX_Control(pDX, IDC_COMBO_BROKER, this->comboBoxBroker);
	DDX_Control(pDX, IDC_COMBO_INSTRUMENT_TYPE, this->comboBoxInstrumentType);
	DDX_Control(pDX, IDC_COMBO_TR_TYPE, this->comboBoxTRType);
	DDX_Control(pDX, IDC_CUSTOM_GRID, this->gridCtrl);

	// DataBunchList 관련
	DDX_Control(pDX, IDC_BUTTON_DATABUNCHLIST_DELETE, this->buttonDeleteDataBunchList);
	DDX_Control(pDX, IDC_BUTTON_DATABUNCHLIST_NEW, this->buttonNewDataBunchList);
	DDX_Control(pDX, IDC_CUSTOM_GRID_DATABUNCHLIST, this->dataBunchGridCtrl);

	// DataBunch 관련
	DDX_Control(pDX, IDC_BUTTON_DATABUNCH_DELETE, this->buttonDeleteDataBunch);
	DDX_Control(pDX, IDC_BUTTON_DATABUNCH_ADD, this->buttonAddDataBunch);
	DDX_Control(pDX, IDC_CUSTOM_GRID_DATABUNCH, this->dataBunchItemGridCtrl);

	DDX_Control(pDX, IDC_EDIT_TRACE, this->editCtrl);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, this->buttonClearTrace);


	// Data Feeding Booking 관련
	DDX_Control(pDX, IDC_TIMEPICKER, this->timeCtrl);
	DDX_Control(pDX, IDC_DATEPICKER, this->dateCtrl);
	DDX_Control(pDX, IDC_BUTTON_BOOK, this->buttonBooking);
}



void CDlgDataFeedingModule::SelectOptions(){
	tstring brokerName = this->GetSelectedBroker();
	CString temp;
	int index = this->comboBoxInstrumentType.GetCurSel();
	this->comboBoxInstrumentType.GetLBText(index, temp);
	tstring instrumentTypeName = temp;
	CString tempTRType;
	this->comboBoxTRType.GetLBText(this->comboBoxTRType.GetCurSel(), tempTRType);
	tstring trType = tempTRType;
	int onlyToFeed = this->buttonAutoOnly.GetCheck();
	this->gridCtrl.DeleteNonFixedRows();
	this->pDataFeedingInfoManager->ArrangeListForGrid(brokerName, instrumentTypeName, trType, onlyToFeed);
	this->gridCtrl.InitDataFeedingInfoGrid(this->pDataFeedingInfoManager->GetListForGrid().GetLength());
	this->ListDataFeedingInfoInGrid(this->pDataFeedingInfoManager->GetListForGrid());
	this->DisplayFeedingResult();
}


void CDlgDataFeedingModule::SelectComboBoxBroker(){
	this->SelectOptions();
}

void CDlgDataFeedingModule::SelectComboBoxInstrumentType(){
	this->SelectOptions();
}


void CDlgDataFeedingModule::OnButtonClickedAdd(){
	CDlgDataFeedingInfoAdd dlgAdd(this);
	dlgAdd.DoModal();
}


void CDlgDataFeedingModule::OnButtonCliekedBook(){
	if(this->bookedDataFeeding==FALSE){
		CTime timeToFeed;
		DWORD timeSet = this->timeCtrl.GetTime(timeToFeed);
		CString cstrTimeToFeed = timeToFeed.Format(_T("%H:%M:%S"));
		tstring strTime(cstrTimeToFeed);

		CTime dateToFeed;
		DWORD dateSet = this->dateCtrl.GetTime(dateToFeed);
		CString cstrDateToFeed = dateToFeed.Format(_T("%Y-%m-%d"));
		tstring strDate(cstrDateToFeed);

		tstring strFullDateTime(strDate + _T(" ") + strTime);

		boost::posix_time::ptime epoch = boost::posix_time::time_from_string(strFullDateTime);
		boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();

		boost::posix_time::time_duration diff = epoch - now;
		int temp = diff.total_milliseconds();
		this->SetTimer(this->bookDataFeedingID, temp, NULL);
		this->buttonBooking.SetWindowText(_T("Unbook"));
		this->buttonStart.EnableWindow(FALSE);
		this->buttonStop.EnableWindow(FALSE);
		this->bookedDataFeeding = TRUE;
	}
	else{
		this->KillTimer(this->bookDataFeedingID);
		this->buttonBooking.SetWindowText(_T("Book"));
		this->buttonStart.EnableWindow(TRUE);
		this->buttonStop.EnableWindow(TRUE);
		this->bookedDataFeeding = FALSE;
	}

}


void CDlgDataFeedingModule::OnButtonClickedStart(){
	this->pDataFeedingInfoManager->GetDataBunchList().InitSaving();
	this->StartETradeDataFeeding();
	this->DisplayFeedingResult();
	this->GetDataBunchItemGridCtrl().DisplayFeedingResult();
}

void CDlgDataFeedingModule::OnButtonClickedStop(){
	this->StopETradeDataFeeding();
	this->pDataFeedingInfoManager->GetDataBunchList().EndSaving();
	this->DisplayFeedingResult();
	this->GetDataBunchItemGridCtrl().DisplayFeedingResult();
}


void CDlgDataFeedingModule::OnButtonClickedEdit(){
}

void CDlgDataFeedingModule::OnButtonClickedSave(){
	BOOL changed = this->gridCtrl.GetChanged();
	if (changed == false){
		MessageBox(TEXT("No items have been changed."), TEXT("Notice"), MB_ICONWARNING);
	}
	else{
		this->pDataFeedingInfoManager->SaveDataFeedingItemInfoList();
	}
}




void CDlgDataFeedingModule::InitComboBoxBroker(){
	int index=0;
	this->comboBoxBroker.ResetContent();
	index = this->comboBoxBroker.AddString(ALL);
	index = this->comboBoxBroker.AddString(ETRADE);
	index = this->comboBoxBroker.AddString(WOORI);
	index = this->comboBoxBroker.SetCurSel(0);
}


void CDlgDataFeedingModule::InitComboBoxInstrumentType(){
	int index=0;
	this->comboBoxInstrumentType.ResetContent();
	index = this->comboBoxInstrumentType.AddString(ALL);
	index = this->comboBoxInstrumentType.AddString(STOCK);
	index = this->comboBoxInstrumentType.AddString(ETF);
	index = this->comboBoxInstrumentType.AddString(FUTURES);
	index = this->comboBoxInstrumentType.AddString(OPTION);
	index = this->comboBoxInstrumentType.SetCurSel(0);
}

void CDlgDataFeedingModule::InitComboBoxTRType(){
	int index = 0;
	this->comboBoxTRType.ResetContent();
	index = this->comboBoxTRType.AddString(ALL);
	index = this->comboBoxTRType.AddString(CONTRACT);
	index = this->comboBoxTRType.AddString(LIMITORDERBOOK);
	index = this->comboBoxTRType.SetCurSel(0);
}

int CDlgDataFeedingModule::GetIndexFromComboBoxBroker(const tstring& broker){
	BOOL found = FALSE;
	int count = this->comboBoxBroker.GetCount();
	int i = 0;
	int index = -1;
	while (i < count && found == FALSE){
		CString temp;
		tstring tempStr;
		this->comboBoxBroker.GetLBText(i, temp);
		tempStr = temp;
		if (tempStr.compare(broker) == 0){
			found = TRUE;
			index = i;
		}
		i++;
	}
	return index;
}


int CDlgDataFeedingModule::GetIndexFromComboBoxInstrumentType(const tstring& instrumentType){
	BOOL found = FALSE;
	int count = this->comboBoxInstrumentType.GetCount();
	int i = 0;
	int index = -1;
	while (i < count && found == FALSE){
		CString temp;
		tstring tempStr;
		this->comboBoxInstrumentType.GetLBText(i, temp);
		tempStr = temp;
		if (tempStr.compare(instrumentType) == 0){
			found = TRUE;
			index = i;
		}
		i++;
	}
	return index;
}


tstring CDlgDataFeedingModule::GetSelectedBroker(){
	CString temp;
	int index = this->comboBoxBroker.GetCurSel();
	this->comboBoxBroker.GetLBText(index, temp);
	tstring broker = temp;
	return broker;
}

tstring CDlgDataFeedingModule::GetSelectedInstrumentType(){
	CString temp;
	int index = this->comboBoxInstrumentType.GetCurSel();
	this->comboBoxInstrumentType.GetLBText(index, temp);
	tstring instrumentTypeName = temp;
	return instrumentTypeName;
}

tstring CDlgDataFeedingModule::GetSelectedTRType(){
	CString temp;
	this->comboBoxTRType.GetLBText(this->comboBoxTRType.GetCurSel(), temp);
	tstring trType = temp;
	return trType;
}



void CDlgDataFeedingModule::ListDataFeedingInfoInGrid(const DataFeedingInfoItemListInGrid& itemList){
	this->gridCtrl.InsertDataFeedingInfo(itemList);
	this->gridCtrl.AutoSize();
	this->gridCtrl.ExpandColumnsToFit();
}

void CDlgDataFeedingModule::ListDataBunchList(const DataBunchList& dataBunchList){
	this->dataBunchGridCtrl.InsertDataBunchList(dataBunchList);
	this->dataBunchGridCtrl.AutoSize();
	this->dataBunchGridCtrl.ExpandLastColumn();
}


void CDlgDataFeedingModule::ListDataBunch(const DataBunch& dataBunch){
	this->dataBunchItemGridCtrl.InsertDataBunch(dataBunch);
	this->dataBunchItemGridCtrl.AutoSize();
	this->dataBunchItemGridCtrl.ExpandColumnsToFit();
}



void CDlgDataFeedingModule::StartETradeDataFeeding(){
	BOOL ret = FALSE;

	if (this->xingAPI->IsConnected() == TRUE){
		
		this->dataFeeding = TRUE;
		this->editCtrl.TraceStartDataFeeding();
		
		for (int i = 0; i < this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetLength(); i++){
			ret = FALSE;
			DataFeedingItemInfo& item = this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(i);
			if(item.GetBroker().compare(ETRADE)==0){

				if (item.GetInstrumentType().compare(STOCK) == 0 || item.GetInstrumentType().compare(ETF) == 0){
					if (item.GetTRType().compare(CONTRACT)==0 && item.GetAutoYN() == TRUE){
						ret = this->xingAPI->AdviseRealData(this->GetSafeHwnd(), S3_, item.GetInstrumentCode().c_str(), sizeof(S3__InBlock));
					}
					else if (item.GetTRType().compare(LIMITORDERBOOK)==0  && item.GetAutoYN() == TRUE){
						ret = this->xingAPI->AdviseRealData(this->GetSafeHwnd(), H1_, item.GetInstrumentCode().c_str(), sizeof(H1__InBlock));
					}
				}
				else if (item.GetInstrumentType().compare(FUTURES) == 0){
					if (item.GetTRType().compare(CONTRACT)==0 && item.GetAutoYN() == TRUE){
						ret = this->xingAPI->AdviseRealData(this->GetSafeHwnd(), FC0, item.GetInstrumentCode().c_str(), sizeof(FC0_InBlock));
					}
					else if (item.GetTRType().compare(LIMITORDERBOOK)==0  && item.GetAutoYN() == TRUE){
						ret = this->xingAPI->AdviseRealData(this->GetSafeHwnd(), FH0, item.GetInstrumentCode().c_str(), sizeof(FH0_InBlock));
					}
				}
				item.AssignAdviseFeedingStatus(ret);
			}
		}
	}
	else{
		MessageBox(TEXT("Not Connected to E*Trade"), TEXT("Notice"), MB_ICONWARNING);
	}
}

void CDlgDataFeedingModule::StopETradeDataFeeding(){
	BOOL ret = FALSE;
	if (this->xingAPI->IsConnected() == TRUE){

		this->dataFeeding = FALSE;
		this->editCtrl.TraceStopDataFeeding();

		for (int i = 0; i < this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetLength(); i++){
			ret = FALSE;
			DataFeedingItemInfo& item = this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(i);
			if(item.GetBroker().compare(ETRADE)==0){
				if (item.GetInstrumentType().compare(STOCK) == 0 || item.GetInstrumentType().compare(ETF) == 0){
					if (item.GetTRType().compare(CONTRACT)==0 && item.GetFeedingStatus() == 1){
						ret = this->xingAPI->UnadviseRealData(this->GetSafeHwnd(), S3_, item.GetInstrumentCode().c_str(), sizeof(S3__InBlock));
					}
					else if (item.GetTRType().compare(LIMITORDERBOOK)==0 && item.GetFeedingStatus() == 1){
						ret = this->xingAPI->UnadviseRealData(this->GetSafeHwnd(), H1_, item.GetInstrumentCode().c_str(), sizeof(H1__InBlock));
					}
				}
				else if (item.GetInstrumentType().compare(FUTURES) == 0){
					if (item.GetTRType().compare(CONTRACT)==0 && item.GetFeedingStatus() == 1){
						ret = this->xingAPI->UnadviseRealData(this->GetSafeHwnd(), FC0, item.GetInstrumentCode().c_str(), sizeof(FC0_InBlock));
					}
					else if (item.GetTRType().compare(LIMITORDERBOOK)==0 && item.GetFeedingStatus() == 1){
						ret = this->xingAPI->UnadviseRealData(this->GetSafeHwnd(), FH0, item.GetInstrumentCode().c_str(), sizeof(FH0_InBlock));
					}
				}
				else if (item.GetInstrumentType().compare(OPTION) == 0){
					if (item.GetTRType().compare(CONTRACT)==0 && item.GetFeedingStatus() == 1){
						ret = this->xingAPI->UnadviseRealData(this->GetSafeHwnd(), OC0, item.GetInstrumentCode().c_str(), sizeof(OC0_InBlock));
					}
					else if (item.GetTRType().compare(LIMITORDERBOOK)==0 && item.GetFeedingStatus() == 1){
						ret = this->xingAPI->UnadviseRealData(this->GetSafeHwnd(), OH0, item.GetInstrumentCode().c_str(), sizeof(OH0_InBlock));
					}
				}
				item.AssignUnadviseFeedingStatus(ret);
			}
		}
	}
	else{
		MessageBox(TEXT("Not Connected to E*Trade"), TEXT("Notice"), MB_ICONWARNING);
	}
	
}

void CDlgDataFeedingModule::DisplayFeedingResult(){
	this->gridCtrl.DisplayFeedingResult();
	this->gridCtrl.AutoSize();
	this->gridCtrl.ExpandColumnsToFit();
}




int CDlgDataFeedingModule::AddDataFeedingInstrument(const DataFeedingItemInfo& item){
	int index = this->pDataFeedingInfoManager->AddDataFeedingItemInfo(item);
	if (index>=0){
		tstring brokerName = this->GetSelectedBroker();
		tstring instrumentTypeName = this->GetSelectedInstrumentType();
		tstring trType = this->GetSelectedTRType();
		int onlyToFeed = this->buttonAutoOnly.GetCheck();
		
		this->gridCtrl.DeleteNonFixedRows();
		this->pDataFeedingInfoManager->ArrangeListForGrid(brokerName, instrumentTypeName, trType, onlyToFeed);
		this->gridCtrl.InitDataFeedingInfoGrid(this->pDataFeedingInfoManager->GetListForGrid().GetLength());
		this->ListDataFeedingInfoInGrid(this->pDataFeedingInfoManager->GetListForGrid());
	}
	return index;
}


//LRESULT CDlgDataFeedingModule::OnXMReceiveRealData(WPARAM wParam, LPARAM lParam){
//	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;
//	tstring brokerName(ETRADE);
//	tstring trCode(pRealPacket->szTrCode);
//
//	// FC0
//	if (trCode.compare(FC0) == 0){
//		LPFC0_OutBlock pOutBlock = (LPFC0_OutBlock)pRealPacket->pszData;
//		tstring instrumentCode(pOutBlock->futcode, sizeof(pOutBlock->futcode));
//		int index = this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().FindIndexOfDataFeedingItemInfo(brokerName, instrumentCode, CONTRACT);
//		DataFeedingItemInfo* pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(index));
//		pItem->AssignDataBlock(pOutBlock, sizeof(FC0_OutBlock));
//	}
//	// FH0
//	else if (trCode.compare(FH0) == 0){
//		LPFH0_OutBlock pOutBlock = (LPFH0_OutBlock)pRealPacket->pszData;
//		tstring instrumentCode(pOutBlock->futcode, sizeof(pOutBlock->futcode));
//		int index = this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().FindIndexOfDataFeedingItemInfo(brokerName, instrumentCode, CONTRACT);
//		DataFeedingItemInfo* pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(index));
//		pItem->AssignDataBlock(pOutBlock, sizeof(FH0_OutBlock));
//	}
//	// S3_
//	else if (trCode.compare(S3_) == 0){
//		LPS3__OutBlock pOutBlock = (LPS3__OutBlock)pRealPacket->pszData;
//		tstring instrumentCode(pOutBlock->shcode, sizeof(pOutBlock->shcode));
//		int index = this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().FindIndexOfDataFeedingItemInfo(brokerName, instrumentCode, CONTRACT);
//		DataFeedingItemInfo* pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(index));
//		pItem->AssignDataBlock(pOutBlock, sizeof(S3__OutBlock));
//	}
//	// H1_
//	else if (trCode.compare(H1_) == 0){
//		LPH1__OutBlock pOutBlock = (LPH1__OutBlock)pRealPacket->pszData;
//		tstring instrumentCode(pOutBlock->shcode, sizeof(pOutBlock->shcode));
//		int index = this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().FindIndexOfDataFeedingItemInfo(brokerName, instrumentCode, CONTRACT);
//		DataFeedingItemInfo* pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(index));
//		pItem->AssignDataBlock(pOutBlock, sizeof(H1__OutBlock));
//	}
//	// OC0
//	else if (trCode.compare(OC0) == 0){
//		LPOC0_OutBlock pOutBlock = (LPOC0_OutBlock)pRealPacket->pszData;
//		tstring instrumentCode(pOutBlock->optcode, sizeof(pOutBlock->optcode));
//		int index = this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().FindIndexOfDataFeedingItemInfo(brokerName, instrumentCode, CONTRACT);
//		DataFeedingItemInfo* pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(index));
//		pItem->AssignDataBlock(pOutBlock, sizeof(OC0_OutBlock));
//	}
//	// OH0
//	else if (trCode.compare(OH0) == 0){
//		LPOH0_OutBlock pOutBlock = (LPOH0_OutBlock)pRealPacket->pszData;
//		tstring instrumentCode(pOutBlock->optcode, sizeof(pOutBlock->optcode));
//		int index = this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().FindIndexOfDataFeedingItemInfo(brokerName, instrumentCode, CONTRACT);
//		DataFeedingItemInfo* pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(index));
//		pItem->AssignDataBlock(pOutBlock, sizeof(OH0_OutBlock));
//	}
//	return 0L;
//}

LRESULT CDlgDataFeedingModule::OnXMReceiveRealData(WPARAM wParam, LPARAM lParam){
	LPRECV_REAL_PACKET pRealPacket = (LPRECV_REAL_PACKET)lParam;
	DataFeedingItemInfo* pItem = 0;

	// FC0
	if(_tcscmp(pRealPacket->szTrCode, FC0)==0){
		LPFC0_OutBlock pOutBlock = (LPFC0_OutBlock)pRealPacket->pszData;
		if(memcmp(pOutBlock->futcode, this->p_InstrumentCodeMaker->GetKOSPI200IndexFuturesCode().c_str(), sizeof(pOutBlock->futcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(10));
		}
		pItem->AssignDataBlock(pOutBlock, sizeof(FC0_OutBlock));
	}
	// FH0
	else if (_tcscmp(pRealPacket->szTrCode, FH0)==0){
		LPFH0_OutBlock pOutBlock = (LPFH0_OutBlock)pRealPacket->pszData;
		if(memcmp(pOutBlock->futcode, this->p_InstrumentCodeMaker->GetKOSPI200IndexFuturesCode().c_str(), sizeof(pOutBlock->futcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(11));
		}
		pItem->AssignDataBlock(pOutBlock, sizeof(FH0_OutBlock));
	}


	// S3_
	else if (_tcscmp(pRealPacket->szTrCode, S3_)==0){
		LPS3__OutBlock pOutBlock = (LPS3__OutBlock)pRealPacket->pszData;
		if(memcmp(pOutBlock->shcode, _T("005930"), sizeof(pOutBlock->shcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(0));
		}
		else if(memcmp(pOutBlock->shcode, _T("069500"), sizeof(pOutBlock->shcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(2));
		}
		else if(memcmp(pOutBlock->shcode, _T("122630"), sizeof(pOutBlock->shcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(4));
		}
		else if(memcmp(pOutBlock->shcode, _T("114800"), sizeof(pOutBlock->shcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(6));
		}
		pItem->AssignDataBlock(pOutBlock, sizeof(S3__OutBlock));
	}
	// H1_
	else if (_tcscmp(pRealPacket->szTrCode, H1_)==0){
		LPH1__OutBlock pOutBlock = (LPH1__OutBlock)pRealPacket->pszData;
		if(memcmp(pOutBlock->shcode, _T("005930"), sizeof(pOutBlock->shcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(1));
		}
		else if(memcmp(pOutBlock->shcode, _T("069500"), sizeof(pOutBlock->shcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(3));
		}
		else if(memcmp(pOutBlock->shcode, _T("122630"), sizeof(pOutBlock->shcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(5));
		}
		else if(memcmp(pOutBlock->shcode, _T("114800"), sizeof(pOutBlock->shcode))==0){
			pItem = &(this->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(7));
		}
		pItem->AssignDataBlock(pOutBlock, sizeof(H1__OutBlock));
	}
	return 0L;
}


LRESULT CDlgDataFeedingModule::ReadviseDataFeeding(WPARAM wParam, LPARAM lParam){

	if(this->dataFeeding == TRUE){
		this->editCtrl.TraceDisconnection();
		this->OnButtonClickedStart();
	}
	return 0L;
}



void CDlgDataFeedingModule::OnTimer(UINT_PTR nIDEvent){
	if(nIDEvent == this->bookDataFeedingID){
		this->KillTimer(this->bookDataFeedingID);
		this->buttonBooking.SetWindowText(_T("Book"));
		this->buttonStart.EnableWindow(TRUE);
		this->buttonStop.EnableWindow(TRUE);
		this->bookedDataFeeding = FALSE;
		this->OnButtonClickedStart();
	}
	else{

	}
}