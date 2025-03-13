#include <TDA1543A.h>

// Define DAC pins
const int DAC_BCK = 3;   // Bit Clock pin
const int DAC_WS = 4;    // Word Select pin
const int DAC_DATA = 5;  // Data pin

// Create a TDA1543A object
TDA1543A dac(DAC_BCK, DAC_WS, DAC_DATA);

void setup() {
  // Initialize the DAC
  dac.begin();
}

void loop() {
  // Generate a simple waveform (e.g., a 1kHz sine wave)
  int16_t sampleValue = 32767 * sin(2 * PI * 1000 * millis() / 1000.0);

  // Send the same sample to both left and right channels
  dac.sendSample(sampleValue, sampleValue);

  delayMicroseconds(10);  // Control the sample rate
}