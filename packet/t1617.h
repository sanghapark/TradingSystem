///////////////////////////////////////////////////////////////////////////////////////////////////
// 투자자매매종합2(t1617) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1617     "t1617"

// 기본입력
typedef struct _t1617InBlock
{
    char    gubun1              [   1];    char    _gubun1              ;    // [string,    1] 시장구분(1:코스피2:코스닥3:선물 StartPos 0, Length 1
    char    gubun2              [   1];    char    _gubun2              ;    // [string,    1] 수량금액구분(1:수량2:금액)     StartPos 2, Length 1
    char    gubun3              [   1];    char    _gubun3              ;    // [string,    1] 일자구분(1:시간대별2:일별)     StartPos 4, Length 1
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] CTSDATE(연속키값-일자)         StartPos 6, Length 8
    char    cts_time            [   8];    char    _cts_time            ;    // [string,    8] CTSTIME(연속키값-시간)         StartPos 15, Length 8
} t1617InBlock, *LPt1617InBlock;
#define NAME_t1617InBlock     "t1617InBlock"

// 기본출력
typedef struct _t1617OutBlock
{
    char    cts_date            [   8];    char    _cts_date            ;    // [string,    8] CTSDATE                        StartPos 0, Length 8
    char    cts_time            [   8];    char    _cts_time            ;    // [string,    8] CTSTIME                        StartPos 9, Length 8
    char    ms_08               [  12];    char    _ms_08               ;    // [long  ,   12] 개인매수                       StartPos 18, Length 12
    char    md_08               [  12];    char    _md_08               ;    // [long  ,   12] 개인매도                       StartPos 31, Length 12
    char    sv_08               [  12];    char    _sv_08               ;    // [long  ,   12] 개인순매수                     StartPos 44, Length 12
    char    ms_17               [  12];    char    _ms_17               ;    // [long  ,   12] 외국인매수                     StartPos 57, Length 12
    char    md_17               [  12];    char    _md_17               ;    // [long  ,   12] 외국인매도                     StartPos 70, Length 12
    char    sv_17               [  12];    char    _sv_17               ;    // [long  ,   12] 외국인순매수                   StartPos 83, Length 12
    char    ms_18               [  12];    char    _ms_18               ;    // [long  ,   12] 기관계매수                     StartPos 96, Length 12
    char    md_18               [  12];    char    _md_18               ;    // [long  ,   12] 기관계매도                     StartPos 109, Length 12
    char    sv_18               [  12];    char    _sv_18               ;    // [long  ,   12] 기관계순매수                   StartPos 122, Length 12
    char    ms_01               [  12];    char    _ms_01               ;    // [long  ,   12] 증권매수                       StartPos 135, Length 12
    char    md_01               [  12];    char    _md_01               ;    // [long  ,   12] 증권매도                       StartPos 148, Length 12
    char    sv_01               [  12];    char    _sv_01               ;    // [long  ,   12] 증권순매수                     StartPos 161, Length 12
} t1617OutBlock, *LPt1617OutBlock;
#define NAME_t1617OutBlock     "t1617OutBlock"

// 출력1, occurs
typedef struct _t1617OutBlock1
{
    char    date                [   8];    char    _date                ;    // [string,    8] 날짜                           StartPos 0, Length 8
    char    time                [   8];    char    _time                ;    // [string,    8] 시간                           StartPos 9, Length 8
    char    sv_08               [  12];    char    _sv_08               ;    // [long  ,   12] 개인                           StartPos 18, Length 12
    char    sv_17               [  12];    char    _sv_17               ;    // [long  ,   12] 외국인                         StartPos 31, Length 12
    char    sv_18               [  12];    char    _sv_18               ;    // [long  ,   12] 기관계                         StartPos 44, Length 12
    char    sv_01               [  12];    char    _sv_01               ;    // [long  ,   12] 증권                           StartPos 57, Length 12
} t1617OutBlock1, *LPt1617OutBlock1;
#define NAME_t1617OutBlock1     "t1617OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
