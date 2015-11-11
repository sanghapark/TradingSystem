///////////////////////////////////////////////////////////////////////////////////////////////////
// KOSDAQ예상체결(YK3) ( attr,block )
#pragma pack( push, 1 )

#define NAME_YK3     "YK3"

// 입력
typedef struct _YK3_InBlock
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
} YK3_InBlock, *LPYK3_InBlock;
#define NAME_YK3_InBlock     "InBlock"

// 출력
typedef struct _YK3_OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 0, Length 6
    char    yeprice             [   8];    char    _yeprice             ;    // [long  ,    8] 예상체결가격                   StartPos 7, Length 8
    char    yevolume            [  12];    char    _yevolume            ;    // [long  ,   12] 예상체결수량                   StartPos 16, Length 12
    char    jnilysign           [   1];    char    _jnilysign           ;    // [string,    1] 예상체결가전일종가대비구분     StartPos 29, Length 1
    char    preychange          [   8];    char    _preychange          ;    // [long  ,    8] 예상체결가전일종가대비         StartPos 31, Length 8
    char    jnilydrate          [   6];    char    _jnilydrate          ;    // [float ,  6.2] 예상체결가전일종가등락율       StartPos 40, Length 6
    char    yofferho0           [   8];    char    _yofferho0           ;    // [long  ,    8] 예상매도호가                   StartPos 47, Length 8
    char    ybidho0             [   8];    char    _ybidho0             ;    // [long  ,    8] 예상매수호가                   StartPos 56, Length 8
    char    yofferrem0          [  12];    char    _yofferrem0          ;    // [long  ,   12] 예상매도호가수량               StartPos 65, Length 12
    char    ybidrem0            [  12];    char    _ybidrem0            ;    // [long  ,   12] 예상매수호가수량               StartPos 78, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 91, Length 6
} YK3_OutBlock, *LPYK3_OutBlock;
#define NAME_YK3_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
