#include "key.h"
#include "apt32f102a_tkey.h"
#include "uart.h"

stKEY_T stKEY;
/*设置键*/
void key_scan1(void)
{
	static unsigned char key_lock = 0;
	static unsigned int press_cnt = 0;
	static unsigned char short_press = 0;
	//	U8_T key_val = GPIO_Read_Status(KEY_T1_PROT, KEY_T1_PIN);

	U8_T key_val = Key_Map & (0x01 << 6) ? 0 : 1;
	if (key_val)
	{
		key_lock = 0;
		press_cnt = 0;
		if (short_press)
		{
			short_press = 0;
			stKEY.key_t1_short_press = 1;
		}
	}
	else if (!key_lock)
	{
		press_cnt++;
		if (press_cnt >= 1)
		{
			short_press = 1;
		}
		if (press_cnt >= 100)
		{
			short_press = 0;
			stKEY.key_t1_long_press = 1;
			key_lock = 1;
		}
	}
}
/*开机键*/
void key_scan2(void)
{
	static unsigned char key_lock = 0;
	static unsigned int press_cnt = 0;
	static unsigned char short_press = 0;
	//	U8_T key_val = GPIO_Read_Status(KEY_T1_PROT, KEY_T1_PIN);

	U8_T key_val = Key_Map & (0x01 << 8) ? 0 : 1;
	if (key_val)
	{
		key_lock = 0;
		press_cnt = 0;
		if (short_press)
		{
			short_press = 0;
			stKEY.key_t2_short_press = 1;
		}
	}
	else if (!key_lock)
	{
		press_cnt++;
		if (press_cnt >= 1)
		{
			short_press = 1;
		}
		if (press_cnt >= 100)
		{
			short_press = 0;
			stKEY.key_t2_long_press = 1;
			key_lock = 1;
		}
	}
}

void key_scan3(void)
{
	static unsigned char key_lock = 0;
	static unsigned int press_cnt = 0;
	static unsigned char short_press = 0;
	//	U8_T key_val = GPIO_Read_Status(KEY_T1_PROT, KEY_T1_PIN);

	U8_T key_val = Key_Map & (0x01 << 7) ? 0 : 1;
	if (key_val)
	{
		key_lock = 0;
		press_cnt = 0;
		if (short_press)
		{
			short_press = 0;
			stKEY.key_t3_short_press = 1;
		}
	}
	else if (!key_lock)
	{
		press_cnt++;
		if (press_cnt >= 1)
		{
			short_press = 1;
		}
		if (press_cnt >= 100)
		{
			short_press = 0;
			stKEY.key_t3_long_press = 1;
			key_lock = 1;
		}
	}
}

void task_key(void)
{
	static uint8_t t = 0;
	if (t++ >= 10)
	{
		key_scan1();
		key_scan2();
		key_scan3();
		t = 0;
	}
}