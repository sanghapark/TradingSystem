// OutputView.cpp : implementation file
//

#include "stdafx.h"
#include "TradingSystem.h"
#include "OutputView.h"


// COutputView

IMPLEMENT_DYNCREATE(COutputView, CView)

COutputView::COutputView()
{

}

COutputView::~COutputView()
{
}

BEGIN_MESSAGE_MAP(COutputView, CView)
END_MESSAGE_MAP()


// COutputView drawing

void COutputView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// COutputView diagnostics

#ifdef _DEBUG
void COutputView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void COutputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// COutputView message handlers
