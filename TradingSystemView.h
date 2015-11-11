
// TradingSystemView.h : interface of the CTradingSystemView class
//

#pragma once


class CTradingSystemView : public CView
{
	protected: // create from serialization only
		CTradingSystemView();
		DECLARE_DYNCREATE(CTradingSystemView)

	// Attributes
	public:
		CTradingSystemDoc* GetDocument() const;

	// Operations
	public:

	// Overrides
	public:
		virtual void OnDraw(CDC* pDC);  // overridden to draw this view
		virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:

	// Implementation
	public:
		virtual ~CTradingSystemView();
	#ifdef _DEBUG
		virtual void AssertValid() const;
		virtual void Dump(CDumpContext& dc) const;
	#endif

	protected:

	// Generated message map functions
	protected:
		DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TradingSystemView.cpp
inline CTradingSystemDoc* CTradingSystemView::GetDocument() const
   { return reinterpret_cast<CTradingSystemDoc*>(m_pDocument); }
#endif

