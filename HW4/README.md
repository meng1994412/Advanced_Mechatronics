## HW4: SPI DAC
### Objectives:
* Build the MCP4912 DAC circuit and write a library to communicate with it.
* Write functions that the DAC outputs a 10Hz sine wave on VoutA and a 5Hz triangle wave on VoutB, updating the values 1000 times a seconds.

### Approaches:
* Code instructions:
  - `main.c`: main function that creates sine wave and triangle wave.
  - `SPI.c` & `SPI.h`: create commnucation between MCP4912 and PIC32 via SPI1 (includes SPI initialization, SPI input & output, voltage seeting functions).

### Results:

Here is the schematic diagram between MCP4912 and PIC32MX250F128B:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW4/Schematic_Diagram.JPG" width="500">

Here is the circuit diagram of breadboard:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW4/circuit%20board.JPG" width="500">

Here is the sine wave and triangle wave read by nScope (oscilloscope):

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW4/nScope%20reading.png" width="800">
