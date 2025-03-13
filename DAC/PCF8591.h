#ifndef PCF8591_H
#define PCF8591_H

#include <Arduino.h>
#include <Wire.h>

class PCF8591 {
public:
    // Constructor for PCF8591 with an I2C address
    PCF8591(uint8_t address);

    // Initialize the PCF8591
    void begin();

    // Read from one of the ADC channels (0-3)
    uint8_t readADC(uint8_t channel);

    // Write a value to the DAC (0-255)
    void writeDAC(uint8_t value);

private:
    uint8_t _address;  // I2C address of the PCF8591

    // Helper function to configure the channel for ADC read
    void selectChannel(uint8_t channel);
};

#endif