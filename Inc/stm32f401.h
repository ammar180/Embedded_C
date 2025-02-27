/*
 * stm32f401.h
 *
 *  Created on: Feb 23, 2025
 *      Author: ammar.ahmed
 */

#ifndef STM32F401_H_
#define STM32F401_H_


#include <stdint.h>

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

#define RCC_BASEADDRESS 0x40023800



#define GPIOA   ((GPIO*)GPIOA_BASE_ADDRESS)
#define GPIOB   ((GPIO*)GPIOB_BASE_ADDRESS)
#define GPIOC   ((GPIO*)GPIOC_BASE_ADDRESS)

typedef struct
{
	volatile int MODER;
	volatile int OTYPER;
	volatile int OSPEEDER;
	volatile int PUPDR;
	volatile int IDR;
	volatile int ODR;
	/*reset w set f AL ODR*/
	volatile int BSRR;
	volatile int LCKR;
     /*lw alternate*/
	volatile int AFR[2];
}GPIO;




#define RCC ((RCC_RegDef_t*)RCC_BASEADDRESS)
typedef struct
{
	volatile int CR;
	volatile int PLLCFGR;
	volatile int CFGR;
	volatile int CIR;
	volatile int AHB1RSTR;
	volatile int AHB2RSTR;
	volatile int RESERVED0 [2];
	volatile int APB1RSTR;
	volatile int APB2RSTR;
	volatile int RESERVED1 [2];
	volatile int AHB1ENR;
	volatile int AHB2ENR;
	volatile int RESERVED2 [2];
	volatile int APB1ENR;
	volatile int APB2ENR;
}RCC_RegDef_t;


typedef enum {
	INPUT,
	OUTPUT,
	ALTERNATE_FUNCTION,
	ANALOG
} GPIO_Mode;

typedef enum {
	PUSH_PULL,
	OPEN_DRAIN
} GPIO_OutputType;

typedef enum {
	PULL_UP,
	PULL_DOWN,
} GPIO_PullType;

typedef enum {
	LOW_SPEED,
	MEDIUM_SPEED,
	HIGH_SPEED,
	VERY_HIGH_SPEED
} GPIO_Speed;

#endif /* STM32F401_H_ */
