#ifndef _SYSTEM_CONFIG_H
#define _SYSTEM_CONFIG_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif

// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************

#define SYS_VERSION_STR           "1.10"
#define SYS_VERSION               11000

// *****************************************************************************
/* Clock System Service Configuration Options
*/
#define SYS_CLK_FREQ                        48000000ul
#define SYS_CLK_BUS_PERIPHERAL_1            48000000ul
#define SYS_CLK_UPLL_BEFORE_DIV2_FREQ       63999984ul
#define SYS_CLK_CONFIG_PRIMARY_XTAL         8000000ul
#define SYS_CLK_CONFIG_SECONDARY_XTAL       0ul

/*** Interrupt System Service Configuration ***/
#define SYS_INT                     true

/*** Ports System Service Configuration ***/

#define SYS_PORT_B_ANSEL        0xac1f
#define SYS_PORT_B_TRIS         0xefbf
#define SYS_PORT_B_LAT          0x0
#define SYS_PORT_B_ODC          0x0
#define SYS_PORT_B_CNPU         0x0
#define SYS_PORT_B_CNPD         0x0
#define SYS_PORT_B_CNEN         0x0


// *****************************************************************************
// *****************************************************************************
// Section: Driver Configuration
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Middleware & Other Library Configuration
// *****************************************************************************
// *****************************************************************************

/*** USB Driver Configuration ***/

/* Enables Device Support */
#define DRV_USBFS_DEVICE_SUPPORT      true

/* Disable Device Support */
#define DRV_USBFS_HOST_SUPPORT      false

/* Maximum USB driver instances */
#define DRV_USBFS_INSTANCES_NUMBER    1

/* Interrupt mode enabled */
#define DRV_USBFS_INTERRUPT_MODE      true

/* Number of Endpoints used */
#define DRV_USBFS_ENDPOINTS_NUMBER    3 // was 1

/*** USB Device Stack Configuration ***/

/* The USB Device Layer will not initialize the USB Driver */
#define USB_DEVICE_DRIVER_INITIALIZE_EXPLICIT

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER     1

/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE      8 // was 64

/* Enable SOF Events */
#define USB_DEVICE_SOF_EVENT_ENABLE

/* Maximum instances of CDC function driver */
#define USB_DEVICE_CDC_INSTANCES_NUMBER     1

/* CDC Transfer Queue Size for both read and
   write. Applicable to all instances of the
   function driver */
#define USB_DEVICE_CDC_QUEUE_DEPTH_COMBINED 3

/* Application USB Device CDC Read Buffer Size. This should be a multiple of
 * the CDC Bulk Endpoint size */

#define APP_READ_BUFFER_SIZE 64

/* Macro defines USB internal DMA Buffer criteria*/

#define APP_MAKE_BUFFER_DMA_READY

// *****************************************************************************
// *****************************************************************************
// Section: Application Configuration
// *****************************************************************************
// *****************************************************************************

#ifdef __cplusplus
}
#endif


#endif // _SYSTEM_CONFIG_H
