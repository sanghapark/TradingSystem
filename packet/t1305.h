///////////////////////////////////////////////////////////////////////////////////////////////////
// 기간별주가(t1305) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1305     "t1305"

// 기본입력
typedef struct _t1305InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    dwmcode             [   1];    char    _dwmcode             ;    // [long  ,    1] 일주월구분                     StartPos 7, Length 1
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 9, Length 8
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 18, Length 4
    char    cnt                 [   4];    char    _cnt                 ;    // [long  ,    4] 건수                           StartPos 23, Length 4
} t1305InBlock, *LPt1305InBlock;
#define NAME_t1305InBlock     "t1305InBlock"

// 출력
typedef struct _t1305OutBlock
{
    char    cnt                 [   4];    char    _cnt                 ;    // [long  ,    4] CNT                            StartPos 0, Length 4
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 5, Length 8
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 14, Length 4
} t1305OutBlock, *LPt1305OutBlock;
#define NAME_t1305OutBlock     "t1305OutBlock"

// 출력1, occurs
typedef struct _t1305OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 9, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 18, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 27, Length 8
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                           StartPos 36, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 45, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 47, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 56, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 63, Length 12
    char    diff_vol            [  10];    char    _diff_vol            ;    // [float , 10.2] 거래증가율                     StartPos 76, Length 10
    char    chdegree            [   6];    char    _chdegree            ;    // [float ,  6.2] 체결강도                       StartPos 87, Length 6
    char    sojinrate           [   6];    char    _sojinrate           ;    // [float ,  6.2] 소진율                         StartPos 94, Length 6
    char    changerate          [   6];    char    _changerate          ;    // [float ,  6.2] 회전율                         StartPos 101, Length 6
    char    fpvolume            [  12];    char    _fpvolume            ;    // [long  ,   12] 외인순매수                     StartPos 108, Length 12
    char    covolume            [  12];    char    _covolume            ;    // [long  ,   12] 기관순매수                     StartPos 121, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 134, Length 6
    char    value               [  12];    char    _value               ;    // [long  ,   12] 누적거래대금                   StartPos 141, Length 12
    char    ppvolume            [  12];    char    _ppvolume            ;    // [long  ,   12] 개인순매수                     StartPos 154, Length 12
    char    o_sign              [   1];    char    _o_sign              ;    // [string,    1] 시가대비구분                   StartPos 167, Length 1
    char    o_change            [   8];    char    _o_change            ;    // [long  ,    8] 시가대비                       StartPos 169, Length 8
    char    o_diff              [   6];    char    _o_diff              ;    // [float ,  6.2] 시가기준등락율                 StartPos 178, Length 6
    char    h_sign              [   1];    char    _h_sign              ;    // [string,    1] 고가대비구분                   StartPos 185, Length 1
    char    h_change            [   8];    char    _h_change            ;    // [long  ,    8] 고가대비                       StartPos 187, Length 8
    char    h_diff              [   6];    char    _h_diff              ;    // [float ,  6.2] 고가기준등락율                 StartPos 196, Length 6
    char    l_sign              [   1];    char    _l_sign              ;    // [string,    1] 저가대비구분                   StartPos 203, Length 1
    char    l_change            [   8];    char    _l_change            ;    // [long  ,    8] 저가대비                       StartPos 205, Length 8
    char    l_diff              [   6];    char    _l_diff              ;    // [float ,  6.2] 저가기준등락율                 StartPos 214, Length 6
} t1305OutBlock1, *LPt1305OutBlock1;
#define NAME_t1305OutBlock1     "t1305OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
