///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW거래량상위(t1961) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1961     "t1961"

// 기본입력
typedef struct _t1961InBlock
{
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 당일전일(0:당일1:전일)         StartPos 0, Length 1
    char    ggubun              [   2];    char    _ggubun              ;    // [string,    2] 권리유형구분(00:EX01:콜02:풋'': StartPos 2, Length 2
    char    itemcode            [  12];    char    _itemcode            ;    // [string,   12] 기초자산종목                   StartPos 5, Length 12
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 조회만기일                     StartPos 18, Length 8
    char    exgubun             [   6];    char    _exgubun             ;    // [string,    6] 대상제외                       StartPos 27, Length 6
    char    sprice              [   8];    char    _sprice              ;    // [long  ,    8] 시작가격                       StartPos 34, Length 8
    char    eprice              [   8];    char    _eprice              ;    // [long  ,    8] 종료가격                       StartPos 43, Length 8
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 거래량                         StartPos 52, Length 12
    char    sjanday             [   8];    char    _sjanday             ;    // [long  ,    8] 잔존시작일수                   StartPos 65, Length 8
    char    ejanday             [   8];    char    _ejanday             ;    // [long  ,    8] 잔존종료일수                   StartPos 74, Length 8
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 83, Length 4
} t1961InBlock, *LPt1961InBlock;
#define NAME_t1961InBlock     "t1961InBlock"

// 출력
typedef struct _t1961OutBlock
{
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                            StartPos 0, Length 4
} t1961OutBlock, *LPt1961OutBlock;
#define NAME_t1961OutBlock     "t1961OutBlock"

// 출력1, occurs
typedef struct _t1961OutBlock1
{
    char    hname               [  40];    char    _hname               ;    // [string,   40] 한글명                         StartPos 0, Length 40
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 41, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 50, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 52, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 61, Length 6
    char    volume              [  12];    char    _volume              ;    // [double,   12] 누적거래량                     StartPos 68, Length 12
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [double,   12] 전일거래량                     StartPos 81, Length 12
    char    elwexec             [  10];    char    _elwexec             ;    // [double, 10.2] 행사가                         StartPos 94, Length 10
    char    convrate            [  12];    char    _convrate            ;    // [double, 12.4] 전환비율                       StartPos 105, Length 12
    char    lastdate            [   8];    char    _lastdate            ;    // [string,    8] 만기일                         StartPos 118, Length 8
    char    itemcode            [  12];    char    _itemcode            ;    // [string,   12] 기초자산종목코드               StartPos 127, Length 12
    char    itemshcode          [   9];    char    _itemshcode          ;    // [string,    9] 기초자산단축코드               StartPos 140, Length 9
    char    itemname            [  20];    char    _itemname            ;    // [string,   20] 기초자산종목명                 StartPos 150, Length 20
    char    itemprice           [  10];    char    _itemprice           ;    // [string,   10] 기초자산현재가                 StartPos 171, Length 10
    char    itemsign            [   1];    char    _itemsign            ;    // [string,    1] 기초자산대비구분               StartPos 182, Length 1
    char    itemchange          [  10];    char    _itemchange          ;    // [string,   10] 기초자산전일대비               StartPos 184, Length 10
    char    itemdiff            [   6];    char    _itemdiff            ;    // [double,  6.2] 기초자산등락율                 StartPos 195, Length 6
    char    elwshcode           [   6];    char    _elwshcode           ;    // [string,    6] ELW종목코드                    StartPos 202, Length 6
} t1961OutBlock1, *LPt1961OutBlock1;
#define NAME_t1961OutBlock1     "t1961OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
