#include <xc.h>
#include "imc.h"

void imc_init(void) {
  // Turn off analog input (since for i2c we still use the i2c2)
  ANSELBbits.ANSB2 = 0;
  ANSELBbits.ANSB3 = 0;

  // Initialize the i2c
  i2c_master_setup();

  // Initialize the accelerometer
  i2c_master_start();                   // start
  i2c_master_send(IMU_ADDR << 1);       // OP + W: R/W = 0 = write
  i2c_master_send(0x10);                // ADDR: CTRL1_XL register for imu accelerometer
  i2c_master_send(0x82);                // CTRL1_XL register: [1 0 0 0 0 0 1 0], ORD_XL = [1 0 0 0] (1.66kHz), FS_XL = [0 0] (4g), BW_XL = [1 0] (100Hz filter)
  i2c_master_stop();

  // Initialize gyroscope
  i2c_master_start();                   // start
  i2c_master_send(IMU_ADDR << 1);       // OP + W: R/W = 0 = write
  i2c_master_send(0x11);                // ADDR: CTRL2_G register for imu gyroscope
  i2c_master_send(0x88);                // CT RL2_G register: [1 0 0 0 1 0 0 0], ORD_G = [1 0 0 0] (1.66kHz), FS_G = [1 0] (1000dps), BW_XL = [0 0] (no filter)
  i2c_master_stop();

  // Initialize IF_INC bit (read multiple registers without specifying each register location)
  i2c_master_start();                   // start
  i2c_master_send(IMU_ADDR << 1);       // OP + W: R/W = 0 = write
  i2c_master_send(0x12);                // ADDR: CTRL3_C register for reading multiple registers
  i2c_master_send(0x04);                // CTRL3_C register: default value [0 0 0 0 0 1 0 0] where IF_INC = 1
  i2c_master_stop();
}

unsigned char imu_test(void) {
  // get the data from WHO_AM_I register
  unsigned char whoami;
  i2c_master_start();                   // start
  i2c_master_send(IMU_ADDR << 1);       // OP + W: R/W = 0 write
  i2c_master_send(0x0F);                // ADDR: WHO_AM_I register for imu

  i2c_master_restart();                 // restart
  i2c_master_send(IMU_ADDR << 1 | 1);   // OP + W: R/W = 1 read
  whoami = i2c_master_recv();           // receive the data from the ADDR
  i2c_master_ack(1);
  i2c_master_stop();
  return whoami;
}

void I2C_read_multiple(unsigned char address, unsigned char regist, unsigned char *data, int length) {
  int i;
  i2c_master_start();                   // star
  i2c_master_send(IMU_ADDR << 1);       // OP + W: R/W = 0 write
  i2c_master_send(0x20);                // ADDR: starting at OUT_TEMP_L

  i2c_master_restart();                 // restart
  i2c_master_send(IMU_ADDR << 1 | 1);   // OP + W: R/W = 1 read
  for (i = 0; i < length; i++) {
    data[i] = i2c_master_recv();        // receive the data from corresponding ADDR
    if (i != length - 1) {
      i2c_master_ack(0);
    }
  }
  i2c_master_ack(1);
  i2c_master_stop();
}

float getXAcc(unsigned char *data) {
  // x acceleration in g's
  signed short xAcc = (data[9] << 8) | data[8];
  return (xAcc / 32767.0 * 2.0);
}

float getYAcc(unsigned char *data) {
  // y acceleration in g's
  signed short yAcc = (data[11] << 8) | data[10];
  return yAcc / 32767.0 * 2.0;
}

float getZAcc(unsigned char *data) {
  // z acceleration in g's
  signed short zAcc = (data[13] << 8) | data[12];
  return zAcc / 32767.0 * 2.0;
}

float getXGyro(unsigned char *data) {
  // x gyro in degrees/second
  signed short xGyro = (data[3] << 8) | data[2];
  return xGyro / 32767.0 * 500.0;
}

float getYGyro(unsigned char *data) {
  // y gyro in degrees/second
  signed short yGyro = (data[5] << 8) | data[4];
  return yGyro / 32767.0 * 500.0;
}

float getZGyro(unsigned char *data) {
  // z gyro in degrees/second
  signed short zGyro = (data[7] << 8) | data[6];
  return zGyro / 32767.0 * 500.0;
}
