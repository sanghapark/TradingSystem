// DlgInstrumentManager.h

#pragma once

#include <afxwin.h>
#include "resource.h"
#include "InstrumentGridCtrl.h"


class CModuleRelationView;
class InstrumentManager;

class CDlgInstrumentManager : public CDialog{
	DECLARE_DYNCREATE(CDlgInstrumentManager)	

	public:
		enum{ IDD = IDD_DIALOG_INSTRUMENT_MANAGER};
		
		CModuleRelationView* pParentView;
		InstrumentManager* pInstrumentManager;

	public:
		CDlgInstrumentManager(CWnd* pParent=NULL);
		virtual ~CDlgInstrumentManager();
		virtual BOOL OnInitDialog();


	protected:
		virtual void DoDataExchange(CDataExchange* pDX);

		DECLARE_MESSAGE_MAP()

	private:
		void InitComboBoxInstrumentType();

	private:
		CComboBox comboBoxInstrumentType;

		CInstrumentGridCtrl instrumentGridCtrl;
};