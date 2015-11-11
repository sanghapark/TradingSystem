///////////////////////////////////////////////////////////////////////////////////////////////////
// 옵션호가(OH0) ( attr,block )
#pragma once
#pragma pack( push, 1 )

#define NAME_OH0     "OH0"

// 입력
typedef struct _OH0_InBlock
{
    char    optcode             [   8];    // [string,    8] 단축코드                       StartPos 0, Length 8
} OH0_InBlock, *LPOH0_InBlock;
#define NAME_OH0_InBlock     "InBlock"

// 출력
typedef struct _OH0_OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 0, Length 6
    char    offerho1            [   6];    char    _offerho1            ;    // [double,  6.2] 매도호가1                      StartPos 7, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [double,  6.2] 매수호가1                      StartPos 14, Length 6
    char    offerrem1           [   7];    char    _offerrem1           ;    // [long  ,    7] 매도호가수량1                  StartPos 21, Length 7
    char    bidrem1             [   7];    char    _bidrem1             ;    // [long  ,    7] 매수호가수량1                  StartPos 29, Length 7
    char    offercnt1           [   5];    char    _offercnt1           ;    // [long  ,    5] 매도호가건수1                  StartPos 37, Length 5
    char    bidcnt1             [   5];    char    _bidcnt1             ;    // [long  ,    5] 매수호가건수1                  StartPos 43, Length 5
    char    offerho2            [   6];    char    _offerho2            ;    // [double,  6.2] 매도호가2                      StartPos 49, Length 6
    char    bidho2              [   6];    char    _bidho2              ;    // [double,  6.2] 매수호가2                      StartPos 56, Length 6
    char    offerrem2           [   7];    char    _offerrem2           ;    // [long  ,    7] 매도호가수량2                  StartPos 63, Length 7
    char    bidrem2             [   7];    char    _bidrem2             ;    // [long  ,    7] 매수호가수량2                  StartPos 71, Length 7
    char    offercnt2           [   5];    char    _offercnt2           ;    // [long  ,    5] 매도호가건수2                  StartPos 79, Length 5
    char    bidcnt2             [   5];    char    _bidcnt2             ;    // [long  ,    5] 매수호가건수2                  StartPos 85, Length 5
    char    offerho3            [   6];    char    _offerho3            ;    // [double,  6.2] 매도호가3                      StartPos 91, Length 6
    char    bidho3              [   6];    char    _bidho3              ;    // [double,  6.2] 매수호가3                      StartPos 98, Length 6
    char    offerrem3           [   7];    char    _offerrem3           ;    // [long  ,    7] 매도호가수량3                  StartPos 105, Length 7
    char    bidrem3             [   7];    char    _bidrem3             ;    // [long  ,    7] 매수호가수량3                  StartPos 113, Length 7
    char    offercnt3           [   5];    char    _offercnt3           ;    // [long  ,    5] 매도호가건수3                  StartPos 121, Length 5
    char    bidcnt3             [   5];    char    _bidcnt3             ;    // [long  ,    5] 매수호가건수3                  StartPos 127, Length 5
    char    offerho4            [   6];    char    _offerho4            ;    // [double,  6.2] 매도호가4                      StartPos 133, Length 6
    char    bidho4              [   6];    char    _bidho4              ;    // [double,  6.2] 매수호가4                      StartPos 140, Length 6
    char    offerrem4           [   7];    char    _offerrem4           ;    // [long  ,    7] 매도호가수량4                  StartPos 147, Length 7
    char    bidrem4             [   7];    char    _bidrem4             ;    // [long  ,    7] 매수호가수량4                  StartPos 155, Length 7
    char    offercnt4           [   5];    char    _offercnt4           ;    // [long  ,    5] 매도호가건수4                  StartPos 163, Length 5
    char    bidcnt4             [   5];    char    _bidcnt4             ;    // [long  ,    5] 매수호가건수4                  StartPos 169, Length 5
    char    offerho5            [   6];    char    _offerho5            ;    // [double,  6.2] 매도호가5                      StartPos 175, Length 6
    char    bidho5              [   6];    char    _bidho5              ;    // [double,  6.2] 매수호가5                      StartPos 182, Length 6
    char    offerrem5           [   7];    char    _offerrem5           ;    // [long  ,    7] 매도호가수량5                  StartPos 189, Length 7
    char    bidrem5             [   7];    char    _bidrem5             ;    // [long  ,    7] 매수호가수량5                  StartPos 197, Length 7
    char    offercnt5           [   5];    char    _offercnt5           ;    // [long  ,    5] 매도호가건수5                  StartPos 205, Length 5
    char    bidcnt5             [   5];    char    _bidcnt5             ;    // [long  ,    5] 매수호가건수5                  StartPos 211, Length 5
    char    totofferrem         [   7];    char    _totofferrem         ;    // [long  ,    7] 매도호가총수량                 StartPos 217, Length 7
    char    totbidrem           [   7];    char    _totbidrem           ;    // [long  ,    7] 매수호가총수량                 StartPos 225, Length 7
    char    totoffercnt         [   5];    char    _totoffercnt         ;    // [long  ,    5] 매도호가총건수                 StartPos 233, Length 5
    char    totbidcnt           [   5];    char    _totbidcnt           ;    // [long  ,    5] 매수호가총건수                 StartPos 239, Length 5
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 단축코드                       StartPos 245, Length 8

	void SetDelimiter(char delimiter);
} OH0_OutBlock, *LPOH0_OutBlock;
#define NAME_OH0_OutBlock     "OutBlock"




#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
