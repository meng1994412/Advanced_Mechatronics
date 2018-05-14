# Advanced Mechatronics in Mechatronics Systems Prototyping
## Project Obejctives
* Design, solder, and debug a printed circuit board (PCB).
* Implement advanced digital communication protocals like SPI, I2C, USB, CAN.
* Create physical prototypes with a laser cutter, and a 3D printer.
* Interface with Android device.

## Software/Language Used
* C
* [MPLAB X IDE v4.15](http://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB XC32/32++ Compiler v1.44](http://www.microchip.com/mplab/compilers)
* [MPLAB Harmony Integrated Software Framework v2.05.01](http://www.microchip.com/mplab/mplab-harmony)
* [EAGLE PCB](https://www.autodesk.com/products/eagle/free-download)
* [Android Studio](https://developer.android.com/studio/)

## Hardware Used
* [Microchip(PIC32MX250F128B)](http://www.microchip.com/wwwproducts/en/PIC32MX250F128B)
* [Microchip(PICkit3)](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=PG164130)
* [PCB](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW3/picture%20of%20board.PNG)
* [Microchip(MCP4902)](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW4/MCP4912DataSheet.pdf)
* [Microchip(MCP23008)](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW5/i2cDataSheet.pdf)
* [TFT LCD](https://www.aliexpress.com/item/Free-Shipping-1-8-inch-TFT-touch-LCD-Module-LCD-Screen-Module-SPI-serial-51-drivers/32263827143.html)
* [IMU(LSM6DS33)](https://www.pololu.com/product/2736)

## Weekly Milstones
### Week 1
* Build and program a PIC32MX250F128B circuit board. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW1))

Here is the circuit board:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW1/6_Breadboard.JPG" width="400">

### Week 2
* Design a PIC32MX250F128B library and schematic on EAGLE. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW2))
* Build a PIC32MX250F128B PCB on EAGLE. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW3))

Here is the schematic:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW2/picture%20of%20schematic.PNG" width="800">

Here is the PCB:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW3/picture%20of%20board.PNG" width="500">

### Week 3
* Build the MCP4912 DAC circuit and write a library to communicate with it. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW4))
* Build the MCP23008 I/O expander circuit and write a library to communicate with it. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW5))

Here is I2C circuit board:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW5/CircuitDiagram.JPG" width="400">

### Week 4
* Build communication between PIC32MX250F128B and TFT LCD via SPI. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW6/HW6.X))
* Solder IMU breakout board onto heahders pins. ([Picture](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW7/CircuiteDiagram.JPG))
* Build communication between PIC32MX250F128B and IMU via I2C. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW7))

Here is circuit board with LCD, IMU communication with PIC32MX250F128B:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW7/CircuiteDiagram.JPG" width="400">

### Week 5
* Rebuild communication between PIC32MX250F128B and IMU via I2C by using Harmony framework. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW8/firmware))
* Build communication between PIC32MX250F128B (including IMU, LCD) and computer via USB (communication class device (CDC)) by using Harmony framework. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW9/firmware)) 

### Week 6
* Add digital signal processing (DSP) filter, including moving average filter (MAF), finite impulse response filter (FIR), and infinite impulse response filter (IIR), on z accleration of IMU to get rid of high frequency noises. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW10)) 
* Build communication between PIC32MX250F128B (including IMU, LCD) and computer via USB (human interface device (HID)) by using Harmony framework. ([details here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW11/firmware))

Here is a plot of raw data, and filtered data:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW10/filter_plot.png" width="500">

more details about the filter: [check here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW10/README.md)

Here is a demo for IMU controlling the mouse on PC via USB communication (HID):

![demo1](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW11/hw11demo.gif)
