///////////////////////////////////////////////////////////////////////////////////////////////////
// 가격대별매매비중조회(t1449) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1449     "t1449"

// 기본입력
typedef struct _t1449InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    dategb              [   1];    char    _dategb              ;    // [string,    1] 일자구분                       StartPos 7, Length 1
} t1449InBlock, *LPt1449InBlock;
#define NAME_t1449InBlock     "t1449InBlock"

// 출력
typedef struct _t1449OutBlock
{
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 0, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 9, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 11, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 20, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 27, Length 12
    char    msvolume            [  12];    char    _msvolume            ;    // [long  ,   12] 매수체결량                     StartPos 40, Length 12
    char    mdvolume            [  12];    char    _mdvolume            ;    // [long  ,   12] 매도체결량                     StartPos 53, Length 12
} t1449OutBlock, *LPt1449OutBlock;
#define NAME_t1449OutBlock     "t1449OutBlock"

// 출력1, occurs
typedef struct _t1449OutBlock1
{
    char    price               [   8];    char    _price               ;    // [long  ,    8] 체결가                         StartPos 0, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 9, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 11, Length 8
    char    tickdiff            [   6];    char    _tickdiff            ;    // [float ,  6.2] 등락율                         StartPos 20, Length 6
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 체결수량                       StartPos 27, Length 12
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 비중                           StartPos 40, Length 6
    char    mdvolume            [  12];    char    _mdvolume            ;    // [long  ,   12] 매도체결량                     StartPos 47, Length 12
    char    msvolume            [  12];    char    _msvolume            ;    // [long  ,   12] 매수체결량                     StartPos 60, Length 12
    char    msdiff              [   6];    char    _msdiff              ;    // [float ,  6.2] 매수비율                       StartPos 73, Length 6
} t1449OutBlock1, *LPt1449OutBlock1;
#define NAME_t1449OutBlock1     "t1449OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
