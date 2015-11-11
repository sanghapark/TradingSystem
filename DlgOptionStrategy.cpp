// DlgOptionStrategy.cpp

#include <ctime>
#include "stdafx.h"
#include "DlgOptionStrategy.h"
#include "DlgOptionManager.h"
#include "Constants.h"
#include "LongPosition.h"
#include "ShortPosition.h"
#include "OptionManager.h"
#include "MathCalculator.h"
#include "./packet/t2101.h"
#include "./packet/t2301.h"
#include "./packet/t3521.h"
#include "TradingSystem.h"
#include "TradingSystemManager.h"
#include "DataConverter.h"

IMPLEMENT_DYNCREATE(CDlgOptionStrategy, CDialog)

BEGIN_MESSAGE_MAP(CDlgOptionStrategy, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_OPTION_MONTH, &CDlgOptionStrategy::SelectComboboxOptionMonth)
	ON_BN_CLICKED(IDC_BUTTON_SELECT_OPTION, &CDlgOptionStrategy::OnButtonClickedRequestData)
	ON_BN_CLICKED(IDC_CHECK_AUTO_CALCULATION, &CDlgOptionStrategy::OnButtonClickedAutoCalculate)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgOptionStrategy::OnButtonClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDlgOptionStrategy::OnButtonClickedCreateStrategy)
	ON_BN_CLICKED(IDC_BUTTON_OPTION_VALUE_CHART, &CDlgOptionStrategy::OnButtonClickedDrawValueCurve)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CDlgOptionStrategy::OnButtonClickedDeletePosition)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_STRATEGY, &CDlgOptionStrategy::OnButtonClickedDeleteStrategy)
	ON_WM_TIMER() // OnTimer 호출하는 메세지
	ON_MESSAGE	 ( WM_USER + XM_RECEIVE_DATA, &CDlgOptionStrategy::OnXMReceiveData	  )
	ON_MESSAGE	 ( WM_USER + XM_TIMEOUT_DATA, &CDlgOptionStrategy::OnXMTimeoutData	  )
	ON_NOTIFY(GVN_SELCHANGED, IDC_CUSTOM_OPTION_LIST, &CDlgOptionStrategy::OnGridOptionListEndSelChange)
	ON_NOTIFY(GVN_SELCHANGING, IDC_CUSTOM_OPTION_LIST, &CDlgOptionStrategy::OnGridOptionListStartSelChange)

	ON_NOTIFY(GVN_SELCHANGED, IDC_CUSTOM_OPTION_STRATEGY_LIST, &CDlgOptionStrategy::OnGridOptionStrategyEndSelChange)
	ON_NOTIFY(GVN_SELCHANGING, IDC_CUSTOM_OPTION_STRATEGY_LIST, &CDlgOptionStrategy::OnGridOptionStrategyStartSelChange)
END_MESSAGE_MAP()




CDlgOptionStrategy::CDlgOptionStrategy(CWnd* pParent)
	:CDialog(CDlgOptionStrategy::IDD, pParent){

	this->pParentView = 0;
	this->pDlgOptionManager = 0;

	this->xingAPI = theApp.xingAPI;


	this->optionManager = &(theApp.tradingSystemManager->GetOptionManager());

	this->statusTimeNowTimer = 1;
	this->statusAutoCalTimer = 2;

	this->t2101Received = FALSE;
	this->t2301_1Received = FALSE;
	this->t2301_2Received = FALSE;
	this->t3521Received = FALSE;

	this->undelyingAssetPrice = 0.0;
	this->historicalVol = 0.0;
	this->riskFreeRate = 0.0;
	this->expiryRatio = 0.0;
	this->expiryRatioByDayCount = 0.0;

	this->selectedStrategyIndex = -1;

	this->pointInWON = 500000.0;
}



CDlgOptionStrategy::~CDlgOptionStrategy(){
	if(this->pDlgOptionManager!=0){
		delete this->pDlgOptionManager;
	}
}


BOOL CDlgOptionStrategy::OnInitDialog(){
	CDialog::OnInitDialog();

	this->gridCtrl.AutoSize();
	this->gridCtrl.ExpandColumnsToFit();

	this->gridCtrlOptionList.AutoSize();
	this->gridCtrlOptionList.ExpandColumnsToFit();

	this->gridCtrlOptionStrategyList.AutoSize();
	this->gridCtrlOptionStrategyList.ExpandColumnsToFit();


	// 디폴트로 일초에 한번씩 자동 조회
	this->editAutoSeconds.SetWindowText(_T("1"));

	CString cstrPointInWON;
	cstrPointInWON.Format(_T("%.0f"), this->pointInWON);
	this->editPointInWON.SetWindowText(cstrPointInWON);

	this->InitComboboxOptionMonth();
	return TRUE;
}



void CDlgOptionStrategy::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_POINT_IN_WON, this->editPointInWON);
	DDX_Control(pDX, IDC_EDIT_NAME, this->editName);
	DDX_Control(pDX, IDC_EDIT_OPTION_CODE, this->editCode);
	DDX_Control(pDX, IDC_EDIT_RISK_FREE_RATE, this->editRate);

	
	DDX_Control(pDX, IDC_EDIT_VOL, this->editVol);
	DDX_Control(pDX, IDC_EDIT_UNDERLYING_ASSET_PRICE, this->editUnderlyingPrice);
	DDX_Control(pDX, IDC_EDIT_NUMBER_CONTRACT, this->editContractCount);

	DDX_Control(pDX, IDC_RADIO_LONG, this->radioLong);
	DDX_Control(pDX, IDC_RADIO_SHORT, this->radioShort);

	DDX_Control(pDX, IDC_RADIO_PREMIUM_MARKET, this->radioPremiumMarket);
	DDX_Control(pDX, IDC_RADIO_PREMIUM_THEO, this->radioPremiumTheo);

	DDX_Control(pDX, IDC_BUTTON_SELECT_OPTION, this->buttonSelectOption);
	DDX_Control(pDX, IDC_CHECK_AUTO_CALCULATION, this->buttonAutoPremiumCalculate);
	DDX_Control(pDX, IDC_BUTTON_ADD, this->buttonAdd);
	DDX_Control(pDX, IDC_BUTTON_DELETE, this->buttonDelete);
	//DDX_Control(pDX, IDC_BUTTON_EDIT, this->buttonEdit);
	DDX_Control(pDX, IDC_BUTTON_SAVE, this->buttonSave);

	DDX_Control(pDX, IDC_DATETIMEPICKER_FROM_DATE, this->dateFrom);
	DDX_Control(pDX, IDC_DATETIMEPICKER_TO_TIME, this->timeTo);
	DDX_Control(pDX, IDC_DATETIMEPICKER_TO_DATE, this->dateTo);
	DDX_Control(pDX, IDC_DATETIMEPICKER_NOW_TIME, this->timeNow);
	DDX_Control(pDX, IDC_DATETIMEPICKER_NOW_DATE, this->dateNow);
	DDX_Control(pDX, IDC_DATETIMEPICKER_MARKET_OPEN_TIME, this->marketOpenTime);
	DDX_Control(pDX, IDC_DATETIMEPICKER_MARKET_CLOSE_TIME, this->marketCloseTime);
	DDX_Control(pDX, IDC_EDIT_EXP_TIME, this->editTimeLeft);
	DDX_Control(pDX, IDC_EDIT_DAYS_LEFT, this->editDaysLeft);
	DDX_Control(pDX, IDC_EDIT_EXPIRY_RATIO2, this->editExpiryRatio2);

	DDX_Control(pDX, IDC_EDIT_SECONDS, this->editAutoSeconds);

	DDX_Control(pDX, IDC_COMBO_OPTION_MONTH, this->comboboxOptionMonth);
	DDX_Control(pDX, IDC_CUSTOM_OPTION_LIST, this->gridCtrlOptionList);
	DDX_Control(pDX, IDC_CUSTOM_GRID_POSITIONS, this->gridCtrl);
	DDX_Control(pDX, IDC_CUSTOM_OPTION_STRATEGY_LIST, this->gridCtrlOptionStrategyList);
	DDX_Control(pDX, IDC_BUTTON_DELETE_STRATEGY, this->buttonDeleteOptionStrategy);
	DDX_Control(pDX, IDC_BUTTON_OPTION_VALUE_CHART, this->buttonDrawValueCurve);
}



void CDlgOptionStrategy::OnButtonClickedAdd(){
	// 데이터 읽어오기

	CString cstrNumContract;
	tstring tstrNumContract;
	this->editContractCount.GetWindowText(cstrNumContract);
	tstrNumContract = cstrNumContract;

	CString tempCode;
	tstring code;
	
	// tstring Option Code
	this->editCode.GetWindowText(tempCode);
	code = tempCode;

	if(code.empty()==false){
		if(DataConverter::CheckIfNumber(tstrNumContract)==true ){
			OptionParameter optionParameter;


			CString tempPosition;
			tstring position;

			tstring temp;

			optionParameter = this->optionPriceBoard.GetOptionParameterByOptionCode(code);

			// tstring position
			position = this->GetCheckedRadioButtonPosition();
			optionParameter.SetPosition(position);

			int numContract = DataConverter::ConvertStringToInt(tstrNumContract);

			optionParameter.SetNumContract(numContract);


			// 포지셔 고유 번호 생성
			int positionNumber = this->gridCtrl.GetRowCount();

			// 선택된 전략이름 가져오기
			int rowIndex = this->gridCtrlOptionStrategyList.GetSelectedCellRange().GetMinRow();
			CString strategyName = this->gridCtrlOptionStrategyList.GetStrategyName(rowIndex);


			// Position 생성해서 PositionList에 생성한다.
			BOOL ret = this->TakeAPosition(optionParameter, positionNumber, strategyName);

			if(ret==TRUE){
				tstring tstrName = strategyName;
				int strategyIndex = this->optionManager->GetOptionStrategyList().FindOptionStrategy(tstrName);
				if(strategyIndex>=0){
					this->gridCtrl.RefreshOptionPositions(this->optionManager->GetOptionStrategyList().GetAt(strategyIndex));
				}
			}
		}
		else{
			MessageBox(_T("숫자를 입력 하세요."));
		}
	}
	else{
		MessageBox(_T("옵션을 선택하세요."));
	}
}



void CDlgOptionStrategy::OnButtonClickedCreateStrategy(){
	// 생성된 PositionList를 OptionStrategyList에 저장한다.
	
	CString tempName;
	tstring name;

	this->editName.GetWindowText(tempName);
	name = tempName;

	if(name.compare(_T(""))!=0){
		int index = -1;
		name = DataConverter::TrimFromStartAndEnd(name);
		index = this->optionManager->FindOptionStrategy(name);
		if(index<0){
			
			/*
			this->positionList.SetName(name);
			int indexAdded = this->optionManager->AddOptionStrategy(this->positionList);
			if(indexAdded >= 0){
				MessageBox(_T("Successfuly Added"));
			}
			*/

			int indexAdded = this->optionManager->CreateOptionStrategy(name);

			OptionStrategyList& strategyList = this->optionManager->GetOptionStrategyList();

			this->gridCtrlOptionStrategyList.RefreshOptionStrategy(strategyList);

			this->gridCtrl.RefreshOptionPositions(strategyList.GetAt(indexAdded));

			
		}
		else{
			MessageBox(_T("Option Starategy with same name already exits!"));
		}
	}
	else{
		MessageBox(_T("Name option strategy!"));
	}
	
}


CString CDlgOptionStrategy::GetCheckedRadioButtonType(){
	CString ret;
	int checkedButton = this->GetCheckedRadioButton(IDC_RADIO_CALL, IDC_RADIO_PUT);

	switch(checkedButton){
	case IDC_RADIO_CALL:
		ret = TEXT("call");
		break;
	case IDC_RADIO_PUT:
		ret = TEXT("put");
		break;
	default:
		ret = TEXT("");
		break;
	}
	return ret;	
}

CString CDlgOptionStrategy::GetCheckedRadioButtonPosition(){
	CString ret;
	int checkedButton = this->GetCheckedRadioButton(IDC_RADIO_SHORT, IDC_RADIO_LONG);

	switch(checkedButton){
	case IDC_RADIO_LONG:
		ret = LONG_POSITION;
		break;
	case IDC_RADIO_SHORT:
		ret = SHORT_POSITION;
		break;
	default:
		ret = _T("");
		break;
	}
	return ret;	
}


CString CDlgOptionStrategy::GetCheckedRadioButtonPremium(){
	CString ret;
	int checkedButton = this->GetCheckedRadioButton(IDC_RADIO_PREMIUM_MARKET, IDC_RADIO_PREMIUM_THEO);

	switch(checkedButton){
	case IDC_RADIO_PREMIUM_MARKET:
		ret = MARKET;
		break;
	case IDC_RADIO_PREMIUM_THEO:
		ret = THEO;
		break;
	default:
		ret = _T("");
		break;
	}
	return ret;	
}





BOOL CDlgOptionStrategy::TakeAPosition(const OptionParameter& optionParameter, int positionNumber , CString strategyName){
	BOOL ret = FALSE;
	Position* pPosition = 0;
	EuropeanOption option(optionParameter.GetOptionCode(),_T("KOSPI200"), optionParameter.GetOptionType(), optionParameter.GetStrikePrice());

	double premium = 0.0;
	tstring tstrPremium = this->GetCheckedRadioButtonPremium();
	if(tstrPremium.compare(MARKET)==0){
		premium = optionParameter.GetPremiumMarket();
	}
	else if(tstrPremium.compare(THEO)==0){
		premium = optionParameter.GetPremium();
	}

	if(optionParameter.GetPosition().compare(LONG_POSITION)==0){
		pPosition = new LongPosition(option, premium, optionParameter.GetNumContract());
	}
	else if(optionParameter.GetPosition().compare(SHORT_POSITION)==0){
		pPosition = new ShortPosition(option, premium, optionParameter.GetNumContract());
	}

	pPosition->SetPositionNumber(positionNumber);

	tstring tstrName = strategyName;
	int index = this->optionManager->FindOptionStrategy(tstrName);

	if(index >=0){
		this->optionManager->GetOptionStrategyList().GetAt(index).AddPosition(pPosition);
		ret = TRUE;
	}
	else{
		MessageBox(_T("옵션 전략을 생성해주세요."));
	}
	//this->positionList.AddPosition(pPosition);
	return ret;
}



void CDlgOptionStrategy::OnTimer(UINT_PTR nIDEvent){
	if(nIDEvent == this->statusTimeNowTimer){
		this->ResetCurrentDateTime();
	}
	else if(nIDEvent == this->statusAutoCalTimer){
		this->RequestData();
	}
}


void CDlgOptionStrategy::InitOptionLifePeriodCtrls(){
	
	// Date
	int intIssueYear = DataConverter::ConvertStringToInt(this->expiryCalculator.GetIssueDate().substr(0,4));
	int intIssueMonth = DataConverter::ConvertStringToInt(this->expiryCalculator.GetIssueDate().substr(4,2));
	int intIssueDay = DataConverter::ConvertStringToInt(this->expiryCalculator.GetIssueDate().substr(6,2));

	int intExpiryYear = DataConverter::ConvertStringToInt(this->expiryCalculator.GetExpiryDate().substr(0,4));
	int intExpiryMonth = DataConverter::ConvertStringToInt(this->expiryCalculator.GetExpiryDate().substr(4,2));
	int intExpiryDay = DataConverter::ConvertStringToInt(this->expiryCalculator.GetExpiryDate().substr(6,2));


	COleDateTime issueDate(intIssueYear, intIssueMonth, intIssueDay, 0, 0, 0);
	COleDateTime expiryDate(intExpiryYear, intExpiryMonth, intExpiryDay, 0, 0, 0);

	this->dateFrom.SetTime(issueDate);
	this->dateTo.SetTime(expiryDate);


	// Time
	int year = COleDateTime::GetCurrentTime().GetYear();
	int month = COleDateTime::GetCurrentTime().GetMonth();
	int day = COleDateTime::GetCurrentTime().GetDay();


	COleDateTime marketOpenTime(year, month, day, 9, 0, 0);
	COleDateTime marketCloseTime(year, month, day, 15, 5, 0);
	COleDateTime marketCloseTimeOnExpiry(year, month, day, 14, 50, 0);

	this->timeTo.SetTime(marketCloseTimeOnExpiry);
	this->marketCloseTime.SetTime(marketCloseTime);
	this->marketOpenTime.SetTime(marketOpenTime);

	/////////

	this->timeTo.SetFormat(_T("HH:mm:ss"));
	this->marketOpenTime.SetFormat(_T("HH:mm:ss"));
	this->marketCloseTime.SetFormat(_T("HH:mm:ss"));

	this->timeNow.SetFormat(_T("HH:mm:ss"));


	this->timeTo.EnableWindow(FALSE);
	this->marketOpenTime.EnableWindow(FALSE);
	this->marketCloseTime.EnableWindow(FALSE);
}


void CDlgOptionStrategy::OnButtonClickedAutoCalculate(){
	int status = this->buttonAutoPremiumCalculate.GetCheck();
	if(status == BST_CHECKED){
		this->editAutoSeconds.EnableWindow(TRUE);
	}
	else if(status == BST_UNCHECKED) {
		this->editAutoSeconds.SetWindowText(_T(""));
		this->editAutoSeconds.EnableWindow(FALSE);
	}
}


void CDlgOptionStrategy::OnButtonClickedRequestData(){
	int status = this->buttonAutoPremiumCalculate.GetCheck();
	if(status == BST_CHECKED){
		CString cstrStatus;
		tstring status;
		this->buttonSelectOption.GetWindowText(cstrStatus);
		status = cstrStatus;

		
		if(status.compare(_T("Request Data"))==0){
			CString csAutoSeconds;
			double autoSeconds;
			this->editAutoSeconds.GetWindowText(csAutoSeconds);
			tstring temp = csAutoSeconds;
			if( DataConverter::CheckIfNumber(temp) ){
				autoSeconds = DataConverter::ConvertStringToDouble(temp)*1000;
				int iAutoSeconds = DataConverter::ConvertDoubleToInt(autoSeconds);
				this->KillTimer(this->statusAutoCalTimer);
				this->SetTimer(this->statusAutoCalTimer, iAutoSeconds, NULL);
				this->EnableParameterCtrls(FALSE);
				this->buttonSelectOption.SetWindowText(_T("Stop Request"));
			}
			else{
				MessageBox(_T("숫자를 입력하세요."));
			}
		}
		else if(status.compare(_T("Stop Request"))==0){
			this->KillTimer(this->statusAutoCalTimer);
			this->EnableParameterCtrls(TRUE);
			this->buttonSelectOption.SetWindowText(_T("Request Data"));
		}
	}
	else if(status == BST_UNCHECKED) {
		this->RequestData();
	}
}





LRESULT CDlgOptionStrategy::OnXMReceiveData( WPARAM wParam, LPARAM lParam ){
	//-------------------------------------------------------------------------------------
	// Data를 받음
	if( wParam == REQUEST_DATA ){
		LPRECV_PACKET pRpData = (LPRECV_PACKET)lParam;

		tstring trCode(pRpData->szTrCode);
		tstring outBlock(pRpData->szBlockName);
		
		if(outBlock.compare(NAME_t2101OutBlock)==0){
			//기초자산 지수 등등
			this->ProcessXRReceiveData_t2101OutBlock(pRpData);
			this->t2101Received = TRUE;
		}
		else if(outBlock.compare(NAME_t2301OutBlock1)==0){
			// 콜옵션 행사가들
			this->ProcessXRReceiveData_t2301OutBlock1(pRpData);
			this->t2301_1Received = TRUE;
		}
		else if(outBlock.compare(NAME_t2301OutBlock2)==0){
			// 풋옵션 행사가들
			this->ProcessXRReceiveData_t2301OutBlock2(pRpData);
			this->t2301_2Received = TRUE;
		}
		else if(outBlock.compare(NAME_t3521OutBlock)==0){
			// CD 91일 금리
			this->ProcessXRReceiveData_t3521OutBlock(pRpData);
			this->t3521Received = TRUE;
		}

		// 이론가 계산시 필요한 데이터가 다 채워졌으면 여기서 이론가 계산
		// underlyingAssetPrice(t2101), timeLeft(자체), rate(t3521), vol(t2101)
		if( this->t2301_1Received == TRUE &&
			this->t2301_2Received == TRUE &&
			this->t3521Received == TRUE){

			if(this->t2101Received==TRUE){
				this->optionPriceBoard.Valuate(this->undelyingAssetPrice, this->expiryRatio, this->riskFreeRate, this->historicalVol);
				this->gridCtrlOptionList.ResetOptionPriceBoardGridCtrl(this->optionPriceBoard);

				// 그리드모양 정리
				this->gridCtrlOptionList.AutoSize();
				this->gridCtrlOptionList.ExpandColumnsToFit();

				// 전에 선택되어진 옵션이 있으면 다시 선택 상태로 만듬
				this->gridCtrlOptionList.SetSelectedOptionRange(this->gridCtrlOptionList.GetPreSelectedRow(), this->gridCtrlOptionList.GetPreSelectedCol());


				if(this->pDlgOptionManager!=0){
					this->pDlgOptionManager->Simulate();
				}


				// 데이터 입수 상태 초기화
				this->t2101Received = FALSE;
				this->t2301_1Received = FALSE;
				this->t2301_2Received = FALSE;
				this->t3521Received = FALSE;
			}
			else {
				this->Request_t2101();
			}
		}

	}

	//-------------------------------------------------------------------------------------
	// 메시지를 받음
	else if( wParam == MESSAGE_DATA ){
		LPMSG_PACKET pMsg = (LPMSG_PACKET)lParam;
		CString strMsg( (tchar*)pMsg->lpszMessageData, pMsg->nMsgLength );
		GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)pMsg->szMsgCode, (LPARAM)(LPCTSTR)strMsg );		
		xingAPI->ReleaseMessageData( lParam );
	}

	//-------------------------------------------------------------------------------------
	// System Error를 받음
	else if( wParam == SYSTEM_ERROR_DATA ){
		LPMSG_PACKET pMsg = (LPMSG_PACKET)lParam;
		CString strMsg( (tchar*)pMsg->lpszMessageData, pMsg->nMsgLength );
		GetParent()->SendMessage( WMU_SET_MESSAGE, (WPARAM)pMsg->szMsgCode, (LPARAM)(LPCTSTR)strMsg );		
		this->xingAPI->ReleaseMessageData( lParam );
	}

	//-------------------------------------------------------------------------------------
	// Release Data를 받음
	else if( wParam == RELEASE_DATA ){
		this->xingAPI->ReleaseRequestData( (int)lParam );
	}

	return 0L;
}

//--------------------------------------------------------------------------------------
// Timeout 발생
//--------------------------------------------------------------------------------------
LRESULT CDlgOptionStrategy::OnXMTimeoutData( WPARAM wParam, LPARAM lParam )
{
	this->xingAPI->ReleaseRequestData( (int)lParam );

	return 0L;
}




double CDlgOptionStrategy::CalExpiryRatio(){
	CTime cissueDate;
	CTime cexpiryDate;
	CTime cexpiryTime;
	CTime cmarketOpenTime;
	CTime cmarketCloseTime;
	CTime cnowDate;
	CTime cnowTime;


	DWORD dwNowTime;
	DWORD dwNowDate;
	dwNowTime = this->timeNow.GetTime(cnowTime);
	dwNowDate = this->dateNow.GetTime(cnowDate);


	DWORD dwissueDate = this->dateFrom.GetTime(cissueDate);
	DWORD dwexpiryDate = this->dateTo.GetTime(cexpiryDate);
	DWORD dwexpiryTime = this->timeTo.GetTime(cexpiryTime);
	DWORD dwmarketOpenTime = this->marketOpenTime.GetTime(cmarketOpenTime);
	DWORD dwmarketCloseTime = this->marketCloseTime.GetTime(cmarketCloseTime);

	CString csissueDate = cissueDate.Format(_T("%Y%m%d"));
	CString csexpiryDate = cexpiryDate.Format(_T("%Y%m%d"));
	CString csexpiryTime = cexpiryTime.Format(_T("%H%M%S"));
	CString csmarketOpenTime = cmarketOpenTime.Format(_T("%H%M%S"));
	CString csmarketCloseTime = cmarketCloseTime.Format(_T("%H%M%S"));
	CString csnowDate = cnowDate.Format(_T("%Y%m%d"));
	CString csnowTime = cnowTime.Format(_T("%H%M%S"));

	tstring issueDate(csissueDate);
	tstring expiryDate(csexpiryDate);
	tstring expiryTime(csexpiryTime);
	tstring marketOpenTime(csmarketOpenTime);
	tstring marketCloseTime(csmarketCloseTime);
	tstring nowDate(csnowDate);
	tstring nowTime(csnowTime);

	this->expiryCalculator.SetIssueDate(issueDate);
	this->expiryCalculator.SetExpiryDate(expiryDate);
	this->expiryCalculator.SetMarketOpenTime(marketOpenTime);
	this->expiryCalculator.SetMarketCloseTime(marketCloseTime);
	this->expiryCalculator.SetMarketCloseTimeOnExpiry(expiryTime);

	tstring dateTime = nowDate.append(nowTime);
	double expiry = expiryCalculator.GetExpirationRatio(dateTime);
	expiry = MathCalculator::Round(expiry, 5);

	return expiry;
}


void CDlgOptionStrategy::SetWindowTextExpiryRatio(double expiryRatio){
	this->editTimeLeft.SetWindowText(DataConverter::ConvertDoubleToString(expiryRatio).c_str());
}


void CDlgOptionStrategy::Request_t3521(){
	t3521InBlock pckInBlock;

	TCHAR			szTrNo[]	= _T("t3521");
	tchar			szNextKey[]	= _T("");


	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), _T(' ') );

	//-----------------------------------------------------------
	// 데이터 입력
	SetXingPacketData( pckInBlock.kind, sizeof( pckInBlock.kind ), _T("S"), DATA_TYPE_STRING );	
	SetXingPacketData( pckInBlock.symbol, sizeof( pckInBlock.symbol ), _T("KIR@CD91"), DATA_TYPE_STRING );	

	//-----------------------------------------------------------
	// 데이터 전송
	int nRqID = xingAPI->Request( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_DATA 으로 온다.
		szTrNo,						// TR 번호
		&pckInBlock,				// InBlock 데이터
		sizeof( pckInBlock ),		// InBlock 데이터 크기
		FALSE,						// 다음조회 여부 : 다음조회일 경우에 세팅한다.
		szNextKey,					// 다음조회 Key : Header Type이 B 일 경우엔 이전 조회때 받은 Next Key를 넣어준다.
		10							// Timeout(초) : 해당 시간(초)동안 데이터가 오지 않으면 Timeout에 발생한다. XM_TIMEOUT_DATA 메시지가 발생한다.
		);

	//-----------------------------------------------------------
	// Request ID가 0보다 작을 경우에는 에러이다.
	if( nRqID < 0 )
	{
		//MessageBox( "조회실패", "에러", MB_ICONSTOP );
	}
}

void CDlgOptionStrategy::Request_t2101(){

	tstring strOptionCode;

	if(optionPriceBoard.GetCallOptions().GetLength()>0){
		strOptionCode = optionPriceBoard.GetCallOptions().GetAt(0).GetOption().GetOptionCode();
	}

	//-----------------------------------------------------------
	// 주식현재가호가조회(t1101) ( attr,block,headtype=A )
	t2101InBlock	pckInBlock;

	TCHAR			szTrNo[]	= _T("t2101");
	tchar			szNextKey[]	= _T("");


	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), _T(' ') );

	//-----------------------------------------------------------
	// 데이터 입력
	SetXingPacketData( pckInBlock.focode, sizeof( pckInBlock.focode ), strOptionCode.c_str(), DATA_TYPE_STRING );				// 단축코드

	//-----------------------------------------------------------
	// 데이터 전송
	int nRqID = xingAPI->Request( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_DATA 으로 온다.
		szTrNo,						// TR 번호
		&pckInBlock,				// InBlock 데이터
		sizeof( pckInBlock ),		// InBlock 데이터 크기
		FALSE,						// 다음조회 여부 : 다음조회일 경우에 세팅한다.
		szNextKey,					// 다음조회 Key : Header Type이 B 일 경우엔 이전 조회때 받은 Next Key를 넣어준다.
		10							// Timeout(초) : 해당 시간(초)동안 데이터가 오지 않으면 Timeout에 발생한다. XM_TIMEOUT_DATA 메시지가 발생한다.
		);

	//-----------------------------------------------------------
	// Request ID가 0보다 작을 경우에는 에러이다.
	if( nRqID < 0 )
	{
		//MessageBox( "조회실패", "에러", MB_ICONSTOP );
	}
}


void CDlgOptionStrategy::Request_t2301(tstring yyyymm){
	//-----------------------------------------------------------
	// 주식현재가호가조회(t1101) ( attr,block,headtype=A )
	t2301InBlock	pckInBlock;

	TCHAR			szTrNo[]	= _T("t2301");
	tchar			szNextKey[]	= _T("");


	//-----------------------------------------------------------
	// 데이터 초기화
	FillMemory( &pckInBlock, sizeof( pckInBlock ), _T(' ') );

	//-----------------------------------------------------------
	// 데이터 입력
	SetXingPacketData( pckInBlock.yyyymm, sizeof( pckInBlock.yyyymm ), yyyymm.c_str(), DATA_TYPE_STRING );				// 단축코드

	//-----------------------------------------------------------
	// 데이터 전송
	int nRqID = xingAPI->Request( 
		GetSafeHwnd(),				// 데이터를 받을 윈도우, XM_RECEIVE_DATA 으로 온다.
		szTrNo,						// TR 번호
		&pckInBlock,				// InBlock 데이터
		sizeof( pckInBlock ),		// InBlock 데이터 크기
		FALSE,						// 다음조회 여부 : 다음조회일 경우에 세팅한다.
		szNextKey,					// 다음조회 Key : Header Type이 B 일 경우엔 이전 조회때 받은 Next Key를 넣어준다.
		10							// Timeout(초) : 해당 시간(초)동안 데이터가 오지 않으면 Timeout에 발생한다. XM_TIMEOUT_DATA 메시지가 발생한다.
		);

	//-----------------------------------------------------------
	// Request ID가 0보다 작을 경우에는 에러이다.
	if( nRqID < 0 ){
		//MessageBox( "조회실패", "에러", MB_ICONSTOP );
	}
}

void CDlgOptionStrategy::InitComboboxOptionMonth(){
	/*
	int year = COleDateTime::GetCurrentTime().GetYear();
	int month = COleDateTime::GetCurrentTime().GetMonth();
	int day = COleDateTime::GetCurrentTime().GetDay();

	tstring tstrYear = DataConverter::ConvertIntToString(year);
	tstring tstrMonth = DataConverter::ConvertIntToString(month);

	tstring tstrDate = tstrYear + _T("-") + tstrMonth;
	
	int index = 0;
	this->comboboxOptionMonth.ResetContent();
	index = this->comboboxOptionMonth.AddString(_T("- select -"));
	index = this->comboboxOptionMonth.AddString(tstrDate.c_str());
	index = this->comboboxOptionMonth.SetCurSel(0);
	*/
	//////////////////////////////////////////////////////////////////////////

	CTime cnowTime;
	cnowTime = CTime::GetCurrentTime();
	CString csnowTime = cnowTime.Format(_T("%Y%m%d%H%M%S"));
	tstring nowTime(csnowTime);

	ExpiryCalculator expiryCalculator;
	expiryCalculator.ResetOptionLifePeriod(nowTime);

	tstring issueYYYYMM = expiryCalculator.GetExpiryDate().substr(0,6);

	tstring tstrYear = issueYYYYMM.substr(0,4);
	tstring tstrMonth = issueYYYYMM.substr(4,2);

	tstring tstrDate = tstrYear + _T("-") + tstrMonth;

	int index = 0;
	this->comboboxOptionMonth.ResetContent();
	index = this->comboboxOptionMonth.AddString(_T("- select -"));
	index = this->comboboxOptionMonth.AddString(tstrDate.c_str());
	index = this->comboboxOptionMonth.SetCurSel(0);
}


void CDlgOptionStrategy::SelectComboboxOptionMonth(){

	int index = this->comboboxOptionMonth.GetCurSel();

	if(index>0){
		
		CString cstrMonth;
		this->comboboxOptionMonth.GetLBText(index, cstrMonth);
		tstring date = cstrMonth;

		tstring year = date.substr(0,4);
		tstring month = date.substr(5,2);

		date = year+month;
		
		ExpiryCalculator expiryCalculator(date);

		this->expiryCalculator = expiryCalculator;

		this->InitOptionLifePeriodCtrls();

		this->SetTimer(this->statusTimeNowTimer, 1000, NULL);
		
		this->editUnderlyingPrice.EnableWindow(FALSE);
		this->editRate.EnableWindow(FALSE);
		this->editVol.EnableWindow(FALSE);
		this->dateFrom.EnableWindow(FALSE);
		this->dateTo.EnableWindow(FALSE);
		this->marketOpenTime.EnableWindow(FALSE);
		this->marketCloseTime.EnableWindow(FALSE);
		this->timeTo.EnableWindow(FALSE);
		this->dateNow.EnableWindow(FALSE);
		this->timeNow.EnableWindow(FALSE);
	}
	else{
		this->KillTimer(this->statusTimeNowTimer);
		this->EnableParameterCtrls(TRUE);

		this->editUnderlyingPrice.SetWindowText(NULL);
		this->editRate.SetWindowText(NULL);
		this->editVol.SetWindowText(NULL);
		this->editTimeLeft.SetWindowText(NULL);

	}

}




// 옵션코드, 기초자산 가격, 변동성
void CDlgOptionStrategy::ProcessXRReceiveData_t2101OutBlock(LPRECV_PACKET pRpData){
	LPt2101OutBlock pOutBlock = (LPt2101OutBlock)pRpData->lpData;
	// 옵션 코드
	//this->editCode.SetWindowText( GetDispData( pOutBlock->focode, sizeof( pOutBlock->focode), DATA_TYPE_STRING ) );
	
	// KOSPI200 지수
	CString cstrKOSPI200 = GetDispData( pOutBlock->kospijisu, sizeof( pOutBlock->kospijisu), DATA_TYPE_FLOAT,2 );
	this->editUnderlyingPrice.SetWindowText(cstrKOSPI200);
	this->undelyingAssetPrice = _ttof(cstrKOSPI200);
	
	// 연사적 변동성
	CString cstrHistVol = GetDispData( pOutBlock->histimpv, sizeof( pOutBlock->histimpv), DATA_TYPE_FLOAT,2 );
	this->editVol.SetWindowText(cstrHistVol);
	this->historicalVol = _ttof(cstrHistVol)/100.0;

	// 잔존일
	CString cstrDaysLeft = GetDispData( pOutBlock->jandatecnt, sizeof( pOutBlock->jandatecnt), DATA_TYPE_LONG );
	this->editDaysLeft.SetWindowText(cstrDaysLeft);
	
	CString cstrExpiryRatio2;
	double dblLeftDays = _ttof(cstrDaysLeft);
	this->expiryRatioByDayCount = dblLeftDays/365.0;
	cstrExpiryRatio2.Format(_T("%.5f"), this->expiryRatioByDayCount);
	this->editExpiryRatio2.SetWindowText(cstrExpiryRatio2);
}

// 콜옵션 : 행사가, 브로커 이론가, 브로커 민감도
void CDlgOptionStrategy::ProcessXRReceiveData_t2301OutBlock1(LPRECV_PACKET pRpData){
	int dataLength = pRpData->nDataLength;
	LPt2301OutBlock1 pOutBlock = (LPt2301OutBlock1)pRpData->lpData;
	int count = dataLength/sizeof(t2301OutBlock1);

	this->optionPriceBoard.SetNumStrikePrices(count);


	for(int i=0; i<count; i++){
		t2301OutBlock1 block = pOutBlock[i];
		OptionInfo item;

		// 옵션 행사가
		CString temp = GetDispData( block.actprice, sizeof( block.actprice), DATA_TYPE_FLOAT,2 );
		double strikePrice = _ttof(temp);

		// 옵션 시장가
		temp = GetDispData( block.price, sizeof( block.price), DATA_TYPE_FLOAT,2 );
		double marketPrice = _ttof(temp);

		// 옵션 코드
		tstring optionCode = GetDispData( block.optcode, sizeof( block.optcode), DATA_TYPE_STRING );

		// 브로커 민감도
		temp = GetDispData( block.delt, sizeof( block.delt), DATA_TYPE_FLOAT, 4 );
		double delta = _ttof(temp);

		temp = GetDispData( block.gama, sizeof( block.gama), DATA_TYPE_FLOAT, 4 );
		double gamma = _ttof(temp);

		temp = GetDispData( block.vega, sizeof( block.vega), DATA_TYPE_FLOAT, 4 );
		double vega = _ttof(temp);

		temp = GetDispData( block.ceta, sizeof( block.ceta), DATA_TYPE_FLOAT, 4 );
		double theta = _ttof(temp);

		temp = GetDispData( block.rhox, sizeof( block.rhox), DATA_TYPE_FLOAT, 4 );
		double rho = _ttof(temp);


		

		// 브로커 이론가
		temp = GetDispData( block.theoryprice, sizeof( block.theoryprice), DATA_TYPE_FLOAT,2 );
		double optionValue = _ttof(temp);

		temp = GetDispData( block.impv, sizeof( block.impv), DATA_TYPE_FLOAT,2 );
		double intrinsicValue = _ttof(temp);

		temp = GetDispData( block.timevl, sizeof( block.timevl), DATA_TYPE_FLOAT,2 );
		double timeValue = _ttof(temp);


		EuropeanOption option(optionCode, _T("KOSPI200"), CALL_OPTION, strikePrice);
		OptionValue brokerOptionValue(optionValue, intrinsicValue, timeValue);
		Sensitivity brokerSensitivity(delta, gamma, vega, theta, rho);

		OptionInfo optionInfo(CALL_OPTION, marketPrice, strikePrice, option, brokerOptionValue, brokerSensitivity);

		this->optionPriceBoard.GetCallOptions().AddOptionInfo(optionInfo);
	}
}


// 풋옵션 : 행사가, 브로커 이론가, 브로커 민감도
void CDlgOptionStrategy::ProcessXRReceiveData_t2301OutBlock2(LPRECV_PACKET pRpData){
	int dataLength = pRpData->nDataLength;
	LPt2301OutBlock2 pOutBlock = (LPt2301OutBlock2)pRpData->lpData;
	int count = dataLength/sizeof(t2301OutBlock2);

	this->optionPriceBoard.SetNumStrikePrices(count);
	for(int i=0; i<count; i++){
		t2301OutBlock2 block = pOutBlock[i];
		OptionInfo item;

		// 옵션 행사가
		CString temp = GetDispData( block.actprice, sizeof( block.actprice), DATA_TYPE_FLOAT,2 );
		double strikePrice = _ttof(temp);

		// 옵션 시장가
		temp = GetDispData( block.price, sizeof( block.price), DATA_TYPE_FLOAT,2 );
		double marketPrice = _ttof(temp);

		// 옵션 코드
		tstring optionCode = GetDispData( block.optcode, sizeof( block.optcode), DATA_TYPE_STRING );

		// 브로커 민감도
		temp = GetDispData( block.delt, sizeof( block.delt), DATA_TYPE_FLOAT, 4 );
		double delta = _ttof(temp);

		temp = GetDispData( block.gama, sizeof( block.gama), DATA_TYPE_FLOAT, 4 );
		double gamma = _ttof(temp);

		temp = GetDispData( block.vega, sizeof( block.vega), DATA_TYPE_FLOAT, 4 );
		double vega = _ttof(temp);

		temp = GetDispData( block.ceta, sizeof( block.ceta), DATA_TYPE_FLOAT, 4 );
		double theta = _ttof(temp);

		temp = GetDispData( block.rhox, sizeof( block.rhox), DATA_TYPE_FLOAT, 4 );
		double rho = _ttof(temp);




		// 브로커 이론가
		temp = GetDispData( block.theoryprice, sizeof( block.theoryprice), DATA_TYPE_FLOAT,2 );
		double optionValue = _ttof(temp);

		temp = GetDispData( block.impv, sizeof( block.impv), DATA_TYPE_FLOAT,2 );
		double intrinsicValue = _ttof(temp);

		temp = GetDispData( block.timevl, sizeof( block.timevl), DATA_TYPE_FLOAT,2 );
		double timeValue = _ttof(temp);


		EuropeanOption option(optionCode, _T("KOSPI200"), PUT_OPTION, strikePrice);
		OptionValue brokerOptionValue(optionValue, intrinsicValue, timeValue);
		Sensitivity brokerSensitivity(delta, gamma, vega, theta, rho);

		OptionInfo optionInfo(PUT_OPTION, marketPrice, strikePrice, option, brokerOptionValue, brokerSensitivity);

		this->optionPriceBoard.GetPutOptions().AddOptionInfo(optionInfo);
	}
}


// CD 91일 금리
void CDlgOptionStrategy::ProcessXRReceiveData_t3521OutBlock(LPRECV_PACKET pRpData){
	LPt3521OutBlock pOutBlock = (LPt3521OutBlock)pRpData->lpData;

	CString cstrCD91 = GetDispData( pOutBlock->close, sizeof( pOutBlock->close), DATA_TYPE_FLOAT,2 ) ;
	this->editRate.SetWindowText(cstrCD91);
	this->riskFreeRate =_ttof(cstrCD91)/100.0;
}



void CDlgOptionStrategy::InitExpiryCalculator(){
	CTime cnowDate;
	CTime cnowTime;
	cnowDate = CTime::GetCurrentTime();
	cnowTime = CTime::GetCurrentTime();
	CString csnowDate = cnowDate.Format(_T("%Y%m%d"));
	CString csnowTime = cnowTime.Format(_T("%H%M%S"));
	tstring nowDate(csnowDate);
	tstring nowTime(csnowTime);

	tstring currentDateTime(nowDate.append(nowTime));

	ExpiryCalculator expiryCalculator(currentDateTime);
	this->expiryCalculator = expiryCalculator;
}


void CDlgOptionStrategy::RequestData(){
	// 데이터 입수 상태 초기화
	this->t2101Received = FALSE;
	this->t2301_1Received = FALSE;
	this->t2301_2Received = FALSE;
	this->t3521Received = FALSE;

	// 옵션 이론가 전광판 업데이트하기전에 초기화
	this->optionPriceBoard.Clear();

	// 옵션월 가져오기
	CString cstrMonth;
	int index = this->comboboxOptionMonth.GetCurSel();
	this->comboboxOptionMonth.GetLBText(index, cstrMonth);
	tstring date = cstrMonth;
	tstring year = date.substr(0,4);
	tstring month = date.substr(5,2);
	date = year+month;

	// 데이터 Request
	this->Request_t3521();
	this->Request_t2301(date);
}


void CDlgOptionStrategy::EnableParameterCtrls(BOOL enable){
	this->comboboxOptionMonth.EnableWindow(enable);

	this->editUnderlyingPrice.EnableWindow(enable);
	this->editRate.EnableWindow(enable);
	this->editVol.EnableWindow(enable);

	this->dateFrom.EnableWindow(enable);
	this->dateTo.EnableWindow(enable);
	this->marketOpenTime.EnableWindow(enable);
	this->marketCloseTime.EnableWindow(enable);
	this->timeTo.EnableWindow(enable);
	
	this->dateNow.EnableWindow(enable);
	this->timeNow.EnableWindow(enable);

	this->editAutoSeconds.EnableWindow(enable);
	this->buttonAutoPremiumCalculate.EnableWindow(enable);
}

void CDlgOptionStrategy::ResetCurrentDateTime(){
	CTime tm = CTime::GetCurrentTime();
	this->timeNow.SetTime(&tm);
	this->dateNow.SetTime(&tm);
	this->expiryRatio = this->CalExpiryRatio();
	this->SetWindowTextExpiryRatio(this->expiryRatio);
}



void CDlgOptionStrategy::OnGridOptionListEndSelChange(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
	*pResult = 0;

	int nRow = pItem->iRow;  
	int nCol = pItem->iColumn;

	this->gridCtrlOptionList.SetSelectedOptionRange(nRow, nCol);

	CString cstrOptionCode = this->gridCtrlOptionList.GetOptionCode(nRow, nCol);

	this->editCode.SetWindowText(cstrOptionCode);
}


void CDlgOptionStrategy::OnGridOptionListStartSelChange(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
	*pResult = 0;

	int nRow = pItem->iRow;  
	int nCol = pItem->iColumn;
	
}


void CDlgOptionStrategy::OnButtonClickedDrawValueCurve(){
	int selectedStrategyIndex = this->GetSelectedStrategyIndex();
	if(selectedStrategyIndex>=0){
		if(this->pDlgOptionManager==0){
			this->pDlgOptionManager = (CDlgOptionManager*)this->CreateOptionValueCurveDialog(RUNTIME_CLASS(CDlgOptionManager), IDD_DIALOG_OPTION_MANAGER);
			this->pDlgOptionManager->pParentDlgOptionStrategy = this;
			this->pDlgOptionManager->Simulate();
		}
		else{
			//AfxMessageBox(_T("Option Value Curve already exists."));
			this->pDlgOptionManager->ShowWindow(SW_SHOW);
		}
	}
	else{
		MessageBox(_T("전략을 선택해주세요."));
	}
}


CDlgOptionManager* CDlgOptionStrategy::CreateOptionValueCurveDialog(CRuntimeClass* pClass, UINT uID){
	CDlgOptionManager* pDlg = (CDlgOptionManager*)pClass->CreateObject();
	BOOL created = pDlg->Create(uID, this);
	if (created == TRUE){
		pDlg->ShowWindow(SW_SHOW);
	}
	else{
		AfxMessageBox(_T("Could Not Create GUI"));
	}
	return pDlg;
}


void CDlgOptionStrategy::OnButtonClickedDeletePosition(){
	int selectedStrategyGridIndex = this->gridCtrlOptionStrategyList.GetSelectedCellRange().GetMinRow();
	CString cstrSelectedStrategy = this->gridCtrlOptionStrategyList.GetStrategyName(selectedStrategyGridIndex);
	tstring tstrSelectedStrategy = cstrSelectedStrategy;

	int selectesStrategyIndex = this->optionManager->GetOptionStrategyList().FindOptionStrategy(tstrSelectedStrategy);
	if(selectedStrategyIndex>=0){
		PositionList* p_PositionList = &(this->optionManager->GetOptionStrategyList().GetAt(selectesStrategyIndex));

		int selectedPositionGridIndex = this->gridCtrl.GetSelectedCellRange().GetMinRow();
		int selectedPositionNumber = this->gridCtrl.GetPositionNumber(selectedPositionGridIndex);

		int index = p_PositionList->FindPositionByPositionNumber(selectedPositionNumber);
		if(index>=0){
			p_PositionList->DeletePosition(index);
			this->gridCtrl.RefreshOptionPositions(*p_PositionList);
		}
		else{
			MessageBox(_T("선택된 포지션이 존재 하지 않습니다."));
		}
	}
}



void CDlgOptionStrategy::OnButtonClickedDeleteStrategy(){
	int selectedStrategyGridIndex = this->gridCtrlOptionStrategyList.GetSelectedCellRange().GetMinRow();
	CString cstrSelectedStrategy = this->gridCtrlOptionStrategyList.GetStrategyName(selectedStrategyGridIndex);
	tstring tstrSelectedStrategy = cstrSelectedStrategy;

	if(cstrSelectedStrategy.IsEmpty()==FALSE){

		int selectesStrategyIndex = this->optionManager->GetOptionStrategyList().FindOptionStrategy(tstrSelectedStrategy);

		if(selectesStrategyIndex>=0){
			this->optionManager->DeleteOptionStrategy(selectesStrategyIndex);

			this->gridCtrlOptionStrategyList.RefreshOptionStrategy(this->optionManager->GetOptionStrategyList());
			this->gridCtrl.RefreshOptionPositions(this->optionManager->GetOptionStrategyList().GetAt(selectedStrategyIndex));
		}
		else{
			MessageBox(_T("선택된 전략이 존재 하지 않습니다."));
		}
	}
	else{
		MessageBox(_T("삭제할 옵션 전략을 선택하세요."));
	}
}


void CDlgOptionStrategy::OnGridOptionStrategyStartSelChange(NMHDR *pNotifyStruct, LRESULT* pResult){

}


void CDlgOptionStrategy::OnGridOptionStrategyEndSelChange(NMHDR *pNotifyStruct, LRESULT* pResult){
	NM_GRIDVIEW* pItem = (NM_GRIDVIEW*) pNotifyStruct;
	*pResult = 0;

	int nRow = pItem->iRow;  
	int nCol = pItem->iColumn;

	CString cstrSelectedStrategy = this->gridCtrlOptionStrategyList.GetStrategyName(nRow);
	this->selectedStrategyName  = cstrSelectedStrategy;

	if(this->selectedStrategyName.empty()==false){
		this->selectedStrategyIndex = this->optionManager->GetOptionStrategyList().FindOptionStrategy(this->selectedStrategyName);
		if(this->selectedStrategyIndex>=0){
			this->gridCtrl.RefreshOptionPositions(this->optionManager->GetOptionStrategyList().GetAt(this->selectedStrategyIndex));
		}
		else{
			MessageBox(_T("선택된 전략이 존재 하지 않습니다."));
		}
	}
}