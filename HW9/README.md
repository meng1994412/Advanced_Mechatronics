## HW9: USB CDC
### Objectives:
* Write a program that when PIC32MX250F128B recieves the letter "r" from [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html) on PC, 100 values of accelerometer and gyroscope (both x, y, z direction) are pops out on PuTTY at 100 Hz.

### Approaches:
* Code instructions (all are under `firmware/src/` ):
  - `ST7735.h` & `ST7735.c`: LCD communication with PIC32MX250F128B (PIC) via SPI.
  - `imc.h` & `imu.c`: IMU communication with PIC via I2C.
  - `i2c_master_noint.h` & `i2c_master_noint.c`: setup I2C communication
  - `app.h` & `app.c`: Build USB communication (CDC) between PIC32 and PuTTY. 
  - `main.c`: main function that controls `app.c`.
* Do not worry about the letter "r" showed up in PuTTY. The python file of serial port communication will take care of that in next week.

### Results:

Here is a demo of communication between PIC32 and PuTTY:

![demo1](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW9/Results/hw9demo.gif)
