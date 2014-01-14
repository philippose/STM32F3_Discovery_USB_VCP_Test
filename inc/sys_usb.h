/**
 ******************************************************************************
 * @file    sys_usb.h
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

#ifndef __SYS_USB_H
#define __SYS_USB_H

/* ---- Publicly visible Macros ---------------------------------------- */

/* ---- Publicly visible Variables and Constants ----------------------- */
extern __IO uint8_t recieveBuffer[VIRTUAL_COM_PORT_DATA_SIZE];
extern __IO  uint32_t receiveLength ;

/* ---- Publicly visible Functions ------------------------------------- */
extern void Sys_USB_Init(void);

extern void Set_Packet_Sent(uint8_t state);

extern bool Packet_Sent(void);

extern void Set_Packet_Received(uint8_t state);

extern bool Packet_Received(void);

extern uint32_t CDC_Send_DATA (uint8_t *ptrBuffer, uint8_t sendLength);

extern uint32_t CDC_Receive_DATA(void);


#endif /* __SYS_USB_H */
