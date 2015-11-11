#ifndef _SC0_H_
#define _SC0_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식주문접수 ( block )
#pragma pack( push, 1 )

#define NAME_SC0     "SC0"

// 입력
typedef struct _SC0_InBlock
{
} SC0_InBlock, *LPSC0_InBlock;
#define NAME_SC0_InBlock     "InBlock"

// 출력
typedef struct _SC0_OutBlock
{
    char    lineseq             [  10];    // [long  ,   10] 라인일련번호                   StartPos 0, Length 10
    char    accno               [  11];    // [string,   11] 계좌번호                       StartPos 10, Length 11
    char    user                [   8];    // [string,    8] 조작자ID                       StartPos 21, Length 8
    char    len                 [   6];    // [long  ,    6] 헤더길이                       StartPos 29, Length 6
    char    gubun               [   1];    // [string,    1] 헤더구분                       StartPos 35, Length 1
    char    compress            [   1];    // [string,    1] 압축구분                       StartPos 36, Length 1
    char    encrypt             [   1];    // [string,    1] 암호구분                       StartPos 37, Length 1
    char    offset              [   3];    // [long  ,    3] 공통시작지점                   StartPos 38, Length 3
    char    trcode              [   8];    // [string,    8] TRCODE                         StartPos 41, Length 8
    char    compid              [   3];    // [string,    3] 이용사번호                     StartPos 49, Length 3
    char    userid              [  16];    // [string,   16] 사용자ID                       StartPos 52, Length 16
    char    media               [   2];    // [string,    2] 접속매체                       StartPos 68, Length 2
    char    ifid                [   3];    // [string,    3] I/F일련번호                    StartPos 70, Length 3
    char    seq                 [   9];    // [string,    9] 전문일련번호                   StartPos 73, Length 9
    char    trid                [  16];    // [string,   16] TR추적ID                       StartPos 82, Length 16
    char    pubip               [  12];    // [string,   12] 공인IP                         StartPos 98, Length 12
    char    prvip               [  12];    // [string,   12] 사설IP                         StartPos 110, Length 12
    char    pcbpno              [   3];    // [string,    3] 처리지점번호                   StartPos 122, Length 3
    char    bpno                [   3];    // [string,    3] 지점번호                       StartPos 125, Length 3
    char    termno              [   8];    // [string,    8] 단말번호                       StartPos 128, Length 8
    char    lang                [   1];    // [string,    1] 언어구분                       StartPos 136, Length 1
    char    proctm              [   9];    // [long  ,    9] AP처리시간                     StartPos 137, Length 9
    char    msgcode             [   4];    // [string,    4] 메세지코드                     StartPos 146, Length 4
    char    outgu               [   1];    // [string,    1] 메세지출력구분                 StartPos 150, Length 1
    char    compreq             [   1];    // [string,    1] 압축요청구분                   StartPos 151, Length 1
    char    funckey             [   4];    // [string,    4] 기능키                         StartPos 152, Length 4
    char    reqcnt              [   4];    // [long  ,    4] 요청레코드개수                 StartPos 156, Length 4
    char    filler              [   6];    // [string,    6] 예비영역                       StartPos 160, Length 6
    char    cont                [   1];    // [string,    1] 연속구분                       StartPos 166, Length 1
    char    contkey             [  18];    // [string,   18] 연속키값                       StartPos 167, Length 18
    char    varlen              [   2];    // [long  ,    2] 가변시스템길이                 StartPos 185, Length 2
    char    varhdlen            [   2];    // [long  ,    2] 가변해더길이                   StartPos 187, Length 2
    char    varmsglen           [   2];    // [long  ,    2] 가변메시지길이                 StartPos 189, Length 2
    char    trsrc               [   1];    // [string,    1] 조회발원지                     StartPos 191, Length 1
    char    eventid             [   4];    // [string,    4] I/F이벤트ID                    StartPos 192, Length 4
    char    ifinfo              [   4];    // [string,    4] I/F정보                        StartPos 196, Length 4
    char    filler1             [  41];    // [string,   41] 예비영역                       StartPos 200, Length 41
    char    ordchegb            [   2];    // [string,    2] 주문체결구분                   StartPos 241, Length 2
    char    marketgb            [   2];    // [string,    2] 시장구분                       StartPos 243, Length 2
    char    ordgb               [   2];    // [string,    2] 주문구분                       StartPos 245, Length 2
    char    orgordno            [  10];    // [long  ,   10] 원주문번호                     StartPos 247, Length 10
    char    accno1              [  11];    // [string,   11] 계좌번호                       StartPos 257, Length 11
    char    accno2              [   9];    // [string,    9] 계좌번호                       StartPos 268, Length 9
    char    passwd              [   8];    // [string,    8] 비밀번호                       StartPos 277, Length 8
    char    expcode             [  12];    // [string,   12] 종목번호                       StartPos 285, Length 12
    char    shtcode             [   9];    // [string,    9] 단축종목번호                   StartPos 297, Length 9
    char    hname               [  40];    // [string,   40] 종목명                         StartPos 306, Length 40
    char    ordqty              [  16];    // [long  ,   16] 주문수량                       StartPos 346, Length 16
    char    ordprice            [  13];    // [long  ,   13] 주문가격                       StartPos 362, Length 13
    char    hogagb              [   1];    // [string,    1] 주문조건                       StartPos 375, Length 1
    char    etfhogagb           [   2];    // [string,    2] 호가유형코드                   StartPos 376, Length 2
    char    pgmtype             [   2];    // [long  ,    2] 프로그램호가구분               StartPos 378, Length 2
    char    gmhogagb            [   1];    // [long  ,    1] 공매도호가구분                 StartPos 380, Length 1
    char    gmhogayn            [   1];    // [long  ,    1] 공매도가능여부                 StartPos 381, Length 1
    char    singb               [   3];    // [string,    3] 신용구분                       StartPos 382, Length 3
    char    loandt              [   8];    // [string,    8] 대출일                         StartPos 385, Length 8
    char    cvrgordtp           [   1];    // [string,    1] 반대매매주문구분               StartPos 393, Length 1
    char    strtgcode           [   6];    // [string,    6] 전략코드                       StartPos 394, Length 6
    char    groupid             [  20];    // [string,   20] 그룹ID                         StartPos 400, Length 20
    char    ordseqno            [  10];    // [long  ,   10] 주문회차                       StartPos 420, Length 10
    char    prtno               [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 430, Length 10
    char    basketno            [  10];    // [long  ,   10] 바스켓번호                     StartPos 440, Length 10
    char    trchno              [  10];    // [long  ,   10] 트렌치번호                     StartPos 450, Length 10
    char    itemno              [  10];    // [long  ,   10] 아아템번호                     StartPos 460, Length 10
    char    brwmgmyn            [   1];    // [long  ,    1] 차입구분                       StartPos 470, Length 1
    char    mbrno               [   3];    // [long  ,    3] 회원사번호                     StartPos 471, Length 3
    char    procgb              [   1];    // [string,    1] 처리구분                       StartPos 474, Length 1
    char    admbrchno           [   3];    // [string,    3] 관리지점번호                   StartPos 475, Length 3
    char    futaccno            [  20];    // [string,   20] 선물계좌번호                   StartPos 478, Length 20
    char    futmarketgb         [   1];    // [string,    1] 선물상품구분                   StartPos 498, Length 1
    char    tongsingb           [   2];    // [string,    2] 통신매체구분                   StartPos 499, Length 2
    char    lpgb                [   1];    // [string,    1] 유동성공급자구분               StartPos 501, Length 1
    char    dummy               [  20];    // [string,   20] DUMMY                          StartPos 502, Length 20
    char    ordno               [  10];    // [long  ,   10] 주문번호                       StartPos 522, Length 10
    char    ordtm               [   9];    // [string,    9] 주문시각                       StartPos 532, Length 9
    char    prntordno           [  10];    // [long  ,   10] 모주문번호                     StartPos 541, Length 10
    char    mgempno             [   9];    // [string,    9] 관리사원번호                   StartPos 551, Length 9
    char    orgordundrqty       [  16];    // [long  ,   16] 원주문미체결수량               StartPos 560, Length 16
    char    orgordmdfyqty       [  16];    // [long  ,   16] 원주문정정수량                 StartPos 576, Length 16
    char    ordordcancelqty     [  16];    // [long  ,   16] 원주문취소수량                 StartPos 592, Length 16
    char    nmcpysndno          [  10];    // [long  ,   10] 비회원사송신번호               StartPos 608, Length 10
    char    ordamt              [  16];    // [long  ,   16] 주문금액                       StartPos 618, Length 16
    char    bnstp               [   1];    // [string,    1] 매매구분                       StartPos 634, Length 1
    char    spareordno          [  10];    // [long  ,   10] 예비주문번호                   StartPos 635, Length 10
    char    cvrgseqno           [  10];    // [long  ,   10] 반대매매일련번호               StartPos 645, Length 10
    char    rsvordno            [  10];    // [long  ,   10] 예약주문번호                   StartPos 655, Length 10
    char    mtordseqno          [  10];    // [long  ,   10] 복수주문일련번호               StartPos 665, Length 10
    char    spareordqty         [  16];    // [long  ,   16] 예비주문수량                   StartPos 675, Length 16
    char    orduserid           [  16];    // [string,   16] 주문사원번호                   StartPos 691, Length 16
    char    spotordqty          [  16];    // [long  ,   16] 실물주문수량                   StartPos 707, Length 16
    char    ordruseqty          [  16];    // [long  ,   16] 재사용주문수량                 StartPos 723, Length 16
    char    mnyordamt           [  16];    // [long  ,   16] 현금주문금액                   StartPos 739, Length 16
    char    ordsubstamt         [  16];    // [long  ,   16] 주문대용금액                   StartPos 755, Length 16
    char    ruseordamt          [  16];    // [long  ,   16] 재사용주문금액                 StartPos 771, Length 16
    char    ordcmsnamt          [  16];    // [long  ,   16] 수수료주문금액                 StartPos 787, Length 16
    char    crdtuseamt          [  16];    // [long  ,   16] 사용신용담보재사용금           StartPos 803, Length 16
    char    secbalqty           [  16];    // [long  ,   16] 잔고수량                       StartPos 819, Length 16
    char    spotordableqty      [  16];    // [long  ,   16] 실물가능수량                   StartPos 835, Length 16
    char    ordableruseqty      [  16];    // [long  ,   16] 재사용가능수량(매도)           StartPos 851, Length 16
    char    flctqty             [  16];    // [long  ,   16] 변동수량                       StartPos 867, Length 16
    char    secbalqtyd2         [  16];    // [long  ,   16] 잔고수량(D2)                   StartPos 883, Length 16
    char    sellableqty         [  16];    // [long  ,   16] 매도주문가능수량               StartPos 899, Length 16
    char    unercsellordqty     [  16];    // [long  ,   16] 미체결매도주문수량             StartPos 915, Length 16
    char    avrpchsprc          [  13];    // [long  ,   13] 평균매입가                     StartPos 931, Length 13
    char    pchsamt             [  16];    // [long  ,   16] 매입금액                       StartPos 944, Length 16
    char    deposit             [  16];    // [long  ,   16] 예수금                         StartPos 960, Length 16
    char    substamt            [  16];    // [long  ,   16] 대용금                         StartPos 976, Length 16
    char    csgnmnymgn          [  16];    // [long  ,   16] 위탁증거금현금                 StartPos 992, Length 16
    char    csgnsubstmgn        [  16];    // [long  ,   16] 위탁증거금대용                 StartPos 1008, Length 16
    char    crdtpldgruseamt     [  16];    // [long  ,   16] 신용담보재사용금               StartPos 1024, Length 16
    char    ordablemny          [  16];    // [long  ,   16] 주문가능현금                   StartPos 1040, Length 16
    char    ordablesubstamt     [  16];    // [long  ,   16] 주문가능대용                   StartPos 1056, Length 16
    char    ruseableamt         [  16];    // [long  ,   16] 재사용가능금액                 StartPos 1072, Length 16
} SC0_OutBlock, *LPSC0_OutBlock;
#define NAME_SC0_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _SC0_H_
