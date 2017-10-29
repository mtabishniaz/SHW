/*******************************************************************************
* File Name: CREG_RX_SLOTS.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_CREG_RX_SLOTS_H) /* CY_CONTROL_REG_CREG_RX_SLOTS_H */
#define CY_CONTROL_REG_CREG_RX_SLOTS_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} CREG_RX_SLOTS_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    CREG_RX_SLOTS_Write(uint8 control) ;
uint8   CREG_RX_SLOTS_Read(void) ;

void CREG_RX_SLOTS_SaveConfig(void) ;
void CREG_RX_SLOTS_RestoreConfig(void) ;
void CREG_RX_SLOTS_Sleep(void) ; 
void CREG_RX_SLOTS_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define CREG_RX_SLOTS_Control        (* (reg8 *) CREG_RX_SLOTS_Sync_ctrl_reg__CONTROL_REG )
#define CREG_RX_SLOTS_Control_PTR    (  (reg8 *) CREG_RX_SLOTS_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_CREG_RX_SLOTS_H */


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                                                                                                    ns: nosniff
server: paintfe
content-length: 265
x-xss-protection: 1; mode=block
x-frame-options: SAMEORIGIN
cache-control: public, max-age=22222222
age: 176132
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 original-response-headers date: Sat, 21 Oct 2017 14:11:04 GMT
expires: Thu, 05 Jul 2018 19:01:26 GMT
content-type: image/png
access-control-allow-origin: *
content-security-policy: script-src 'none'; object-src 'none'; base-uri 'none'
x-content-type-options: nosniff
server: paintfe
content-length: 265
x-xss-protection: 1; mode=block
x-frame-options: SAMEORIGIN
cache-control: public, max-age=22222222
age: 176132
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 net-response-time-onstart 134 net-response-time-onstop 134   	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               