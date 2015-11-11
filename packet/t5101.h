#ifndef _t5101_H_
#define _t5101_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 현물복수정상주문 ( base21=SONAT016,headtype=B )
#pragma pack( push, 1 )

#define NAME_t5101     "t5101"

// 입력
typedef struct _t5101InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 5, Length 2
    char    ordercnt            [   6];    // [long  ,    6] 현물주문횟수                   StartPos 7, Length 6
    char    reccnt1             [   5];    // [long  ,    5] 레코드갯수1                    StartPos 13, Length 5
} t5101InBlock, *LPt5101InBlock;
#define NAME_t5101InBlock     "t5101InBlock"

// 입력, occurs
typedef struct _t5101InBlock1
{
    char    ordergb             [   1];    // [string,    1] 주문처리구분                   StartPos 0, Length 1
    char    orgordno            [  10];    // [long  ,   10] 원주문번호                     StartPos 1, Length 10
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 11, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 31, Length 8
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 39, Length 1
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 40, Length 12
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 52, Length 16
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 68, Length 13
    char    hogagb              [   2];    // [string,    2] 호가유형코드                   StartPos 81, Length 2
    char    gongtype            [   1];    // [string,    1] 공매도가능여부                 StartPos 83, Length 1
    char    ghogagb             [   1];    // [string,    1] 공매도호가구분                 StartPos 84, Length 1
    char    ordcondgb           [   1];    // [string,    1] 주문조건구분                   StartPos 85, Length 1
    char    pgmtype             [   2];    // [string,    2] 프로그램호가유형코드           StartPos 86, Length 2
    char    operordnum          [  12];    // [string,   12] 운용지시번호                   StartPos 88, Length 12
    char    sincd               [   3];    // [string,    3] 신용거래코드                   StartPos 100, Length 3
    char    loandt              [   8];    // [string,    8] 대출일                         StartPos 103, Length 8
    char    flowsupgb           [   1];    // [string,    1] 유동성공급자여부               StartPos 111, Length 1
    char    multiordno          [  10];    // [long  ,   10] 복수주문일련번호               StartPos 112, Length 10
    char    ordno               [  10];    // [long  ,   10] 주문번호                       StartPos 122, Length 10
    char    msgcode             [   4];    // [string,    4] 메세지코드                     StartPos 132, Length 4
    char    msg                 [ 100];    // [string,  100] 메세지내용                     StartPos 136, Length 100
    char    proctm              [   9];    // [string,    9] 처리시각                       StartPos 236, Length 9
} t5101InBlock1, *LPt5101InBlock1;
#define NAME_t5101InBlock1     "t5101InBlock1"

// 입력
typedef struct _t5101OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    tongsingb           [   2];    // [string,    2] 통신매체코드                   StartPos 5, Length 2
    char    ordercnt            [   6];    // [long  ,    6] 현물주문횟수                   StartPos 7, Length 6
} t5101OutBlock, *LPt5101OutBlock;
#define NAME_t5101OutBlock     "t5101OutBlock"

// 입력, occurs
typedef struct _t5101OutBlock1
{
    char    ordergb             [   1];    // [string,    1] 주문처리구분                   StartPos 0, Length 1
    char    orgordno            [  10];    // [long  ,   10] 원주문번호                     StartPos 1, Length 10
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 11, Length 20
    char    passwd              [   8];    // [string,    8] 입력비밀번호                   StartPos 31, Length 8
    char    memegb              [   1];    // [string,    1] 매매구분                       StartPos 39, Length 1
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 40, Length 12
    char    qty                 [  16];    // [long  ,   16] 주문수량                       StartPos 52, Length 16
    char    price               [  13];    // [double, 13.2] 주문가                         StartPos 68, Length 13
    char    hogagb              [   2];    // [string,    2] 호가유형코드                   StartPos 81, Length 2
    char    gongtype            [   1];    // [string,    1] 공매도가능여부                 StartPos 83, Length 1
    char    ghogagb             [   1];    // [string,    1] 공매도호가구분                 StartPos 84, Length 1
    char    ordcondgb           [   1];    // [string,    1] 주문조건구분                   StartPos 85, Length 1
    char    pgmtype             [   2];    // [string,    2] 프로그램호가유형코드           StartPos 86, Length 2
    char    operordnum          [  12];    // [string,   12] 운용지시번호                   StartPos 88, Length 12
    char    sincd               [   3];    // [string,    3] 신용거래코드                   StartPos 100, Length 3
    char    loandt              [   8];    // [string,    8] 대출일                         StartPos 103, Length 8
    char    flowsupgb           [   1];    // [string,    1] 유동성공급자여부               StartPos 111, Length 1
    char    multiordno          [  10];    // [long  ,   10] 복수주문일련번호               StartPos 112, Length 10
    char    ordno               [  10];    // [long  ,   10] 주문번호                       StartPos 122, Length 10
    char    msgcode             [   4];    // [string,    4] 메세지코드                     StartPos 132, Length 4
    char    msg                 [ 100];    // [string,  100] 메세지내용                     StartPos 136, Length 100
    char    proctm              [   9];    // [string,    9] 처리시각                       StartPos 236, Length 9
} t5101OutBlock1, *LPt5101OutBlock1;
#define NAME_t5101OutBlock1     "t5101OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t5101_H_
