/*******************************************************************************
* File Name: CREG_INJ.h  
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

#if !defined(CY_CONTROL_REG_CREG_INJ_H) /* CY_CONTROL_REG_CREG_INJ_H */
#define CY_CONTROL_REG_CREG_INJ_H

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

} CREG_INJ_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    CREG_INJ_Write(uint8 control) ;
uint8   CREG_INJ_Read(void) ;

void CREG_INJ_SaveConfig(void) ;
void CREG_INJ_RestoreConfig(void) ;
void CREG_INJ_Sleep(void) ; 
void CREG_INJ_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define CREG_INJ_Control        (* (reg8 *) CREG_INJ_Sync_ctrl_reg__CONTROL_REG )
#define CREG_INJ_Control_PTR    (  (reg8 *) CREG_INJ_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_CREG_INJ_H */


/* [] END OF FILE */
    �> ?? ???? ?? ?$? (?,?0?4? 8?<?@?D? H?L?P?T? X?\?`?d? h?l?p?t? x?|?�?�? �?�?�?�? �?�?�?�? �?�?�?�? �?�?�?�? �?�?�?�? �?�?�?�? �?�?�?�? �?�? `      00 0000 00 0$0 (0,00040 80<0@0D0 H0L0P0T0 X0\0`0d0 h0l0p0t0 x0|0�0�0 �0�0�0�0 �0�0�0�0 �0�0�0�0 �0�0�0�0����������������2����3���o����0��4��������������������������������������������������������������������������������������������~�p����� � �0�0�0�0 �0�0�0�0 �0�0�0�0 �0�0�0�0 �0�0�0�0 �0�0 11 1111 11 1$1 (1,10141 81<1@1D1 H1L1P1T1 X1\1`1d1 h1l1p1t1 x1|1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1 22 2222 22 2$2 (2,20242 82<2@2D2 H2L2P2T2 X2\2`2d2 h2l2p2t2 x2|2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2 33 3333 33 3$3 (3,30343 83<3@3D3 H3L3P3T3 X3\3`3d3 h3l3p3t3 x3|3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3 44 4444 44 4$4 (4,40444 84<4@4D4 H4L4P4T4 X4\4`4d4 h4l4p4t4 x4|4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4 55 5555 55 5$5 (5,50545 85<5@5D5 H5L5P5T5 X5\5`5d5 h5l5p5t5 x5|5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5 66 6666 66 6$6 (6,60646 86<6@6D6 H6L6P6T6 X6\6`6d6 h6l6p6t6 x6|6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6 77 7777 77 7$7 (7,70747 87<7@7D7 H7L7P7T7 X7\7`7d7 h7l7p7t7 x7|7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7 88 8888 88 8$8 (8,80848 88<8@8D8 H8L8P8T8 X8\8`8d8 h8l8p8t8 x8|8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8 99 9999 99 9$9 (9,90949 89<9@9D9 H9L9P9T9 X9\9`9d9 h9l9p9t9 x9|9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9 :: :::: :: :$: (:,:0:4: 8:<:@:D: H:L:P:T: X:\:`:d: h:l:p:t: x:|:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�: ;; ;;;; ;; ;$; (;,;0;4; 8;<;@;D; 