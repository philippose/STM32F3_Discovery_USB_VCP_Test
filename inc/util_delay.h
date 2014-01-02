/**
 ******************************************************************************
 * @file    util_delay.h
 * @author  Philippose Rajan
 * @date    17.11.2013
 * @brief   Utility Functions for various Time Delays
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

#ifndef __UTIL_DELAY_H
#define __UTIL_DELAY_H

/* ---- Publicly visible Macros ---------------------------------------- */

/* ---- Publicly visible Variables ------------------------------------- */

/* ---- Publicly visible functions ------------------------------------- */

/**
 * @brief   Initialises the Delay Utilities
 * @param   None
 * @retval  Status of Initialisation
 */
extern Type_Err Util_Delay_Init(void);

/**
 * @brief   Generates a delay of the given time in microseconds
 * @param   timeUs   Delay time in microseconds
 * @retval  None
 */
extern void Util_Delay_us(uint32_t timeUs);

/**
 * @brief   Generates a delay of the given time in milliseconds
 * @param   timeMs   Delay time in milliseconds
 * @retval  None
 */
extern void Util_Delay_ms(uint32_t timeMs);

#endif /* __UTIL_DELAY_H */
