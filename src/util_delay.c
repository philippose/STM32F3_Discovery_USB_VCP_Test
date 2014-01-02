/**
 ******************************************************************************
 * @file    util_delay.c
 * @author  Philippose Rajan
 * @date    17.11.2013
 * @brief   Common Utilities
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

/* ---- Externally visible Variables ------------------------------------- */

/* ---- Externally visible Functions ------------------------------------- */
Type_Err Util_Delay_Init(void);

void Util_Delay_ms(uint32_t timeMs);

void Util_Delay_us(uint32_t timeUs);

/* ---- Local Variables -------------------------------------------------- */
static uint32_t uSecTicks;
static bool subSysReady;

/* ---- Local Functions -------------------------------------------------- */

/* ----------------------------------------------------------------------- */

Type_Err Util_Delay_Init(void)
{
    RCC_ClocksTypeDef clockData;

    subSysReady = FALSE;

    /* Gets the number of ticks for 1 usec */
    RCC_GetClocksFreq(&clockData);
    uSecTicks = clockData.SYSCLK_Frequency / 1000000;

    /* Enable and start the Cortex Cycle Counter */
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;

    subSysReady = TRUE;

    return ERR_OK;
}


void Util_Delay_us(uint32_t timeUs)
{
    /* Return immediately if the Delay system has not been initiated */
    if(!subSysReady) return;

    uint32_t strt = DWT->CYCCNT;

    for(;;)
    {
        uint32_t curr = DWT->CYCCNT;
        uint32_t elapsedTicks = curr - strt;

        if((elapsedTicks / uSecTicks) >= timeUs)
        {
            break;
        }
    }
}


void Util_Delay_ms(uint32_t timeMs)
{
    /* Return immediately if the Delay system has not been initiated */
    if(!subSysReady) return;

    uint32_t remainingMs = timeMs;

    /* Decrement the number of milliseconds each time 1000 usecs have passed */
    while(remainingMs > 0)
    {
        Util_Delay_us(1000);
        remainingMs--;
    }
}

