// DlgOptionManager.cpp


#include "stdafx.h"
#include "DlgOptionManager.h"
#include "TradingSystem.h"
#include "DlgOptionStrategy.h"
#include "DataConverter.h"
#include "OptionManager.h"
#include "DataConverter.h"


IMPLEMENT_DYNCREATE(CDlgOptionManager, CDialog)


CDlgOptionManager::CDlgOptionManager(CWnd* pParent /* = NULL */)
	: CDialog(CDlgOptionManager::IDD, pParent){
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	this->pParentDlgOptionStrategy = 0;


	this->xMin = 0;
	this->xMax = 0;
	this->yMin = 0;
	this->yMax = 0;
	this->expiryRatio = 0.0;
	this->expiryRatioByDayCount = 0.0;
	this->riskFreeRate = 0.0;
	this->histVolatility = 0.0;
	this->parameterScale = 10000;

	this->xScale = .1;
}


void CDlgOptionManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHART, this->m_ChartViewer);

	
	DDX_Control(pDX, IDC_BUTTON_SIMULATE_OPTION_STRATEGY, this->buttonSimulate);

	DDX_Control(pDX, IDC_SLIDER_PARAMETER, this->sliderParameter);
	DDX_Control(pDX, IDC_EDIT_SLIDER_VALUE, this->editParameter);
	//DDX_Control(pDX, IDC_SPIN_PARAMETER, this->spinParameter);
	DDX_Control(pDX, IDC_COMBO_PARAMETERS, this->comboParameters);
	DDX_Control(pDX, IDC_EDIT_SLIDER_MIN, this->editSliderMin);
	DDX_Control(pDX, IDC_EDIT_SLIDER_MAX, this->editSliderMax);

	DDX_Control(pDX, IDC_CHECK_OPTION_PRICE_RANGE_AUTO, this->checkButtonYAxisAuto);
	DDX_Control(pDX, IDC_EDIT_OPTION_PRICE_MIN, this->editOptionPriceMin);
	DDX_Control(pDX, IDC_EDIT_OPTION_PRICE_MAX, this->editOptionPriceMax);
	DDX_Control(pDX, IDC_EDIT_UNDERLYING_ASSET_PRICE_MIN, this->editUnderlyngAssetPriceMin);
	DDX_Control(pDX, IDC_EDIT_UNDERLYING_ASSET_PRICE_MAX, this->editUnderyingAssetPriceMax);
	DDX_Control(pDX, IDC_EDIT_TIME_LEFT, this->editTimeLeft);
	DDX_Control(pDX, IDC_EDIT_RATE, this->editRiskFreeRate);
	DDX_Control(pDX, IDC_EDIT_VOLATILITY, this->editVolatility);

	//DDX_Control(pDX, IDC_LIST_OPTION_STRATEGY, this->listBox);
	//DDX_Control(pDX, IDC_CUSTOM_OPTION_STRATEGY_POSITIONS, this->gridCtrl);
}


BEGIN_MESSAGE_MAP(CDlgOptionManager, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_SIMULATE_OPTION_STRATEGY, &CDlgOptionManager::OnButtonClickedSimulate)
	ON_BN_CLICKED(IDC_CHECK_OPTION_PRICE_RANGE_AUTO, &CDlgOptionManager::OnCheckButtonClickedAutoYAxis)
	ON_WM_HSCROLL()
	ON_CBN_SELCHANGE(IDC_COMBO_PARAMETERS, &CDlgOptionManager::ResetSlider)
	//ON_EN_CHANGE(IDC_EDIT_SLIDER_VALUE, &CDlgOptionManager::OnEditParameterValueChanged)
	//ON_MESSAGE(WM_HSCROLL, &CDlgOptionManager::OnHScroll)
	//WM_HSCROOL(IDC_SLIDER_PARAMETER, &CDlgOptionManager::OnSliderChanged)
END_MESSAGE_MAP()



void CDlgOptionManager::OnButtonClickedSimulate(){
	// 선택된 Option Strategy Payoff curve 보여준다
	this->Simulate();
}


void CDlgOptionManager::OnCheckButtonClickedAutoYAxis(){
	int checked = this->checkButtonYAxisAuto.GetCheck();
	if(checked == BST_CHECKED){
		this->editOptionPriceMin.EnableWindow(FALSE);
		this->editOptionPriceMax.EnableWindow(FALSE);
	}
	else if(checked == BST_UNCHECKED){
		this->editOptionPriceMin.EnableWindow(TRUE);
		this->editOptionPriceMax.EnableWindow(TRUE);
	}
}


void CDlgOptionManager::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar){
	/*
	// 전략을 선택하고 해야 가능
	int selectedStrategyIndex = this->listBox.GetCurSel();
	if(selectedStrategyIndex >= 0){

		CString cstrStrategyName;
		this->listBox.GetText(selectedStrategyIndex, cstrStrategyName);
		tstring strStrategyName = cstrStrategyName;


		int pos = this->sliderParameter.GetPos();
		double tempPos = pos/100.0;
		this->editParameter.SetWindowText(DataConverter::ConvertDoubleToString(tempPos).c_str());
		//this->spinParameter.SetPos(pos);
		//int temp = this->spinParameter.GetPos();


	}
	else{
		MessageBox(_T("Select a strategy!"));
	}
	*/
	this->Simulate();
	int pos = this->sliderParameter.GetPos();
	double tempPos = pos/double(this->parameterScale);
	CString temp;
	temp.Format(_T("%.4f"), tempPos);
	this->editParameter.SetWindowText(temp);
}

/* 에디트에서 바꿀때만 호출되는 것이 아니고 슬라이더로 바꿀때도 바뀐다.
void CDlgOptionManager::OnEditParameterValueChanged(){
	CString tempParamValue;
	tstring paramValue;
	double value;

	this->editParameter.GetWindowText(tempParamValue);
	paramValue = tempParamValue;
	if(DataConverter::CheckIfNumber(paramValue)){
		value = DataConverter::ConvertStringToDouble(paramValue);
		if(value>=0.0 && value<=1.0){
			int temp = value*100;
			this->sliderParameter.SetPos(temp);
		}
		else{
			MessageBox(_T("Enter a number between min and max"));
		}
	}
	else{
		MessageBox(_T("Enter a number between min and max"));
	}
}
*/


BOOL CDlgOptionManager::OnInitDialog()
{
	CDialog::OnInitDialog();

	this->InitComboBoxParameters();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	//SetWindowPos(&wndTop, 0, 0, 1100, 820, SWP_NOMOVE);
	CenterWindow();


	// 옵션 페이오프 커브 그리기
	const char *imageMap = 0;
	BaseChart* xyChart = this->InitXYChart(&imageMap);
	if(xyChart != 0){
		this->m_ChartViewer.setChart(xyChart);
		this->m_ChartViewer.setImageMap(imageMap);
		if(xyChart!=0){
			delete xyChart;
		}
	}	

	this->editOptionPriceMin.EnableWindow(FALSE);
	this->editOptionPriceMax.EnableWindow(FALSE);
	this->checkButtonYAxisAuto.SetCheck(BST_CHECKED);

	return TRUE;  // return TRUE  unless you set the focus to a control
}


void CDlgOptionManager::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}



BaseChart* CDlgOptionManager::InitXYChart(const char **imageMap){
	int min = -100;
	int max = 100;
	int range = max - min;

	double* xLabels = new double[range];
	int val = 0;
	for(int i=0; i<range; i++){
		val = min+i;
		xLabels[i] = val; 
	}

	// Create an XYChart object of size 600 x 300 pixels, with a light blue (EEEEFF)
	// background, black border, 1 pxiel 3D border effect and rounded corners
	//XYChart *c = new XYChart(600, 300, 0xeeeeff, 0x000000, 1);
	XYChart *c = new XYChart(950,500);
	//c->setRoundedFrame();

	// Set the plotarea at (55, 58) and of size 520 x 195 pixels, with white
	// background. Turn on both horizontal and vertical grid lines with light grey
	// color (0xcccccc)
	c->setPlotArea(55, 58, 850, 400, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);

	// Add a legend box at (50, 30) (top of the chart) with horizontal layout. Use 9
	// pts Arial Bold font. Set the background and border color to Transparent.
	c->addLegend(50, 30, false, "arialbd.ttf", 9)->setBackground(Chart::Transparent);

	// Add a title box to the chart using 15 pts Times Bold Italic font, on a light
	// blue (CCCCFF) background with glass effect. white (0xffffff) on a dark red
	// (0x800000) background, with a 1 pixel 3D border.
	c->addTitle("Option Payoff Curve", 0, 15);

	// Set the labels on the x axis.
	c->xAxis()->setLabels(DoubleArray(xLabels, range));
	c->yAxis()->setLabels(DoubleArray(xLabels, range));

	// Display 1 out of 3 labels on the x-axis.
	c->xAxis()->setLabelStep(10);
	c->yAxis()->setLabelStep(10);

	// Add a title to the x axis
	c->xAxis()->setTitle("Underlying Asset Price");
	c->yAxis()->setTitle("Option Price");

	c->xAxis()->setOffset(0,0);
	c->yAxis()->setOffset(0,0);
	c->xAxis()->setWidth(2);
	c->yAxis()->setWidth(2);


	// Add a line layer to the chart
	LineLayer *layer = c->addLineLayer();

	// Set the default line width to 2 pixels
	layer->setLineWidth(2);

	// Add the three data sets to the line layer. For demo purpose, we use a dash
	// line color for the last line

	// Output the chart
	c->makeChart();

	//include tool tip for the chart
	*imageMap = c->getHTMLImageMap("clickable", "", "title='[{dataSetName}] Hour {xLabel}: {value} MBytes'");

	if(xLabels!=0){
		delete[] xLabels;
	}


	return c;
}

BaseChart* CDlgOptionManager::GraphOptionPayoffCurve2(const char **imageMap, PositionList& positionList){
	XYChart *xyChart = 0;
	
	double dblRange = (double(this->xMax) - double(this->xMin))/this->xScale;
	int range(dblRange);
	double* values = new double[range];
	double* payoffs = new double[range];
	double* xLabels = new double[range];

	double* valuesBroker = new double[range];
	
	/*
	double yMax = 0.0;
	double yMin = 0.0;
	double absLargestDoubleValue = 0.0;
	double absLargestDoublePayoff = 0.0;
	double absYAxisDoubleValue = 0.0;
	*/
		
	double increment = this->xScale;
	double underlyingAssetPrice(this->xMin);
	for(int i=0; i<range; i++){
		OptionParameter params(underlyingAssetPrice, this->expiryRatio, this->riskFreeRate, this->histVolatility);
		OptionParameter paramsBroker(underlyingAssetPrice, this->expiryRatioByDayCount, this->riskFreeRate, this->histVolatility);

		double sumValues = 0.0;
		double sumPayoffs = 0.0;
		double sumValuesBroker = 0.0;
		for(int j=0; j<positionList.GetLength(); j++){
			positionList.GetAt(j)->Valuate(params);
			sumValues += positionList.GetAt(j)->GetValue();
			sumPayoffs += positionList.GetAt(j)->GetPayoff();

			positionList.GetAt(j)->Valuate(paramsBroker);
			sumValuesBroker += positionList.GetAt(j)->GetValue();
		}

		values[i] = sumValues;
		payoffs[i] = sumPayoffs;
		valuesBroker[i] = sumValuesBroker;
		xLabels[i] = underlyingAssetPrice;

		underlyingAssetPrice += increment;
		/*
		if(absLargestDoubleValue<abs(sumValues)){
			absLargestDoubleValue = abs(sumValues);
		}
		if(absLargestDoublePayoff<abs(sumPayoffs)){
			absLargestDoublePayoff = abs(sumPayoffs);
		}
		*/
	}
	

	xyChart = new XYChart(950,500, 0xcccccc, 0x000000, 1);
	xyChart->setPlotArea(55, 58, 850, 400, 0xffffff, -1, -1, 0xcccccc, 0xcccccc);
	xyChart->addLegend(50, 30, false, "arialbd.ttf", 9)->setBackground(Chart::Transparent);

	
	xyChart->setAxisAtOrigin(Chart::XYAxisAtOrigin);
	xyChart->addTitle("Option Payoff Curve", 0, 15);	
	xyChart->yAxis()->setTitle("Option Price");
	xyChart->xAxis()->setTitle("Underlying Asset Price");
	xyChart->yAxis()->setLabelStep(2);
	xyChart->yAxis()->setWidth(2);

	//xyChart->xAxis()->setLabels(DoubleArray(xLabels, range));
	xyChart->xAxis()->setLabelStep(2);
	xyChart->xAxis()->setWidth(2);
	
	
	
	LineLayer *layer = xyChart->addLineLayer();
	layer->setLineWidth(2);
	
	layer->addDataSet(DoubleArray(payoffs, range), 0xff0000, "Payoff at Maturity");
	layer->addDataSet(DoubleArray(values, range), 0x008800, "Value by TS");
	layer->addDataSet(DoubleArray(valuesBroker, range), 0x99CC00, "Value by Broker");
	layer->setXData(DoubleArray(xLabels, range));
	
	double index = this->pParentDlgOptionStrategy->GetUnderlyingAssetPrice();
	CString cstrIndex;
	cstrIndex.Format(_T("%.2f"), index);
	

	Mark* mark = xyChart->xAxis()->addMark(index, 0xCC0000, "KOSPI200:"+cstrIndex);
	mark->setAlignment(TopCenter);
	xyChart->makeChart();

	//include tool tip for the chart
	*imageMap = xyChart->getHTMLImageMap("clickable", "", "title='[{dataSetName}] x {xLabel}: y {value}'");

	
	if(payoffs!=0){
		delete[] payoffs;
	}
	if(values!=0){
		delete[] values;
	}
	if(xLabels!=0){
		delete[] xLabels;
	}
	
	return xyChart;
}



void CDlgOptionManager::InitComboBoxParameters(){
	this->comboParameters.AddString(_T("-select-"));
	this->comboParameters.AddString(_T("변동성"));
	this->comboParameters.AddString(_T("잔존만기"));
	this->comboParameters.AddString(_T("무위험이자율"));
	this->comboParameters.SetCurSel(0);
	this->InitSliderParameter();
}

void CDlgOptionManager::InitSliderParameter(){
	this->editVolatility.EnableWindow(TRUE);
	this->editTimeLeft.EnableWindow(TRUE);
	this->editRiskFreeRate.EnableWindow(TRUE);
	this->sliderParameter.EnableWindow(FALSE);

	int min = 0;
	int max = this->parameterScale;
	int increment = 1;
	int initPos = 0;

	// 콤보박스 초기화
	int index = this->comboParameters.FindString(0, _T("-select-"));
	this->comboParameters.SetCurSel(index);

	// 슬라이더 초기화
	this->sliderParameter.SetRange(min, max);
	this->sliderParameter.SetPos(initPos);
	this->sliderParameter.SetTicFreq(increment);
	this->sliderParameter.SetLineSize(increment);
	this->sliderParameter.SetPageSize(increment);
	double tempMin = min/double(this->parameterScale);
	double tempMax = max/double(this->parameterScale);
	CString temp;
	temp.Format(_T("%.4f"), tempMin);
	this->editSliderMin.SetWindowText(temp);
	temp.Format(_T("%.4f"), tempMax);
	this->editSliderMax.SetWindowText(temp);
	double tempInitPos = initPos/double(this->parameterScale);
	temp.Format(_T("%.4f"), tempInitPos);
	this->editParameter.SetWindowText(temp);
}

void CDlgOptionManager::InitSliderParameterForVolatility(){

	this->editVolatility.SetWindowText(_T(""));
	this->editVolatility.EnableWindow(FALSE);
	this->editTimeLeft.EnableWindow(TRUE);
	this->editRiskFreeRate.EnableWindow(TRUE);
	this->sliderParameter.EnableWindow(TRUE);

	int min = 0;
	int max = this->parameterScale;
	int increment = 1;
	int initPos = 0;

	// 콤보박스 초기화
	int index = this->comboParameters.FindString(0, _T("변동성"));
	this->comboParameters.SetCurSel(index);

	// 슬라이더 초기화
	this->sliderParameter.SetRange(min, max);
	this->sliderParameter.SetPos(initPos);
	this->sliderParameter.SetTicFreq(increment);
	this->sliderParameter.SetLineSize(increment);
	this->sliderParameter.SetPageSize(increment);
	double tempMin = min/double(this->parameterScale);
	double tempMax = max/double(this->parameterScale);

	CString temp;
	temp.Format(_T("%.4f"), tempMin);
	this->editSliderMin.SetWindowText(temp);
	temp.Format(_T("%.4f"), tempMax);
	this->editSliderMax.SetWindowText(temp);
	double tempInitPos = initPos/double(this->parameterScale);
	temp.Format(_T("%.4f"), tempInitPos);
	this->editParameter.SetWindowText(temp);

	// 스핀 초기화
	//this->spinParameter.SetRange(min, max);
	//UDACCEL udaccel[] = {{0, increment}};
	//this->spinParameter.SetAccel(1, udaccel);
}

void CDlgOptionManager::InitSliderParameterForTime(){

	this->editTimeLeft.SetWindowText(_T(""));
	this->editTimeLeft.EnableWindow(FALSE);
	this->editVolatility.EnableWindow(TRUE);
	this->editRiskFreeRate.EnableWindow(TRUE);
	this->sliderParameter.EnableWindow(TRUE);

	int min = 0;
	int max = this->parameterScale;
	int increment = 1;
	int initPos = 0;

	// 콤보박스 초기화
	int index = this->comboParameters.FindString(0, _T("잔존만기"));
	this->comboParameters.SetCurSel(index);

	// 슬라이더 초기화
	this->sliderParameter.SetRange(min, max);
	this->sliderParameter.SetPos(initPos);
	this->sliderParameter.SetTicFreq(increment);
	this->sliderParameter.SetLineSize(increment);
	this->sliderParameter.SetPageSize(increment);
	double tempMin = min/double(this->parameterScale);
	double tempMax = max/double(this->parameterScale);
	CString temp;
	temp.Format(_T("%.4f"), tempMin);
	this->editSliderMin.SetWindowText(temp);
	temp.Format(_T("%.4f"), tempMax);
	this->editSliderMax.SetWindowText(temp);
	double tempInitPos = initPos/double(this->parameterScale);
	temp.Format(_T("%.4f"), tempInitPos);
	this->editParameter.SetWindowText(temp);
}

void CDlgOptionManager::InitSliderParameterForRiskFreeRate(){
	this->editRiskFreeRate.SetWindowText(_T(""));
	this->editRiskFreeRate.EnableWindow(FALSE);
	this->editVolatility.EnableWindow(TRUE);
	this->editTimeLeft.EnableWindow(TRUE);
	this->sliderParameter.EnableWindow(TRUE);

	int min = 0;
	int max = this->parameterScale;
	int increment = 1;
	int initPos = 0;

	// 콤보박스 초기화
	int index = this->comboParameters.FindString(0, _T("무위험이자율"));
	this->comboParameters.SetCurSel(index);

	// 슬라이더 초기화
	this->sliderParameter.SetRange(min, max);
	this->sliderParameter.SetPos(initPos);
	this->sliderParameter.SetTicFreq(increment);
	this->sliderParameter.SetLineSize(increment);
	this->sliderParameter.SetPageSize(increment);
	double tempMin = min/double(this->parameterScale);
	double tempMax = max/double(this->parameterScale);
	CString temp;
	temp.Format(_T("%.4f"), tempMin);
	this->editSliderMin.SetWindowText(temp);
	temp.Format(_T("%.4f"), tempMax);
	this->editSliderMax.SetWindowText(temp);
	double tempInitPos = initPos/double(this->parameterScale);
	temp.Format(_T("%.4f"), tempInitPos);
	this->editParameter.SetWindowText(temp);
}

void CDlgOptionManager::ResetSlider(){
	int index = this->comboParameters.GetCurSel();
	CString cstrTemp;
	this->comboParameters.GetLBText(index, cstrTemp);
	tstring parameter = cstrTemp;

	if(parameter.compare(_T("-select-"))==0){
		this->InitSliderParameter();
	}
	else if(parameter.compare(_T("변동성"))==0){
		this->InitSliderParameterForVolatility();
	}
	else if(parameter.compare(_T("잔존만기"))==0){
		this->InitSliderParameterForTime();
	}
	else if(parameter.compare(_T("무위험이자율"))==0){
		this->InitSliderParameterForRiskFreeRate();
	}
	else{
		this->InitSliderParameter();
	}
}


BOOL CDlgOptionManager::ReadParameter(double* timeLeft, double* riskFreeRate, double* vol){
	BOOL valid = TRUE;

	CString cstrTimeLeft;

	CString cstrRiskFreeRate;

	CString cstrVol;

	tstring temp;

	CString cstrComboParameter;
	this->comboParameters.GetWindowText(cstrComboParameter);
	tstring strCombParameter = cstrComboParameter;

	if(strCombParameter.compare(_T("잔존만기"))==0){
		int pos = this->sliderParameter.GetPos();
		double doublePos(pos);
		*timeLeft = doublePos;
	}
	else{
		this->editTimeLeft.GetWindowText(cstrTimeLeft);
		*timeLeft = _ttof(cstrTimeLeft);
	}
	
	if(strCombParameter.compare(_T("무위험이자율"))==0){
		int pos = this->sliderParameter.GetPos();
		double doublePos(pos/100.0);
		*riskFreeRate = doublePos;
	}
	else{
		this->editRiskFreeRate.GetWindowText(cstrRiskFreeRate);
		temp = cstrRiskFreeRate;
		if(DataConverter::CheckIfNumber(temp)){
			*riskFreeRate = DataConverter::ConvertStringToDouble(temp);
		}
		else{
			valid = FALSE;
		}
	}
	
	if(strCombParameter.compare(_T("변동성"))==0){
		int pos = this->sliderParameter.GetPos();
		double doublePos(pos/100.0);
		*vol = doublePos;
	}
	else{
		this->editVolatility.GetWindowText(cstrVol);
		temp = cstrVol;
		if(DataConverter::CheckIfNumber(temp)){
			*vol = DataConverter::ConvertStringToDouble(temp);
		}
		else{
			valid = FALSE;
		}
	}
	return valid;
}


void CDlgOptionManager::layoutCharts()
{
	// Get the size of the window
	CRect winRect;
	GetWindowRect(&winRect);


	// The margin between charts. 
	int margin = 5;

	// The first chart is at the right side of the list box.
	int cursorX = winRect.left + margin;

	// The first chart is align with the top of the window.
	int cursorY = margin;

	int maxWidth = 0;
	int lineHeight = 0;



	// Get the size of the chart
	CRect chartRect;
	m_ChartViewer.GetWindowRect(&chartRect);

	if ( (cursorX + (chartRect.right - chartRect.left) > 
		(winRect.right - winRect.left)))
	{
		// There is not enough space left for the chart, so move to next line
		cursorY += (lineHeight + margin);
		cursorX = winRect.left + margin;
		lineHeight = 0;
	}

	// Put the chart in the current cursor position
	m_ChartViewer.MoveWindow(cursorX, cursorY, chartRect.right - chartRect.left,
		chartRect.bottom - chartRect.top);

	// Advance the x cursor
	cursorX += (chartRect.right - chartRect.left + margin);

	// Update the maximum line width
	if (cursorX > maxWidth)
		maxWidth = cursorX;

	// Update the line height
	if (chartRect.bottom - chartRect.top > lineHeight)
		lineHeight = chartRect.bottom - chartRect.top;

	m_ChartViewer.ShowWindow(TRUE);
}


void CDlgOptionManager::Simulate(){
	this->expiryRatio= this->GetExpiryRatio();
	this->riskFreeRate = this->GetRiskFreeRate();
	this->histVolatility = this->GetHistoricalVolatility();
	this->expiryRatioByDayCount = this->pParentDlgOptionStrategy->GetExpiryRatioByDayCount();

	int selectedStrategyIndex = this->pParentDlgOptionStrategy->GetSelectedStrategyIndex();
	double min = this->pParentDlgOptionStrategy->optionManager->GetOptionStrategyList().GetAt(selectedStrategyIndex).GetStrikePriceMin();
	double max = this->pParentDlgOptionStrategy->optionManager->GetOptionStrategyList().GetAt(selectedStrategyIndex).GetStrikePriceMax();

	double underlyingAssetPrice = this->pParentDlgOptionStrategy->GetUnderlyingAssetPrice();

	if(min>underlyingAssetPrice){
		min = underlyingAssetPrice;
	}
	if(max<underlyingAssetPrice){
		max = underlyingAssetPrice;
	}

	min = min*(.98);
	max = max*(1.02);

	this->xMin = DataConverter::ConvertDoubleToInt(min);
	this->xMax = DataConverter::ConvertDoubleToInt(max);


	CString temp;
	temp.Format(_T("%f"), this->expiryRatio);
	this->editTimeLeft.SetWindowText(temp);

	temp.Format(_T("%f"), this->riskFreeRate);
	this->editRiskFreeRate.SetWindowText(temp);

	temp.Format(_T("%f"), this->histVolatility);
	this->editVolatility.SetWindowText(temp);

	temp.Format(_T("%d"), this->xMin);
	this->editUnderlyngAssetPriceMin.SetWindowText(temp);

	temp.Format(_T("%d"), this->xMax);
	this->editUnderyingAssetPriceMax.SetWindowText(temp);



	int index = this->pParentDlgOptionStrategy->GetSelectedStrategyIndex();
	if(index>= 0){

		PositionList* p_positionList = &(this->pParentDlgOptionStrategy->optionManager->GetOptionStrategyList().GetAt(index));

		const char *imageMap = 0;
		BaseChart* xyChart = this->GraphOptionPayoffCurve2(&imageMap, *p_positionList);
		if(xyChart != 0){
			this->m_ChartViewer.setChart(xyChart);
			this->m_ChartViewer.setImageMap(imageMap);
			if(xyChart!=0){
				delete xyChart;
			}
		}

	}
}


double CDlgOptionManager::GetExpiryRatio(){
	double expiryRatio = 0.0;

	CString selectedParameter = this->GetSelectedComboboxParameter();

	tstring param = selectedParameter;
	if(param.compare(_T("잔존만기"))==0){
		int pos = this->sliderParameter.GetPos();
		expiryRatio = pos/10000.0;
	}
	else{
		expiryRatio = this->pParentDlgOptionStrategy->GetExpiryRatio();
	}
	
	return expiryRatio;
}


double CDlgOptionManager::GetRiskFreeRate(){
	double riskFreeRate = 0.0;

	CString selectedParameter = this->GetSelectedComboboxParameter();

	tstring param = selectedParameter;
	if(param.compare(_T("무위험이자율"))==0){
		int pos = this->sliderParameter.GetPos();
		riskFreeRate = pos/10000.0;
	}
	else{
		riskFreeRate = this->pParentDlgOptionStrategy->GetRiskFreeRate();
	}

	return riskFreeRate;
}


double CDlgOptionManager::GetHistoricalVolatility(){
	double vol = 0.0;

	CString selectedParameter = this->GetSelectedComboboxParameter();

	tstring param = selectedParameter;
	if(param.compare(_T("변동성"))==0){
		int pos = this->sliderParameter.GetPos();
		vol = pos/10000.0;
	}
	else{
		vol = this->pParentDlgOptionStrategy->GetHistoricalVol();
	}

	return vol;
}



CString CDlgOptionManager::GetSelectedComboboxParameter(){
	int index = this->comboParameters.GetCurSel();
	CString cstrTemp;
	this->comboParameters.GetLBText(index, cstrTemp);
	return cstrTemp;
}