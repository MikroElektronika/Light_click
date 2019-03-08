/*
    __light_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __light_driver.h
@brief    Light Driver
@mainpage Light Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   LIGHT
@brief      Light Click Driver
@{

| Global Library Prefix | **LIGHT** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Sep 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _LIGHT_H_
#define _LIGHT_H_

/** 
 * @macro T_LIGHT_P
 * @brief Driver Abstract type 
 */
#define T_LIGHT_P    const uint8_t*

/** @defgroup LIGHT_COMPILE Compilation Config */              /** @{ */

   #define   __LIGHT_DRV_SPI__                            /**<     @macro __LIGHT_DRV_SPI__  @brief SPI driver selector */
//  #define   __LIGHT_DRV_I2C__                            /**<     @macro __LIGHT_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __LIGHT_DRV_UART__                           /**<     @macro __LIGHT_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup LIGHT_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup LIGHT_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup LIGHT_INIT Driver Initialization */              /** @{ */

#ifdef   __LIGHT_DRV_SPI__
void light_spiDriverInit(T_LIGHT_P gpioObj, T_LIGHT_P spiObj);
#endif
#ifdef   __LIGHT_DRV_I2C__
void light_i2cDriverInit(T_LIGHT_P gpioObj, T_LIGHT_P i2cObj, uint8_t slave);
#endif
#ifdef   __LIGHT_DRV_UART__
void light_uartDriverInit(T_LIGHT_P gpioObj, T_LIGHT_P uartObj);
#endif


/** @defgroup LIGHT_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write data function
 *
 * @param[in] address         Register address
 *
 * @param[in] writeCommand    Command to write
 *
 * Function write byte of data to MCP3201
 */
void light_writeData( uint8_t address, uint8_t writeCommand );

/**
 * @brief Generic read data function
 *
 * @return    14-bit data from MCP3201
 *
 * Function read 14-bit data from MCP3201
 */
uint16_t light_readData();

/**
 * @brief Function calculate percent
 *
 * @param[in] lightValue     14-bit data ADC value
 *
 * @return                   8-bit data light intensity percent
 *
 * Function calculate light intensity percent
 */
uint8_t light_calculatePercent( uint16_t lightValue );





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Light_STM.c
    @example Click_Light_TIVA.c
    @example Click_Light_CEC.c
    @example Click_Light_KINETIS.c
    @example Click_Light_MSP.c
    @example Click_Light_PIC.c
    @example Click_Light_PIC32.c
    @example Click_Light_DSPIC.c
    @example Click_Light_AVR.c
    @example Click_Light_FT90x.c
    @example Click_Light_STM.mbas
    @example Click_Light_TIVA.mbas
    @example Click_Light_CEC.mbas
    @example Click_Light_KINETIS.mbas
    @example Click_Light_MSP.mbas
    @example Click_Light_PIC.mbas
    @example Click_Light_PIC32.mbas
    @example Click_Light_DSPIC.mbas
    @example Click_Light_AVR.mbas
    @example Click_Light_FT90x.mbas
    @example Click_Light_STM.mpas
    @example Click_Light_TIVA.mpas
    @example Click_Light_CEC.mpas
    @example Click_Light_KINETIS.mpas
    @example Click_Light_MSP.mpas
    @example Click_Light_PIC.mpas
    @example Click_Light_PIC32.mpas
    @example Click_Light_DSPIC.mpas
    @example Click_Light_AVR.mpas
    @example Click_Light_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __light_driver.h

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