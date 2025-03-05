#ifndef STM32f401_ADC_HANDLER_H
#define STM32f401_ADC_HANDLER_H

#include <stdint.h>
#include "Stm32f401-adc.h"
#include "Stm32f401-gpio.h"

void ADC_EnableClock(void);

void ADC_Init(ADC_Channel channel, ADC_SampleTime sampleTime, ADC_CR1_Bits resolution);

uint32_t ADC_Read(void);

int ConvertToTemperature(uint32_t adcValue, ADC_CR1_Bits resolution);

#endif /* STM32f401_ADC_HANDLER_H */
