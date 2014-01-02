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
#include "usb_desc.h"

/* ---- Externally visible Variables ------------------------------------- */
__IO uint8_t recieveBuffer[VIRTUAL_COM_PORT_DATA_SIZE];
__IO uint32_t receiveLength;

/* ---- Externally visible Functions ------------------------------------- */
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
