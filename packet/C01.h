///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물주문체결 ( block )
#pragma pack( push, 1 )

#define NAME_C01     "C01"

// 입력
typedef struct _C01_InBlock
{
} C01_InBlock, *LPC01_InBlock;
#define NAME_C01_InBlock     "InBlock"

// 출력
typedef struct _C01_OutBlock
{
    char    lineseq             [  10];    // [long  ,   10] 라인일련번호                   StartPos 0, Length 10
    char    accno               [  11];    // [string,   11] 계좌번호                       StartPos 10, Length 11
    char    user                [   8];    // [string,    8] 조작자ID                       StartPos 21, Length 8
    char    seq                 [  11];    // [long  ,   11] 일련번호                       StartPos 29, Length 11
    char    trcode              [  11];    // [string,   11] trcode                         StartPos 40, Length 11
    char    typecode            [   1];    // [string,    1] 정규시간외구분                 StartPos 51, Length 1
    char    memberno            [   5];    // [string,    5] 회원번호                       StartPos 52, Length 5
    char    bpno                [   5];    // [string,    5] 지점번호                       StartPos 57, Length 5
    char    ordno               [  10];    // [string,   10] 주문번호                       StartPos 62, Length 10
    char    orgordno            [  10];    // [string,   10] 원주문번호                     StartPos 72, Length 10
    char    expcode             [  12];    // [string,   12] 종목코드                       StartPos 82, Length 12
    char    yakseq              [  11];    // [string,   11] 약정번호                       StartPos 94, Length 11
    char    cheprice            [  11];    // [float , 11.2] 체결가격                       StartPos 105, Length 11
    char    chevol              [  10];    // [long  ,   10] 체결수량                       StartPos 116, Length 10
    char    ordgb               [   2];    // [string,    2] 체결유형                       StartPos 126, Length 2
    char    chedate             [   8];    // [string,    8] 체결일자                       StartPos 128, Length 8
    char    chetime             [   9];    // [string,    9] 체결시각                       StartPos 136, Length 9
    char    spdprc1             [  11];    // [float , 11.2] 최근월체결가격                 StartPos 145, Length 11
    char    spdprc2             [  11];    // [float , 11.2] 차근월체결가격                 StartPos 156, Length 11
    char    dosugb              [   1];    // [string,    1] 매도수구분                     StartPos 167, Length 1
    char    accno1              [  12];    // [string,   12] 계좌번호1                      StartPos 168, Length 12
    char    sihogagb            [  11];    // [string,   11] 시장조성호가구분               StartPos 180, Length 11
    char    jakino              [   5];    // [string,    5] 위탁사번호                     StartPos 191, Length 5
    char    daeyong             [  12];    // [string,   12] 대용주권계좌번호               StartPos 196, Length 12
    char    mem_filler          [   6];    // [string,    6] mem_filler                     StartPos 208, Length 6
    char    mem_accno           [  11];    // [string,   11] mem_accno                      StartPos 214, Length 11
    char    mem_filler1         [  23];    // [string,   23] mem_filler1                    StartPos 225, Length 23
    char    filler              [  81];    // [string,   81] Filler                         StartPos 248, Length 81
} C01_OutBlock, *LPC01_OutBlock;
#define NAME_C01_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
