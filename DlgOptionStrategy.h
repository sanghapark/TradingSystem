// DlgOptionStrategy.h

#pragma once


#include <afxcmn.h>
#include <afxdtctl.h>
#include "resource.h"
#include "OptionPositionGridGtrl.h"
#include "PositionList.h"
#include "ExpiryCalculator.h"
#include "OptionListGridCtrl.h"
#include "IXingAPI.h"
#include "OptionPriceBoard.h"
#include "OptionStrategyGridCtrl.h"
#include "OptionManager.h"

class CDlgOptionManager;
class CModuleRelationView;
class OptionManager;

class CDlgOptionStrategy : public CDialog{
	DECLARE_DYNCREATE(CDlgOptionStrategy)

	public:
		enum {IDD=IDD_DIALOG_OPTION_STRATEGY};
		CDlgOptionStrategy(CWnd* pParent = NULL);
		virtual ~CDlgOptionStrategy();
		virtual BOOL OnInitDialog();

		

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);

		DECLARE_MESSAGE_MAP()
		afx_msg void OnButtonClickedRequestData();
		afx_msg void OnButtonClickedCalExpiry();
		afx_msg void OnButtonClickedCalTheoPrice();

		afx_msg void OnButtonClickedAdd();
		
		afx_msg void OnButtonClickedCreateStrategy();

		afx_msg void OnButtonClickedAutoCalculate();

		afx_msg void OnTimer(UINT_PTR nIDEvent); // 현재시간 사용 체크시 일초마다 호출되서 현재시간 업데이트 함
		afx_msg	LRESULT		OnXMReceiveData		( WPARAM wParam, LPARAM lParam );
		afx_msg	LRESULT		OnXMTimeoutData		( WPARAM wParam, LPARAM lParam );

		afx_msg void OnGridOptionListStartSelChange(NMHDR *pNotifyStruct, LRESULT* pResult);
		afx_msg void OnGridOptionListEndSelChange(NMHDR *pNotifyStruct, LRESULT* pResult);
		afx_msg void OnGridOptionStrategyStartSelChange(NMHDR *pNotifyStruct, LRESULT* pResult);
		afx_msg void OnGridOptionStrategyEndSelChange(NMHDR *pNotifyStruct, LRESULT* pResult);
		afx_msg void OnButtonClickedDrawValueCurve();
		afx_msg void OnButtonClickedDeletePosition();
		afx_msg void OnButtonClickedDeleteStrategy();

	private:
		double CalExpiryRatio();
		CString GetCheckedRadioButtonType();
		CString GetCheckedRadioButtonPosition();
		CString GetCheckedRadioButtonPremium();
		BOOL TakeAPosition(const OptionParameter& optionParameter, int positionNumber, CString strategyName);
		void InitExpiryCalculator();
		void InitOptionLifePeriodCtrls();
		void SetWindowTextExpiryRatio(double expiryRatio);
		void ResetCurrentDateTime();
		
		void InitComboboxOptionMonth();
		void SelectComboboxOptionMonth();

		void RequestData();
		void Request_t3521(); // CD 91일 무위험 이자율 가져옴
		void Request_t2101(); // KOSPI200 기초자산 지수 등등
		void Request_t2301(tstring yyyymm); // 행사가 가져옴

		void ProcessXRReceiveData_t2101OutBlock(LPRECV_PACKET pRpData);
		void ProcessXRReceiveData_t2301OutBlock1(LPRECV_PACKET pRpData);
		void ProcessXRReceiveData_t2301OutBlock2(LPRECV_PACKET pRpData);
		void ProcessXRReceiveData_t3521OutBlock(LPRECV_PACKET pRpData);

		void EnableParameterCtrls(BOOL enable);

		CDlgOptionManager* CreateOptionValueCurveDialog(CRuntimeClass* pClass, UINT uID);

	public:
		IXingAPI* xingAPI;
		CDlgOptionManager* pDlgOptionManager;
		CModuleRelationView* pParentView;
		OptionManager* optionManager;

	private:
		
		CEdit editPointInWON; //IDC_EDIT_POINT_IN_WON
		CEdit editName; // StrategyName, IDC_EDIT_NAME
		CEdit editCode; // Option Code, IDC_EDIT_OPTION_CODE
		CEdit editRate; // 무위험 이자율, IDC_EDIT_RISK_FREE_RATE
		
		CEdit editVol;  // 변동성, IDC_EDIT_VOL
		CEdit editUnderlyingPrice;  //기초자산 가격, IDC_EDIT_UNDERLYING_ASSET_PRICE
		CEdit editContractCount; // # of Contract, IDC_EDIT_NUMBER_CONTRACT

		CButton radioLong; // 포지션: Long, IDC_RADIO_LONG
		CButton radioShort;// 포지션: Short, IDC_RADIO_SHORT

		CButton radioPremiumMarket; // IDC_RADIO_PREMIUM_MARKET
		CButton radioPremiumTheo; // IDC_RADIO_PREMIUM_THEO

		CButton buttonSelectOption; // Select Option, IDC_BUTTON_SELECT_OPTION
		CButton buttonAdd;  // Take a Position!, IDC_BUTTON_ADD
		CButton buttonDelete; // Delete, IDC_BUTTON_DELETE
		//CButton buttonEdit;  // Edit, IDC_BUTTON_EDIT
		CButton buttonSave; // Save Strategy, IDC_BUTTON_SAVE

		//자존기간
		CDateTimeCtrl dateFrom; // 발행일 날짜, IDC_DATETIMEPICKER_FROM_DATE
		CDateTimeCtrl dateTo; // 만기일 날짜, IDC_DATETIMEPICKER_TO_DATE
		CDateTimeCtrl timeTo; // 만기일 시간, IDC_DATETIMEPICKER_TO_TIME
		CDateTimeCtrl timeNow; // 현재시간, 
		CDateTimeCtrl dateNow; // 현재 날짜, IDC_DATETIMEPICKER_NOW_DATE
		CDateTimeCtrl marketOpenTime; // 장시간 오픈, IDC_DATETIMEPICKER_MARKET_OPEN_TIME
		CDateTimeCtrl marketCloseTime; // 장시간 클로즈, IDC_DATETIMEPICKER_MARKET_CLOSE_TIME
		CEdit editTimeLeft; // 잔존기간 [0~1], IDC_EDIT_EXP_TIME

		CEdit editDaysLeft; // 잔존일 IDC_EDIT_DAYS_LEFT
		CEdit editExpiryRatio2; // 잔존만기 IDC_EDIT_EXPIRY_RATIO2


		CEdit editAutoSeconds; // IDC_EDIT_SECONDS
		CButton buttonAutoPremiumCalculate; // 실시간 자동 이론가 계산


		CComboBox comboboxOptionMonth; //IDC_COMBO__OPTION_MONTH
		CButton buttonDrawValueCurve; // IDC_BUTTON_OPTION_VALUE_CHART


		COptionListGridCtrl gridCtrlOptionList; //IDC_CUSTOM_OPTION_LIST
		COptionPositionGridCtrl gridCtrl;
		COptionStrategyGridCtrl gridCtrlOptionStrategyList; //IDC_CUSTOM_OPTION_STRATEGY_LIST
		CButton buttonDeleteOptionStrategy; //IDC_BUTTON_DELETE_STRATEGY

		int statusTimeNowTimer;
		int statusAutoCalTimer;
		ExpiryCalculator expiryCalculator;

		BOOL t2101Received;
		BOOL t2301_1Received;
		BOOL t2301_2Received;
		BOOL t3521Received;

		//PositionList positionList;
		OptionPriceBoard optionPriceBoard;

		double undelyingAssetPrice;	// ProcessXRReceiveData_t2101OutBlock	이함수에서 값세팅
		double historicalVol;		// ProcessXRReceiveData_t2101OutBlock	이함수에서 값세팅
		double riskFreeRate;		// ProcessXRReceiveData_t3521OutBlock	이함수에서 값세팅
		double expiryRatio;			// ResetCurrentDateTime					이함수에서 값세팅
		double expiryRatioByDayCount; // 잔여일/365 식으로 잔존만기 계산 (브로커식)
		double pointInWON;

		tstring selectedStrategyName;
		int selectedStrategyIndex;
	public:
		tstring& GetSelectedStrategyName() const;
		int GetSelectedStrategyIndex() const;
		double GetUnderlyingAssetPrice() const;
		double GetHistoricalVol() const;
		double GetRiskFreeRate() const;
		double GetExpiryRatio() const;
		double GetExpiryRatioByDayCount() const;
};




inline tstring& CDlgOptionStrategy::GetSelectedStrategyName() const{
	return const_cast<tstring&>(this->selectedStrategyName);
}


inline int CDlgOptionStrategy::GetSelectedStrategyIndex() const{
	return this->selectedStrategyIndex;
}



inline double CDlgOptionStrategy::GetUnderlyingAssetPrice() const{
	return this->undelyingAssetPrice;
}


inline double CDlgOptionStrategy::GetHistoricalVol() const{
	return this->historicalVol;
}

inline double CDlgOptionStrategy::GetRiskFreeRate() const{
	return this->riskFreeRate;
}


inline double CDlgOptionStrategy::GetExpiryRatio() const{
	return this->expiryRatio;
}


inline double CDlgOptionStrategy::GetExpiryRatioByDayCount() const{
	return this->expiryRatioByDayCount;
}