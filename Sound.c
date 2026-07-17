#include "Sound.h"
#include "DAC.h"
#include "Piano.h"
#include "stm32_hal_legacy.h"
#include "stm32f051x8.h"
#include "stm32f0xx_hal_tim.h"
#include "main.h"
 TIM_HandleTypeDef htim3;
void Sound_Init(int reload){
    DAC_Init();
    Piano_Init();

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = reload;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  
}

void Sound_Play(char note){ 
  /* 
  PB10 - C Note f = 523Hz 0.00191 seconds 
  PB11 - B Note f = 494Hz 0.00202 seconds 
  PB12 - A Note f = 440Hz 0.00227 seconds 
  None - X Note(No Sound) */
 int reload = 0;
if (note == 'C') 
{  
  reload = 2868;   

} else if (note == 'B') { 
  reload = 3035; 

} else if (note == 'A') { 
  reload = 3408;
  


} else {
   HAL_TIM_Base_Stop_IT(&htim3); 
   return;
  }

  if (reload > 0) {
      __HAL_TIM_SET_AUTORELOAD(&htim3, reload);
     
      if(htim3.State != HAL_TIM_STATE_BUSY) {
          HAL_TIM_Base_Start_IT(&htim3);
      }
  } 

} 
