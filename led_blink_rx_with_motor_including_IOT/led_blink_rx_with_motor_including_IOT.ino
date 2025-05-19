#include <SPI.h>
#include <RF24.h>
#include <WiFi.h>
#include <WebServer.h>

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

String tankStatus = "Unknown";

// Wi-Fi credentials (Update with your mobile hotspot credentials)
const char* ssid = "A23";
const char* password = "87654321";

WebServer server(80);

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

  // Connect to Mobile Hotspot
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Setup web server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  server.handleClient();
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
      tankStatus = "FULL";
      delay(500);
      digitalWrite(externalLED3, LOW);
      delay(500);

    } else if (strcmp(text, LEBEL_2) == 0) {
      // MEDIUM
      digitalWrite(externalLED2, HIGH);
      tankStatus = "MEDIUM";
      delay(500);
      digitalWrite(externalLED2, LOW);
      delay(500);

    } else if (strcmp(text, LEBEL_3) == 0) {
      // LOW
      digitalWrite(externalLED1, HIGH);
      digitalWrite(pumpPin, HIGH);  // Turn ON pump
      tankStatus = "LOW";
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

void handleRoot() {
  String html = "<html><head><title>Water Tank Status</title><style>";
  html += "body {font-family: Arial, sans-serif; background: linear-gradient(135deg, #007BFF 30%, #00d2ff 100%); color: #fff; text-align: center; margin: 0; padding: 20px;}";
  html += "h1 {font-size: 3em; margin-bottom: 20px; text-shadow: 2px 2px 10px rgba(0,0,0,0.4);}";
  html += ".status {font-size: 1.5em; margin: 20px auto; width: 90%; max-width: 400px; padding: 20px; border-radius: 20px; background-color: #ffffffdd; color: #333; box-shadow: 0 8px 30px rgba(0,0,0,0.5); transition: transform 0.3s, box-shadow 0.3s;}";
  html += ".status:hover {transform: scale(1.05); box-shadow: 0 12px 40px rgba(0,0,0,0.6);}";
  html += ".full {background-color: #28a745dd; color: #fff;}";
  html += ".medium {background-color: #ffc107dd; color: #fff;}";
  html += ".low {background-color: #dc3545dd; color: #fff;}";
  html += ".unknown {background-color: #6c757ddd; color: #fff;}";
  html += "footer {margin-top: 40px; font-size: 0.9em; color: #ddd; text-shadow: 1px 1px 5px rgba(0,0,0,0.5);}";
  html += "</style></head><body>";

  html += "<h1>Water Tank Status</h1>";

  if (tankStatus == "FULL") {
    html += "<div class='status full'>Tank is FULL. Pump is OFF.</div>";
  } else if (tankStatus == "MEDIUM") {
    html += "<div class='status medium'>Tank is MEDIUM. Pump is running intermittently.</div>";
  } else if (tankStatus == "LOW") {
    html += "<div class='status low'>Tank is LOW. Pump is ON.</div>";
  } else {
    html += "<div class='status unknown'>Status Unknown.</div>";
  }

  html += "<footer>Powered by ESP32 | IoT Water Monitoring System</footer>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}
