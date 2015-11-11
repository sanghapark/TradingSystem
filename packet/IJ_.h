///////////////////////////////////////////////////////////////////////////////////////////////////
// 지수(IJ) ( attr,block )
#pragma pack( push, 1 )

#define NAME_IJ_     "IJ_"

// 입력
typedef struct _IJ__InBlock
{
    char    upcode              [   3];    // [string,    3] 업종코드                       StartPos 0, Length 3
} IJ__InBlock, *LPIJ__InBlock;
#define NAME_IJ__InBlock     "InBlock"

// 출력
typedef struct _IJ__OutBlock
{
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 0, Length 6
    char    jisu                [   8];    char    _jisu                ;    // [float ,  8.2] 지수                           StartPos 7, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 16, Length 1
    char    change              [   8];    char    _change              ;    // [float ,  8.2] 전일비                         StartPos 18, Length 8
    char    drate               [   6];    char    _drate               ;    // [float ,  6.2] 등락율                         StartPos 27, Length 6
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결량                         StartPos 34, Length 8
    char    volume              [   8];    char    _volume              ;    // [long  ,    8] 거래량                         StartPos 43, Length 8
    char    value               [   8];    char    _value               ;    // [long  ,    8] 거래대금                       StartPos 52, Length 8
    char    upjo                [   4];    char    _upjo                ;    // [long  ,    4] 상한종목수                     StartPos 61, Length 4
    char    highjo              [   4];    char    _highjo              ;    // [long  ,    4] 상승종목수                     StartPos 66, Length 4
    char    unchgjo             [   4];    char    _unchgjo             ;    // [long  ,    4] 보합종목수                     StartPos 71, Length 4
    char    lowjo               [   4];    char    _lowjo               ;    // [long  ,    4] 하락종목수                     StartPos 76, Length 4
    char    downjo              [   4];    char    _downjo              ;    // [long  ,    4] 하한종목수                     StartPos 81, Length 4
    char    upjrate             [   6];    char    _upjrate             ;    // [float ,  6.2] 상승종목비율                   StartPos 86, Length 6
    char    openjisu            [   8];    char    _openjisu            ;    // [float ,  8.2] 시가지수                       StartPos 93, Length 8
    char    opentime            [   6];    char    _opentime            ;    // [string,    6] 시가시간                       StartPos 102, Length 6
    char    highjisu            [   8];    char    _highjisu            ;    // [float ,  8.2] 고가지수                       StartPos 109, Length 8
    char    hightime            [   6];    char    _hightime            ;    // [string,    6] 고가시간                       StartPos 118, Length 6
    char    lowjisu             [   8];    char    _lowjisu             ;    // [float ,  8.2] 저가지수                       StartPos 125, Length 8
    char    lowtime             [   6];    char    _lowtime             ;    // [string,    6] 저가시간                       StartPos 134, Length 6
    char    frgsvolume          [   8];    char    _frgsvolume          ;    // [long  ,    8] 외인순매수수량                 StartPos 141, Length 8
    char    orgsvolume          [   8];    char    _orgsvolume          ;    // [long  ,    8] 기관순매수수량                 StartPos 150, Length 8
    char    frgsvalue           [  10];    char    _frgsvalue           ;    // [long  ,   10] 외인순매수금액                 StartPos 159, Length 10
    char    orgsvalue           [  10];    char    _orgsvalue           ;    // [long  ,   10] 기관순매수금액                 StartPos 170, Length 10
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] 업종코드                       StartPos 181, Length 3
} IJ__OutBlock, *LPIJ__OutBlock;
#define NAME_IJ__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
