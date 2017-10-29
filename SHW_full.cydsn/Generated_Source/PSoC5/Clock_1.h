/*******************************************************************************
* File Name: Clock_1.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_1_H)
#define CY_CLOCK_Clock_1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock_1_Start(void) ;
void Clock_1_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock_1_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock_1_StandbyPower(uint8 state) ;
void Clock_1_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock_1_GetDividerRegister(void) ;
void Clock_1_SetModeRegister(uint8 modeBitMask) ;
void Clock_1_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_1_GetModeRegister(void) ;
void Clock_1_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_1_GetSourceRegister(void) ;
#if defined(Clock_1__CFG3)
void Clock_1_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_1_GetPhaseRegister(void) ;
#endif /* defined(Clock_1__CFG3) */

#define Clock_1_Enable()                       Clock_1_Start()
#define Clock_1_Disable()                      Clock_1_Stop()
#define Clock_1_SetDivider(clkDivider)         Clock_1_SetDividerRegister(clkDivider, 1u)
#define Clock_1_SetDividerValue(clkDivider)    Clock_1_SetDividerRegister((clkDivider) - 1u, 1u)
#define Clock_1_SetMode(clkMode)               Clock_1_SetModeRegister(clkMode)
#define Clock_1_SetSource(clkSource)           Clock_1_SetSourceRegister(clkSource)
#if defined(Clock_1__CFG3)
#define Clock_1_SetPhase(clkPhase)             Clock_1_SetPhaseRegister(clkPhase)
#define Clock_1_SetPhaseValue(clkPhase)        Clock_1_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Clock_1__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock_1_CLKEN              (* (reg8 *) Clock_1__PM_ACT_CFG)
#define Clock_1_CLKEN_PTR          ((reg8 *) Clock_1__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock_1_CLKSTBY            (* (reg8 *) Clock_1__PM_STBY_CFG)
#define Clock_1_CLKSTBY_PTR        ((reg8 *) Clock_1__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock_1_DIV_LSB            (* (reg8 *) Clock_1__CFG0)
#define Clock_1_DIV_LSB_PTR        ((reg8 *) Clock_1__CFG0)
#define Clock_1_DIV_PTR            ((reg16 *) Clock_1__CFG0)

/* Clock MSB divider configuration register. */
#define Clock_1_DIV_MSB            (* (reg8 *) Clock_1__CFG1)
#define Clock_1_DIV_MSB_PTR        ((reg8 *) Clock_1__CFG1)

/* Mode and source configuration register */
#define Clock_1_MOD_SRC            (* (reg8 *) Clock_1__CFG2)
#define Clock_1_MOD_SRC_PTR        ((reg8 *) Clock_1__CFG2)

#if defined(Clock_1__CFG3)
/* Analog clock phase configuration register */
#define Clock_1_PHASE              (* (reg8 *) Clock_1__CFG3)
#define Clock_1_PHASE_PTR          ((reg8 *) Clock_1__CFG3)
#endif /* defined(Clock_1__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock_1_CLKEN_MASK         Clock_1__PM_ACT_MSK
#define Clock_1_CLKSTBY_MASK       Clock_1__PM_STBY_MSK

/* CFG2 field masks */
#define Clock_1_SRC_SEL_MSK        Clock_1__CFG2_SRC_SEL_MASK
#define Clock_1_MODE_MASK          (~(Clock_1_SRC_SEL_MSK))

#if defined(Clock_1__CFG3)
/* CFG3 phase mask */
#define Clock_1_PHASE_MASK         Clock_1__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock_1__CFG3) */

#endif /* CY_CLOCK_Clock_1_H */


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                                                                                           		.align	2
  39              		.global	ADC_SAR_RestoreConfig
  40              		.thumb
  41              		.thumb_func
  42              		.type	ADC_SAR_RestoreConfig, %function
  43              	ADC_SAR_RestoreConfig:
  44              	.LFB1:
  46:Generated_Source\PSoC5/ADC_SAR_PM.c ****     /* All configuration registers are marked as [reset_all_retention] */
  47:Generated_Source\PSoC5/ADC_SAR_PM.c **** }
  48:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  49:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  50:Generated_Source\PSoC5/ADC_SAR_PM.c **** /*******************************************************************************
  51:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Function Name: ADC_SAR_RestoreConfig
  52:Generated_Source\PSoC5/ADC_SAR_PM.c **** ********************************************************************************
  53:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
  54:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Summary:
  55:Generated_Source\PSoC5/ADC_SAR_PM.c **** *  Restores the current user configuration.
  56:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
  57:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Parameters:
  58:Generated_Source\PSoC5/ADC_SAR_PM.c **** *  None.
  59:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
  60:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Return:
  61:Generated_Source\PSoC5/ADC_SAR_PM.c **** *  None.
  62:Generated_Source\PSoC5/ADC_SAR_PM.c **** *
  63:Generated_Source\PSoC5/ADC_SAR_PM.c **** *******************************************************************************/
  64:Generated_Source\PSoC5/ADC_SAR_PM.c **** void ADC_SAR_RestoreConfig(void)
  65:Generated_Source\PSoC5/ADC_SAR_PM.c **** {
  45              		.loc 1 65 0
  46              		.cfi_startproc
  47              		@ args = 0, pretend = 0, frame = 0
  48              		@ frame_needed = 0, uses_anonymous_args = 0
  49              		@ link register save eliminated.
ARM GAS  C:\Users\dr\AppData\Local\Temp\cctap6ob.s 			page 3


  50 0000 7047     		bx	lr
  51              		.cfi_endproc
  52              	.LFE1:
  53              		.size	ADC_SAR_RestoreConfig, .-ADC_SAR_RestoreConfig
  54 0002 00BF     		.section	.text.ADC_SAR_Sleep,"ax",%progbits
  55              		.align	2
  56              		.global	ADC_SAR_Sleep
  57              		.thumb
  58              		.thumb_func
  59              		.type	ADC_SAR_Sleep, %function
  60              	ADC_SAR_Sleep:
  61              	.LFB2:
  66:Generated_Source\PSoC5/ADC_SAR_PM.c ****     /* All congiguration registers are marked as [reset_all_retention] */
  67:Generated_Source\PSoC5/ADC_SAR_PM.c **** }
  68:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  69:Generated_Source\PSoC5/ADC_SAR_PM.c **** 
  70:Generated_Source\PSoC5/ADC_SAR_PM.c **** /*******************************************************************************
  71:Generated_Source\PSoC5/ADC_SAR_PM.c **** * Function Name: ADC_SAR_Sleep
  72:Generated_Source\PSoC5/ADC_SAR_PM.c **** *************************************************************