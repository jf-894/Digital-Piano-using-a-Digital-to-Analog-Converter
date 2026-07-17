#include "Piano.h"
#include "stm32f0xx_hal_rcc.h"


void Piano_Init(void){
__HAL_RCC_GPIOB_CLK_ENABLE();
GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.Pin = GPIO_PIN_10| GPIO_PIN_11| GPIO_PIN_12;
    GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
    GPIO_InitStructure.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
}

char Piano_In(){
    /*
PB10 - C Note f = 523Hz 0.00191 seconds
PB11 - B Note f = 494Hz 0.00202 seconds
PB12 - A Note f = 440Hz 0.00227 seconds
None - X Note(No Sound)
*/
  if (HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10) == 1) {
  return 'C';
} else if (HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11) == 1) {
  return 'B';
} else if (HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_12) == 1) {
  return 'A';
} else {
return 'X';
}


}