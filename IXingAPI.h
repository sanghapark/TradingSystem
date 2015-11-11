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
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Receive Flag
#define		REQUEST_DATA			1
#define		MESSAGE_DATA			2
#define		SYSTEM_ERROR_DATA		3
#define		RELEASE_DATA			4
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
	inline	int		Request					( HWND hWnd, LPCTSTR pszCode, LPVOID lpData, int nDataSize, BOOL bNext=FALSE, LPCTSTR pszNextKey=TEXT(""), int nTimeOut=30 );
	inline	BOOL	ReleaseRequestData		( int nRequestID );
	inline	BOOL	ReleaseMessageData		( LPARAM lp );

	// 실시간TR 관련
	inline	BOOL	AdviseRealData			( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen );
	inline	BOOL	UnadviseRealData		( HWND hWnd, LPCTSTR pszTrNo, LPCTSTR pszData, int nDataUnitLen );
	inline	BOOL	UnadviseWindow			( HWND hWnd );

	// 계좌 관련
	inline	int		GetAccountListCount		();
	inline	BOOL	GetAccountList			( int nIndex, LPTSTR pszAcc, int nAccSize );

	// 정보얻기
	inline	CString	GetCommMedia			();			// 통신매체를 구한다.
	inline	CString	GetETKMedia				();			// 당사매체를 구한다.
	inline	CString	GetClientIP				();			// 공인IP를 구한다.
	inline	CString	GetServerName			();			// 서버명을 구한다.

	inline	void	SetHeaderInfo			( LPCTSTR szType, LPCTSTR szValue );

protected:
	inline	int		LoadLibHelper		( LPCTSTR szPath );

protected:
	HMODULE			m_hModule;

	typedef BOOL	( __stdcall *FP_CONNECT					) ( HWND, LPCTSTR, int, int, int, int );
	typedef BOOL	( __stdcall *FP_ISCONNECTED				) ( );
	typedef BOOL	( __stdcall *FP_DISCONNECT				) ( );
	typedef BOOL	( __stdcall *FP_LOGIN					) ( HWND, LPCTSTR, LPCTSTR, LPCTSTR, int, BOOL );
	typedef BOOL	( __stdcall *FP_LOGOUT					) ( HWND );
	typedef int		( __stdcall *FP_GETLASTERROR			) ( );
	typedef int		( __stdcall *FP_GETERRORMESSAGE			) ( int, LPTSTR, int );
	
	typedef int		( __stdcall *FP_REQUEST					) ( HWND, LPCTSTR, LPVOID, int, BOOL, LPCTSTR, int );
	typedef void	( __stdcall *FP_RELEASEREQUESTDATA		) ( int );
	typedef void	( __stdcall *FP_RELEASEMESSAGEDATA		) ( LPARAM );
	
	typedef BOOL	( __stdcall *FP_ADVISEREALDATA			) ( HWND, LPCTSTR, LPCTSTR, int );
	typedef BOOL	( __stdcall *FP_UNADVISEREALDATA		) ( HWND, LPCTSTR, LPCTSTR, int );
	typedef BOOL	( __stdcall *FP_UNADVISEWINDOW			) ( HWND );
	
	typedef int		( __stdcall *FP_GETACCOUNTLISTCOUNT		) ( );
	typedef BOOL	( __stdcall *FP_GETACCOUNTLIST			) ( int, LPTSTR, int );
	typedef void	( __stdcall *FP_GETCOMMMEDIA			) ( LPTSTR );
	typedef void	( __stdcall *FP_GETETKMEDIA				) ( LPTSTR );
	typedef void	( __stdcall *FP_GETCLIENTIP				) ( LPTSTR );
	typedef void	( __stdcall *FP_GETSERVERNAME			) ( LPTSTR );
	typedef void	( __stdcall *FP_SETHEADERINFO			) ( LPCTSTR, LPCTSTR );

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
};

BOOL IXingAPI::Init(LPCTSTR szPath)
{
	if( IsInit() ) return TRUE;

	return LoadLibHelper( szPath );
}

BOOL IXingAPI::LoadLibHelper( LPCTSTR szPath )
{
	TCHAR szCommLib[MAX_PATH] = { 0 };

	if( szPath == NULL || _tcslen( szPath ) == 0 )
	{
		lstrcpy( szCommLib, _T( "XingAPI.dll" ) );
	}
	else
	{
		_stprintf_s( szCommLib, _T( "%s\\XingAPI.dll" ), szPath );
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
	if( NULL == m_hModule  ) return TEXT("");
	if( NULL == m_fpGetErrorMessage ) m_fpGetErrorMessage = (FP_GETERRORMESSAGE)GetProcAddress(m_hModule, "ETK_GetErrorMessage");
	ASSERT( m_fpGetErrorMessage );
	if (NULL == m_fpGetErrorMessage) return TEXT("");

	TCHAR szData[1024] = { 0 };
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

BOOL IXingAPI::GetAccountList( int nIndex, LPTSTR pszAcc, int nAccSize )
{
	if( NULL == m_hModule )	return FALSE;
	
	if( NULL == m_fpGetAccountList )	
		m_fpGetAccountList = (FP_GETACCOUNTLIST)GetProcAddress(m_hModule, "ETK_GetAccountList");

	if( NULL == m_fpGetAccountList )	return FALSE;

	return m_fpGetAccountList( nIndex, pszAcc, nAccSize );
}

CString	IXingAPI::GetCommMedia()
{
	if (NULL == m_hModule)	return TEXT("");
	
	if( NULL == m_fpGetCommMedia )	
		m_fpGetCommMedia = (FP_GETCOMMMEDIA)GetProcAddress( m_hModule, "ETK_GetCommMedia" );

	if (NULL == m_fpGetCommMedia)	return TEXT("");

	TCHAR szMedia[256] = { 0 };
	m_fpGetCommMedia( szMedia );
	return szMedia;
}

CString	IXingAPI::GetETKMedia()
{
	if (NULL == m_hModule)	return TEXT("");
	
	if( NULL == m_fpGetETKMedia )	
		m_fpGetETKMedia = (FP_GETETKMEDIA)GetProcAddress( m_hModule, "ETK_GetETKMedia" );

	if (NULL == m_fpGetETKMedia)	return TEXT("");

	TCHAR szMedia[256] = { 0 };
	m_fpGetETKMedia( szMedia );
	return szMedia;
}

CString	IXingAPI::GetClientIP()
{
	if (NULL == m_hModule)	return TEXT("");
	
	if( NULL == m_fpGetClientIP )	
		m_fpGetClientIP = (FP_GETCLIENTIP)GetProcAddress( m_hModule, "ETK_GetClientIP" );

	if (NULL == m_fpGetClientIP)	return TEXT("");

	TCHAR szIP[256] = { 0 };
	m_fpGetClientIP( szIP );
	return szIP;
}

CString	IXingAPI::GetServerName()
{
	if (NULL == m_hModule)	return TEXT("");
	
	if( NULL == m_fpGetServerName )	
		m_fpGetServerName = (FP_GETSERVERNAME)GetProcAddress( m_hModule, "ETK_GetServerName" );

	if (NULL == m_fpGetServerName)	return TEXT("");

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

#endif // _IXINGAPI_H_
