#ifndef _APP_H
#define _APP_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
#include "mouse.h"

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

typedef enum
{
	/* Application's state machine's initial state. */
	APP_STATE_INIT=0,

	/* Application waits for configuration in this state */
    APP_STATE_WAIT_FOR_CONFIGURATION,

    /* Application runs mouse emulation in this state */
    APP_STATE_MOUSE_EMULATE,

    /* Application error state */
    APP_STATE_ERROR

} APP_STATES;

typedef struct
{
    /* The application's current state */
    APP_STATES state;

    /* device layer handle returned by device layer open function */
    USB_DEVICE_HANDLE  deviceHandle;

    /* Is device configured */
    bool isConfigured;

    /* Mouse x coordinate*/
    MOUSE_COORDINATE xCoordinate;

    /* Mouse y coordinate*/
    MOUSE_COORDINATE yCoordinate;

    /* Mouse buttons*/
    MOUSE_BUTTON_STATE mouseButton[MOUSE_BUTTON_NUMBERS];

    /* HID instance associated with this app object*/
    SYS_MODULE_INDEX hidInstance;

    /* Transfer handle */
    USB_DEVICE_HID_TRANSFER_HANDLE reportTransferHandle;

    /* Device Layer System Module Object */
    SYS_MODULE_OBJ deviceLayerObject;

    /* USB HID active Protocol */
    uint8_t activeProtocol;

    /* USB HID current Idle */
    uint8_t idleRate;

    /* Tracks the progress of the report send */
    bool isMouseReportSendBusy;

    /* Flag determines SOF event has occured */
    bool sofEventHasOccurred;

    /* SET IDLE timer */
    uint16_t setIdleTimer;

} APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************
void APP_Initialize ( void );

void APP_Tasks ( void );


#endif /* _APP_H */
/*******************************************************************************
 End of File
 */
