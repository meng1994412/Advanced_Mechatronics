#include<xc.h>           // processor SFR definitions
#include<sys/attribs.h>  // __ISR macro

// DEVCFG0
#pragma config DEBUG = OFF // no debugging
#pragma config JTAGEN = OFF // no jtag
#pragma config ICESEL = ICS_PGx1 // use PGED1 and PGEC1
#pragma config PWP = OFF // no write protect
#pragma config BWP = OFF // no boot write protect
#pragma config CP = OFF // no code protect

// DEVCFG1
#pragma config FNOSC = PRIPLL // use primary oscillator with pll
#pragma config FSOSCEN = OFF // turn off secondary oscillator
#pragma config IESO = OFF // no switching clocks
#pragma config POSCMOD = HS // high speed crystal mode
#pragma config OSCIOFNC = OFF // disable secondary osc
#pragma config FPBDIV = DIV_1 // divide sysclk freq by 1 for peripheral bus clock
#pragma config FCKSM = CSDCMD // do not enable clock switch
#pragma config WDTPS = PS1048576 // use slowest wdt    //???
#pragma config WINDIS = OFF // wdt no window mode
#pragma config FWDTEN = OFF // wdt disabled
#pragma config FWDTWINSZ = WINSZ_25 // wdt window at 25%

// DEVCFG2 - get the sysclk clock to 48MHz from the 8MHz crystal
#pragma config FPLLIDIV = DIV_2 // divide input clock to be in range 4-5MHz
#pragma config FPLLMUL = MUL_24 // multiply clock after FPLLIDIV
#pragma config FPLLODIV = DIV_2 // divide clock after FPLLMUL to get 48MHz
#pragma config UPLLIDIV = DIV_2 // divider for the 8MHz input clock, then multiplied by 12 to get 48MHz for USB
#pragma config UPLLEN = ON // USB clock on

// DEVCFG3
#pragma config USERID = 0 // some 16bit userid, doesn't matter what
#pragma config PMDL1WAY = OFF // allow multiple reconfigurations
#pragma config IOL1WAY = OFF // allow multiple reconfigurations
#pragma config FUSBIDIO = ON // USB pins controlled by USB module
#pragma config FVBUSONIO = ON // USB BUSON controlled by USB module

#define SLAVE_ADDR 0x20   //0b0010 0000

void initExpander(void);
void setExpander(char pin, char level);
char getExpander(void);

int main() {

    __builtin_disable_interrupts();

    // set the CP0 CONFIG register to indicate that kseg0 is cacheable (0x3)
    __builtin_mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 0xa4210583);

    // LED pin as output
    TRISAbits.TRISA4 = 0;

    // Pushbutton pin as input
    TRISBbits.TRISB4 = 1;

    // Turn off LED
    LATAbits.LATA4 = 0;

    initExpander();
    setExpander(0, 1);

    __builtin_enable_interrupts();

    while(1) {
        char status = (getExpander()>>7);
        setExpander(0, status);
    }
    return 0;
}

void initExpander(void) {
    ANSELBbits.ANSB2 = 0;
    ANSELBbits.ANSB3 = 0;
    i2c_master_setup();
    i2c_master_start();                 // S
    i2c_master_send(SLAVE_ADDR << 1);   // OP+W: R/W = 0 = write
    i2c_master_send(0x00);              // ADDR: IODIR, set the address
    i2c_master_send(0xF0);              // Din/Dout: set GP4-7 input and GP0-3 output
    i2c_master_stop();                  // P: Stop
}

void setExpander(char pin, char level) {
    i2c_master_start();                 // S
    i2c_master_send(SLAVE_ADDR << 1);   // OP+W: R/W = 0 write
    i2c_master_send(0x0A);              // ADDR: OLAT, set the output latch address
    i2c_master_send(level << pin);      // Dout: set pin high/low
    i2c_master_stop();                  // P: Stop
}

char getExpander() {
    char status;
    i2c_master_start();                 // S
    i2c_master_send(SLAVE_ADDR << 1);   // OP+W: R/W = 0 write
    i2c_master_send(0x09);              // ADDR: GPIO
    i2c_master_restart();               // SR
    i2c_master_send(SLAVE_ADDR << 1 | 1);// OP+R: R/W = 1 = read
    status = i2c_master_recv();
    i2c_master_ack(1);                  // no more bytes requested from SLAVE
    i2c_master_stop();                  // P: Stop
    return status;
}
