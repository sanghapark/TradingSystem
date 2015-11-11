#ifndef _t5502_H_
#define _t5502_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 현물정정주문(t5502) ( base21=SONAT001,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5502     "t5502"

// 기본입력
typedef struct _t5502InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    orgordno            [  10];    // [long  ,   10] 원주문번호                     StartPos 5, Length 10
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 15, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 35, Length 8
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 43, Length 12
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 55, Length 16
    char    hogagb              [   2];    // [string,    2] 호가유형코드                   StartPos 71, Length 2
    char    memegb              [   1];    // [string,    1] 주문조건구분                   StartPos 73, Length 1
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 74, Length 13
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 87, Length 2
    char    stragb              [   6];    // [string,    6] 전략코드                       StartPos 89, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 95, Length 20
    char    ordernum            [  10];    // [long  ,   10] 주문회차                       StartPos 115, Length 10
    char    portnum             [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 125, Length 10
    char    basketnum           [  10];    // [long  ,   10] 바스켓번호                     StartPos 135, Length 10
    char    tranchnum           [  10];    // [long  ,   10] 트렌치번호                     StartPos 145, Length 10
    char    itemnum             [  10];    // [long  ,   10] 아이템번호                     StartPos 155, Length 10
} t5502InBlock, *LPt5502InBlock;
#define NAME_t5502InBlock     "t5502InBlock"

// 기본출력
typedef struct _t5502OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    orgordno            [  10];    // [long  ,   10] 원주문번호                     StartPos 5, Length 10
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 15, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 35, Length 8
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 43, Length 12
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 55, Length 16
    char    hogagb              [   2];    // [string,    2] 호가유형코드                   StartPos 71, Length 2
    char    memegb              [   1];    // [string,    1] 주문조건구분                   StartPos 73, Length 1
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 74, Length 13
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 87, Length 2
    char    stragb              [   6];    // [string,    6] 전략코드                       StartPos 89, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 95, Length 20
    char    ordernum            [  10];    // [long  ,   10] 주문회차                       StartPos 115, Length 10
    char    portnum             [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 125, Length 10
    char    basketnum           [  10];    // [long  ,   10] 바스켓번호                     StartPos 135, Length 10
    char    tranchnum           [  10];    // [long  ,   10] 트렌치번호                     StartPos 145, Length 10
    char    itemnum             [  10];    // [long  ,   10] 아이템번호                     StartPos 155, Length 10
} t5502OutBlock, *LPt5502OutBlock;
#define NAME_t5502OutBlock     "t5502OutBlock"

// 기본출력1
typedef struct _t5502OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    ordno               [  10];    // [long  ,   10] 주문번호                       StartPos 5, Length 10
    char    mordno              [  10];    // [long  ,   10] 모주문번호                     StartPos 15, Length 10
    char    ordtime             [   9];    // [string,    9] 주문시각                       StartPos 25, Length 9
    char    ordmktcode          [   2];    // [string,    2] 주문시장코드                   StartPos 34, Length 2
    char    ordcode             [   2];    // [string,    2] 주문유형코드                   StartPos 36, Length 2
    char    expcode             [   9];    // [string,    9] 단축종목번호                   StartPos 38, Length 9
    char    pgmtype             [   2];    // [string,    2] 프로그램호가유형코드           StartPos 47, Length 2
    char    gongtype            [   1];    // [string,    1] 공매도호가구분                 StartPos 49, Length 1
    char    gonghoga            [   1];    // [string,    1] 공매도가능여부                 StartPos 50, Length 1
    char    sinmemecode         [   3];    // [string,    3] 신용거래코드                   StartPos 51, Length 3
    char    loandt              [   8];    // [string,    8] 대출일                         StartPos 54, Length 8
    char    oppbuygb            [   1];    // [string,    1] 반대매매주문구분               StartPos 62, Length 1
    char    fowsupgb            [   1];    // [string,    1] 유동성공급자여부               StartPos 63, Length 1
    char    operno              [   9];    // [string,    9] 관리사원번호                   StartPos 64, Length 9
    char    ordamt              [  16];    // [long  ,   16] 주문금액                       StartPos 73, Length 16
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 89, Length 1
    char    fillermemegb        [  10];    // [long  ,   10] 예비주문번호                   StartPos 90, Length 10
    char    oppbuyseqno         [  10];    // [long  ,   10] 반대매매일련번호               StartPos 100, Length 10
    char    preeordno           [  10];    // [long  ,   10] 예약주문번호                   StartPos 110, Length 10
    char    cashordamt          [  16];    // [long  ,   16] 현금주문금액                   StartPos 120, Length 16
    char    daeordamt           [  16];    // [long  ,   16] 대용주문금액                   StartPos 136, Length 16
    char    recordamt           [  16];    // [long  ,   16] 재사용주문금액                 StartPos 152, Length 16
    char    accno               [  40];    // [string,   40] 계좌명                         StartPos 168, Length 40
    char    hname               [  40];    // [string,   40] 종목명                         StartPos 208, Length 40
} t5502OutBlock1, *LPt5502OutBlock1;
#define NAME_t5502OutBlock1     "t5502OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t5502_H_
