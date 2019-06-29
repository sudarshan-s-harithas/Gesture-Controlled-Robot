# Gesture-Controlled-Robot

In this project, we have designed a simple Hand Gesture Controlled Robot using Arduino. This Hand Gesture Controlled Robot is based on Arduino Nano, ADXL335, RF Transmitter-Receiver Pair and L293D Motor Driver.

## Preface

A Robot is an electro-mechanical system that is operated by a computer program. Robots can be autonomous or semi-autonomous. An autonomous robot is not controlled by human and acts on its own decision by sensing its environment.

Majority of the industrial robots are autonomous as they are required to operate at high speed and with great accuracy. But some applications require semi-autonomous or human controlled robots.

Some of the most commonly used control systems are voice recognition, tactile or touch controlled and motion controlled.One of the frequently implemented motion controlled robot is a Hand Gesture Controlled Robot. In this project, a hand gesture controlled robot is developed using ADXL335.which is a 3-axis Accelerometer .


## Principle of Hand Gesture Controlled Robot

In order to understand the principle of operation of Hand Gesture Controlled Robot, let us divide the project into three parts.

The first part is getting data from the  Accelerometer  to the Arduino. The Arduino continuously acquires data from the accelerometer and based on the predefined parameters,which determies the position of the hand hence direction. it sends a data to the RF Transmitter.

The second part of the project is the Wireless Communication between the RF Transmitter and RF Receiver. The RF Transmitter, upon receiving data from Arduino (through the Encoder IC), transmits it through the RF Communication to the RF Receiver.

Finally, the third part of the project is decoding the Data received by the RF Receiver and sending appropriate signals to the Motor Driver IC, which will activate the Wheel Motors of the Robot.  
