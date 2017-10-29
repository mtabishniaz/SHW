/*******************************************************************************
* File Name: CREG_LOAD_PM.c
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

#include "CREG_LOAD.h"

/* Check for removal by optimization */
#if !defined(CREG_LOAD_Sync_ctrl_reg__REMOVED)

static CREG_LOAD_BACKUP_STRUCT  CREG_LOAD_backup = {0u};

    
/*******************************************************************************
* Function Name: CREG_LOAD_SaveConfig
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
void CREG_LOAD_SaveConfig(void) 
{
    CREG_LOAD_backup.controlState = CREG_LOAD_Control;
}


/*******************************************************************************
* Function Name: CREG_LOAD_RestoreConfig
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
void CREG_LOAD_RestoreConfig(void) 
{
     CREG_LOAD_Control = CREG_LOAD_backup.controlState;
}


/*******************************************************************************
* Function Name: CREG_LOAD_Sleep
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
void CREG_LOAD_Sleep(void) 
{
    CREG_LOAD_SaveConfig();
}


/*******************************************************************************
* Function Name: CREG_LOAD_Wakeup
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
void CREG_LOAD_Wakeup(void)  
{
    CREG_LOAD_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     