#include "app.h"
#include <xc.h>           // processor SFR definitions
#include <sys/attribs.h>  // __ISR macro
#include <stdio.h>
#include "ST7735.h"
#include "i2c_master_noint.h"
#include "imc.h"


APP_DATA appData;
#define MSG_LEN 100
#define DATA_LEN 14


void APP_Initialize ( void )
{
    // Place the App state machine in its initial state.
    appData.state = APP_STATE_INIT;

    __builtin_disable_interrupts();

    // set the CP0 CONFIG register to indicate that kseg0 is cacheable (0x3)
    __builtin_mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 0xa4210583);

    // 0 data RAM access wait states
    BMXCONbits.BMXWSDRM = 0x0;

    // enable multi vector interrupts
    INTCONbits.MVEC = 0x1;

    // disable JTAG to get pins back
    DDPCONbits.JTAGEN = 0;

    // LED pin as output
    TRISAbits.TRISA4 = 0;

    // Pushbutton pin as input
    TRISBbits.TRISB4 = 1;

    // Turn off LED
    LATAbits.LATA4 = 0;

    // Initialize all the peripherals
    imc_init();
    LCD_init();
    LCD_clearScreen(BLACK);
    __builtin_enable_interrupts();
}

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            // define some parameters and arrays
            unsigned char test_msg[MSG_LEN];
            unsigned char data[DATA_LEN] = {};
            unsigned char msg[MSG_LEN];
            float xAcc;
            float yAcc;
            // use _CP0_SET_COUNT(0) and _CP0_GET_COUNT() to test the PIC timing
            // remember the core timer runs at half the sysclk
            _CP0_SET_COUNT(0);
            // who am i test
            unsigned char status = imu_test();
            sprintf(test_msg, "Test address = %d  ", status);
            LCD_drawString(1, 1, test_msg, WHITE, BLACK);

            // get the x & y acceleration data
            I2C_read_multiple(IMU_ADDR, 0x20, data, DATA_LEN);
            xAcc = getXAcc(data);
            yAcc = getYAcc(data);

            sprintf(msg, "xAcc = %1.3f  ", xAcc);
            LCD_drawString(1, 10, msg, WHITE, BLACK);
            sprintf(msg, "yAcc = %1.3f  ", yAcc);
            LCD_drawString(1, 20, msg, WHITE, BLACK);

            // draw static bar
            LCD_drawStaticBar(10, 80, 3, 108, BLUE);
            LCD_drawStaticBar(64, 30, 110, 3, BLUE);

            // draw dynamic bar
            LCD_drawDynamicBarX(64, 80, 3, xAcc, WHITE, BLUE);
            LCD_drawDynamicBarY(64, 80, yAcc, 3, WHITE, BLUE);


            while (_CP0_GET_COUNT()<1200000) { ; }
            LATAbits.LATA4 =! LATAbits.LATA4;
            break;
        }


        /* The default state should never be executed. */
        default:
        {

            break;
        }
    }
}
