///////////////////////////////////////////////////////////////////////////////////////////////////
// 프로그램매매종합조회(미니)(t1640) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1640     "t1640"

// 기본입력
typedef struct _t1640InBlock
{
    char    gubun               [   2];    char    _gubun               ;    // [string,    2] 구분                           StartPos 0, Length 2
} t1640InBlock, *LPt1640InBlock;
#define NAME_t1640InBlock     "t1640InBlock"

// 출력
typedef struct _t1640OutBlock
{
    char    offervolume         [   8];    char    _offervolume         ;    // [long  ,    8] 매도수량                       StartPos 0, Length 8
    char    bidvolume           [   8];    char    _bidvolume           ;    // [long  ,    8] 매수수량                       StartPos 9, Length 8
    char    volume              [   8];    char    _volume              ;    // [long  ,    8] 순매수수량                     StartPos 18, Length 8
    char    offerdiff           [   8];    char    _offerdiff           ;    // [long  ,    8] 매도증감                       StartPos 27, Length 8
    char    biddiff             [   8];    char    _biddiff             ;    // [long  ,    8] 매수증감                       StartPos 36, Length 8
    char    sundiff             [   8];    char    _sundiff             ;    // [long  ,    8] 순매수증감                     StartPos 45, Length 8
    char    basis               [   6];    char    _basis               ;    // [float ,  6.2] 베이시스                       StartPos 54, Length 6
    char    offervalue          [  12];    char    _offervalue          ;    // [double,   12] 매도금액                       StartPos 61, Length 12
    char    bidvalue            [  12];    char    _bidvalue            ;    // [double,   12] 매수금액                       StartPos 74, Length 12
    char    value               [  12];    char    _value               ;    // [double,   12] 순매수금액                     StartPos 87, Length 12
    char    offervaldiff        [  12];    char    _offervaldiff        ;    // [double,   12] 매도금액증감                   StartPos 100, Length 12
    char    bidvaldiff          [  12];    char    _bidvaldiff          ;    // [double,   12] 매수금액증감                   StartPos 113, Length 12
    char    sunvaldiff          [  12];    char    _sunvaldiff          ;    // [double,   12] 순매수증감                     StartPos 126, Length 12
} t1640OutBlock, *LPt1640OutBlock;
#define NAME_t1640OutBlock     "t1640OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
