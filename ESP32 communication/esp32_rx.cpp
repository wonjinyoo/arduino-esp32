#define RX_PIN 15

unsigned long highTime, lowTime, period;
float frequency;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Measure the HIGH time
  highTime = pulseIn(RX_PIN, HIGH);
  
  // Measure the LOW time
  lowTime = pulseIn(RX_PIN, LOW);
  
  // Calculate the full period (HIGH time + LOW time)
  period = highTime + lowTime;

  // If we successfully measured the period
  if (period > 0) {
    // Calculate the frequency in Hz (1,000,000 microseconds per second)
    frequency = int(1000000 / period);

    // Print the frequency
    Serial.print("Frequency: ");
    Serial.print(int(frequency));
    Serial.println(" Hz");
  } else {
    Serial.println("No signal detected.");
  }

  delay(1000); // Wait for 1 second before measuring again
}
