#include <PCF8591.h>

const uint8_t PCF8591_ADDRESS = 0x48;
PCF8591 dac(PCF8591_ADDRESS);

void setup() {
    Serial.begin(9600);
    dac.begin();
}

void loop() {
    // Read analog values from channels 0 and 1
    uint8_t leftChannel = dac.readADC(0);
    uint8_t rightChannel = dac.readADC(1);

    // Output to DAC with alternating values for a stereo-like effect
    dac.writeDAC(leftChannel);
    delay(10);  // Small delay for "left" channel

    dac.writeDAC(rightChannel);
    delay(10);  // Small delay for "right" channel
}