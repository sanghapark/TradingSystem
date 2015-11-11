///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식현재가호가조회(t1101) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1101     "t1101"

// 기본입력
typedef struct _t1101InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
} t1101InBlock, *LPt1101InBlock;
#define NAME_t1101InBlock     "t1101InBlock"

// 출력
typedef struct _t1101OutBlock
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                         StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 48, Length 12
    char    jnilclose           [   8];    char    _jnilclose           ;    // [long  ,    8] 전일종가                       StartPos 61, Length 8
    char    offerho1            [   8];    char    _offerho1            ;    // [long  ,    8] 매도호가1                      StartPos 70, Length 8
    char    bidho1              [   8];    char    _bidho1              ;    // [long  ,    8] 매수호가1                      StartPos 79, Length 8
    char    offerrem1           [  12];    char    _offerrem1           ;    // [long  ,   12] 매도호가수량1                  StartPos 88, Length 12
    char    bidrem1             [  12];    char    _bidrem1             ;    // [long  ,   12] 매수호가수량1                  StartPos 101, Length 12
    char    preoffercha1        [  12];    char    _preoffercha1        ;    // [long  ,   12] 직전매도대비수량1              StartPos 114, Length 12
    char    prebidcha1          [  12];    char    _prebidcha1          ;    // [long  ,   12] 직전매수대비수량1              StartPos 127, Length 12
    char    offerho2            [   8];    char    _offerho2            ;    // [long  ,    8] 매도호가2                      StartPos 140, Length 8
    char    bidho2              [   8];    char    _bidho2              ;    // [long  ,    8] 매수호가2                      StartPos 149, Length 8
    char    offerrem2           [  12];    char    _offerrem2           ;    // [long  ,   12] 매도호가수량2                  StartPos 158, Length 12
    char    bidrem2             [  12];    char    _bidrem2             ;    // [long  ,   12] 매수호가수량2                  StartPos 171, Length 12
    char    preoffercha2        [  12];    char    _preoffercha2        ;    // [long  ,   12] 직전매도대비수량2              StartPos 184, Length 12
    char    prebidcha2          [  12];    char    _prebidcha2          ;    // [long  ,   12] 직전매수대비수량2              StartPos 197, Length 12
    char    offerho3            [   8];    char    _offerho3            ;    // [long  ,    8] 매도호가3                      StartPos 210, Length 8
    char    bidho3              [   8];    char    _bidho3              ;    // [long  ,    8] 매수호가3                      StartPos 219, Length 8
    char    offerrem3           [  12];    char    _offerrem3           ;    // [long  ,   12] 매도호가수량3                  StartPos 228, Length 12
    char    bidrem3             [  12];    char    _bidrem3             ;    // [long  ,   12] 매수호가수량3                  StartPos 241, Length 12
    char    preoffercha3        [  12];    char    _preoffercha3        ;    // [long  ,   12] 직전매도대비수량3              StartPos 254, Length 12
    char    prebidcha3          [  12];    char    _prebidcha3          ;    // [long  ,   12] 직전매수대비수량3              StartPos 267, Length 12
    char    offerho4            [   8];    char    _offerho4            ;    // [long  ,    8] 매도호가4                      StartPos 280, Length 8
    char    bidho4              [   8];    char    _bidho4              ;    // [long  ,    8] 매수호가4                      StartPos 289, Length 8
    char    offerrem4           [  12];    char    _offerrem4           ;    // [long  ,   12] 매도호가수량4                  StartPos 298, Length 12
    char    bidrem4             [  12];    char    _bidrem4             ;    // [long  ,   12] 매수호가수량4                  StartPos 311, Length 12
    char    preoffercha4        [  12];    char    _preoffercha4        ;    // [long  ,   12] 직전매도대비수량4              StartPos 324, Length 12
    char    prebidcha4          [  12];    char    _prebidcha4          ;    // [long  ,   12] 직전매수대비수량4              StartPos 337, Length 12
    char    offerho5            [   8];    char    _offerho5            ;    // [long  ,    8] 매도호가5                      StartPos 350, Length 8
    char    bidho5              [   8];    char    _bidho5              ;    // [long  ,    8] 매수호가5                      StartPos 359, Length 8
    char    offerrem5           [  12];    char    _offerrem5           ;    // [long  ,   12] 매도호가수량5                  StartPos 368, Length 12
    char    bidrem5             [  12];    char    _bidrem5             ;    // [long  ,   12] 매수호가수량5                  StartPos 381, Length 12
    char    preoffercha5        [  12];    char    _preoffercha5        ;    // [long  ,   12] 직전매도대비수량5              StartPos 394, Length 12
    char    prebidcha5          [  12];    char    _prebidcha5          ;    // [long  ,   12] 직전매수대비수량5              StartPos 407, Length 12
    char    offerho6            [   8];    char    _offerho6            ;    // [long  ,    8] 매도호가6                      StartPos 420, Length 8
    char    bidho6              [   8];    char    _bidho6              ;    // [long  ,    8] 매수호가6                      StartPos 429, Length 8
    char    offerrem6           [  12];    char    _offerrem6           ;    // [long  ,   12] 매도호가수량6                  StartPos 438, Length 12
    char    bidrem6             [  12];    char    _bidrem6             ;    // [long  ,   12] 매수호가수량6                  StartPos 451, Length 12
    char    preoffercha6        [  12];    char    _preoffercha6        ;    // [long  ,   12] 직전매도대비수량6              StartPos 464, Length 12
    char    prebidcha6          [  12];    char    _prebidcha6          ;    // [long  ,   12] 직전매수대비수량6              StartPos 477, Length 12
    char    offerho7            [   8];    char    _offerho7            ;    // [long  ,    8] 매도호가7                      StartPos 490, Length 8
    char    bidho7              [   8];    char    _bidho7              ;    // [long  ,    8] 매수호가7                      StartPos 499, Length 8
    char    offerrem7           [  12];    char    _offerrem7           ;    // [long  ,   12] 매도호가수량7                  StartPos 508, Length 12
    char    bidrem7             [  12];    char    _bidrem7             ;    // [long  ,   12] 매수호가수량7                  StartPos 521, Length 12
    char    preoffercha7        [  12];    char    _preoffercha7        ;    // [long  ,   12] 직전매도대비수량7              StartPos 534, Length 12
    char    prebidcha7          [  12];    char    _prebidcha7          ;    // [long  ,   12] 직전매수대비수량7              StartPos 547, Length 12
    char    offerho8            [   8];    char    _offerho8            ;    // [long  ,    8] 매도호가8                      StartPos 560, Length 8
    char    bidho8              [   8];    char    _bidho8              ;    // [long  ,    8] 매수호가8                      StartPos 569, Length 8
    char    offerrem8           [  12];    char    _offerrem8           ;    // [long  ,   12] 매도호가수량8                  StartPos 578, Length 12
    char    bidrem8             [  12];    char    _bidrem8             ;    // [long  ,   12] 매수호가수량8                  StartPos 591, Length 12
    char    preoffercha8        [  12];    char    _preoffercha8        ;    // [long  ,   12] 직전매도대비수량8              StartPos 604, Length 12
    char    prebidcha8          [  12];    char    _prebidcha8          ;    // [long  ,   12] 직전매수대비수량8              StartPos 617, Length 12
    char    offerho9            [   8];    char    _offerho9            ;    // [long  ,    8] 매도호가9                      StartPos 630, Length 8
    char    bidho9              [   8];    char    _bidho9              ;    // [long  ,    8] 매수호가9                      StartPos 639, Length 8
    char    offerrem9           [  12];    char    _offerrem9           ;    // [long  ,   12] 매도호가수량9                  StartPos 648, Length 12
    char    bidrem9             [  12];    char    _bidrem9             ;    // [long  ,   12] 매수호가수량9                  StartPos 661, Length 12
    char    preoffercha9        [  12];    char    _preoffercha9        ;    // [long  ,   12] 직전매도대비수량9              StartPos 674, Length 12
    char    prebidcha9          [  12];    char    _prebidcha9          ;    // [long  ,   12] 직전매수대비수량9              StartPos 687, Length 12
    char    offerho10           [   8];    char    _offerho10           ;    // [long  ,    8] 매도호가10                     StartPos 700, Length 8
    char    bidho10             [   8];    char    _bidho10             ;    // [long  ,    8] 매수호가10                     StartPos 709, Length 8
    char    offerrem10          [  12];    char    _offerrem10          ;    // [long  ,   12] 매도호가수량10                 StartPos 718, Length 12
    char    bidrem10            [  12];    char    _bidrem10            ;    // [long  ,   12] 매수호가수량10                 StartPos 731, Length 12
    char    preoffercha10       [  12];    char    _preoffercha10       ;    // [long  ,   12] 직전매도대비수량10             StartPos 744, Length 12
    char    prebidcha10         [  12];    char    _prebidcha10         ;    // [long  ,   12] 직전매수대비수량10             StartPos 757, Length 12
    char    offer               [  12];    char    _offer               ;    // [long  ,   12] 매도호가수량합                 StartPos 770, Length 12
    char    bid                 [  12];    char    _bid                 ;    // [long  ,   12] 매수호가수량합                 StartPos 783, Length 12
    char    preoffercha         [  12];    char    _preoffercha         ;    // [long  ,   12] 직전매도대비수량합             StartPos 796, Length 12
    char    prebidcha           [  12];    char    _prebidcha           ;    // [long  ,   12] 직전매수대비수량합             StartPos 809, Length 12
    char    hotime              [   8];    char    _hotime              ;    // [string,    8] 수신시간                       StartPos 822, Length 8
    char    yeprice             [   8];    char    _yeprice             ;    // [long  ,    8] 예상체결가격                   StartPos 831, Length 8
    char    yevolume            [  12];    char    _yevolume            ;    // [long  ,   12] 예상체결수량                   StartPos 840, Length 12
    char    yesign              [   1];    char    _yesign              ;    // [string,    1] 예상체결전일구분               StartPos 853, Length 1
    char    yechange            [   8];    char    _yechange            ;    // [long  ,    8] 예상체결전일대비               StartPos 855, Length 8
    char    yediff              [   6];    char    _yediff              ;    // [float ,  6.2] 예상체결등락율                 StartPos 864, Length 6
    char    tmoffer             [  12];    char    _tmoffer             ;    // [long  ,   12] 시간외매도잔량                 StartPos 871, Length 12
    char    tmbid               [  12];    char    _tmbid               ;    // [long  ,   12] 시간외매수잔량                 StartPos 884, Length 12
    char    ho_status           [   1];    char    _ho_status           ;    // [string,    1] 동시구분                       StartPos 897, Length 1
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 899, Length 6
    char    uplmtprice          [   8];    char    _uplmtprice          ;    // [long  ,    8] 상한가                         StartPos 906, Length 8
    char    dnlmtprice          [   8];    char    _dnlmtprice          ;    // [long  ,    8] 하한가                         StartPos 915, Length 8
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 924, Length 8
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 933, Length 8
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 942, Length 8
} t1101OutBlock, *LPt1101OutBlock;
#define NAME_t1101OutBlock     "t1101OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
