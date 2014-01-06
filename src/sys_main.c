/**
 ******************************************************************************
 * @file    sys_main.c
 * @author  Philippose Rajan
 * @date    06.01.2014
 * @brief   Main Initialisation routines for the base system comes here
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
#include "usb_pwr.h"

/* Note: This file is required to be included because of the constant variable
 * declarations it contains
 */
#include "board_setup.c"

/* ---- Externally visible Variables ------------------------------------- */

/* ---- Externally visible Functions ------------------------------------- */
/**
 * @brief       This function carries out the basic initialisation routines before jumping
 *              into the application
 * @param       None
 * @return      None
 *
 */
void Sys_Init(void);

/**
 * @brief       This function carries out the initialisation of the Subsystems before jumping
 *              into the application
 * @param       None
 * @return      None
 *
 */
void Sys_Board_Init(void);



/* ---- Local Variables -------------------------------------------------- */

/* ---- Local Functions -------------------------------------------------- */

/* ----------------------------------------------------------------------- */

void Sys_Init(void)
{
    /* ---- ****** NOTE ****** ------------------------------------------- */
    /* At this point, the function **SystemInit** has already been run from the Startup file */
    /* ------------------------------------------------------------------- */

    /* Continue the Initialisation of the system from here.... */
    SystemCoreClockUpdate();

    /* Setup the interrupt settings as per the requirements of FreeRTOS */
    NVIC_Configuration();

    /* Setup the basic system - peripherals, I/O Pins to default, etc... */
    /* Enable all the relevant peripheral clocks */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 |
                           RCC_APB1Periph_TIM3 |
                           RCC_APB1Periph_TIM4 |
                           RCC_APB1Periph_TIM6 |
                           RCC_APB1Periph_TIM7 |
                           RCC_APB1Periph_WWDG |
                           RCC_APB1Periph_SPI2 |
                           RCC_APB1Periph_SPI3 |
                           RCC_APB1Periph_USART2 |
                           RCC_APB1Periph_USART3 |
                           RCC_APB1Periph_UART4 |
                           RCC_APB1Periph_UART5 |
                           RCC_APB1Periph_I2C1 |
                           RCC_APB1Periph_I2C2 |
                           RCC_APB1Periph_USB |
                           RCC_APB1Periph_CAN1 |
                           RCC_APB1Periph_PWR |
                           RCC_APB1Periph_DAC |
                           0, ENABLE);


    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 |
                           RCC_APB2Periph_TIM8 |
                           RCC_APB2Periph_TIM15 |
                           RCC_APB2Periph_TIM16 |
                           RCC_APB2Periph_TIM17 |
                           RCC_APB2Periph_USART1 |
                           RCC_APB2Periph_SPI1 |
                           RCC_APB2Periph_SYSCFG |
                           0, ENABLE);


    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA |
                          RCC_AHBPeriph_GPIOB |
                          RCC_AHBPeriph_GPIOC |
                          RCC_AHBPeriph_GPIOD |
                          RCC_AHBPeriph_GPIOE |
                          RCC_AHBPeriph_GPIOF |
                          RCC_AHBPeriph_TS |
                          RCC_AHBPeriph_CRC |
                          RCC_AHBPeriph_FLITF |
                          RCC_AHBPeriph_SRAM |
                          RCC_AHBPeriph_DMA2 |
                          RCC_AHBPeriph_DMA1 |
                          RCC_AHBPeriph_ADC34 |
                          RCC_AHBPeriph_ADC12 |
                          0, ENABLE);


    /* Setup the I/O Pins to all inputs, except for the USB and JTAG pins */
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_StructInit(&GPIO_InitStructure);
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;

    /* Remove the USB and JTAG Pins from the list */
    GPIO_InitStructure.GPIO_Pin &= ~(GPIO_Pin_11 | GPIO_Pin_12);
    GPIO_InitStructure.GPIO_Pin &= ~(GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);

    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    GPIO_Init(GPIOF, &GPIO_InitStructure);


    /* Initialise the Panic LED independent of the initialisation task which comes later */
    /* NOTE: This is a hack which needs to be solved in a better way!!! */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);


    /* Initialise the Delay Subsystem */
    Util_Delay_Init();
}



void Sys_Board_Init(void)
{
    /* ---- Setup the LEDs on the Board ---------------------------------- */
    const struct Sys_LED_Cfg *ledCfg = &brdLEDCfg;
    SYS_ASSERT(ledCfg);
    Sys_LED_Init(ledCfg);
    /* ------------------------------------------------------------------- */

    /* Now setup the User Button to generate an Interrupt */
    STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);

    /* Setup the USB Subsystem */
    USB_Pins_Config();
    Set_USBClock();
    USB_Interrupts_Config();
    USB_Init();
}

