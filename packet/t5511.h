///////////////////////////////////////////////////////////////////////////////////////////////////
// 선옵정상주문(t5511) ( base21=SONBT001,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5511     "t5511"

// 기본입력
typedef struct _t5511InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    ordmarketcode       [   2];    // [string,    2] 주문시장코드                   StartPos 5, Length 2
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 7, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 27, Length 8
    char    expcode             [  32];    // [string,   32] 선물옵션종목번호               StartPos 35, Length 32
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 67, Length 1
    char    offergb             [   2];    // [string,    2] 선물옵션주문유형코드           StartPos 68, Length 2
    char    hogagb              [   2];    // [string,    2] 선물옵션호가유형코드           StartPos 70, Length 2
    char    tradegb             [   2];    // [string,    2] 선물옵션거래유형코드           StartPos 72, Length 2
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 74, Length 13
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 87, Length 16
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 103, Length 2
    char    stragb              [   6];    // [string,    6] 전략코드                       StartPos 105, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 111, Length 20
    char    ordernum            [  10];    // [long  ,   10] 주문회차                       StartPos 131, Length 10
    char    portnum             [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 141, Length 10
    char    basketnum           [  10];    // [long  ,   10] 바스켓번호                     StartPos 151, Length 10
    char    tranchnum           [  10];    // [long  ,   10] 트렌치번호                     StartPos 161, Length 10
    char    itemnum             [  10];    // [long  ,   10] 아이템번호                     StartPos 171, Length 10
    char    operordnum          [  12];    // [string,   12] 운용지시번호                   StartPos 181, Length 12
    char    mgempno             [   9];    // [string,    9] 관리사원번호                   StartPos 193, Length 9
    char    fundid              [  12];    // [string,   12] 펀드ID                         StartPos 202, Length 12
    char    dummyfundorgordno   [   3];    // [long  ,    3] dummy펀드원주문번호            StartPos 214, Length 3
    char    fundorgordno        [   7];    // [long  ,    7] 펀드원주문번호                 StartPos 217, Length 7
} t5511InBlock, *LPt5511InBlock;
#define NAME_t5511InBlock     "t5511InBlock"

// 기본출력
typedef struct _t5511OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    ordmarketcode       [   2];    // [string,    2] 주문시장코드                   StartPos 5, Length 2
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 7, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 27, Length 8
    char    expcode             [  32];    // [string,   32] 선물옵션종목번호               StartPos 35, Length 32
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 67, Length 1
    char    offergb             [   2];    // [string,    2] 선물옵션주문유형코드           StartPos 68, Length 2
    char    hogagb              [   2];    // [string,    2] 선물옵션호가유형코드           StartPos 70, Length 2
    char    tradegb             [   2];    // [string,    2] 선물옵션거래유형코드           StartPos 72, Length 2
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 74, Length 13
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 87, Length 16
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 103, Length 2
    char    stragb              [   6];    // [string,    6] 전략코드                       StartPos 105, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 111, Length 20
    char    ordernum            [  10];    // [long  ,   10] 주문회차                       StartPos 131, Length 10
    char    portnum             [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 141, Length 10
    char    basketnum           [  10];    // [long  ,   10] 바스켓번호                     StartPos 151, Length 10
    char    tranchnum           [  10];    // [long  ,   10] 트렌치번호                     StartPos 161, Length 10
    char    itemnum             [  10];    // [long  ,   10] 아이템번호                     StartPos 171, Length 10
    char    operordnum          [  12];    // [string,   12] 운용지시번호                   StartPos 181, Length 12
    char    mgempno             [   9];    // [string,    9] 관리사원번호                   StartPos 193, Length 9
    char    fundid              [  12];    // [string,   12] 펀드ID                         StartPos 202, Length 12
    char    dummyfundorgordno   [   3];    // [long  ,    3] dummy펀드원주문번호            StartPos 214, Length 3
    char    fundorgordno        [   7];    // [long  ,    7] 펀드원주문번호                 StartPos 217, Length 7
} t5511OutBlock, *LPt5511OutBlock;
#define NAME_t5511OutBlock     "t5511OutBlock"

// 기본출력1
typedef struct _t5511OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    dummyordno          [   3];    // [long  ,    3] dummy주문번호                  StartPos 5, Length 3
    char    ordno               [   7];    // [long  ,    7] 주문번호                       StartPos 8, Length 7
    char    brnnm               [  40];    // [string,   40] 지점명                         StartPos 15, Length 40
    char    accnm               [  40];    // [string,   40] 계좌명                         StartPos 55, Length 40
    char    isunm               [  40];    // [string,   40] 종목명                         StartPos 95, Length 40
    char    ordableamt          [  16];    // [long  ,   16] 주문가능금액                   StartPos 135, Length 16
    char    mnyordableamt       [  16];    // [long  ,   16] 현금주문가능금액               StartPos 151, Length 16
    char    ordmgn              [  16];    // [long  ,   16] 주문증거금액                   StartPos 167, Length 16
    char    mnyordmgn           [  16];    // [long  ,   16] 현금주문증거금액               StartPos 183, Length 16
    char    ordableqty          [  16];    // [long  ,   16] 주문가능수량                   StartPos 199, Length 16
} t5511OutBlock1, *LPt5511OutBlock1;
#define NAME_t5511OutBlock1     "t5511OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
