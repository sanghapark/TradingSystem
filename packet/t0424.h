///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식잔고2(t0424) ( attr,tuxcode=t0424,headtype=D )
#pragma pack( push, 1 )

#define NAME_t0424     "t0424"

// 기본입력
typedef struct _t0424InBlock
{
    char    accno               [  11];    char    _accno               ;    // [string,   11] 계좌번호                       StartPos 0, Length 11
    char    passwd              [   8];    char    _passwd              ;    // [string,    8] 비밀번호                       StartPos 12, Length 8
    char    prcgb               [   1];    char    _prcgb               ;    // [string,    1] 단가구분                       StartPos 21, Length 1
    char    chegb               [   1];    char    _chegb               ;    // [string,    1] 체결구분                       StartPos 23, Length 1
    char    dangb               [   1];    char    _dangb               ;    // [string,    1] 단일가구분                     StartPos 25, Length 1
    char    charge              [   1];    char    _charge              ;    // [string,    1] 제비용포함여부                 StartPos 27, Length 1
    char    cts_expcode         [  22];    char    _cts_expcode         ;    // [string,   22] CTS_종목번호                   StartPos 29, Length 22
} t0424InBlock, *LPt0424InBlock;
#define NAME_t0424InBlock     "t0424InBlock"

// 출력
typedef struct _t0424OutBlock
{
    char    sunamt              [  18];    char    _sunamt              ;    // [long  ,   18] 추정순자산                     StartPos 0, Length 18
    char    dtsunik             [  18];    char    _dtsunik             ;    // [long  ,   18] 실현손익                       StartPos 19, Length 18
    char    mamt                [  18];    char    _mamt                ;    // [long  ,   18] 매입금액                       StartPos 38, Length 18
    char    sunamt1             [  18];    char    _sunamt1             ;    // [long  ,   18] 추정D2예수금                   StartPos 57, Length 18
    char    cts_expcode         [  22];    char    _cts_expcode         ;    // [string,   22] CTS_종목번호                   StartPos 76, Length 22
    char    tappamt             [  18];    char    _tappamt             ;    // [long  ,   18] 평가금액                       StartPos 99, Length 18
    char    tdtsunik            [  18];    char    _tdtsunik            ;    // [long  ,   18] 평가손익                       StartPos 118, Length 18
} t0424OutBlock, *LPt0424OutBlock;
#define NAME_t0424OutBlock     "t0424OutBlock"

// 출력1, occurs
typedef struct _t0424OutBlock1
{
    char    expcode             [  12];    char    _expcode             ;    // [string,   12] 종목번호                       StartPos 0, Length 12
    char    jangb               [  10];    char    _jangb               ;    // [string,   10] 잔고구분                       StartPos 13, Length 10
    char    janqty              [  18];    char    _janqty              ;    // [long  ,   18] 잔고수량                       StartPos 24, Length 18
    char    mdposqt             [  18];    char    _mdposqt             ;    // [long  ,   18] 매도가능수량                   StartPos 43, Length 18
    char    pamt                [  18];    char    _pamt                ;    // [long  ,   18] 평균단가                       StartPos 62, Length 18
    char    mamt                [  18];    char    _mamt                ;    // [long  ,   18] 매입금액                       StartPos 81, Length 18
    char    sinamt              [  18];    char    _sinamt              ;    // [long  ,   18] 대출금액                       StartPos 100, Length 18
    char    lastdt              [   8];    char    _lastdt              ;    // [string,    8] 만기일자                       StartPos 119, Length 8
    char    msat                [  18];    char    _msat                ;    // [long  ,   18] 당일매수금액                   StartPos 128, Length 18
    char    mpms                [  18];    char    _mpms                ;    // [long  ,   18] 당일매수단가                   StartPos 147, Length 18
    char    mdat                [  18];    char    _mdat                ;    // [long  ,   18] 당일매도금액                   StartPos 166, Length 18
    char    mpmd                [  18];    char    _mpmd                ;    // [long  ,   18] 당일매도단가                   StartPos 185, Length 18
    char    jsat                [  18];    char    _jsat                ;    // [long  ,   18] 전일매수금액                   StartPos 204, Length 18
    char    jpms                [  18];    char    _jpms                ;    // [long  ,   18] 전일매수단가                   StartPos 223, Length 18
    char    jdat                [  18];    char    _jdat                ;    // [long  ,   18] 전일매도금액                   StartPos 242, Length 18
    char    jpmd                [  18];    char    _jpmd                ;    // [long  ,   18] 전일매도단가                   StartPos 261, Length 18
    char    sysprocseq          [  10];    char    _sysprocseq          ;    // [long  ,   10] 처리순번                       StartPos 280, Length 10
    char    loandt              [   8];    char    _loandt              ;    // [string,    8] 대출일자                       StartPos 291, Length 8
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                         StartPos 300, Length 20
    char    marketgb            [   1];    char    _marketgb            ;    // [string,    1] 시장구분                       StartPos 321, Length 1
    char    jonggb              [   1];    char    _jonggb              ;    // [string,    1] 종목구분                       StartPos 323, Length 1
    char    janrt               [  10];    char    _janrt               ;    // [float , 10.2] 보유비중                       StartPos 325, Length 10
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 336, Length 8
    char    appamt              [  18];    char    _appamt              ;    // [long  ,   18] 평가금액                       StartPos 345, Length 18
    char    dtsunik             [  18];    char    _dtsunik             ;    // [long  ,   18] 평가손익                       StartPos 364, Length 18
    char    sunikrt             [  10];    char    _sunikrt             ;    // [float , 10.2] 수익율                         StartPos 383, Length 10
    char    fee                 [  10];    char    _fee                 ;    // [long  ,   10] 수수료                         StartPos 394, Length 10
    char    tax                 [  10];    char    _tax                 ;    // [long  ,   10] 제세금                         StartPos 405, Length 10
    char    sininter            [  10];    char    _sininter            ;    // [long  ,   10] 신용이자                       StartPos 416, Length 10
} t0424OutBlock1, *LPt0424OutBlock1;
#define NAME_t0424OutBlock1     "t0424OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
