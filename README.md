# AquaNode
Wireless Water Level Monitoring and Motor Control System.
**Project Report: AquaNode – Wireless Water Level Monitoring and Motor Control System**

-----
**Abstract**

AquaNode is an innovative wireless water level monitoring and motor control system designed to automate the process of maintaining optimal water levels in overhead tanks. This project uses an ultrasonic sensor to measure the water level and transmits the data wirelessly using NRF24L01 modules. An Arduino Nano serves as the transmitter controller, while an ESP32 microcontroller processes the data on the receiver side. The system operates in three modes—Low, Mid, and Full—based on the measured water distance, and accordingly controls an RGB LED indicator and a motor using a 2N2222 transistor. The motor is turned ON when water is low or mid, and automatically turned OFF when the tank reaches full capacity. AquaNode offers a reliable, efficient, and cost-effective solution to water management by reducing manual intervention, conserving electricity, and preventing water overflow through real-time wireless communication.

-----
**1. Introduction**

Water management is essential in households and industries. AquaNode is a wireless water level monitoring and control system that utilizes an ultrasonic sensor and RF communication to maintain the water level in a tank automatically. The system helps conserve water and electricity by automating the motor operation based on real-time water level data.

-----
**2. Objective**

To design and implement a wireless water tank level monitoring system using an Arduino Nano, ESP32, NRF24L01 modules, and an ultrasonic sensor. The system should:

- Monitor water levels continuously.
- Transmit water level status wirelessly.
- Indicate levels using LEDs.
- Control a motor based on water levels. 
-----
**3. Components Used**

**Transmitter Side:**

- **Arduino Nano** – Controls the ultrasonic sensor and handles data transmission. 
- **Ultrasonic Sensor (HC-SR04)** – Measures water level by distance.
- **NRF24L01** – Sends water level data wirelessly. 


![Arduino Nano - ATmega328](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.001.jpeg)![HC-SR04 Ultrasonic Sensor](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.002.png)![NRF24L01 2.4GHz wireless transceiver module](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.003.jpeg)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.004.png)






![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.005.png)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.006.png)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.007.png)

**Receiver Side:**

- **ESP32** – Processes received data and controls output. 
- **NRF24L01 (with external antenna)** – Receives data from the transmitter. 
- **RGB LEDs (Red, Yellow, Green)** – Indicate water level status. 
- **2N2222 NPN Transistor** – Acts as a switch for controlling a 12V supply to the motor.
- ![NRF24L01 PA+LNA SMA Wireless ...](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.008.jpeg)![ERH India 1 Pc Mini Water Pump Double Sided 9v DC Motor with 1 Meter Pipe  Aquariums and Fish Tanks, Water Fountains, Medical Devices, Automotive ...](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.009.jpeg)![Amazon.in: Buy DOIT DEVIT V1 ESP32-WROOM-32 Development Board ESP32 ESP-32S  WiFi Bluetooth Dev Module CP2102 for Arduino Online at Low Prices in India  ...](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.010.jpeg)**Water Pump/Motor (12V)** – Operates based on water level. 






  ![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.011.png)![2N2222 NPN Transistor](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.012.jpeg)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.013.png)![How to use a RGB LED with Arduino | Tutorial](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.014.png)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.015.png)







![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.016.png)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.017.png)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.018.png)


**4. Working Principle**

**Transmitter Operation:**

- The **ultrasonic sensor** measures the distance from the sensor to the water surface.
- Based on the measured distance, one of the three water level modes is determined:
  - **Low Level**: Distance > 30 cm → Red LED blinks, motor ON.
  - **Mid Level**: Distance ≤ 20 cm → Yellow LED blinks, motor ON.
  - **Full Level**: Distance ≤ 10 cm → Green LED blinks, motor OFF.
- This status is sent to the receiver via **NRF24L01**.

**Receiver Operation:**

- The **ESP32** receives the data through **NRF24L01**.
- Depending on the received status:
  - **Low Level**: Red LED blinks (delay 500 ms), motor turns ON via 2N2222.
  - **Mid Level**: Yellow LED blinks (delay 500 ms), motor remains ON.
  - **Full Level**: Green LED blinks (delay 500 ms), motor turns OFF.
- The **2N2222 transistor** controls the external 12V power to the motor, acting as a switch.



![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.019.png)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.020.png)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.021.jpeg)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.022.jpeg)




![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.023.png)![](Aspose.Words.758ef7ca-64c0-462e-99db-d780faae7005.024.png)

**5. System Modes**

|**Mode**|**Condition**|**LED Color**|**LED Blink**|**Motor Status**|
| :-: | :-: | :-: | :-: | :-: |
|Low Water|Distance > 30 cm|**Red**|500 ms|ON|
|Mid Water|Distance ≤ 20 cm|**Yellow**|500 ms|ON|
|Full Water|Distance ≤ 10 cm|**Green**|500 ms|OFF|

-----
**6. Advantages**

- **Wireless Communication**: Reduces the need for wired connections.
- **Automation**: No manual intervention needed to start/stop the motor.
- **Energy Efficient**: Turns the motor off at the right time, saving electricity.
- **Water Saving**: Prevents tank overflow and wastage.
-----
**7. Conclusion**

AquaNode demonstrates a practical solution to automate and manage water levels in a tank wirelessly. With minimal components and cost, it delivers efficient performance and helps conserve vital resources.

**Academic & Technical References :-**

1. S. B. Waghmare and P. P. Patil (2019)
   *"Smart Wireless Water Level Monitoring & Controlling System"*
   International Journal of Engineering Research & Technology (IJERT), Vol. 8, Issue 06
   https://www.ijert.org/smart-wireless-water-level-monitoring-controlling-system
   ➤ Discusses the use of wireless sensors and automation for water level management.
1. R. Gandhi, S. M. Jambhulkar, M. Chatterjee (2021)
   *"IoT Based Smart Water Level Monitoring and Control System"*
   International Journal of Scientific Research in Engineering and Management (IJSREM)
   https://ijsrem.com/download/iot-based-smart-water-level-monitoring-and-control-system/
   ➤ Presents an ESP32-based solution for remote tank management.
1. Sharma, K., & Mishra, A. (2020)
   *"Wireless Water Level Monitoring System Using IoT and Ultrasonic Sensor"*
   International Research Journal of Engineering and Technology (IRJET), Vol. 7 Issue 6
   https://www.irjet.net/archives/V7/i6/IRJET-V7I6243.pdf
   ➤ Describes ultrasonic level sensing and ESP-based wireless transmission.
1. Prajapati, M., & Patel, D. (2018)
   *"Design and Implementation of Water Tank Level Monitoring System using Wireless Sensor Network"*
   International Journal of Advanced Research in Electrical, Electronics and Instrumentation Engineering
   <https://www.ijareeie.com/>
   ➤ Focuses on RF-based solutions for water level detection and control.

