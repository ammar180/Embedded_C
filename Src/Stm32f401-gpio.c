/*
 * Stm32f401-gpio.c
 *
 *  Created on: Feb 26, 2025
 *      Author: ammar.ahmed
 */

#include "Stm32f401-gpio.h"

void GPIO_EnableClock(GPIO *pGPIOx){
	if(pGPIOx == GPIOA){
		RCC->AHB1ENR |=(1<<0);
	}else if(pGPIOx == GPIOB){
		RCC->AHB1ENR |=(1<<1);
	}else if(pGPIOx == GPIOC){
		RCC->AHB1ENR |=(1<<2);
	}
}

void GPIO_Init(GPIO *pGPIOx , int pinNumber , GPIO_Mode mode , GPIO_Speed speed , GPIO_OutputType outputType , GPIO_PullType pull){
	pGPIOx->MODER &= ~(0x3 << (pinNumber * 2));
	pGPIOx->MODER |= (mode << (pinNumber * 2));

	pGPIOx->OSPEEDER &= ~(0x3 << (pinNumber * 2));
	pGPIOx->OSPEEDER |= (speed << (pinNumber * 2));

	pGPIOx->OTYPER &= ~(0x1 << (pinNumber));
	pGPIOx->OTYPER |= (outputType << (pinNumber));

	pGPIOx->PUPDR &= ~(0x3 << (pinNumber * 2));
	pGPIOx->PUPDR |= (pull << (pinNumber * 2));
}

void GPIO_WriteOutputPin(GPIO *pGPIOx , int pinNumber , int value ){
	if(value == 1){
		pGPIOx->ODR |= (1 << pinNumber);
	}else if (value == 0){
		pGPIOx->ODR &= ~(1 << pinNumber); 
	}
}

void GPIO_TogglePin(GPIO *pGPIOx, int pinNumber){
	pGPIOx->ODR ^= (1 << pinNumber);
}

int GPIO_ReadInputPin(GPIO *pGPIOx, int pinNumber){
	return ((pGPIOx->IDR >> pinNumber) & 0x1);
}