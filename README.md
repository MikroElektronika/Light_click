![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Light Click

---

- **CIC Prefix**  : LIGHT
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Sep 2018.

---

### Software Support

We provide a library for the Light Click on our [LibStock](https://libstock.mikroe.com/projects/view/630/light-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control Light Click.
Library performs the communication with the device via SPI driver by writting to registers and by reading from registers.
Library reads measurements for ADC value and calculate calculate light intensity percent from MCP3201 sensor.

Key functions :

- ``` void light_writeData( uint8_t address, uint8_t writeCommand ) ``` - Generic write data function
- ``` uint16_t light_readData() ``` - Generic read data function
- ``` uint8_t light_calculatePercent( uint16_t lightValue ) ``` - Function calculate light intensity percent

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI, GPIO and LOG structures, set AN pin as input and CS pin as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Light Click board.
     Measured light intensity and calculate light intensity percent from sensor,
     results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 100 ms when the data value changes.


```.c

void applicationTask()
{
    lightValue = light_readData();
    lightPercent = light_calculatePercent( lightValue );

    if ( percentOld != lightPercent )
    {
        mikrobus_logWrite( " Light Intensity :", _LOG_TEXT );
        IntToStr( lightPercent, logText );
        mikrobus_logWrite( logText, _LOG_TEXT );
        mikrobus_logWrite( " %", _LOG_LINE );

        mikrobus_logWrite( " Light Value     :", _LOG_TEXT );
        IntToStr( lightValue, logText );
        mikrobus_logWrite( logText, _LOG_LINE );
        mikrobus_logWrite( "---------------------------", _LOG_LINE );

        percentOld = lightPercent;
        Delay_100ms();
    }
}

```


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/630/light-click-example) page.

Other mikroE Libraries used in the example:

- SPI
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
