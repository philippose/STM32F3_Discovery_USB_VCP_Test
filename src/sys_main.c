/**
 ******************************************************************************
 * @file    sys_main.c
 * @author  Philippose Rajan
 * @date    17.11.2013
 * @brief   Primary file containing the main function
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


/* Includes ------------------------------------------------------------------*/
#include <stdio.h>

#include "globals.h"

#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_pwr.h"

#include "util_delay.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
RCC_ClocksTypeDef RCC_Clocks;

__IO uint8_t userButtonState;

/* Extern variables ----------------------------------------------------------*/
extern __IO uint8_t Receive_Buffer[64];
extern __IO  uint32_t Receive_length ;

__IO  uint32_t length ;
uint8_t Send_Buffer[64];
uint32_t packet_sent=1;
uint32_t packet_receive=1;


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
 * Function Name  : main.
 * Descriptioan    : Main routine.
 * Input          : None.
 * Output         : None.
 * Return         : None.
 *******************************************************************************/
int main(void)
{
    bool LEDSwitchedOff = FALSE;

    RCC_GetClocksFreq(&RCC_Clocks);

    /* Set the SysTick to interrupt at 10 ms intervals */
    SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);

    /* Setup the basic system */
    Set_System();
    Set_USBClock();

    /* Initialise the USB Subsystem */
    USB_Interrupts_Config();
    USB_Init();

    /* Initialise the Delay Subsystem */
    Util_Delay_Init();

    /* STM32F3 Discovery specific initialisation routine */
    STM_EVAL_LEDInit(LED3);
    STM_EVAL_LEDInit(LED4);
    STM_EVAL_LEDInit(LED5);
    STM_EVAL_LEDInit(LED6);
    STM_EVAL_LEDInit(LED7);
    STM_EVAL_LEDInit(LED8);
    STM_EVAL_LEDInit(LED9);
    STM_EVAL_LEDInit(LED10);


    /* Initialise the User Button State to 0 */
    userButtonState = 0x00;

    /* Now setup the User Button to generate an Interrupt */
    STM_EVAL_PBInit(BUTTON_USER, BUTTON_MODE_EXTI);

    length = sprintf(Send_Buffer, "%f\r\n", 3.141592);
    /* length = strlen(Send_Buffer); */

    while (1)
    {
        if (bDeviceState == CONFIGURED)
        {
            CDC_Receive_DATA();
            /*Check to see if we have data yet */
            //if (Receive_length  != 0)
            if(userButtonState > 0)
            {
                if(!LEDSwitchedOff)
                {
                    STM_EVAL_LEDOff(LED4);
                    STM_EVAL_LEDOff(LED5);
                    STM_EVAL_LEDOff(LED6);
                    STM_EVAL_LEDOff(LED7);
                    STM_EVAL_LEDOff(LED8);
                    STM_EVAL_LEDOff(LED9);
                    STM_EVAL_LEDOff(LED3);
                    LEDSwitchedOff = TRUE;
                }

                STM_EVAL_LEDToggle(LED10);
                Util_Delay_ms(50);

                if (packet_sent == 1)
                {
                    CDC_Send_DATA ((unsigned char*)Send_Buffer,length);
                    userButtonState = 0;
                }

                Receive_length = 0;
            }
        }
        else
        {
            /* Toggle LD3 */
            STM_EVAL_LEDToggle(LED3);
            /* Insert 50 ms delay */
            Util_Delay_ms(50);
            /* Toggle LD5 */
            STM_EVAL_LEDToggle(LED5);
            /* Insert 50 ms delay */
            Util_Delay_ms(50);
            /* Toggle LD7 */
            STM_EVAL_LEDToggle(LED7);
            /* Insert 50 ms delay */
            Util_Delay_ms(50);
            /* Toggle LD9 */
            STM_EVAL_LEDToggle(LED9);
            /* Insert 50 ms delay */
            Util_Delay_ms(50);
            /* Toggle LD10 */
            STM_EVAL_LEDToggle(LED10);
            /* Insert 50 ms delay */
            Util_Delay_ms(50);
            /* Toggle LD8 */
            STM_EVAL_LEDToggle(LED8);
            /* Insert 50 ms delay */
            Util_Delay_ms(50);
            /* Toggle LD6 */
            STM_EVAL_LEDToggle(LED6);
            /* Insert 50 ms delay */
            Util_Delay_ms(50);
            /* Toggle LD4 */
            STM_EVAL_LEDToggle(LED4);
            /* Insert 50 ms delay */
            Util_Delay_ms(50);
        }
    }
} 





#ifdef USE_FULL_ASSERT
/*******************************************************************************
 * Function Name  : assert_failed
 * Description    : Reports the name of the source file and the source line number
 *                  where the assert_param error has occurred.
 * Input          : - file: pointer to the source file name
 *                  - line: assert_param error line source number
 * Output         : None
 * Return         : None
 *******************************************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {}
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
