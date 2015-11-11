///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식챠트(종합)(t4201) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t4201     "t4201"

// 기본입력
typedef struct _t4201InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 주기구분(0:틱1:분2:일3:주4:월) StartPos 7, Length 1
    char    ncnt                [   4];    char    _ncnt                ;    // [long  ,    4] 틱개수                         StartPos 9, Length 4
    char    qrycnt              [   4];    char    _qrycnt              ;    // [long  ,    4] 건수(500건이하)                StartPos 14, Length 4
    char    tdgb                [   1];    char    _tdgb                ;    // [string,    1] 당일구분(0:전체1:당일만)       StartPos 19, Length 1
    char    sdate               [   8];    char    _sdate               ;    // [string,    8] 시작일자                       StartPos 21, Length 8
    char    edate               [   8];    char    _edate               ;    // [string,    8] 종료일자                       StartPos 30, Length 8
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] 연속일자                       StartPos 39, Length 8
    char    cts_time            [  10];    char    _cts_time            ;    // [string,   10] 연속시간                       StartPos 48, Length 10
    char    cts_daygb           [   1];    char    _cts_daygb           ;    // [string,    1] 연속당일구분(0:연속전체1:연속당 StartPos 59, Length 1
} t4201InBlock, *LPt4201InBlock;
#define NAME_t4201InBlock     "t4201InBlock"

// 출력
typedef struct _t4201OutBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    jisiga              [   8];    char    _jisiga              ;    // [long  ,    8] 전일시가                       StartPos 7, Length 8
    char    jihigh              [   8];    char    _jihigh              ;    // [long  ,    8] 전일고가                       StartPos 16, Length 8
    char    jilow               [   8];    char    _jilow               ;    // [long  ,    8] 전일저가                       StartPos 25, Length 8
    char    jiclose             [   8];    char    _jiclose             ;    // [long  ,    8] 전일종가                       StartPos 34, Length 8
    char    jivolume            [  12];    char    _jivolume            ;    // [long  ,   12] 전일거래량                     StartPos 43, Length 12
    char    disiga              [   8];    char    _disiga              ;    // [long  ,    8] 당일시가                       StartPos 56, Length 8
    char    dihigh              [   8];    char    _dihigh              ;    // [long  ,    8] 당일고가                       StartPos 65, Length 8
    char    dilow               [   8];    char    _dilow               ;    // [long  ,    8] 당일저가                       StartPos 74, Length 8
    char    diclose             [   8];    char    _diclose             ;    // [long  ,    8] 당일종가                       StartPos 83, Length 8
    char    highend             [   8];    char    _highend             ;    // [long  ,    8] 상한가                         StartPos 92, Length 8
    char    lowend              [   8];    char    _lowend              ;    // [long  ,    8] 하한가                         StartPos 101, Length 8
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] 연속일자                       StartPos 110, Length 8
    char    cts_time            [  10];    char    _cts_time            ;    // [string,   10] 연속시간                       StartPos 119, Length 10
    char    cts_daygb           [   1];    char    _cts_daygb           ;    // [string,    1] 연속당일구분                   StartPos 130, Length 1
} t4201OutBlock, *LPt4201OutBlock;
#define NAME_t4201OutBlock     "t4201OutBlock"

// 출력1, occurs
typedef struct _t4201OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    time                [  10];    char    _time                ;    // [string,   10] 시간                           StartPos 9, Length 10
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 20, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 29, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 38, Length 8
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                           StartPos 47, Length 8
    char    jdiff_vol           [  12];    char    _jdiff_vol           ;    // [long  ,   12] 거래량                         StartPos 56, Length 12
    char    value               [  12];    char    _value               ;    // [long  ,   12] 거래대금                       StartPos 69, Length 12
    char    jongchk             [  13];    char    _jongchk             ;    // [long  ,   13] 수정구분                       StartPos 82, Length 13
    char    rate                [   6];    char    _rate                ;    // [double,  6.2] 수정비율                       StartPos 96, Length 6
    char    pricechk            [  13];    char    _pricechk            ;    // [long  ,   13] 수정주가반영항목               StartPos 103, Length 13
    char    ratevalue           [  12];    char    _ratevalue           ;    // [long  ,   12] 수정비율반영거래대금           StartPos 117, Length 12
} t4201OutBlock1, *LPt4201OutBlock1;
#define NAME_t4201OutBlock1     "t4201OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
