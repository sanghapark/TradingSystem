///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식현재가시세메모(t1104) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1104     "t1104"

// 기본입력
typedef struct _t1104InBlock
{
    char    code                [   6];    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    nrec                [   2];    // [string,    2] 건수                           StartPos 6, Length 2
} t1104InBlock, *LPt1104InBlock;
#define NAME_t1104InBlock     "t1104InBlock"

// 기본입력1, occurs
typedef struct _t1104InBlock1
{
    char    indx                [   1];    // [string,    1] 인덱스                         StartPos 0, Length 1
    char    gubn                [   1];    // [string,    1] 조건구분                       StartPos 1, Length 1
    char    dat1                [   1];    // [string,    1] 데이타1                        StartPos 2, Length 1
    char    dat2                [   8];    // [string,    8] 데이타2                        StartPos 3, Length 8
} t1104InBlock1, *LPt1104InBlock1;
#define NAME_t1104InBlock1     "t1104InBlock1"

// 출력
typedef struct _t1104OutBlock
{
    char    nrec                [   2];    // [string,    2] 출력건수                       StartPos 0, Length 2
} t1104OutBlock, *LPt1104OutBlock;
#define NAME_t1104OutBlock     "t1104OutBlock"

// 출력1, occurs
typedef struct _t1104OutBlock1
{
    char    indx                [   1];    // [string,    1] 인덱스                         StartPos 0, Length 1
    char    gubn                [   1];    // [string,    1] 조건구분                       StartPos 1, Length 1
    char    vals                [   8];    // [string,    8] 출력값                         StartPos 2, Length 8
} t1104OutBlock1, *LPt1104OutBlock1;
#define NAME_t1104OutBlock1     "t1104OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
