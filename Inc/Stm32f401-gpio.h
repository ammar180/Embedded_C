/*
 * Stm32f401-gpio.h
 *
 *  Created on: Feb 26, 2025
 *      Author: ammar.ahmed
 */

#ifndef STM32F401_GPIO_H_
#define STM32F401_GPIO_H_

#include "stm32f401.h"

void GPIO_EnableClock(GPIO *pGPIOx);
void GPIO_Init(GPIO *pGPIOx, int pinNumber, int mode, int speed, int outputType, int pull);
void GPIO_WriteOutputPin(GPIO *pGPIOx, int pinNumber, int value);
void GPIO_TogglePin(GPIO *pGPIOx, int pinNumber);
int GPIO_ReadInputPin(GPIO *pGPIOx, int pinNumber);

#endif /* STM32F401_GPIO_H_ */
