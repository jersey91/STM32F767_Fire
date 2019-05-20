#ifndef __BSP_LED_H
#define	__BSP_LED_H

#include "stm32f7xx_hal.h"

/*
硬件介绍
DS0-LED0-PB1
DS1-LED1-PB0
*/

/*******************************************************/
#define LED0_PIN                  GPIO_PIN_1              
#define LED0_GPIO_PORT            GPIOB                     
#define LED0_GPIO_CLK_ENABLE()    __GPIOB_CLK_ENABLE()


#define LED1_PIN                  GPIO_PIN_0               
#define LED1_GPIO_PORT            GPIOB                     
#define LED1_GPIO_CLK_ENABLE()    __GPIOB_CLK_ENABLE()
/************************************************************/


#define ON  GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

#define LED0(a)	HAL_GPIO_WritePin(LED0_GPIO_PORT,LED0_PIN,a)
#define LED1(a)	HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_PIN,a)


#define	digitalHi(p,i)			{p->BSRR=i;}				
#define digitalLo(p,i)			{p->BSRR=(uint32_t)i << 16;}			
#define digitalToggle(p,i)		{p->ODR ^=i;}			

#define LED0_TOGGLE		digitalToggle(LED0_GPIO_PORT,LED0_PIN)
#define LED0_OFF		digitalHi(LED0_GPIO_PORT,LED0_PIN)
#define LED0_ON			digitalLo(LED0_GPIO_PORT,LED0_PIN)

#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED1_OFF		digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED1_ON			digitalLo(LED1_GPIO_PORT,LED1_PIN)


void LED_GPIO_Config(void);

#endif /* __BSP_LED_H */
