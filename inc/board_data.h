/**
 ******************************************************************************
 * @file    board_data.h
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

#ifndef __board_data_H
#define __board_data_H

/* ---- Publicly visible Macros ---------------------------------------- */

/* ---- LED Definitions for the STM32F3Discovery Board --------- */
#define BRD_LED_BLUE_SE                                 0
#define BRD_LED_RED_S                                   1
#define BRD_LED_ORANGE_SW                               2
#define BRD_LED_GREEN_W                                 3
#define BRD_LED_BLUE_NW                                 4
#define BRD_LED_RED_N                                   5
#define BRD_LED_ORANGE_NE                               6
#define BRD_LED_GREEN_E                                 7

#define BRD_LED_HEARTBEAT                               (BRD_LED_GREEN_E)
#define BRD_LED_PANIC                                   (BRD_LED_RED_S)
#define BRD_LED_USB_STAT                                (BRD_LED_GREEN_W)
/* ------------------------------------------------------------- */




/* ---- Publicly visible Variables and Constants ----------------------- */

/* ---- Publicly visible Functions ------------------------------------- */


#endif /* __board_data_H */
