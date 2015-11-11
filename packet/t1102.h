///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식현재가(시세)조회(t1102) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1102     "t1102"

// 기본입력
typedef struct _t1102InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
} t1102InBlock, *LPt1102InBlock;
#define NAME_t1102InBlock     "t1102InBlock"

// 출력
typedef struct _t1102OutBlock
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                         StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] 누적거래량                     StartPos 48, Length 12
    char    recprice            [   8];    char    _recprice            ;    // [long  ,    8] 기준가                         StartPos 61, Length 8
    char    avg                 [   8];    char    _avg                 ;    // [long  ,    8] 가중평균                       StartPos 70, Length 8
    char    uplmtprice          [   8];    char    _uplmtprice          ;    // [long  ,    8] 상한가                         StartPos 79, Length 8
    char    dnlmtprice          [   8];    char    _dnlmtprice          ;    // [long  ,    8] 하한가                         StartPos 88, Length 8
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [long  ,   12] 전일거래량                     StartPos 97, Length 12
    char    volumediff          [  12];    char    _volumediff          ;    // [long  ,   12] 거래량차                       StartPos 110, Length 12
    char    open                [   8];    char    _open                ;    // [long  ,    8] 시가                           StartPos 123, Length 8
    char    opentime            [   6];    char    _opentime            ;    // [string,    6] 시가시간                       StartPos 132, Length 6
    char    high                [   8];    char    _high                ;    // [long  ,    8] 고가                           StartPos 139, Length 8
    char    hightime            [   6];    char    _hightime            ;    // [string,    6] 고가시간                       StartPos 148, Length 6
    char    low                 [   8];    char    _low                 ;    // [long  ,    8] 저가                           StartPos 155, Length 8
    char    lowtime             [   6];    char    _lowtime             ;    // [string,    6] 저가시간                       StartPos 164, Length 6
    char    high52w             [   8];    char    _high52w             ;    // [long  ,    8] 52최고가                       StartPos 171, Length 8
    char    high52wdate         [   8];    char    _high52wdate         ;    // [string,    8] 52최고가일                     StartPos 180, Length 8
    char    low52w              [   8];    char    _low52w              ;    // [long  ,    8] 52최저가                       StartPos 189, Length 8
    char    low52wdate          [   8];    char    _low52wdate          ;    // [string,    8] 52최저가일                     StartPos 198, Length 8
    char    exhratio            [   6];    char    _exhratio            ;    // [float ,  6.2] 소진율                         StartPos 207, Length 6
    char    per                 [   6];    char    _per                 ;    // [float ,  6.2] PER                            StartPos 214, Length 6
    char    pbrx                [   6];    char    _pbrx                ;    // [float ,  6.2] PBRX                           StartPos 221, Length 6
    char    listing             [  12];    char    _listing             ;    // [long  ,   12] 상장주식수(천)                 StartPos 228, Length 12
    char    jkrate              [   8];    char    _jkrate              ;    // [long  ,    8] 증거금율                       StartPos 241, Length 8
    char    memedan             [   5];    char    _memedan             ;    // [string,    5] 수량단위                       StartPos 250, Length 5
    char    offernocd1          [   3];    char    _offernocd1          ;    // [string,    3] 매도증권사코드1                StartPos 256, Length 3
    char    bidnocd1            [   3];    char    _bidnocd1            ;    // [string,    3] 매수증권사코드1                StartPos 260, Length 3
    char    offerno1            [   6];    char    _offerno1            ;    // [string,    6] 매도증권사명1                  StartPos 264, Length 6
    char    bidno1              [   6];    char    _bidno1              ;    // [string,    6] 매수증권사명1                  StartPos 271, Length 6
    char    dvol1               [   8];    char    _dvol1               ;    // [long  ,    8] 총매도수량1                    StartPos 278, Length 8
    char    svol1               [   8];    char    _svol1               ;    // [long  ,    8] 총매수수량1                    StartPos 287, Length 8
    char    dcha1               [   8];    char    _dcha1               ;    // [long  ,    8] 매도증감1                      StartPos 296, Length 8
    char    scha1               [   8];    char    _scha1               ;    // [long  ,    8] 매수증감1                      StartPos 305, Length 8
    char    ddiff1              [   6];    char    _ddiff1              ;    // [float ,  6.2] 매도비율1                      StartPos 314, Length 6
    char    sdiff1              [   6];    char    _sdiff1              ;    // [float ,  6.2] 매수비율1                      StartPos 321, Length 6
    char    offernocd2          [   3];    char    _offernocd2          ;    // [string,    3] 매도증권사코드2                StartPos 328, Length 3
    char    bidnocd2            [   3];    char    _bidnocd2            ;    // [string,    3] 매수증권사코드2                StartPos 332, Length 3
    char    offerno2            [   6];    char    _offerno2            ;    // [string,    6] 매도증권사명2                  StartPos 336, Length 6
    char    bidno2              [   6];    char    _bidno2              ;    // [string,    6] 매수증권사명2                  StartPos 343, Length 6
    char    dvol2               [   8];    char    _dvol2               ;    // [long  ,    8] 총매도수량2                    StartPos 350, Length 8
    char    svol2               [   8];    char    _svol2               ;    // [long  ,    8] 총매수수량2                    StartPos 359, Length 8
    char    dcha2               [   8];    char    _dcha2               ;    // [long  ,    8] 매도증감2                      StartPos 368, Length 8
    char    scha2               [   8];    char    _scha2               ;    // [long  ,    8] 매수증감2                      StartPos 377, Length 8
    char    ddiff2              [   6];    char    _ddiff2              ;    // [float ,  6.2] 매도비율2                      StartPos 386, Length 6
    char    sdiff2              [   6];    char    _sdiff2              ;    // [float ,  6.2] 매수비율2                      StartPos 393, Length 6
    char    offernocd3          [   3];    char    _offernocd3          ;    // [string,    3] 매도증권사코드3                StartPos 400, Length 3
    char    bidnocd3            [   3];    char    _bidnocd3            ;    // [string,    3] 매수증권사코드3                StartPos 404, Length 3
    char    offerno3            [   6];    char    _offerno3            ;    // [string,    6] 매도증권사명3                  StartPos 408, Length 6
    char    bidno3              [   6];    char    _bidno3              ;    // [string,    6] 매수증권사명3                  StartPos 415, Length 6
    char    dvol3               [   8];    char    _dvol3               ;    // [long  ,    8] 총매도수량3                    StartPos 422, Length 8
    char    svol3               [   8];    char    _svol3               ;    // [long  ,    8] 총매수수량3                    StartPos 431, Length 8
    char    dcha3               [   8];    char    _dcha3               ;    // [long  ,    8] 매도증감3                      StartPos 440, Length 8
    char    scha3               [   8];    char    _scha3               ;    // [long  ,    8] 매수증감3                      StartPos 449, Length 8
    char    ddiff3              [   6];    char    _ddiff3              ;    // [float ,  6.2] 매도비율3                      StartPos 458, Length 6
    char    sdiff3              [   6];    char    _sdiff3              ;    // [float ,  6.2] 매수비율3                      StartPos 465, Length 6
    char    offernocd4          [   3];    char    _offernocd4          ;    // [string,    3] 매도증권사코드4                StartPos 472, Length 3
    char    bidnocd4            [   3];    char    _bidnocd4            ;    // [string,    3] 매수증권사코드4                StartPos 476, Length 3
    char    offerno4            [   6];    char    _offerno4            ;    // [string,    6] 매도증권사명4                  StartPos 480, Length 6
    char    bidno4              [   6];    char    _bidno4              ;    // [string,    6] 매수증권사명4                  StartPos 487, Length 6
    char    dvol4               [   8];    char    _dvol4               ;    // [long  ,    8] 총매도수량4                    StartPos 494, Length 8
    char    svol4               [   8];    char    _svol4               ;    // [long  ,    8] 총매수수량4                    StartPos 503, Length 8
    char    dcha4               [   8];    char    _dcha4               ;    // [long  ,    8] 매도증감4                      StartPos 512, Length 8
    char    scha4               [   8];    char    _scha4               ;    // [long  ,    8] 매수증감4                      StartPos 521, Length 8
    char    ddiff4              [   6];    char    _ddiff4              ;    // [float ,  6.2] 매도비율4                      StartPos 530, Length 6
    char    sdiff4              [   6];    char    _sdiff4              ;    // [float ,  6.2] 매수비율4                      StartPos 537, Length 6
    char    offernocd5          [   3];    char    _offernocd5          ;    // [string,    3] 매도증권사코드5                StartPos 544, Length 3
    char    bidnocd5            [   3];    char    _bidnocd5            ;    // [string,    3] 매수증권사코드5                StartPos 548, Length 3
    char    offerno5            [   6];    char    _offerno5            ;    // [string,    6] 매도증권사명5                  StartPos 552, Length 6
    char    bidno5              [   6];    char    _bidno5              ;    // [string,    6] 매수증권사명5                  StartPos 559, Length 6
    char    dvol5               [   8];    char    _dvol5               ;    // [long  ,    8] 총매도수량5                    StartPos 566, Length 8
    char    svol5               [   8];    char    _svol5               ;    // [long  ,    8] 총매수수량5                    StartPos 575, Length 8
    char    dcha5               [   8];    char    _dcha5               ;    // [long  ,    8] 매도증감5                      StartPos 584, Length 8
    char    scha5               [   8];    char    _scha5               ;    // [long  ,    8] 매수증감5                      StartPos 593, Length 8
    char    ddiff5              [   6];    char    _ddiff5              ;    // [float ,  6.2] 매도비율5                      StartPos 602, Length 6
    char    sdiff5              [   6];    char    _sdiff5              ;    // [float ,  6.2] 매수비율5                      StartPos 609, Length 6
    char    fwdvl               [  12];    char    _fwdvl               ;    // [long  ,   12] 외국계매도합계수량             StartPos 616, Length 12
    char    ftradmdcha          [  12];    char    _ftradmdcha          ;    // [long  ,   12] 외국계매도직전대비             StartPos 629, Length 12
    char    ftradmddiff         [   6];    char    _ftradmddiff         ;    // [float ,  6.2] 외국계매도비율                 StartPos 642, Length 6
    char    fwsvl               [  12];    char    _fwsvl               ;    // [long  ,   12] 외국계매수합계수량             StartPos 649, Length 12
    char    ftradmscha          [  12];    char    _ftradmscha          ;    // [long  ,   12] 외국계매수직전대비             StartPos 662, Length 12
    char    ftradmsdiff         [   6];    char    _ftradmsdiff         ;    // [float ,  6.2] 외국계매수비율                 StartPos 675, Length 6
    char    vol                 [   6];    char    _vol                 ;    // [float ,  6.2] 회전율                         StartPos 682, Length 6
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 689, Length 6
    char    value               [  12];    char    _value               ;    // [long  ,   12] 누적거래대금                   StartPos 696, Length 12
    char    jvolume             [  12];    char    _jvolume             ;    // [long  ,   12] 전일동시간거래량               StartPos 709, Length 12
    char    highyear            [   8];    char    _highyear            ;    // [long  ,    8] 연중최고가                     StartPos 722, Length 8
    char    highyeardate        [   8];    char    _highyeardate        ;    // [string,    8] 연중최고일자                   StartPos 731, Length 8
    char    lowyear             [   8];    char    _lowyear             ;    // [long  ,    8] 연중최저가                     StartPos 740, Length 8
    char    lowyeardate         [   8];    char    _lowyeardate         ;    // [string,    8] 연중최저일자                   StartPos 749, Length 8
    char    target              [   8];    char    _target              ;    // [long  ,    8] 목표가                         StartPos 758, Length 8
    char    capital             [  12];    char    _capital             ;    // [long  ,   12] 자본금                         StartPos 767, Length 12
    char    abscnt              [  12];    char    _abscnt              ;    // [long  ,   12] 유동주식수                     StartPos 780, Length 12
    char    parprice            [   8];    char    _parprice            ;    // [long  ,    8] 액면가                         StartPos 793, Length 8
    char    gsmm                [   2];    char    _gsmm                ;    // [string,    2] 결산월                         StartPos 802, Length 2
    char    subprice            [   8];    char    _subprice            ;    // [long  ,    8] 대용가                         StartPos 805, Length 8
    char    total               [  12];    char    _total               ;    // [long  ,   12] 시가총액                       StartPos 814, Length 12
    char    listdate            [   8];    char    _listdate            ;    // [string,    8] 상장일                         StartPos 827, Length 8
    char    name                [  10];    char    _name                ;    // [string,   10] 전분기명                       StartPos 836, Length 10
    char    bfsales             [  12];    char    _bfsales             ;    // [long  ,   12] 전분기매출액                   StartPos 847, Length 12
    char    bfoperatingincome   [  12];    char    _bfoperatingincome   ;    // [long  ,   12] 전분기영업이익                 StartPos 860, Length 12
    char    bfordinaryincome    [  12];    char    _bfordinaryincome    ;    // [long  ,   12] 전분기경상이익                 StartPos 873, Length 12
    char    bfnetincome         [  12];    char    _bfnetincome         ;    // [long  ,   12] 전분기순이익                   StartPos 886, Length 12
    char    bfeps               [  13];    char    _bfeps               ;    // [float , 13.2] 전분기EPS                      StartPos 899, Length 13
    char    name2               [  10];    char    _name2               ;    // [string,   10] 전전분기명                     StartPos 913, Length 10
    char    bfsales2            [  12];    char    _bfsales2            ;    // [long  ,   12] 전전분기매출액                 StartPos 924, Length 12
    char    bfoperatingincome2  [  12];    char    _bfoperatingincome2  ;    // [long  ,   12] 전전분기영업이익               StartPos 937, Length 12
    char    bfordinaryincome2   [  12];    char    _bfordinaryincome2   ;    // [long  ,   12] 전전분기경상이익               StartPos 950, Length 12
    char    bfnetincome2        [  12];    char    _bfnetincome2        ;    // [long  ,   12] 전전분기순이익                 StartPos 963, Length 12
    char    bfeps2              [  13];    char    _bfeps2              ;    // [float , 13.2] 전전분기EPS                    StartPos 976, Length 13
    char    salert              [   7];    char    _salert              ;    // [float ,  7.2] 전년대비매출액                 StartPos 990, Length 7
    char    opert               [   7];    char    _opert               ;    // [float ,  7.2] 전년대비영업이익               StartPos 998, Length 7
    char    ordrt               [   7];    char    _ordrt               ;    // [float ,  7.2] 전년대비경상이익               StartPos 1006, Length 7
    char    netrt               [   7];    char    _netrt               ;    // [float ,  7.2] 전년대비순이익                 StartPos 1014, Length 7
    char    epsrt               [   7];    char    _epsrt               ;    // [float ,  7.2] 전년대비EPS                    StartPos 1022, Length 7
    char    info1               [  10];    char    _info1               ;    // [string,   10] 락구분                         StartPos 1030, Length 10
    char    info2               [  10];    char    _info2               ;    // [string,   10] 관리/급등구분                  StartPos 1041, Length 10
    char    info3               [  10];    char    _info3               ;    // [string,   10] 정지/연장구분                  StartPos 1052, Length 10
    char    info4               [  12];    char    _info4               ;    // [string,   12] 투자/불성실구분                StartPos 1063, Length 12
    char    janginfo            [  10];    char    _janginfo            ;    // [string,   10] 장구분                         StartPos 1076, Length 10
    char    t_per               [   6];    char    _t_per               ;    // [float ,  6.2] T.PER                          StartPos 1087, Length 6
} t1102OutBlock, *LPt1102OutBlock;
#define NAME_t1102OutBlock     "t1102OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
