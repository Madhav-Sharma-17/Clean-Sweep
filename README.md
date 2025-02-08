Components

ESP32 microcontroller

4 Ultrasonic sensors (HC-SR04)

L293D motor driver

4 DC motors

2-channel relay module

Vacuum cleaner

Water pump

Circuit Diagram

Ensure the components are wired as follows:

Motors are connected to the L293D motor driver (IN1, IN2, IN3, IN4, ENA, ENB)

Ultrasonic sensors are connected to ESP32 GPIO pins

Vacuum cleaner and pump are controlled via a 2-channel relay module

Installation

Install the Arduino IDE and ESP32 board support.

Connect the ESP32 via USB and upload the provided code.

Power the robot using an appropriate battery.

Usage

The robot moves autonomously, avoiding obstacles using ultrasonic sensors.

The vacuum and pump are activated during operation.

If an obstacle is detected, the robot reverses and turns to avoid it.

Notes

Ensure proper power supply for motors and ESP32.

Adjust ultrasonic sensor angles for better obstacle detection.

Future Improvements

Add remote control capability via WiFi/Bluetooth.

Implement a more efficient cleaning algorithm.

Integrate a dustbin full detection mechanism.
