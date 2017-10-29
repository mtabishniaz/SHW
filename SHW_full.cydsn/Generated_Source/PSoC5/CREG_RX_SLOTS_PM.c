/*******************************************************************************
* File Name: CREG_RX_SLOTS_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CREG_RX_SLOTS.h"

/* Check for removal by optimization */
#if !defined(CREG_RX_SLOTS_Sync_ctrl_reg__REMOVED)

static CREG_RX_SLOTS_BACKUP_STRUCT  CREG_RX_SLOTS_backup = {0u};

    
/*******************************************************************************
* Function Name: CREG_RX_SLOTS_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CREG_RX_SLOTS_SaveConfig(void) 
{
    CREG_RX_SLOTS_backup.controlState = CREG_RX_SLOTS_Control;
}


/*******************************************************************************
* Function Name: CREG_RX_SLOTS_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void CREG_RX_SLOTS_RestoreConfig(void) 
{
     CREG_RX_SLOTS_Control = CREG_RX_SLOTS_backup.controlState;
}


/*******************************************************************************
* Function Name: CREG_RX_SLOTS_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CREG_RX_SLOTS_Sleep(void) 
{
    CREG_RX_SLOTS_SaveConfig();
}


/*******************************************************************************
* Function Name: CREG_RX_SLOTS_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CREG_RX_SLOTS_Wakeup(void)  
{
    CREG_RX_SLOTS_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
                         se-uri 'none'
x-content-type-options: nosniff
server: paintfe
content-length: 312
x-xss-protection: 1; mode=block
x-frame-options: SAMEORIGIN
cache-control: public, max-age=22222222
age: 107084
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 net-response-time-onstart 53 net-response-time-onstop 53   8                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 