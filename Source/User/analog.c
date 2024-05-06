#include "analog.h"
#include "logic.h"

U16_T adc_result_direct[MAXNUM_CH] = {0}; // ADC直接结果
U16_T adc_result_conver[MAXNUM_CH] = {0}; // ADC换算结果
/**
 * @brief adc通道转化
 * @param [in] ch 通道
 * 
 * @details 
 */
void adc_conver(U8_T ch) // adc检测函数  参数为adc通道
{
	ADC12_Software_Reset();
	ADC12_CLK_CMD(ADC_CLK_CR, ENABLE);							  // enable ADC CLK
	ADC12_Configure_Mode(ADC12_12BIT, One_shot_mode, 0, 6, 2, 1); // 12BIT ADC; Continuous mode; Conversion priority selection 0; Holding cycles=6 ;ADC_CLK=PCLK/2*2=0.2us; Number of Conversions=1
	switch (ch)
	{
	case CH_USB1:
	{
		ADC12_Configure_VREF_Selecte(ADC12_VREFP_VDD_VREFN_VSS);						 // ADC VREF Positive FVR4.096V,negative VSS
		ADC12_ConversionChannel_Config(ADC12_ADCIN10, ADC12_CV_RepeatNum1, ADC12_AVGDIS, 0); // SEQ0 chose ADCIN0, 6 Holding cycles, Average 1 time
		break;
	}
	case CH_USB2:
	{
		ADC12_Configure_VREF_Selecte(ADC12_VREFP_VDD_VREFN_VSS);							// ADC VREF Positive FVR4.096V,negative VSS
		ADC12_ConversionChannel_Config(ADC12_ADCIN11, ADC12_CV_RepeatNum1, ADC12_AVGDIS, 0); // SEQ0 chose ADCIN0, 6 Holding cycles, Average 1 time
		break;
	}
	case CH_USB3:
	{
		ADC12_Configure_VREF_Selecte(ADC12_VREFP_VDD_VREFN_VSS);							// ADC VREF Positive FVR4.096V,negative VSS
		ADC12_ConversionChannel_Config(ADC12_ADCIN12, ADC12_CV_RepeatNum1, ADC12_AVGDIS, 0); // SEQ0 chose ADCIN0, 6 Holding cycles, Average 1 time
		break;
	}
	case CH_USB4:
	{
		ADC12_Configure_VREF_Selecte(ADC12_VREFP_VDD_VREFN_VSS);							 // ADC VREF Positive FVR4.096V,negative VSS
		ADC12_ConversionChannel_Config(ADC12_ADCIN13, ADC12_CV_RepeatNum1, ADC12_AVGDIS, 0); // SEQ0 chose ADCIN0, 6 Holding cycles, Average 1 time
		break;
	}
	}

	ADC12_CMD(ENABLE);	// enable ADC
	ADC12_ready_wait(); // wait ADC get ready
	/*平均值滤波*/
	#if 0
	if (ch == CH_CC2)
	{
		adc_return[ch] = 0;
		for (U8_T i = 0; i < 16; i++)
		{
			ADC12_Control(ADC12_START); // ADC convert start
			ADC12_SEQEND_wait(0);
			adc_return[ch] += ADC0->DR[0];
		}
		adc_return[ch] >>= 4;
	}
	
	/*单次结果*/
	else
	#endif
	{
		ADC12_Control(ADC12_START); // ADC convert start
		ADC12_SEQEND_wait(0);
		adc_result_direct[ch] = ADC0->DR[0];
	}
	/*ADC结果换算为有意义的物理量*/
	switch (ch)
	{
	case CH_USB1:
		adc_result_conver[ch] = adc_result_direct[ch] /4096.0 * 3300  ;
		break;
	case CH_USB2:
		adc_result_conver[ch] = adc_result_direct[ch] / 4096.0 * 3300;
		break;
	case CH_USB3:
		adc_result_conver[ch] = adc_result_direct[ch] / 4096.0 * 3300;
		break;
	case CH_USB4:
		adc_result_conver[ch] = (adc_result_direct[ch] / 4096.0 * 3300 * 1.1 - 26) >= 0 ? (adc_result_direct[ch] / 4096.0 * 3300 * 1.1 - 26) :  0;
		break;
	}
}
/*adc_task*/
void adc_task(void)
{
	U8_T i;
	for (i = 0; i < MAXNUM_CH; i++)
	{
		adc_conver(i);
	}
}
