#ifndef _t5024_H_
#define _t5024_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 장외단주매도주문(t5024) ( base21=SOFST101,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5024     "t5024"

// 기본입력
typedef struct _t5024InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    mmgb                [   1];    // [string,    1] 매매구분                       StartPos 5, Length 1
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 6, Length 20
    char    passwd              [   8];    // [string,    8] 비밀번호                       StartPos 26, Length 8
    char    paycode             [   2];    // [string,    2] 결제업무코드                   StartPos 34, Length 2
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 36, Length 12
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 48, Length 16
    char    orddan              [  15];    // [double, 15.4] 주문단가                       StartPos 64, Length 15
} t5024InBlock, *LPt5024InBlock;
#define NAME_t5024InBlock     "t5024InBlock"

// 기본출력
typedef struct _t5024OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    mmgb                [   1];    // [string,    1] 매매구분                       StartPos 5, Length 1
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 6, Length 20
    char    passwd              [   8];    // [string,    8] 비밀번호                       StartPos 26, Length 8
    char    paycode             [   2];    // [string,    2] 결제업무코드                   StartPos 34, Length 2
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 36, Length 12
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 48, Length 16
    char    orddan              [  15];    // [double, 15.4] 주문단가                       StartPos 64, Length 15
} t5024OutBlock, *LPt5024OutBlock;
#define NAME_t5024OutBlock     "t5024OutBlock"

// 기본출력1
typedef struct _t5024OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  40];    // [string,   40] 계좌명                         StartPos 5, Length 40
    char    expcode             [  40];    // [string,   40] 종목명                         StartPos 45, Length 40
    char    ordno               [  10];    // [long  ,   10] 주문번호                       StartPos 85, Length 10
    char    ordprice            [  16];    // [long  ,   16] 주문금액                       StartPos 95, Length 16
    char    fee                 [  16];    // [long  ,   16] 수수료                         StartPos 111, Length 16
    char    paydate             [   8];    // [string,    8] 결제일                         StartPos 127, Length 8
} t5024OutBlock1, *LPt5024OutBlock1;
#define NAME_t5024OutBlock1     "t5024OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t5024_H_
