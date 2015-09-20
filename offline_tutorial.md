## Setting up your environment

We will be primarily working on Particle Photons, which are cheap, WiFi-enabled microcontrollers.

![](https://docs.particle.io/assets/images/photon-new.jpg)

Although each photon is owned by HackTX and protected by authentication, we can use a few command-line tools to upload your programs locally over USB.

First, make sure you have [git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) and [nodejs](https://nodejs.org/en/) installed, and clone this repository.

`git clone https://github.com/hacktx/hackroom`

To upload our programs over USB, we will need a few things:

- npm: `sudo apt-get install npm`
- The Particle CLI (Command-line Interface): `sudo npm install -g particle-cli`
- DFU-Util 0.7+ and OpenSSL. Both of these are freely available on Windows, Mac, and Linux.
  * Linux: `sudo apt-get install openssl && ./install-dfu.sh`
  * Mac: `brew install DFU-util openssl`
  * Windows: [See guide here.](https://community.particle.io/t/tutorial-installing-dfu-driver-on-windows-24-feb-2015/3518)

Finally, you'll need a Particle account. You can sign up [online](https://build.particle.io/signup) or by running `particle setup`. Don't worry about scanning for Photons -- we'll be connecting via usb.

## Developing

We have provided some sample applications in the [examples](examples) folder. You can also see hacks from other attendees in [projects](projects). 

If the device isn't connected to the internet (it will blink green instead of cyan), add `SYSTEM_MODE(SEMI_AUTOMATIC)` to the top of your `.ino` file to skip the connection step. You can still print and read data from Serial into a server or application running on your computer.

The [web IDE](https://build.particle.io/) is an awesome and easy way to build your projects, but you can also develop directly in the terminal.

## Uploading your program 

Now that you've done your work, you can verify that it compiles and update your photon. 

Copy all of your code to a new folder within [projects](projects/).

Verify that your program compiles over the cloud:

`particle compile p ./projects/path-to-application --saveTo firmware.bin`

Then set the photon to DFU mode...

1. Press both the RESET and MODE buttons.
2. Release the RESET button.
3. Wait for the LED to start flashing yellow.
4. Release the MODE button.

...and flash the firmware over USB: `particle flash --usb firmware.bin`

Phew! If everything goes well, your photon will flash purple, then pulse white, and your project will work! You can tweak it if you want, show it off to someone around you, and let it live on until the next hacker comes to do it all over again.