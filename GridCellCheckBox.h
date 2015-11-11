// GridCellCheckBox.h

#pragma once

#include "NewCellTypes/GridCellCheck.h"


class CGridCellCheckBox : public CGridCellCheck{
	DECLARE_DYNCREATE(CGridCellCheckBox)
	
	public:
		CGridCellCheckBox();
		virtual ~CGridCellCheckBox();
	private:
		virtual BOOL Draw(CDC* pDC, int nRow, int nCol, CRect rect, BOOL bEraseBkgnd /* = TRUE */);
		
};