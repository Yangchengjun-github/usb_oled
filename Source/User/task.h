#ifndef _TASK_H_
#define _TASK_H_

#include "key.h"
#include "led.h"
#include "uart.h"
#include "analog.h"
#include "logic.h"
#include "define.h"
#include "gui.h"



typedef struct
{
	U8_T Run;					// 任务状态：Run/Stop
	U16_T TIMCount;			// 定时计数器
	U16_T TRITime;			// 重载计数器
	void (*TaskHook)(void); // 任务函数
} TASK_COMPONENTS;



void Task_Marks_Handler_Callback(void);
void Task_Pro_Handler_Callback(void);

#endif