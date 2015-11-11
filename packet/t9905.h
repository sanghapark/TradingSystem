///////////////////////////////////////////////////////////////////////////////////////////////////
// 기초자산리스트조회(t9905) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t9905     "t9905"

// 기본입력
typedef struct _t9905InBlock
{
    char    dummy               [   1];    // [string,    1] DUMMY                          StartPos 0, Length 1
} t9905InBlock, *LPt9905InBlock;
#define NAME_t9905InBlock     "t9905InBlock"

// 출력1, occurs
typedef struct _t9905OutBlock1
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    expcode             [  12];    // [string,   12] 표준코드                       StartPos 6, Length 12
    char    hname               [  20];    // [string,   20] 종목명                         StartPos 18, Length 20
} t9905OutBlock1, *LPt9905OutBlock1;
#define NAME_t9905OutBlock1     "t9905OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
