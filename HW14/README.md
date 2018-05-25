## HW14: Android USB
### Objectives:
* Solder the PCB with components from breadboard including PIC32MX250F128B, buttons, capacitors, resistors, regulators, LEDS, USB mini connector, female header pins, right programmer headers, switch.
* Write a PIC32 program (USB communication with class CDC) that the PIC32 will send a number to the host (eg. [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html), [Android Phone]((https://www.amazon.com/gp/product/B00HPP3VW2/ref=s9_acsd_hps_bw_c_x_4_w))) 5 times per second.
* Write an Android app with a slider to update value, a textview to show slider value, a button to press to send the value of the slider to the PIC, a textview to show what was sent to the PIC, and a textview wrapped in a scrollview to show what was received from the PIC.

### Approaches:
* PIC32 Program Code instructions (all are under `PIC32Program/firmware/src/` ):
  - `app.h` & `app.c`: send a number to the host (either PuTTY or Android device) 5 times per second.
  - `main.c`: main function that controls `app.c`.

* Android App Code instruction (core codes are under `AndroidProgram/app/src/main`):
  - `MainActivity.java`:  Initializes the USB host code, adds permission to use USB, detects when the PIC is plugged in, and appends the received data to the data that is already in the green textview. ([Path here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/AndroidProgram/app/src/main/java/sunnystormborn/myapplication/MainActivity.java))
  - `activity_main.xml`: Contains the layout of text, view of the app including slider, button, textview, scrollview. ([Path here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/AndroidProgram/app/src/main/res/layout/activity_main.xml))
  - `AndroidManifest.xml`: Give the app permission to use USB communication and `device_filter.xml`. ([Path here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/AndroidProgram/app/src/main/AndroidManifest.xml)) 
  - `device_filter.xml`: identify the PIC USB PID and VID codes. ([Path here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/AndroidProgram/app/src/main/res/xml/device_filter.xml))
  - `classes.jar`: precompiled USB library. ([Path here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW14/AndroidProgram/app/libs)).
  
### Results:

Here are two pictures for the front and back of the PCB before soldering:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/Results/PCBfront.JPG", width=500>

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/Results/PCBback.JPG", width=500>

Here is the picture for PCB after soldering with components:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/Results/PCBsoldering.JPG">

Here is the screen of Android app:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/Results/AndroidScreen.png">

Here is the demo of how communication beteen PIC32 and Android device work:

![demo1](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW14/Results/hw14demo.gif)

