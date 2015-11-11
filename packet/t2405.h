///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물옵션호가잔량비율챠트(t2405) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t2405     "t2405"

// 기본입력
typedef struct _t2405InBlock
{
    char    focode              [   8];    char    _focode              ;    // [string,    8] 단축코드                       StartPos 0, Length 8
    char    bgubun              [   1];    char    _bgubun              ;    // [string,    1] 분구분                         StartPos 9, Length 1
    char    nmin                [   2];    char    _nmin                ;    // [string,    2] N분                            StartPos 11, Length 2
    char    etime               [   4];    char    _etime               ;    // [string,    4] 종료시간                       StartPos 14, Length 4
    char    hgubun              [   1];    char    _hgubun              ;    // [string,    1] 호가구분                       StartPos 19, Length 1
    char    cnt                 [   3];    char    _cnt                 ;    // [string,    3] 조회건수                       StartPos 21, Length 3
    char    cts_time            [   6];    char    _cts_time            ;    // [string,    6] 시간CTS                        StartPos 25, Length 6
} t2405InBlock, *LPt2405InBlock;
#define NAME_t2405InBlock     "t2405InBlock"

// 출력
typedef struct _t2405OutBlock
{
    char    mdvolume            [  12];    char    _mdvolume            ;    // [double,   12] 매도체결수량                   StartPos 0, Length 12
    char    mdchecnt            [   8];    char    _mdchecnt            ;    // [long  ,    8] 매도체결건수                   StartPos 13, Length 8
    char    msvolume            [  12];    char    _msvolume            ;    // [double,   12] 매수체결수량                   StartPos 22, Length 12
    char    mschecnt            [   8];    char    _mschecnt            ;    // [long  ,    8] 매수체결건수                   StartPos 35, Length 8
    char    cts_time            [   6];    char    _cts_time            ;    // [string,    6] 시간CTS                        StartPos 44, Length 6
} t2405OutBlock, *LPt2405OutBlock;
#define NAME_t2405OutBlock     "t2405OutBlock"

// 출력1, occurs
typedef struct _t2405OutBlock1
{
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 0, Length 6
    char    price               [   6];    char    _price               ;    // [float ,  6.2] 현재가                         StartPos 7, Length 6
    char    sign                [   1];    char    _sign                ;    // [string,    1] 전일대비구분                   StartPos 14, Length 1
    char    change              [   6];    char    _change              ;    // [float ,  6.2] 전일대비                       StartPos 16, Length 6
    char    volume              [  12];    char    _volume              ;    // [double,   12] 누적거래량                     StartPos 23, Length 12
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 체결수량                       StartPos 36, Length 8
    char    offerho1            [   6];    char    _offerho1            ;    // [float ,  6.2] 매도1호가                      StartPos 45, Length 6
    char    bidho1              [   6];    char    _bidho1              ;    // [float ,  6.2] 매수1호가                      StartPos 52, Length 6
    char    offerrem            [   8];    char    _offerrem            ;    // [long  ,    8] 매도수량                       StartPos 59, Length 8
    char    bidrem              [   8];    char    _bidrem              ;    // [long  ,    8] 매수수량                       StartPos 68, Length 8
    char    offercnt            [   8];    char    _offercnt            ;    // [long  ,    8] 매도건수                       StartPos 77, Length 8
    char    bidcnt              [   8];    char    _bidcnt              ;    // [long  ,    8] 매수건수                       StartPos 86, Length 8
    char    c_offerrem          [   8];    char    _c_offerrem          ;    // [long  ,    8] 매도증감수량                   StartPos 95, Length 8
    char    c_bidrem            [   8];    char    _c_bidrem            ;    // [long  ,    8] 매수증감수량                   StartPos 104, Length 8
    char    c_offercnt          [   8];    char    _c_offercnt          ;    // [long  ,    8] 매도증감건수                   StartPos 113, Length 8
    char    c_bidcnt            [   8];    char    _c_bidcnt            ;    // [long  ,    8] 매수증감건수                   StartPos 122, Length 8
    char    r_bidrem            [   6];    char    _r_bidrem            ;    // [float ,  6.2] 매수수량비율                   StartPos 131, Length 6
    char    r_bidcnt            [   6];    char    _r_bidcnt            ;    // [float ,  6.2] 매수건수비율                   StartPos 138, Length 6
    char    r_sign              [   1];    char    _r_sign              ;    // [string,    1] 매수비율구분                   StartPos 145, Length 1
    char    date                [   8];    char    _date                ;    // [string,    8] 일자                           StartPos 147, Length 8
} t2405OutBlock1, *LPt2405OutBlock1;
#define NAME_t2405OutBlock1     "t2405OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
