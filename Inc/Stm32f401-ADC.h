/*
* stm32f401-adc.h
*
*  Created on: Mar 3, 2025
*      Author: ammar.ahmed
*/

#ifndef STM32F401-ADC_H_
#define STM32F401-ADC_H_

#include <stdint.h>

#define ADC1_BASE_ADDRESS 0x40012000

typedef struct
{
    volatile int SR;
    volatile int CR1;
    volatile int CR2;
    volatile int SMPR1;
    volatile int SMPR2;
    volatile int JOFR1;
    volatile int JOFR2;
    volatile int JOFR3;
    volatile int JOFR4;
    volatile int HTR;
    volatile int LTR;
    volatile int SQR1;
    volatile int SQR2;
    volatile int SQR3;
    volatile int JSQR;
    volatile int JDR1;
    volatile int JDR2;
    volatile int JDR3;
    volatile int JDR4;
    volatile int DR;
    volatile int RESERVED[28]; // Reserved space to match the memory map
} ADC_RegDef_t;

#define ADC1 ((ADC_RegDef_t*)ADC1_BASE_ADDRESS)

// ADC_SR register bit definitions
typedef enum {
    ADC_SR_AWD = 0x01,
    ADC_SR_EOC = 0x02,
    ADC_SR_JEOC = 0x04,
    ADC_SR_JSTRT = 0x08,
    ADC_SR_STRT = 0x10,
    ADC_SR_OVR = 0x20
} ADC_SR_Bits;

// ADC_CR1 register bit definitions
typedef enum {
    ADC_CR1_AWDCH = 0x1F,
    ADC_CR1_EOCIE = 0x20,
    ADC_CR1_AWDIE = 0x40,
    ADC_CR1_JEOCIE = 0x80,
    ADC_CR1_SCAN = 0x100,
    ADC_CR1_AWDSGL = 0x200,
    ADC_CR1_JAUTO = 0x400,
    ADC_CR1_DISCEN = 0x800,
    ADC_CR1_JDISCEN = 0x1000,
    ADC_CR1_DISCNUM = 0xE000,
    ADC_CR1_JAWDEN = 0x40000,
    ADC_CR1_AWDEN = 0x80000,
    ADC_CR1_RES = 0x300000,
    ADC_CR1_OVRIE = 0x400000
} ADC_CR1_Bits;

// ADC_CR2 register bit definitions
typedef enum {
    ADC_CR2_ADON = 0x01,
    ADC_CR2_CONT = 0x02,
    ADC_CR2_DMA = 0x100,
    ADC_CR2_DDS = 0x200,
    ADC_CR2_EOCS = 0x400,
    ADC_CR2_ALIGN = 0x800,
    ADC_CR2_JEXTSEL = 0xF000,
    ADC_CR2_JEXTEN = 0x30000,
    ADC_CR2_JSWSTART = 0x40000,
    ADC_CR2_EXTSEL = 0xF00000,
    ADC_CR2_EXTEN = 0x3000000,
    ADC_CR2_SWSTART = 0x4000000
} ADC_CR2_Bits;

// ADC_SMPR1 register bit definitions
typedef enum {
    ADC_SMPR1_SMP10 = 0x07,
    ADC_SMPR1_SMP11 = 0x38,
    ADC_SMPR1_SMP12 = 0x1C0,
    ADC_SMPR1_SMP13 = 0xE00,
    ADC_SMPR1_SMP14 = 0x7000,
    ADC_SMPR1_SMP15 = 0x38000,
    ADC_SMPR1_SMP16 = 0x1C0000,
    ADC_SMPR1_SMP17 = 0xE00000,
    ADC_SMPR1_SMP18 = 0x7000000
} ADC_SMPR1_Bits;

// ADC_SMPR2 register bit definitions
typedef enum {
    ADC_SMPR2_SMP0 = 0x07,
    ADC_SMPR2_SMP1 = 0x38,
    ADC_SMPR2_SMP2 = 0x1C0,
    ADC_SMPR2_SMP3 = 0xE00,
    ADC_SMPR2_SMP4 = 0x7000,
    ADC_SMPR2_SMP5 = 0x38000,
    ADC_SMPR2_SMP6 = 0x1C0000,
    ADC_SMPR2_SMP7 = 0xE00000,
    ADC_SMPR2_SMP8 = 0x7000000,
    ADC_SMPR2_SMP9 = 0x38000000
} ADC_SMPR2_Bits;

// ADC_SQR1 register bit definitions
typedef enum {
    ADC_SQR1_L = 0x0F,
    ADC_SQR1_SQ13 = 0x1F0,
    ADC_SQR1_SQ14 = 0x3E00,
    ADC_SQR1_SQ15 = 0x7C000,
    ADC_SQR1_SQ16 = 0xF8000
} ADC_SQR1_Bits;

// ADC_SQR2 register bit definitions
typedef enum {
    ADC_SQR2_SQ7 = 0x1F,
    ADC_SQR2_SQ8 = 0x3E0,
    ADC_SQR2_SQ9 = 0x7C00,
    ADC_SQR2_SQ10 = 0xF8000,
    ADC_SQR2_SQ11 = 0x1F00000,
    ADC_SQR2_SQ12 = 0x3E000000
} ADC_SQR2_Bits;

// ADC_SQR3 register bit definitions
typedef enum {
    ADC_SQR3_SQ1 = 0x1F,
    ADC_SQR3_SQ2 = 0x3E0,
    ADC_SQR3_SQ3 = 0x7C00,
    ADC_SQR3_SQ4 = 0xF8000,
    ADC_SQR3_SQ5 = 0x1F00000,
    ADC_SQR3_SQ6 = 0x3E000000
} ADC_SQR3_Bits;

// ADC_JSQR register bit definitions
typedef enum {
    ADC_JSQR_JSQ1 = 0x1F,
    ADC_JSQR_JSQ2 = 0x3E0,
    ADC_JSQR_JSQ3 = 0x7C00,
    ADC_JSQR_JSQ4 = 0xF8000,
    ADC_JSQR_JL = 0x300000
} ADC_JSQR_Bits;

// ADC channels
typedef enum {
    ADC_CHANNEL_0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7,
    ADC_CHANNEL_8,
    ADC_CHANNEL_9,
    ADC_CHANNEL_10,
    ADC_CHANNEL_11,
    ADC_CHANNEL_12,
    ADC_CHANNEL_13,
    ADC_CHANNEL_14,
    ADC_CHANNEL_15,
    ADC_CHANNEL_16,
    ADC_CHANNEL_17,
    ADC_CHANNEL_18
} ADC_Channel;

// ADC sample times
typedef enum {
    ADC_SAMPLETIME_3CYCLES,
    ADC_SAMPLETIME_15CYCLES,
    ADC_SAMPLETIME_28CYCLES,
    ADC_SAMPLETIME_56CYCLES,
    ADC_SAMPLETIME_84CYCLES,
    ADC_SAMPLETIME_112CYCLES,
    ADC_SAMPLETIME_144CYCLES,
    ADC_SAMPLETIME_480CYCLES
} ADC_SampleTime;

#endif /* STM32F401-ADC_H_ */
