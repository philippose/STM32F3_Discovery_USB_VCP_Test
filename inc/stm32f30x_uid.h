/**
 ******************************************************************************
 * @file    stm32f30x_uid.h
 * @author  Philippose Rajan
 * @date    17-November-2013
 * @brief   Location of the STM32F30x Unique IDs
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

#ifndef STM32F30X_UID_H_
#define STM32F30X_UID_H_

/* Unique Devices IDs register set */
/* These are the addresses in ROM of the locations of the STM32 Unique IDs
 * For more information, see STM32F3xx Reference Manual RM0316 (DM00043574.pdf) */
#if defined(STM32F30X)
    #define         ID1          (0x1FFFF7AC)
    #define         ID2          (0x1FFFF7B0)
    #define         ID3          (0x1FFFF7B4)
#endif

#endif /* STM32F30X_UID_H_ */
