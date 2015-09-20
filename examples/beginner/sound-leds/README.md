sound-leds
========

> Skills: 
> LED strip, Sound sensors
> Interrupts

A sound-reactive LED strip!

## Hardware Setup

For 15 LEDs, you can power them straight from the VIN pin of the Photon, which is powered through micro-USB. For larger amounts, you'll need an external DC power supply.

The LEDs will need:

* power via VIN (5+ volts)
* ground via GND
* data input via one of the digital pins, D#. In this tutorial, we use D0.

For connections between the LED strip and Photon, you can use jumper wires directly, or hook them up using a breadboard.

You will also need to connect the sound sensors to:

* data input via an analog pin, A#.
* data input via a digital pin, D#.
* power via VIN or 3v3 (3+ volts)
* ground via GND