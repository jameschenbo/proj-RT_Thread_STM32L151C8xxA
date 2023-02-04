/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "app_config.h"
#include "rtthread.h"

#ifdef EXA_USING_CREATE_STATIC_THREAD
extern void example_01_create_static_thread(void);
#endif

#ifdef EXA_USING_CREATE_DYNAMIC_THREAD
void example_01_create_dynamic_thread(void);
#endif

#ifdef EXA_USING_CREATE_SUSPEND_THREAD
void example_01_create_threads(void);
#endif
#ifdef EXA_USING_CREATE_QUEUE
void example_02_create_message_queue(void);
#endif
/**
  * @brief  这里是main线程了 
  * @retval int
  */
int main(void)
{
#ifdef EXA_USING_CREATE_STATIC_THREAD
    example_01_create_static_thread();
#endif  
    
#ifdef EXA_USING_CREATE_DYNAMIC_THREAD
    example_01_create_dynamic_thread();
#endif   

#ifdef EXA_USING_CREATE_SUSPEND_THREAD
    example_01_create_threads();
#endif    
    
#ifdef EXA_USING_CREATE_QUEUE
    example_02_create_message_queue();
#endif
}






/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
//void Error_Handler(void)
//{
//  /* USER CODE BEGIN Error_Handler_Debug */
//  /* User can add his own implementation to report the HAL error return state */
//  __disable_irq();
//  while (1)
//  {
//  }
//  /* USER CODE END Error_Handler_Debug */
//}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

