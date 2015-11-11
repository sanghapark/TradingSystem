///////////////////////////////////////////////////////////////////////////////////////////////////
// KOSDAQ호가잔량(HA) ( attr,block )
#pragma pack( push, 1 )

#define NAME_HA_     "HA_"

// 입력
typedef struct _HA__InBlock
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
} HA__InBlock, *LPHA__InBlock;
#define NAME_HA__InBlock     "InBlock"

// 출력
typedef struct _HA__OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 0, Length 6
    char    offerho1            [   7];    char    _offerho1            ;    // [long  ,    7] 매도호가1                      StartPos 7, Length 7
    char    bidho1              [   7];    char    _bidho1              ;    // [long  ,    7] 매수호가1                      StartPos 15, Length 7
    char    offerrem1           [   9];    char    _offerrem1           ;    // [long  ,    9] 매도호가잔량1                  StartPos 23, Length 9
    char    bidrem1             [   9];    char    _bidrem1             ;    // [long  ,    9] 매수호가잔량1                  StartPos 33, Length 9
    char    offerho2            [   7];    char    _offerho2            ;    // [long  ,    7] 매도호가2                      StartPos 43, Length 7
    char    bidho2              [   7];    char    _bidho2              ;    // [long  ,    7] 매수호가2                      StartPos 51, Length 7
    char    offerrem2           [   9];    char    _offerrem2           ;    // [long  ,    9] 매도호가잔량2                  StartPos 59, Length 9
    char    bidrem2             [   9];    char    _bidrem2             ;    // [long  ,    9] 매수호가잔량2                  StartPos 69, Length 9
    char    offerho3            [   7];    char    _offerho3            ;    // [long  ,    7] 매도호가3                      StartPos 79, Length 7
    char    bidho3              [   7];    char    _bidho3              ;    // [long  ,    7] 매수호가3                      StartPos 87, Length 7
    char    offerrem3           [   9];    char    _offerrem3           ;    // [long  ,    9] 매도호가잔량3                  StartPos 95, Length 9
    char    bidrem3             [   9];    char    _bidrem3             ;    // [long  ,    9] 매수호가잔량3                  StartPos 105, Length 9
    char    offerho4            [   7];    char    _offerho4            ;    // [long  ,    7] 매도호가4                      StartPos 115, Length 7
    char    bidho4              [   7];    char    _bidho4              ;    // [long  ,    7] 매수호가4                      StartPos 123, Length 7
    char    offerrem4           [   9];    char    _offerrem4           ;    // [long  ,    9] 매도호가잔량4                  StartPos 131, Length 9
    char    bidrem4             [   9];    char    _bidrem4             ;    // [long  ,    9] 매수호가잔량4                  StartPos 141, Length 9
    char    offerho5            [   7];    char    _offerho5            ;    // [long  ,    7] 매도호가5                      StartPos 151, Length 7
    char    bidho5              [   7];    char    _bidho5              ;    // [long  ,    7] 매수호가5                      StartPos 159, Length 7
    char    offerrem5           [   9];    char    _offerrem5           ;    // [long  ,    9] 매도호가잔량5                  StartPos 167, Length 9
    char    bidrem5             [   9];    char    _bidrem5             ;    // [long  ,    9] 매수호가잔량5                  StartPos 177, Length 9
    char    offerho6            [   7];    char    _offerho6            ;    // [long  ,    7] 매도호가6                      StartPos 187, Length 7
    char    bidho6              [   7];    char    _bidho6              ;    // [long  ,    7] 매수호가6                      StartPos 195, Length 7
    char    offerrem6           [   9];    char    _offerrem6           ;    // [long  ,    9] 매도호가잔량6                  StartPos 203, Length 9
    char    bidrem6             [   9];    char    _bidrem6             ;    // [long  ,    9] 매수호가잔량6                  StartPos 213, Length 9
    char    offerho7            [   7];    char    _offerho7            ;    // [long  ,    7] 매도호가7                      StartPos 223, Length 7
    char    bidho7              [   7];    char    _bidho7              ;    // [long  ,    7] 매수호가7                      StartPos 231, Length 7
    char    offerrem7           [   9];    char    _offerrem7           ;    // [long  ,    9] 매도호가잔량7                  StartPos 239, Length 9
    char    bidrem7             [   9];    char    _bidrem7             ;    // [long  ,    9] 매수호가잔량7                  StartPos 249, Length 9
    char    offerho8            [   7];    char    _offerho8            ;    // [long  ,    7] 매도호가8                      StartPos 259, Length 7
    char    bidho8              [   7];    char    _bidho8              ;    // [long  ,    7] 매수호가8                      StartPos 267, Length 7
    char    offerrem8           [   9];    char    _offerrem8           ;    // [long  ,    9] 매도호가잔량8                  StartPos 275, Length 9
    char    bidrem8             [   9];    char    _bidrem8             ;    // [long  ,    9] 매수호가잔량8                  StartPos 285, Length 9
    char    offerho9            [   7];    char    _offerho9            ;    // [long  ,    7] 매도호가9                      StartPos 295, Length 7
    char    bidho9              [   7];    char    _bidho9              ;    // [long  ,    7] 매수호가9                      StartPos 303, Length 7
    char    offerrem9           [   9];    char    _offerrem9           ;    // [long  ,    9] 매도호가잔량9                  StartPos 311, Length 9
    char    bidrem9             [   9];    char    _bidrem9             ;    // [long  ,    9] 매수호가잔량9                  StartPos 321, Length 9
    char    offerho10           [   7];    char    _offerho10           ;    // [long  ,    7] 매도호가10                     StartPos 331, Length 7
    char    bidho10             [   7];    char    _bidho10             ;    // [long  ,    7] 매수호가10                     StartPos 339, Length 7
    char    offerrem10          [   9];    char    _offerrem10          ;    // [long  ,    9] 매도호가잔량10                 StartPos 347, Length 9
    char    bidrem10            [   9];    char    _bidrem10            ;    // [long  ,    9] 매수호가잔량10                 StartPos 357, Length 9
    char    totofferrem         [   9];    char    _totofferrem         ;    // [long  ,    9] 총매도호가잔량                 StartPos 367, Length 9
    char    totbidrem           [   9];    char    _totbidrem           ;    // [long  ,    9] 총매수호가잔량                 StartPos 377, Length 9
    char    donsigubun          [   1];    char    _donsigubun          ;    // [string,    1] 동시호가구분                   StartPos 387, Length 1
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 389, Length 6
} HA__OutBlock, *LPHA__OutBlock;
#define NAME_HA__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
