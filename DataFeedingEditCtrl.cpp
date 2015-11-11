// DataFeedingEditCtrl.cpp

#include "DataFeedingEditCtrl.h"
#include "DataTypeDefinition.h"

CDataFeedingEditCtrl::CDataFeedingEditCtrl(CWnd* pParent){
	this->parentDlg = (CDlgDataFeedingModule*)pParent;
}


CDataFeedingEditCtrl::~CDataFeedingEditCtrl(){
}


void CDataFeedingEditCtrl::TraceStartDataFeeding(){
	CTime currentTime = CTime::GetCurrentTime();
	CString cstrCurrentTime = currentTime.Format(_T("%Y-%m-%d  %H:%M:%S"));
	tstring strCurrentTime(cstrCurrentTime);
	tstring strLog(_T("Start Data Feeding"));
	tstring strTrace = strCurrentTime + _T(" : ") + strLog + _T("\r\n"); 

	int length;
	length = this->GetWindowTextLength();
	this->SetSel(length, length);
	this->ReplaceSel(strTrace.c_str());
}


void CDataFeedingEditCtrl::TraceStopDataFeeding(){
	CTime currentTime = CTime::GetCurrentTime();
	CString cstrCurrentTime = currentTime.Format(_T("%Y-%m-%d  %H:%M:%S"));
	tstring strCurrentTime(cstrCurrentTime);
	tstring strLog(_T("Stop Data Feeding"));
	tstring strTrace = strCurrentTime + _T(" : ") + strLog + _T("\r\n"); 

	int length;
	length = this->GetWindowTextLength();
	this->SetSel(length, length);
	this->ReplaceSel(strTrace.c_str());
}


void CDataFeedingEditCtrl::TraceDisconnection(){
	CTime currentTime = CTime::GetCurrentTime();
	CString cstrCurrentTime = currentTime.Format(_T("%Y-%m-%d  %H:%M:%S"));
	tstring strCurrentTime(cstrCurrentTime);
	tstring strLog(_T("Server was disconnected. Readvise Data Feeding"));
	tstring strTrace = strCurrentTime + _T(" : ") + strLog + _T("\r\n"); 

	int length;
	length = this->GetWindowTextLength();
	this->SetSel(length, length);
	this->ReplaceSel(strTrace.c_str());
}