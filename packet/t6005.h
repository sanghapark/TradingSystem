///////////////////////////////////////////////////////////////////////////////////////////////////
// 증거금율별주문가능금액조회(t6005) ( base21=SONAQ201,headtype=B )
#pragma pack( push, 1 )

#define NAME_t6005     "t6005"

// 기본입력
typedef struct _t6005InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 5, Length 1
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 6, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 26, Length 8
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 34, Length 12
    char    hopemesu            [  13];    // [double, 13.2] 주문가                         StartPos 46, Length 13
    char    mechegb             [   2];    // [string,    2] 통신매체코드                   StartPos 59, Length 2
} t6005InBlock, *LPt6005InBlock;
#define NAME_t6005InBlock     "t6005InBlock"

// 기본출력
typedef struct _t6005OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 5, Length 1
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 6, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 26, Length 8
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 34, Length 12
    char    hopemesu            [  13];    // [double, 13.2] 주문가                         StartPos 46, Length 13
    char    mechegb             [   2];    // [string,    2] 통신매체코드                   StartPos 59, Length 2
} t6005OutBlock, *LPt6005OutBlock;
#define NAME_t6005OutBlock     "t6005OutBlock"

// 기본출력1
typedef struct _t6005OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accname             [  40];    // [string,   40] 계좌명                         StartPos 5, Length 40
    char    codename            [  40];    // [string,   40] 종목명                         StartPos 45, Length 40
    char    depoamt             [  16];    // [long  ,   16] 예수금                         StartPos 85, Length 16
    char    daeamt              [  16];    // [long  ,   16] 대용금액                       StartPos 101, Length 16
    char    cdamreuse           [  16];    // [long  ,   16] 신용담보재사용금액             StartPos 117, Length 16
    char    cashordamt          [  16];    // [long  ,   16] 현금주문가능금액               StartPos 133, Length 16
    char    orddae              [  16];    // [long  ,   16] 대용주문가능금액               StartPos 149, Length 16
    char    margincash          [  16];    // [long  ,   16] 현금증거금액                   StartPos 165, Length 16
    char    margindae           [  16];    // [long  ,   16] 대용증거금액                   StartPos 181, Length 16
    char    kospiamt            [  16];    // [long  ,   16] 거래소금액                     StartPos 197, Length 16
    char    kosdaqamt           [  16];    // [long  ,   16] 코스닥금액                     StartPos 213, Length 16
    char    d1cash              [  16];    // [long  ,   16] 추정예수금(D+1)                StartPos 229, Length 16
    char    d2cash              [  16];    // [long  ,   16] 추정예수금(D+2)                StartPos 245, Length 16
    char    chulcanamt          [  16];    // [long  ,   16] 출금가능금액                   StartPos 261, Length 16
    char    misuamt             [  16];    // [long  ,   16] 미수금액                       StartPos 277, Length 16
    char    susuryorate         [  11];    // [double, 11.8] 수수료율                       StartPos 293, Length 11
    char    addchamt            [  16];    // [long  ,   16] 추가징수금액                   StartPos 304, Length 16
    char    resuseamt           [  16];    // [long  ,   16] 재사용대상금액                 StartPos 320, Length 16
    char    cashresuseamt       [  16];    // [long  ,   16] 현금재사용대상금액             StartPos 336, Length 16
    char    usemarginrate       [   7];    // [double,  7.4] 이용사증거금률                 StartPos 352, Length 7
    char    daereuseamt         [  16];    // [long  ,   16] 대용재사용대상금액             StartPos 359, Length 16
    char    daeresuseamt        [   7];    // [double,  7.4] 종목증거금률                   StartPos 375, Length 7
    char    charate             [   7];    // [double,  7.4] 계좌증거금률                   StartPos 382, Length 7
    char    marginrate          [   7];    // [double,  7.4] 거래증거금률                   StartPos 389, Length 7
    char    susuryo             [  16];    // [long  ,   16] 수수료                         StartPos 396, Length 16
    char    ordamt50            [  16];    // [long  ,   16] 증거금률50퍼센트주문가능금액   StartPos 412, Length 16
    char    ordcashqty50        [  16];    // [long  ,   16] 증거금률50퍼센트주문가능수량   StartPos 428, Length 16
    char    ordamt30            [  16];    // [long  ,   16] 증거금률30퍼센트주문가능금액   StartPos 444, Length 16
    char    ordqty30            [  16];    // [long  ,   16] 증거금률30퍼센트주문가능수량   StartPos 460, Length 16
    char    ordamt40            [  16];    // [long  ,   16] 증거금률40퍼센트주문가능금액   StartPos 476, Length 16
    char    ordqty40            [  16];    // [long  ,   16] 증거금률40퍼센트주문가능수량   StartPos 492, Length 16
    char    ordamt100           [  16];    // [long  ,   16] 증거금률100퍼센트주문가능금액  StartPos 508, Length 16
    char    ordqty100           [  16];    // [long  ,   16] 증거금률100퍼센트주문가능수량  StartPos 524, Length 16
    char    ordcashamt100       [  16];    // [long  ,   16] 증거금률100퍼센트현금주문가능금 StartPos 540, Length 16
    char    ordcashqty100       [  16];    // [long  ,   16] 증거금률100퍼센트현금주문가능수 StartPos 556, Length 16
    char    reamt20             [  16];    // [long  ,   16] 증거금률20퍼센트재사용가능금액 StartPos 572, Length 16
    char    reamt30             [  16];    // [long  ,   16] 증거금률30퍼센트재사용가능금액 StartPos 588, Length 16
    char    reamt40             [  16];    // [long  ,   16] 증거금률40퍼센트재사용가능금액 StartPos 604, Length 16
    char    reamt100            [  16];    // [long  ,   16] 증거금률100퍼센트재사용가능금액 StartPos 620, Length 16
    char    memeqty             [  16];    // [long  ,   16] 주문가능수량                   StartPos 636, Length 16
    char    ordamt              [  16];    // [long  ,   16] 주문가능금액                   StartPos 652, Length 16
} t6005OutBlock1, *LPt6005OutBlock1;
#define NAME_t6005OutBlock1     "t6005OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
