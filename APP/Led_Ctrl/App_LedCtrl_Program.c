/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  App_ledCtrl_Program.c
 *        \brief  Controling the application functions
 *
 *      \details  Contains all application layer functions used
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "App_LedCtrl_Interface.h"
#include "Led_Interface.h"
#include "Gpio_Interface.h"
#include "Gpt_Interface.h"
#include "Gpt_Private.h"
#include "Nvic_Interface.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void LedCtrl_Init(void)                                      
* \Description     : initialize all drivers used in led control operation                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LedCtrl_Init(void)
{
    GPT_ConfigType Timer0Cfg = {TIMER0, 12500, 0xFFFFFFFF, CONTINUOUS};

    Gpt_Init(&Timer0Cfg);
    Gpt_DisableIntNotification(TIMER0);
   /* Gpt_StartTimer(TIMER0, 65000); */

    Nvic_Init();

    Gpio_InitChannel(PORTF_ID, PIN1_ID, PIN_OUTPUT, NO_PULL);
    Led_OpType(PORTF_ID, PIN1_ID, STD_HIGH);
}

/******************************************************************************
* \Syntax          : void LedCtrl_PWMBlink(uint16 OnCounts,uint16 OffCounts)                                    
* \Description     : responsible for the PWM effect in the led operation control                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : OnCounts - Number of counts for the "LED On" operation
                     OffCounts - Number of counts for the "LED Off" operation                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void LedCtrl_PwmBlink(uint16 OnCounts,uint16 OffCounts)
{
    Led_OpType(PORTF_ID, PIN1_ID, STD_LOW);
	Gpt_StartTimer(TIMER0, OnCounts);

    Led_OpType(PORTF_ID, PIN1_ID, STD_HIGH);
    Gpt_StartTimer(TIMER0, OffCounts);

	// if((TIMER0_TAV_R >> 7) < OnCounts)
    // {
	//     Led_OpType(PORTF_ID, PIN1_ID, STD_HIGH);
	// }
    // else if((TIMER0_TAV_R >> 7) > OffCounts)
    // {
	// 	Led_OpType(PORTF_ID, PIN1_ID, STD_LOW);	
	// }
	
}

/**********************************************************************************************************************
 *  END OF FILE: App_ledCtrl_Program.c
 *********************************************************************************************************************/
