#pragma once

#include <tchar.h>

// Inument Types
#define ALL		_T("All")
#define STOCK	_T("Stock")
#define ETF		_T("ETF")
#define FUTURES	_T("Futures")
#define OPTION	_T("Option")


// Contract or LimirOrderBook
#define CONTRACT		_T("Contract")
#define LIMITORDERBOOK	_T("LimitOrderBook")

// TRCode
#define S3_		_T("S3_")
#define H1_		_T("H1_")
#define FC0		_T("FC0")
#define FH0		_T("FH0")
#define OC0		_T("OC0")
#define OH0		_T("OH0")



// BrokerName
#define ETRADE	_T("E*Trade")
#define WOORI	_T("Woori")


// DataFeeding Dialog List Columns
#define COUNT		_T("#")
#define ITEMID			_T("ID")
#define BROKER      _T("Broker")
#define INSTRUMENT	_T("Instrument")
#define NAME		_T("Name")
#define CODE _T("Code")
#define TRTYPE _T("TRType")
#define TRCODE _T("TRCode")
#define AUTO _T("Auto")
#define SAVE _T("Save")
#define MAP _T("Map")



// Start or STOP
#define START	_T("Start")
#define STOP	_T("Stop")


// Color
/*
static const COLORREF 	BLACK = RGB(0, 0, 0);
static const COLORREF 	BLUE = RGB(0, 0, 255);
static const COLORREF 	CYAN = RGB(0, 160, 160);
static const COLORREF 	GREEN = RGB(0, 255, 0);
static const COLORREF 	GREY = RGB(160, 160, 160);
static const COLORREF 	RED = RGB(255, 0, 0);
static const COLORREF 	WHITE = RGB(255, 255, 255);
static const COLORREF 	YELLOW = RGB(255, 255, 0);
*/

// Menu List
#define MODULE_LIST _T("Modules")
#define LOGIN_MANAGER _T("Login Manager")
#define ETRADE_LOGIN _T("E*Trade Login")
#define WOORI_LOGIN _T("Woori Login")
#define DATA_FEEDING_MANAGER _T("Data Feeding Manager")
#define REAL_TIME_FEEDING _T("Real-time Feeding")
#define BROKERS _T("Brokers")
#define DATA_BUNCHER _T("Data Buncher")
#define VIRTUAL_FEEDING _T("Virtual Feeding")



// Position
#define LONG_POSITION _T("long")
#define SHORT_POSITION _T("short")

// Option
#define CALL_OPTION _T("call")
#define PUT_OPTION _T("put")

// 옵션 전광판 칼럼명
#define SP  _T("SP")
#define MP _T("MP")
#define TP _T("TP")
#define TSTP _T("TSTP")
#define INV _T("INV")
#define MTV _T("MTV")
#define TTV _T("TTV")
#define TSTV _T("TSTV")
#define MP_TP _T("MP-TP")
#define MP_TSTP _T("MP-TSTP")


#define FIRST_MONTH _T("최근월물")


#define MARKET _T("market")
#define THEO _T("theo")