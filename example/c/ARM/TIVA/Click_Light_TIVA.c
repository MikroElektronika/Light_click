/*
Example for Light Click

    Date          : Sep 2018.
    Author        : Nenad Filipovic

Test configuration TIVA :
    
    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI, GPIO and LOG structures, set AN pin as input and CS pin as output.
- Application Initialization - Initialization driver enable's - SPI and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Light Click board.
     Measured light intensity and calculate light intensity percent from sensor,
     results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 100 ms when the data value changes.

Additional Functions :

- UART
- Conversions

*/

#include "Click_Light_types.h"
#include "Click_Light_config.h"


char logText[10];
uint16_t lightValue;
uint8_t lightPercent;
uint8_t percentOld = 0;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
    mikrobus_spiInit( _MIKROBUS1, &_LIGHT_SPI_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    light_spiDriverInit( (T_LIGHT_P)&_MIKROBUS1_GPIO, (T_LIGHT_P)&_MIKROBUS1_SPI );
    mikrobus_logWrite( "       Initialization", _LOG_LINE );
    mikrobus_logWrite( "---------------------------", _LOG_LINE );
    Delay_100ms();
}

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

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}