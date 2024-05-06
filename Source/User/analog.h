#ifndef _ANALOG_H_
#define _ANALOG_H_
#include "apt32f102a_adc.h"
#include "apt32f102a_gpio.h"

typedef enum
{
    CH_USB1,
    CH_USB2,
    CH_USB3,
    CH_USB4,
    MAXNUM_CH

} adc_channel_typedef;

void adc_task(void);
void adc_conver(U8_T ch);

extern void my_printf(const char *fmt, ...);

extern U16_T adc_result_direct[MAXNUM_CH];  // ADC直接结果
extern U16_T adc_result_conver[MAXNUM_CH];   // ADC换算结果


#define BAT_VOLTAGE_LOW 3400
#define BAT_VOLTAGE_EMPTY 3000

#endif