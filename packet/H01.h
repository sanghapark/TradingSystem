///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물주문정정취소 ( block )
#pragma pack( push, 1 )

#define NAME_H01     "H01"

// 입력
typedef struct _H01_InBlock
{
} H01_InBlock, *LPH01_InBlock;
#define NAME_H01_InBlock     "InBlock"

// 출력
typedef struct _H01_OutBlock
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
    char    dosugb              [   1];    // [string,    1] 매도수구분                     StartPos 94, Length 1
    char    mocagb              [   1];    // [string,    1] 정정취소구분                   StartPos 95, Length 1
    char    accno1              [  12];    // [string,   12] 계좌번호1                      StartPos 96, Length 12
    char    qty2                [  10];    // [long  ,   10] 호가수량                       StartPos 108, Length 10
    char    price               [  11];    // [float , 11.2] 호가가격                       StartPos 118, Length 11
    char    ordgb               [   1];    // [string,    1] 주문유형                       StartPos 129, Length 1
    char    hogagb              [   1];    // [string,    1] 호가구분                       StartPos 130, Length 1
    char    sihogagb            [  11];    // [string,   11] 시장조성호가구분               StartPos 131, Length 11
    char    tradid              [   5];    // [string,    5] 자사주신고서ID                 StartPos 142, Length 5
    char    treacode            [   1];    // [string,    1] 자사주매매방법                 StartPos 147, Length 1
    char    askcode             [   2];    // [string,    2] 매도유형코드                   StartPos 148, Length 2
    char    creditcode          [   2];    // [string,    2] 신용구분코드                   StartPos 150, Length 2
    char    jakigb              [   2];    // [string,    2] 위탁자기구분                   StartPos 152, Length 2
    char    trustnum            [   5];    // [string,    5] 위탁사번호                     StartPos 154, Length 5
    char    ptgb                [   2];    // [string,    2] 프로그램구분                   StartPos 159, Length 2
    char    substonum           [  12];    // [string,   12] 대용주권계좌번호               StartPos 161, Length 12
    char    accgb               [   2];    // [string,    2] 계좌구분코드                   StartPos 173, Length 2
    char    accmarggb           [   2];    // [string,    2] 계좌증거금코드                 StartPos 175, Length 2
    char    nationcode          [   3];    // [string,    3] 국가코드                       StartPos 177, Length 3
    char    investgb            [   4];    // [string,    4] 투자자구분                     StartPos 180, Length 4
    char    forecode            [   2];    // [string,    2] 외국인코드                     StartPos 184, Length 2
    char    medcode             [   1];    // [string,    1] 주문매체구분                   StartPos 186, Length 1
    char    ordid               [  12];    // [string,   12] 주문식별자번호                 StartPos 187, Length 12
    char    orddate             [   8];    // [string,    8] 호가일자                       StartPos 199, Length 8
    char    rcvtime             [   9];    // [string,    9] 회원사주문시각                 StartPos 207, Length 9
    char    mem_filler          [   6];    // [string,    6] mem_filler                     StartPos 216, Length 6
    char    mem_accno           [  11];    // [string,   11] mem_accno                      StartPos 222, Length 11
    char    mem_filler1         [  23];    // [string,   23] mem_filler1                    StartPos 233, Length 23
    char    qty                 [  10];    // [long  ,   10] 실정정취소수량                 StartPos 256, Length 10
    char    autogb              [   1];    // [string,    1] 자동취소구분                   StartPos 266, Length 1
    char    rejcode             [   4];    // [string,    4] 거부사유                       StartPos 267, Length 4
    char    filler              [  58];    // [string,   58] 필러                           StartPos 271, Length 58
} H01_OutBlock, *LPH01_OutBlock;
#define NAME_H01_OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
