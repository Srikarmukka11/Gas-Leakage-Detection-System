#include <LiquidCrystal.h>

// Pin connections
const int gasSensorPin = A0;      // MQ-135 connected to analog pin A0
const int buzzerPin = 8;          // Buzzer connected to digital pin 8
const int threshold = 300;        // Gas level threshold (adjust as needed)

// LCD pin setup: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.begin(16, 2); // Initialize 16x2 LCD
  lcd.print("Gas Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  int gasLevel = analogRead(gasSensorPin);
  
  lcd.setCursor(0, 0);
  lcd.print("Gas Level: ");
  lcd.print(gasLevel);

  if (gasLevel > threshold) {
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("!! GAS LEAKAGE !!");
  } else {
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: Safe     ");
  }

  delay(1000); // Wait for a second
}
