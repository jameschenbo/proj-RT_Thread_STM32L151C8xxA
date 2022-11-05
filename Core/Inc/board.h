#ifndef _BOARD_H
#define _BOARD_H

#include "stm32l1xx_hal.h"
#include "bsp_gpio.h"
#include "bsp_usart.h"





#define KEY_Pin GPIO_PIN_14
#define KEY_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_15
#define LED_GPIO_Port GPIOA


#define LED_TOGGLE() HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin)
#define LED_ON() HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_RESET)
#define LED_OFF() HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_SET)

#endif
