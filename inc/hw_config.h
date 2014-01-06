/**
  ******************************************************************************
  * @file    hw_config.h
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Hardware Configuration & Setup
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

#ifndef __HW_CONFIG_H
#define __HW_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f30x.h"
#include "stm32f30x_conf.h"
#include "stm32f30x_uid.h"
#include "stm32f3_discovery.h"

#include "usb_type.h"
#include "usb_desc.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* ---- Define the internal IRQ priorities - Important for FreeRTOS --------- */
#define SYS_IRQ_PRIO_HIGHEST                  4
#define SYS_IRQ_PRIO_HIGH                     5
#define SYS_IRQ_PRIO_MID                      8
#define SYS_IRQ_PRIO_LOW                      12
/* -------------------------------------------------------------------------- */

#ifdef STM32F30X
  #define USB_DISCONNECT                      GPIOE
  #define USB_DISCONNECT_PIN                  GPIO_Pin_14

  #define RCC_AHBPeriph_GPIO_DISCONNECT       RCC_AHBPeriph_GPIOE
#endif /* STM32F30X */

/* Exported macro ------------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */
void Enter_LowPowerMode(void);
void Leave_LowPowerMode(void);

void NVIC_Configuration(void);


void Set_USBClock(void);
void USB_Pins_Config(void);
void USB_Interrupts_Config(void);
void USB_Cable_Config (FunctionalState NewState);

void Get_SerialNum(void);

/* External variables --------------------------------------------------------*/

#endif  /*__HW_CONFIG_H*/
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
