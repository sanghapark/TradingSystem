///////////////////////////////////////////////////////////////////////////////////////////////////
// ELW시간외호가잔량(h2) ( attr,block )
#pragma pack( push, 1 )

#define NAME_h2_     "h2_"

// 입력
typedef struct _h2__InBlock
{
    char    shcode              [   6];    // [string,    6] 단축코드                       StartPos 0, Length 6
} h2__InBlock, *LPh2__InBlock;
#define NAME_h2__InBlock     "InBlock"

// 출력
typedef struct _h2__OutBlock
{
    char    hotime              [   6];    char    _hotime              ;    // [string,    6] 호가시간                       StartPos 0, Length 6
    char    tmofferrem          [  12];    char    _tmofferrem          ;    // [long  ,   12] 시간외매도잔량                 StartPos 7, Length 12
    char    tmbidrem            [  12];    char    _tmbidrem            ;    // [long  ,   12] 시간외매수잔량                 StartPos 20, Length 12
    char    pretmoffercha       [  12];    char    _pretmoffercha       ;    // [long  ,   12] 시간외매도수량직전대비         StartPos 33, Length 12
    char    pretmbidcha         [  12];    char    _pretmbidcha         ;    // [long  ,   12] 시간외매수수량직전대비         StartPos 46, Length 12
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] 단축코드                       StartPos 59, Length 6
} h2__OutBlock, *LPh2__OutBlock;
#define NAME_h2__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
