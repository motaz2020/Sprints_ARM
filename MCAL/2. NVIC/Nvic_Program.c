/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Nvic_Program.c
 *        \brief  Nested Vector Interrupt Control
 *
 *      \details  The Driver Configure All MCU interrupts for its specific usage
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Common_Macros.h"
#include "Nvic_Interface.h"
#include "Nvic_Private.h"

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
* \Syntax          : void Nvic_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Nvic_Init(void)
{
    /* Enable 16/32-Bit Timer0 interrupt */
    NVIC_EN0_R |= 0x80000;
}


/**********************************************************************************************************************
 *  END OF FILE: Nvic_Program.c
 *********************************************************************************************************************/
