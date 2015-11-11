// DlgOptionManager.h

#pragma once

#include <afxwin.h>
#include "resource.h"
#include "ChartViewer.h"
#include "PositionList.h"
#include "OptionPositionGridGtrl.h"


class CDlgOptionStrategy;


class CDlgOptionManager : public CDialog{
	DECLARE_DYNCREATE(CDlgOptionManager)	

	public:
		CDlgOptionManager(CWnd* pParent = NULL);

		enum {IDD = IDD_DIALOG_OPTION_MANAGER};

		void Simulate();

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);

	protected:
		HICON m_hIcon;

		virtual BOOL OnInitDialog();
		
		
		DECLARE_MESSAGE_MAP()
		afx_msg void OnPaint();
		afx_msg void OnButtonClickedSimulate();
		afx_msg void OnCheckButtonClickedAutoYAxis();
		afx_msg void OnSliderChanged();
		afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
		afx_msg void OnEditParameterValueChanged();

	public:
		CDlgOptionStrategy* pParentDlgOptionStrategy;

	private:
		CChartViewer m_ChartViewer;
		
		
		CButton buttonSimulate;
		

		CSliderCtrl sliderParameter;
		CEdit editParameter;
		CEdit editSliderMin;
		CEdit editSliderMax;
		//CSpinButtonCtrl spinParameter;
		CComboBox comboParameters;

		CEdit editOptionPriceMin;
		CEdit editOptionPriceMax;
		CEdit editUnderlyngAssetPriceMin;
		CEdit editUnderyingAssetPriceMax;
		CEdit editTimeLeft;
		CEdit editRiskFreeRate;
		CEdit editVolatility;
		CButton checkButtonYAxisAuto;

		int xMin;
		int xMax;
		int yMin;
		int yMax;
		double expiryRatio;
		double expiryRatioByDayCount;
		double riskFreeRate;
		double histVolatility;
		int parameterScale;

		double xScale;

	private:
		void InitComboBoxParameters();

		void InitSliderParameter();
		void InitSliderParameterForVolatility();
		void InitSliderParameterForTime();
		void InitSliderParameterForRiskFreeRate();
		void ResetSlider();

		CString GetSelectedComboboxParameter();
		double GetExpiryRatio();
		double GetRiskFreeRate();
		double GetHistoricalVolatility();

		BOOL ReadParameter(double* timeLeft, double* riskFreeRate, double* vol);

		void layoutCharts();
		BaseChart* GraphOptionPayoffCurve2(const char **imageMap, PositionList& positionList);
		BaseChart* InitXYChart(const char **imageMap);
};