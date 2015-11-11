///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW호가잔량(h3) ( attr,block )
#pragma pack( push, 1 )

#define NAME_h3_     "h3_"

// 입력
typedef struct _h3__InBlock
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
} h3__InBlock, *LPh3__InBlock;
#define NAME_h3__InBlock     "InBlock"

// 출력
typedef struct _h3__OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 0, Length 6
    char    offerho1            [   7];    char    _offerho1            ;    // [long  ,    7] 매도호가1                      StartPos 7, Length 7
    char    bidho1              [   7];    char    _bidho1              ;    // [long  ,    7] 매수호가1                      StartPos 15, Length 7
    char    offerrem1           [   9];    char    _offerrem1           ;    // [long  ,    9] 매도호가잔량1                  StartPos 23, Length 9
    char    bidrem1             [   9];    char    _bidrem1             ;    // [long  ,    9] 매수호가잔량1                  StartPos 33, Length 9
    char    lp_offerho1         [   9];    char    _lp_offerho1         ;    // [long  ,    9] LP매도호가수량1                StartPos 43, Length 9
    char    lp_bidho1           [   9];    char    _lp_bidho1           ;    // [long  ,    9] LP매수호가수량1                StartPos 53, Length 9
    char    offerho2            [   7];    char    _offerho2            ;    // [long  ,    7] 매도호가2                      StartPos 63, Length 7
    char    bidho2              [   7];    char    _bidho2              ;    // [long  ,    7] 매수호가2                      StartPos 71, Length 7
    char    offerrem2           [   9];    char    _offerrem2           ;    // [long  ,    9] 매도호가잔량2                  StartPos 79, Length 9
    char    bidrem2             [   9];    char    _bidrem2             ;    // [long  ,    9] 매수호가잔량2                  StartPos 89, Length 9
    char    lp_offerho2         [   9];    char    _lp_offerho2         ;    // [long  ,    9] LP매도호가수량2                StartPos 99, Length 9
    char    lp_bidho2           [   9];    char    _lp_bidho2           ;    // [long  ,    9] LP매수호가수량2                StartPos 109, Length 9
    char    offerho3            [   7];    char    _offerho3            ;    // [long  ,    7] 매도호가3                      StartPos 119, Length 7
    char    bidho3              [   7];    char    _bidho3              ;    // [long  ,    7] 매수호가3                      StartPos 127, Length 7
    char    offerrem3           [   9];    char    _offerrem3           ;    // [long  ,    9] 매도호가잔량3                  StartPos 135, Length 9
    char    bidrem3             [   9];    char    _bidrem3             ;    // [long  ,    9] 매수호가잔량3                  StartPos 145, Length 9
    char    lp_offerho3         [   9];    char    _lp_offerho3         ;    // [long  ,    9] LP매도호가수량3                StartPos 155, Length 9
    char    lp_bidho3           [   9];    char    _lp_bidho3           ;    // [long  ,    9] LP매수호가수량3                StartPos 165, Length 9
    char    offerho4            [   7];    char    _offerho4            ;    // [long  ,    7] 매도호가4                      StartPos 175, Length 7
    char    bidho4              [   7];    char    _bidho4              ;    // [long  ,    7] 매수호가4                      StartPos 183, Length 7
    char    offerrem4           [   9];    char    _offerrem4           ;    // [long  ,    9] 매도호가잔량4                  StartPos 191, Length 9
    char    bidrem4             [   9];    char    _bidrem4             ;    // [long  ,    9] 매수호가잔량4                  StartPos 201, Length 9
    char    lp_offerho4         [   9];    char    _lp_offerho4         ;    // [long  ,    9] LP매도호가수량4                StartPos 211, Length 9
    char    lp_bidho4           [   9];    char    _lp_bidho4           ;    // [long  ,    9] LP매수호가수량4                StartPos 221, Length 9
    char    offerho5            [   7];    char    _offerho5            ;    // [long  ,    7] 매도호가5                      StartPos 231, Length 7
    char    bidho5              [   7];    char    _bidho5              ;    // [long  ,    7] 매수호가5                      StartPos 239, Length 7
    char    offerrem5           [   9];    char    _offerrem5           ;    // [long  ,    9] 매도호가잔량5                  StartPos 247, Length 9
    char    bidrem5             [   9];    char    _bidrem5             ;    // [long  ,    9] 매수호가잔량5                  StartPos 257, Length 9
    char    lp_offerho5         [   9];    char    _lp_offerho5         ;    // [long  ,    9] LP매도호가수량5                StartPos 267, Length 9
    char    lp_bidho5           [   9];    char    _lp_bidho5           ;    // [long  ,    9] LP매수호가수량5                StartPos 277, Length 9
    char    offerho6            [   7];    char    _offerho6            ;    // [long  ,    7] 매도호가6                      StartPos 287, Length 7
    char    bidho6              [   7];    char    _bidho6              ;    // [long  ,    7] 매수호가6                      StartPos 295, Length 7
    char    offerrem6           [   9];    char    _offerrem6           ;    // [long  ,    9] 매도호가잔량6                  StartPos 303, Length 9
    char    bidrem6             [   9];    char    _bidrem6             ;    // [long  ,    9] 매수호가잔량6                  StartPos 313, Length 9
    char    lp_offerho6         [   9];    char    _lp_offerho6         ;    // [long  ,    9] LP매도호가수량6                StartPos 323, Length 9
    char    lp_bidho6           [   9];    char    _lp_bidho6           ;    // [long  ,    9] LP매수호가수량6                StartPos 333, Length 9
    char    offerho7            [   7];    char    _offerho7            ;    // [long  ,    7] 매도호가7                      StartPos 343, Length 7
    char    bidho7              [   7];    char    _bidho7              ;    // [long  ,    7] 매수호가7                      StartPos 351, Length 7
    char    offerrem7           [   9];    char    _offerrem7           ;    // [long  ,    9] 매도호가잔량7                  StartPos 359, Length 9
    char    bidrem7             [   9];    char    _bidrem7             ;    // [long  ,    9] 매수호가잔량7                  StartPos 369, Length 9
    char    lp_offerho7         [   9];    char    _lp_offerho7         ;    // [long  ,    9] LP매도호가수량7                StartPos 379, Length 9
    char    lp_bidho7           [   9];    char    _lp_bidho7           ;    // [long  ,    9] LP매수호가수량7                StartPos 389, Length 9
    char    offerho8            [   7];    char    _offerho8            ;    // [long  ,    7] 매도호가8                      StartPos 399, Length 7
    char    bidho8              [   7];    char    _bidho8              ;    // [long  ,    7] 매수호가8                      StartPos 407, Length 7
    char    offerrem8           [   9];    char    _offerrem8           ;    // [long  ,    9] 매도호가잔량8                  StartPos 415, Length 9
    char    bidrem8             [   9];    char    _bidrem8             ;    // [long  ,    9] 매수호가잔량8                  StartPos 425, Length 9
    char    lp_offerho8         [   9];    char    _lp_offerho8         ;    // [long  ,    9] LP매도호가수량8                StartPos 435, Length 9
    char    lp_bidho8           [   9];    char    _lp_bidho8           ;    // [long  ,    9] LP매수호가수량8                StartPos 445, Length 9
    char    offerho9            [   7];    char    _offerho9            ;    // [long  ,    7] 매도호가9                      StartPos 455, Length 7
    char    bidho9              [   7];    char    _bidho9              ;    // [long  ,    7] 매수호가9                      StartPos 463, Length 7
    char    offerrem9           [   9];    char    _offerrem9           ;    // [long  ,    9] 매도호가잔량9                  StartPos 471, Length 9
    char    bidrem9             [   9];    char    _bidrem9             ;    // [long  ,    9] 매수호가잔량9                  StartPos 481, Length 9
    char    lp_offerho9         [   9];    char    _lp_offerho9         ;    // [long  ,    9] LP매도호가수량9                StartPos 491, Length 9
    char    lp_bidho9           [   9];    char    _lp_bidho9           ;    // [long  ,    9] LP매수호가수량9                StartPos 501, Length 9
    char    offerho10           [   7];    char    _offerho10           ;    // [long  ,    7] 매도호가10                     StartPos 511, Length 7
    char    bidho10             [   7];    char    _bidho10             ;    // [long  ,    7] 매수호가10                     StartPos 519, Length 7
    char    offerrem10          [   9];    char    _offerrem10          ;    // [long  ,    9] 매도호가잔량10                 StartPos 527, Length 9
    char    bidrem10            [   9];    char    _bidrem10            ;    // [long  ,    9] 매수호가잔량10                 StartPos 537, Length 9
    char    lp_offerho10        [   9];    char    _lp_offerho10        ;    // [long  ,    9] LP매도호가수량10               StartPos 547, Length 9
    char    lp_bidho10          [   9];    char    _lp_bidho10          ;    // [long  ,    9] LP매수호가수량10               StartPos 557, Length 9
    char    totofferrem         [   9];    char    _totofferrem         ;    // [long  ,    9] 총매도호가잔량                 StartPos 567, Length 9
    char    totbidrem           [   9];    char    _totbidrem           ;    // [long  ,    9] 총매수호가잔량                 StartPos 577, Length 9
    char    donsigubun          [   1];    char    _donsigubun          ;    // [string,    1] 동시호가구분                   StartPos 587, Length 1
    char    spread              [   6];    char    _spread              ;    // [float ,  6.2] 스프레드                       StartPos 589, Length 6
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 596, Length 6
} h3__OutBlock, *LPh3__OutBlock;
#define NAME_h3__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
