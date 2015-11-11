///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식피못/디마크조회(t1105) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1105     "t1105"

// 기본입력
typedef struct _t1105InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
} t1105InBlock, *LPt1105InBlock;
#define NAME_t1105InBlock     "t1105InBlock"

// 출력
typedef struct _t1105OutBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
    char    pbot                [   8];    char    _pbot                ;    // [long  ,    8] 피봇                           StartPos 7, Length 8
    char    offer1              [   8];    char    _offer1              ;    // [long  ,    8] 1차저항                        StartPos 16, Length 8
    char    supp1               [   8];    char    _supp1               ;    // [long  ,    8] 1차지지                        StartPos 25, Length 8
    char    offer2              [   8];    char    _offer2              ;    // [long  ,    8] 2차저항                        StartPos 34, Length 8
    char    supp2               [   8];    char    _supp2               ;    // [long  ,    8] 2차지지                        StartPos 43, Length 8
    char    stdprc              [   8];    char    _stdprc              ;    // [long  ,    8] 기준가격                       StartPos 52, Length 8
    char    offerd              [   8];    char    _offerd              ;    // [long  ,    8] D저항                          StartPos 61, Length 8
    char    suppd               [   8];    char    _suppd               ;    // [long  ,    8] D지지                          StartPos 70, Length 8
} t1105OutBlock, *LPt1105OutBlock;
#define NAME_t1105OutBlock     "t1105OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
