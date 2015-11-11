///////////////////////////////////////////////////////////////////////////////////////////////////
// ETF시간별추이(t1902) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1902     "t1902"

// 기본입력
typedef struct _t1902InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 7, Length 6
} t1902InBlock, *LPt1902InBlock;
#define NAME_t1902InBlock     "t1902InBlock"

// 출력
typedef struct _t1902OutBlock
{
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 0, Length 6
    char    hname               [  20];    char    _hname               ;    // [string,   20] 종목명                         StartPos 7, Length 20
    char    upname              [  20];    char    _upname              ;    // [string,   20] 업종지수명                     StartPos 28, Length 20
} t1902OutBlock, *LPt1902OutBlock;
#define NAME_t1902OutBlock     "t1902OutBlock"

// 출력1, occurs
typedef struct _t1902OutBlock1
{
    char    time                [   8];    char    _time                ;    // [string,    8] 시간                           StartPos 0, Length 8
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 9, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 18, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 20, Length 8
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 누적거래량                     StartPos 29, Length 12
    char    navdiff             [   9];    char    _navdiff             ;    // [float ,  9.2] NAV대비                        StartPos 42, Length 9
    char    nav                 [   9];    char    _nav                 ;    // [float ,  9.2] NAV                            StartPos 52, Length 9
    char    navchange           [   9];    char    _navchange           ;    // [float ,  9.2] 전일대비                       StartPos 62, Length 9
    char    crate               [   9];    char    _crate               ;    // [float ,  9.2] 추적오차                       StartPos 72, Length 9
    char    grate               [   9];    char    _grate               ;    // [float ,  9.2] 괴리                           StartPos 82, Length 9
    char    jisu                [   8];    char    _jisu                ;    // [float ,  8.2] 지수                           StartPos 92, Length 8
    char    jichange            [   8];    char    _jichange            ;    // [float ,  8.2] 전일대비                       StartPos 101, Length 8
    char    jirate              [   8];    char    _jirate              ;    // [float ,  8.2] 전일대비율                     StartPos 110, Length 8
} t1902OutBlock1, *LPt1902OutBlock1;
#define NAME_t1902OutBlock1     "t1902OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
