/*******************************************************************************
  USB HID Function Driver
  Company:
    Microchip Technology Inc.
  File Name:
    usb_device_hid_mouse.h
  Summary:
    USB HID MOUSE Function Driver
  Description:

*******************************************************************************/

#ifndef _USB_FUNCTION_HID_MOUSE_H
#define _USB_FUNCTION_HID_MOUSE_H

#include <stdint.h>
#include <stdbool.h>
#include "system_config.h"
#include "system/system.h"
#include "usb/usb_common.h"
#include "usb/usb_chapter_9.h"
#include "usb/usb_device.h"
#include "usb/usb_device_hid.h"

// *****************************************************************************
// *****************************************************************************
// Section: USB Device HID Mouse types and definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Number of Mouse Buttons.
  Summary:
    Number of Mouse Buttons.
  Description:
    Number of Mouse Buttons.
  Remarks:
    None.
*/
#define MOUSE_BUTTON_NUMBERS 2

// *****************************************************************************
/* Mouse Coordinate.
  Summary:
    Mouse Coordinate type
  Description:
    This type defines the  Mouse Coordinate data type.

  Remarks:
    None.
*/

typedef int8_t MOUSE_COORDINATE;

// *****************************************************************************
/*  Mouse Button State.
  Summary:
   Mouse Button State.
  Description:
    This enumeration defines the possible state of the mouse button.

  Remarks:
    None.
*/

typedef enum
{
    /* Button is not pressed */
    MOUSE_BUTTON_STATE_RELEASED,

	/* Button is pressed */
    MOUSE_BUTTON_STATE_PRESSED

}
MOUSE_BUTTON_STATE;

// *****************************************************************************
/* Mouse Report
  Summary:
   Mouse Report.
  Description:
    This is the Mouse Report. The application can use the
    MOUSE_ReportCreate() function to populate this report.

  Remarks:
    None.
*/

typedef struct
{
    uint8_t data[3];
}
MOUSE_REPORT;


// *****************************************************************************
// *****************************************************************************
// Section: USB HID Mouse functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void MOUSE_ReportCreate
    (
        MOUSE_COORDINATE x,
        MOUSE_COORDINATE y,
        MOUSE_BUTTON_STATE * buttonArray,
        MOUSE_REPORT * mouseReport
    )
  Summary:
    This function creates a mouse report.
  Description:
    This function creates a mouse report. The application can use this function
    to create the mouse report. The report can then be sent to the host by using
    the USB_DEVICE_HID_ReportSend() function.
  Precondition:
    None.
  Parameters:
    x - Mouse X Coordinate
    y - Mouse Y Coordinate
    buttonArray - Pointer to an array of button states. Size of the array is
    defined by USB_HID_MOUSE_BUTTON_NUBMERS.
    mouseReport - Output only variable that will contain the mouse report.
  Returns:
    None
  Example:
    <code>
    // This example shows how to create and send the mouse report. Assume
    // that device is configured. Number of mouse buttons is 3. Assume that
    // this mouse is associated with HID Device Instance 0.
    MOUSE_REPORT mouseReport;
    MOUSE_BUTTON_STATE mouseButtons[MOUSE_BUTTON_NUMBERS];
    MOUSE_COORDINATE xCoordinate;
    MOUSE_COORDINATE yCoordinate;
    USB_DEVICE_HID_TRANSFER_HANDLE transferHandle;
    USB_DEVICE_HID_RESULT result;
    // Update the mouse state
    xCoordinate = someXCoordinate;
    yCoordinate = someYCoordinate;
    mouseButtons[0] = USB_HID_MOUSE_BUTTON_STATE_PRESSED;
    mouseButtons[1] = USB_HID_MOUSE_BUTTON_STATE_RELEASED;
    mouseButtons[2] = USB_HID_MOUSE_BUTTON_STATE_RELEASED;
    // Create the report.
    MOUSE_ReportCreate( xCoordinate, yCoordinate,
        mouseButtons, &mouseReport);
    // Now send the report

    result = USB_DEVICE_HID_ReportSend( 0, &transferHandle,
               (uint8_t *)mouseReport, sizeof(MOUSE_REPORT));
    if(USB_DEVICE_HID_RESULT_OK != result)
    {
        // Do error handling here.
    }
    // The completion of the report send is indicated by the
    // USB_DEVICE_HID_EVENT_REPORT_SEND_COMPLETE event.
    </code>
  Remarks:
    None.
*/

void MOUSE_ReportCreate
(
    MOUSE_COORDINATE x,
    MOUSE_COORDINATE y,
    MOUSE_BUTTON_STATE * buttonArray,
    MOUSE_REPORT * mouseReport
);

#endif
