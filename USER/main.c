
#include "main.h"

static void BSP_Init(void)
{
	/*
	 * STM32�ж����ȼ�����Ϊ4����4bit��������ʾ��ռ���ȼ�����ΧΪ��0~15
	 * ���ȼ�����ֻ��Ҫ����һ�μ��ɣ��Ժ������������������Ҫ�õ��жϣ�
	 * ��ͳһ��������ȼ�����
	 */
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );
	
	/* ��ʱ������ʼ�� */
	delay_init();
	
	/* ���ڳ�ʼ��	*/
	uart_init(115200);
	
	/* LED��ʼ�� */
	LED_GPIO_Config();
	Usart2_Init(115200);
	ESP8266_Init();

}

int main(void)
{	 	 
	 BSP_Init();
	//������ʼ����
    xTaskCreate((TaskFunction_t )app_task,            //������
                (const char*    )"app_task",          //��������
                (uint16_t       )APP_STK_SIZE,        //�����ջ��С
                (void*          )NULL,                  //���ݸ��������Ĳ���
                (UBaseType_t    )APP_TASK_PRIO,       //�������ȼ�
                (TaskHandle_t*  )&APPTask_Handler);   //������              
    vTaskStartScheduler();          //�����������
}

//��ʼӦ��������
void app_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //�����ٽ���
    //����LED0����
    xTaskCreate((TaskFunction_t )led0_task,     	
                (const char*    )"led0_task",   	
                (uint16_t       )LED0_STK_SIZE, 
                (void*          )NULL,				
                (UBaseType_t    )LED0_TASK_PRIO,	
                (TaskHandle_t*  )&LED0Task_Handler);
				
    vTaskDelete(APPTask_Handler); //ɾ����ʼ����
    taskEXIT_CRITICAL();            //�˳��ٽ���
}

//LED0������ 
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

