// COptionListGridCtrl.h

#pragma once

#include "GridCtrl_src/GridCtrl.h"
#include "packet/t2301.h"
#include "OptionPriceBoard.h"


class CDlgOptionStrategy;

class COptionListGridCtrl : public CGridCtrl{
	public:
		COptionListGridCtrl(CWnd* pParent=NULL);
		virtual ~COptionListGridCtrl();
	
	protected:
		DECLARE_MESSAGE_MAP()

	public:
		void InitHeader();
		void ResetOptionPriceBoardGridCtrl(const OptionPriceBoard& board);
		void DeleteList();
		void SetSelectedOptionRange(int row, int col);
		CString GetOptionCode(int row, int col);

	public:
		CDlgOptionStrategy* parentDlg;
		
		int GetPreSelectedRow() const;
		int GetPreSelectedCol() const;

	private:
		const int countColumn;
		const int fixedRow;
		const int fixedColumn;
		const int fontSize;

		int preSelectedRow;
		int preSelectedCol;
};



inline int COptionListGridCtrl::GetPreSelectedRow() const{
	return this->preSelectedRow;
}


inline int COptionListGridCtrl::GetPreSelectedCol() const{
	return this->preSelectedCol;
}