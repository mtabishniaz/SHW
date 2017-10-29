/*******************************************************************************
* File Name: PWM_LED_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_LED.h"

static PWM_LED_backupStruct PWM_LED_backup;


/*******************************************************************************
* Function Name: PWM_LED_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_LED_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_LED_SaveConfig(void) 
{

    #if(!PWM_LED_UsingFixedFunction)
        #if(!PWM_LED_PWMModeIsCenterAligned)
            PWM_LED_backup.PWMPeriod = PWM_LED_ReadPeriod();
        #endif /* (!PWM_LED_PWMModeIsCenterAligned) */
        PWM_LED_backup.PWMUdb = PWM_LED_ReadCounter();
        #if (PWM_LED_UseStatus)
            PWM_LED_backup.InterruptMaskValue = PWM_LED_STATUS_MASK;
        #endif /* (PWM_LED_UseStatus) */

        #if(PWM_LED_DeadBandMode == PWM_LED__B_PWM__DBM_256_CLOCKS || \
            PWM_LED_DeadBandMode == PWM_LED__B_PWM__DBM_2_4_CLOCKS)
            PWM_LED_backup.PWMdeadBandValue = PWM_LED_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_LED_KillModeMinTime)
             PWM_LED_backup.PWMKillCounterPeriod = PWM_LED_ReadKillTime();
        #endif /* (PWM_LED_KillModeMinTime) */

        #if(PWM_LED_UseControl)
            PWM_LED_backup.PWMControlRegister = PWM_LED_ReadControlRegister();
        #endif /* (PWM_LED_UseControl) */
    #endif  /* (!PWM_LED_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_LED_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_LED_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_LED_RestoreConfig(void) 
{
        #if(!PWM_LED_UsingFixedFunction)
            #if(!PWM_LED_PWMModeIsCenterAligned)
                PWM_LED_WritePeriod(PWM_LED_backup.PWMPeriod);
            #endif /* (!PWM_LED_PWMModeIsCenterAligned) */

            PWM_LED_WriteCounter(PWM_LED_backup.PWMUdb);

            #if (PWM_LED_UseStatus)
                PWM_LED_STATUS_MASK = PWM_LED_backup.InterruptMaskValue;
            #endif /* (PWM_LED_UseStatus) */

            #if(PWM_LED_DeadBandMode == PWM_LED__B_PWM__DBM_256_CLOCKS || \
                PWM_LED_DeadBandMode == PWM_LED__B_PWM__DBM_2_4_CLOCKS)
                PWM_LED_WriteDeadTime(PWM_LED_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_LED_KillModeMinTime)
                PWM_LED_WriteKillTime(PWM_LED_backup.PWMKillCounterPeriod);
            #endif /* (PWM_LED_KillModeMinTime) */

            #if(PWM_LED_UseControl)
                PWM_LED_WriteControlRegister(PWM_LED_backup.PWMControlRegister);
            #endif /* (PWM_LED_UseControl) */
        #endif  /* (!PWM_LED_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_LED_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_LED_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_LED_Sleep(void) 
{
    #if(PWM_LED_UseControl)
        if(PWM_LED_CTRL_ENABLE == (PWM_LED_CONTROL & PWM_LED_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_LED_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_LED_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_LED_UseControl) */

    /* Stop component */
    PWM_LED_Stop();

    /* Save registers configuration */
    PWM_LED_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_LED_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_LED_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_LED_Wakeup(void) 
{
     /* Restore registers values */
    PWM_LED_RestoreConfig();

    if(PWM_LED_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_LED_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                              SUVWATAUAVH��@H�l$ L��H�e �E H�E    H����H�H�ME���   �@���3��NI�N(H������   H��H�H���Ph�8 ���  H�H�����   �8 ���  ;�t�E ��    ��I�N(H��P`;�|�E3��   I�N �9 A����Q���8 L�h83��   ��I��� ��H�a H��H���p��H��t[��I��� ��H��H��tH9tH��H����o��H��H�H�����   �8 ���  H�H����  �8 ���  ;�t�E �9��I�E I���P`;��o���A��D  I�N H��P`D;��6����E��H�M �"   �
H�M�1�����E� H�e A^A]A\_^][��SUVWATAUAVH��0H�i H�l$ H�m H�M������H��0A^A]A\_^][��̈� SUVWATAUAVH��@H�l$ L��H�e �E H�E    H���H�H�ME���   �`���3��[I�N(H������   H��H�H���Ph�8 H���   H��Ph��H�H�����   �8 H���   H��Ph;�t	�E �   ��f�I�N(H��P`;�|�E3���   I�N �9 A����O���8 L�h83��   ��I������H�t H��H���n��H��tl��I�����H��H��tH9tH��H���
n��H��H�H�����   �8 H���   H��Ph��H�H����  �8 H���   H��Ph;�t	�E �> ��I�E I���P`;��^���A���    I�N H��P`D;��#����E��H�M �"   �
H�M�1�����E� H�e A^A]A\_^][��SUVWATAUAVH��0H�i H�l$ H�m H�M������H��0A^A]A\_^][��̘� SUVWH��(A��H�kI�xI�p�    H�;���   Hc�H;���   H��H��uPH��L�v��H��t
H�I;�t3�H��u3��NH�W��H��tH9tH��H���l��H�Ȁ9 H�Ax�����H��L� H��t
H�I;�t3�H��u3��7H�� H��tH9tH��H���Rl��H�Ȁ9 H�IxH��Ph�����7���H��(_^][����l�����̨� SVWH�� H��H��Ƈ�    Ƈ�    H�H����p  �ȅ���  H�5ޱ�H�H�H�H����  �ȅ�tDH�H�H�H�����  H��H�:±�H�A�   ��A����uA�   H��H���/-���  H�5�ݱ�H�H�H�H����  �ȅ���   H�H�H�H�����  H��H�����H�A�   H����4���ȅ�ucH�Sܱ�H�A�   H����4���ȅ�uDH�D±�H�A�   H��