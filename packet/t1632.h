///////////////////////////////////////////////////////////////////////////////////////////////////
// 시간대별프로그램매매추이(t1632) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1632     "t1632"

// 기본입력
typedef struct _t1632InBlock
{
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분                           StartPos 0, Length 1
    char    gubun1              [   1];    char    _gubun1              ;    // [string,    1] 금액수량구분                   StartPos 2, Length 1
    char    gubun2              [   1];    char    _gubun2              ;    // [string,    1] 직전대비증감                   StartPos 4, Length 1
    char    gubun3              [   1];    char    _gubun3              ;    // [string,    1] 전일구분                       StartPos 6, Length 1
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                           StartPos 8, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 17, Length 6
} t1632InBlock, *LPt1632InBlock;
#define NAME_t1632InBlock     "t1632InBlock"

// 출력
typedef struct _t1632OutBlock
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜CTS                        StartPos 0, Length 8
    char    time                [   6];    char    _time                ;    // [string,    6] 시간CTS                        StartPos 9, Length 6
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 16, Length 4
} t1632OutBlock, *LPt1632OutBlock;
#define NAME_t1632OutBlock     "t1632OutBlock"

// 출력1, occurs
typedef struct _t1632OutBlock1
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
} t1632OutBlock1, *LPt1632OutBlock1;
#define NAME_t1632OutBlock1     "t1632OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
