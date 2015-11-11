
// TradingSystem.h : main header file for the TradingSystem application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols



// CTradingSystemApp:
// See TradingSystem.cpp for the implementation of this class
//

class IXingAPI;
class TradingSystemManager;

class CTradingSystemApp : public CWinApp{
	public:
		CTradingSystemApp();
		~CTradingSystemApp();


	public:
		// Αυ±Η»η APIs
		IXingAPI* xingAPI;
		TradingSystemManager* tradingSystemManager;

	public:
		virtual BOOL InitInstance();

		afx_msg void OnAppAbout();
		DECLARE_MESSAGE_MAP()

		

	private:
		
};


extern CTradingSystemApp theApp;