# Saurav-Home-Robot

### Hardware Components

 - Raspberry Pi 4
 - Arduino UNO with Adafruit Motor Shield (HW-130)
 - Differential drive robot chassis using N20 geared motors with Quad type encoders
    - RPM: 200 RPM
    - Gear Ratio: 1:150
    - Encoders CPR at output shaft: 4220
- Li-ion batteries

### Software

 - ROS 2
 - Ubuntu on Raspberry Pi 4
 - ROS Arduino Serial Bridge
    - Differential drive controller
    - PID control
    - Encoder driver
    - Motor driver


### Run Commands

#### Arduino
- Serial baud rate: 57600
- Serial commands:
    - `e` get encoder values
    - `r` reset encoder values
    - `o 50 75` Run left & right motor with 50 & 75 speed respectively (max 255)
    - `m 60 86` Run motors with closed loop rpm of 60 and 86