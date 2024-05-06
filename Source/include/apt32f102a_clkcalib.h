  /******************************************************************************
  * @file    apt32f102_clkcalib.h
  * @author  APT AE Team
  * @version V1.22
  * @date    2021/11/22
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


#include "apt32f102a.h"


/**
  * @brief  CALIB OSC SELECTE SET
  */
typedef enum
{
	CLK_HFOSC_24M	=	(0x1ul),
	CLK_HFOSC_12M	=	(0x2ul),
	CLK_HFOSC_6M	=	(0x3ul),
	CLK_IMOSC_5556K	=	(0x4ul),
	CLK_IMOSC_4194K	=	(0x5ul),
	CLK_IMOSC_2097K	=	(0x6ul),
	CLK_IMOSC_131K	=	(0x7ul)
}CALIB_OSC_SELECTE_TypeDef;


extern U8_T std_clk_calib(CALIB_OSC_SELECTE_TypeDef OSC_CALIB_X);