/*
* stm32f401-adc.h
*
*  Created on: Mar 3, 2025
*      Author: ammar.ahmed
*/

#ifndef STM32F401_ADC_H_
#define STM32F401_ADC_H_

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
    // Resolution bits
    ADC_CR1_RES_12B = 0x00000000, // 12 bits
    ADC_CR1_RES_10B = 0x100000,    // 10 bits
    ADC_CR1_RES_8B  = 0x200000,    // 8 bits
    ADC_CR1_RES_6B  = 0x300000,     // 6 bits

    ADC_CR1_AWDCH   = 0x1F,     // Bits for Analog Watchdog Channel Selection
    ADC_CR1_EOCIE   = 0x20,     // End of Conversion Interrupt Enable
    ADC_CR1_AWDIE   = 0x40,     // Analog Watchdog Interrupt Enable
    ADC_CR1_JEOCIE  = 0x80,     // Injected Channel End of Conversion Interrupt Enable
    ADC_CR1_SCAN    = 0x100,    // Scan Mode Enable
    ADC_CR1_AWDSGL  = 0x200,    // Enable the Analog Watchdog on a Single Channel
    ADC_CR1_JAUTO   = 0x400,    // Automatic Injected Group Conversion
    ADC_CR1_DISCEN  = 0x800,    // Discontinuous Mode Enable
    ADC_CR1_JDISCEN = 0x1000,   // Discontinuous Mode for Injected Channels Enable
    ADC_CR1_DISCNUM = 0xE000,   // Discontinuous Mode Channel Count
    ADC_CR1_JAWDEN  = 0x40000,  // Injected Channel Analog Watchdog Enable
    ADC_CR1_AWDEN   = 0x80000,  // Analog Watchdog Enable
    ADC_CR1_OVRIE   = 0x400000  // Overrun Interrupt Enable
} ADC_CR1_Bits;

// ADC_CR2 register bit definitions
typedef enum {
    ADC_CR2_ADON      = (1 << 0),       // Bit 0: ADC ON/OFF
    ADC_CR2_CONT      = (1 << 1),       // Bit 1: Continuous Conversion Mode
    ADC_CR2_DMA       = (1 << 2),       // Bit 2: DMA Mode
    ADC_CR2_DDS       = (1 << 8),       // Bit 8: DMA Disable Selection
    ADC_CR2_EOCS      = (1 << 9),       // Bit 9: End of Conversion Selection
    ADC_CR2_ALIGN     = (1 << 10),      // Bit 10: Data Alignment
    ADC_CR2_JEXTSEL   = (0xF << 12),    // Bits 12-15: Injected External Trigger Selection
    ADC_CR2_JEXTEN    = (0x3 << 16),    // Bits 16-17: Injected External Trigger Enable
    ADC_CR2_JSWSTART  = (1 << 18),      // Bit 18: Start Conversion for Injected Group
    ADC_CR2_EXTSEL    = (0xF << 20),    // Bits 20-23: External Trigger Selection
    ADC_CR2_EXTEN     = (0x3 << 24),    // Bits 24-25: External Trigger Enable
    ADC_CR2_SWSTART   = (1 << 30)       // Bit 30: Start Conversion for Regular Group
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

#endif /* STM32F401_ADC_H_ */
