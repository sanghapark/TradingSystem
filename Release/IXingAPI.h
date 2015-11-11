#ifndef _IXINGAPI_H_
#define _IXINGAPI_H_

//------------------------------------------------------------------------------
// 메시지 정의
// 메시지의 ID값은 Connect시에 설정한 nStartMsgID와 더하여 사용하면 된다.
#define 	XM_DISCONNECT			1		// 서버와의 연결이 끊어졌을 경우 발생
#define 	XM_RECEIVE_DATA			3		// RequestData로 요청한 데이터가 서버로부터 받았을 때 발생
#define 	XM_RECEIVE_REAL_DATA	4		// AdviseData로 요청한 데이터가 서버로부터 받았을 때 발생
#define 	XM_LOGIN				5		// 서버로부터 로그인 결과 받았을때 발생
#define 	XM_LOGOUT				6		// 서버로부터 로그아웃 결과 받았을때 발생
#define		XM_TIMEOUT_DATA			7		// RequestData로 요청한 데이터가 Timeout 이 발생했을때
#define 	XM_RECEIVE_LINK_DATA	8		// HTS 에서 연동 데이터가 발생했을 때 : by zzin 2013.11.11  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Receive Flag
#define		REQUEST_DATA			1
#define		MESSAGE_DATA			2
#define		SYSTEM_ERROR_DATA		3
#define		RELEASE_DATA			4
#define		LINK_DATA				10
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Structure 정의
#pragma pack( push, 1 )

// 조회TR 수신 Packet
typedef struct _RECV_PACKET
{
	_RECV_PACKET() { ZeroMemory( this, sizeof(_RECV_PACKET ) ); }

	int					nRqID;						// Request ID
	int					nDataLength;				// 받은 데이터 크기
	int					nTotalDataBufferSize;		// lpData에 할당된 크기
	int					nElapsedTime;				// 전송에서 수신까지 걸린시간(1/1000초)
	int					nDataMode;					// 1:BLOCK MODE, 2:NON-BLOCK MODE
	char				szTrCode	[10+1];			// AP Code
	char				cCont		[1];			// '0' : 다음조회 없음, '1' : 다음조회 있음
	char				szContKey	[18+1];			// 연속키, Data Header가 B 인 경우에만 사용
	char				szUserData	[30+1];			// 사용자 데이터
	char				szBlockName [17];			// Block 명, Block Mode 일때 사용
	unsigned char*		lpData;
} RECV_PACKET, *LPRECV_PACKET;

// 메시지 수신 Packet
typedef struct
{
	int					nRqID;						// Request ID
	int					nIsSystemError;				// 0:일반메시지, 1:System Error 메시지
	char				szMsgCode[5+1];				// 메시지 코드
	int					nMsgLength;					// Message 길이
	unsigned char*		lpszMessageData;			// Message Data
} MSG_PACKET, *LPMSG_PACKET;

// 실시간TR 수신 Packet
typedef struct _REAL_RECV_PACKET
{
	_REAL_RECV_PACKET() { ZeroMemory( this, sizeof( _REAL_RECV_PACKET ) ); }

	char				szTrCode [ 3 + 1];
	
	int					nKeyLength;
	char				szKeyData[32 + 1];
	char				szRegKey [32 + 1];

	int					nDataLength;
	char*				pszData;
} RECV_REAL_PACKET, *LPRECV_REAL_PACKET;


// HTS에서 API로 연동되어 수신되는 Packet
typedef struct _LINKDATA_RECV_MSG
{
	_LINKDATA_RECV_MSG() { ZeroMemory( this, sizeof( _LINKDATA_RECV_MSG ) );	}

	char				sLinkName[32];
	char				sLinkData[32];
	char				sFiller  [64];
}LINKDATA_RECV_MSG, *LPLINKDATA_RECV_MSG;
//------------------------------------------------------------------------------

class IXingAPI  
{
public:
	IXingAPI () { ZeroMemory( this, sizeof( IXingAPI ) ); }
	~IXingAPI() { Uninit(); }

	inline	HMODULE	GetSafeHandle			()											{ return m_hModule; }

public:
	// 초기화 관련
	inline	BOOL	Init					( LPCTSTR szPath=NULL );
	inline	BOOL	IsInit					()											{ return m_hModule != NULL; }
	inline	void	Uninit					();

	// 서버연결
	inline	BOOL	Connect					( HWND hWnd, LPCTSTR pszSvrIP, int nPort, int nStartMsgID, int nTimeOut=-1, int nSendMaxPacketSize=-1 );
	inline	BOOL	IsConnected				();
	inline	BOOL	Disconnect				();
	
	// 로그인
	inline	BOOL	Login					( HWND hWnd, LPCTSTR pszID, LPCTSTR pszPwd, LPCTSTR pszCertPwd, int nType, BOOL bShowCertErrDlg=TRUE );
	inline	BOOL	Logout					( HWND hWnd );

	inline	int		GetLastError			();
	inline	CString	GetErrorMessage			( int nErrorCode );
	
	// 조회성TR 관련
	inline	int		Request					( HWND hWnd, LPCTSTR pszCode, LPVOID lpData, int nDataSize, BOOL bNext=FALSE, LPCTSTR pszNextKey="", int nTimeOut=30 );
	inline	BOOL	ReleaseRequestData		( int nRequestID );
	inline	BOOL	ReleaseMessageData		( LPARAM lp );

	// 실시간TR 관련
	inline	BOOL	AdviseRealData			( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen );
	inline	BOOL	UnadviseRealData		( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen );
	inline	BOOL	UnadviseWindow			( HWND hWnd );

	// 계좌 관련
	inline	int		GetAccountListCount		();
	inline	BOOL	GetAccountList			( int nIndex, LPSTR pszAcc, int nAccSize );

	// 정보얻기
	inline	CString	GetCommMedia			();			// 통신매체를 구한다.
	inline	CString	GetETKMedia				();			// 당사매체를 구한다.
	inline	CString	GetClientIP				();			// 공인IP를 구한다.
	inline	CString	GetServerName			();			// 서버명을 구한다.

	inline	void	SetHeaderInfo			( LPCTSTR szType, LPCTSTR szValue );

	inline	CString	GetProcBranchNo			();			// 처리점을 구한다.
	inline	BOOL	GetUseOverFuture		();			// 해외선물 사용권한	
	inline	BOOL	GetUseFX				();			// FX 사용권한

	inline	void	SetNotifyFlag			( BOOL bNotifyFlag );	// 긴급메시지, 서버접속 단절통지 등의 통보 설정 (지원 예정)

	//------------------------------------------------------------------------------
	// 부가 서비스 TR 조회
	//     반환값       - Request() 함수와 동일
	//     hWnd			- 조회 결과를 받을 윈도우의 핸들
	//
	// [1] 종목 검색        
	//     pszCode		- "t1807" (HTS '[1807] 종목검색' 에서 'API 로 내보내기' 저장한 조건의 종목을 검색하는 TR)
    //     lpData		- 'API로 내보내기' 한 파일의 전체 경로 지정, NULL 입력시 파일다이얼로그 표시
	//
	//     ex)  HTS '[1807] 종목검색' 에서 'API 로 내보내기' 저장한 파일이 "D:\test.adf"
	//          pszCode = "t1833", pszData = "D:\test.adf"   

	inline	int		RequestService			( HWND hWnd, LPCTSTR pszCode, LPCTSTR pszData );	

	// 부가 서비스 조회 TR 삭제
	inline	int		RemoveService			( HWND hWnd, LPCTSTR pszCode, LPCTSTR pszData );

	//------------------------------------------------------------------------------
	// API 에서 HTS로 연동 (API -> HTS) : 연동을 원할때마다 요청한다
	//     반환값       - 연동 성공 여부
	//     hWnd			- 연동을 요청한 윈도우의 핸들
	//     
	// [1] 종목 연동
    //     pszLinkKey	- &STOCK_CODE				: 주식 종목코드
    //                    &ETF_CODE					: ETF 종목코드
    //                    &ELW_CODE					: ELW 종목코드
    //                    &KONEX_CODE				: 코넥스 종목코드
    //                    &FREEBOARD_CODE			: 프리보드 종목코드
    //                    &KSPI_CODE				: 코스피 업종 코드
    //                    &KSQI_CODE				: 코스닥 업종 코드
    //                    &FUTURE_CODE				: 선물종목코드
    //                    &OPTION_CODE				: 옵션종목코드
    //                    &FUTOPT_CODE				: 선물/옵션 종목코드 
    //                    &FUTSP_CODE				: 선물스프레드 종목코드
    //                    &STOCK_FUTURE_CODE		: 주식 선물 종목코드
    //                    &STOCK_OPTION_CODE		: 주식 옵션 종목코드
    //                    &STOCK_FUTOPT_CODE		: 주식 선물옵션 종목코드 
    //                    &STOCK_FUTSP_CODE			: 주식 선물스프레드 종목코드
    //                    &FUTOPT_STOCK_FUTOPT_CODE : 선물옵션 & 주식 선물옵션 종목코드
    //                    &US_CODE					: 해외종목코드
    //                    &COMMODITY_FUTOPT_CODE	: 상품선물/선물옵션
    //                    &COMMODITY_FUTURE_CODE	: 상품선물
    //                    &COMMODITY_STAR_CODE		: 스타선물
    //                    &CME_FUTURE_CODE			: CME야간선물
    //                    &EUREX_OPTION_CODE		: EUREX야간옵션
    //                    &NIGHT_FUTOPT_CODE		: 야간선물옵션
    //     pszData    	- 상품별 종목코드  
	//
	//     ex) 주식 종목 연동 : pszLinkKey = "&STOCK_CODE", pszData = "078020"
	//         선물 종목 연동 : pszLinkKey = "&FUTURE_CODE", pszData = "101HC000"
	//     
	// [2] HTS 화면 열기 
    //     pszLinkKey	- &OPEN_SCREEN : 화면 열기
	//     pszData    	- 열고 싶은 화면 번호
	//
	//     ex) HTS의 '[6602]선옵원장 미결제잔고' 열기
	//         pszLinkKey = &OPEN_SCREEN, pszData = "6602"	

	inline	int		RequestLinkToHTS        ( HWND hWnd, LPCTSTR pszLinkKey, LPCTSTR pszData, LPCTSTR pszFiller=NULL );

	//------------------------------------------------------------------------------
	// HTS 에서 API로 연동 (HTS -> API) : 등록하면 해제할때까지 연동된다
	//     hWnd			- 연동을 원하는 윈도우의 핸들
	// 
	// ※ HTS에서 연동 발생 시, XM_RECEIVE_LINK_DATA 로 메시지가 발생
	//	  WPARAM = LINK_DATA, 
	//	  LPARAM = LINKDATA_RECV_MSG 구조체 데이터 
	//    ★★★  사용방식은 Real 수신과 동일, LPARAM 메모리 수신 후 반드시 해제 필요

	inline	void	AdviseLinkFromHTS		( HWND hWnd );
	inline	void	UnAdviseLinkFromHTS		( HWND hWnd );

	//------------------------------------------------------------------------------
	// 데이터의 압축을 해제한다 : 틱챠트 데이터 등에서 압축상태로 수신받은 경우 사용
	//     반환값       - 압축을 해제한 데이터(pszDest)의 길이
	//
	//     pszSrc		- 압축상태 데이터
	//     pszDest		- 압축을 해제한 데이터를 저장할 메모리 (Outblock 구조체 사이즈 최대 2000건)
	//	   nSrcLen	    - pszSrc 데이터의 길이
	// 
	// 사용 방법 
	//     ex) t8411 TR 이용시, InBlock의 comp_yn(압축여부) 필드에 "Y" 입력 후 조회
	//          ReceiveData() 에서 Occurs 블럭(t8411OutBlock1)이 압축되어 수신되므로, 해당 블럭 압축을 해제
	// 
	//			LRESULT t8411_Wnd::OnXMReceiveData( WPARAM wParam, LPARAM lParam )
	//			{
	//				//-------------------------------------------------------------------------------------
	//				// Data를 받음
	//				if( wParam == REQUEST_DATA )
	//				{
	//					LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;
	//
	//					if( strcmp( pRpData->szBlockName, NAME_t8411OutBlock ) == 0 )
	//					{
	//					}
	//					else if( strcmp( pRpData->szBlockName, NAME_t8411OutBlock1 ) == 0 )
	//					{
	//						LPt8411OutBlock1 pOutBlock1 = (LPt8411OutBlock1)pRpData->lpData;
    //
	//						t8411OutBlock1 szOutBlock1[2000];		// 압축 해제시 최대 2000건 수신
	//						int nDestSize = g_iXingAPI.Decompress((char *)pOutBlock1, (char *)&szOutBlock1[0], pRpData->nDataLength);
    //
	//						// Occurs 일 경우
	//						// Header가 'A' 이면 전체길이에서 OutBlock의 길이를 나눠서 갯수를 구한다.
	//						if (nDestSize > 0)
	//						{
	//							int nCount = nDestSize / sizeof( t8411OutBlock1 );
	//
	//							for( int i=0; i<nCount; i++ )
	//							{
	//								데이터 표시 
	//							}
	//						}
	//					}
	//				}
	//			}
	// 
	inline	int		Decompress				( LPCTSTR pszSrc, LPCTSTR pszDest, int nSrcLen );

	//------------------------------------------------------------------------------

protected:
	inline	int		LoadLibHelper		( LPCTSTR szPath );

protected:
	HMODULE			m_hModule;

	typedef BOOL	( __stdcall *FP_CONNECT					) ( HWND, LPCTSTR, int, int, int, int );
	typedef BOOL	( __stdcall *FP_ISCONNECTED				) ( );
	typedef BOOL	( __stdcall *FP_DISCONNECT				) ( );
	typedef BOOL	( __stdcall *FP_LOGIN					) ( HWND, LPCSTR, LPCSTR, LPCSTR, int, BOOL );
	typedef BOOL	( __stdcall *FP_LOGOUT					) ( HWND );
	typedef int		( __stdcall *FP_GETLASTERROR			) ( );
	typedef int		( __stdcall *FP_GETERRORMESSAGE			) ( int, LPSTR, int );
	
	typedef int		( __stdcall *FP_REQUEST					) ( HWND, LPCTSTR, LPVOID, int, BOOL, LPCTSTR, int );
	typedef void	( __stdcall *FP_RELEASEREQUESTDATA		) ( int );
	typedef void	( __stdcall *FP_RELEASEMESSAGEDATA		) ( LPARAM );
	
	typedef BOOL	( __stdcall *FP_ADVISEREALDATA			) ( HWND, LPCTSTR, LPCTSTR, int );
	typedef BOOL	( __stdcall *FP_UNADVISEREALDATA		) ( HWND, LPCTSTR, LPCTSTR, int );
	typedef BOOL	( __stdcall *FP_UNADVISEWINDOW			) ( HWND );
	
	typedef int		( __stdcall *FP_GETACCOUNTLISTCOUNT		) ( );
	typedef BOOL	( __stdcall *FP_GETACCOUNTLIST			) ( int, LPSTR, int );
	typedef void	( __stdcall *FP_GETCOMMMEDIA			) ( LPTSTR );
	typedef void	( __stdcall *FP_GETETKMEDIA				) ( LPTSTR );
	typedef void	( __stdcall *FP_GETCLIENTIP				) ( LPTSTR );
	typedef void	( __stdcall *FP_GETSERVERNAME			) ( LPTSTR );
	typedef void	( __stdcall *FP_SETHEADERINFO			) ( LPCTSTR, LPCTSTR );

	typedef void	(__stdcall *FP_GETPROCBRANCHNO			) ( LPTSTR );
	typedef BOOL	(__stdcall *FP_GETUSEOVERFUTURE			) ( );
	typedef BOOL	(__stdcall *FP_GETUSEFX					) ( );

	typedef void	(__stdcall *FP_SETNOTIFYFLAG			) ( BOOL );

	typedef int		( __stdcall *FP_REQUESTSERVICE			) ( HWND, LPCTSTR, LPCTSTR );
	typedef int		( __stdcall *FP_REMOVESERVICE			) ( HWND, LPCTSTR, LPCTSTR );

	typedef int		( __stdcall *FP_REQUESTLINKTOHTS    	) ( HWND, LPCTSTR, LPCTSTR, LPCTSTR );
	typedef void	( __stdcall *FP_ADVISELINKFROMHTS    	) ( HWND );
	typedef void	( __stdcall *FP_UNADVISELINKFROMHTS    	) ( HWND );

	typedef int		( __stdcall *FP_DECOMPRESS				) ( LPCTSTR, LPCTSTR, int );

	FP_CONNECT					m_fpConnect;
	FP_ISCONNECTED				m_fpIsConnected;
	FP_DISCONNECT				m_fpDisconnect;
	FP_LOGIN					m_fpLogin;
	FP_LOGOUT					m_fpLogout;

	FP_GETLASTERROR				m_fpGetLastError;
	FP_GETERRORMESSAGE			m_fpGetErrorMessage;

	FP_REQUEST					m_fpRequest;
	FP_ADVISEREALDATA			m_fpAdviseRealData;
	FP_UNADVISEREALDATA			m_fpUnadviseRealData;
	FP_UNADVISEWINDOW			m_fpUnadviseWindow;
	FP_RELEASEREQUESTDATA		m_fpReleaseRequestData;
	FP_RELEASEMESSAGEDATA		m_fpReleaseMessageData;

	FP_GETACCOUNTLISTCOUNT		m_fpGetAccountListCount;
	FP_GETACCOUNTLIST			m_fpGetAccountList;
	FP_GETCOMMMEDIA				m_fpGetCommMedia;
	FP_GETETKMEDIA				m_fpGetETKMedia;
	FP_GETCLIENTIP				m_fpGetClientIP;
	FP_GETSERVERNAME			m_fpGetServerName;

	FP_SETHEADERINFO			m_fpSetHeaderInfo;

	FP_GETPROCBRANCHNO			m_fpGetProcBranchNo;
	FP_GETUSEOVERFUTURE			m_fpGetUseOverFuture;
	FP_GETUSEFX					m_fpGetUseFX;

	FP_SETNOTIFYFLAG			m_fpSetNotifyFlag;

	FP_REQUESTSERVICE			m_fpRequestService;
	FP_REMOVESERVICE			m_fpRemoveService;

	FP_REQUESTLINKTOHTS			m_fpRequestLinkToHTS;
	FP_ADVISELINKFROMHTS		m_fpAdviseLinkFromHTS;
	FP_UNADVISELINKFROMHTS		m_fpUnAdviseLinkFromHTS;

	FP_DECOMPRESS				m_fpDecompress;
};

BOOL IXingAPI::Init(LPCTSTR szPath)
{
	if( IsInit() ) return TRUE;

	return LoadLibHelper( szPath );
}

BOOL IXingAPI::LoadLibHelper( LPCTSTR szPath )
{
	TCHAR szCommLib[MAX_PATH] = { 0 };

	if( szPath == NULL || strlen( szPath ) == 0 )
	{
		lstrcpy( szCommLib, _T( "XingAPI.dll" ) );
	}
	else
	{
		_stprintf( szCommLib, _T( "%s\\XingAPI.dll" ), szPath );
	}

	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetCurrentDirectory( MAX_PATH, szCurrentDir );
	SetCurrentDirectory( szPath );
	m_hModule = ::LoadLibrary( szCommLib );
	SetCurrentDirectory( szCurrentDir );

	return NULL == m_hModule ? FALSE : TRUE;
}

void IXingAPI::Uninit()
{
	if( IsInit() ) ::FreeLibrary( m_hModule );
	m_hModule = NULL;
}

BOOL IXingAPI::Connect( HWND hWnd, LPCTSTR pszSvrIP, int nPort, int nStartMsgID, int nTimeOut, int nSendMaxPacketSize )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule   ) return FALSE;
	if( NULL == m_fpConnect ) m_fpConnect = (FP_CONNECT)GetProcAddress(m_hModule, "ETK_Connect");
	ASSERT( m_fpConnect );
	if( NULL == m_fpConnect ) return FALSE;
	return m_fpConnect( hWnd, pszSvrIP, nPort, nStartMsgID, nTimeOut, nSendMaxPacketSize );
}

BOOL IXingAPI::IsConnected()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return FALSE;
	if( NULL == m_fpIsConnected ) m_fpIsConnected = (FP_ISCONNECTED)GetProcAddress(m_hModule, "ETK_IsConnected");
	ASSERT( m_fpIsConnected );
	if( NULL == m_fpIsConnected ) return FALSE;
	return m_fpIsConnected();
}

BOOL IXingAPI::Disconnect()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return FALSE;
	if( NULL == m_fpDisconnect	) m_fpDisconnect = (FP_DISCONNECT)GetProcAddress(m_hModule, "ETK_Disconnect");
	ASSERT( m_fpDisconnect );
	if( NULL == m_fpDisconnect	) return FALSE;
	return m_fpDisconnect();
}

BOOL IXingAPI::Login( HWND hWnd, LPCTSTR pszID, LPCTSTR pszPwd, LPCTSTR pszCertPwd, int nType, BOOL bShowCertErrDlg )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule )	return FALSE;
	if( NULL == m_fpLogin )	m_fpLogin = (FP_LOGIN)GetProcAddress(m_hModule, "ETK_Login");
	ASSERT( m_fpLogin );
	if( NULL == m_fpLogin )	return FALSE;
	return m_fpLogin( hWnd, pszID, pszPwd, pszCertPwd, nType, bShowCertErrDlg );
}

BOOL IXingAPI::Logout( HWND hWnd )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule  ) return FALSE;
	if( NULL == m_fpLogout ) m_fpLogout = (FP_LOGOUT)GetProcAddress(m_hModule, "ETK_Logout");
	ASSERT( m_fpLogout );
	if( NULL == m_fpLogout ) return FALSE;
	return m_fpLogout( hWnd );
}

int	IXingAPI::GetLastError()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule  ) return FALSE;
	if( NULL == m_fpGetLastError ) m_fpGetLastError = (FP_GETLASTERROR)GetProcAddress(m_hModule, "ETK_GetLastError");
	ASSERT( m_fpGetLastError );
	if( NULL == m_fpGetLastError ) return FALSE;
	return m_fpGetLastError();
}

CString	IXingAPI::GetErrorMessage( int nErrorCode )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule  ) return "";
	if( NULL == m_fpGetErrorMessage ) m_fpGetErrorMessage = (FP_GETERRORMESSAGE)GetProcAddress(m_hModule, "ETK_GetErrorMessage");
	ASSERT( m_fpGetErrorMessage );
	if( NULL == m_fpGetErrorMessage ) return "";

	char szData[1024] = { 0 };
	m_fpGetErrorMessage( nErrorCode, szData, sizeof( szData ) );
	return szData;
}

int IXingAPI::Request( HWND hWnd, LPCTSTR pszCode, LPVOID lpData, int nDataSize, BOOL bNext, LPCTSTR pszNextKey, int nTimeOut )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpRequest )	
		m_fpRequest = (FP_REQUEST)GetProcAddress(m_hModule, "ETK_Request");
	
	if( NULL == m_fpRequest )	return -1;
	
	return m_fpRequest(hWnd, pszCode, lpData, nDataSize, bNext, pszNextKey, nTimeOut);
}

BOOL IXingAPI::AdviseRealData ( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpAdviseRealData )	
		m_fpAdviseRealData = (FP_ADVISEREALDATA)GetProcAddress(m_hModule, "ETK_AdviseRealData");

	if( NULL == m_fpAdviseRealData )	return FALSE;

	return m_fpAdviseRealData( hWnd, pszTrNo, pszData, nDataUnitLen );
}

BOOL IXingAPI::UnadviseRealData( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpUnadviseRealData )	
		m_fpUnadviseRealData = (FP_UNADVISEREALDATA)GetProcAddress(m_hModule, "ETK_UnadviseRealData");

	if( NULL == m_fpUnadviseRealData )	return FALSE;

	return m_fpUnadviseRealData( hWnd, pszTrNo, pszData, nDataUnitLen );
}

BOOL IXingAPI::UnadviseWindow( HWND hWnd )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpUnadviseWindow )	
		m_fpUnadviseWindow = (FP_UNADVISEWINDOW)GetProcAddress(m_hModule, "ETK_UnadviseWindow");

	if( NULL == m_fpUnadviseWindow )	return FALSE;

	return m_fpUnadviseWindow(hWnd);
}

BOOL IXingAPI::ReleaseRequestData( int nRequestID )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpReleaseRequestData )	
		m_fpReleaseRequestData = (FP_RELEASEREQUESTDATA)GetProcAddress(m_hModule, "ETK_ReleaseRequestData");

	if( NULL == m_fpReleaseRequestData )	return FALSE;

	m_fpReleaseRequestData(nRequestID);
	return TRUE;
}

BOOL IXingAPI::ReleaseMessageData(LPARAM lp)
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpReleaseMessageData )	
		m_fpReleaseMessageData = (FP_RELEASEMESSAGEDATA)GetProcAddress(m_hModule, "ETK_ReleaseMessageData");

	if( NULL == m_fpReleaseMessageData )	return FALSE;

	m_fpReleaseMessageData(lp);
	return TRUE;
}

int	IXingAPI::GetAccountListCount()
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpGetAccountListCount )	
		m_fpGetAccountListCount = (FP_GETACCOUNTLISTCOUNT)GetProcAddress(m_hModule, "ETK_GetAccountListCount");

	if( NULL == m_fpGetAccountListCount )	return 0;

	return m_fpGetAccountListCount();
}

BOOL IXingAPI::GetAccountList( int nIndex, LPSTR pszAcc, int nAccSize )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpGetAccountList )	
		m_fpGetAccountList = (FP_GETACCOUNTLIST)GetProcAddress(m_hModule, "ETK_GetAccountList");

	if( NULL == m_fpGetAccountList )	return FALSE;

	return m_fpGetAccountList( nIndex, pszAcc, nAccSize );
}

CString	IXingAPI::GetCommMedia()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetCommMedia )	
		m_fpGetCommMedia = (FP_GETCOMMMEDIA)GetProcAddress( m_hModule, "ETK_GetCommMedia" );

	if( NULL == m_fpGetCommMedia )	return "";

	TCHAR szMedia[256] = { 0 };
	m_fpGetCommMedia( szMedia );
	return szMedia;
}

CString	IXingAPI::GetETKMedia()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetETKMedia )	
		m_fpGetETKMedia = (FP_GETETKMEDIA)GetProcAddress( m_hModule, "ETK_GetETKMedia" );

	if( NULL == m_fpGetETKMedia )	return "";

	TCHAR szMedia[256] = { 0 };
	m_fpGetETKMedia( szMedia );
	return szMedia;
}

CString	IXingAPI::GetClientIP()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetClientIP )	
		m_fpGetClientIP = (FP_GETCLIENTIP)GetProcAddress( m_hModule, "ETK_GetClientIP" );

	if( NULL == m_fpGetClientIP )	return "";

	TCHAR szIP[256] = { 0 };
	m_fpGetClientIP( szIP );
	return szIP;
}

CString	IXingAPI::GetServerName()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetServerName )	
		m_fpGetServerName = (FP_GETSERVERNAME)GetProcAddress( m_hModule, "ETK_GetServerName" );

	if( NULL == m_fpGetServerName )	return "";

	TCHAR szName[256] = { 0 };
	m_fpGetServerName( szName );
	return szName;
}

void IXingAPI::SetHeaderInfo( LPCTSTR szType, LPCTSTR szValue )
{
	if( NULL == m_hModule )	return;
	
	if( NULL == m_fpSetHeaderInfo )	
		m_fpSetHeaderInfo = (FP_SETHEADERINFO)GetProcAddress( m_hModule, "ETK_SetHeaderInfo" );
	
	if( NULL == m_fpSetHeaderInfo )	return;
	
	m_fpSetHeaderInfo( szType, szValue );
}

CString	IXingAPI::GetProcBranchNo()
{
	if( NULL == m_hModule )	return "";
	
	if( NULL == m_fpGetProcBranchNo )	
		m_fpGetProcBranchNo = (FP_GETPROCBRANCHNO)GetProcAddress( m_hModule, "ETK_GetProcBranchNo" );

	if( NULL == m_fpGetProcBranchNo )	return "";

	TCHAR szProcBranchNo[256] = { 0 };
	m_fpGetProcBranchNo( szProcBranchNo );
	return szProcBranchNo;
}

BOOL IXingAPI::GetUseOverFuture()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return FALSE;
	if( NULL == m_fpGetUseOverFuture ) m_fpGetUseOverFuture = (FP_GETUSEOVERFUTURE)GetProcAddress( m_hModule, "ETK_GetUseOverFuture" );
	ASSERT( m_fpGetUseOverFuture );
	if( NULL == m_fpGetUseOverFuture ) return FALSE;
	return m_fpGetUseOverFuture();
}

BOOL IXingAPI::GetUseFX()
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return FALSE;
	if( NULL == m_fpGetUseFX ) m_fpGetUseFX = (FP_GETUSEFX)GetProcAddress( m_hModule, "ETK_GetUseFX" );
	ASSERT( m_fpGetUseFX );
	if( NULL == m_fpGetUseFX ) return FALSE;
	return m_fpGetUseFX();
}

void IXingAPI::SetNotifyFlag( BOOL bNotifyFlag )
{
	ASSERT( m_hModule );
	if( NULL == m_hModule		) return;

	if( NULL == m_fpSetNotifyFlag ) m_fpSetNotifyFlag = (FP_SETNOTIFYFLAG)GetProcAddress( m_hModule, "ETK_SetNotifyFlag" );
	ASSERT( m_fpSetNotifyFlag );
	if( NULL == m_fpSetNotifyFlag ) return;
	
	m_fpSetNotifyFlag( bNotifyFlag );
}

int IXingAPI::RequestService( HWND hWnd, LPCTSTR pszCode, LPCTSTR pszData )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpRequestService )	
		m_fpRequestService = (FP_REQUESTSERVICE)GetProcAddress( m_hModule, "ETK_RequestService" );
	
	if( NULL == m_fpRequestService )	return -1;
	
	return m_fpRequestService( hWnd, pszCode, pszData );
}

int IXingAPI::RemoveService( HWND hWnd, LPCTSTR pszCode, LPCTSTR pszData )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpRemoveService )	
		m_fpRemoveService = (FP_REMOVESERVICE)GetProcAddress( m_hModule, "ETK_RemoveService" );
	
	if( NULL == m_fpRemoveService )	return -1;
	
	return m_fpRemoveService( hWnd, pszCode, pszData );
}

int IXingAPI::RequestLinkToHTS( HWND hWnd, LPCTSTR pszLinkKey, LPCTSTR pszData, LPCTSTR pszFiller )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpRequestLinkToHTS )	
		m_fpRequestLinkToHTS = (FP_REQUESTLINKTOHTS)GetProcAddress( m_hModule, "ETK_RequestLinkToHTS" );
	
	if( NULL == m_fpRequestLinkToHTS )	return -1;
	
	return m_fpRequestLinkToHTS( hWnd, pszLinkKey, pszData, pszFiller );
}

void IXingAPI::AdviseLinkFromHTS( HWND hWnd )
{
	if( NULL == m_hModule )	return;
	
	if( NULL == m_fpAdviseLinkFromHTS )	
		m_fpAdviseLinkFromHTS = (FP_ADVISELINKFROMHTS)GetProcAddress( m_hModule, "ETK_AdviseLinkFromHTS" );
	
	if( NULL == m_fpAdviseLinkFromHTS )	return;
	
	m_fpAdviseLinkFromHTS( hWnd );
}

void IXingAPI::UnAdviseLinkFromHTS( HWND hWnd )
{
	if( NULL == m_hModule )	return;
	
	if( NULL == m_fpUnAdviseLinkFromHTS )	
		m_fpUnAdviseLinkFromHTS = (FP_UNADVISELINKFROMHTS)GetProcAddress( m_hModule, "ETK_UnAdviseLinkFromHTS" );
	
	if( NULL == m_fpUnAdviseLinkFromHTS )	return;
	
	m_fpUnAdviseLinkFromHTS( hWnd );
}


int IXingAPI::Decompress( LPCTSTR pszSrc, LPCTSTR pszDest, int nSrcLen )
{
	if( NULL == m_hModule )	return -1;
	
	if( NULL == m_fpDecompress )	
		m_fpDecompress = (FP_DECOMPRESS)GetProcAddress( m_hModule, "ETK_Decompress" );
	
	if( NULL == m_fpDecompress )	return -1;
	
	return m_fpDecompress( pszSrc, pszDest, nSrcLen );
}

#endif // _IXINGAPI_H_
