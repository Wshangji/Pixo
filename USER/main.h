#ifndef __MAIN_H
#define __MAIN_H	 

#include "FreeRTOS.h"
#include "task.h"

#include "delay.h"
#include "usart.h"
#include "sys.h"

#include "thingfly_config.h"

const char *sub_topics[] = {sInfoTopic, sOtaTopic, sNtpTopic, sPropertyTopic, sFunctionTopic, sPropertyOnline, sFunctionOnline, sMonitorTopic};


// APP任务
#define APP_TASK_PRIO		1		//任务优先级
#define APP_STK_SIZE 		128 	//任务堆栈大小 
TaskHandle_t APPTask_Handler; 	//任务句柄
void app_task(void *pvParameters);	//任务函数

// LED灯任务
#define LED0_TASK_PRIO		2
#define LED0_STK_SIZE 		50  
TaskHandle_t LED0Task_Handler;
void led0_task(void *pvParameters);
		 				    
#endif
