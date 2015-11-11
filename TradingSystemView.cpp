
// TradingSystemView.cpp : implementation of the CTradingSystemView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TradingSystem.h"
#endif

#include "TradingSystemDoc.h"
#include "TradingSystemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTradingSystemView

IMPLEMENT_DYNCREATE(CTradingSystemView, CView)

BEGIN_MESSAGE_MAP(CTradingSystemView, CView)
END_MESSAGE_MAP()

// CTradingSystemView construction/destruction

CTradingSystemView::CTradingSystemView()
{
	// TODO: add construction code here

}

CTradingSystemView::~CTradingSystemView()
{
}

BOOL CTradingSystemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTradingSystemView drawing

void CTradingSystemView::OnDraw(CDC* /*pDC*/)
{
	CTradingSystemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTradingSystemView diagnostics

#ifdef _DEBUG
void CTradingSystemView::AssertValid() const
{
	CView::AssertValid();
}

void CTradingSystemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTradingSystemDoc* CTradingSystemView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTradingSystemDoc)));
	return (CTradingSystemDoc*)m_pDocument;
}
#endif //_DEBUG


// CTradingSystemView message handlers
