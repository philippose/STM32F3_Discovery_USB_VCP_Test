/**
 ******************************************************************************
 * @file    STM32F30x_MemLayout.ld
 * @author  Philippose Rajan
 * @date    10-November-2013
 * @brief   Memory Layout Specifications
 * 
 *          This script is set up for the following configuration:
 *			(Controller: STM32F3VCT6)
 *			- FLASH: 	256 KB
 *			- RAM:		40 KB
 *			- CCMRAM:	8 KB
 *
 * @see	    The GNU Public License (GPL) Version 3
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
 

/* Specify the memory areas */
/* For Memory Map Ref.: STM32F3 Series Reference Manual DM00043574 */
MEMORY
{
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 256K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 40K
  CCMRAM (rw)     : ORIGIN = 0x10000000, LENGTH = 8K
}


