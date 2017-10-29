/*******************************************************************************
* File Name: CREG_RX_SLOTS.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CREG_RX_SLOTS.h"

/* Check for removal by optimization */
#if !defined(CREG_RX_SLOTS_Sync_ctrl_reg__REMOVED)

    
/*******************************************************************************
* Function Name: CREG_RX_SLOTS_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void CREG_RX_SLOTS_Write(uint8 control) 
{
    CREG_RX_SLOTS_Control = control;
}


/*******************************************************************************
* Function Name: CREG_RX_SLOTS_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 CREG_RX_SLOTS_Read(void) 
{
    return CREG_RX_SLOTS_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
                                                      wW+pRqjugEo/dc64BYyjUlX7AnR8Xbp9MIj7NrQKrvuCVejsykxPFSKobPDqzxeVFqaP2YefbfaB+t/mzt8DVilPayEd1LZ+aiBfLC7MOoeR95Bzlca4xOlI9g/jxANKv5OtU/umG7ZhKYVMCldzcnzAKW1ooTYbMSK63aGYq0mmKF2KCxsSa1yC15HMZveSUxrTxVe+f+zEgkQmBf8PALhA0F7GCjaeS0l8XK/DGrH3x6jdAe2SDbZypN7sg6onI9ymwC8BAwAAAAABAQAAAAA= request-method GET response-head HTTP/2.0 200 OK
date: Mon, 23 Oct 2017 13:16:17 GMT
expires: Sat, 07 Jul 2018 18:06:39 GMT
content-type: image/png
access-control-allow-origin: *
content-security-policy: script-src 'none'; object-src 'none'; base-uri 'none'
x-content-type-options: nosniff
server: paintfe
content-length: 316
x-xss-protection: 1; mode=block
x-frame-options: SAMEORIGIN
cache-control: public, max-age=22222222
age: 6619
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 original-response-headers date: Mon, 23 Oct 2017 13:16:17 GMT
expires: Sat, 07 Jul 2018 18:06:39 GMT
content-type: image/png
access-control-allow-origin: *
content-security-policy: script-src 'none'; object-src 'none'; base-uri 'none'
x-content-type-options: nosniff
server: paintfe
content-length: 316
x-xss-protection: 1; mode=block
x-frame-options: SAMEORIGIN
cache-control: public, max-age=22222222
age: 6619
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 net-response-time-onstart 139 net-response-time-onstop 139   <                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              