
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// User-defined Messages
#define WMU_SELECT_MODULE_TREE_ITEM (WM_USER + 1000)
#define WMU_READVISE_DATA_FEEDING (WM_USER+1001)


// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions


//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")


#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#include <afxcview.h>
#include "TradingSystemManager.h"


//extern TradingSystemManager tradingSystemManager;
extern	BOOL		g_bShowRaw;

#define WMU_SHOW_TR		( WM_USER + 1000 )
#define WMU_SET_MESSAGE	( WM_USER + 1001 )

enum
{
	DATA_TYPE_STRING = 0,		// 문자열
	DATA_TYPE_LONG,				// 정수
	DATA_TYPE_FLOAT,			// 실수
	DATA_TYPE_FLOAT_DOT,		// 실수( 소숫점을 가지고 있음 )
};

CString GetDispData( TCHAR* psData, int nSize, int nType, int nDotPos=0 );
void SetXingPacketData( TCHAR* psData, int nSize, LPCTSTR pszSrc, int nType, int nDotPos=0 );
void SetXingPacketData( TCHAR* psData, int nSize, CWnd* pWnd, int nID, int nType, int nDotPos=0 );









