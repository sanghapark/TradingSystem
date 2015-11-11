///////////////////////////////////////////////////////////////////////////////////////////////////
// ETF현재가(시세)조회(t1901) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1901     "t1901"

// 기본입력
typedef struct _t1901InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 0, Length 6
} t1901InBlock, *LPt1901InBlock;
#define NAME_t1901InBlock     "t1901InBlock"

// 출력
typedef struct _t1901OutBlock
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] 한글명                         StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] 현재가                         StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] 전일대비                       StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] 등락율                         StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [float ,   12] 누적거래량                     StartPos 48, Length 12
    char    recprice            [   8];    char    _recprice            ;    // [long  ,    8] 기준가                         StartPos 61, Length 8
    char    avg                 [   8];    char    _avg                 ;    // [long  ,    8] 가중평균                       StartPos 70, Length 8
    char    uplmtprice          [   8];    char    _uplmtprice          ;    // [long  ,    8] 상한가                         StartPos 79, Length 8
    char    dnlmtprice          [   8];    char    _dnlmtprice          ;    // [long  ,    8] 하한가                         StartPos 88, Length 8
    char    jnilvolume          [  12];    char    _jnilvolume          ;    // [float ,   12] 전일거래량                     StartPos 97, Length 12
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
    char    flmtvol             [  12];    char    _flmtvol             ;    // [float ,   12] 외국인보유수량                 StartPos 214, Length 12
    char    per                 [   6];    char    _per                 ;    // [float ,  6.2] PER                            StartPos 227, Length 6
    char    listing             [  12];    char    _listing             ;    // [long  ,   12] 상장주식수(천)                 StartPos 234, Length 12
    char    jkrate              [   8];    char    _jkrate              ;    // [long  ,    8] 증거금율                       StartPos 247, Length 8
    char    vol                 [   6];    char    _vol                 ;    // [float ,  6.2] 회전율                         StartPos 256, Length 6
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 263, Length 6
    char    value               [  12];    char    _value               ;    // [long  ,   12] 누적거래대금                   StartPos 270, Length 12
    char    highyear            [   8];    char    _highyear            ;    // [long  ,    8] 연중최고가                     StartPos 283, Length 8
    char    highyeardate        [   8];    char    _highyeardate        ;    // [string,    8] 연중최고일자                   StartPos 292, Length 8
    char    lowyear             [   8];    char    _lowyear             ;    // [long  ,    8] 연중최저가                     StartPos 301, Length 8
    char    lowyeardate         [   8];    char    _lowyeardate         ;    // [string,    8] 연중최저일자                   StartPos 310, Length 8
    char    upname              [  20];    char    _upname              ;    // [string,   20] 업종명                         StartPos 319, Length 20
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] 업종코드                       StartPos 340, Length 3
    char    upprice             [   7];    char    _upprice             ;    // [float ,  7.2] 업종현재가                     StartPos 344, Length 7
    char    upsign              [   1];    char    _upsign              ;    // [string,    1] 업종전일비구분                 StartPos 352, Length 1
    char    upchange            [   6];    char    _upchange            ;    // [float ,  6.2] 업종전일대비                   StartPos 354, Length 6
    char    updiff              [   6];    char    _updiff              ;    // [float ,  6.2] 업종등락율                     StartPos 361, Length 6
    char    futname             [  20];    char    _futname             ;    // [string,   20] 선물최근월물명                 StartPos 368, Length 20
    char    futcode             [   8];    char    _futcode             ;    // [string,    8] 선물최근월물코드               StartPos 389, Length 8
    char    futprice            [   6];    char    _futprice            ;    // [float ,  6.2] 선물현재가                     StartPos 398, Length 6
    char    futsign             [   1];    char    _futsign             ;    // [string,    1] 선물전일비구분                 StartPos 405, Length 1
    char    futchange           [   6];    char    _futchange           ;    // [float ,  6.2] 선물전일대비                   StartPos 407, Length 6
    char    futdiff             [   6];    char    _futdiff             ;    // [float ,  6.2] 선물등락율                     StartPos 414, Length 6
    char    nav                 [   8];    char    _nav                 ;    // [float ,  8.2] NAV                            StartPos 421, Length 8
    char    navsign             [   1];    char    _navsign             ;    // [string,    1] NAV전일대비구분                StartPos 430, Length 1
    char    navchange           [   8];    char    _navchange           ;    // [float ,  8.2] NAV전일대비                    StartPos 432, Length 8
    char    navdiff             [   6];    char    _navdiff             ;    // [float ,  6.2] NAV등락율                      StartPos 441, Length 6
    char    cocrate             [   6];    char    _cocrate             ;    // [float ,  6.2] 추적오차율                     StartPos 448, Length 6
    char    kasis               [   6];    char    _kasis               ;    // [float ,  6.2] 괴리율                         StartPos 455, Length 6
    char    subprice            [  10];    char    _subprice            ;    // [long  ,   10] 대용가                         StartPos 462, Length 10
    char    offerno1            [   6];    char    _offerno1            ;    // [string,    6] 매도증권사코드1                StartPos 473, Length 6
    char    bidno1              [   6];    char    _bidno1              ;    // [string,    6] 매수증권사코드1                StartPos 480, Length 6
    char    dvol1               [   8];    char    _dvol1               ;    // [long  ,    8] 총매도수량1                    StartPos 487, Length 8
    char    svol1               [   8];    char    _svol1               ;    // [long  ,    8] 총매수수량1                    StartPos 496, Length 8
    char    dcha1               [   8];    char    _dcha1               ;    // [long  ,    8] 매도증감1                      StartPos 505, Length 8
    char    scha1               [   8];    char    _scha1               ;    // [long  ,    8] 매수증감1                      StartPos 514, Length 8
    char    ddiff1              [   6];    char    _ddiff1              ;    // [float ,  6.2] 매도비율1                      StartPos 523, Length 6
    char    sdiff1              [   6];    char    _sdiff1              ;    // [float ,  6.2] 매수비율1                      StartPos 530, Length 6
    char    offerno2            [   6];    char    _offerno2            ;    // [string,    6] 매도증권사코드2                StartPos 537, Length 6
    char    bidno2              [   6];    char    _bidno2              ;    // [string,    6] 매수증권사코드2                StartPos 544, Length 6
    char    dvol2               [   8];    char    _dvol2               ;    // [long  ,    8] 총매도수량2                    StartPos 551, Length 8
    char    svol2               [   8];    char    _svol2               ;    // [long  ,    8] 총매수수량2                    StartPos 560, Length 8
    char    dcha2               [   8];    char    _dcha2               ;    // [long  ,    8] 매도증감2                      StartPos 569, Length 8
    char    scha2               [   8];    char    _scha2               ;    // [long  ,    8] 매수증감2                      StartPos 578, Length 8
    char    ddiff2              [   6];    char    _ddiff2              ;    // [float ,  6.2] 매도비율2                      StartPos 587, Length 6
    char    sdiff2              [   6];    char    _sdiff2              ;    // [float ,  6.2] 매수비율2                      StartPos 594, Length 6
    char    offerno3            [   6];    char    _offerno3            ;    // [string,    6] 매도증권사코드3                StartPos 601, Length 6
    char    bidno3              [   6];    char    _bidno3              ;    // [string,    6] 매수증권사코드3                StartPos 608, Length 6
    char    dvol3               [   8];    char    _dvol3               ;    // [long  ,    8] 총매도수량3                    StartPos 615, Length 8
    char    svol3               [   8];    char    _svol3               ;    // [long  ,    8] 총매수수량3                    StartPos 624, Length 8
    char    dcha3               [   8];    char    _dcha3               ;    // [long  ,    8] 매도증감3                      StartPos 633, Length 8
    char    scha3               [   8];    char    _scha3               ;    // [long  ,    8] 매수증감3                      StartPos 642, Length 8
    char    ddiff3              [   6];    char    _ddiff3              ;    // [float ,  6.2] 매도비율3                      StartPos 651, Length 6
    char    sdiff3              [   6];    char    _sdiff3              ;    // [float ,  6.2] 매수비율3                      StartPos 658, Length 6
    char    offerno4            [   6];    char    _offerno4            ;    // [string,    6] 매도증권사코드4                StartPos 665, Length 6
    char    bidno4              [   6];    char    _bidno4              ;    // [string,    6] 매수증권사코드4                StartPos 672, Length 6
    char    dvol4               [   8];    char    _dvol4               ;    // [long  ,    8] 총매도수량4                    StartPos 679, Length 8
    char    svol4               [   8];    char    _svol4               ;    // [long  ,    8] 총매수수량4                    StartPos 688, Length 8
    char    dcha4               [   8];    char    _dcha4               ;    // [long  ,    8] 매도증감4                      StartPos 697, Length 8
    char    scha4               [   8];    char    _scha4               ;    // [long  ,    8] 매수증감4                      StartPos 706, Length 8
    char    ddiff4              [   6];    char    _ddiff4              ;    // [float ,  6.2] 매도비율4                      StartPos 715, Length 6
    char    sdiff4              [   6];    char    _sdiff4              ;    // [float ,  6.2] 매수비율4                      StartPos 722, Length 6
    char    offerno5            [   6];    char    _offerno5            ;    // [string,    6] 매도증권사코드5                StartPos 729, Length 6
    char    bidno5              [   6];    char    _bidno5              ;    // [string,    6] 매수증권사코드5                StartPos 736, Length 6
    char    dvol5               [   8];    char    _dvol5               ;    // [long  ,    8] 총매도수량5                    StartPos 743, Length 8
    char    svol5               [   8];    char    _svol5               ;    // [long  ,    8] 총매수수량5                    StartPos 752, Length 8
    char    dcha5               [   8];    char    _dcha5               ;    // [long  ,    8] 매도증감5                      StartPos 761, Length 8
    char    scha5               [   8];    char    _scha5               ;    // [long  ,    8] 매수증감5                      StartPos 770, Length 8
    char    ddiff5              [   6];    char    _ddiff5              ;    // [float ,  6.2] 매도비율5                      StartPos 779, Length 6
    char    sdiff5              [   6];    char    _sdiff5              ;    // [float ,  6.2] 매수비율5                      StartPos 786, Length 6
    char    fwdvl               [  12];    char    _fwdvl               ;    // [long  ,   12] 외국계매도합계수량             StartPos 793, Length 12
    char    ftradmdcha          [  12];    char    _ftradmdcha          ;    // [long  ,   12] 외국계매도직전대비             StartPos 806, Length 12
    char    ftradmddiff         [   6];    char    _ftradmddiff         ;    // [float ,  6.2] 외국계매도비율                 StartPos 819, Length 6
    char    fwsvl               [  12];    char    _fwsvl               ;    // [long  ,   12] 외국계매수합계수량             StartPos 826, Length 12
    char    ftradmscha          [  12];    char    _ftradmscha          ;    // [long  ,   12] 외국계매수직전대비             StartPos 839, Length 12
    char    ftradmsdiff         [   6];    char    _ftradmsdiff         ;    // [float ,  6.2] 외국계매수비율                 StartPos 852, Length 6
} t1901OutBlock, *LPt1901OutBlock;
#define NAME_t1901OutBlock     "t1901OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
