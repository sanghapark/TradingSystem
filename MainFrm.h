
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

#include "DlgLoginStatusTabBar.h"
#include "DlgModuleTree.h"

class CMainFrame : public CFrameWnd{
	protected: // create from serialization only
		CMainFrame();
		DECLARE_DYNCREATE(CMainFrame)

	// Attributes
	public:

	// Operations
	public:

	// Overrides
	public:
		virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
		virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
		virtual void OnSize(UINT nType, int cx, int cy);

	// Implementation
	public:
		virtual ~CMainFrame();
	#ifdef _DEBUG
		virtual void AssertValid() const;
		virtual void Dump(CDumpContext& dc) const;
	#endif

	protected:  // control bar embedded members
		CToolBar			m_wndToolBar;
		CStatusBar			m_wndStatusBar;
		CDlgLoginStatusTabBar	m_wndLoginStatusTabBar;
		CSplitterWnd		m_wndRelationSplitter;
		BOOL				m_bInitRelationSplitter;
		//CDialogBar »ó¼Ó, CModuleTreeView ¸â¹öº¯¼ö °¡Áü
		CDlgModuleTree m_wndModuleTree;

	// Generated message map functions
	protected:
		afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		afx_msg void OnViewLoginStatusTabBar();
		afx_msg LRESULT OnSelectModuleTreeItem(WPARAM wParam, LPARAM lParam);
		afx_msg LRESULT ReadviseDataFeeding(WPARAM wParam, LPARAM lParam);
		DECLARE_MESSAGE_MAP()


};


