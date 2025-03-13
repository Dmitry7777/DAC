#ifndef TDA1543A_H
#define TDA1543A_H

#include <Arduino.h>

class TDA1543A {
public:
    // Constructor for TDA1543A DAC with the BCK, WS, and DATA pins
    TDA1543A(uint8_t DAC_BCK, uint8_t DAC_WS, uint8_t DAC_DATA);

    // Initialize the DAC
    void begin();

    // Send a single sample (16-bit) to the DAC
    void sendSample(int16_t leftChannel, int16_t rightChannel);

    // Play audio buffer
    void playAudioBuffer(int16_t* buffer, size_t length);

private:
    uint8_t _DAC_BCK;   // Bit Clock pin
    uint8_t _DAC_WS;    // Word Select pin (L/R Clock)
    uint8_t _DAC_DATA;  // Data pin for audio data

    // Send a 16-bit word to the DAC (I2S format)
    void sendWord(int16_t word);
};

#endif