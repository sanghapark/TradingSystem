//DlgDataFeedingInfoItemAdd.cpp

#include "DlgDataFeedingInfoAdd.h"
#include "Constants.h"
#include "DlgDataFeedingModule.h"
#include "DataConverter.h"

IMPLEMENT_DYNCREATE(CDlgDataFeedingInfoAdd, CDialog)

BEGIN_MESSAGE_MAP(CDlgDataFeedingInfoAdd, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgDataFeedingInfoAdd::OnButtonClickedAdd)
END_MESSAGE_MAP()



CDlgDataFeedingInfoAdd::CDlgDataFeedingInfoAdd(CWnd* pParent)
	:CDialog(CDlgDataFeedingInfoAdd::IDD, pParent){
	this->pParent = (CDlgDataFeedingModule*)pParent;
}


CDlgDataFeedingInfoAdd::~CDlgDataFeedingInfoAdd(){
}


BOOL CDlgDataFeedingInfoAdd::OnInitDialog(){
	CDialog::OnInitDialog();
	this->InitComboBoxType();
	this->InitComboBoxTRType();

	int lastIndex = this->pParent->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetLength()-1;
	int itemID = this->pParent->pDataFeedingInfoManager->GetDataFeedingInfoItemList().GetAt(lastIndex).GetID()+1;

	this->editItemID.SetWindowText(DataConverter::ConvertIntToString(itemID).c_str());

	tstring selectedBroker = this->pParent->GetSelectedBroker();
	tstring selectedInstrumentType = this->pParent->GetSelectedInstrumentType();
	if (selectedBroker.compare(_T("All")) != 0){
		this->editBroker.SetWindowText(selectedBroker.c_str());
		this->editBroker.SetReadOnly();
	}
	if (selectedInstrumentType.compare(_T("All")) != 0){
		int typeIndex = this->GetIndexFromComboInstrumentType(selectedInstrumentType);
		this->comboBoxType.SetCurSel(typeIndex);
		this->comboBoxType.EnableWindow(FALSE);
	}
	return TRUE;
}

void CDlgDataFeedingInfoAdd::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ITEMID, this->editItemID);
	DDX_Control(pDX, IDC_EDIT_BROKEr, this->editBroker);
	DDX_Control(pDX, IDC_COMBO_TYPE, this->comboBoxType);
	DDX_Control(pDX, IDC_EDIT_NAME, this->editName);
	DDX_Control(pDX, IDC_EDIT_CODE, this->editCode);
	DDX_Control(pDX, IDC_COMBO_TRTYPE, this->comboBoxTRType);
	DDX_Control(pDX, IDC_EDIT_TRCODE, this->editTRCode);
	DDX_Control(pDX, IDC_CHECK_AUTO, this->checkAutoYN);
}

void CDlgDataFeedingInfoAdd::OnButtonClickedAdd(){
	CString tempItemID;
	CString tempBroker;
	CString tempType;
	CString tempName;
	CString tempCode;
	CString tempTRType;
	CString tempTRCode;
	BOOL autoYN = FALSE;
	
	this->editItemID.GetWindowText(tempItemID);

	this->editBroker.GetWindowText(tempBroker);
	this->comboBoxType.GetLBText(this->comboBoxType.GetCurSel(), tempType);
	this->editName.GetWindowText(tempName);
	this->editCode.GetWindowText(tempCode);
	this->comboBoxTRType.GetLBText(this->comboBoxTRType.GetCurSel(), tempTRType);
	this->editTRCode.GetWindowText(tempTRCode);
	autoYN = this->checkAutoYN.GetCheck();

	tempBroker.Trim();
	tempName.Trim();
	tempCode.Trim();
	tempTRCode.Trim();

	tstring strItemID = tempItemID;
	int itemID = DataConverter::ConvertStringToInt(strItemID);
	tstring broker = tempBroker;
	tstring type = tempType;
	tstring name = tempName;
	tstring code = tempCode;
	tstring trType = tempTRType;
	tstring trCode = tempTRCode;
	
	if (itemID > 0 &&
		broker.empty() == FALSE &&
		type.compare(_T("-Select-")) != 0 &&
		name.empty() == FALSE &&
		code.empty() == FALSE &&
		trCode.empty() == FALSE){
		tstring brokerName = broker;
		tstring instrumentTypeName = type;

		DataFeedingItemInfo item(itemID, broker, type, name, code, trType, trCode, autoYN);

		BOOL added = this->pParent->AddDataFeedingInstrument(item);
		if (added == TRUE){
			::SendMessage(GetSafeHwnd(), WM_CLOSE, NULL, NULL);
		}
		else{
			MessageBox(_T("Already in the list"), _T("Notice"), MB_ICONWARNING);
		}
	}
	else{
		MessageBox(_T("Fill out all options"), _T("Notice"), MB_ICONWARNING);
	}



}


void CDlgDataFeedingInfoAdd::InitComboBoxType(){
	int i = 0;
	this->comboBoxType.ResetContent();
	this->comboBoxType.InsertString(i++, _T("-Select-"));
	this->comboBoxType.InsertString(i++, STOCK);
	this->comboBoxType.InsertString(i++, ETF);
	this->comboBoxType.InsertString(i++, FUTURES);
	this->comboBoxType.InsertString(i++, OPTION);
	this->comboBoxType.SetCurSel(0);
}


void CDlgDataFeedingInfoAdd::InitComboBoxTRType(){
	int i = 0;
	this->comboBoxTRType.ResetContent();
	this->comboBoxTRType.InsertString(i++, _T("-Select-"));
	this->comboBoxTRType.InsertString(i++, CONTRACT);
	this->comboBoxTRType.InsertString(i++, LIMITORDERBOOK);
	this->comboBoxTRType.SetCurSel(0);
}



int CDlgDataFeedingInfoAdd::GetIndexFromComboInstrumentType(const tstring& instrumentType){
	BOOL found = FALSE;
	int count = this->comboBoxType.GetCount();
	int i = 0;
	int index = -1;
	while (i < count && found == FALSE){
		CString temp;
		tstring tempStr;
		this->comboBoxType.GetLBText(i, temp);
		tempStr = temp;
		if (tempStr.compare(instrumentType) == 0){
			found = TRUE;
			index = i;
		}
		i++;
	}
	return index;
}