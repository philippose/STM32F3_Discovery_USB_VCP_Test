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

#ifndef GLOBALS_H_
#define GLOBALS_H_

/* ---- Commonly required Includes -------------------------------------- */
#include "hw_config.h"

/* ---- Global Defines and Macros --------------------------------------- */
typedef enum GLOB_ERR
{
    ERR_OK              = 0,
    ERR_INV_PARAM       = 10,
    ERR_INIT_FAILED     = 20
} Type_Err;

/* ---- Global Variables ------------------------------------------------ */

/* ---- Global Functions ------------------------------------------------ */

#endif /* GLOBALS_H_ */
