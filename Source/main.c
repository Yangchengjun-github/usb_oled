/*
 ******************************************************************************
 * @file    main.c
 * @author  APT AE Team
 * @version V1.15
 * @date    2022/08/30
 ******************************************************************************
 *THIS SOFTWARE WHICH IS FOR ILLUSTRATIVE PURPOSES ONLY WHICH PROVIDES
 *CUSTOMER WITH CODING INFORMATION REGARDING THEIR PRODUCTS.
 *APT CHIP SHALL NOT BE HELD RESPONSIBILITY ADN LIABILITY FOR ANY DIRECT,
 *INDIRECT DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF
 *SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 *CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.AND APT CHIP RESERVES
 *THE RIGHT TO MAKE CHANGES IN THE SOFTWARE WITHOUT NOTIFICATION
 ******************************************************************************
 */
/* Includes ------------------------------------------------------------------*/
#include "apt32f102a.h"
#include "apt32f102a_adc.h"
#include "apt32f102a_bt.h"
#include "apt32f102a_coret.h"
#include "apt32f102a_countera.h"
#include "apt32f102a_crc.h"
#include "apt32f102a_ept.h"
#include "apt32f102a_et.h"
#include "apt32f102a_gpio.h"
#include "apt32f102a_gpt.h"
#include "apt32f102a_i2c.h"
#include "apt32f102a_ifc.h"
#include "apt32f102a_lpt.h"
#include "apt32f102a_rtc.h"
#include "apt32f102a_sio.h"
#include "apt32f102a_spi.h"
#include "apt32f102a_syscon.h"
#include "apt32f102a_uart.h"
#include "apt32f102a_wwdt.h"
#include "apt32f102a_types_local.h"
#include "apt32f102a_tkey.h"
#include "task.h"
//#include "bmp.h"
#include "oled.h"
//#include "oledfont.h"

/* defines -------------------------------------------------------------------*/
/* externs Register-------------------------------------------------------------------*/

/* externs function-------------------------------------------------------------------*/
extern void delay_nms(unsigned int t);
extern void APT32F102_init(void);

/***************************************************/
// main
/**************************************************/
int main(void)
{
  // delay_nms(1000);
  // SYSCON_WDT_CMD(DISABLE);
  // PCLK_goto_deepsleep_mode();
  APT32F102_init();
  OLED_Init();         // 初始化OLED
  OLED_ColorTurn(0);   // 0正常显示，1 反色显示
  OLED_DisplayTurn(0); // 0正常显示 1 屏幕翻转显示
  OLED_Clear();
  OLED_ShowString(0, 0, "nihao", 16);

  while (1)
  {

    SYSCON_IWDCNT_Reload();
    Task_Pro_Handler_Callback();
	//OLED_ShowString(0, 0, "nihao", 16);

    //....
    //....
  }
}
/******************* (C) COPYRIGHT 2019 APT Chip *****END OF FILE****/