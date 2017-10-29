/*******************************************************************************
* File Name: Control_Reg_2_PM.c
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

#include "Control_Reg_2.h"

/* Check for removal by optimization */
#if !defined(Control_Reg_2_Sync_ctrl_reg__REMOVED)

static Control_Reg_2_BACKUP_STRUCT  Control_Reg_2_backup = {0u};

    
/*******************************************************************************
* Function Name: Control_Reg_2_SaveConfig
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
void Control_Reg_2_SaveConfig(void) 
{
    Control_Reg_2_backup.controlState = Control_Reg_2_Control;
}


/*******************************************************************************
* Function Name: Control_Reg_2_RestoreConfig
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
void Control_Reg_2_RestoreConfig(void) 
{
     Control_Reg_2_Control = Control_Reg_2_backup.controlState;
}


/*******************************************************************************
* Function Name: Control_Reg_2_Sleep
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
void Control_Reg_2_Sleep(void) 
{
    Control_Reg_2_SaveConfig();
}


/*******************************************************************************
* Function Name: Control_Reg_2_Wakeup
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
void Control_Reg_2_Wakeup(void)  
{
    Control_Reg_2_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
                         Xuf-��z5l<�0����{] j�ݩ����h+}�.�h!R��hw���JM[z��"j������	� 	�����EW����Fmn�/�x2�yJ�p�0f.�����
�`	jN]��,�a��̬��y�����3�N�}��oXp.i;��g����p巻~�9属�Ⱥ��s#�SQ�p����Zt���=m���-���C��䀅��ڲLA��-$�U��N^|o�������[t��ڿ�J���@o�7�o��.v�$oܼ���f����`�ݶΟqï��❝�7�&�{�[ӧF`�D�7���x!  ��d��      Y�xY�x>U�1[@�t   �    :https://www.google.is/maps/vt/pb=!1m4!1m3!1i13!2i4083!3i2728!2m3!1e0!2sm!3i396093239!3m7!2sen!5e1105!12m4!1e68!2m2!1sset!2sRoadmap!4e1!5m4!1e4!8m2!1e0!1e1!6m7!1e12!2i2!26m1!4b1!39b1!44e1!50e0 necko:classified 1 strongly-framed 1 security-info FnhllAKWRHGAlo+ESXykKAAAAAAAAAAAwAAAAAAAAEaphjojH6pBabDSgSnsfLHeAAQAAgAAAAAAAAAAAAAAAAAAAAAB4vFIJp5wRkeyPxAQ9RJGKPqbqVvKO0mKuIl8ec8o/uhmCjImkVxP+7sgiYWmMt8FvcOXmlQiTNWFiWlrbpbqgwAAAAAAAASJMIIEhTCCA22gAwIBAgIIOzyY6Xi8gwUwDQYJKoZIhvcNAQELBQAwSTELMAkGA1UEBhMCVVMxEzARBgNVBAoTCkdvb2dsZSBJbmMxJTAjBgNVBAMTHEdvb2dsZSBJbnRlcm5ldCBBdXRob3JpdHkgRzIwHhcNMTcxMDEwMTQzMzU2WhcNMTcxMjI5MDAwMDAwWjBlMQswCQYDVQQGEwJVUzETMBEGA1UECAwKQ2FsaWZv