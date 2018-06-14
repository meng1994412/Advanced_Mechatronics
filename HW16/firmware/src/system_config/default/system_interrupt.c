// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "system/common/sys_common.h"
#include "app.h"
#include "system_definitions.h"

int speed_error = 0, error= 0;
int left=0, right=0;
int MAX_DUTY = 2400;

int center_mass_high = 0;
int center_mass_low = 0;
int center_mass_low_old = 0;

void __ISR(_USB_1_VECTOR, ipl4AUTO) _IntHandlerUSBInstance0(void)
{

    DRV_USBFS_Tasks_ISR(sysObj.drvUSBObject);
}


void __ISR(_TIMER_4_VECTOR, IPL4SOFT) Timer4ISR(void) {
    // code for PI control goes here
    center_mass_high = get_center_mass_high();
    center_mass_low = get_center_mass_low();
    speed_error = get_difference();
    float kp = 2.6;

    if (center_mass_low == 0) {
        MAX_DUTY = 1510;
        center_mass_low = center_mass_low_old;
        kp = 6.0;
    }


    error = center_mass_low - 319; // 240 means the dot is in the middle of the screen
    if(error < -30) {              // slow down the left motor to steer to the left
        error  = -error;
        left = 0.85 * MAX_DUTY - kp * error;
        right = 0.85 * MAX_DUTY - error;
        if (left < 0) {
            left = 0;
        }
    }
    else if(error > 30) {           // slow down the right motor to steer to the right
        right = 0.85 * MAX_DUTY - kp * error;
        left = 0.85 * MAX_DUTY - error;
        if (right < 0) {
            right = 0;
        }
    } else {
     right = MAX_DUTY;
     left = MAX_DUTY;
    }
    OC1RS = right;
    OC4RS = left;

    center_mass_low_old = center_mass_low;

    IFS0bits.T4IF = 0;              // clear interrupt flag, last line
}
