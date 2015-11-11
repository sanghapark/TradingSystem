// DlgDataFeedingInfoAdd.h

#pragma once

#include <afxcmn.h>
#include "resource.h"
#include "DataTypeDefinition.h"

class CDlgDataFeedingModule;

class CDlgDataFeedingInfoAdd : public CDialog{
	DECLARE_DYNCREATE(CDlgDataFeedingInfoAdd)

	public:
		enum {IDD=IDD_DIALOG_DATA_FEEDING_INFO_ITEM_ADD};
		CDlgDataFeedingInfoAdd(CWnd* pParent = NULL);
		virtual ~CDlgDataFeedingInfoAdd();
		virtual BOOL OnInitDialog();

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);

		DECLARE_MESSAGE_MAP()
		afx_msg void OnButtonClickedAdd();

	private:
		void InitComboBoxType();
		void InitComboBoxTRType();
		int GetIndexFromComboInstrumentType(const tstring& instrumentType);

	public:
		CDlgDataFeedingModule* pParent;

	private:
		CEdit editItemID;
		CEdit editBroker;
		CComboBox comboBoxType;
		CEdit editName;
		CEdit editCode;
		CComboBox comboBoxTRType;
		CEdit editTRCode;
		CButton checkAutoYN;
};