#ifndef STM32f401_ADC_HANDLER_H
#define STM32f401_ADC_HANDLER_H

#include "Stm32f401-adc.h"
#include "Stm32f401-gpio.h"

void ADC_EnableClock(void);

void ADC_Init(ADC_Channel channel, ADC_SampleTime sampleTime);

uint32_t ADC_Read(void);

float ConvertToTemperature(uint32_t adcValue);

#endif /* STM32f401_ADC_HANDLER_H */