///////////////////////////////////////////////////////////////////////////////////////////////////
// ETF구성종목조회(t1904) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1904     "t1904"

// 기본입력
typedef struct _t1904InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    cts_jcode           [  12];    char    _cts_jcode           ;    // [string,   12] 종목CTS                        StartPos 7, Length 12
} t1904InBlock, *LPt1904InBlock;
#define NAME_t1904InBlock     "t1904InBlock"

// 출력
typedef struct _t1904OutBlock
{
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 0, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 9, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 11, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 20, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 27, Length 12
    char    etftotcap           [  12];    char    _etftotcap           ;    // [long  ,   12] 순자산총액                     StartPos 40, Length 12
    char    etfnum              [   4];    char    _etfnum              ;    // [long  ,    4] 종목수                         StartPos 53, Length 4
    char    cash                [  12];    char    _cash                ;    // [long  ,   12] 현금                           StartPos 58, Length 12
    char    cts_jcode           [  12];    char    _cts_jcode           ;    // [string,   12] 종목CTS                        StartPos 71, Length 12
} t1904OutBlock, *LPt1904OutBlock;
#define NAME_t1904OutBlock     "t1904OutBlock"

// 출력1, occurs
typedef struct _t1904OutBlock1
{
    char    shcode              [  12];    char    _shcode              ;    // [string,   12] 단축코드                       StartPos 0, Length 12
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                         StartPos 13, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 34, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 43, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 45, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 54, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 61, Length 12
    char    icux                [   6];    char    _icux                ;    // [long  ,    6] 단위증권수                     StartPos 74, Length 6
    char    profitdate          [   8];    char    _profitdate          ;    // [string,    8] 이익분배기준일                 StartPos 81, Length 8
    char    parprice            [   8];    char    _parprice            ;    // [long  ,    8] 액면금액                       StartPos 90, Length 8
} t1904OutBlock1, *LPt1904OutBlock1;
#define NAME_t1904OutBlock1     "t1904OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
