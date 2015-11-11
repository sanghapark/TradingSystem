#ifndef _t5012_H_
#define _t5012_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 거래소 선물대용매도(t5012) ( base21=SONAT013,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5012     "t5012"

// 기본입력
typedef struct _t5012InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 25, Length 8
    char    futaccno            [  20];    // [string,   20] 선물계좌번호                   StartPos 33, Length 20
    char    futmarketgb         [   1];    // [string,    1] 선물시장구분                   StartPos 53, Length 1
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 54, Length 12
    char    futdaegb            [   1];    // [string,    1] 선물대용구분                   StartPos 66, Length 1
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 67, Length 16
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 83, Length 13
    char    hogagb              [   2];    // [string,    2] 호가유형코드                   StartPos 96, Length 2
    char    ordcondgb           [   1];    // [string,    1] 주문조건구분                   StartPos 98, Length 1
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 99, Length 2
} t5012InBlock, *LPt5012InBlock;
#define NAME_t5012InBlock     "t5012InBlock"

// 기본출력
typedef struct _t5012OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 25, Length 8
    char    futaccno            [  20];    // [string,   20] 선물계좌번호                   StartPos 33, Length 20
    char    futmarketgb         [   1];    // [string,    1] 선물시장구분                   StartPos 53, Length 1
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 54, Length 12
    char    futdaegb            [   1];    // [string,    1] 선물대용구분                   StartPos 66, Length 1
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 67, Length 16
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 83, Length 13
    char    hogagb              [   2];    // [string,    2] 호가유형코드                   StartPos 96, Length 2
    char    ordcondgb           [   1];    // [string,    1] 주문조건구분                   StartPos 98, Length 1
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 99, Length 2
} t5012OutBlock, *LPt5012OutBlock;
#define NAME_t5012OutBlock     "t5012OutBlock"

// 기본출력1
typedef struct _t5012OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    ordno               [  10];    // [long  ,   10] 주문번호                       StartPos 5, Length 10
} t5012OutBlock1, *LPt5012OutBlock1;
#define NAME_t5012OutBlock1     "t5012OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t5012_H_
