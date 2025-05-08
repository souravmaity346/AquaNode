# AquaNode – Wireless Water Level Monitoring and Motor Control System
## Abstract

**AquaNode** is an innovative wireless water level monitoring and motor control system designed to automate the process of maintaining optimal water levels in overhead tanks. This project uses an ultrasonic sensor to measure water level and transmits the data wirelessly using NRF24L01 modules. An Arduino Nano serves as the transmitter, while an ESP32 processes data on the receiver side.

The system operates in three modes—Low, Mid, and Full—based on the measured water distance, and controls an RGB LED indicator and a motor using a 2N2222 transistor.

---

## 1. Introduction

Water management is essential in both households and industries. AquaNode helps conserve water and electricity by automating motor operation based on real-time data using RF communication and ultrasonic sensors.

---

## 2. Objective

To design and implement a wireless water tank level monitoring system using:

- Arduino Nano
- ESP32
- NRF24L01 modules
- Ultrasonic sensor (HC-SR04)

### System Goals:
- Monitor water levels continuously.
- Transmit data wirelessly.
- Indicate levels via LEDs.
- Control a motor automatically.

---

## 3. Components Used

### Transmitter Side:
- **Arduino Nano** – Controls the ultrasonic sensor and handles data transmission.  
- **Ultrasonic Sensor (HC-SR04)** – Measures water level.  
- **NRF24L01** – Sends data wirelessly.  
