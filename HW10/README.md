## HW10: Digital Signal Processing
### Objectives:
* Create 3 digital filters including moving average filter (MAF), finite impulse response filter (FIR), and infinite reponse filter (IIR) to smooth out the high frequency noisy data on z acceleration.
* Plot raw data and filtered data. ([Plots Here](#results))
* Compare the filters to find out the best filter, in terms of how much the noise is reduced vs how many computations are required.

### Approaches:
* In order to get the plot of data, run the `read_serial.py` under `firmware/src/`, which will read data from PIC32MX250F128B (recieving data from IMU) via USB Port.
* Code instructions:
  - `ST7735.h` & `ST7735.c`: LCD communication with PIC32MX250F128B (PIC) via SPI.
  - `imc.h` & `imu.c`: IMU communication with PIC via I2C.
  - `i2c_master_noint.h` & `i2c_master_noint.c`: setup I2C communication
  - `app.h` & `app.c`: USB communication with PC, which sends both the raw data and filtered data to PC.
  - `main.c`: main function controls the `app.c`.
  - `read_serial.py`: Read the data via USB Port and plot the data, including raw data, MAF data, IIR data, and FIR data.

### Results:
Here is the plot of raw data, MAF data, IIR data, and FIR data:
<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW10/filter_plot.png" width="500">

<img src="https://github.com/meng1994412/ChenyangMeng_ME433_2018/blob/master/HW10/filter_plot2.png" width="500">

5-sample is used in MAF. 
4th-order, 5-sample is used in FIR filter, where the weights are [0.0, 0.2037, 0.5926, 0.2037, 0.0].
coefficients a = 0.2 and b = 0.8 (0.2 * previous_data + 0.8 * new_data) are used in IIR filter.

From the plots:
MAF is better for reducing the noises. The signial get more smooth but also more delayed.
IIR is better for tracking the raw data.

From computation complexity perspectives:
IIR if better since it has only O(1) computation complexity, comparing to MAF and FIR which both have O(n).
