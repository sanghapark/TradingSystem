// CDataFeedingGridCtrl.h

#pragma  once

#include "GridCtrl_src/GridCtrl.h"
#include "DataFeedingItemInfoList.h"
#include "DataTypeDefinition.h"
#include "DataFeedingInfoItemListInGrid.h"
#include "Constants.h"


class CDlgDataFeedingModule;

class CDataFeedingGridCtrl : public CGridCtrl{
	public:
		CDataFeedingGridCtrl(CWnd* pParent=NULL);
		virtual ~CDataFeedingGridCtrl();

		BOOL GetChanged() const;

	protected:
		DECLARE_MESSAGE_MAP()
		afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	
	public:
		void InitDataFeedingInfoGrid(int itemCount);
		void InitDataFeedingInfoGridHeader();
		void InsertDataFeedingInfo(const DataFeedingInfoItemListInGrid& list);
		void InsertItem(int rowIndex, const DataFeedingItemInfo& itemInfo);

		void DeleteAllDataFeedingItem();

		//void NotifyFeedingResult(const DataFeedingInfoItemListInGrid& list);
		void DisplayFeedingResult();

	public:
		CDlgDataFeedingModule* parentDlg;

	private:
		BOOL changed;
		const int countColumn;
		const int fixedRow;
		const int fixedColumn;
		const int columnIndexCheckBox;
		const int fontSize;
};

inline BOOL CDataFeedingGridCtrl::GetChanged() const{
	return this->changed;
}