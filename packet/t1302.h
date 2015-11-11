///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식분별주가조회(t1302) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1302     "t1302"

// 기본입력
typedef struct _t1302InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 작업구분                       StartPos 7, Length 1
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 9, Length 6
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 건수                           StartPos 16, Length 3
} t1302InBlock, *LPt1302InBlock;
#define NAME_t1302InBlock     "t1302InBlock"

// 출력
typedef struct _t1302OutBlock
{
    char    cts_time            [   6];    char    _cts_time            ;    // [string,    6] 시간CTS                        StartPos 0, Length 6
} t1302OutBlock, *LPt1302OutBlock;
#define NAME_t1302OutBlock     "t1302OutBlock"

// 출력1, occurs
typedef struct _t1302OutBlock1
{
    char    chetime             [   6];    char    _chetime             ;    // [string,    6] 시간                           StartPos 0, Length 6
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                           StartPos 7, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 16, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 18, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 27, Length 6
    char    chdegree            [   8];    char    _chdegree            ;    // [float ,  8.2] 체결강도                       StartPos 34, Length 8
    char    mdvolume            [  12];    char    _mdvolume            ;    // [long  ,   12] 매도체결수량                   StartPos 43, Length 12
    char    msvolume            [  12];    char    _msvolume            ;    // [long  ,   12] 매수체결수량                   StartPos 56, Length 12
    char    revolume            [  12];    char    _revolume            ;    // [long  ,   12] 순매수체결량                   StartPos 69, Length 12
    char    mdchecnt            [   8];    char    _mdchecnt            ;    // [long  ,    8] 매도체결건수                   StartPos 82, Length 8
    char    mschecnt            [   8];    char    _mschecnt            ;    // [long  ,    8] 매수체결건수                   StartPos 91, Length 8
    char    rechecnt            [   8];    char    _rechecnt            ;    // [long  ,    8] 순체결건수                     StartPos 100, Length 8
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 109, Length 12
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 122, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 131, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 140, Length 8
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 체결량                         StartPos 149, Length 12
    char    mdchecnttm          [   8];    char    _mdchecnttm          ;    // [long  ,    8] 매도체결건수(시간)             StartPos 162, Length 8
    char    mschecnttm          [   8];    char    _mschecnttm          ;    // [long  ,    8] 매수체결건수(시간)             StartPos 171, Length 8
    char    totofferrem         [  12];    char    _totofferrem         ;    // [long  ,   12] 매도잔량                       StartPos 180, Length 12
    char    totbidrem           [  12];    char    _totbidrem           ;    // [long  ,   12] 매수잔량                       StartPos 193, Length 12
    char    mdvolumetm          [  12];    char    _mdvolumetm          ;    // [long  ,   12] 시간별매도체결량               StartPos 206, Length 12
    char    msvolumetm          [  12];    char    _msvolumetm          ;    // [long  ,   12] 시간별매수체결량               StartPos 219, Length 12
} t1302OutBlock1, *LPt1302OutBlock1;
#define NAME_t1302OutBlock1     "t1302OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
