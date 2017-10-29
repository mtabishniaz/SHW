#if !defined(RXSUBSYSTEM_H)
#define RXSUBSYSTEM_H

/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "dlm.h"

#include <stdint.h>

void INIT_RX_SUBSYSTEM(void);
CY_ISR(ISR_HEADER_READ_h);


uint16 adcValue;

uint8 rxModLevel;
uint16 rxLength;
int16 rxTrackSum;
uint8 rxSrc, rxDst;

uint8 headCnt;
	
	
#endif
/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                                                                , %function
  25              	ADC_SAR_SaveConfig:
  26              	.LFB0:
  27              		.file 1 "Generated_Source\\PSoC5\\ADC_SAR_PM.c"
   1:Generated_Source\PSoC5/ADC_SAR_PM.c **** /*******************************************************************************
   2:Generated_Source\PSoC5/ADC_SAR_PM.c **** * File Name: ADC_SAR_PM.c
   3:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Version 3.10
   4:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
   5:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Description:
   6:Generated_Source\PSoC5/ADC_SAR_PM.c **** *  This file provides Sleep/WakeUp APIs functionality.
   7:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
   8:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Note:
   9:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
  10:Generated_Source\PSoC5/ADC_SAR_PM.c **** ********************************************************************************
  11:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
  12:Generated_Source\PSoC5/ADC_SAR_PM.c **** * You may use this file only in accordance with the license, terms, conditions,
  13:Generated_Source\PSoC5/ADC_SAR_PM.c **** * disclaimers, and limitations in the end user license agreement accompanying
  14:Generated_Source\PSoC5/ADC_SAR_PM.c **** * the software package with which this file was provided.
  15:Generated_Source\PSoC5/ADC_SAR_PM.c **** *******************************************************************************/
  16:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  17:Generated_Source\PSoC5/ADC_SAR_PM.c **** #include "ADC_SAR.h"
  18:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  19:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  20:Generated_Source\PSoC5/ADC_SAR_PM.c **** /***************************************
  21:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Local data allocation
  22:Generated_Source\PSoC5/ADC_SAR_PM.c **** ***************************************/
  23:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  24:Generated_Source\PSoC5/ADC_SAR_PM.c **** static ADC_SAR_BACKUP_STRUCT  ADC_SAR_backup =
  25:Generated_Source\PSoC5/ADC_SAR_PM.c **** {
  26:Generated_Source\PSoC5/ADC_SAR_PM.c ****     ADC_SAR_DISABLED
  27:Generated_Source\PSoC5/ADC_SAR_PM.c **** };
  28:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  29:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  30:Generated_Source\PSoC5/ADC_SAR_PM.c **** /*******************************************************************************
ARM GAS  C:\Users\dr\AppData\Local\Temp\ccxMHndR.s 			page 2


  31:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Function Name: ADC_SAR_SaveConfig
  32:Generated_Source\PSoC5/ADC_SAR_PM.c **** ********************************************************************************
  33:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
  34:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Summary:
  35:Generated_Source\PSoC5/ADC_SAR_PM.c **** *  Saves the current user configuration.
  36:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
  37:Generated_Source\PSoC5/ADC_SAR_PM.c