// DataFeedingEditCtrl.h

#pragma once

#include <afxcmn.h>

class CDlgDataFeedingModule;

class CDataFeedingEditCtrl : public CEdit{
	public:
		CDataFeedingEditCtrl(CWnd* pParent = NULL);
		virtual ~CDataFeedingEditCtrl();

		void TraceStartDataFeeding();
		void TraceStopDataFeeding();
		void TraceDisconnection();

		CDlgDataFeedingModule* parentDlg;

	protected:
		//DECLARE_MESSAGE_MAP()

	private:
		
};