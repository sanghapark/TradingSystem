#pragma once


// CModuleRelationView view

class CDlgDataFeedingModule;
class CDlgInstrumentManager;
class CDlgOptionStrategy;

class CModuleRelationView : public CView
{
	DECLARE_DYNCREATE(CModuleRelationView)

	protected:
		CModuleRelationView();           // protected constructor used by dynamic creation
		virtual ~CModuleRelationView();

	public:
		virtual void OnDraw(CDC* pDC);      // overridden to draw this view
		
		// CDlgDataFeedingModule 관련 함수
		CDlgDataFeedingModule* CreateDlgDataFeedingModule();


		// CDlgInstrumentManager 관련 함수
		CDlgInstrumentManager* CreateDlgInstrumentManager();

		// CDlgOptionStrategy 관련함수
		CDlgOptionStrategy* CreateDlgOptionStrategy();

	public: // 이 View창에서 생성되는 Dialog 포인터
		CDlgDataFeedingModule* p_DlgDataFeedingModule;
		CDlgInstrumentManager* p_DlgInstrumentManager;
		CDlgOptionStrategy* p_DlgOptionStrategy;


	#ifdef _DEBUG
		virtual void AssertValid() const;
	#ifndef _WIN32_WCE
		virtual void Dump(CDumpContext& dc) const;
	#endif
	#endif

	protected:
		DECLARE_MESSAGE_MAP()
		afx_msg LRESULT ReadviseDataFeeding(WPARAM wParam, LPARAM lParam);

	private:
		CDialog* CreateManagerDialog(CRuntimeClass* pClass, UINT uID);

		
};


