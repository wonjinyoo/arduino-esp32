#include <Arduino.h>

#define TX_LED_PIN 2 // Onboard LED pin on ESP32 (can change if necessary)
#define RX_PIN 16    // Pin for the RX device (use a GPIO pin for communication)

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Set the LED pin as output
  pinMode(TX_LED_PIN, OUTPUT);

  // Ensure the LED is initially off
  digitalWrite(TX_LED_PIN, LOW);
}

void loop() {
  // Send some data, can be any byte or message you choose
  Serial.println("Signal");

  // Turn on the LED to indicate a signal has been sent
  digitalWrite(TX_LED_PIN, HIGH);

  // Wait for a second to see the effect
  delay(1000);

  // Turn off the LED after a while
  digitalWrite(TX_LED_PIN, LOW);

  // Wait before sending the next signal
  delay(500);
}
