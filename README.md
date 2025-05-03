# AquaNode
Wireless Water Level Monitoring and Motor Control System.
# AquaNode – Wireless Water Level Monitoring and Motor Control System

## Abstract

**AquaNode** is an innovative wireless water level monitoring and motor control system designed to automate the process of maintaining optimal water levels in overhead tanks. This project uses an ultrasonic sensor to measure the water level and transmits the data wirelessly using NRF24L01 modules. An Arduino Nano serves as the transmitter controller, while an ESP32 microcontroller processes the data on the receiver side.

The system operates in three modes—Low, Mid, and Full—based on the measured water distance, and accordingly controls an RGB LED indicator and a motor using a 2N2222 transistor. The motor is turned ON when water is low or mid, and automatically turned OFF when the tank reaches full capacity.

AquaNode offers a reliable, efficient, and cost-effective solution to water management by reducing manual intervention, conserving electricity, and preventing water overflow through real-time wireless communication.

---

## 1. Introduction

Water management is essential in households and industries. AquaNode is a wireless water level monitoring and control system that utilizes an ultrasonic sensor and RF communication to maintain the water level in a tank automatically. The system helps conserve water and electricity by automating the motor operation based on real-time water level data.

---

## 2. Objective

To design and implement a wireless water tank level monitoring system using an Arduino Nano, ESP32, NRF24L01 modules, and an ultrasonic sensor. The system should:

- Monitor water levels continuously.
- Transmit water level status wirelessly.
- Indicate levels using LEDs.
- Control a motor based on water levels.

---

## 3. Components Used

### Transmitter Side

- **Arduino Nano** – Controls the ultrasonic sensor and handles data transmission.  
- **Ultrasonic Sensor (HC-SR04)** – Measures water level by distance.  
- **NRF24L01** – Sends water level data wirelessly.  

### Receiver Side

- **ESP32** – Processes received data and controls output.  
- **NRF24L01 (with external antenna)** – Receives data from the transmitter.  
- **RGB LEDs (Red, Yellow, Green)** – Indicate water level status.  
- **2N2222 NPN Transistor** – Acts as a switch for controlling a 12V supply to the motor.  
- **Water Pump/Motor (12V)** – Operates based on water level.  

---

## 4. Working Principle

### Transmitter Operation

- The ultrasonic sensor measures the distance from the sensor to the water surface.
- Based on the measured distance, one of the three water level modes is determined:
  - **Low Level**: Distance > 30 cm → Red LED blinks, motor ON.
  - **Mid Level**: Distance ≤ 20 cm → Yellow LED blinks, motor ON.
  - **Full Level**: Distance ≤ 10 cm → Green LED blinks, motor OFF.
- This status is sent to the receiver via NRF24L01.

### Receiver Operation

- The ESP32 receives the data through NRF24L01.
- Depending on the received status:
  - **Low Level**: Red LED blinks (delay 500 ms), motor turns ON via 2N2222.
  - **Mid Level**: Yellow LED blinks (delay 500 ms), motor remains ON.
  - **Full Level**: Green LED blinks (delay 500 ms), motor turns OFF.
- The 2N2222 transistor controls the external 12V power to the motor, acting as a switch.

---

## 5. System Modes

| Mode        | Condition         | LED Color | LED Blink | Motor Status |
|-------------|-------------------|-----------|-----------|---------------|
| Low Water   | Distance > 30 cm  | Red       | 500 ms    | ON            |
| Mid Water   | Distance ≤ 20 cm  | Yellow    | 500 ms    | ON            |
| Full Water  | Distance ≤ 10 cm  | Green     | 500 ms    | OFF           |

---

## 6. Advantages

- **Wireless Communication**: Reduces the need for wired connections.
- **Automation**: No manual intervention needed to start/stop the motor.
- **Energy Efficient**: Turns the motor off at the right time, saving electricity.
- **Water Saving**: Prevents tank overflow and wastage.

---

## 7. Conclusion

AquaNode demonstrates a practical solution to automate and manage water levels in a tank wirelessly. With minimal components and cost, it delivers efficient performance and helps conserve vital resources.

---

## Academic & Technical References

- **Waghmare, S. B., & Patil, P. P. (2019)**  
  *Smart Wireless Water Level Monitoring & Controlling System*  
  [IJERT, Vol. 8, Issue 06](https://www.ijert.org/smart-wireless-water-level-monitoring-controlling-system)

- **Gandhi, R., Jambhulkar, S. M., & Chatterjee, M. (2021)**  
  *IoT Based Smart Water Level Monitoring and Control System*  
  [IJSREM](https://ijsrem.com/download/iot-based-smart-water-level-monitoring-and-control-system/)

- **Sharma, K., & Mishra, A. (2020)**  
  *Wireless Water Level Monitoring System Using IoT and Ultrasonic Sensor*  
  [IRJET, Vol. 7 Issue 6](https://www.irjet.net/archives/V7/i6/IRJET-V7I6243.pdf)

- **Prajapati, M., & Patel, D. (2018)**  
  *Design and Implementation of Water Tank Level Monitoring System using Wireless Sensor Network*  
  [IJAREEIE](https://www.ijareeie.com/)

