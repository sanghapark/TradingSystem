///////////////////////////////////////////////////////////////////////////////////////////////////
// 투자자매매종합(챠트) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1664     "t1664"

// 기본입력
typedef struct _t1664InBlock
{
    char    mgubun              [   1];    char    _mgubun              ;    // [string,    1] 시장구분                       StartPos 0, Length 1
    char    vagubun             [   1];    char    _vagubun             ;    // [string,    1] 금액수량구분                   StartPos 2, Length 1
    char    bdgubun             [   1];    char    _bdgubun             ;    // [string,    1] 시간일별구분                   StartPos 4, Length 1
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 조회건수                       StartPos 6, Length 3
} t1664InBlock, *LPt1664InBlock;
#define NAME_t1664InBlock     "t1664InBlock"

// 출력1, occurs
typedef struct _t1664OutBlock1
{
    char    dt                  [   8];    char    _dt                  ;    // [string,    8] 일자시간                       StartPos 0, Length 8
    char    tjj01               [  12];    char    _tjj01               ;    // [double,   12] 증권순매수                     StartPos 9, Length 12
    char    tjj02               [  12];    char    _tjj02               ;    // [double,   12] 보험순매수                     StartPos 22, Length 12
    char    tjj03               [  12];    char    _tjj03               ;    // [double,   12] 투신순매수                     StartPos 35, Length 12
    char    tjj04               [  12];    char    _tjj04               ;    // [double,   12] 은행순매수                     StartPos 48, Length 12
    char    tjj05               [  12];    char    _tjj05               ;    // [double,   12] 종금순매수                     StartPos 61, Length 12
    char    tjj06               [  12];    char    _tjj06               ;    // [double,   12] 기금순매수                     StartPos 74, Length 12
    char    tjj07               [  12];    char    _tjj07               ;    // [double,   12] 기타순매수                     StartPos 87, Length 12
    char    tjj08               [  12];    char    _tjj08               ;    // [double,   12] 개인순매수                     StartPos 100, Length 12
    char    tjj17               [  12];    char    _tjj17               ;    // [double,   12] 외국인순매수                   StartPos 113, Length 12
    char    tjj18               [  12];    char    _tjj18               ;    // [double,   12] 기관순매수                     StartPos 126, Length 12
    char    cha                 [  12];    char    _cha                 ;    // [double,   12] 차익순매수                     StartPos 139, Length 12
    char    bicha               [  12];    char    _bicha               ;    // [double,   12] 비차익순매수                   StartPos 152, Length 12
    char    totcha              [  12];    char    _totcha              ;    // [double,   12] 종합순매수                     StartPos 165, Length 12
    char    basis               [   6];    char    _basis               ;    // [float ,  6.2] 베이시스                       StartPos 178, Length 6
} t1664OutBlock1, *LPt1664OutBlock1;
#define NAME_t1664OutBlock1     "t1664OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
