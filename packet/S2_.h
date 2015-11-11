///////////////////////////////////////////////////////////////////////////////////////////////////
// KOSPI우선호가(S2) ( attr,block )
#pragma pack( push, 1 )

#define NAME_S2_     "S2_"

// 입력
typedef struct _S2__InBlock
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
} S2__InBlock, *LPS2__InBlock;
#define NAME_S2__InBlock     "InBlock"

// 출력
typedef struct _S2__OutBlock
{
    char    offerho             [   8];    char    _offerho             ;    // [long  ,    8] 매도호가                       StartPos 0, Length 8
    char    bidho               [   8];    char    _bidho               ;    // [long  ,    8] 매수호가                       StartPos 9, Length 8
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 18, Length 6
} S2__OutBlock, *LPS2__OutBlock;
#define NAME_S2__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
