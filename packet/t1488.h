///////////////////////////////////////////////////////////////////////////////////////////////////
// 예상체결가등락율상위조회(t1488) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1488     "t1488"

// 기본입력
typedef struct _t1488InBlock
{
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 거래소구분                     StartPos 0, Length 1
    char    sign                [   1];    char    _sign                ;    // [string,    1] 상하락구분                     StartPos 2, Length 1
    char    jgubun              [   1];    char    _jgubun              ;    // [string,    1] 장구분                         StartPos 4, Length 1
    char    jongchk             [  12];    char    _jongchk             ;    // [string,   12] 종목체크                       StartPos 6, Length 12
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 19, Length 4
    char    volume              [   1];    char    _volume              ;    // [string,    1] 거래량                         StartPos 24, Length 1
    char    yesprice            [   8];    char    _yesprice            ;    // [long  ,    8] 예상체결시작가격               StartPos 26, Length 8
    char    yeeprice            [   8];    char    _yeeprice            ;    // [long  ,    8] 예상체결종료가격               StartPos 35, Length 8
    char    yevolume            [  12];    char    _yevolume            ;    // [long  ,   12] 예상체결량                     StartPos 44, Length 12
} t1488InBlock, *LPt1488InBlock;
#define NAME_t1488InBlock     "t1488InBlock"

// 출력
typedef struct _t1488OutBlock
{
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 0, Length 4
} t1488OutBlock, *LPt1488OutBlock;
#define NAME_t1488OutBlock     "t1488OutBlock"

// 출력1, occurs
typedef struct _t1488OutBlock1
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                         StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 48, Length 12
    char    offerrem            [   8];    char    _offerrem            ;    // [long  ,    8] 매도잔량                       StartPos 61, Length 8
    char    offerho             [   8];    char    _offerho             ;    // [long  ,    8] 매도호가                       StartPos 70, Length 8
    char    bidho               [   8];    char    _bidho               ;    // [long  ,    8] 매수호가                       StartPos 79, Length 8
    char    bidrem              [   8];    char    _bidrem              ;    // [long  ,    8] 매수잔량                       StartPos 88, Length 8
    char    cnt                 [   4];    char    _cnt                 ;    // [long  ,    4] 연속일수                       StartPos 97, Length 4
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 102, Length 6
    char    jkrate              [   3];    char    _jkrate              ;    // [string,    3] 증거금율                       StartPos 109, Length 3
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [long  ,   12] 전일거래량                     StartPos 113, Length 12
} t1488OutBlock1, *LPt1488OutBlock1;
#define NAME_t1488OutBlock1     "t1488OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
