///////////////////////////////////////////////////////////////////////////////////////////////////
// 신호조회(t1809) ( block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1809     "t1809"

// 기본입력
typedef struct _t1809InBlock
{
    char    gubun               [   1];    // [string,    1] 신호구분                       StartPos 0, Length 1
    char    jmGb                [   1];    // [string,    1] 종목구분                       StartPos 1, Length 1
    char    jmcode              [   6];    // [string,    6] 종목코드                       StartPos 2, Length 6
    char    cts                 [  30];    // [string,   30] NEXTKEY                        StartPos 8, Length 30
} t1809InBlock, *LPt1809InBlock;
#define NAME_t1809InBlock     "t1809InBlock"

// 기본출력
typedef struct _t1809OutBlock
{
    char    cts                 [  30];    // [string,   30] NEXTKEY                        StartPos 0, Length 30
} t1809OutBlock, *LPt1809OutBlock;
#define NAME_t1809OutBlock     "t1809OutBlock"

// 기본출력1, occurs
typedef struct _t1809OutBlock1
{
    char    date                [   8];    // [string,    8] 일자                           StartPos 0, Length 8
    char    time                [   6];    // [string,    6] 시간                           StartPos 8, Length 6
    char    signal_id           [   4];    // [string,    4] 신호ID                         StartPos 14, Length 4
    char    signal_desc         [ 300];    // [string,  300] 신호명                         StartPos 18, Length 300
    char    point               [   3];    // [string,    3] 신호강도                       StartPos 318, Length 3
    char    keyword             [  40];    // [string,   40] 뉴스신호키워드                 StartPos 321, Length 40
    char    seq                 [  24];    // [string,   24] 신호별구분                     StartPos 361, Length 24
    char    gubun               [   2];    // [string,    2] 신호구분                       StartPos 385, Length 2
    char    jmcode              [   6];    // [string,    6] 신호종목                       StartPos 387, Length 6
    char    price               [   7];    // [long  ,    7] 종목가격                       StartPos 393, Length 7
    char    sign                [   1];    // [string,    1] 종목등락부호                   StartPos 400, Length 1
    char    chgrate             [   6];    // [float ,  6.2] 대비등락율                     StartPos 401, Length 6
    char    volume              [   9];    // [long  ,    9] 거래량                         StartPos 407, Length 9
    char    datetime            [  16];    // [string,   16] 신호일시                       StartPos 416, Length 16
} t1809OutBlock1, *LPt1809OutBlock1;
#define NAME_t1809OutBlock1     "t1809OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
