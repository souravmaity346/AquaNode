#include <SPI.h>
#include <RF24.h>

#define LEBEL_1 "FULL"
#define LEBEL_2 "MEDIUM"
#define LEBEL_3 "LOW"

RF24 radio(4, 5);  // CE, CSN
const byte address[6] = "00001";

const int ledPin = 2;
const int externalLED1 = 14;  // LOW
const int externalLED2 = 12;  // MEDIUM
const int externalLED3 = 13;  // FULL
const int pumpPin = 15;       // Water Pump control pin

unsigned long lastReceivedTime = 0;
const unsigned long timeout = 1000;

void setup() {
  Serial.begin(115200);

  pinMode(externalLED1, OUTPUT);
  pinMode(externalLED2, OUTPUT);
  pinMode(externalLED3, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pumpPin, OUTPUT);
  
  digitalWrite(ledPin, LOW);
  digitalWrite(pumpPin, LOW);  // Pump OFF initially

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() {
  unsigned long currentTime = millis();

  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.print("Received: ");
    Serial.println(text);  // Print received message
    lastReceivedTime = currentTime;

    if (strcmp(text, LEBEL_1) == 0) {
      // FULL
      digitalWrite(externalLED3, HIGH);
      digitalWrite(pumpPin, LOW);  // Turn OFF pump
      delay(500);
      digitalWrite(externalLED3, LOW);
      delay(500);

    } else if (strcmp(text, LEBEL_2) == 0) {
      // MEDIUM
      digitalWrite(externalLED2, HIGH);
      delay(500);
      digitalWrite(externalLED2, LOW);
      delay(500);

    } else if (strcmp(text, LEBEL_3) == 0) {
      // LOW
      digitalWrite(externalLED1, HIGH);
      digitalWrite(pumpPin, HIGH);  // Turn ON pump
      delay(500);
      digitalWrite(externalLED1, LOW);
      delay(100);
    }
  }

  // Indicator LED for signal activity
  if (currentTime - lastReceivedTime < timeout) {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
