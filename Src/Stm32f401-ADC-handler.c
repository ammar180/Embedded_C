#include "Stm32f401-ADC-handler.h"

void ADC_EnableClock(void) {
    RCC->APB2ENR |= (1 << 8); // Enable ADC1 clock
}

void ADC_Init(ADC_Channel channel, ADC_SampleTime sampleTime) {
    ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC
    if (channel < ADC_CHANNEL_10) {
        ADC1->SMPR2 |= (sampleTime << (channel * 3)); // Set sampling time for channels 0-9
    } else {
        ADC1->SMPR1 |= (sampleTime << ((channel - ADC_CHANNEL_10) * 3)); // Set sampling time for channels 10-18
    }
    ADC1->SQR3 = channel; // Set the channel as the first conversion in regular sequence
}

uint32_t ADC_Read(void) {
    ADC1->CR2 |= ADC_CR2_SWSTART; // Start conversion
    while (!(ADC1->SR & ADC_SR_EOC)); // Wait for conversion to complete
    return ADC1->DR; // Read ADC value
}

float ConvertToTemperature(uint32_t adcValue) {
    // Convert ADC value to temperature (refer to the reference manual for the formula)
    float temperature = ((adcValue * 3.3 / 4096) - 0.76) / 0.0025 + 25;
    return temperature;
}