/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2019-05-20
  ******************************************************************************
  */
  
#include "bsp_led.h"   


void LED_GPIO_Config(void)
{		
    GPIO_InitTypeDef  GPIO_InitStruct;

    LED0_GPIO_CLK_ENABLE();
    LED1_GPIO_CLK_ENABLE();
  													   
    GPIO_InitStruct.Pin = LED1_PIN;	

    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;  

    GPIO_InitStruct.Pull  = GPIO_PULLUP;

    GPIO_InitStruct.Speed = GPIO_SPEED_HIGH; 

    HAL_GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStruct);	

    GPIO_InitStruct.Pin = LED2_PIN;	
    HAL_GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStruct);	

    GPIO_InitStruct.Pin = LED3_PIN;	
    HAL_GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStruct);	

    GPIO_InitStruct.Pin = LED4_PIN;	
    HAL_GPIO_Init(LED4_GPIO_PORT, &GPIO_InitStruct);	

    LED_RGBOFF;

    LED4(ON);
		
}
/*********************************************END OF FILE**********************/
