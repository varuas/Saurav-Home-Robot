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
 - Ubuntu 22 on Raspberry Pi 4
 - ROS Arduino Serial Bridge
    - Differential drive controller
    - PID control
    - Encoder driver
    - Motor driver

### Preliminary setups

- Install Ubuntu on WSL2
- Allow ICMPv4 outbound firewall on windows to allow RP4 to ping WSL

### Run Commands

#### Arduino
- Serial baud rate: 57600
- Serial commands:
    - `e` get encoder values
    - `r` reset encoder values
    - `o 50 75` Run left & right motor with 50 & 75 speed respectively (max 255)
    - `m 60 86` Run motors with closed loop rpm of 60 and 86

### Raspberry Pi 4

Test Serial

`tio -b 57600 /dev/ttyACM0`

Run Serial Motor Driver
 - `ros2 run serial_motor_demo driver --ros-args -p serial_port:=/dev/ttyACM0 -p baud_rate:=57600 -p loop_rate:=30 -p encoder_cpr:=4220`

 Run Serial Motor GUI (on dev machine)
 `ros2 run serial_motor_demo gui`

### Links & Credits

ROS Arduino Bridge forked from: https://github.com/joshnewans/ros_arduino_bridge

ROS/Arduino Serial Motor demo: https://github.com/joshnewans/serial_motor_demo

