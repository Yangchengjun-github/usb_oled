#include "task.h"

static TASK_COMPONENTS Task_Comps[] =
	{
		// 状态  计数  周期  函数
		{0, 10, 10, task_key}, /* task 1 Period： 10ms */
		{0, 10, 10, task_sys},
		//{0, 1000, 1000, task_debug},
		//{0, 500, 500, adc_task},
		//{0, 300, 300, lcd_display},
		/* Add new task here */
};

U8_T Tasks_Max = sizeof(Task_Comps) / sizeof(Task_Comps[0]);

//========================================================================
// 函数: Task_Handler_Callback
// 描述: 任务标记回调函数.
// 参数: None.
// 返回: None.
// 版本: V1.0, 2012-10-22
//========================================================================
void Task_Marks_Handler_Callback(void)
{
	U8_T i;
	for (i = 0; i < Tasks_Max; i++)
	{
		if (Task_Comps[i].TIMCount) /* If the time is not 0 */
		{
			Task_Comps[i].TIMCount--;		 /* Time counter decrement */
			if (Task_Comps[i].TIMCount == 0) /* If time arrives */
			{
				/*Resume the timer value and try again */
				Task_Comps[i].TIMCount = Task_Comps[i].TRITime;
				Task_Comps[i].Run = 1; /* The task can be run */
			}
		}
	}
}

//========================================================================
// 函数: Task_Pro_Handler_Callback
// 描述: 任务处理回调函数.
// 参数: None.
// 返回: None.
// 版本: V1.0, 2012-10-22
//========================================================================

void Task_Pro_Handler_Callback(void)
{
	U8_T i;
	for (i = 0; i < Tasks_Max; i++)
	{
		if (Task_Comps[i].Run) /* If task can be run */
		{
			Task_Comps[i].Run = 0;	  /* Flag clear 0 */
			Task_Comps[i].TaskHook(); /* Run task */
		}
	}
}