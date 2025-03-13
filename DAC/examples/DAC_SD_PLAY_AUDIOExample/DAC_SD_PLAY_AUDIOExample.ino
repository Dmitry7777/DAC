#include <TDA1543A.h>
#include <SD.h>
#include <SPI.h>

// Define DAC pins
const int DAC_BCK = 3;   // Bit Clock pin
const int DAC_WS = 4;    // Word Select pin
const int DAC_DATA = 5;  // Data pin

// Create a TDA1543A object
TDA1543A dac(DAC_BCK, DAC_WS, DAC_DATA);

// SD card setup
const int chipSelect = 10;  // Pin for CS of the SD card module

void setup() {
  Serial.begin(9600);

  // Initialize the DAC
  dac.begin();

  // Initialize the SD card
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    while (1);
  }

  Serial.println("SD card initialized.");
}

void loop() {
  File audioFile = SD.open("audio.raw");
  
  if (audioFile) {
    int16_t buffer[512];  // Buffer to store audio samples

    while (audioFile.available()) {
      audioFile.read(buffer, sizeof(buffer));

      // Play the buffer
      dac.playAudioBuffer(buffer, sizeof(buffer) / sizeof(buffer[0]));
    }
    
    audioFile.close();
  } else {
    Serial.println("Error opening audio file.");
  }

  delay(1000);  // Wait for 1 second before replaying
}