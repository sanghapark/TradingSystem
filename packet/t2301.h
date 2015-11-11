///////////////////////////////////////////////////////////////////////////////////////////////////
// 옵션전광판(t2301) ( attr,block,headtype=A )
#ifndef _t2301_H_
#define _t2301_H_

#pragma pack( push, 1 )

#define NAME_t2301     "t2301"

// 기본입력
typedef struct _t2301InBlock
{
    char    yyyymm              [   6];    char    _yyyymm              ;    // [string,    6] 월물                           StartPos 0, Length 6
} t2301InBlock, *LPt2301InBlock;
#define NAME_t2301InBlock     "t2301InBlock"

// 출력
typedef struct _t2301OutBlock
{
    char    histimpv            [   4];    char    _histimpv            ;    // [long  ,    4] 역사적변동성                   StartPos 0, Length 4
    char    jandatecnt          [   4];    char    _jandatecnt          ;    // [long  ,    4] 옵션잔존일                     StartPos 5, Length 4
    char    cimpv               [   6];    char    _cimpv               ;    // [float ,  6.3] 콜옵션대표IV                   StartPos 10, Length 6
    char    pimpv               [   6];    char    _pimpv               ;    // [float ,  6.3] 풋옵션대표IV                   StartPos 17, Length 6
    char    gmprice             [   6];    char    _gmprice             ;    // [float ,  6.2] 근월물현재가                   StartPos 24, Length 6
    char    gmsign              [   1];    char    _gmsign              ;    // [string,    1] 근월물전일대비구분             StartPos 31, Length 1
    char    gmchange            [   6];    char    _gmchange            ;    // [float ,  6.2] 근월물전일대비                 StartPos 33, Length 6
    char    gmdiff              [   6];    char    _gmdiff              ;    // [float ,  6.2] 근월물등락율                   StartPos 40, Length 6
    char    gmvolume            [  12];    char    _gmvolume            ;    // [long  ,   12] 근월물거래량                   StartPos 47, Length 12
    char    gmshcode            [   8];    char    _gmshcode            ;    // [string,    8] 근월물선물코드                 StartPos 60, Length 8
} t2301OutBlock, *LPt2301OutBlock;
#define NAME_t2301OutBlock     "t2301OutBlock"

// 출력1, occurs
typedef struct _t2301OutBlock1
{
    char    actprice            [   6];    char    _actprice            ;    // [float ,  6.2] 행사가                         StartPos 0, Length 6
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 콜옵션코드                     StartPos 7, Length 8
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                         StartPos 16, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 23, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                       StartPos 25, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 32, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 39, Length 12
    char    iv                  [   6];    char    _iv                  ;    // [float ,  6.2] IV                             StartPos 52, Length 6
    char    mgjv                [  12];    char    _mgjv                ;    // [long  ,   12] 미결제약정                     StartPos 59, Length 12
    char    mgjvupdn            [  12];    char    _mgjvupdn            ;    // [long  ,   12] 미결제약정증감                 StartPos 72, Length 12
    char    offerho1            [   6];    char    _offerho1            ;    // [float ,  6.2] 매도호가                       StartPos 85, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [float ,  6.2] 매수호가                       StartPos 92, Length 6
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 체결량                         StartPos 99, Length 12
    char    delt                [   6];    char    _delt                ;    // [float ,  6.4] 델타                           StartPos 112, Length 6
    char    gama                [   6];    char    _gama                ;    // [float ,  6.4] 감마                           StartPos 119, Length 6
    char    vega                [   6];    char    _vega                ;    // [float ,  6.4] 베가                           StartPos 126, Length 6
    char    ceta                [   6];    char    _ceta                ;    // [float ,  6.4] 쎄타                           StartPos 133, Length 6
    char    rhox                [   6];    char    _rhox                ;    // [float ,  6.4] 로우                           StartPos 140, Length 6
    char    theoryprice         [   6];    char    _theoryprice         ;    // [float ,  6.2] 이론가                         StartPos 147, Length 6
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재가치                       StartPos 154, Length 6
    char    timevl              [   6];    char    _timevl              ;    // [float ,  6.2] 시간가치                       StartPos 161, Length 6
    char    jvolume             [  12];    char    _jvolume             ;    // [long  ,   12] 잔고수량                       StartPos 168, Length 12
    char    parpl               [  12];    char    _parpl               ;    // [long  ,   12] 평가손익                       StartPos 181, Length 12
    char    jngo                [   6];    char    _jngo                ;    // [long  ,    6] 청산가능수량                   StartPos 194, Length 6
    char    offerrem1           [  12];    char    _offerrem1           ;    // [long  ,   12] 매도잔량                       StartPos 201, Length 12
    char    bidrem1             [  12];    char    _bidrem1             ;    // [long  ,   12] 매수잔량                       StartPos 214, Length 12
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                           StartPos 227, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                           StartPos 234, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                           StartPos 241, Length 6
    char    atmgubun            [   1];    char    _atmgubun            ;    // [string,    1] ATM구분                        StartPos 248, Length 1
    char    jisuconv            [   6];    char    _jisuconv            ;    // [float ,  6.2] 지수환산                       StartPos 250, Length 6
    char    value               [  12];    char    _value               ;    // [float ,   12] 거래대금                       StartPos 257, Length 12
} t2301OutBlock1, *LPt2301OutBlock1;
#define NAME_t2301OutBlock1     "t2301OutBlock1"

// 출력2, occurs
typedef struct _t2301OutBlock2
{
    char    actprice            [   6];    char    _actprice            ;    // [float ,  6.2] 행사가                         StartPos 0, Length 6
    char    optcode             [   8];    char    _optcode             ;    // [string,    8] 풋옵션코드                     StartPos 7, Length 8
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                         StartPos 16, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 23, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                       StartPos 25, Length 6
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 32, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 39, Length 12
    char    iv                  [   6];    char    _iv                  ;    // [float ,  6.2] IV                             StartPos 52, Length 6
    char    mgjv                [  12];    char    _mgjv                ;    // [long  ,   12] 미결제약정                     StartPos 59, Length 12
    char    mgjvupdn            [  12];    char    _mgjvupdn            ;    // [long  ,   12] 미결제약정증감                 StartPos 72, Length 12
    char    offerho1            [   6];    char    _offerho1            ;    // [float ,  6.2] 매도호가                       StartPos 85, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [float ,  6.2] 매수호가                       StartPos 92, Length 6
    char    cvolume             [  12];    char    _cvolume             ;    // [long  ,   12] 체결량                         StartPos 99, Length 12
    char    delt                [   6];    char    _delt                ;    // [float ,  6.4] 델타                           StartPos 112, Length 6
    char    gama                [   6];    char    _gama                ;    // [float ,  6.4] 감마                           StartPos 119, Length 6
    char    vega                [   6];    char    _vega                ;    // [float ,  6.4] 베가                           StartPos 126, Length 6
    char    ceta                [   6];    char    _ceta                ;    // [float ,  6.4] 쎄타                           StartPos 133, Length 6
    char    rhox                [   6];    char    _rhox                ;    // [float ,  6.4] 로우                           StartPos 140, Length 6
    char    theoryprice         [   6];    char    _theoryprice         ;    // [float ,  6.2] 이론가                         StartPos 147, Length 6
    char    impv                [   6];    char    _impv                ;    // [float ,  6.2] 내재가치                       StartPos 154, Length 6
    char    timevl              [   6];    char    _timevl              ;    // [float ,  6.2] 시간가치                       StartPos 161, Length 6
    char    jvolume             [  12];    char    _jvolume             ;    // [long  ,   12] 잔고수량                       StartPos 168, Length 12
    char    parpl               [  12];    char    _parpl               ;    // [long  ,   12] 평가손익                       StartPos 181, Length 12
    char    jngo                [   6];    char    _jngo                ;    // [long  ,    6] 청산가능수량                   StartPos 194, Length 6
    char    offerrem1           [  12];    char    _offerrem1           ;    // [long  ,   12] 매도잔량                       StartPos 201, Length 12
    char    bidrem1             [  12];    char    _bidrem1             ;    // [long  ,   12] 매수잔량                       StartPos 214, Length 12
    char    open                [   6];    char    _open                ;    // [float ,  6.2] 시가                           StartPos 227, Length 6
    char    high                [   6];    char    _high                ;    // [float ,  6.2] 고가                           StartPos 234, Length 6
    char    low                 [   6];    char    _low                 ;    // [float ,  6.2] 저가                           StartPos 241, Length 6
    char    atmgubun            [   1];    char    _atmgubun            ;    // [string,    1] ATM구분                        StartPos 248, Length 1
    char    jisuconv            [   6];    char    _jisuconv            ;    // [float ,  6.2] 지수환산                       StartPos 250, Length 6
    char    value               [  12];    char    _value               ;    // [float ,   12] 거래대금                       StartPos 257, Length 12
} t2301OutBlock2, *LPt2301OutBlock2;
#define NAME_t2301OutBlock2     "t2301OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
#endif