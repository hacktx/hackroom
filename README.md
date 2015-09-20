The Hackroom
=============

Located on the third floor in Balcony Room A, The Hackroom is a room for chilling and discovery -- a place to get away from all the hubba and play around with something cool. This is a space to relax, experiment with hardware, and enjoy the balcony views.

[![](http://i.imgur.com/TxMMAhF.jpg)](https://www.flickr.com/photos/c3o/930797842/in/photolist-2qfzLE-acgzK-7UBjsV-UknNV-8SpfeF-fr47yN-abDj1y-acep8-7oZvmH-acg2F-ace67-ccaWUA-5e78mm-5DTx4C-5DPf7e-BFCdx-4S93hn-PokXw-5tJ62m-bzXa1L-4AAeGE-a6RyF-dfCso-fr44of-aDUQ44-mKDpN-3ohjyz-puGzL-fr462j-cXwzcN-bu1LPc-bER8Z5-acehj-abDj91-aceb3-n2idW-e7cMfz-r4vShY-4cZYPX-aceei-wGeTh3-rGee8t-s8z9tH-acenH-8VWeZv-a6VgMh-3riCMq-m9KXKM-mxYdw-pb1Hf8)

Like this, but less spooky.

## Hacking and Modifying

All of the hardware in the hackroom is open for modification, from the showcase projects on the table to the LEDs lining the walls. Keep reading to learn how to take everything apart and put 'em back together again.

### Venue Lighting System

Within the HackTX slack, the #ledparty channel allows attendees to vote on and change venue lighting within the Blackbox and Hackroom. If you have an idea for a new animation, pattern, or color that you'd like to see, checkout the code at [particle-power/firmware](https://github.com/hacktx/particle-power/blob/master/firmware/led-show.ino) and add a new function. You can test your code on the smaller LED strips in the hackroom. Once you're set, open a pull request, and we'll add your lighting function to the vote system.

### LED Throwies

Tiny, portable, connectable LED buddies. See the above picture.

 Come to the hackroom, learn to make one, and take it out into the wild.

### batbuns

Our own lil robot friend.

### Illumaphone

[A theremin using light. 'nuff said.](http://www.instructables.com/id/Illumaphone-Light-based-Electronic-Musical-Instrum/)

### Estimote iBeacons

Throughout the venue, we have Estimote iBeacons setup and ready for your use. More on that later.

### 3D Printers

Yeah, we have 3D printers. [SketchUp](http://www.sketchup.com/) is a great, free tool for making models. Experimentation encouraged.

### Particle IoT Photon Microcontrollers

Many of these projects use Photons: small wifi-enabled microcontrollers. We have a ton of different components, including:

* lasers
* photoresistors
* sound sensors
* distance sensors
* piezo buzzers
* button switches
* LED strips
* diffused LEDs
* transistors
* resistors
* diodes
* 2 continuous-rotation motors
* Jumper wires

The easiest way to develop on our Photons is to get direct photon access through the web IDE. [(Online Tutorial)](online_tutorial.md)

However, if you're particularly inclined, you can connect via micro-USB, flash your firmware directly, and scamper off into the hacking wilderness. [(Offline Tutorial)](offline_tutorial.md)

## Hardware Tips

If you aren't familiar with breadboards and wires, [here is a great, in-depth tutorial from sparkfun](https://learn.sparkfun.com/tutorials/how-to-use-a-breadboard).

## Submitting a pull request

Once everything is working, we highly recommend that you [submit a pull request](https://github.com/hacktx/hackroom/pulls) to share your project with everyone who visits this page!

You will need to fork this repository from the top-right corner of this page.

![](https://help.github.com/assets/images/help/repository/fork_button.jpg)

Commit and push your project:

```
git add ./projects/path-to-application
git commit -m "Added my project!!!"
git remote add local https://github.com/<your username>/hackroom
git push local master
```

Then, create your pull request! Here is a [great guide](https://help.github.com/articles/creating-a-pull-request/).