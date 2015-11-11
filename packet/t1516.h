///////////////////////////////////////////////////////////////////////////////////////////////////
// 업종별종목시세(t1516) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1516     "t1516"

// 기본입력
typedef struct _t1516InBlock
{
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] 업종코드                       StartPos 0, Length 3
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분                           StartPos 4, Length 1
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 6, Length 6
} t1516InBlock, *LPt1516InBlock;
#define NAME_t1516InBlock     "t1516InBlock"

// 출력
typedef struct _t1516OutBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    pricejisu           [  12];    char    _pricejisu           ;    // [float , 12.2] 지수                           StartPos 7, Length 12
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 20, Length 1
    char    change              [   7];    char    _change              ;    // [float ,  7.2] 전일대비                       StartPos 22, Length 7
    char    jdiff               [   6];    char    _jdiff               ;    // [float ,  6.2] 등락율                         StartPos 30, Length 6
} t1516OutBlock, *LPt1516OutBlock;
#define NAME_t1516OutBlock     "t1516OutBlock"

// 출력1, occurs
typedef struct _t1516OutBlock1
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                         StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 48, Length 12
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 61, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 70, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 79, Length 8
    char    sojinrate           [   6];    char    _sojinrate           ;    // [float ,  6.2] 소진율                         StartPos 88, Length 6
    char    beta                [   6];    char    _beta                ;    // [float ,  6.5] 베타계수                       StartPos 95, Length 6
    char    perx                [   8];    char    _perx                ;    // [float ,  8.2] PER                            StartPos 102, Length 8
    char    frgsvolume          [  12];    char    _frgsvolume          ;    // [long  ,   12] 외인순매수                     StartPos 111, Length 12
    char    orgsvolume          [  12];    char    _orgsvolume          ;    // [long  ,   12] 기관순매수                     StartPos 124, Length 12
    char    diff_vol            [  10];    char    _diff_vol            ;    // [float , 10.2] 거래증가율                     StartPos 137, Length 10
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 148, Length 6
    char    total               [  12];    char    _total               ;    // [long  ,   12] 시가총액                       StartPos 155, Length 12
    char    value               [  12];    char    _value               ;    // [long  ,   12] 거래대금                       StartPos 168, Length 12
} t1516OutBlock1, *LPt1516OutBlock1;
#define NAME_t1516OutBlock1     "t1516OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
