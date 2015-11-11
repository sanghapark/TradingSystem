///////////////////////////////////////////////////////////////////////////////////////////////////
// 외인기관종목별동향(t1701) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1701     "t1701"

// 기본입력
typedef struct _t1701InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 종목코드                       StartPos 0, Length 6
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] 구분                           StartPos 7, Length 1
    char    fromdt              [   8];    char    _fromdt              ;    // [string,    8] 시작일자                       StartPos 9, Length 8
    char    todt                [   8];    char    _todt                ;    // [string,    8] 종료일자                       StartPos 18, Length 8
    char    prapp               [   3];    char    _prapp               ;    // [long  ,    3] PR적용                         StartPos 27, Length 3
    char    prgubun             [   1];    char    _prgubun             ;    // [string,    1] PR적용구분                     StartPos 31, Length 1
    char    orggubun            [   1];    char    _orggubun            ;    // [string,    1] 기관적용                       StartPos 33, Length 1
    char    frggubun            [   1];    char    _frggubun            ;    // [string,    1] 외인적용                       StartPos 35, Length 1
} t1701InBlock, *LPt1701InBlock;
#define NAME_t1701InBlock     "t1701InBlock"

// 출력, occurs
typedef struct _t1701OutBlock
{
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                           StartPos 0, Length 8
    char    close               [   8];    char    _close               ;    // [long  ,    8] 종가                           StartPos 9, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 18, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 20, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 29, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 36, Length 12
    char    psnvolume           [  12];    char    _psnvolume           ;    // [long  ,   12] 개인                           StartPos 49, Length 12
    char    orgvolume           [  12];    char    _orgvolume           ;    // [long  ,   12] 기관                           StartPos 62, Length 12
    char    frgvolume           [  12];    char    _frgvolume           ;    // [long  ,   12] 외국인                         StartPos 75, Length 12
    char    frgvolumesum        [  12];    char    _frgvolumesum        ;    // [long  ,   12] 외국계                         StartPos 88, Length 12
    char    pgmvolume           [  12];    char    _pgmvolume           ;    // [long  ,   12] 프로그램                       StartPos 101, Length 12
    char    listing             [  12];    char    _listing             ;    // [long  ,   12] 보유주식수                     StartPos 114, Length 12
    char    listupdn            [  12];    char    _listupdn            ;    // [long  ,   12] 발행증감                       StartPos 127, Length 12
    char    sjrate              [   6];    char    _sjrate              ;    // [float ,  6.2] 소진율                         StartPos 140, Length 6
} t1701OutBlock, *LPt1701OutBlock;
#define NAME_t1701OutBlock     "t1701OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
