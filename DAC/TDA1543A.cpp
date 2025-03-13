#include "TDA1543A.h"

// Constructor for TDA1543A DAC
TDA1543A::TDA1543A(uint8_t DAC_BCK, uint8_t DAC_WS, uint8_t DAC_DATA) {
    _DAC_BCK = DAC_BCK;
    _DAC_WS = DAC_WS;
    _DAC_DATA = DAC_DATA;
}

// Initialize the DAC pins
void TDA1543A::begin() {
    pinMode(_DAC_BCK, OUTPUT);
    pinMode(_DAC_WS, OUTPUT);
    pinMode(_DAC_DATA, OUTPUT);

    // Set the initial states
    digitalWrite(_DAC_BCK, LOW);
    digitalWrite(_DAC_WS, LOW);
    digitalWrite(_DAC_DATA, LOW);
}

// Send a 16-bit stereo sample (left and right channels) to the DAC
void TDA1543A::sendSample(int16_t leftChannel, int16_t rightChannel) {
    // Left channel first (I2S format)
    sendWord(leftChannel);
    
    // Switch the Word Select signal to indicate the right channel
    digitalWrite(_DAC_WS, HIGH);

    // Right channel next
    sendWord(rightChannel);
    
    // Switch the Word Select back to low for the next left channel
    digitalWrite(_DAC_WS, LOW);
}

// Send a 16-bit word to the DAC (I2S format)
void TDA1543A::sendWord(int16_t word) {
    for (int i = 15; i >= 0; i--) {
        digitalWrite(_DAC_BCK, LOW);
        
        // Send the most significant bit first
        digitalWrite(_DAC_DATA, (word & (1 << i)) ? HIGH : LOW);
        
        // Clock the bit into the DAC
        digitalWrite(_DAC_BCK, HIGH);
    }
}

// Play an audio buffer (array of samples)
void TDA1543A::playAudioBuffer(int16_t* buffer, size_t length) {
    for (size_t i = 0; i < length; i += 2) {
        // Send left and right samples (assumes interleaved stereo samples)
        sendSample(buffer[i], buffer[i + 1]);
    }
}