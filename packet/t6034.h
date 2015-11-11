///////////////////////////////////////////////////////////////////////////////////////////////////
// 계좌예탁현황(선물/옵션)(t6034) ( base21=SONBQ105,headtype=B )
#pragma pack( push, 1 )

#define NAME_t6034     "t6034"

// 기본입력
typedef struct _t6034InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 비밀번호                       StartPos 25, Length 8
} t6034InBlock, *LPt6034InBlock;
#define NAME_t6034InBlock     "t6034InBlock"

// 기본출력
typedef struct _t6034OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 비밀번호                       StartPos 25, Length 8
} t6034OutBlock, *LPt6034OutBlock;
#define NAME_t6034OutBlock     "t6034OutBlock"

// 기본출력1
typedef struct _t6034OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accname             [  40];    // [string,   40] 계좌명                         StartPos 5, Length 40
    char    yetaktotamt         [  16];    // [long  ,   16] 예탁금총액                     StartPos 45, Length 16
    char    yesuamt             [  16];    // [long  ,   16] 예수금                         StartPos 61, Length 16
    char    dyamt               [  16];    // [long  ,   16] 대용금액                       StartPos 77, Length 16
    char    addyetaktotamt      [  16];    // [long  ,   16] 충당예탁금총액                 StartPos 93, Length 16
    char    addyesuamt          [  16];    // [long  ,   16] 충당예수금                     StartPos 109, Length 16
    char    futprofitamt        [  16];    // [long  ,   16] 선물손익금액                   StartPos 125, Length 16
    char    outamt              [  16];    // [long  ,   16] 인출가능금액                   StartPos 141, Length 16
    char    outcashamt          [  16];    // [long  ,   16] 인출가능현금액                 StartPos 157, Length 16
    char    outdyamt            [  16];    // [long  ,   16] 인출가능대용금액               StartPos 173, Length 16
    char    dipositamt          [  16];    // [long  ,   16] 증거금액                       StartPos 189, Length 16
    char    cashdipositamt      [  16];    // [long  ,   16] 현금증거금액                   StartPos 205, Length 16
    char    ordpoamt            [  16];    // [long  ,   16] 주문가능금액                   StartPos 221, Length 16
    char    cashpoamt           [  16];    // [long  ,   16] 현금주문가능금액               StartPos 237, Length 16
    char    adddipositamt       [  16];    // [long  ,   16] 추가증거금액                   StartPos 253, Length 16
    char    cashadddipositamt   [  16];    // [long  ,   16] 현금추가증거금액               StartPos 269, Length 16
    char    supyoinamt          [  16];    // [long  ,   16] 금전일수표입금액               StartPos 285, Length 16
    char    foptpredymedoamt    [  16];    // [long  ,   16] 선물옵션전일대용매도금액       StartPos 301, Length 16
    char    fopttodaydymedoamt  [  16];    // [long  ,   16] 선물옵션금일대용매도금액       StartPos 317, Length 16
    char    foptpreaddamt       [  16];    // [long  ,   16] 선물옵션전일가입금액           StartPos 333, Length 16
    char    fopttodayaddamt     [  16];    // [long  ,   16] 선물옵션금일가입금액           StartPos 349, Length 16
    char    fordyamt            [  16];    // [long  ,   16] 외화대용금액                   StartPos 365, Length 16
    char    foptaccpositname    [  20];    // [string,   20] 선물옵션계좌사후증거금명       StartPos 381, Length 20
} t6034OutBlock1, *LPt6034OutBlock1;
#define NAME_t6034OutBlock1     "t6034OutBlock1"

// 기본출력2, occurs
typedef struct _t6034OutBlock2
{
    char    groupcodname        [  20];    // [string,   20] 상품군코드명                   StartPos 0, Length 20
    char    dangerpositamt      [  16];    // [long  ,   16] 순위험증거금액                 StartPos 20, Length 16
    char    pricepositamt       [  16];    // [long  ,   16] 가격증거금액                   StartPos 36, Length 16
    char    spreadpositamt      [  16];    // [long  ,   16] 스프레드증거금액               StartPos 52, Length 16
    char    priceratepositamt   [  16];    // [long  ,   16] 가격변동증거금액               StartPos 68, Length 16
    char    minpositamt         [  16];    // [long  ,   16] 최소증거금액                   StartPos 84, Length 16
    char    ordpositamt         [  16];    // [long  ,   16] 주문증거금액                   StartPos 100, Length 16
    char    optsunmesuamt       [  16];    // [long  ,   16] 옵션순매수금액                 StartPos 116, Length 16
    char    wtpositamt          [  16];    // [long  ,   16] 위탁증거금액                   StartPos 132, Length 16
    char    ujpositamt          [  16];    // [long  ,   16] 유지증거금액                   StartPos 148, Length 16
    char    fmesucheamt         [  16];    // [long  ,   16] 선물매수체결금액               StartPos 164, Length 16
    char    fmedocheamt         [  16];    // [long  ,   16] 선물매도체결금액               StartPos 180, Length 16
    char    optmesucheamt       [  16];    // [long  ,   16] 옵션매수체결금액               StartPos 196, Length 16
    char    optmedocheamt       [  16];    // [long  ,   16] 옵션매도체결금액               StartPos 212, Length 16
    char    flossamt            [  16];    // [long  ,   16] 선물손익금액                   StartPos 228, Length 16
    char    totriskwtpositamt   [  16];    // [long  ,   16] 총위험위탁증거금               StartPos 244, Length 16
} t6034OutBlock2, *LPt6034OutBlock2;
#define NAME_t6034OutBlock2     "t6034OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
