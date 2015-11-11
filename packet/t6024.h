///////////////////////////////////////////////////////////////////////////////////////////////////
// 주문가능수량/증거금(t6024) ( base21=SONBQ103,headtype=B )
#pragma pack( push, 1 )

#define NAME_t6024     "t6024"

// 기본입력
typedef struct _t6024InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 25, Length 8
    char    gubun               [   1];    // [string,    1] 금액수량구분                   StartPos 33, Length 1
    char    fohogagb            [   2];    // [string,    2] 선물옵션호가유형코드           StartPos 34, Length 2
    char    ordamt              [  16];    // [long  ,   16] 주문금액                       StartPos 36, Length 16
} t6024InBlock, *LPt6024InBlock;
#define NAME_t6024InBlock     "t6024InBlock"

// 기본입력1
typedef struct _t6024InBlock1
{
    char    reccnt2             [   5];    // [long  ,    5] 레코드갯수2                    StartPos 0, Length 5
} t6024InBlock1, *LPt6024InBlock1;
#define NAME_t6024InBlock1     "t6024InBlock1"

// 기본입력2, occurs
typedef struct _t6024InBlock2
{
    char    focodeno            [  32];    // [string,   32] 선물옵션종목번호               StartPos 0, Length 32
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 32, Length 1
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 33, Length 13
    char    ordqty              [  16];    // [long  ,   16] 주문수량                       StartPos 46, Length 16
} t6024InBlock2, *LPt6024InBlock2;
#define NAME_t6024InBlock2     "t6024InBlock2"

// 기본출력
typedef struct _t6024OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 25, Length 8
    char    gubun               [   1];    // [string,    1] 금액수량구분                   StartPos 33, Length 1
    char    fohogagb            [   2];    // [string,    2] 선물옵션호가유형코드           StartPos 34, Length 2
    char    ordamt              [  16];    // [long  ,   16] 주문금액                       StartPos 36, Length 16
} t6024OutBlock, *LPt6024OutBlock;
#define NAME_t6024OutBlock     "t6024OutBlock"

// 기본출력1, occurs
typedef struct _t6024OutBlock1
{
    char    focodeno            [  32];    // [string,   32] 선물옵션종목번호               StartPos 0, Length 32
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 32, Length 1
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 33, Length 13
    char    ordqty              [  16];    // [long  ,   16] 주문수량                       StartPos 46, Length 16
} t6024OutBlock1, *LPt6024OutBlock1;
#define NAME_t6024OutBlock1     "t6024OutBlock1"

// 기본출력2
typedef struct _t6024OutBlock2
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accname             [  40];    // [string,   40] 계좌명                         StartPos 5, Length 40
    char    date                [   8];    // [string,    8] 주문일                         StartPos 45, Length 8
    char    ordnamtqty          [  16];    // [long  ,   16] 주문가능금액                   StartPos 53, Length 16
    char    ordcashamt          [  16];    // [long  ,   16] 현금주문가능금액               StartPos 69, Length 16
    char    orddyamt            [  16];    // [long  ,   16] 대용주문가능금액               StartPos 85, Length 16
    char    syfpriceamt         [  16];    // [long  ,   16] 소요선물증거금액               StartPos 101, Length 16
    char    syfcashamt          [  16];    // [long  ,   16] 소요선물현금증거금액           StartPos 117, Length 16
    char    syfdyamt            [  16];    // [long  ,   16] 소요선물대용증거금액           StartPos 133, Length 16
    char    syoptpriceamt       [  16];    // [long  ,   16] 소요옵션증거금액               StartPos 149, Length 16
    char    syoptchashamt       [  16];    // [long  ,   16] 소요옵션현금증거금액           StartPos 165, Length 16
    char    syoptdyamt          [  16];    // [long  ,   16] 소요옵션대용증거금액           StartPos 181, Length 16
    char    syspdpriceamt       [  16];    // [long  ,   16] 소요스프레드증거금액           StartPos 197, Length 16
    char    syspdcashamt        [  16];    // [long  ,   16] 소요스프레드현금증거금액       StartPos 213, Length 16
    char    syspddyamt          [  16];    // [long  ,   16] 소요스프레드대용증거금액       StartPos 229, Length 16
    char    sypriceamt          [  16];    // [long  ,   16] 소요증거금액                   StartPos 245, Length 16
    char    sychashamt          [  16];    // [long  ,   16] 소요현금증거금액               StartPos 261, Length 16
    char    sydyamt             [  16];    // [long  ,   16] 소요대용증거금액               StartPos 277, Length 16
    char    namamt              [  16];    // [long  ,   16] 증거금잔액                     StartPos 293, Length 16
    char    cashnamamt          [  16];    // [long  ,   16] 현금증거금잔액                 StartPos 309, Length 16
    char    dynamamt            [  16];    // [long  ,   16] 대용증거금잔액                 StartPos 325, Length 16
} t6024OutBlock2, *LPt6024OutBlock2;
#define NAME_t6024OutBlock2     "t6024OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
