///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목별증시일정(t3202) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t3202     "t3202"

// 기본입력
typedef struct _t3202InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    date                [   8];    char    _date                ;    // [string,    8] 조회일자                       StartPos 7, Length 8
} t3202InBlock, *LPt3202InBlock;
#define NAME_t3202InBlock     "t3202InBlock"

// 출력, occurs
typedef struct _t3202OutBlock
{
    char    recdt               [   8];    char    _recdt               ;    // [string,    8] 기준일                         StartPos 0, Length 8
    char    tableid             [   6];    char    _tableid             ;    // [string,    6] 테이블아이디                   StartPos 9, Length 6
    char    upgu                [   2];    char    _upgu                ;    // [string,    2] 업무구분                       StartPos 16, Length 2
    char    custno              [   5];    char    _custno              ;    // [string,    5] 발행체번호                     StartPos 19, Length 5
    char    custnm              [  80];    char    _custnm              ;    // [string,   80] 발행회사명                     StartPos 25, Length 80
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 106, Length 6
    char    upnm                [  20];    char    _upnm                ;    // [string,   20] 업무명                         StartPos 113, Length 20
} t3202OutBlock, *LPt3202OutBlock;
#define NAME_t3202OutBlock     "t3202OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
