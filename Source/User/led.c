#include "led.h"
#include "logic.h"

stLED_T stLED;


/*标志数字编码 ： 0-9 + 全熄灭*/
const unsigned char number_encode[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111, 0b00000000};
/*每颗LED对应管脚*/
const unsigned char led_encode[][2] = {	{2,1},{3,1},{4,1},{5,1},{1,4},{2,4},{3,4},   //A1--G1         0-6
									 	{1,2},{3,2},{4,2},{5,2},{1,5},{2,5,},{3,5},   //A2--G2        7-13
									 	{1,3},{2,3},{4,3},  //A3 B3 C3         14-16
									 	{5,3},{5,4},{4,5},	 //D3 E3 F3        17-19
										{1,6} //G3
										};
void led_map(unsigned char high_pin, unsigned char low_pin); // io口动作

void led_display(void)
{
	static U8_T i = 0;
	static U8_T g,s;
	
	//my_printf("%d\n",count_down_15day);
	if(i == 0)
	{
		g = stLED.LED_NUM % 10;
		s = stLED.LED_NUM / 10;
	}
	
	LEDX_Z(); 
	switch (i)
	{
	case 0:
		if (stLED.LED_A3)
			led_map(1, 3);
		break;
	case 1:
		if (stLED.LED_B3)
			led_map(2, 3);
		break;
	case 2:
		if (stLED.LED_C3)
			led_map(4, 3);
		break;
	case 3:
		if (stLED.LED_D3)
			led_map(5, 3);
		break;
	case 4:
		if (stLED.LED_E3)
			led_map(5, 4);
		break;
	case 5:
		if (stLED.LED_F3)
			led_map(4, 5);
		break;
	case 6:
		if (stLED.LED_G3)
			led_map(1, 6);
		break;
	case 7:
		if (number_encode[s] & 1 << (i - 7))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 8:
		if (number_encode[s] & 1 << (i - 7))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 9:
		if (number_encode[s] & 1 << (i - 7))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 10:
		if (number_encode[s] & 1 << (i - 7))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 11:
		if (number_encode[s] & 1 << (i - 7))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 12:
		if (number_encode[s] & 1 << (i - 7))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 13:
		if (number_encode[s] & 1 << (i - 7))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 14:
		if (number_encode[g] & 1 << (i - 14))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 15:
		if (number_encode[g] & 1 << (i - 14))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 16:
		if (number_encode[g] & 1 << (i - 14))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 17:
		if (number_encode[g] & 1 << (i - 14))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 18:
		if (number_encode[g] & 1 << (i - 14))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 19:
		if (number_encode[g] & 1 << (i - 14))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	case 20:
		if (number_encode[g] & 1 << (i - 14))
			led_map(led_encode[i - 7][0], led_encode[i - 7][1]);
		break;
	
	default : break;
	}
	i++;
	/*部分息屏*/
	if (stLED.LED_NUM == 99)
	{
		if (i >= 7)
		{
			i  = 0;
		}
	}
	if(i >= 21)
	{
		i = 0;
	}
}
void led_map(unsigned char high_pin, unsigned char low_pin)
{
	switch (high_pin)
	{
	case 1:
	{
		LED1_H();
		break;
	}
	case 2:
	{
		LED2_H();
		break;
	}
	case 3:
	{
		LED3_H();
		break;
	}
	case 4:
	{
		LED4_H();
		break;
	}
	case 5:
	{
		LED5_H();
		break;
	}
	case 6:
	{
		LED6_H();
		break;
	}
	}
	switch (low_pin)
	{
	case 1:
	{
		LED1_L();
		break;
	}
	case 2:
	{
		LED2_L();
		break;
	}
	case 3:
	{
		LED3_L();
		break;
	}
	case 4:
	{
		LED4_L();
		break;
	}
	case 5:
	{
		LED5_L();
		break;
	}
	case 6:
	{
		LED6_L();
		break;
	}
	}
}
