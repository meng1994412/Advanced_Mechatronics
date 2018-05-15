## HW5: I2C IO
### Objectives:
* Build the MCP23008 I/O expander circuit and write a library to communicate with it.
* Build an LED circuit on pin GP0 and a pushbutton circuit on pin GP7 (check the [schematic](# results)).
* Write functions that use the I/O expander to read pin GP7, and if GP7 is low, output high on GP0, otherwise output low.

### Approaches:
* Connect the RESET pin to MCLR so that the Expander resets when the PIC does.
* Start by turning on the LED on GP0, then move on to reading GP7.
* Blink the LED controlled directly by the PIC so that you know the code has not crashed.
* Code Instructions:
  - `i2c_master_noint.h` & `i2c_master_noint.c`: setup I2C communication.
  - `main.c`: main function that makes communication between MCP23008 and PIC32. 

### Results:

Here is the schematic diagram between MCP23008 and PIC32:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW5/SchematicDiagram.JPG" width="500">

Here is the breadboar circuit diagram:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW5/CircuitDiagram.JPG" width="700">

Here is a demo of communication between MCP23008 and PIC32 (The commnucation sets up successfully as LED blinks by pushing the button):

![demo](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW5/hw5demo.gif)

More details about MCP23008 datasheet: [Here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW5/MCP23008DataSheet.pdf), and I2C communication: [Here](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW5/i2cDataSheet.pdf)
