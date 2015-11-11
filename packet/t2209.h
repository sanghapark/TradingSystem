///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션틱분별체결조회챠트(t2209) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2209     "t2209"

// 기본입력
typedef struct _t2209InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
    char    cgubun              [   1];    char    _cgubun              ;    // [string,    1] 챠트구분                       StartPos 9, Length 1
    char    bgubun              [   3];    char    _bgubun              ;    // [string,    3] 분구분                         StartPos 11, Length 3
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 조회건수                       StartPos 15, Length 3
} t2209InBlock, *LPt2209InBlock;
#define NAME_t2209InBlock     "t2209InBlock"

// 출력1, occurs
typedef struct _t2209OutBlock1
{
    char    chetime             [  10];    char    _chetime             ;    // [string,   10] 시간                           StartPos 0, Length 10
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                         StartPos 11, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 18, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                       StartPos 20, Length 6
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                           StartPos 27, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                           StartPos 34, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                           StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [double,   12] 거래량                         StartPos 48, Length 12
    char    value               [  12];    char    _value               ;    // [double,   12] 거래대금                       StartPos 61, Length 12
    char    openyak             [   8];    char    _openyak             ;    // [long  ,    8] 미결수량                       StartPos 74, Length 8
    char    openupdn            [   8];    char    _openupdn            ;    // [long  ,    8] 미결증감                       StartPos 83, Length 8
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결수량                       StartPos 92, Length 8
    char    s_mschecnt          [   8];    char    _s_mschecnt          ;    // [long  ,    8] 매수순간체결건수               StartPos 101, Length 8
    char    s_mdchecnt          [   8];    char    _s_mdchecnt          ;    // [long  ,    8] 매도순간체결건수               StartPos 110, Length 8
    char    ss_mschecnt         [   8];    char    _ss_mschecnt         ;    // [long  ,    8] 순매수순간체결건수             StartPos 119, Length 8
    char    s_mschevol          [  12];    char    _s_mschevol          ;    // [double,   12] 매수순간체결량                 StartPos 128, Length 12
    char    s_mdchevol          [  12];    char    _s_mdchevol          ;    // [double,   12] 매도순간체결량                 StartPos 141, Length 12
    char    ss_mschevol         [  12];    char    _ss_mschevol         ;    // [double,   12] 순매수순간체결량               StartPos 154, Length 12
    char    chdegvol            [   8];    char    _chdegvol            ;    // [float ,  8.2] 체결강도(거래량)               StartPos 167, Length 8
    char    chdegcnt            [   8];    char    _chdegcnt            ;    // [float ,  8.2] 체결강도(건수)                 StartPos 176, Length 8
} t2209OutBlock1, *LPt2209OutBlock1;
#define NAME_t2209OutBlock1     "t2209OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
