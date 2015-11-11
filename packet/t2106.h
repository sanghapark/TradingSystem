///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물/옵션현재가시세메모(t2106) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2106     "t2106"

// 기본입력
typedef struct _t2106InBlock
{
    char    code                [   8];    // [string,    8] 종목코드                       StartPos 0, Length 8
    char    nrec                [   2];    // [string,    2] 건수                           StartPos 8, Length 2
} t2106InBlock, *LPt2106InBlock;
#define NAME_t2106InBlock     "t2106InBlock"

// 기본입력1, occurs
typedef struct _t2106InBlock1
{
    char    indx                [   1];    // [string,    1] 인덱스                         StartPos 0, Length 1
    char    gubn                [   1];    // [string,    1] 조건구분                       StartPos 1, Length 1
    char    dat1                [   1];    // [string,    1] 데이타1                        StartPos 2, Length 1
    char    dat2                [   8];    // [string,    8] 데이타2                        StartPos 3, Length 8
} t2106InBlock1, *LPt2106InBlock1;
#define NAME_t2106InBlock1     "t2106InBlock1"

// 출력
typedef struct _t2106OutBlock
{
    char    nrec                [   2];    // [string,    2] 출력건수                       StartPos 0, Length 2
} t2106OutBlock, *LPt2106OutBlock;
#define NAME_t2106OutBlock     "t2106OutBlock"

// 출력1, occurs
typedef struct _t2106OutBlock1
{
    char    indx                [   1];    // [string,    1] 인덱스                         StartPos 0, Length 1
    char    gubn                [   1];    // [string,    1] 조건구분                       StartPos 1, Length 1
    char    vals                [   8];    // [string,    8] 출력값                         StartPos 2, Length 8
} t2106OutBlock1, *LPt2106OutBlock1;
#define NAME_t2106OutBlock1     "t2106OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
