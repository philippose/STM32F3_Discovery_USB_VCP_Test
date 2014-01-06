/**
 ******************************************************************************
 * @file    globals.h
 * @author  Philippose Rajan
 * @date    17.11.2013
 * @brief   Global includes, exports, variables, etc...
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

#ifndef __GLOBALS_H
#define __GLOBALS_H

/* ---- Commonly required Includes -------------------------------------- */
#include "board_data.h"
#include "sys_types.h"
#include "hw_config.h"

/* ---- Subsystems to be included --------------------------------------- */
#include "util_delay.h"
#include "util_led.h"
#include "sys_usb.h"

/* ---- FreeRTOS related includes --------------------------------------- */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"


/* ---- Global Defines and Macros --------------------------------------- */
#define SYS_ASSERT(x) if(!(x)) while(1)
#define NELEMENTS(x) (sizeof(x) / sizeof(*(x)))

#define SYSTICK_PERIOD          10      /*! Systick period [in ms] */
#define HEARTBEAT_PERIOD        (1000)    /* Heart Beat Period [in ms] */

/* ---- Global Variables ------------------------------------------------ */

/* ---- Global Functions ------------------------------------------------ */

#endif /* __GLOBALS_H */
