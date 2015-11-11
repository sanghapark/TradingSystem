///////////////////////////////////////////////////////////////////////////////////////////////////
// KOSDAQ시간외호가잔량(HB) ( attr,block )
#pragma pack( push, 1 )

#define NAME_HB_     "HB_"

// 입력
typedef struct _HB__InBlock
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
} HB__InBlock, *LPHB__InBlock;
#define NAME_HB__InBlock     "InBlock"

// 출력
typedef struct _HB__OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 0, Length 6
    char    tmofferrem          [  12];    char    _tmofferrem          ;    // [long  ,   12] 시간외매도잔량                 StartPos 7, Length 12
    char    tmbidrem            [  12];    char    _tmbidrem            ;    // [long  ,   12] 시간외매수잔량                 StartPos 20, Length 12
    char    pretmoffercha       [  12];    char    _pretmoffercha       ;    // [long  ,   12] 시간외매도수량직전대비         StartPos 33, Length 12
    char    pretmbidcha         [  12];    char    _pretmbidcha         ;    // [long  ,   12] 시간외매수수량직전대비         StartPos 46, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 59, Length 6
} HB__OutBlock, *LPHB__OutBlock;
#define NAME_HB__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
