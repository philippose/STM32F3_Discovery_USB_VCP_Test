/**
 ******************************************************************************
 * @file    stm32f30x_it.c
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

/* ---- Includes --------------------------------------------------------- */
#include "globals.h"

#include "util_delay.h"
#include "usb_istr.h"

/* ---- Externally visible Variables ------------------------------------- */

/* ---- Externally visible Functions ------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void DebugMon_Handler(void);

// void SVC_Handler(void);      /* Handled by FreeRTOS */
// void PendSV_Handler(void);   /* Handled by FreeRTOS */
// void SysTick_Handler(void);  /* Handled by FreeRTOS */

void EXTI0_IRQHandler(void);

void USB_LP_CAN1_RX0_IRQHandler(void);
void USBWakeUp_IRQHandler(void);

/* ---- Local Variables -------------------------------------------------- */

/* ---- Local Functions -------------------------------------------------- */

/* ----------------------------------------------------------------------- */
extern __IO uint8_t userButtonState;


/******************************************************************************/
/*            Cortex-M Processor Exceptions Handlers                         */
/******************************************************************************/

/*******************************************************************************
 * Function Name  : NMI_Handler
 * Description    : This function handles NMI exception.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void NMI_Handler(void)
{
}

/*******************************************************************************
 * Function Name  : HardFault_Handler
 * Description    : This function handles Hard Fault exception.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void HardFault_Handler(void)
{
    /* Go to infinite loop when Hard Fault exception occurs */
    while (1)
    {
    }
}

/*******************************************************************************
 * Function Name  : MemManage_Handler
 * Description    : This function handles Memory Manage exception.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void MemManage_Handler(void)
{
    /* Go to infinite loop when Memory Manage exception occurs */
    while (1)
    {
    }
}

/*******************************************************************************
 * Function Name  : BusFault_Handler
 * Description    : This function handles Bus Fault exception.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void BusFault_Handler(void)
{
    /* Go to infinite loop when Bus Fault exception occurs */
    while (1)
    {
    }
}

/*******************************************************************************
 * Function Name  : UsageFault_Handler
 * Description    : This function handles Usage Fault exception.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void UsageFault_Handler(void)
{
    /* Go to infinite loop when Usage Fault exception occurs */
    while (1)
    {
    }
}

/*******************************************************************************
 * Function Name  : SVC_Handler
 * Description    : This function handles SVCall exception.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
/*
void SVC_Handler(void)
{
}
*/

/*******************************************************************************
 * Function Name  : DebugMon_Handler
 * Description    : This function handles Debug Monitor exception.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void DebugMon_Handler(void)
{
}

/*******************************************************************************
 * Function Name  : PendSV_Handler
 * Description    : This function handles PendSVC exception.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
/*
void PendSV_Handler(void)
{
}
*/

/*******************************************************************************
 * Function Name  : SysTick_Handler
 * Description    : This function handles SysTick Handler.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
/*
void SysTick_Handler(void)
{
}
*/

/*******************************************************************************
 * Function Name  : EXTI0_IRQHandler
 * Description    : This function handles the External EXTI0 Interrupt
 *                  requests.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void EXTI0_IRQHandler(void)
{
    if((EXTI_GetITStatus(USER_BUTTON_EXTI_LINE) == SET) && (STM_EVAL_PBGetState(BUTTON_USER) != RESET))
    {
        /* The delays are used to prevent multiple triggering of the interrupt
         * due to contact bounce on the switch */
        Util_Delay_ms(50);
        while(STM_EVAL_PBGetState(BUTTON_USER) != RESET);

        userButtonState++;

        if(userButtonState >= 2) userButtonState = 0;

        /* Now clear the Interrupt Pending bit so that it can be triggered again */
        EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
    }
}


/*******************************************************************************
 * Function Name  : USB_IRQHandler
 * Description    : This function handles USB Low Priority interrupts
 *                  requests.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void USB_LP_CAN1_RX0_IRQHandler(void)
{
    USB_Istr();
}

/*******************************************************************************
 * Function Name  : USB_FS_WKUP_IRQHandler
 * Description    : This function handles USB WakeUp interrupt request.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
void USBWakeUp_IRQHandler(void)
{
    EXTI_ClearITPendingBit(EXTI_Line18);
}

/******************************************************************************/
/*                 STM32 Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32xxx.s).                                            */
/******************************************************************************/

/*******************************************************************************
 * Function Name  : PPP_IRQHandler
 * Description    : This function handles PPP interrupt request.
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
/*void PPP_IRQHandler(void)
{
}*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

