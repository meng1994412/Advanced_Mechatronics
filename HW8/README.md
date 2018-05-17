## HW8: Harmony Framework
### Objectives:
* Rebuild communication between PIC32MX250F128B and IMU via I2C by using Harmony framework (which is redo the [HW7](https://github.com/meng1994412/ChenyangMeng_ME433_2018/tree/master/HW7) by using Harmony framework).

### Approaches:
* Code instructions (all are under `firmware/src/` ):
  - `ST7735.h` & `ST7735.c`: LCD communication with PIC32MX250F128B (PIC) via SPI.
  - `imc.h` & `imu.c`: IMU communication with PIC via I2C.
  - `i2c_master_noint.h` & `i2c_master_noint.c`: setup I2C communication
  - `app.h` & `app.c`: Build communication among IMU, PIC32, and LCD. 
  - `main.c`: main function that controls `app.c`.
