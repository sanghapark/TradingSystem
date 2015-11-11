///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물호가(FH0) ( attr,block )
#pragma once
#pragma pack( push, 1 )

#define NAME_FH0     "FH0"

// 입력
typedef struct _FH0_InBlock
{
    char    futcode             [   8];    // [string,    8] 단축코드                       StartPos 0, Length 8
} FH0_InBlock, *LPFH0_InBlock;
#define NAME_FH0_InBlock     "InBlock"

// 출력
typedef struct _FH0_OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 0, Length 6
    char    offerho1            [   6];    char    _offerho1            ;    // [double,  6.2] 매도호가1                      StartPos 7, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [double,  6.2] 매수호가1                      StartPos 14, Length 6
    char    offerrem1           [   6];    char    _offerrem1           ;    // [long  ,    6] 매도호가수량1                  StartPos 21, Length 6
    char    bidrem1             [   6];    char    _bidrem1             ;    // [long  ,    6] 매수호가수량1                  StartPos 28, Length 6
    char    offercnt1           [   5];    char    _offercnt1           ;    // [long  ,    5] 매도호가건수1                  StartPos 35, Length 5
    char    bidcnt1             [   5];    char    _bidcnt1             ;    // [long  ,    5] 매수호가건수1                  StartPos 41, Length 5
    char    offerho2            [   6];    char    _offerho2            ;    // [double,  6.2] 매도호가2                      StartPos 47, Length 6
    char    bidho2              [   6];    char    _bidho2              ;    // [double,  6.2] 매수호가2                      StartPos 54, Length 6
    char    offerrem2           [   6];    char    _offerrem2           ;    // [long  ,    6] 매도호가수량2                  StartPos 61, Length 6
    char    bidrem2             [   6];    char    _bidrem2             ;    // [long  ,    6] 매수호가수량2                  StartPos 68, Length 6
    char    offercnt2           [   5];    char    _offercnt2           ;    // [long  ,    5] 매도호가건수2                  StartPos 75, Length 5
    char    bidcnt2             [   5];    char    _bidcnt2             ;    // [long  ,    5] 매수호가건수2                  StartPos 81, Length 5
    char    offerho3            [   6];    char    _offerho3            ;    // [double,  6.2] 매도호가3                      StartPos 87, Length 6
    char    bidho3              [   6];    char    _bidho3              ;    // [double,  6.2] 매수호가3                      StartPos 94, Length 6
    char    offerrem3           [   6];    char    _offerrem3           ;    // [long  ,    6] 매도호가수량3                  StartPos 101, Length 6
    char    bidrem3             [   6];    char    _bidrem3             ;    // [long  ,    6] 매수호가수량3                  StartPos 108, Length 6
    char    offercnt3           [   5];    char    _offercnt3           ;    // [long  ,    5] 매도호가건수3                  StartPos 115, Length 5
    char    bidcnt3             [   5];    char    _bidcnt3             ;    // [long  ,    5] 매수호가건수3                  StartPos 121, Length 5
    char    offerho4            [   6];    char    _offerho4            ;    // [double,  6.2] 매도호가4                      StartPos 127, Length 6
    char    bidho4              [   6];    char    _bidho4              ;    // [double,  6.2] 매수호가4                      StartPos 134, Length 6
    char    offerrem4           [   6];    char    _offerrem4           ;    // [long  ,    6] 매도호가수량4                  StartPos 141, Length 6
    char    bidrem4             [   6];    char    _bidrem4             ;    // [long  ,    6] 매수호가수량4                  StartPos 148, Length 6
    char    offercnt4           [   5];    char    _offercnt4           ;    // [long  ,    5] 매도호가건수4                  StartPos 155, Length 5
    char    bidcnt4             [   5];    char    _bidcnt4             ;    // [long  ,    5] 매수호가건수4                  StartPos 161, Length 5
    char    offerho5            [   6];    char    _offerho5            ;    // [double,  6.2] 매도호가5                      StartPos 167, Length 6
    char    bidho5              [   6];    char    _bidho5              ;    // [double,  6.2] 매수호가5                      StartPos 174, Length 6
    char    offerrem5           [   6];    char    _offerrem5           ;    // [long  ,    6] 매도호가수량5                  StartPos 181, Length 6
    char    bidrem5             [   6];    char    _bidrem5             ;    // [long  ,    6] 매수호가수량5                  StartPos 188, Length 6
    char    offercnt5           [   5];    char    _offercnt5           ;    // [long  ,    5] 매도호가건수5                  StartPos 195, Length 5
    char    bidcnt5             [   5];    char    _bidcnt5             ;    // [long  ,    5] 매수호가건수5                  StartPos 201, Length 5
    char    totofferrem         [   6];    char    _totofferrem         ;    // [long  ,    6] 매도호가총수량                 StartPos 207, Length 6
    char    totbidrem           [   6];    char    _totbidrem           ;    // [long  ,    6] 매수호가총수량                 StartPos 214, Length 6
    char    totoffercnt         [   5];    char    _totoffercnt         ;    // [long  ,    5] 매도호가총건수                 StartPos 221, Length 5
    char    totbidcnt           [   5];    char    _totbidcnt           ;    // [long  ,    5] 매수호가총건수                 StartPos 227, Length 5
    char    futcode             [   8];    char    _futcode             ;    // [string,    8] 단축코드                       StartPos 233, Length 8

	void SetDelimiter(char delimiter);

} FH0_OutBlock, *LPFH0_OutBlock;
#define NAME_FH0_OutBlock     "OutBlock"





#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
