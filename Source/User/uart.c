#include "uart.h"
#include "logic.h"


void uart_string(unsigned char str[100])
{
	unsigned char i = 0;
	
	while(str[i] != '\0')
	{
		UARTTxByte(UART2,str[i]);
		i++;
	}
}

void task_debug(void)
{
	//my_printf("hello world!\n");
}