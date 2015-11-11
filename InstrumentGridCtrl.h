// InstrumentGridCtrl.h

#pragma once

#include "GridCtrl_src/GridCtrl.h"
#include "InstrumentList.h"

class CDlgInstrumentManager;

class CInstrumentGridCtrl : public CGridCtrl{
	public:
		CInstrumentGridCtrl(CWnd* pParent=NULL);
		virtual ~CInstrumentGridCtrl();

		void InitGrid(int itemCount);
		void InsertInstrumentList(const InstrumentList& instrumentList);

	protected:
		DECLARE_MESSAGE_MAP()

	private:
		void InitHeader();
		void InsertInstrument(int rowIndex, const Instrument& instrument);
		void DeleteAllInstruments();

	public:
		CDlgInstrumentManager* parentDlg;

	private:
		const int columnCount;
		const int fixedRow;
		const int fixedColumn;
		const int fontSize;
};