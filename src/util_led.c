/**
 ******************************************************************************
 * @file    util_led.c
 * @author  Philippose Rajan
 * @date    06.01.2014
 * @brief   <Put in a brief description here>
 *
 * @see     The GNU Public License (GPL) Version 3
 *
 ******************************************************************************
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ---- Includes --------------------------------------------------------- */
#include "globals.h"
#include "sys_led_intern.h"

/* ---- Externally visible Variables ------------------------------------- */

/* ---- Externally visible Functions ------------------------------------- */
int32_t Sys_LED_Init(const struct Sys_LED_Cfg *brdSetup);

void Util_LED_On(uint32_t led);

void Util_LED_Off(uint32_t led);

void Util_LED_Toggle(uint32_t led);

/* ---- Local Variables -------------------------------------------------- */
static const struct Sys_LED_Cfg *currCfg;

/* ---- Local Functions -------------------------------------------------- */

/* ----------------------------------------------------------------------- */

int32_t Sys_LED_Init(const struct Sys_LED_Cfg *brdSetup)
{
    SYS_ASSERT(brdSetup);

    currCfg = brdSetup;

    for(uint8_t i = 0; i < brdSetup->numLEDs; i++)
    {
        const struct Sys_LED *currLED = &(brdSetup->LEDs[i]);

        GPIO_Init(currLED->pin.basePort, (GPIO_InitTypeDef*)&currLED->pin.initData);
        Util_LED_Off(i);
    }

    return 0;
}



void Util_LED_Off(uint32_t led)
{
    SYS_ASSERT(currCfg);

    if(led >= currCfg->numLEDs)
    {
        return;
    }

    const struct Sys_LED *currLED = &(currCfg->LEDs[led]);

    if(currLED->activeHigh)
    {
        currLED->pin.basePort->BRR = currLED->pin.initData.GPIO_Pin;
    }
    else
    {
        currLED->pin.basePort->BSRR = currLED->pin.initData.GPIO_Pin;
    }
}



void Util_LED_On(uint32_t led)
{
    SYS_ASSERT(currCfg);

    if(led >= currCfg->numLEDs)
    {
        return;
    }

    const struct Sys_LED *currLED = &(currCfg->LEDs[led]);

    if(currLED->activeHigh)
    {
        currLED->pin.basePort->BSRR = currLED->pin.initData.GPIO_Pin;
    }
    else
    {
        currLED->pin.basePort->BRR = currLED->pin.initData.GPIO_Pin;
    }
}



void Util_LED_Toggle(uint32_t led)
{
    SYS_ASSERT(currCfg);

    if(led >= currCfg->numLEDs)
    {
        return;
    }

    const struct Sys_LED *currLED = &(currCfg->LEDs[led]);

    currLED->pin.basePort->ODR ^= currLED->pin.initData.GPIO_Pin;
}

