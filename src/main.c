/**
  ******************************************************************************
  * @file    main.c
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Virtual Com Port Demo main file
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


/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
RCC_ClocksTypeDef RCC_Clocks;
__IO uint32_t TimingDelay = 0;
/* Extern variables ----------------------------------------------------------*/
extern __IO uint8_t Receive_Buffer[64];
extern __IO  uint32_t Receive_length ;
extern __IO  uint32_t length ;
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

  /* Set the SysTick to interrupt at 100 ms intervals */
  SysTick_Config(RCC_Clocks.HCLK_Frequency / 100);


  Set_System();
  Set_USBClock();
  USB_Interrupts_Config();
  USB_Init();
  
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);
  STM_EVAL_LEDInit(LED7);
  STM_EVAL_LEDInit(LED8);
  STM_EVAL_LEDInit(LED9);
  STM_EVAL_LEDInit(LED10);


  while (1)
  {
    if (bDeviceState == CONFIGURED)
    {
      CDC_Receive_DATA();
      /*Check to see if we have data yet */
      if (Receive_length  != 0)
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
    	Delay(5);

        if (packet_sent == 1)
          CDC_Send_DATA ((unsigned char*)Receive_Buffer,Receive_length);
        Receive_length = 0;
      }
    }
    else
    {
        /* Toggle LD3 */
        STM_EVAL_LEDToggle(LED3);
        /* Insert 50 ms delay */
        Delay(5);
        /* Toggle LD5 */
        STM_EVAL_LEDToggle(LED5);
        /* Insert 50 ms delay */
        Delay(5);
        /* Toggle LD7 */
        STM_EVAL_LEDToggle(LED7);
        /* Insert 50 ms delay */
        Delay(5);
        /* Toggle LD9 */
        STM_EVAL_LEDToggle(LED9);
        /* Insert 50 ms delay */
        Delay(5);
        /* Toggle LD10 */
        STM_EVAL_LEDToggle(LED10);
        /* Insert 50 ms delay */
        Delay(5);
        /* Toggle LD8 */
        STM_EVAL_LEDToggle(LED8);
        /* Insert 50 ms delay */
        Delay(5);
        /* Toggle LD6 */
        STM_EVAL_LEDToggle(LED6);
        /* Insert 50 ms delay */
        Delay(5);
        /* Toggle LD4 */
        STM_EVAL_LEDToggle(LED4);
        /* Insert 50 ms delay */
        Delay(5);
    }
  }
} 


/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
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
