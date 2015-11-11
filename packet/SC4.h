#ifndef _SC4_H_
#define _SC4_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// 주식주문거부 ( block )
#pragma pack( push, 1 )

#define NAME_SC4     "SC4"

// 입력
typedef struct _SC4_InBlock
{
} SC4_InBlock, *LPSC4_InBlock;
#define NAME_SC4_InBlock     "InBlock"

// 출력
typedef struct _SC4_OutBlock
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
    char    ordxctptncode       [   2];    // [string,    2] 주문체결유형코드               StartPos 241, Length 2
    char    ordmktcode          [   2];    // [string,    2] 주문시장코드                   StartPos 243, Length 2
    char    ordptncode          [   2];    // [string,    2] 주문유형코드                   StartPos 245, Length 2
    char    mgmtbrnno           [   3];    // [string,    3] 관리지점번호                   StartPos 247, Length 3
    char    accno1              [  11];    // [string,   11] 계좌번호                       StartPos 250, Length 11
    char    accno2              [   9];    // [string,    9] 계좌번호                       StartPos 261, Length 9
    char    acntnm              [  40];    // [string,   40] 계좌명                         StartPos 270, Length 40
    char    Isuno               [  12];    // [string,   12] 종목번호                       StartPos 310, Length 12
    char    Isunm               [  40];    // [string,   40] 종목명                         StartPos 322, Length 40
    char    ordno               [  10];    // [long  ,   10] 주문번호                       StartPos 362, Length 10
    char    orgordno            [  10];    // [long  ,   10] 원주문번호                     StartPos 372, Length 10
    char    execno              [  10];    // [long  ,   10] 체결번호                       StartPos 382, Length 10
    char    ordqty              [  16];    // [long  ,   16] 주문수량                       StartPos 392, Length 16
    char    ordprc              [  13];    // [long  ,   13] 주문가격                       StartPos 408, Length 13
    char    execqty             [  16];    // [long  ,   16] 체결수량                       StartPos 421, Length 16
    char    execprc             [  13];    // [long  ,   13] 체결가격                       StartPos 437, Length 13
    char    mdfycnfqty          [  16];    // [long  ,   16] 정정확인수량                   StartPos 450, Length 16
    char    mdfycnfprc          [  16];    // [long  ,   16] 정정확인가격                   StartPos 466, Length 16
    char    canccnfqty          [  16];    // [long  ,   16] 취소확인수량                   StartPos 482, Length 16
    char    rjtqty              [  16];    // [long  ,   16] 거부수량                       StartPos 498, Length 16
    char    ordtrxptncode       [   4];    // [long  ,    4] 주문처리유형코드               StartPos 514, Length 4
    char    mtiordseqno         [  10];    // [long  ,   10] 복수주문일련번호               StartPos 518, Length 10
    char    ordcndi             [   1];    // [string,    1] 주문조건                       StartPos 528, Length 1
    char    ordprcptncode       [   2];    // [string,    2] 호가유형코드                   StartPos 529, Length 2
    char    nsavtrdqty          [  16];    // [long  ,   16] 비저축체결수량                 StartPos 531, Length 16
    char    shtnIsuno           [   9];    // [string,    9] 단축종목번호                   StartPos 547, Length 9
    char    opdrtnno            [  12];    // [string,   12] 운용지시번호                   StartPos 556, Length 12
    char    cvrgordtp           [   1];    // [string,    1] 반대매매주문구분               StartPos 568, Length 1
    char    unercqty            [  16];    // [long  ,   16] 미체결수량(주문)               StartPos 569, Length 16
    char    orgordunercqty      [  16];    // [long  ,   16] 원주문미체결수량               StartPos 585, Length 16
    char    orgordmdfyqty       [  16];    // [long  ,   16] 원주문정정수량                 StartPos 601, Length 16
    char    orgordcancqty       [  16];    // [long  ,   16] 원주문취소수량                 StartPos 617, Length 16
    char    ordavrexecprc       [  13];    // [long  ,   13] 주문평균체결가격               StartPos 633, Length 13
    char    ordamt              [  16];    // [long  ,   16] 주문금액                       StartPos 646, Length 16
    char    stdIsuno            [  12];    // [string,   12] 표준종목번호                   StartPos 662, Length 12
    char    bfstdIsuno          [  12];    // [string,   12] 전표준종목번호                 StartPos 674, Length 12
    char    bnstp               [   1];    // [string,    1] 매매구분                       StartPos 686, Length 1
    char    ordtrdptncode       [   2];    // [string,    2] 주문거래유형코드               StartPos 687, Length 2
    char    mgntrncode          [   3];    // [string,    3] 신용거래코드                   StartPos 689, Length 3
    char    adduptp             [   2];    // [string,    2] 수수료합산코드                 StartPos 692, Length 2
    char    commdacode          [   2];    // [string,    2] 통신매체코드                   StartPos 694, Length 2
    char    Loandt              [   8];    // [string,    8] 대출일                         StartPos 696, Length 8
    char    mbrnmbrno           [   3];    // [long  ,    3] 회원/비회원사번호              StartPos 704, Length 3
    char    ordacntno           [  20];    // [string,   20] 주문계좌번호                   StartPos 707, Length 20
    char    agrgbrnno           [   3];    // [string,    3] 집계지점번호                   StartPos 727, Length 3
    char    mgempno             [   9];    // [string,    9] 관리사원번호                   StartPos 730, Length 9
    char    futsLnkbrnno        [   3];    // [string,    3] 선물연계지점번호               StartPos 739, Length 3
    char    futsLnkacntno       [  20];    // [string,   20] 선물연계계좌번호               StartPos 742, Length 20
    char    futsmkttp           [   1];    // [string,    1] 선물시장구분                   StartPos 762, Length 1
    char    regmktcode          [   2];    // [string,    2] 등록시장코드                   StartPos 763, Length 2
    char    mnymgnrat           [   7];    // [long  ,    7] 현금증거금률                   StartPos 765, Length 7
    char    substmgnrat         [   9];    // [long  ,    9] 대용증거금률                   StartPos 772, Length 9
    char    mnyexecamt          [  16];    // [long  ,   16] 현금체결금액                   StartPos 781, Length 16
    char    ubstexecamt         [  16];    // [long  ,   16] 대용체결금액                   StartPos 797, Length 16
    char    cmsnamtexecamt      [  16];    // [long  ,   16] 수수료체결금액                 StartPos 813, Length 16
    char    crdtpldgexecamt     [  16];    // [long  ,   16] 신용담보체결금액               StartPos 829, Length 16
    char    crdtexecamt         [  16];    // [long  ,   16] 신용체결금액                   StartPos 845, Length 16
    char    prdayruseexecval    [  16];    // [long  ,   16] 전일재사용체결금액             StartPos 861, Length 16
    char    crdayruseexecval    [  16];    // [long  ,   16] 금일재사용체결금액             StartPos 877, Length 16
    char    spotexecqty         [  16];    // [long  ,   16] 실물체결수량                   StartPos 893, Length 16
    char    stslexecqty         [  16];    // [long  ,   16] 공매도체결수량                 StartPos 909, Length 16
    char    strtgcode           [   6];    // [string,    6] 전략코드                       StartPos 925, Length 6
    char    grpId               [  20];    // [string,   20] 그룹Id                         StartPos 931, Length 20
    char    ordseqno            [  10];    // [long  ,   10] 주문회차                       StartPos 951, Length 10
    char    ptflno              [  10];    // [long  ,   10] 포트폴리오번호                 StartPos 961, Length 10
    char    bskno               [  10];    // [long  ,   10] 바스켓번호                     StartPos 971, Length 10
    char    trchno              [  10];    // [long  ,   10] 트렌치번호                     StartPos 981, Length 10
    char    itemno              [  10];    // [long  ,   10] 아이템번호                     StartPos 991, Length 10
    char    orduserId           [  16];    // [string,   16] 주문자Id                       StartPos 1001, Length 16
    char    brwmgmtYn           [   1];    // [long  ,    1] 차입관리여부                   StartPos 1017, Length 1
    char    frgrunqno           [   6];    // [string,    6] 외국인고유번호                 StartPos 1018, Length 6
    char    trtzxLevytp         [   1];    // [string,    1] 거래세징수구분                 StartPos 1024, Length 1
    char    lptp                [   1];    // [string,    1] 유동성공급자구분               StartPos 1025, Length 1
    char    exectime            [   9];    // [string,    9] 체결시각                       StartPos 1026, Length 9
    char    rcptexectime        [   9];    // [string,    9] 거래소수신체결시각             StartPos 1035, Length 9
    char    rmndLoanamt         [  16];    // [long  ,   16] 잔여대출금액                   StartPos 1044, Length 16
    char    secbalqty           [  16];    // [long  ,   16] 잔고수량                       StartPos 1060, Length 16
    char    spotordableqty      [  16];    // [long  ,   16] 실물가능수량                   StartPos 1076, Length 16
    char    ordableruseqty      [  16];    // [long  ,   16] 재사용가능수량(매도)           StartPos 1092, Length 16
    char    flctqty             [  16];    // [long  ,   16] 변동수량                       StartPos 1108, Length 16
    char    secbalqtyd2         [  16];    // [long  ,   16] 잔고수량(d2)                   StartPos 1124, Length 16
    char    sellableqty         [  16];    // [long  ,   16] 매도주문가능수량               StartPos 1140, Length 16
    char    unercsellordqty     [  16];    // [long  ,   16] 미체결매도주문수량             StartPos 1156, Length 16
    char    avrpchsprc          [  13];    // [long  ,   13] 평균매입가                     StartPos 1172, Length 13
    char    pchsant             [  16];    // [long  ,   16] 매입금액                       StartPos 1185, Length 16
    char    deposit             [  16];    // [long  ,   16] 예수금                         StartPos 1201, Length 16
    char    substamt            [  16];    // [long  ,   16] 대용금                         StartPos 1217, Length 16
    char    csgnmnymgn          [  16];    // [long  ,   16] 위탁증거금현금                 StartPos 1233, Length 16
    char    csgnsubstmgn        [  16];    // [long  ,   16] 위탁증거금대용                 StartPos 1249, Length 16
    char    crdtpldgruseamt     [  16];    // [long  ,   16] 신용담보재사용금               StartPos 1265, Length 16
    char    ordablemny          [  16];    // [long  ,   16] 주문가능현금                   StartPos 1281, Length 16
    char    ordablesubstamt     [  16];    // [long  ,   16] 주문가능대용                   StartPos 1297, Length 16
    char    ruseableamt         [  16];    // [long  ,   16] 재사용가능금액                 StartPos 1313, Length 16
} SC4_OutBlock, *LPSC4_OutBlock;
#define NAME_SC4_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _SC4_H_
