#ifndef __MAIN_H
#define __MAIN_H	 

#include "FreeRTOS.h"
#include "task.h"

#include "delay.h"
#include "usart.h"
#include "sys.h"

#include "thingfly_config.h"

const char *sub_topics[] = {sInfoTopic, sOtaTopic, sNtpTopic, sPropertyTopic, sFunctionTopic, sPropertyOnline, sFunctionOnline, sMonitorTopic};


// APP����
#define APP_TASK_PRIO		1		//�������ȼ�
#define APP_STK_SIZE 		128 	//�����ջ��С 
TaskHandle_t APPTask_Handler; 	//������
void app_task(void *pvParameters);	//������

// LED������
#define LED0_TASK_PRIO		2
#define LED0_STK_SIZE 		50  
TaskHandle_t LED0Task_Handler;
void led0_task(void *pvParameters);
		 				    
#endif
