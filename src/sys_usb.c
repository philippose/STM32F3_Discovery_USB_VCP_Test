/**
 ******************************************************************************
 * @file    sys_usb.c
 * @author  Philippose Rajan
 * @date    25.11.2013
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

/* ---- Includes --------------------------------------------------------- */
#include "globals.h"
#include "usb_lib.h"
#include "usb_prop.h"
#include "usb_desc.h"
#include "usb_pwr.h"

/* ---- Externally visible Variables ------------------------------------- */
__IO uint8_t recieveBuffer[VIRTUAL_COM_PORT_DATA_SIZE];
__IO uint32_t receiveLength;

/* ---- Externally visible Functions ------------------------------------- */
void Sys_USB_Init(void);

void Set_Packet_Sent(uint8_t state);

bool Packet_Sent(void);

void Set_Packet_Received(uint8_t state);

bool Packet_Received(void);

uint32_t CDC_Send_DATA (uint8_t *ptrBuffer, uint8_t Send_length);

uint32_t CDC_Receive_DATA(void);

/* ---- Local Variables -------------------------------------------------- */
static uint8_t packetSent = 1;
static uint8_t packetReceived = 1;

/* ---- Local Functions -------------------------------------------------- */

/* ----------------------------------------------------------------------- */

void Sys_USB_Init(void)
{
    /* ---- Setup the GPIO Pins for the USB Subsystem -------------------- */
    {
        static GPIO_InitTypeDef GPIO_InitStructure;

        /*Set PA11,12 as IN - USB_DM,DP*/
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
        GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
        GPIO_Init(GPIOA, &GPIO_InitStructure);

        /*SET PA11,12 for USB: USB_DM,DP*/
        GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_14);
        GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_14);
    }
    /* ------------------------------------------------------------------- */

    /* ---- Setup the Interrupt Line used by the USB API ----------------- */
    {
        static EXTI_InitTypeDef EXTI_InitStructure;

        /* Configure the EXTI line 18 connected internally to the USB IP */
        EXTI_ClearITPendingBit(EXTI_Line18);
        EXTI_InitStructure.EXTI_Line = EXTI_Line18;
        EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
        EXTI_InitStructure.EXTI_LineCmd = ENABLE;
        EXTI_Init(&EXTI_InitStructure);
    }
    /* ------------------------------------------------------------------- */

    /* ---- Setup the USB Clock to 48 MHz -------------------------------- */
    /* Select USBCLK source */
    RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_1Div5);

    /* Enable the USB clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USB, ENABLE);
    /* ------------------------------------------------------------------- */

    /* ---- Setup the Interrupt Priorities for the USB Subsystem --------- */
    {
        static NVIC_InitTypeDef NVIC_InitStructure;

        /* Enable the USB interrupt */
        NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = SYS_IRQ_PRIO_LOW;
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
        NVIC_Init(&NVIC_InitStructure);

        /* Enable the USB Wake-up interrupt */
        NVIC_InitStructure.NVIC_IRQChannel = USBWakeUp_IRQn;
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = SYS_IRQ_PRIO_HIGH;
        NVIC_Init(&NVIC_InitStructure);
    }
    /* ------------------------------------------------------------------- */

    USB_Init();
}



void Set_Packet_Sent(uint8_t state)
{
    packetSent = (state == 0 ? 0 : 1);
}



bool Packet_Sent(void)
{
    return (packetSent == 0 ? 0 : 1);
}



void Set_Packet_Received(uint8_t state)
{
    packetReceived = (state == 0 ? 0 : 1);
}



bool Packet_Received(void)
{
    return (packetReceived == 0 ? 0 : 1);
}



/*******************************************************************************
 * Function Name  : Send DATA .
 * Description    : send the data received from the STM32 to the PC through USB
 * Input          : None.
 * Output         : None.
 * Return         : None.
 *******************************************************************************/
uint32_t CDC_Send_DATA (uint8_t *ptrBuffer, uint8_t sendLength)
{
    /*if max buffer is Not reached*/
    if(sendLength < VIRTUAL_COM_PORT_DATA_SIZE)
    {
        /*Sent flag*/
        Set_Packet_Sent(0);

        /* send  packet to PMA*/
        UserToPMABufferCopy((unsigned char*)ptrBuffer, ENDP1_TXADDR, sendLength);
        SetEPTxCount(ENDP1, sendLength);
        SetEPTxValid(ENDP1);
    }
    else
    {
        return 0;
    }

    return 1;
}



/*******************************************************************************
 * Function Name  : Receive DATA .
 * Description    : receive the data from the PC to STM32 and send it through USB
 * Input          : None.
 * Output         : None.
 * Return         : None.
 *******************************************************************************/
uint32_t CDC_Receive_DATA(void)
{
    /*Receive flag*/
    Set_Packet_Received(0);

    /* Validate the Endpoint to indicate readiness to receive */
    SetEPRxValid(ENDP3);

    return 1 ;
}
