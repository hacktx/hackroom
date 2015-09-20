Illumaphone
=============

> Skills: 
> Photoresistors, Serial I/O
> ChucK musical programming

A musical instrument using light -- a photosensitive theremin.

via @bonniee (https://github.com/bonniee/illumaphone), musical hack maestra. [Here's some more inspiration](https://github.com/bonniee/mug-music).

## Hardware Setup

Photoresistors on A0, A1, ... , A5, all connected to a power line.

## Software Setup

Install ChucK. Run `sudo chuck cuppy.ck:0 --out32` while the microcontroller is running and connected to your computer via USB. This command will use the first compatible serial device and the default audio device, which is assumed to have 32 output channels. You can list your audio channels and details with `sudo chuck --probe`.