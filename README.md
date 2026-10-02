# TRANSFORMAZE — Autonomous Maze-Solving Robot

An Arduino Uno robot that navigates a wooden maze on its own using three HC-SR04 ultrasonic sensors (front, left, right).

**Course:** CSC1100 – Computer Programming
**University:** Egyptian Chinese University (ECU) — Faculty of Computer & Information Systems
**Supervisors:** Dr. Ayman Mohamed, Dr. Doaa Mohey
**Dean of the Faculty:** Dr. Soha Safwat

![Team poster](images/team-poster.png)

## Features
Autonomy · speed and efficiency · sensor integration · ultrasonic sensing · flexible design · compatibility with other technologies · educational challenges

## Hardware
- Arduino Uno
- L298N motor driver
- 2 DC motors + wheels, 2-wheel chassis (11 × 17.4 cm)
- 3 × HC-SR04 ultrasonic sensors
- 12 V power supply

![Robot](images/robot.png)

## Pin mapping
| Function | Pin |
|---|---|
| Motor 1 direction | 5, 6 |
| Motor 2 direction | 7, 8 |
| Motor 1 / Motor 2 speed (PWM) | 3 / 11 |
| Front sensor (trig / echo) | 9 / 10 |
| Left sensor (trig / echo) | A0 / A1 |
| Right sensor (trig / echo) | A2 / A3 |

## How it works
Each loop reads the three distances (average of 5 pings per sensor) and prints them over Serial at 9600 baud. With `threshold = 20` cm:

1. **Front blocked** → stop, reverse, then turn toward the side with more free space.
2. **Left blocked** → stop, turn right.
3. **Right blocked** → stop, turn left.
4. **Otherwise** → drive forward.

Source: [`firmware/transformaze/transformaze.ino`](firmware/transformaze/transformaze.ino)

## Maze
| Photo | Plan |
|---|---|
| ![Maze](images/maze-photo.jpg) | ![Plan](images/maze-plan.jpg) |

## Upload / run
1. Open `firmware/transformaze/transformaze.ino` in the Arduino IDE.
2. Select **Arduino Uno** and the correct port, then upload.
3. Open the Serial Monitor at 9600 baud to see the sensor readings.

## Docs
Project presentation: [`docs/TRANSFORMAZE-presentation.pdf`](docs/TRANSFORMAZE-presentation.pdf)

## Team
Aly Amr · Judy Waleed Khairy · Ali Nagy Ali · Seif Alaa Eldin Khaled · Nora Maher Mohamed El-Amin · Malak Hossam Shamseldeen · Habiba Abdelrhman Mahmoud · Joseph Akram Youssef · Aya Eslam Abdelaleem · Loay Mohamed Abd Alfatah
