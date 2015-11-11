///////////////////////////////////////////////////////////////////////////////////////////////////
// OTCBB체결(TS) ( attr,block )
#pragma pack( push, 1 )

#define NAME_TS_     "TS_"

// 입력
typedef struct _TS__InBlock
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
} TS__InBlock, *LPTS__InBlock;
#define NAME_TS__InBlock     "InBlock"

// 출력
typedef struct _TS__OutBlock
{
    char    chetime             [   6];    char    _chetime             ;    // [string,    6] 체결시간                       StartPos 0, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 7, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 9, Length 8
    char    drate               [   6];    char    _drate               ;    // [float ,  6.2] 등락율                         StartPos 18, Length 6
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 25, Length 8
    char    opentime            [   6];    char    _opentime            ;    // [string,    6] 시가시간                       StartPos 34, Length 6
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 41, Length 8
    char    hightime            [   6];    char    _hightime            ;    // [string,    6] 고가시간                       StartPos 50, Length 6
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 57, Length 8
    char    lowtime             [   6];    char    _lowtime             ;    // [string,    6] 저가시간                       StartPos 66, Length 6
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 73, Length 8
    char    cgubun              [   1];    char    _cgubun              ;    // [string,    1] 체결구분                       StartPos 82, Length 1
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결량                         StartPos 84, Length 8
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 93, Length 12
    char    value               [  12];    char    _value               ;    // [long  ,   12] 누적거래대금                   StartPos 106, Length 12
    char    mdvolume            [  12];    char    _mdvolume            ;    // [long  ,   12] 매도누적체결량                 StartPos 119, Length 12
    char    mdchecnt            [   8];    char    _mdchecnt            ;    // [long  ,    8] 매도누적체결건수               StartPos 132, Length 8
    char    msvolume            [  12];    char    _msvolume            ;    // [long  ,   12] 매수누적체결량                 StartPos 141, Length 12
    char    mschecnt            [   8];    char    _mschecnt            ;    // [long  ,    8] 매수누적체결건수               StartPos 154, Length 8
    char    cpower              [   9];    char    _cpower              ;    // [float ,  9.2] 체결강도                       StartPos 163, Length 9
    char    w_avrg              [   8];    char    _w_avrg              ;    // [long  ,    8] 가중평균가                     StartPos 173, Length 8
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 182, Length 6
} TS__OutBlock, *LPTS__OutBlock;
#define NAME_TS__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
