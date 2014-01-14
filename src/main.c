/**
 ******************************************************************************
 * @file    main.c
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
#include "sys_main.h"

#include "usb_lib.h"
#include "usb_pwr.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint8_t userButtonState;

/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/


/* ---- Parameters for the Initialisation Task ------------------------------ */
#define STACK_SUBSYS_INIT       (200)
#define PRIORITY_SUBSYS_INIT    (tskIDLE_PRIORITY + configMAX_PRIORITIES - 1)
portTASK_FUNCTION_PROTO(taskSubSysInit, pvParameters);
xTaskHandle hndSubSysInit;
/* -------------------------------------------------------------------------- */

/* ---- Parameters for the Dummy Receiver Task ------------------------------ */
#define STACK_DUMMY_RECV        (configMINIMAL_STACK_SIZE)
#define PRIORITY_DUMMY_RECV     (tskIDLE_PRIORITY + 3)
portTASK_FUNCTION_PROTO(taskDummyReceiver, pvParameters);
xTaskHandle hndDummyReceiver;
/* -------------------------------------------------------------------------- */

/* ---- Parameters for the Task transmitting data --------------------------- */
#define STACK_USB_DATA_TX       (configMINIMAL_STACK_SIZE)
#define PRIORITY_USB_DATA_TX    (tskIDLE_PRIORITY + 3)
portTASK_FUNCTION_PROTO(taskUSBDataTx, pvParameters);
xTaskHandle hndUSBDataTx;
/* -------------------------------------------------------------------------- */

/* ---- Parameters for the Heartbeat Task ----------------------------------- */
#define STACK_HEARTBEAT         (configMINIMAL_STACK_SIZE)
#define PRIORITY_HEARTBEAT      (tskIDLE_PRIORITY + 3)
portTASK_FUNCTION_PROTO(taskHeartBeat, pvParameters);
xTaskHandle hndHeartBeat;
/* -------------------------------------------------------------------------- */

/* Private functions ---------------------------------------------------------*/

/**
 * @brief       The main function for the Application
 * @param       None
 * @return      None
 */
int main(void)
{
    int32_t result;

    /* Initialise the User Button State to 0 */
    userButtonState = 0x00;

    /* Basic System initialisation */
    Sys_Init();

    /* The rest of the initialisation is performed within a FreeRTOS task to allow
     * the scheduler to start up without and problems
     */
    result = xTaskCreate(taskSubSysInit, (const signed char *)"Init", STACK_SUBSYS_INIT, NULL, PRIORITY_SUBSYS_INIT, &hndSubSysInit);

    SYS_ASSERT(result == pdPASS);

    /* Start the FreeRTOS Task Scheduler*/
    vTaskStartScheduler();



    /* --- If all goes well, does not get here --- */
    while(1)
    {
        GPIOE->ODR ^= GPIO_Pin_13;
        for(int i = 0; i < 1000000; i++);
    }
} 



portTASK_FUNCTION(taskSubSysInit, pvParameters)
{
    uint32_t result;

    /* Initialise the various Sub-Systems */
    Sys_Board_Init();

    result = xTaskCreate(taskHeartBeat, (const signed char *)"Heart Beat", STACK_HEARTBEAT, NULL, PRIORITY_HEARTBEAT, &hndHeartBeat);
    SYS_ASSERT(result == pdPASS);

    result = xTaskCreate(taskDummyReceiver, (const signed char *)"Dummy USB Receiver", STACK_DUMMY_RECV, NULL, PRIORITY_DUMMY_RECV, &hndDummyReceiver);
    SYS_ASSERT(result == pdPASS);

    result = xTaskCreate(taskUSBDataTx, (const signed char *)"USB Data Tx", STACK_USB_DATA_TX, NULL, PRIORITY_USB_DATA_TX, &hndUSBDataTx);
    SYS_ASSERT(result == pdPASS);

    /* Terminate this task once all the initialisation is done */
    vTaskDelete(NULL);
}



portTASK_FUNCTION(taskHeartBeat, pvParameters)
{
    portTickType nextHeartBeatTime;

    Util_LED_Off(BRD_LED_HEARTBEAT);
    // STM_EVAL_LEDOff(LED10);

    nextHeartBeatTime = xTaskGetTickCount();

    for(;;)
    {
        vTaskDelayUntil(&nextHeartBeatTime, HEARTBEAT_PERIOD / portTICK_RATE_MS);

        Util_LED_Toggle(BRD_LED_HEARTBEAT);
        //STM_EVAL_LEDToggle(LED10);
    }
}



portTASK_FUNCTION(taskDummyReceiver, pvParameters)
{
    for(;;)
    {
        if(bDeviceState == CONFIGURED)
        {
            if(Packet_Received())
            {
                CDC_Receive_DATA();
                Set_Packet_Received(0);
                receiveLength = 0;
            }
        }
    }
}



portTASK_FUNCTION(taskUSBDataTx, pvParameters)
{
    portTickType nextRunTime;

    Util_LED_Off(BRD_LED_USB_STAT);
    //STM_EVAL_LEDOff(LED7);

    nextRunTime = xTaskGetTickCount();

    for(;;)
    {
        vTaskDelayUntil(&nextRunTime, 500 / portTICK_RATE_MS);

        Util_LED_Toggle(BRD_LED_USB_STAT);
        //STM_EVAL_LEDToggle(LED7);
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
