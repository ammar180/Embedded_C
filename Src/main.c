/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "Stm32f401-gpio.h"
#include "Stm32f401-ADC-handler.h"

void delay(volatile uint32_t time) {
    for(uint32_t i = 0; i < time * 1000; i++);
}

int main(void)
{
    GPIO_EnableClock(GPIOA);
    ADC_EnableClock();

    GPIO_Init(GPIOA, 0, OUTPUT, PUSH_PULL, PULL_DOWN, LOW_SPEED);
    GPIO_Init(GPIOA, 2, OUTPUT, PUSH_PULL, PULL_UP, LOW_SPEED);
    ADC_Init();

    while(1)
    {
        // toggle LED on button press (pull )
        GPIO_WriteOutputPin(GPIOA, 2, GPIO_ReadInputPin(GPIOA, 0));

        // Read temperature sensor value
        uint32_t adcValue = ADC_Read();
        float temperature = ConvertToTemperature(adcValue);

        // Use the temperature value as needed
        // For example, you can print it to a debug console or use it in your application logic

        delay(1000); // Delay for 1 second
    }
}
