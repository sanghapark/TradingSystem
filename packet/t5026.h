///////////////////////////////////////////////////////////////////////////////////////////////////
// 일괄청산주문/가능여부조회(t5026) ( base21=SONBT701,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5026     "t5026"

// 기본입력
typedef struct _t5026InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 25, Length 8
    char    qrygb               [   1];    // [string,    1] 조회처리구분                   StartPos 33, Length 1
    char    fotradgb            [   2];    // [string,    2] 선물옵션거래유형코드           StartPos 34, Length 2
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 36, Length 2
    char    gb                  [   1];    // [string,    1] 처리구분                       StartPos 38, Length 1
} t5026InBlock, *LPt5026InBlock;
#define NAME_t5026InBlock     "t5026InBlock"

// 기본출력
typedef struct _t5026OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 25, Length 8
    char    qrygb               [   1];    // [string,    1] 조회처리구분                   StartPos 33, Length 1
    char    fotradgb            [   2];    // [string,    2] 선물옵션거래유형코드           StartPos 34, Length 2
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 36, Length 2
    char    gb                  [   1];    // [string,    1] 처리구분                       StartPos 38, Length 1
} t5026OutBlock, *LPt5026OutBlock;
#define NAME_t5026OutBlock     "t5026OutBlock"

// 기본출력1
typedef struct _t5026OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  40];    // [string,   40] 계좌명                         StartPos 5, Length 40
    char    ordgb               [   1];    // [string,    1] 주문처리구분                   StartPos 45, Length 1
    char    ordgbnm             [  20];    // [string,   20] 주문처리구분명                 StartPos 46, Length 20
} t5026OutBlock1, *LPt5026OutBlock1;
#define NAME_t5026OutBlock1     "t5026OutBlock1"

// 기본출력2, occurs
typedef struct _t5026OutBlock2
{
    char    seq                 [   4];    // [long  ,    4] 순서                           StartPos 0, Length 4
    char    offergb             [   1];    // [string,    1] 선물옵션종목유형구분           StartPos 4, Length 1
    char    focode              [  32];    // [string,   32] 선물옵션종목번호               StartPos 5, Length 32
    char    mmgb                [   1];    // [string,    1] 매매구분                       StartPos 37, Length 1
    char    mmgbnm              [  10];    // [string,   10] 매매구분명                     StartPos 38, Length 10
    char    openyak             [  16];    // [long  ,   16] 미결제수량                     StartPos 48, Length 16
    char    micheqty            [  16];    // [long  ,   16] 미체결수량                     StartPos 64, Length 16
    char    price               [  13];    // [double, 13.2] 현재가                         StartPos 80, Length 13
    char    banhoqty            [  16];    // [long  ,   16] 반대호가수량                   StartPos 93, Length 16
    char    ordgb               [   1];    // [string,    1] 주문처리구분                   StartPos 109, Length 1
    char    ordgbnm             [  20];    // [string,   20] 주문처리구분명                 StartPos 110, Length 20
} t5026OutBlock2, *LPt5026OutBlock2;
#define NAME_t5026OutBlock2     "t5026OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
