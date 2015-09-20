buzzer
===============

> Skills: 
> Tact button switches, piezo buzzers

Buzzzzzz

## Hardware Setup

![](http://i.imgur.com/kqQfBcV.png)

The piezo buzzer needs data from A# and ground from GND. The button needs a connection to D# on one side for reading, and a connection to power (we use 5V here) on the opposite leg.

### How does it work?

When the button is unpressed, there is no connection between the two legs crossing the bridge, so the pin is only connected to ground (GND) and we read a LOW signal. When the button is pressed, the connection is made, connecting it to the 5V power pin, providing a HIGH value. When we read a high value in code, we play a predefined tone.

https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-11-using-a-piezo-buzzer