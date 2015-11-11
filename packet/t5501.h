#ifndef _t5501_H_
#define _t5501_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 현물정상주문(t5501) ( base21=SONAT000,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5501     "t5501"

// 입력
typedef struct _t5501InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 25, Length 8
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 33, Length 12
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 45, Length 16
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 61, Length 13
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 74, Length 1
    char    hogagb              [   2];    // [string,    2] 호가유형코드                   StartPos 75, Length 2
    char    pgmtype             [   2];    // [string,    2] 프로그램호가유형코드           StartPos 77, Length 2
    char    gongtype            [   1];    // [string,    1] 공매도가능여부                 StartPos 79, Length 1
    char    gonghoga            [   1];    // [string,    1] 공매도호가구분                 StartPos 80, Length 1
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 81, Length 2
    char    sinmemecode         [   3];    // [string,    3] 신용거래코드                   StartPos 83, Length 3
    char    loandt              [   8];    // [string,    8] 대출일                         StartPos 86, Length 8
    char    memnumber           [   3];    // [string,    3] 회원번호                       StartPos 94, Length 3
    char    ordcondgb           [   1];    // [string,    1] 주문조건구분                   StartPos 97, Length 1
    char    stragb              [   6];    // [string,    6] 전략코드                       StartPos 98, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 104, Length 20
    char    ordernum            [  10];    // [long  ,   10] 주문회차                       StartPos 124, Length 10
    char    portnum             [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 134, Length 10
    char    basketnum           [  10];    // [long  ,   10] 바스켓번호                     StartPos 144, Length 10
    char    tranchnum           [  10];    // [long  ,   10] 트렌치번호                     StartPos 154, Length 10
    char    itemnum             [  10];    // [long  ,   10] 아이템번호                     StartPos 164, Length 10
    char    operordnum          [  12];    // [string,   12] 운용지시번호                   StartPos 174, Length 12
    char    flowsupgb           [   1];    // [string,    1] 유동성공급자여부               StartPos 186, Length 1
    char    oppbuygb            [   1];    // [string,    1] 반대매매구분                   StartPos 187, Length 1
} t5501InBlock, *LPt5501InBlock;
#define NAME_t5501InBlock     "t5501InBlock"

// 출력
typedef struct _t5501OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 5, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 25, Length 8
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 33, Length 12
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 45, Length 16
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 61, Length 13
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 74, Length 1
    char    hogagb              [   2];    // [string,    2] 호가유형코드                   StartPos 75, Length 2
    char    pgmtype             [   2];    // [string,    2] 프로그램호가유형코드           StartPos 77, Length 2
    char    gongtype            [   1];    // [string,    1] 공매도가능여부                 StartPos 79, Length 1
    char    gonghoga            [   1];    // [string,    1] 공매도호가구분                 StartPos 80, Length 1
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 81, Length 2
    char    sinmemecode         [   3];    // [string,    3] 신용거래코드                   StartPos 83, Length 3
    char    loandt              [   8];    // [string,    8] 대출일                         StartPos 86, Length 8
    char    memnumber           [   3];    // [string,    3] 회원번호                       StartPos 94, Length 3
    char    ordcondgb           [   1];    // [string,    1] 주문조건구분                   StartPos 97, Length 1
    char    stragb              [   6];    // [string,    6] 전략코드                       StartPos 98, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 104, Length 20
    char    ordernum            [  10];    // [long  ,   10] 주문회차                       StartPos 124, Length 10
    char    portnum             [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 134, Length 10
    char    basketnum           [  10];    // [long  ,   10] 바스켓번호                     StartPos 144, Length 10
    char    tranchnum           [  10];    // [long  ,   10] 트렌치번호                     StartPos 154, Length 10
    char    itemnum             [  10];    // [long  ,   10] 아이템번호                     StartPos 164, Length 10
    char    operordnum          [  12];    // [string,   12] 운용지시번호                   StartPos 174, Length 12
    char    flowsupgb           [   1];    // [string,    1] 유동성공급자여부               StartPos 186, Length 1
    char    oppbuygb            [   1];    // [string,    1] 반대매매구분                   StartPos 187, Length 1
} t5501OutBlock, *LPt5501OutBlock;
#define NAME_t5501OutBlock     "t5501OutBlock"

// 출력1
typedef struct _t5501OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    ordno               [  10];    // [long  ,   10] 주문번호                       StartPos 5, Length 10
    char    ordtime             [   9];    // [string,    9] 주문시각                       StartPos 15, Length 9
    char    ordmktcode          [   2];    // [string,    2] 주문시장코드                   StartPos 24, Length 2
    char    ordcode             [   2];    // [string,    2] 주문유형코드                   StartPos 26, Length 2
    char    expcode             [   9];    // [string,    9] 단축종목번호                   StartPos 28, Length 9
    char    operno              [   9];    // [string,    9] 관리사원번호                   StartPos 37, Length 9
    char    ordamt              [  16];    // [long  ,   16] 주문금액                       StartPos 46, Length 16
    char    fillermemegb        [  10];    // [long  ,   10] 예비주문번호                   StartPos 62, Length 10
    char    oppbuyseqno         [  10];    // [long  ,   10] 반대매매일련번호               StartPos 72, Length 10
    char    preeordno           [  10];    // [long  ,   10] 예약주문번호                   StartPos 82, Length 10
    char    realordcnt          [  16];    // [long  ,   16] 실물주문수량                   StartPos 92, Length 16
    char    recoordcnt          [  16];    // [long  ,   16] 재사용주문수량                 StartPos 108, Length 16
    char    cashordamt          [  16];    // [long  ,   16] 현금주문금액                   StartPos 124, Length 16
    char    daeordamt           [  16];    // [long  ,   16] 대용주문금액                   StartPos 140, Length 16
    char    recordamt           [  16];    // [long  ,   16] 재사용주문금액                 StartPos 156, Length 16
    char    accno               [  40];    // [string,   40] 계좌명                         StartPos 172, Length 40
    char    hname               [  40];    // [string,   40] 종목명                         StartPos 212, Length 40
} t5501OutBlock1, *LPt5501OutBlock1;
#define NAME_t5501OutBlock1     "t5501OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t5501_H_
