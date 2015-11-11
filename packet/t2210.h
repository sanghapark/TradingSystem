///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션시간대별체결조회(단일출력용) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2210     "t2210"

// 기본입력
typedef struct _t2210InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 특이거래량                     StartPos 9, Length 12
    char    stime               [   4];    char    _stime               ;    // [string,    4] 시작시간                       StartPos 22, Length 4
    char    etime               [   4];    char    _etime               ;    // [string,    4] 종료시간                       StartPos 27, Length 4
} t2210InBlock, *LPt2210InBlock;
#define NAME_t2210InBlock     "t2210InBlock"

// 출력
typedef struct _t2210OutBlock
{
    char    mdvolume            [   8];    char    _mdvolume            ;    // [long  ,    8] 매도체결수량                   StartPos 0, Length 8
    char    mdchecnt            [   8];    char    _mdchecnt            ;    // [long  ,    8] 매도체결건수                   StartPos 9, Length 8
    char    msvolume            [   8];    char    _msvolume            ;    // [long  ,    8] 매수체결수량                   StartPos 18, Length 8
    char    mschecnt            [   8];    char    _mschecnt            ;    // [long  ,    8] 매수체결건수                   StartPos 27, Length 8
} t2210OutBlock, *LPt2210OutBlock;
#define NAME_t2210OutBlock     "t2210OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
