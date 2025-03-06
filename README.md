# Project Context and Purpose

This document provides an overview of the context and purpose of the code in this project, which is designed for an STM32 microcontroller. The project involves configuring and using GPIO and ADC peripherals to read temperature data and control various outputs based on the temperature.

## Table of Contents
1. [Introduction](#introduction)
2. [GPIO Configuration](#gpio-configuration)
3. [ADC Configuration](#adc-configuration)
4. [Main Application Logic](#main-application-logic)
5. [File Descriptions](#file-descriptions)

## Introduction
The project is designed to read temperature data from an LM35 temperature sensor using the ADC peripheral of an STM32 microcontroller. Based on the temperature readings, the project controls LEDs, a fan, and a buzzer to indicate different temperature ranges and alert conditions.

## Key Steps to Make This Project

1. **Define Base Addresses and Structs**:
    - Define the base addresses for the GPIO and ADC peripherals.
    - Create structs to represent the registers of these peripherals.

2. **GPIO Configuration**:
    - Enable the clock for the GPIO port.
    - Initialize the GPIO pins for the temperature sensor, LEDs, button, buzzer, and fan.
    - Configure the pins as input or output as required.

3. **ADC Configuration**:
    - Enable the clock for the ADC peripheral.
    - Initialize the ADC to read from the temperature sensor pin.
    - Configure the ADC channel, sample time, and resolution.

4. **Main Application Logic**:
    - In the `main` function, set up an infinite loop to continuously read the temperature data from the ADC.
    - Convert the ADC value to a temperature reading.
    - Control the LEDs, fan, and buzzer based on the temperature ranges.
    - Handle button presses to toggle temperature units and reset the system.

5. **Utility Functions**:
    - Implement utility functions such as `delay`, `ConvertCelsiusToFahrenheit`, and `ConvertToTemperature`.

6. **Build and Export**:
    - Configure the build system (e.g., Makefile) to compile the project.
    - Export the compiled `.hex` file to the desired directory.

By following these steps, you can create a project that reads temperature data from an LM35 sensor using an STM32 microcontroller and controls various outputs based on the temperature readings.

## GPIO Configuration
GPIO (General Purpose Input/Output) pins are configured for various purposes:
- **Temperature Sensor Pin**: Configured as an analog input to read temperature data.
- **LED Pins**: Configured as outputs to indicate different temperature ranges.
- **Button Pin**: Configured as an input to toggle temperature units and reset the system.
- **Buzzer Pin**: Configured as an output to alert critical temperature conditions.
- **Fan Pin**: Configured as an output to control a fan based on temperature.

### Example: GPIO Configuration
```c

#include "Stm32f401-gpio.h"

void GPIO_EnableClock(GPIO *pGPIOx){
    // ...existing code...
}

void GPIO_Init(GPIO *pGPIOx , int pinNumber , GPIO_Mode mode , GPIO_Speed speed , GPIO_OutputType outputType , GPIO_PullType pull){
    // ...existing code...
}

void GPIO_WriteOutputPin(GPIO *pGPIOx , int pinNumber , int value ){
    // ...existing code...
}

void GPIO_TogglePin(GPIO *pGPIOx, int pinNumber){
    // ...existing code...
}

int GPIO_ReadInputPin(GPIO *pGPIOx, int pinNumber){
    // ...existing code...
}
```

## ADC Configuration
The ADC (Analog-to-Digital Converter) is used to read the analog voltage from the temperature sensor and convert it to a digital value. This digital value is then used to calculate the temperature.

### Example: ADC Configuration
```c

#include "Stm32f401-ADC-handler.h"

void ADC_EnableClock(void) {
    // ...existing code...
}

void ADC_Init(ADC_Channel channel, ADC_SampleTime sampleTime, ADC_CR1_Bits resolution) {
    // ...existing code...
}

uint32_t ADC_Read(void) {
    // ...existing code...
}

int ConvertToTemperature(uint32_t adcValue, ADC_CR1_Bits resolution) {
    // ...existing code...
}
```

## Main Application Logic
The main application reads the temperature data from the ADC and controls the LEDs, fan, and buzzer based on the temperature ranges. It also handles button presses to toggle temperature units and reset the system.

### Example: Main Application
```c

#include <stdint.h>
#include "Stm32f401-gpio.h"
#include "Stm32f401-ADC-handler.h"

typedef enum {
    TEMP_SENSOR_PIN,
    RED_LED_PIN,
    GREEN_LED_PIN,
    YELLOW_LED_PIN,
    BUTTON_PIN,
    BUZZER_PIN,
    FAN_PIN,
} PinNumber;

void delay(volatile uint32_t time) {
    // ...existing code...
}

int ConvertCelsiusToFahrenheit(int temperature) {
    // ...existing code...
}

int main(void) {
    // ...existing code...
}
```

## File Descriptions
- **Stm32f401-gpio.c**: Contains functions to configure and control GPIO pins.
- **Stm32f401-ADC-handler.c**: Contains functions to configure and read from the ADC.
- **main.c**: Contains the main application logic that ties together the GPIO and ADC configurations.

## Conclusion
This project demonstrates how to configure and use GPIO and ADC peripherals on an STM32 microcontroller to read temperature data and control various outputs based on the temperature. The provided code serves as a foundation for more complex embedded applications.
