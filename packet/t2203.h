///////////////////////////////////////////////////////////////////////////////////////////////////
// 기간별주가(t2203) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2203     "t2203"

// 기본입력
typedef struct _t2203InBlock
{
    char    shcode              [   8];    char    _shcode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
    char    futcheck            [   1];    char    _futcheck            ;    // [string,    1] 선물최근월물                   StartPos 9, Length 1
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 11, Length 8
    char    cts_code            [   8];    char    _cts_code            ;    // [string,    8] CTS종목코드                    StartPos 20, Length 8
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 전종목만기일                   StartPos 29, Length 8
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 조회요청건수                   StartPos 38, Length 3
} t2203InBlock, *LPt2203InBlock;
#define NAME_t2203InBlock     "t2203InBlock"

// 출력
typedef struct _t2203OutBlock
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    cts_code            [   8];    char    _cts_code            ;    // [string,    8] CTS종목코드                    StartPos 9, Length 8
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 전종목만기일                   StartPos 18, Length 8
    char    nowfutyn            [   1];    char    _nowfutyn            ;    // [string,    1] 최근월선물여부                 StartPos 27, Length 1
} t2203OutBlock, *LPt2203OutBlock;
#define NAME_t2203OutBlock     "t2203OutBlock"

// 출력1, occurs
typedef struct _t2203OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                           StartPos 9, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                           StartPos 16, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                           StartPos 23, Length 6
    char    close               [   6];    char    _close               ;    // [float ,  6.2] 종가                           StartPos 30, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 37, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                       StartPos 39, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 46, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 53, Length 12
    char    diff_vol            [  10];    char    _diff_vol            ;    // [float , 10.2] 거래증가율                     StartPos 66, Length 10
    char    openyak             [   8];    char    _openyak             ;    // [long  ,    8] 미결수량                       StartPos 77, Length 8
    char    openyakupdn         [   8];    char    _openyakupdn         ;    // [long  ,    8] 미결증감                       StartPos 86, Length 8
    char    value               [  12];    char    _value               ;    // [float ,   12] 거래대금                       StartPos 95, Length 12
} t2203OutBlock1, *LPt2203OutBlock1;
#define NAME_t2203OutBlock1     "t2203OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
