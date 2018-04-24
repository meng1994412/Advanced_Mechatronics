#include"SPI1.h"

// initialize SPI1
void initSPI1(void) {
  // Master Device: SPI1(PIC32)
  // Pins: SDO1(A1), SCK1(B14), SDI1(B8), SS1(A0)
  // Manually control the SS1 as digital output
  RPA1Rbits.RPA1R = 0b0011;   // set SDO1 to A1
  SDI1Rbits.SDI1R = 0b0100;   // set SDI1 to B8, in this homework SDI1 is not connected to SPI DAC
  SPI1CON = 0;                // turn off the SPI module and reset it
  SPI1BUF;                    // clear the rx buffer by reading from it
  SPI1BRG = 0x1;              // baud rate to 12.5MHz SPIxBRG = Fpb/(2*Fsck) - 1 = 1, Fpb = 50MHz, Fsck = 12.5MHz
  SPI1STATbits.SPIROV = 0     // clear the overflow bit
  SPI1CONbits.CKP = 0;        // the clock is idle when low, active when high
  SPI1CONbits.CKE = 1;        // data changes when clock goes from hi to lo (since CKP is 0)
  SPI1CONbits.MSTEN = 1;      // master operation
  SPI1CONbits.ON = 1;         // turn on SPI1
  TRISAbits.TRISA0 = 0;       // set A0 as an output
}

// send a byte via SPI and return the response
char SPI1_IO(char write) {
  SPI1BUF = write;
  while(!SPI1STATbits.SPIRBF) { ; } // wait until the master receives the data
  return SPI1BUF;
}

// where channel is 0 or 1 (for VoutA and VoutB), and voltage is the 10-bit output level.
void setVoltage(char channel, unsigned char voltage) {
  unsigned char LSB, MSB;

  MSB =  channel << 7;
  MSB |= 0b01110000;
  MSB |= voltage >> 6;

  LSB = (voltage << 2) & 0b11111111; // 0xFF

  CS = 0;                     // activate SPI1 by setting the chip line low
  SPI1_IO(MSB);
  SPI1_IO(LSB);
  CS = 1;                     // deactivate the SPI1 by rasing the line to high, ending the communication
  
}
