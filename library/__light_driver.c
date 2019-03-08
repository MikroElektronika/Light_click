/*
    __light_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__light_driver.h"
#include "__light_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __LIGHT_DRV_I2C__
static uint8_t _slaveAddress;
#endif

const uint8_t _LIGHT_COMMAND_REG                          = 0x80;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __LIGHT_DRV_SPI__

void light_spiDriverInit(T_LIGHT_P gpioObj, T_LIGHT_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
    
    hal_gpio_csSet(1);

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LIGHT_DRV_I2C__

void light_i2cDriverInit(T_LIGHT_P gpioObj, T_LIGHT_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __LIGHT_DRV_UART__

void light_uartDriverInit(T_LIGHT_P gpioObj, T_LIGHT_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */

/* Generic write data function */
void light_writeData( uint8_t address, uint8_t writeCommand )
{
    uint8_t writeReg[ 2 ];

    writeReg[ 0 ] = address;
    writeReg[ 1 ] = writeCommand;

    hal_gpio_csSet( 0 );
    hal_spiWrite( writeReg, 2 );
    hal_gpio_csSet( 1 );
}

/* Generic read data function */
uint16_t light_readData()
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 2 ];
    uint16_t result;

    writeReg[ 0 ] = _LIGHT_COMMAND_REG;
    
    hal_gpio_csSet( 0 );
    hal_spiWrite( writeReg, 1 );
    hal_spiRead( readReg, 2 );
    hal_gpio_csSet( 1 );
    
    result = 0x00;
    result = readReg[ 0 ] & 0x0F;
    result <<= 8;
    result |= readReg[ 1 ];

    return result;
}

/* Function calculate light intensity percent  */
uint8_t light_calculatePercent( uint16_t lightValue )
{
    uint8_t result;

    lightValue /= 4096;
    lightValue *= 100;

    result = ( uint8_t ) lightValue;

    return result;
}




/* -------------------------------------------------------------------------- */
/*
  __light_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */