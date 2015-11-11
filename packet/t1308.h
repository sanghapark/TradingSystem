///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식시간대별체결조회챠트(t1308) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1308     "t1308"

// 기본입력
typedef struct _t1308InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    starttime           [   4];    char    _starttime           ;    // [string,    4] 시작시간                       StartPos 7, Length 4
    char    endtime             [   4];    char    _endtime             ;    // [string,    4] 종료시간                       StartPos 12, Length 4
    char    bun_term            [   2];    char    _bun_term            ;    // [string,    2] 분간격                         StartPos 17, Length 2
} t1308InBlock, *LPt1308InBlock;
#define NAME_t1308InBlock     "t1308InBlock"

// 출력1, occurs
typedef struct _t1308OutBlock1
{
    char    chetime             [   8];    char    _chetime             ;    // [string,    8] 시간                           StartPos 0, Length 8
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 9, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 18, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 20, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 29, Length 6
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결수량                       StartPos 36, Length 8
    char    chdegvol            [   8];    char    _chdegvol            ;    // [float ,  8.2] 체결강도(거래량)               StartPos 45, Length 8
    char    chdegcnt            [   8];    char    _chdegcnt            ;    // [float ,  8.2] 체결강도(건수)                 StartPos 54, Length 8
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 63, Length 12
    char    mdvolume            [  12];    char    _mdvolume            ;    // [long  ,   12] 매도체결수량                   StartPos 76, Length 12
    char    mdchecnt            [   8];    char    _mdchecnt            ;    // [long  ,    8] 매도체결건수                   StartPos 89, Length 8
    char    msvolume            [  12];    char    _msvolume            ;    // [long  ,   12] 매수체결수량                   StartPos 98, Length 12
    char    mschecnt            [   8];    char    _mschecnt            ;    // [long  ,    8] 매수체결건수                   StartPos 111, Length 8
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 120, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 129, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 138, Length 8
} t1308OutBlock1, *LPt1308OutBlock1;
#define NAME_t1308OutBlock1     "t1308OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
