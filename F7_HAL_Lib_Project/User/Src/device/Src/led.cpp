#ifdef __cplusplus
    #include "led.h"
#endif


/**
 * LED灯之DS0初始化函数
*/
void DS0_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    /* Enable the GPIO_LED clock */
    DS0_GPIO_CLK_ENABLE();
  
    /* Configure the GPIO_LED pin */
    GPIO_InitStruct.Pin = DS0_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    
    HAL_GPIO_Init(DS0_GPIO_PORT, &GPIO_InitStruct);
    
    /* By default, turn off LED */
    HAL_GPIO_WritePin(DS0_GPIO_PORT, DS0_PIN, GPIO_PIN_SET);   
}

/**
 * LED灯之DS1初始化函数
*/
void DS1_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    
    /* Enable the GPIO_LED clock */
    DS0_GPIO_CLK_ENABLE();
  
    /* Configure the GPIO_LED pin */
    GPIO_InitStruct.Pin = DS0_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    
    HAL_GPIO_Init(DS0_GPIO_PORT, &GPIO_InitStruct);
    
    /* By default, turn off LED */
    HAL_GPIO_WritePin(DS0_GPIO_PORT, DS0_PIN, GPIO_PIN_SET);   
}


/**
 * DS0打开
*/
void DS0_On(void)
{
  HAL_GPIO_WritePin(DS0_GPIO_PORT, DS0_PIN, GPIO_PIN_RESET);
}

/**
 * DS0关闭
*/
void DS0_Off(void)
{
  HAL_GPIO_WritePin(DS0_GPIO_PORT, DS0_PIN, GPIO_PIN_SET);
}


/**
 * DS1打开
*/
void DS1_On(void)
{
  HAL_GPIO_WritePin(DS1_GPIO_PORT, DS1_PIN, GPIO_PIN_RESET);
}
/**
 * DS1关闭
*/
void DS1_Off(void)
{
  HAL_GPIO_WritePin(DS1_GPIO_PORT, DS1_PIN, GPIO_PIN_SET);
}





