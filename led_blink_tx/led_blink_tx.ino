#include <SPI.h>
#include <RF24.h>
#include <HCSR04.h>

#define level_1 10.0
#define level_2 15.0

#define LEBEL_1 "FULL"
#define LEBEL_2 "MEDIUM"
#define LEBEL_3 "LOW"

HCSR04 hc(2, 3); //initialisation class HCSR04 (trig pin , echo pin)

char msg[15] = {0};

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  float distance = hc.dist();
  memset(msg, 0, sizeof(msg));
  if (distance <= level_1)
  {
    strcpy(msg, LEBEL_1);
  }
  else if ((distance > level_1) && (distance <= level_2))
  {
    strcpy(msg, LEBEL_2);
  }
  else
  {
    strcpy(msg, LEBEL_3);
  }
  bool success = radio.write(&msg, strlen(msg));
  if (success) {
    Serial.print("Send dist: ");
    Serial.println(distance); // return curent distance in serial
  } else {
    Serial.println("Failed to send");
  }
  delay(500); // send every 100 ms
}
