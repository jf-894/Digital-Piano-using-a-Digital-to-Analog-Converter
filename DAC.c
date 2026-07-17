#include "DAC.h"
#include "stm32f0xx_hal_gpio.h"

#define OUT (*((volatile uint32_t *)0x48000814))

const uint8_t wave[32]= {
8,9,11,12,13,14,14,15,15,15,14,
14,13,12,11,9,8,7,5,4,3,2,
2,1,1,1,2,2,3,4,5,7};

void DAC_Init(void){
    __HAL_RCC_GPIOC_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.Pin = GPIO_PIN_0 |GPIO_PIN_1 |GPIO_PIN_2 |GPIO_PIN_3;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStructure.Pull = GPIO_NOPULL;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void DAC_Out(uint8_t index){
OUT = wave[index];
}