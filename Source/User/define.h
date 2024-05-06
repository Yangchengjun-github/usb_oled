#ifndef _DEFINE_H
#define _DEFINE_H

#include "apt32f102a_gpio.h"


/*CHARGE_F*/
#define CHARGE_PROT GPIOB0
#define CHARGE_PIN 1
/*LDO*/
#define LDO_PROT GPIOB0
#define LDO_PIN 4
/*VBAT*/
#define VBAT_PROT GPIOA0
#define VBAT_PIN 12
/*V5OUT*/
#define V5OUT_PROT GPIOB0
#define V5OUT_PIN 5
/*VIN*/
#define VIN_PROT GPIOA0
#define VIN_PIN 8
/*SIGNAL*/
#define SIGNAL_PROT GPIOA0
#define SIGNAL_PIN 10
/*BOOST_EN*/
#define BOOST_PROT GPIOA0
#define BOOST_PIN 9
/*KEY*/
#define KEY_T2_PROT GPIOB0
#define KEY_T2_PIN 3
#define KEY_T1_PROT GPIOB0
#define KEY_T1_PIN 2
/*LED*/
#define LED6_PROT GPIOA0
#define LED6_PIN 13
#define LED5_PROT GPIOA0
#define LED5_PIN 11
#define LED4_PROT GPIOA0
#define LED4_PIN 14
#define LED3_PROT GPIOA0
#define LED3_PIN 15
#define LED2_PROT GPIOA0
#define LED2_PIN 0
#define LED1_PROT GPIOA0
#define LED1_PIN 1


#endif // !