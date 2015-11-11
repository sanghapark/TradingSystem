///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물/옵션 현재가(시세) 조회 ( ATTR,BLOCK,HEADTYPE=A )
#pragma pack( push, 1 )

#define NAME_t2101     "t2101"

// 기본입력                       
typedef struct _t2101InBlock
{
	char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                        StartPos 0, Length 8
} t2101InBlock, *LPt2101InBlock;
#define NAME_t2101InBlock     "t2101InBlock"

// 출력                           
typedef struct _t2101OutBlock
{
	char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                          StartPos 0, Length 20
	char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                          StartPos 21, Length 6
	char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                    StartPos 28, Length 1
	char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                        StartPos 30, Length 6
	char    jnilclose           [   6];    char    _jnilclose           ;    // [float ,  6.2] 전일종가                        StartPos 37, Length 6
	char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                          StartPos 44, Length 6
	char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                          StartPos 51, Length 12
	char    value               [  12];    char    _value               ;    // [long  ,   12] 거래대금                        StartPos 64, Length 12
	char    mgjv                [   8];    char    _mgjv                ;    // [long  ,    8] 미결제량                        StartPos 77, Length 8
	char    mgjvdiff            [   8];    char    _mgjvdiff            ;    // [long  ,    8] 미결제증감                      StartPos 86, Length 8
	char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                            StartPos 95, Length 6
	char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                            StartPos 102, Length 6
	char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                            StartPos 109, Length 6
	char    uplmtprice          [   6];    char    _uplmtprice          ;    // [float ,  6.2] 상한가                          StartPos 116, Length 6
	char    dnlmtprice          [   6];    char    _dnlmtprice          ;    // [float ,  6.2] 하한가                          StartPos 123, Length 6
	char    high52w             [   6];    char    _high52w             ;    // [float ,  6.2] 52최고가                        StartPos 130, Length 6
	char    low52w              [   6];    char    _low52w              ;    // [float ,  6.2] 52최저가                        StartPos 137, Length 6
	char    basis               [   6];    char    _basis               ;    // [float ,  6.2] 베이시스                        StartPos 144, Length 6
	char    recprice            [   6];    char    _recprice            ;    // [float ,  6.2] 기준가                          StartPos 151, Length 6
	char    theoryprice         [   6];    char    _theoryprice         ;    // [float ,  6.2] 이론가                          StartPos 158, Length 6
	char    glyl                [   6];    char    _glyl                ;    // [float ,  6.3] 괴리율                          StartPos 165, Length 6
	char    cbhprice            [   6];    char    _cbhprice            ;    // [float ,  6.2] CB상한가                        StartPos 172, Length 6
	char    cblprice            [   6];    char    _cblprice            ;    // [float ,  6.2] CB하한가                        StartPos 179, Length 6
	char    lastmonth           [   8];    char    _lastmonth           ;    // [string,    8] 만기일                          StartPos 186, Length 8
	char    jandatecnt          [   8];    char    _jandatecnt          ;    // [long  ,    8] 잔여일                          StartPos 195, Length 8
	char    pricejisu           [   6];    char    _pricejisu           ;    // [float ,  6.2] 종합지수                        StartPos 204, Length 6
	char    jisusign            [   1];    char    _jisusign            ;    // [string,    1] 종합지수전일대비구분            StartPos 211, Length 1
	char    jisuchange          [   6];    char    _jisuchange          ;    // [float ,  6.2] 종합지수전일대비                StartPos 213, Length 6
	char    jisudiff            [   6];    char    _jisudiff            ;    // [float ,  6.2] 종합지수등락율                  StartPos 220, Length 6
	char    kospijisu           [   6];    char    _kospijisu           ;    // [float ,  6.2] KOSPI200지수                    StartPos 227, Length 6
	char    kospisign           [   1];    char    _kospisign           ;    // [string,    1] KOSPI200전일대비구분            StartPos 234, Length 1
	char    kospichange         [   6];    char    _kospichange         ;    // [float ,  6.2] KOSPI200전일대비                StartPos 236, Length 6
	char    kospidiff           [   6];    char    _kospidiff           ;    // [float ,  6.2] KOSPI200등락율                  StartPos 243, Length 6
	char    listhprice          [   6];    char    _listhprice          ;    // [float ,  6.2] 상장최고가                      StartPos 250, Length 6
	char    listlprice          [   6];    char    _listlprice          ;    // [float ,  6.2] 상장최저가                      StartPos 257, Length 6
	char    delt                [   6];    char    _delt                ;    // [float ,  6.4] 델타                            StartPos 264, Length 6
	char    gama                [   6];    char    _gama                ;    // [float ,  6.4] 감마                            StartPos 271, Length 6
	char    ceta                [   6];    char    _ceta                ;    // [float ,  6.4] 세타                            StartPos 278, Length 6
	char    vega                [   6];    char    _vega                ;    // [float ,  6.4] 베가                            StartPos 285, Length 6
	char    rhox                [   6];    char    _rhox                ;    // [float ,  6.4] 로우                            StartPos 292, Length 6
	char    gmprice             [   6];    char    _gmprice             ;    // [float ,  6.2] 근월물현재가                    StartPos 299, Length 6
	char    gmsign              [   1];    char    _gmsign              ;    // [string,    1] 근월물전일대비구분              StartPos 306, Length 1
	char    gmchange            [   6];    char    _gmchange            ;    // [float ,  6.2] 근월물전일대비                  StartPos 308, Length 6
	char    gmdiff              [   6];    char    _gmdiff              ;    // [float ,  6.2] 근월물등락율                    StartPos 315, Length 6
	char    theorypriceg        [   6];    char    _theorypriceg        ;    // [float ,  6.2] 이론가                          StartPos 322, Length 6
	char    histimpv            [   6];    char    _histimpv            ;    // [float ,  6.2] 역사적변동성                    StartPos 329, Length 6
	char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재변동성                      StartPos 336, Length 6
	char    sbasis              [   6];    char    _sbasis              ;    // [float ,  6.2] 시장BASIS                       StartPos 343, Length 6
	char    ibasis              [   6];    char    _ibasis              ;    // [float ,  6.2] 이론BASIS                       StartPos 350, Length 6
	char    gmfutcode           [   8];    char    _gmfutcode           ;    // [string,    8] 근월물종목코드                  StartPos 357, Length 8
	char    actprice            [   6];    char    _actprice            ;    // [float ,  6.2] 행사가                          StartPos 366, Length 6
	char    greeks_time         [   6];    char    _greeks_time         ;    // [string,    6] 거래소민감도수신시간            StartPos 373, Length 6
	char    greeks_confirm      [   8];    char    _greeks_confirm      ;    // [string,    8] 거래소민감도확정여부            StartPos 380, Length 8
	char    danhochk            [   1];    char    _danhochk            ;    // [string,    1] 단일가호가여부                  StartPos 389, Length 1
	char    yeprice             [   6];    char    _yeprice             ;    // [float ,  6.2] 예상체결가                      StartPos 391, Length 6
	char    jnilysign           [   1];    char    _jnilysign           ;    // [string,    1] 예상체결가전일종가대비구분      StartPos 398, Length 1
	char    jnilychange         [   6];    char    _jnilychange         ;    // [float ,  6.2] 예상체결가전일종가대비          StartPos 400, Length 6
	char    jnilydrate          [   6];    char    _jnilydrate          ;    // [float ,  6.2] 예상체결가전일종가등락율        StartPos 407, Length 6
	char    alloc_gubun         [   1];    char    _alloc_gubun         ;    // [string,    1] 배분구분(1:배분개시2:배분해제0: StartPos 414, Length 1
	char    bjandatecnt         [   8];    char    _bjandatecnt         ;    // [long  ,    8] 잔여일(영업일)                  StartPos 416, Length 8
	char    focode              [   8];    char    _focode              ;    // [string,    8] 종목코드                        StartPos 425, Length 8
	char    dy_gubun            [   1];    char    _dy_gubun            ;    // [string,    1] 실시간가격제한여부(0:대상아님1: StartPos 434, Length 1
	char    dy_uplmtprice       [   6];    char    _dy_uplmtprice       ;    // [float ,  6.2] 실시간상한가                    StartPos 436, Length 6
	char    dy_dnlmtprice       [   6];    char    _dy_dnlmtprice       ;    // [float ,  6.2] 실시간하한가                    StartPos 443, Length 6
} t2101OutBlock, *LPt2101OutBlock;
#define NAME_t2101OutBlock     "t2101OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
