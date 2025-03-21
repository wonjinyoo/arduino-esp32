#include <Arduino.h>

#define RX_SIGNAL_PIN 15  // Pin to receive the PWM signal from TX ESP32
#define NEXTION_TX_PIN 17  // Define pin for Nextion TX (connected to RX2 of ESP32)
#define NEXTION_RX_PIN 16  // Define pin for Nextion RX (connected to TX2 of ESP32)

unsigned long highTime, lowTime, period;
float frequency;
const int pin = RX_SIGNAL_PIN;

void setup() {
  Serial.begin(9600);          // Serial to PC for debugging
  Serial2.begin(9600, SERIAL_8N1, NEXTION_RX_PIN, NEXTION_TX_PIN);  // Serial2 for Nextion communication
  pinMode(pin, INPUT);
}

void loop() {
  // Measure the HIGH time of the signal
  highTime = pulseIn(pin, HIGH);
  
  // Measure the LOW time of the signal
  lowTime = pulseIn(pin, LOW);
  
  // Calculate the total period (HIGH time + LOW time)
  period = highTime + lowTime;
  
  if (period > 0) {
    // Calculate frequency as 1/period, converted from microseconds to Hz
    frequency = int(1000000.0 / period);

    // Print the frequency to the Serial Monitor
    Serial.print("Frequency: ");
    Serial.print(int(frequency));
    Serial.println(" Hz");
    
    // Send the frequency data to Nextion screen
    // Update Text Box t0 with the new frequency value
    Serial2.print("t0.txt=\""); // Start the text update command for t0
    Serial2.print(int(frequency));   // Send the frequency value
    Serial2.print("\"");        // Close the string
    Serial2.write(0xFF);        // Send the end of command sequence
    Serial2.write(0xFF);
    Serial2.write(0xFF);
  } else {
    // If no pulse detected, show an error message on the Nextion screen
    Serial2.print("t0.txt=\"No Signal\""); 
    Serial2.write(0xFF);
    Serial2.write(0xFF);
    Serial2.write(0xFF);
  }

  delay(1000); // Wait for 1 second before measuring again
}
