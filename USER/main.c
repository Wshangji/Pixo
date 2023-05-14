
#include "main.h"

static void BSP_Init(void)
{
	/*
	 * STM32中断优先级分组为4，即4bit都用来表示抢占优先级，范围为：0~15
	 * 优先级分组只需要分组一次即可，以后如果有其他的任务需要用到中断，
	 * 都统一用这个优先级分组
	 */
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	
	/* 延时函数初始化 */
	delay_init();
	
	/* 串口初始化	*/
	uart_init(115200);
	
	/* LED初始化 */
	LED_GPIO_Config();
	Usart2_Init(115200);
	ESP8266_Init();

}

int main(void)
{	 	 
	 BSP_Init();
	//创建开始任务
    xTaskCreate((TaskFunction_t )app_task,            //任务函数
                (const char*    )"app_task",          //任务名称
                (uint16_t       )APP_STK_SIZE,        //任务堆栈大小
                (void*          )NULL,                  //传递给任务函数的参数
                (UBaseType_t    )APP_TASK_PRIO,       //任务优先级
                (TaskHandle_t*  )&APPTask_Handler);   //任务句柄              
    vTaskStartScheduler();          //开启任务调度
}

//开始应用任务函数
void app_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //进入临界区
    //创建LED0任务
    xTaskCreate((TaskFunction_t )led0_task,     	
                (const char*    )"led0_task",   	
                (uint16_t       )LED0_STK_SIZE, 
                (void*          )NULL,				
                (UBaseType_t    )LED0_TASK_PRIO,	
                (TaskHandle_t*  )&LED0Task_Handler);
				
    vTaskDelete(APPTask_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
}

//LED0任务函数 
void led0_task(void *pvParameters)
{
    while(1)
    {
        LED1_ON;
        vTaskDelay(500);
        LED1_OFF;
        vTaskDelay(500);
    }
}   

