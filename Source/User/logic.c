#include "logic.h"
#include "apt32f102a_tkey.h"
#include "apt32f102a_i2c.h"
/*主要应用参数*/

U16_T uart_tx_cnt = 0;
U16_T led_blink_cnt = 0;

// 10ms
void
task_sys(void)
{
	if(uart_tx_cnt++ > 10)
	{
		uart_tx_cnt = 0;
		my_printf("k1:%d,k2:%d,k3:%d\n", Key_Map & (1 << 6) ? 1 : 0, Key_Map & (1 << 8) ? 1 : 0, Key_Map & (1 << 7) ? 1 : 0);
		my_printf("k1:%d,k2:%d,k3:%d\n", baseline_data0[6], baseline_data0[8], baseline_data0[7]);
		my_printf("k1:%d,k2:%d,k3:%d\n", sampling_data0[6], sampling_data0[8], sampling_data0[7]);
	}
	if(KEY_SET_SHORT)
	{
		KEY_SET_SHORT = 0;
		GPIO_Reverse(GPIOA0,4);
		GPIO_Reverse(GPIOA0, 12);
	}
	if (KEY_UP_SHORT)
	{
		KEY_UP_SHORT = 0;
		GPIO_Reverse(GPIOA0, 3);
		GPIO_Reverse(GPIOA0, 9);
	}
	led_blink_cnt++;
//	if(led_blink_cnt <= 50)
//	{
//		GPIO_Write_High(GPIOA0,9);
//		GPIO_Write_Low(GPIOA0, 12);
//	}
//	else if(led_blink_cnt <= 100)
//	{
//		GPIO_Write_High(GPIOA0,12);
//		GPIO_Write_Low(GPIOA0, 9);
//	}
//	else
//	{
//		led_blink_cnt = 0;
//	}
}
