///////////////////////////////////////////////////////////////////////////////////////////////////
// 계좌별예수금조회(t6011) ( base21=SONAQ109,headtype=B )
#pragma pack( push, 1 )

#define NAME_t6011     "t6011"

// 기본입력
typedef struct _t6011InBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    kwbpno              [   3];    // [string,    3] 관리지점번호                   StartPos 5, Length 3
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 8, Length 20
    char    passwd              [   8];    // [string,    8] 비밀번호                       StartPos 28, Length 8
    char    jangb               [   1];    // [string,    1] 잔고생성구분                   StartPos 36, Length 1
} t6011InBlock, *LPt6011InBlock;
#define NAME_t6011InBlock     "t6011InBlock"

// 기본출력
typedef struct _t6011OutBlock
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    kwbpno              [   3];    // [string,    3] 관리지점번호                   StartPos 5, Length 3
    char    accno               [  20];    // [string,   20] 계좌번호                       StartPos 8, Length 20
    char    passwd              [   8];    // [string,    8] 비밀번호                       StartPos 28, Length 8
    char    jangb               [   1];    // [string,    1] 잔고생성구분                   StartPos 36, Length 1
} t6011OutBlock, *LPt6011OutBlock;
#define NAME_t6011OutBlock     "t6011OutBlock"

// 기본출력1
typedef struct _t6011OutBlock1
{
    char    reccnt              [   5];    // [long  ,    5] 레코드갯수                     StartPos 0, Length 5
    char    bpname              [  40];    // [string,   40] 지점명                         StartPos 5, Length 40
    char    name                [  40];    // [string,   40] 계좌명                         StartPos 45, Length 40
    char    ordcamt             [  16];    // [long  ,   16] 현금주문가능금액               StartPos 85, Length 16
    char    drawamt             [  16];    // [long  ,   16] 출금가능금액                   StartPos 101, Length 16
    char    kospiamt            [  16];    // [long  ,   16] 거래소금액                     StartPos 117, Length 16
    char    kosdaqamt           [  16];    // [long  ,   16] 코스닥금액                     StartPos 133, Length 16
    char    evlamt              [  16];    // [long  ,   16] 평가금액                       StartPos 149, Length 16
    char    sunapsum            [  16];    // [long  ,   16] 미수금액                       StartPos 165, Length 16
    char    yetaktot            [  16];    // [long  ,   16] 예탁자산총액                   StartPos 181, Length 16
    char    sonik               [  12];    // [double, 12.6] 손익률                         StartPos 197, Length 12
    char    tujawon             [  20];    // [long  ,   20] 투자원금                       StartPos 209, Length 20
    char    tujason             [  16];    // [long  ,   16] 투자손익금액                   StartPos 229, Length 16
    char    sindambo            [  16];    // [long  ,   16] 신용담보주문금액               StartPos 245, Length 16
    char    depoamt             [  16];    // [long  ,   16] 예수금                         StartPos 261, Length 16
    char    daeamt              [  16];    // [long  ,   16] 대용금액                       StartPos 277, Length 16
    char    d1depoamt           [  16];    // [long  ,   16] D1예수금                       StartPos 293, Length 16
    char    d2depoamt           [  16];    // [long  ,   16] D2예수금                       StartPos 309, Length 16
    char    cashamt             [  16];    // [long  ,   16] 현금미수금액                   StartPos 325, Length 16
    char    margincash          [  16];    // [long  ,   16] 증거금현금                     StartPos 341, Length 16
    char    margindae           [  16];    // [long  ,   16] 증거금대용                     StartPos 357, Length 16
    char    supyoamt            [  16];    // [long  ,   16] 수표금액                       StartPos 373, Length 16
    char    ordcamtdae          [  16];    // [long  ,   16] 대용주문가능금액               StartPos 389, Length 16
    char    ord100              [  16];    // [long  ,   16] 증거금률100퍼센트주문가능금액  StartPos 405, Length 16
    char    inordamt            [  16];    // [long  ,   16] 증거금률35%주문가능금액        StartPos 421, Length 16
    char    ord50               [  16];    // [long  ,   16] 증거금률50%주문가능금액        StartPos 437, Length 16
    char    dmdosoamt           [  16];    // [long  ,   16] 전일매도정산금액               StartPos 453, Length 16
    char    dmsusoamt           [  16];    // [long  ,   16] 전일매수정산금액               StartPos 469, Length 16
    char    todosoamt           [  16];    // [long  ,   16] 금일매도정산금액               StartPos 485, Length 16
    char    tosusoamt           [  16];    // [long  ,   16] 금일매수정산금액               StartPos 501, Length 16
    char    dmpayneed           [  16];    // [long  ,   16] D1연체변제소요금액             StartPos 517, Length 16
    char    topayneed           [  16];    // [long  ,   16] D2연체변제소요금액             StartPos 533, Length 16
    char    d1drawamt           [  16];    // [long  ,   16] D1추정인출가능금액             StartPos 549, Length 16
    char    d2drawamt           [  16];    // [long  ,   16] D2추정인출가능금액             StartPos 565, Length 16
    char    dambore             [  16];    // [long  ,   16] 예탁담보대출금액               StartPos 581, Length 16
    char    limreq              [  16];    // [long  ,   16] 신용설정보증금                 StartPos 597, Length 16
    char    loanamt             [  16];    // [long  ,   16] 융자금액                       StartPos 613, Length 16
    char    damborate           [   9];    // [double,  9.3] 담보비율                       StartPos 629, Length 9
    char    cashjan             [  16];    // [long  ,   16] 원담보금액                     StartPos 638, Length 16
    char    bucashjan           [  16];    // [long  ,   16] 부담보금액                     StartPos 654, Length 16
    char    needdambo           [  16];    // [long  ,   16] 소요담보금액                   StartPos 670, Length 16
    char    orgdambo            [  16];    // [long  ,   16] 원담보부족금액                 StartPos 686, Length 16
    char    dambolack           [  16];    // [long  ,   16] 담보부족금액                   StartPos 702, Length 16
    char    chugadambo          [  16];    // [long  ,   16] 추가담보현금                   StartPos 718, Length 16
    char    d1jumun             [  16];    // [long  ,   16] D1주문가능금액                 StartPos 734, Length 16
    char    sinimnap            [  16];    // [long  ,   16] 신용이자미납금액               StartPos 750, Length 16
    char    etcloan             [  16];    // [long  ,   16] 기타대여금액                   StartPos 766, Length 16
    char    nextbandae          [  16];    // [long  ,   16] 익일추정반대매매금액           StartPos 782, Length 16
    char    cashjantot          [  16];    // [long  ,   16] 원담보합계금액                 StartPos 798, Length 16
    char    sinordamt           [  16];    // [long  ,   16] 신용주문가능금액               StartPos 814, Length 16
    char    bucashjantot        [  16];    // [long  ,   16] 부담보합계금액                 StartPos 830, Length 16
    char    sindamcash          [  16];    // [long  ,   16] 신용담보금현금                 StartPos 846, Length 16
    char    sindamdae           [  16];    // [long  ,   16] 신용담보대용금액               StartPos 862, Length 16
    char    addsindamcash       [  16];    // [long  ,   16] 추가신용담보현금               StartPos 878, Length 16
    char    sindamreuseamt      [  16];    // [long  ,   16] 신용담보재사용금액             StartPos 894, Length 16
    char    addsindamdae        [  16];    // [long  ,   16] 추가신용담보대용               StartPos 910, Length 16
    char    mddaedamloanamt     [  16];    // [long  ,   16] 매도대금담보대출금액           StartPos 926, Length 16
    char    chlimitamt          [  16];    // [long  ,   16] 처분제한금액                   StartPos 942, Length 16
} t6011OutBlock1, *LPt6011OutBlock1;
#define NAME_t6011OutBlock1     "t6011OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
