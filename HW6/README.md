## HW6: LCD
### Objectives:
* Create an algorithm to draw string on LCD.
* Create an algorithm to draw loading bar on LCD.
* Show a live frames-per-second reading.

### Approaches:
* In order to draw string on LCD (function `void LCD_drawString(unsigned short x, unsigned short y, char *msg, unsigned short color1, unsigned short color2)`), we need to draw character one by one (function `void LCD_drawChar(unsigned short x, unsigned short y, char ch, unsigned short color1, unsigned short color2)`).
* In order to draw character on LCD, we need to draw pixel one by one (function `void LCD_drawPixel(unsigned short x, unsigned short y, unsigned short color)`)
* Code Instructions:
  - `ST7735.h` & `ST7735.c`: LCD communication with PIC32MX250F128B (PIC) via SPI (including the functions mentioned above).
  - `main.c`: main function that display "Hello, World %d", loading bar, and live fps on LCD screen.

### Results:

Here is the schematic diagram between TFT LCD and PIC32:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW6/SchematicDiagram.JPG" width="400">

Here is the breadboard diagram:

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW6/CircuitDiagram.JPG" width="600">

Here is a demo for LCD display (loading bar elongates as number after "Hello, World!" increases):

![demo1](https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW6/hw6demo.gif)

