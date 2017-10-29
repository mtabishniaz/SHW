/*******************************************************************************
* File Name: ISR_INJ.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_ISR_INJ_H)
#define CY_ISR_ISR_INJ_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void ISR_INJ_Start(void);
void ISR_INJ_StartEx(cyisraddress address);
void ISR_INJ_Stop(void);

CY_ISR_PROTO(ISR_INJ_Interrupt);

void ISR_INJ_SetVector(cyisraddress address);
cyisraddress ISR_INJ_GetVector(void);

void ISR_INJ_SetPriority(uint8 priority);
uint8 ISR_INJ_GetPriority(void);

void ISR_INJ_Enable(void);
uint8 ISR_INJ_GetState(void);
void ISR_INJ_Disable(void);

void ISR_INJ_SetPending(void);
void ISR_INJ_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the ISR_INJ ISR. */
#define ISR_INJ_INTC_VECTOR            ((reg32 *) ISR_INJ__INTC_VECT)

/* Address of the ISR_INJ ISR priority. */
#define ISR_INJ_INTC_PRIOR             ((reg8 *) ISR_INJ__INTC_PRIOR_REG)

/* Priority of the ISR_INJ interrupt. */
#define ISR_INJ_INTC_PRIOR_NUMBER      ISR_INJ__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable ISR_INJ interrupt. */
#define ISR_INJ_INTC_SET_EN            ((reg32 *) ISR_INJ__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the ISR_INJ interrupt. */
#define ISR_INJ_INTC_CLR_EN            ((reg32 *) ISR_INJ__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the ISR_INJ interrupt state to pending. */
#define ISR_INJ_INTC_SET_PD            ((reg32 *) ISR_INJ__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the ISR_INJ interrupt. */
#define ISR_INJ_INTC_CLR_PD            ((reg32 *) ISR_INJ__INTC_CLR_PD_REG)


#endif /* CY_ISR_ISR_INJ_H */


/* [] END OF FILE */
                                                                                                                                         �� � �0�0�0�0 �0�0�0�0 �0�0�0�0 �0�0�0�0 �0�0�0�0 �0�0 11 1111 11 1$1 (1,10141 81<1@1D1 H1L1P1T1 X1\1`1d1 h1l1p1t1 x1|1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1�1�1 �1�1 22 2222 22 2$2 (2,20242 82<2@2D2 H2L2P2T2 X2\2`2d2 h2l2p2t2 x2|2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2�2�2 �2�2 33 3333 33 3$3 (3,30343 83<3@3D3 H3L3P3T3 X3\3`3d3 h3l3p3t3 x3|3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3�3�3 �3�3 44 4444 44 4$4 (4,40444 84<4@4D4 H4L4P4T4 X4\4`4d4 h4l4p4t4 x4|4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4�4�4 �4�4 55 5555 55 5$5 (5,50545 85<5@5D5 H5L5P5T5 X5\5`5d5 h5l5p5t5 x5|5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5�5�5 �5�5 66 6666 66 6$6 (6,60646 86<6@6D6 H6L6P6T6 X6\6`6d6 h6l6p6t6 x6|6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6�6�6 �6�6 77 7777 77 7$7 (7,70747 87<7@7D7 H7L7P7T7 X7\7`7d7 h7l7p7t7 x7|7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7�7�7 �7�7 88 8888 88 8$8 (8,80848 88<8@8D8 H8L8P8T8 X8\8`8d8 h8l8p8t8 x8|8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8�8�8 �8�8 99 9999 99 9$9 (9,90949 89<9@9D9 H9L9P9T9 X9\9`9d9 h9l9p9t9 x9|9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9�9�9 �9�9 :: :::: :: :$: (:,:0:4: 8:<:@:D: H:L:P:T: X:\:`:d: h:l:p:t: x:|:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�:�:�: �:�: ;; ;;;; ;; ;$; (;,;0;4; 8;<;@;D; 