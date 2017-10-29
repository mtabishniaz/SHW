/*******************************************************************************
* File Name: CREG_INJ_RES_PM.c
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

#include "CREG_INJ_RES.h"

/* Check for removal by optimization */
#if !defined(CREG_INJ_RES_Sync_ctrl_reg__REMOVED)

static CREG_INJ_RES_BACKUP_STRUCT  CREG_INJ_RES_backup = {0u};

    
/*******************************************************************************
* Function Name: CREG_INJ_RES_SaveConfig
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
void CREG_INJ_RES_SaveConfig(void) 
{
    CREG_INJ_RES_backup.controlState = CREG_INJ_RES_Control;
}


/*******************************************************************************
* Function Name: CREG_INJ_RES_RestoreConfig
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
void CREG_INJ_RES_RestoreConfig(void) 
{
     CREG_INJ_RES_Control = CREG_INJ_RES_backup.controlState;
}


/*******************************************************************************
* Function Name: CREG_INJ_RES_Sleep
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
void CREG_INJ_RES_Sleep(void) 
{
    CREG_INJ_RES_SaveConfig();
}


/*******************************************************************************
* Function Name: CREG_INJ_RES_Wakeup
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
void CREG_INJ_RES_Wakeup(void)  
{
    CREG_INJ_RES_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
                                            voetb0mCtUpnmIEUwLX/eMNEvjg2qTH3/33ysCo2l25+/EcR8upF+2KIcmnk5WwaJzfq7cFPQc4CvczmTHasJi/jmVaIaJ9HC50g3dx584TQX26lDLddF/Li4uEbJ7TSopnTzjQdWBtWbMFh3bcfhFCKaqK2kIJV3bgup5HibEnZ2LPm6lekY072ZFCGM4QYc4ukqzou2JWCRmGo0dMHJhnvQXpnIQGwATqCD4Q1AB2AFYUBpov18Ls0/XhvUSyPsdGdrm8mRFcwO+UmFXWidDdAAABWOXTYrkAAAQDAEcwRQIgGhXXbwUO5bD4Ts/Q0gqZwUS2vl/A4Hemk7ovxl82v9oCIQCbtkflDXbcunY4MAQCbKlnesPGc/nftA84xDhJpxFHWQB3AO5Lvbd1zmC64UJpH6vhnmajD35fsHLYgwDEe4l6qP3LAAABWOXTZBEAAAQDAEgwRgIhAKubngQoa5Iak8eCOrffH7Xx3AP1NMb5pFw35nt2VSeRAiEA47Kq1UQcDXIEsV+WnuPd9LM5kpdeu0+TiHKtTLRQr0swDQYJKoZIhvcNAQELBQADggEBADrNSsoonbj1YGjwy9t9wP9+kZBwrNMO2n5N5fQNhGawkEAX+lXlzgm3TqYlTNi6sCFbPBAErim3aMVlWuOlctgnjtAdmdWZ4qEONrBLHPGgukDJ3Uen/EC/gwK6KdBCb4Ttp6MMPY1chb/ciTLi3QUUU4h4OJWqUjvccBCDs/LydNjKWZZTxLJmxRSmfpyCU3uU2XHHMNlo8UTIlqZsOtdqhg7/Q/cvMDHDkcI/tqelmg0MD2H9KpcmAvVkwgjn+BVpv5HELl+0EP0UhYknI1B6LBecJuj7jI26eXZdX35CYkpI/SZA9KK+OYKHh6vCxKqnRZ9ZQUOjXnIWKQeV5HjAKwEDAAAAAAEBAAAAAA== request-method GET response-head HTTP/2.0 200 OK
last-modified: Tue, 01 Jan 200