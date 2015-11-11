///////////////////////////////////////////////////////////////////////////////////////////////////
// 테마종목별시세조회(t1537) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1537     "t1537"

// 기본입력
typedef struct _t1537InBlock
{
    char    tmcode              [   4];    char    _tmcode              ;    // [string,    4] 테마코드                       StartPos 0, Length 4
} t1537InBlock, *LPt1537InBlock;
#define NAME_t1537InBlock     "t1537InBlock"

// 출력
typedef struct _t1537OutBlock
{
    char    upcnt               [   4];    char    _upcnt               ;    // [long  ,    4] 상승종목수                     StartPos 0, Length 4
    char    tmcnt               [   4];    char    _tmcnt               ;    // [long  ,    4] 테마종목수                     StartPos 5, Length 4
    char    uprate              [   4];    char    _uprate              ;    // [long  ,    4] 상승종목비율                   StartPos 10, Length 4
    char    tmname              [  36];    char    _tmname              ;    // [string,   36] 테마명                         StartPos 15, Length 36
} t1537OutBlock, *LPt1537OutBlock;
#define NAME_t1537OutBlock     "t1537OutBlock"

// 출력1, occurs
typedef struct _t1537OutBlock1
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                         StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 48, Length 12
    char    jniltime            [   9];    char    _jniltime            ;    // [float ,  9.2] 전일동시간                     StartPos 61, Length 9
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 71, Length 6
    char    yeprice             [   8];    char    _yeprice             ;    // [long  ,    8] 예상체결가                     StartPos 78, Length 8
} t1537OutBlock1, *LPt1537OutBlock1;
#define NAME_t1537OutBlock1     "t1537OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
