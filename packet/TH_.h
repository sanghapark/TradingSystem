///////////////////////////////////////////////////////////////////////////////////////////////////
// OTCBB호가(TH) ( attr,block )
#pragma pack( push, 1 )

#define NAME_TH_     "TH_"

// 입력
typedef struct _TH__InBlock
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
} TH__InBlock, *LPTH__InBlock;
#define NAME_TH__InBlock     "InBlock"

// 출력
typedef struct _TH__OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 0, Length 6
    char    offerho1            [   8];    char    _offerho1            ;    // [long  ,    8] 매도호가1                      StartPos 7, Length 8
    char    bidho1              [   8];    char    _bidho1              ;    // [long  ,    8] 매수호가1                      StartPos 16, Length 8
    char    offerrem1           [  12];    char    _offerrem1           ;    // [long  ,   12] 매도호가잔량1                  StartPos 25, Length 12
    char    bidrem1             [  12];    char    _bidrem1             ;    // [long  ,   12] 매수호가잔량1                  StartPos 38, Length 12
    char    preoffercha1        [  12];    char    _preoffercha1        ;    // [long  ,   12] 직전매도대비수량1              StartPos 51, Length 12
    char    prebidcha1          [  12];    char    _prebidcha1          ;    // [long  ,   12] 직전매수대비수량1              StartPos 64, Length 12
    char    offerho2            [   8];    char    _offerho2            ;    // [long  ,    8] 매도호가2                      StartPos 77, Length 8
    char    bidho2              [   8];    char    _bidho2              ;    // [long  ,    8] 매수호가2                      StartPos 86, Length 8
    char    offerrem2           [  12];    char    _offerrem2           ;    // [long  ,   12] 매도호가잔량2                  StartPos 95, Length 12
    char    bidrem2             [  12];    char    _bidrem2             ;    // [long  ,   12] 매수호가잔량2                  StartPos 108, Length 12
    char    preoffercha2        [  12];    char    _preoffercha2        ;    // [long  ,   12] 직전매도대비수량2              StartPos 121, Length 12
    char    prebidcha2          [  12];    char    _prebidcha2          ;    // [long  ,   12] 직전매수대비수량2              StartPos 134, Length 12
    char    offerho3            [   8];    char    _offerho3            ;    // [long  ,    8] 매도호가3                      StartPos 147, Length 8
    char    bidho3              [   8];    char    _bidho3              ;    // [long  ,    8] 매수호가3                      StartPos 156, Length 8
    char    offerrem3           [  12];    char    _offerrem3           ;    // [long  ,   12] 매도호가잔량3                  StartPos 165, Length 12
    char    bidrem3             [  12];    char    _bidrem3             ;    // [long  ,   12] 매수호가잔량3                  StartPos 178, Length 12
    char    preoffercha3        [  12];    char    _preoffercha3        ;    // [long  ,   12] 직전매도대비수량3              StartPos 191, Length 12
    char    prebidcha3          [  12];    char    _prebidcha3          ;    // [long  ,   12] 직전매수대비수량3              StartPos 204, Length 12
    char    offerho4            [   8];    char    _offerho4            ;    // [long  ,    8] 매도호가4                      StartPos 217, Length 8
    char    bidho4              [   8];    char    _bidho4              ;    // [long  ,    8] 매수호가4                      StartPos 226, Length 8
    char    offerrem4           [  12];    char    _offerrem4           ;    // [long  ,   12] 매도호가잔량4                  StartPos 235, Length 12
    char    bidrem4             [  12];    char    _bidrem4             ;    // [long  ,   12] 매수호가잔량4                  StartPos 248, Length 12
    char    preoffercha4        [  12];    char    _preoffercha4        ;    // [long  ,   12] 직전매도대비수량4              StartPos 261, Length 12
    char    prebidcha4          [  12];    char    _prebidcha4          ;    // [long  ,   12] 직전매수대비수량4              StartPos 274, Length 12
    char    offerho5            [   8];    char    _offerho5            ;    // [long  ,    8] 매도호가5                      StartPos 287, Length 8
    char    bidho5              [   8];    char    _bidho5              ;    // [long  ,    8] 매수호가5                      StartPos 296, Length 8
    char    offerrem5           [  12];    char    _offerrem5           ;    // [long  ,   12] 매도호가잔량5                  StartPos 305, Length 12
    char    bidrem5             [  12];    char    _bidrem5             ;    // [long  ,   12] 매수호가잔량5                  StartPos 318, Length 12
    char    preoffercha5        [  12];    char    _preoffercha5        ;    // [long  ,   12] 직전매도대비수량5              StartPos 331, Length 12
    char    prebidcha5          [  12];    char    _prebidcha5          ;    // [long  ,   12] 직전매수대비수량5              StartPos 344, Length 12
    char    offerho6            [   8];    char    _offerho6            ;    // [long  ,    8] 매도호가6                      StartPos 357, Length 8
    char    bidho6              [   8];    char    _bidho6              ;    // [long  ,    8] 매수호가6                      StartPos 366, Length 8
    char    offerrem6           [  12];    char    _offerrem6           ;    // [long  ,   12] 매도호가잔량6                  StartPos 375, Length 12
    char    bidrem6             [  12];    char    _bidrem6             ;    // [long  ,   12] 매수호가잔량6                  StartPos 388, Length 12
    char    preoffercha6        [  12];    char    _preoffercha6        ;    // [long  ,   12] 직전매도대비수량6              StartPos 401, Length 12
    char    prebidcha6          [  12];    char    _prebidcha6          ;    // [long  ,   12] 직전매수대비수량6              StartPos 414, Length 12
    char    offerho7            [   8];    char    _offerho7            ;    // [long  ,    8] 매도호가7                      StartPos 427, Length 8
    char    bidho7              [   8];    char    _bidho7              ;    // [long  ,    8] 매수호가7                      StartPos 436, Length 8
    char    offerrem7           [  12];    char    _offerrem7           ;    // [long  ,   12] 매도호가잔량7                  StartPos 445, Length 12
    char    bidrem7             [  12];    char    _bidrem7             ;    // [long  ,   12] 매수호가잔량7                  StartPos 458, Length 12
    char    preoffercha7        [  12];    char    _preoffercha7        ;    // [long  ,   12] 직전매도대비수량7              StartPos 471, Length 12
    char    prebidcha7          [  12];    char    _prebidcha7          ;    // [long  ,   12] 직전매수대비수량7              StartPos 484, Length 12
    char    offerho8            [   8];    char    _offerho8            ;    // [long  ,    8] 매도호가8                      StartPos 497, Length 8
    char    bidho8              [   8];    char    _bidho8              ;    // [long  ,    8] 매수호가8                      StartPos 506, Length 8
    char    offerrem8           [  12];    char    _offerrem8           ;    // [long  ,   12] 매도호가잔량8                  StartPos 515, Length 12
    char    bidrem8             [  12];    char    _bidrem8             ;    // [long  ,   12] 매수호가잔량8                  StartPos 528, Length 12
    char    preoffercha8        [  12];    char    _preoffercha8        ;    // [long  ,   12] 직전매도대비수량8              StartPos 541, Length 12
    char    prebidcha8          [  12];    char    _prebidcha8          ;    // [long  ,   12] 직전매수대비수량8              StartPos 554, Length 12
    char    offerho9            [   8];    char    _offerho9            ;    // [long  ,    8] 매도호가9                      StartPos 567, Length 8
    char    bidho9              [   8];    char    _bidho9              ;    // [long  ,    8] 매수호가9                      StartPos 576, Length 8
    char    offerrem9           [  12];    char    _offerrem9           ;    // [long  ,   12] 매도호가잔량9                  StartPos 585, Length 12
    char    bidrem9             [  12];    char    _bidrem9             ;    // [long  ,   12] 매수호가잔량9                  StartPos 598, Length 12
    char    preoffercha9        [  12];    char    _preoffercha9        ;    // [long  ,   12] 직전매도대비수량9              StartPos 611, Length 12
    char    prebidcha9          [  12];    char    _prebidcha9          ;    // [long  ,   12] 직전매수대비수량9              StartPos 624, Length 12
    char    offerho10           [   8];    char    _offerho10           ;    // [long  ,    8] 매도호가10                     StartPos 637, Length 8
    char    bidho10             [   8];    char    _bidho10             ;    // [long  ,    8] 매수호가10                     StartPos 646, Length 8
    char    offerrem10          [  12];    char    _offerrem10          ;    // [long  ,   12] 매도호가잔량10                 StartPos 655, Length 12
    char    bidrem10            [  12];    char    _bidrem10            ;    // [long  ,   12] 매수호가잔량10                 StartPos 668, Length 12
    char    preoffercha10       [  12];    char    _preoffercha10       ;    // [long  ,   12] 직전매도대비수량10             StartPos 681, Length 12
    char    prebidcha10         [  12];    char    _prebidcha10         ;    // [long  ,   12] 직전매수대비수량10             StartPos 694, Length 12
    char    totofferrem         [  12];    char    _totofferrem         ;    // [long  ,   12] 총매도호가잔량                 StartPos 707, Length 12
    char    totbidrem           [  12];    char    _totbidrem           ;    // [long  ,   12] 총매수호가잔량                 StartPos 720, Length 12
    char    preoffercha         [  12];    char    _preoffercha         ;    // [long  ,   12] 직전매도호가총대비수량         StartPos 733, Length 12
    char    prebidcha           [  12];    char    _prebidcha           ;    // [long  ,   12] 직전매수호가총대비수량         StartPos 746, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 759, Length 6
} TH__OutBlock, *LPTH__OutBlock;
#define NAME_TH__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
