/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MCF52259CAG80
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior MCF C Compiler
**     Date/Time   : 2013-10-26, 10:23, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "LED2.h"
#include "LEDpin2.h"
#include "LED3.h"
#include "LEDpin3.h"
#include "LED4.h"
#include "LEDpin4.h"
#include "WAIT1.h"
#include "UTIL1.h"
#include "USB1.h"
#include "USBInit1.h"
#include "CDC1.h"
#include "Tx1.h"
#include "Rx1.h"
#include "CS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
static uint8_t cdc_buffer[USB1_DATA_BUFF_SIZE];
static uint8_t in_buffer[USB1_DATA_BUFF_SIZE];
#if 0
static void CDC_Run(void) {
  int i, cnt = 0;
  uint32_t val = 0;
  unsigned char buf[16];

  (void)CDC1_SendString((unsigned char*)"Hello world from the KL25Z with USB CDC\r\n");
  for(;;) {
    while(CDC1_App_Task(cdc_buffer, sizeof(cdc_buffer))==ERR_BUSOFF) {
      /* device not enumerated */
      LED1_Neg(); LED2_Off();
      WAIT1_Waitms(10);
      cnt++;
      if (cnt==100) {
        LED3_Neg();
        cnt = 0;
      }
    }
    LED1_Off(); LED2_Neg(); LED3_Off();
    if (CDC1_GetCharsInRxBuf()!=0) {
      i = 0;
      while(   i<sizeof(in_buffer)-1
            && CDC1_GetChar(&in_buffer[i])==ERR_OK
           )
      {
        i++;
      }
      in_buffer[i] = '\0';
      (void)CDC1_SendString((unsigned char*)"echo: ");
      (void)CDC1_SendString(in_buffer);
      UTIL1_strcpy(buf, sizeof(buf), (unsigned char*)"val: ");
      UTIL1_strcatNum32u(buf, sizeof(buf), val);
      UTIL1_strcat(buf, sizeof(buf), (unsigned char*)"\r\n");
      (void)CDC1_SendString(buf);
      val++;
    } else {
      WAIT1_Waitms(10);
      cnt++;
      if ((cnt%1024)==0) { /* from time to time, write some text */
        (void)CDC1_SendString((unsigned char*)"Type some text and it will echo.\r\n");
      }
    }
  }
}
#endif

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  LED1_Neg();
  WAIT1_Waitms(200);
  LED2_Neg();
  WAIT1_Waitms(200);
  LED3_Neg();
  WAIT1_Waitms(200);
  LED4_Neg();
  WAIT1_Waitms(200);

 // CDC_Run();

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale MCF series of microcontrollers.
**
** ###################################################################
*/
