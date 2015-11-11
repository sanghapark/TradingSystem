///////////////////////////////////////////////////////////////////////////////////////////////////
// 선물/옵션미결제잔고(t0433) ( tuxcode=t0433,headtype=D )
#pragma pack( push, 1 )

#define NAME_t0433     "t0433"

// 기본입력
typedef struct _t0433InBlock
{
    char    accno               [  11];                                      // [string,   11] 계좌번호                       StartPos 0, Length 11
    char    passwd              [   8];                                      // [string,    8] 비밀번호                       StartPos 11, Length 8
    char    cts_expcode         [   8];                                      // [string,    8] CTS_종목번호                   StartPos 19, Length 8
    char    cts_medocd          [   1];                                      // [string,    1] CTS_매매구분                   StartPos 27, Length 1
} t0433InBlock, *LPt0433InBlock;
#define NAME_t0433InBlock     "t0433InBlock"

// 출력
typedef struct _t0433OutBlock
{
    char    tdtsunik            [  18];                                      // [long  ,   18] 매매손익합계                   StartPos 0, Length 18
    char    tmamt               [  18];                                      // [long  ,   18] 미결제약정합계                 StartPos 18, Length 18
    char    cts_expcode         [   8];                                      // [string,    8] CTS_종목번호                   StartPos 36, Length 8
    char    cts_medocd          [   1];                                      // [string,    1] CTS_매매구분                   StartPos 44, Length 1
} t0433OutBlock, *LPt0433OutBlock;
#define NAME_t0433OutBlock     "t0433OutBlock"

// 출력1, occurs
typedef struct _t0433OutBlock1
{
    char    expcode             [   8];                                      // [string,    8] 종목번호                       StartPos 0, Length 8
    char    medosu              [   4];                                      // [string,    4] 구분                           StartPos 8, Length 4
    char    jqty                [  10];                                      // [long  ,   10] 잔고수량                       StartPos 12, Length 10
    char    pamt                [  10];                                      // [float , 10.2] 평균단가                       StartPos 22, Length 10
    char    medocd              [   1];                                      // [string,    1] 매매구분                       StartPos 33, Length 1
    char    mamt                [  18];                                      // [long  ,   18] 총매입금액                     StartPos 34, Length 18
    char    sysprocseq          [  10];                                      // [long  ,   10] 처리순번                       StartPos 52, Length 10
} t0433OutBlock1, *LPt0433OutBlock1;
#define NAME_t0433OutBlock1     "t0433OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
