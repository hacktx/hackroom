rainbow
========

> Skills: LED strip

A quick tutorial to get familiar with hardware using LED strips.

## Hardware Setup

![](http://i.imgur.com/dPkRhFh.png)

For 15 LEDs, you can power them straight from the VIN pin of the Photon, which is powered through micro-USB. For larger amounts, you'll need an external DC power supply.

The LEDs will need:

* power via VIN (RED)
* ground via GND (BLACK)
* data input via one of the digital pins, D# (YELLOW). In this tutorial, we use D0.

For connections between the LED strip and Photon, you can use jumper wires directly, or hook them up using a breadboard.

Once your circuit is setup, you can power on your Photon via USB. It will connect to the internet. 

Go to https://build.particle.io/build, create a new application, and insert your `.ino` code. You will also have to import the neopixel library under 'libraries' -- click on the library, then click `INCLUDE IN APP`. 

Once you're ready, save and flash your code to the device. It'll flash purple, then white, do a few jumps and tricks, then land on a breathing cyan color and your LED strip will light up!