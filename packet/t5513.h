///////////////////////////////////////////////////////////////////////////////////////////////////
// 선옵취소주문(t5513) ( base21=SONBT003,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5513     "t5513"

// 기본입력
typedef struct _t5513InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    ordmarketcode       [   2];    // [string,    2] 주문시장코드                   StartPos 5, Length 2
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 7, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 27, Length 8
    char    expcode             [  32];    // [string,   32] 선물옵션종목번호               StartPos 35, Length 32
    char    fnoordptncode       [   2];    // [string,    2] 선물옵션주문유형코드           StartPos 67, Length 2
    char    dummyorgordno       [   3];    // [long  ,    3] dummy원주문번호                StartPos 69, Length 3
    char    orgordno            [   7];    // [long  ,    7] 원주문번호                     StartPos 72, Length 7
    char    qty                 [  16];    // [long  ,   16] 취소수량                       StartPos 79, Length 16
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 95, Length 2
    char    stragb              [   6];    // [string,    6] 전략코드                       StartPos 97, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 103, Length 20
    char    ordernum            [  10];    // [long  ,   10] 주문회차                       StartPos 123, Length 10
    char    portnum             [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 133, Length 10
    char    basketnum           [  10];    // [long  ,   10] 바스켓번호                     StartPos 143, Length 10
    char    tranchnum           [  10];    // [long  ,   10] 트렌치번호                     StartPos 153, Length 10
    char    itemnum             [  10];    // [long  ,   10] 아이템번호                     StartPos 163, Length 10
    char    mgempno             [   9];    // [string,    9] 관리사번                       StartPos 173, Length 9
    char    fundid              [  12];    // [string,   12] 펀드ID                         StartPos 182, Length 12
    char    dummyfundorgordno   [   3];    // [long  ,    3] dummy펀드원주문번호            StartPos 194, Length 3
    char    fundorgordno        [   7];    // [long  ,    7] 펀드원주문번호                 StartPos 197, Length 7
    char    dummyfundordno      [   3];    // [long  ,    3] dummy펀드주문번호              StartPos 204, Length 3
    char    fundordno           [   7];    // [long  ,    7] 펀드주문번호                   StartPos 207, Length 7
} t5513InBlock, *LPt5513InBlock;
#define NAME_t5513InBlock     "t5513InBlock"

// 기본출력
typedef struct _t5513OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    ordmarketcode       [   2];    // [string,    2] 주문시장코드                   StartPos 5, Length 2
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 7, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 27, Length 8
    char    expcode             [  32];    // [string,   32] 선물옵션종목번호               StartPos 35, Length 32
    char    fnoordptncode       [   2];    // [string,    2] 선물옵션주문유형코드           StartPos 67, Length 2
    char    dummyorgordno       [   3];    // [long  ,    3] dummy원주문번호                StartPos 69, Length 3
    char    orgordno            [   7];    // [long  ,    7] 원주문번호                     StartPos 72, Length 7
    char    qty                 [  16];    // [long  ,   16] 취소수량                       StartPos 79, Length 16
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 95, Length 2
    char    stragb              [   6];    // [string,    6] 전략코드                       StartPos 97, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 103, Length 20
    char    ordernum            [  10];    // [long  ,   10] 주문회차                       StartPos 123, Length 10
    char    portnum             [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 133, Length 10
    char    basketnum           [  10];    // [long  ,   10] 바스켓번호                     StartPos 143, Length 10
    char    tranchnum           [  10];    // [long  ,   10] 트렌치번호                     StartPos 153, Length 10
    char    itemnum             [  10];    // [long  ,   10] 아이템번호                     StartPos 163, Length 10
    char    mgempno             [   9];    // [string,    9] 관리사번                       StartPos 173, Length 9
    char    fundid              [  12];    // [string,   12] 펀드ID                         StartPos 182, Length 12
    char    dummyfundorgordno   [   3];    // [long  ,    3] dummy펀드원주문번호            StartPos 194, Length 3
    char    fundorgordno        [   7];    // [long  ,    7] 펀드원주문번호                 StartPos 197, Length 7
    char    dummyfundordno      [   3];    // [long  ,    3] dummy펀드주문번호              StartPos 204, Length 3
    char    fundordno           [   7];    // [long  ,    7] 펀드주문번호                   StartPos 207, Length 7
} t5513OutBlock, *LPt5513OutBlock;
#define NAME_t5513OutBlock     "t5513OutBlock"

// 기본출력1
typedef struct _t5513OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    dummyordno          [   3];    // [long  ,    3] dummy주문번호                  StartPos 5, Length 3
    char    ordno               [   7];    // [long  ,    7] 주문번호                       StartPos 8, Length 7
    char    brnnm               [  40];    // [string,   40] 지점명                         StartPos 15, Length 40
    char    accno               [  40];    // [string,   40] 계좌명                         StartPos 55, Length 40
    char    isunm               [  40];    // [string,   40] 종목명                         StartPos 95, Length 40
    char    ordableamt          [  16];    // [long  ,   16] 주문가능금액                   StartPos 135, Length 16
    char    mnyordableamt       [  16];    // [long  ,   16] 현금주문가능금액               StartPos 151, Length 16
    char    ordmgn              [  16];    // [long  ,   16] 주문증거금액                   StartPos 167, Length 16
    char    mnyordmgn           [  16];    // [long  ,   16] 현금주문증거금액               StartPos 183, Length 16
    char    ordableqty          [  16];    // [long  ,   16] 주문가능수량                   StartPos 199, Length 16
} t5513OutBlock1, *LPt5513OutBlock1;
#define NAME_t5513OutBlock1     "t5513OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
