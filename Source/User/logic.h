#ifndef _LOGIC_H_
#define _LOGIC_H_

#include "key.h"
#include "analog.h"
#include "apt32f102a_gpio.h"
#include "apt32f102a_syscon.h"
#include "led.h"

typedef enum
{
    sys_state_shutdown,  //关机
    sys_state_sleep,  //睡眠
    sys_state_interaction, // 感应模式
    sys_state_interval,    // 间歇模式
    sys_state_continue     // 持续模式
} sys_state_typedef;
#define RADAR_POW_ON()  GPIO_Write_High(LDO_PROT,LDO_PIN)
#define RADAR_POW_OFF() GPIO_Write_Low(LDO_PROT, LDO_PIN)
#define DET_VIN() (adc_result_conver[CH_VIN] > 2500)  //1:插入
#define DET_CHARGE() (!GPIO_Read_Status(CHARGE_PROT,CHARGE_PIN)) //1:充电中 0:充电结束
#define DET_RADAR() (!GPIO_Read_Status(SIGNAL_PROT,SIGNAL_PIN))  //1:有感应
#define WATER_ON() GPIO_Write_High(BOOST_PROT,BOOST_PIN);GPIO_Write_High(V5OUT_PROT,V5OUT_PIN)
#define WATER_OFF()  GPIO_Write_Low(BOOST_PROT,BOOST_PIN);GPIO_Write_Low(V5OUT_PROT,V5OUT_PIN)
void task_sys(void);

extern volatile  U8_T count_down_15day;
#endif