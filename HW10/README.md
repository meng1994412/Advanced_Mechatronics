## HW10: Digital Signal Processing
### Objectives:
* Create 3 digital filters including moving average filter (MAF), finite impulse response filter (FIR), and infinite reponse filter (IIR) to smooth out the high frequency noisy data on z acceleration.
* Plot raw data and filtered data.
* Compare the filters to find out the best filter, in terms of how much the noise is reduced vs how many computations are required.

### Approaches:
* In order to get the plot of data, run the `read_serial.py` under `firmware/src/`, which will read data from PIC32MX250F128B (recieving data from IMU) via USB Port.
* Code instructions:
  - `ST7735.h` & `ST7735.c`: LCD communication with PIC32MX250F128B (PIC) via SPI.
  - `imc.h` & `imu.c`: IMU communication with PIC via I2C.
  - `i2c_master_noint.h` & `i2c_master_noint.c`: setup I2C communication
  - `app.h` & `app.c`: USB communication with PC, which sends both the raw data and filtered data to PC.
  - `read_serial.py`: Read the data via USB Port and plot the data, including raw data, MAF data, IIR data, and FIR data.

### Results:
Here is the plot of raw data, MAF data, IIR data, and FIR data:
<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW10/filter_plot.png" width="500">
