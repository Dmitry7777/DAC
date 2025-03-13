#include <PCF8591.h>

// Set up the I2C address for the PCF8591 (usually 0x48, but check your device)
const uint8_t PCF8591_ADDRESS = 0x48;

// Create a PCF8591 object
PCF8591 dac(PCF8591_ADDRESS);

void setup() {
    Serial.begin(9600);
    dac.begin();
}

void loop() {
    // Read analog values from channels 0, 1, 2, and 3
    uint8_t adcValue0 = dac.readADC(0);
    uint8_t adcValue1 = dac.readADC(1);
    uint8_t adcValue2 = dac.readADC(2);
    uint8_t adcValue3 = dac.readADC(3);

    // Print ADC values to Serial Monitor
    Serial.print("ADC0: "); Serial.print(adcValue0);
    Serial.print(" | ADC1: "); Serial.print(adcValue1);
    Serial.print(" | ADC2: "); Serial.print(adcValue2);
    Serial.print(" | ADC3: "); Serial.println(adcValue3);

    // Write a value to the DAC (outputting an analog voltage)
    dac.writeDAC(adcValue0);  // Mirror ADC0 to DAC output

    delay(500);  // Delay for readability
}