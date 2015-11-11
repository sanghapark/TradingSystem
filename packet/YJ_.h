///////////////////////////////////////////////////////////////////////////////////////////////////
// 예상지수(YJ) ( attr,block )
#pragma pack( push, 1 )

#define NAME_YJ_     "YJ_"

// 입력
typedef struct _YJ__InBlock
{
    char    upcode              [   3];    // [string,    3] 업종코드                       StartPos 0, Length 3
} YJ__InBlock, *LPYJ__InBlock;
#define NAME_YJ__InBlock     "InBlock"

// 출력
typedef struct _YJ__OutBlock
{
    char    time                [   6];    char    _time                ;    // [string,    6] 시간                           StartPos 0, Length 6
    char    jisu                [   8];    char    _jisu                ;    // [float ,  8.2] 예상지수                       StartPos 7, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] 예상전일대비구분               StartPos 16, Length 1
    char    change              [   8];    char    _change              ;    // [float ,  8.2] 예상전일비                     StartPos 18, Length 8
    char    drate               [   6];    char    _drate               ;    // [float ,  6.2] 예상등락율                     StartPos 27, Length 6
    char    cvolume             [   8];    char    _cvolume             ;    // [long  ,    8] 예상체결량                     StartPos 34, Length 8
    char    volume              [   8];    char    _volume              ;    // [long  ,    8] 누적거래량                     StartPos 43, Length 8
    char    value               [   8];    char    _value               ;    // [long  ,    8] 예상거래대금                   StartPos 52, Length 8
    char    upcode              [   3];    char    _upcode              ;    // [string,    3] 업종코드                       StartPos 61, Length 3
} YJ__OutBlock, *LPYJ__OutBlock;
#define NAME_YJ__OutBlock     "OutBlock"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////
