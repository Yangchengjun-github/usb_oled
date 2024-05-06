#ifndef _LED_H_
#define _LED_H_
#include "apt32f102a_gpio.h"
#include "define.h"

#define LED1_H()   	GPIO_Init(LED1_PROT,LED1_PIN,0);GPIO_Set_Value(LED1_PROT,LED1_PIN,1);
#define LED1_L() 	GPIO_Init(LED1_PROT,LED1_PIN,0);GPIO_Set_Value(LED1_PROT,LED1_PIN,0);
#define LED1_Z() 	GPIO_InPutOutPut_Disable(LED1_PROT,LED1_PIN);

#define LED2_H()   	GPIO_Init(LED2_PROT,LED2_PIN,0);GPIO_Set_Value(LED2_PROT,LED2_PIN,1);
#define LED2_L() 	GPIO_Init(LED2_PROT,LED2_PIN,0);GPIO_Set_Value(LED2_PROT,LED2_PIN,0);
#define LED2_Z() 	GPIO_InPutOutPut_Disable(LED2_PROT,LED2_PIN);

#define LED3_H()   	GPIO_Init(LED3_PROT,LED3_PIN,0);GPIO_Set_Value(LED3_PROT,LED3_PIN,1);
#define LED3_L() 	GPIO_Init(LED3_PROT,LED3_PIN,0);GPIO_Set_Value(LED3_PROT,LED3_PIN,0);
#define LED3_Z() 	GPIO_InPutOutPut_Disable(LED3_PROT,LED3_PIN);

#define LED4_H()   	GPIO_Init(LED4_PROT,LED4_PIN,0);GPIO_Set_Value(LED4_PROT,LED4_PIN,1);
#define LED4_L() 	GPIO_Init(LED4_PROT,LED4_PIN,0);GPIO_Set_Value(LED4_PROT,LED4_PIN,0);
#define LED4_Z() 	GPIO_InPutOutPut_Disable(LED4_PROT,LED4_PIN);

#define LED5_H()   	GPIO_Init(LED5_PROT,LED5_PIN,0);GPIO_Set_Value(LED5_PROT,LED5_PIN,1);
#define LED5_L() 	GPIO_Init(LED5_PROT,LED5_PIN,0);GPIO_Set_Value(LED5_PROT,LED5_PIN,0);
#define LED5_Z() 	GPIO_InPutOutPut_Disable(LED5_PROT,LED5_PIN);

#define LED6_H()   	GPIO_Init(LED6_PROT,LED6_PIN,0);GPIO_Set_Value(LED6_PROT,LED6_PIN,1);
#define LED6_L() 	GPIO_Init(LED6_PROT,LED6_PIN,0);GPIO_Set_Value(LED6_PROT,LED6_PIN,0);
#define LED6_Z() 	GPIO_InPutOutPut_Disable(LED6_PROT,LED6_PIN);

#define LEDX_Z()	LED1_Z();LED2_Z();LED3_Z();LED4_Z();LED5_Z();LED6_Z();

typedef struct
{
    U8_T LED_A3 : 1;
    U8_T LED_B3 : 1;
    U8_T LED_C3 : 1;
    U8_T LED_D3 : 1;
    U8_T LED_E3 : 1;
    U8_T LED_F3 : 1;
    U8_T LED_G3 : 1;
    U8_T LED_EMPTY2: 1;
    U16_T LED_NUM;
} stLED_T;
extern stLED_T stLED;

void led_display(void);

#define LED_LOCK       stLED.LED_E3                             //锁
#define LED_INTERACTION        stLED.LED_A3                      //感应模式
#define LED_INTERVAL     stLED.LED_C3               //间歇模式
#define LED_CONTINUE      stLED.LED_B3              //持续模式
#define LED_BAT  stLED.LED_D3      //电池
#define LED_BAT_LOW stLED.LED_G3   //电池低电（红）
#define LED_WARNING stLED.LED_F3   //滤芯警告
#define LED_DAY stLED.LED_NUM          //天数倒计时
#define DISPLAY_OFF 99   //息屏

#endif