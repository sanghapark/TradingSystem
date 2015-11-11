///////////////////////////////////////////////////////////////////////////////////////////////////
// 시간대별프로그램매매추이(차트)(t1662) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1662     "t1662"

// 기본입력
typedef struct _t1662InBlock
{
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분                           StartPos 0, Length 1
    char    gubun1              [   1];    char    _gubun1              ;    // [string,    1] 금액수량구분                   StartPos 2, Length 1
    char    gubun3              [   1];    char    _gubun3              ;    // [string,    1] 전일구분                       StartPos 4, Length 1
} t1662InBlock, *LPt1662InBlock;
#define NAME_t1662InBlock     "t1662InBlock"

// 출력, occurs
typedef struct _t1662OutBlock
{
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 0, Length 6
    char    k200jisu            [   6];    char    _k200jisu            ;    // [float ,  6.2] KP200                          StartPos 7, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 대비구분                       StartPos 14, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 대비                           StartPos 16, Length 6
    char    k200basis           [   6];    char    _k200basis           ;    // [float ,  6.2] BASIS                          StartPos 23, Length 6
    char    tot3                [  12];    char    _tot3                ;    // [long  ,   12] 전체순매수                     StartPos 30, Length 12
    char    tot1                [  12];    char    _tot1                ;    // [long  ,   12] 전체매수                       StartPos 43, Length 12
    char    tot2                [  12];    char    _tot2                ;    // [long  ,   12] 전체매도                       StartPos 56, Length 12
    char    cha3                [  12];    char    _cha3                ;    // [long  ,   12] 차익순매수                     StartPos 69, Length 12
    char    cha1                [  12];    char    _cha1                ;    // [long  ,   12] 차익매수                       StartPos 82, Length 12
    char    cha2                [  12];    char    _cha2                ;    // [long  ,   12] 차익매도                       StartPos 95, Length 12
    char    bcha3               [  12];    char    _bcha3               ;    // [long  ,   12] 비차익순매수                   StartPos 108, Length 12
    char    bcha1               [  12];    char    _bcha1               ;    // [long  ,   12] 비차익매수                     StartPos 121, Length 12
    char    bcha2               [  12];    char    _bcha2               ;    // [long  ,   12] 비차익매도                     StartPos 134, Length 12
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 147, Length 12
} t1662OutBlock, *LPt1662OutBlock;
#define NAME_t1662OutBlock     "t1662OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
