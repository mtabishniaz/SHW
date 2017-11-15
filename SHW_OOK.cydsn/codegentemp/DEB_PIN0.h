/*******************************************************************************
* File Name: DEB_PIN0.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DEB_PIN0_H) /* Pins DEB_PIN0_H */
#define CY_PINS_DEB_PIN0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DEB_PIN0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DEB_PIN0__PORT == 15 && ((DEB_PIN0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DEB_PIN0_Write(uint8 value);
void    DEB_PIN0_SetDriveMode(uint8 mode);
uint8   DEB_PIN0_ReadDataReg(void);
uint8   DEB_PIN0_Read(void);
void    DEB_PIN0_SetInterruptMode(uint16 position, uint16 mode);
uint8   DEB_PIN0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DEB_PIN0_SetDriveMode() function.
     *  @{
     */
        #define DEB_PIN0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DEB_PIN0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DEB_PIN0_DM_RES_UP          PIN_DM_RES_UP
        #define DEB_PIN0_DM_RES_DWN         PIN_DM_RES_DWN
        #define DEB_PIN0_DM_OD_LO           PIN_DM_OD_LO
        #define DEB_PIN0_DM_OD_HI           PIN_DM_OD_HI
        #define DEB_PIN0_DM_STRONG          PIN_DM_STRONG
        #define DEB_PIN0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DEB_PIN0_MASK               DEB_PIN0__MASK
#define DEB_PIN0_SHIFT              DEB_PIN0__SHIFT
#define DEB_PIN0_WIDTH              1u

/* Interrupt constants */
#if defined(DEB_PIN0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DEB_PIN0_SetInterruptMode() function.
     *  @{
     */
        #define DEB_PIN0_INTR_NONE      (uint16)(0x0000u)
        #define DEB_PIN0_INTR_RISING    (uint16)(0x0001u)
        #define DEB_PIN0_INTR_FALLING   (uint16)(0x0002u)
        #define DEB_PIN0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DEB_PIN0_INTR_MASK      (0x01u) 
#endif /* (DEB_PIN0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DEB_PIN0_PS                     (* (reg8 *) DEB_PIN0__PS)
/* Data Register */
#define DEB_PIN0_DR                     (* (reg8 *) DEB_PIN0__DR)
/* Port Number */
#define DEB_PIN0_PRT_NUM                (* (reg8 *) DEB_PIN0__PRT) 
/* Connect to Analog Globals */                                                  
#define DEB_PIN0_AG                     (* (reg8 *) DEB_PIN0__AG)                       
/* Analog MUX bux enable */
#define DEB_PIN0_AMUX                   (* (reg8 *) DEB_PIN0__AMUX) 
/* Bidirectional Enable */                                                        
#define DEB_PIN0_BIE                    (* (reg8 *) DEB_PIN0__BIE)
/* Bit-mask for Aliased Register Access */
#define DEB_PIN0_BIT_MASK               (* (reg8 *) DEB_PIN0__BIT_MASK)
/* Bypass Enable */
#define DEB_PIN0_BYP                    (* (reg8 *) DEB_PIN0__BYP)
/* Port wide control signals */                                                   
#define DEB_PIN0_CTL                    (* (reg8 *) DEB_PIN0__CTL)
/* Drive Modes */
#define DEB_PIN0_DM0                    (* (reg8 *) DEB_PIN0__DM0) 
#define DEB_PIN0_DM1                    (* (reg8 *) DEB_PIN0__DM1)
#define DEB_PIN0_DM2                    (* (reg8 *) DEB_PIN0__DM2) 
/* Input Buffer Disable Override */
#define DEB_PIN0_INP_DIS                (* (reg8 *) DEB_PIN0__INP_DIS)
/* LCD Common or Segment Drive */
#define DEB_PIN0_LCD_COM_SEG            (* (reg8 *) DEB_PIN0__LCD_COM_SEG)
/* Enable Segment LCD */
#define DEB_PIN0_LCD_EN                 (* (reg8 *) DEB_PIN0__LCD_EN)
/* Slew Rate Control */
#define DEB_PIN0_SLW                    (* (reg8 *) DEB_PIN0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DEB_PIN0_PRTDSI__CAPS_SEL       (* (reg8 *) DEB_PIN0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DEB_PIN0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DEB_PIN0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DEB_PIN0_PRTDSI__OE_SEL0        (* (reg8 *) DEB_PIN0__PRTDSI__OE_SEL0) 
#define DEB_PIN0_PRTDSI__OE_SEL1        (* (reg8 *) DEB_PIN0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DEB_PIN0_PRTDSI__OUT_SEL0       (* (reg8 *) DEB_PIN0__PRTDSI__OUT_SEL0) 
#define DEB_PIN0_PRTDSI__OUT_SEL1       (* (reg8 *) DEB_PIN0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DEB_PIN0_PRTDSI__SYNC_OUT       (* (reg8 *) DEB_PIN0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DEB_PIN0__SIO_CFG)
    #define DEB_PIN0_SIO_HYST_EN        (* (reg8 *) DEB_PIN0__SIO_HYST_EN)
    #define DEB_PIN0_SIO_REG_HIFREQ     (* (reg8 *) DEB_PIN0__SIO_REG_HIFREQ)
    #define DEB_PIN0_SIO_CFG            (* (reg8 *) DEB_PIN0__SIO_CFG)
    #define DEB_PIN0_SIO_DIFF           (* (reg8 *) DEB_PIN0__SIO_DIFF)
#endif /* (DEB_PIN0__SIO_CFG) */

/* Interrupt Registers */
#if defined(DEB_PIN0__INTSTAT)
    #define DEB_PIN0_INTSTAT            (* (reg8 *) DEB_PIN0__INTSTAT)
    #define DEB_PIN0_SNAP               (* (reg8 *) DEB_PIN0__SNAP)
    
	#define DEB_PIN0_0_INTTYPE_REG 		(* (reg8 *) DEB_PIN0__0__INTTYPE)
#endif /* (DEB_PIN0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DEB_PIN0_H */


/* [] END OF FILE */
