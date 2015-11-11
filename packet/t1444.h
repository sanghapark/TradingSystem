///////////////////////////////////////////////////////////////////////////////////////////////////
// 시가총액상위(t1444) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1444     "t1444"

// 기본입력
typedef struct _t1444InBlock
{
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] 업종코드                       StartPos 0, Length 3
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 4, Length 4
} t1444InBlock, *LPt1444InBlock;
#define NAME_t1444InBlock     "t1444InBlock"

// 출력
typedef struct _t1444OutBlock
{
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 0, Length 4
} t1444OutBlock, *LPt1444OutBlock;
#define NAME_t1444OutBlock     "t1444OutBlock"

// 출력1, occurs
typedef struct _t1444OutBlock1
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                         StartPos 7, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 28, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 37, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 39, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 48, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 55, Length 12
    char    vol_rate            [   6];    char    _vol_rate            ;    // [float ,  6.2] 거래비중                       StartPos 68, Length 6
    char    total               [  12];    char    _total               ;    // [long  ,   12] 시가총액                       StartPos 75, Length 12
    char    rate                [   6];    char    _rate                ;    // [float ,  6.2] 비중                           StartPos 88, Length 6
    char    for_rate            [   6];    char    _for_rate            ;    // [float ,  6.2] 외인비중                       StartPos 95, Length 6
} t1444OutBlock1, *LPt1444OutBlock1;
#define NAME_t1444OutBlock1     "t1444OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
