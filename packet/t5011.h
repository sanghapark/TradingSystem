///////////////////////////////////////////////////////////////////////////////////////////////////
// 선옵복수계좌복수종목취소주문 ( base21=SONBT714,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5011     "t5011"

// 기본입력
typedef struct _t5011InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 5, Length 2
    char    reccnt1             [   5];    // [long  ,    5] 레코드갯수1                    StartPos 7, Length 5
} t5011InBlock, *LPt5011InBlock;
#define NAME_t5011InBlock     "t5011InBlock"

// 기본입력1, occurs
typedef struct _t5011InBlock1
{
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 0, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 20, Length 8
    char    expcode             [  32];    // [string,   32] 선물옵션종목번호               StartPos 28, Length 32
    char    dummyorgordno       [   3];    // [long  ,    3] dummy원주문번호                StartPos 60, Length 3
    char    orgordno            [   7];    // [long  ,    7] 원주문번호                     StartPos 63, Length 7
    char    qty                 [  16];    // [long  ,   16] 취소수량                       StartPos 70, Length 16
} t5011InBlock1, *LPt5011InBlock1;
#define NAME_t5011InBlock1     "t5011InBlock1"

// 기본출력
typedef struct _t5011OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 5, Length 2
} t5011OutBlock, *LPt5011OutBlock;
#define NAME_t5011OutBlock     "t5011OutBlock"

// 기본출력1, occurs
typedef struct _t5011OutBlock1
{
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 0, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 20, Length 8
    char    expcode             [  32];    // [string,   32] 선물옵션종목번호               StartPos 28, Length 32
    char    dummyorgordno       [   3];    // [long  ,    3] dummy원주문번호                StartPos 60, Length 3
    char    orgordno            [   7];    // [long  ,    7] 원주문번호                     StartPos 63, Length 7
    char    qty                 [  16];    // [long  ,   16] 취소수량                       StartPos 70, Length 16
} t5011OutBlock1, *LPt5011OutBlock1;
#define NAME_t5011OutBlock1     "t5011OutBlock1"

// 기본출력2, occurs
typedef struct _t5011OutBlock2
{
    char    dummyordno          [   3];    // [long  ,    3] dummy주문번호                  StartPos 0, Length 3
    char    ordno               [   7];    // [long  ,    7] 주문번호                       StartPos 3, Length 7
    char    msgcode             [   4];    // [string,    4] 메시지코드                     StartPos 10, Length 4
    char    msg                 [ 100];    // [string,  100] 메시지내용                     StartPos 14, Length 100
    char    proctime            [   9];    // [string,    9] 처리시각                       StartPos 114, Length 9
} t5011OutBlock2, *LPt5011OutBlock2;
#define NAME_t5011OutBlock2     "t5011OutBlock2"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
