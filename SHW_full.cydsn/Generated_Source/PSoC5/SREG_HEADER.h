/*******************************************************************************
* File Name: SREG_HEADER.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_SREG_HEADER_H) /* CY_STATUS_REG_SREG_HEADER_H */
#define CY_STATUS_REG_SREG_HEADER_H

#include "cyfitter.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
     (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))
    #include "cytypes.h"
    #include "CyLib.h"
#else
    #include "syslib/cy_syslib.h"
#endif

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} SREG_HEADER_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 SREG_HEADER_Read(void) ;
void SREG_HEADER_InterruptEnable(void) ;
void SREG_HEADER_InterruptDisable(void) ;
void SREG_HEADER_WriteMask(uint8 mask) ;
uint8 SREG_HEADER_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define SREG_HEADER_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define SREG_HEADER_INPUTS              4


/***************************************
*             Registers
***************************************/

/* Status Register */
#define SREG_HEADER_Status             (* (reg8 *) SREG_HEADER_sts_sts_reg__STATUS_REG )
#define SREG_HEADER_Status_PTR         (  (reg8 *) SREG_HEADER_sts_sts_reg__STATUS_REG )
#define SREG_HEADER_Status_Mask        (* (reg8 *) SREG_HEADER_sts_sts_reg__MASK_REG )
#define SREG_HEADER_Status_Aux_Ctrl    (* (reg8 *) SREG_HEADER_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_SREG_HEADER_H */


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                      e: Tue, 24 Oct 2017 13:09:42 GMT
expires: Fri, 01 Jan 1990 00:00:00 GMT
cache-control: no-cache, must-revalidate
pragma: no-cache
content-type: image/gif
x-content-type-options: nosniff
server: HTTP server (unknown)
content-length: 0
x-xss-protection: 1; mode=block
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 original-response-headers date: Tue, 24 Oct 2017 13:09:42 GMT
expires: Fri, 01 Jan 1990 00:00:00 GMT
cache-control: no-cache, must-revalidate
pragma: no-cache
content-type: image/gif
x-content-type-options: nosniff
server: HTTP server (unknown)
content-length: 0
x-xss-protection: 1; mode=block
set-cookie: SIDCC=AE4kn7_RBc0KYLQCvW8YCL_gbZZpLVCQ6jwUgozrL8R38cSztbLqJKapBKBJowrDWxi48UMOMJvwQGPB-3sqtQ; expires=Mon, 22-Jan-2018 13:09:42 GMT; path=/; domain=.google.com; priority=high
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 net-response-time-onstart 54 net-response-time-onstop 54                                                         