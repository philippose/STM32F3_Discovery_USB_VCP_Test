/**
 ******************************************************************************
 * @file    sys_types.h
 * @author  Philippose Rajan
 * @date    24.11.2013
 * @brief   Custom Data types which need to be visible throughout the application
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

#ifndef __SYS_TYPES_H
#define __SYS_TYPES_H

/* ---- Publicly visible Macros ---------------------------------------- */
typedef enum Type_Err
{
    ERR_OK              = 0,
    ERR_INV_PARAM       = 10,
    ERR_INIT_FAILED     = 20
} Type_Err;

/* ---- Publicly visible Variables and Constants ----------------------- */

/* ---- Publicly visible Functions ------------------------------------- */


#endif /* __SYS_TYPES_H */
