#include "Stm32f401-ADC-handler.h"

void ADC_EnableClock(void) {
    RCC->APB2ENR |= (1 << 8); // Enable ADC1 clock
}

void ADC_Init(ADC_Channel channel, ADC_SampleTime sampleTime, ADC_CR1_Bits resolution) {
    ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC
    for (volatile int i = 0; i < 1000; i++); // Short delay
    ADC1->CR1 |= resolution;   // Set resolution to 12 bits
    if (channel < ADC_CHANNEL_10) {
        ADC1->SMPR2 |= (sampleTime << (channel * 3)); // Set sampling time for channels 0-9
    } else {
        ADC1->SMPR1 |= (sampleTime << ((channel - ADC_CHANNEL_10) * 3)); // Set sampling time for channels 10-18
    }
    ADC1->SQR3 = channel; // Set the channel as the first conversion in regular sequence
}

uint32_t ADC_Read(void) {
    ADC1->CR2 |= (1 << 30); // Start conversion
    while (!(ADC1->SR &  ADC_SR_EOC)); // Wait for conversion to complete
    return ADC1->DR; // Read ADC value from data register
}
int ConvertToTemperature(uint32_t adcValue, ADC_CR1_Bits resolution) {
    // Calculate the number of bits for the resolution
    int bits;

    // Determine the number of bits based on the resolution parameter
    switch (resolution) {
        case ADC_CR1_RES_12B:
            bits = 12;
            break;
        case ADC_CR1_RES_10B:
            bits = 10;
            break;
        case ADC_CR1_RES_8B:
            bits = 8;
            break;
        case ADC_CR1_RES_6B:
            bits = 6;
            break;
        default:
            bits = 12; // Default to 12-bit resolution
            break;
    }

    // Convert ADC value to temperature in Celsius
    int temperature = (adcValue * 3.3 / (1 << bits)) / 0.01; // Modify as per sensor specifics

    return temperature;
}
