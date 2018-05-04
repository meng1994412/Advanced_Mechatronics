#ifndef imc__H__
#define imc__H__

#define IMU_ADDR 0b1101011

void imc_init(void);
unsigned char imu_test(void);
void I2C_read_multiple(unsigned char address, unsigned char register, unsigned char *data, int length);
float getXAcc(unsigned char *data);
float getYAcc(unsigned char *data);
float getZAcc(unsigned char *data);
float getXGyro(unsigned char *data);
float getYGyro(unsigned char *data);
float getZGyro(unsigned char *data);


#endif
