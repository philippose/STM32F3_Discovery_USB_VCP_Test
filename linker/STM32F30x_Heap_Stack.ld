/**
 ******************************************************************************
 * @file    STM32F30x_Heap_Stack.ld
 * @author  Philippose Rajan
 * @date    10-November-2013
 * @brief   Heap and Stack Size Specifications for the STM32F30x series
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
 

/* Verify that the heap and stack fit into the RAM */
/* Required Heap size */
_Heap_Size = 0x0;      

/* Required Stack size */
_Stack_Size = 0x200; 

