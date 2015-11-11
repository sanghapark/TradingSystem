///////////////////////////////////////////////////////////////////////////////////////////////////
// 프로그램매매종합조회(t1631) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1631     "t1631"

// 기본입력
typedef struct _t1631InBlock
{
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분                           StartPos 0, Length 1
    char    dgubun              [   1];    char    _dgubun              ;    // [string,    1] 일자구분                       StartPos 2, Length 1
    char    sdate               [   8];    char    _sdate               ;    // [string,    8] 시작일자                       StartPos 4, Length 8
    char    edate               [   8];    char    _edate               ;    // [string,    8] 종료일자                       StartPos 13, Length 8
} t1631InBlock, *LPt1631InBlock;
#define NAME_t1631InBlock     "t1631InBlock"

// 출력
typedef struct _t1631OutBlock
{
    char    cdhrem              [   8];    char    _cdhrem              ;    // [long  ,    8] 매도차익미체결잔량             StartPos 0, Length 8
    char    bdhrem              [   8];    char    _bdhrem              ;    // [long  ,    8] 매도비차익미체결잔량           StartPos 9, Length 8
    char    tcdrem              [   8];    char    _tcdrem              ;    // [long  ,    8] 매도차익주문수량               StartPos 18, Length 8
    char    tbdrem              [   8];    char    _tbdrem              ;    // [long  ,    8] 매도비차익주문수량             StartPos 27, Length 8
    char    cshrem              [   8];    char    _cshrem              ;    // [long  ,    8] 매수차익미체결잔량             StartPos 36, Length 8
    char    bshrem              [   8];    char    _bshrem              ;    // [long  ,    8] 매수비차익미체결잔량           StartPos 45, Length 8
    char    tcsrem              [   8];    char    _tcsrem              ;    // [long  ,    8] 매수차익주문수량               StartPos 54, Length 8
    char    tbsrem              [   8];    char    _tbsrem              ;    // [long  ,    8] 매수비차익주문수량             StartPos 63, Length 8
} t1631OutBlock, *LPt1631OutBlock;
#define NAME_t1631OutBlock     "t1631OutBlock"

// 출력1, occurs
typedef struct _t1631OutBlock1
{
    char    offervolume         [   8];    char    _offervolume         ;    // [long  ,    8] 매도수량                       StartPos 0, Length 8
    char    offervalue          [  12];    char    _offervalue          ;    // [long  ,   12] 매도금액                       StartPos 9, Length 12
    char    bidvolume           [   8];    char    _bidvolume           ;    // [long  ,    8] 매수수량                       StartPos 22, Length 8
    char    bidvalue            [  12];    char    _bidvalue            ;    // [long  ,   12] 매수금액                       StartPos 31, Length 12
    char    volume              [   8];    char    _volume              ;    // [long  ,    8] 순매수수량                     StartPos 44, Length 8
    char    value               [  12];    char    _value               ;    // [long  ,   12] 순매수금액                     StartPos 53, Length 12
} t1631OutBlock1, *LPt1631OutBlock1;
#define NAME_t1631OutBlock1     "t1631OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
