## HW11: USB mouse
### Objectives:
* Use IMU to control the mouse on computer via USB (human interface device (HID)).

### Approaches:
* Code instructions:
  - `ST7735.h` & `ST7735.c`: LCD communication with PIC32MX250F128B (PIC) via SPI.
  - `imc.h` & `imu.c`: IMU communication with PIC via I2C.
  - `i2c_master_noint.h` & `i2c_master_noint.c`: setup I2C communication
  - `app.h` & `app.c`: USB communication with PC, which send IMU data (x, y acceleration) to computer to control the mouse.
  - `main.c`: main function controls the `app.c`.
  - `mouse.c` & `mouse.h`: Mouse control functions.
  
  ### Results:
  
