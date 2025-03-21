#include <Arduino.h>

#define TX_LED_PIN 2   // Onboard LED pin on ESP32
#define TX_PIN 15      // Pin to send PWM signal

void setup() {
  // Set up PWM signal on the TX_PIN
  ledcSetup(0, 100, 8); // PWM channel 0, 1kHz frequency, 8-bit resolution
  ledcAttachPin(TX_PIN, 0); // Attach the pin to the PWM channel

  // Start with the PWM signal set at 50% duty cycle
  ledcWrite(0, 128); // 50% duty cycle for 8-bit resolution

  // Set the TX LED as output
  pinMode(TX_LED_PIN, OUTPUT);
  digitalWrite(TX_LED_PIN, LOW); // Initially off
}

void loop() {
  // Send the PWM signal continuously with 50% duty cycle
  // Turn on the TX LED to indicate the signal is being sent
  digitalWrite(TX_LED_PIN, HIGH);

  // Add delay to maintain the signal and LED status
  delay(1000);

  // Turn off the TX LED to indicate the signal has been sent
  digitalWrite(TX_LED_PIN, LOW);

  // Wait before sending again
  delay(500);
}
