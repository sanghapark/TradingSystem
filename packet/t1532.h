///////////////////////////////////////////////////////////////////////////////////////////////////
// 종목별테마(t1532) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1532     "t1532"

// 기본입력
typedef struct _t1532InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
} t1532InBlock, *LPt1532InBlock;
#define NAME_t1532InBlock     "t1532InBlock"

// 출력, occurs
typedef struct _t1532OutBlock
{
    char    tmname              [  36];    char    _tmname              ;    // [string,   36] 테마명                         StartPos 0, Length 36
    char    avgdiff             [   6];    char    _avgdiff             ;    // [float ,  6.2] 평균등락율                     StartPos 37, Length 6
    char    tmcode              [   4];    char    _tmcode              ;    // [string,    4] 테마코드                       StartPos 44, Length 4
} t1532OutBlock, *LPt1532OutBlock;
#define NAME_t1532OutBlock     "t1532OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
