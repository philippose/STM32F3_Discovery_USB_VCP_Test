/**
 ******************************************************************************
 * @file    stm32f30x_it.h
 * @author  Philippose Rajan
 * @date    17.11.2013
 * @brief   STM32F30x Interrupt Service Routines
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


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32_IT_H
#define __STM32_IT_H

/* ---- Publicly visible Macros ---------------------------------------- */

/* ---- Publicly visible Variables ------------------------------------- */

/* ---- Publicly visible functions ------------------------------------- */

extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void MemManage_Handler(void);
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void DebugMon_Handler(void);

// extern void SVC_Handler(void);      /* Handled by FreeRTOS */
// extern void PendSV_Handler(void);   /* Handled by FreeRTOS */
// extern void SysTick_Handler(void);  /* Handled by FreeRTOS */

extern void EXTI0_IRQHandler(void);

extern void USB_LP_CAN1_RX0_IRQHandler(void);
extern void USBWakeUp_IRQHandler(void);

#endif /* __STM32_IT_H */

