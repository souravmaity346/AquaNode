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


![Screenshot 2025-05-08 204017](https://github.com/user-attachments/assets/dec49c52-63e6-43a8-9e79-7a2884ae5dcd)

### Receiver Side:
- **ESP32** – Receives data and controls output.  
- **NRF24L01** – With external antenna.  
- **RGB LEDs** – Indicate Low (Red), Mid (Yellow), and Full (Green).  
- **2N2222 NPN Transistor** – Switches 12V to the motor.  
- **Water Pump/Motor (12V)** 

![Screenshot 2025-05-08 204044](https://github.com/user-attachments/assets/dee8ca7e-e969-428e-8627-f3853a1457fe)


## 4. Working Principle

### Transmitter Operation:
- The ultrasonic sensor measures the distance to the water surface.
- Based on distance:
  - **Low**: > 30 cm → Red LED, motor ON.
  - **Mid**: ≤ 20 cm → Yellow LED, motor ON.
  - **Full**: ≤ 10 cm → Green LED, motor OFF.
- Status is transmitted via NRF24L01.

### Receiver Operation:
- ESP32 receives status via NRF24L01.
- Depending on mode:
  - Red/Yellow LED blinks (500 ms) → Motor ON.
  - Green LED blinks (500 ms) → Motor OFF.
- 2N2222 transistor switches the motor.

  
![Screenshot 2025-05-08 204135](https://github.com/user-attachments/assets/85b42b73-aae3-427d-b4da-58f336ee5cc7)



https://github.com/user-attachments/assets/a19c02a9-bb45-4a62-a6a9-b72f0afa9e10




## 5. System Modes

| Mode       | Distance Condition | LED Color | Blink Delay | Motor Status |
|------------|--------------------|-----------|-------------|--------------|
| Low Water  | > 30 cm            | Red       | 500 ms      | ON           |
| Mid Water  | ≤ 20 cm            | Yellow    | 500 ms      | ON           |
| Full Water | ≤ 10 cm            | Green     | 500 ms      | OFF          |

---

## 6. Advantages

- **Wireless Communication** – No need for long wires.
- **Automation** – No manual motor control.
- **Energy Efficient** – Saves electricity.
- **Water Saving** – Prevents overflow.

---

## 7. Conclusion

AquaNode is a cost-effective, efficient solution to manage water levels automatically. With minimal components, it ensures better water and energy conservation using real-time communication.

---

## References

1. Waghmare & Patil, *Smart Wireless Water Level Monitoring & Controlling System*, IJERT  
   [Link](https://www.ijert.org/smart-wireless-water-level-monitoring-controlling-system)

2. Gandhi et al., *IoT Based Smart Water Level Monitoring*, IJSREM  
   [Link](https://ijsrem.com/download/iot-based-smart-water-level-monitoring-and-control-system/)

3. Sharma & Mishra, *Wireless Water Level Monitoring Using IoT*, IRJET  
   [Link](https://www.irjet.net/archives/V7/i6/IRJET-V7I6243.pdf)

4. Prajapati & Patel, *Water Tank Monitoring Using Wireless Sensor Network*, IJAREEIE  
   [Link](https://www.ijareeie.com/)
