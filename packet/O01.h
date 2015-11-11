///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물주문접수 ( block )
#pragma pack( push, 1 )

#define NAME_O01     "O01"

// 입력
typedef struct _O01_InBlock
{
} O01_InBlock, *LPO01_InBlock;
#define NAME_O01_InBlock     "InBlock"

// 출력
typedef struct _O01_OutBlock
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
    char    trcode1             [   4];    // [string,    4] tr코드                         StartPos 241, Length 4
    char    firmno              [   3];    // [string,    3] 회사번호                       StartPos 245, Length 3
    char    acntno              [  11];    // [string,   11] 계좌번호                       StartPos 248, Length 11
    char    acntno1             [   9];    // [string,    9] 계좌번호                       StartPos 259, Length 9
    char    acntnm              [  40];    // [string,   40] 계좌명                         StartPos 268, Length 40
    char    brnno               [   3];    // [string,    3] 지점번호                       StartPos 308, Length 3
    char    ordmktcode          [   2];    // [string,    2] 주문시장코드                   StartPos 311, Length 2
    char    ordno1              [   3];    // [string,    3] 주문번호                       StartPos 313, Length 3
    char    ordno               [   7];    // [long  ,    7] 주문번호                       StartPos 316, Length 7
    char    orgordno1           [   3];    // [string,    3] 원주문번호                     StartPos 323, Length 3
    char    orgordno            [   7];    // [long  ,    7] 원주문번호                     StartPos 326, Length 7
    char    prntordno           [   3];    // [string,    3] 모주문번호                     StartPos 333, Length 3
    char    prntordno1          [   7];    // [long  ,    7] 모주문번호                     StartPos 336, Length 7
    char    isuno               [  12];    // [string,   12] 종목번호                       StartPos 343, Length 12
    char    fnoIsuno            [   8];    // [string,    8] 선물옵션종목번호               StartPos 355, Length 8
    char    fnoIsunm            [  40];    // [string,   40] 선물옵션종목명                 StartPos 363, Length 40
    char    pdgrpcode           [   2];    // [string,    2] 상품군분류코드                 StartPos 403, Length 2
    char    fnoIsuptntp         [   1];    // [string,    1] 선물옵션종목유형구분           StartPos 405, Length 1
    char    bnstp               [   1];    // [string,    1] 매매구분                       StartPos 406, Length 1
    char    mrctp               [   1];    // [string,    1] 정정취소구분                   StartPos 407, Length 1
    char    ordqty              [  16];    // [long  ,   16] 주문수량                       StartPos 408, Length 16
    char    hogatype            [   2];    // [string,    2] 호가유형코드                   StartPos 424, Length 2
    char    mmgb                [   2];    // [string,    2] 거래유형코드                   StartPos 426, Length 2
    char    ordprc              [  13];    // [double, 13.2] 주문가격                       StartPos 428, Length 13
    char    unercqty            [  16];    // [long  ,   16] 미체결수량                     StartPos 441, Length 16
    char    commdacode          [   2];    // [string,    2] 통신매체                       StartPos 457, Length 2
    char    peeamtcode          [   2];    // [string,    2] 수수료합산코드                 StartPos 459, Length 2
    char    mgempno             [   9];    // [string,    9] 관리사원                       StartPos 461, Length 9
    char    fnotrdunitamt       [  19];    // [double, 19.8] 선물옵션거래단위금액           StartPos 470, Length 19
    char    trxtime             [   9];    // [string,    9] 처리시각                       StartPos 489, Length 9
    char    strtgcode           [   6];    // [string,    6] 전략코드                       StartPos 498, Length 6
    char    grpId               [  20];    // [string,   20] 그룹Id                         StartPos 504, Length 20
    char    ordseqno            [  10];    // [string,   10] 주문회차                       StartPos 524, Length 10
    char    ptflno              [  10];    // [string,   10] 포트폴리오 번호                StartPos 534, Length 10
    char    bskno               [  10];    // [string,   10] 바스켓번호                     StartPos 544, Length 10
    char    trchno              [  10];    // [string,   10] 트렌치번호                     StartPos 554, Length 10
    char    Itemno              [  10];    // [string,   10] 아이템번호                     StartPos 564, Length 10
    char    userId              [  16];    // [string,   16] 주문자Id                       StartPos 574, Length 16
    char    opdrtnno            [  12];    // [string,   12] 운영지시번호                   StartPos 590, Length 12
    char    rjtcode             [   3];    // [string,    3] 부적격코드                     StartPos 602, Length 3
    char    mrccnfqty           [  16];    // [long  ,   16] 정정취소확인수량               StartPos 605, Length 16
    char    orgordunercqty      [  16];    // [long  ,   16] 원주문미체결수량               StartPos 621, Length 16
    char    orgordmrcqty        [  16];    // [long  ,   16] 원주문정정취소수량             StartPos 637, Length 16
    char    ctrcttime           [   8];    // [string,    8] 약정시각(체결시각)             StartPos 653, Length 8
    char    ctrctno             [  10];    // [string,   10] 약정번호                       StartPos 661, Length 10
    char    execprc             [  13];    // [double, 13.2] 체결가격                       StartPos 671, Length 13
    char    execqty             [  16];    // [long  ,   16] 체결수량                       StartPos 684, Length 16
    char    newqty              [  16];    // [long  ,   16] 신규체결수량                   StartPos 700, Length 16
    char    qdtqty              [  16];    // [long  ,   16] 청산체결수량                   StartPos 716, Length 16
    char    lastqty             [  16];    // [long  ,   16] 최종결제수량                   StartPos 732, Length 16
    char    lallexecqty         [  16];    // [long  ,   16] 전체체결수량                   StartPos 748, Length 16
    char    allexecamt          [  16];    // [long  ,   16] 전체체결금액                   StartPos 764, Length 16
    char    fnobalevaltp        [   1];    // [string,    1] 잔고평가구분                   StartPos 780, Length 1
    char    bnsplamt            [  16];    // [long  ,   16] 매매손익금액                   StartPos 781, Length 16
    char    fnoIsuno1           [   8];    // [string,    8] 선물옵션종목번호1              StartPos 797, Length 8
    char    bnstp1              [   1];    // [string,    1] 매매구분1                      StartPos 805, Length 1
    char    execprc1            [  13];    // [double, 13.2] 체결가1                        StartPos 806, Length 13
    char    newqty1             [  16];    // [long  ,   16] 신규체결수량1                  StartPos 819, Length 16
    char    qdtqty1             [  16];    // [long  ,   16] 청산체결수량1                  StartPos 835, Length 16
    char    allexecamt1         [  16];    // [long  ,   16] 전체체결금액1                  StartPos 851, Length 16
    char    fnoIsuno2           [   8];    // [string,    8] 선물옵션종목번호2              StartPos 867, Length 8
    char    bnstp2              [   1];    // [string,    1] 매매구분2                      StartPos 875, Length 1
    char    execprc2            [  13];    // [double, 13.2] 체결가2                        StartPos 876, Length 13
    char    newqty2             [  16];    // [long  ,   16] 신규체결수량2                  StartPos 889, Length 16
    char    lqdtqty2            [  16];    // [long  ,   16] 청산체결수량2                  StartPos 905, Length 16
    char    allexecamt2         [  16];    // [long  ,   16] 전체체결금액2                  StartPos 921, Length 16
    char    dps                 [  16];    // [long  ,   16] 예수금                         StartPos 937, Length 16
    char    ftsubtdsgnamt       [  16];    // [long  ,   16] 선물대용지정금액               StartPos 953, Length 16
    char    mgn                 [  16];    // [long  ,   16] 증거금                         StartPos 969, Length 16
    char    mnymgn              [  16];    // [long  ,   16] 증거금현금                     StartPos 985, Length 16
    char    ordableamt          [  16];    // [long  ,   16] 주문가능금액                   StartPos 1001, Length 16
    char    mnyordableamt       [  16];    // [long  ,   16] 주문가능현금액                 StartPos 1017, Length 16
    char    fnoIsuno_1          [   8];    // [string,    8] 잔고 종목번호1                 StartPos 1033, Length 8
    char    bnstp_1             [   1];    // [string,    1] 잔고 매매구분1                 StartPos 1041, Length 1
    char    unsttqty_1          [  16];    // [long  ,   16] 미결제수량1                    StartPos 1042, Length 16
    char    lqdtableqty_1       [  16];    // [long  ,   16] 주문가능수량1                  StartPos 1058, Length 16
    char    avrprc_1            [  13];    // [double, 13.2] 평균가1                        StartPos 1074, Length 13
    char    fnoIsuno_2          [   8];    // [string,    8] 잔고 종목번호2                 StartPos 1087, Length 8
    char    bnstp_2             [   1];    // [string,    1] 잔고 매매구분2                 StartPos 1095, Length 1
    char    unsttqty_2          [  16];    // [long  ,   16] 미결제수량2                    StartPos 1096, Length 16
    char    lqdtableqty_2       [  16];    // [long  ,   16] 주문가능수량2                  StartPos 1112, Length 16
    char    avrprc_2            [  13];    // [double, 13.2] 평균가2                        StartPos 1128, Length 13
} O01_OutBlock, *LPO01_OutBlock;
#define NAME_O01_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
