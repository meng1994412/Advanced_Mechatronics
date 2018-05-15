## HW7: IMU
### Objectives:
* Solder IMU ([LSM6DS33](https://www.pololu.com/product/2736)) breakout board onto heahders pins.
* Build communication between PIC32MX250F128B and IMU via I2C. 
* Display the test result, and acceleration of X, Y direction on LCD screen ([check demo](#results)).

### Approaches:
* Check the communication by reading the WHOAMI register, that result should be 0b01101001 (decimal 105).
* Write functions to be able to read many registers in a row including temperature, gyroscope, and accelerometer data registers.
* Read the IMU at 20 Hz, and blink your LED as a heartbeat. 
* Draw bars starting from the center of the LCD in the direction of the chip +X and +Y directions, and scale the length of the bars to match the readings from the accelerometer.
* Code instructions:
  - `ST7735.h` & `ST7735.c`: LCD communication with PIC32MX250F128B (PIC) via SPI.
  - `imc.h` & `imu.c`: IMU communication with PIC via I2C.
  - `i2c_master_noint.h` & `i2c_master_noint.c`: setup I2C communication
  - `main.c`: main function that display the test result, and acceleration of X, Y direction on LCD.
  
### Results:

Here is the schematic diagram between IMU and PIC32:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW7/SchematicDiagram.JPG" width="400">

Here is the breadboard diagram:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW7/CircuiteDiagram.JPG" width="400">

Here is a demo of IMU reading on LCD screen:

![demo1](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW7/hw7demo.gif)

More information about IMU: [check here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW7/LSM6DS33DataSheet.pdf)
