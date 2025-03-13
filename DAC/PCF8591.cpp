#include "PCF8591.h"

// Constructor: set the I2C address for PCF8591
PCF8591::PCF8591(uint8_t address) {
    _address = address;
}

// Initialize I2C communication
void PCF8591::begin() {
    Wire.begin();  // Start I2C communication
}

// Read from an ADC channel (0-3)
uint8_t PCF8591::readADC(uint8_t channel) {
    selectChannel(channel);  // Select the channel

    // Request a single byte from the PCF8591
    Wire.requestFrom(_address, (uint8_t)2);

    // The first byte is a dummy read, so we discard it
    Wire.read();
    // The second byte is the actual ADC reading
    uint8_t result = Wire.read();
    
    return result;
}

// Write a value to the DAC
void PCF8591::writeDAC(uint8_t value) {
    Wire.beginTransmission(_address);
    Wire.write(0x40);     // Control byte to enable DAC
    Wire.write(value);    // Write DAC value
    Wire.endTransmission();
}

// Select the ADC channel (0-3)
void PCF8591::selectChannel(uint8_t channel) {
    if (channel > 3) channel = 3;  // Clamp channel to 0-3 range

    Wire.beginTransmission(_address);
    Wire.write(channel);   // Set control byte to select channel
    Wire.endTransmission();
}