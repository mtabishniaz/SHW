                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                M_LED_COUNTERCAP_LSB     (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define PWM_LED_COUNTERCAP_LSB_PTR ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define PWM_LED_COUNTER_LSB        (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define PWM_LED_COUNTER_LSB_PTR    ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define PWM_LED_CAPTURE_LSB        (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__F1_REG)
            #define PWM_LED_CAPTURE_LSB_PTR    ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__F1_REG)
        #else
            #if(PWM_LED_PWMModeIsCenterAligned)
               #define PWM_LED_PERIOD_LSB      (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
               #define PWM_LED_PERIOD_LSB_PTR  ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #else
               #define PWM_LED_PERIOD_LSB      (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
               #define PWM_LED_PERIOD_LSB_PTR  ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
            #endif /* (PWM_LED_PWMModeIsCenterAligned) */

            #define PWM_LED_COMPARE1_LSB       (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define PWM_LED_COMPARE1_LSB_PTR   ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define PWM_LED_COMPARE2_LSB       (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define PWM_LED_COMPARE2_LSB_PTR   ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define PWM_LED_COUNTERCAP_LSB     (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define PWM_LED_COUNTERCAP_LSB_PTR ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define PWM_LED_COUNTER_LSB        (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define PWM_LED_COUNTER_LSB_PTR    ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define PWM_LED_CAPTURE_LSB        (*(reg16 *) PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
            #define PWM_LED_CAPTURE_LSB_PTR    ((reg16 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define PWM_LED_AUX_CONTROLDP1          (*(reg8 *)  PWM_LED_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)
       #define PWM_LED_AUX_CONTROLDP1_PTR      ((reg8 *)   PWM_LED_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (PWM_LED_Resolution == 8) */

   #define PWM_LED_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__A1_REG)
   #define PWM_LED_AUX_CONTROLDP0          (*(reg8 *)  PWM_LED_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)
   #define PWM_LED_AUX_CONTROLDP0_PTR      ((reg8 *)   PWM_LED_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (PWM_LED_UsingFixedFunction) */

#if(PWM_LED_KillModeMinTime )
    #define PWM_LED_KILLMODEMINTIME        (*(reg8 *)  PWM_LED_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define PWM_LED_KILLMODEMINTIME_PTR    ((reg8 *)   PWM_LED_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (PWM_LED_KillModeMinTime ) */

#if(PWM_LED_DeadBandMode == PWM_LED__B_PWM__DBM_256_CLOCKS)
    #define PWM_LED_DEADBAND_COUNT         (*(reg8 *)  PWM_LED_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define PWM_LED_DEADBAND_COUNT_PTR     ((reg8 *)   PWM_LED_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define PWM_LED_DEADBAND_LSB_PTR       ((reg8 *)   PWM_LED_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define PWM_LED_DEADBAND_LSB           (*(reg8 *)  PWM_LED_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(PWM_LED_DeadBandMode == PWM_LED__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (PWM_LED_UsingFixedFunction)
        #define PWM_LED_DEADBAND_COUNT         (*(reg8 *)  PWM_LED_PWMHW__CFG0)
        #define PWM_LED_DEADBAND_COUNT_PTR     ((reg8 *)   PWM_LED_PWMHW__CFG0)
        #define PWM_LED_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << PWM_LED_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define PWM_LED_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define PWM_LED_DEADBAND_COUNT         (*(reg8 *)  PWM_LED_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define PWM_LED_DEADBAND_COUNT_PTR     ((reg8 *)   PWM_LED_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define PWM_LED_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << PWM_LED_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define PWM_LED_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (PWM_LED_UsingFixedFunction) */
#endif /* (PWM_LED_DeadBandMode == PWM_LED__B_PWM__DBM_256_CLOCKS) */



#if (PWM_LED_UsingFixedFunction)
    #define PWM_LED_STATUS                 (*(reg8 *) PWM_LED_PWMHW__SR0)
    #define PWM_LED_STATUS_PTR             ((reg8 *) PWM_LED_PWMHW__SR0)
    #define PWM_LED_STATUS_MASK            (*(reg8 *) PWM_LED_PWMHW__SR0)
    #define PWM_LED_STATUS_MASK_PTR        ((reg8 *) PWM_LED_PWMHW__SR0)
    #define PWM_LED_CONTROL                (*(reg8 *) PWM_LED_PWMHW__CFG0)
    #define PWM_LED_CONTROL_PTR            ((reg8 *) PWM_LED_PWMHW__CFG0)
    #define PWM_LED_CONTROL2               (*(reg8 *) PWM_LED_PWMHW__CFG1)
    #define PWM_LED_CONTROL3               (*(reg8 *) PWM_LED_PWMHW__CFG2)
    #define PWM_LED_GLOBAL_ENABLE          (*(reg8 *) PWM_LED_PWMHW__PM_ACT_CFG)
    #define PWM_LED_GLOBAL_ENABLE_PTR      ( (reg8 *) PWM_LED_PWMHW__PM_ACT_CFG)
    #define PWM_LED_GLOBAL_STBY_ENABLE     (*(reg8 *) PWM_LED_PWMHW__PM_STBY_CFG)
    #define PWM_LED_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) PWM_LED_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define PWM_LED_BLOCK_EN_MASK          (PWM_LED_PWMHW__PM_ACT_MSK)
    #define PWM_LED_BLOCK_STBY_EN_MASK     (PWM_LED_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define PWM_LED_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define PWM_LED_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define PWM_LED_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define PWM_LED_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define PWM_LED_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define PWM_LED_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define PWM_LED_CTRL_ENABLE            (uint8)((uint8)0x01u << PWM_LED_CTRL_ENABLE_SHIFT)
    #define PWM_LED_CTRL_RESET             (uint8)((uint8)0x01u << PWM_LED_CTRL_RESET_SHIFT)
    #define PWM_LED_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << PWM_LED_CTRL_CMPMODE2_SHIFT)
    #define PWM_LED_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << PWM_LED_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define PWM_LED_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define PWM_LED_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << PWM_LED_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define PWM_LED_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define PWM_LED_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define PWM_LED_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define PWM_LED_STATUS_TC_INT_EN_MASK_SHIFT            (PWM_LED_STATUS_TC_SHIFT - 4u)
    #define PWM_LED_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define PWM_LED_STATUS_CMP1_INT_EN_MASK_SHIFT          (PWM_LED_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define PWM_LED_STATUS_TC              (uint8)((uint8)0x01u << PWM_LED_STATUS_TC_SHIFT)
    #define PWM_LED_STATUS_CMP1            (uint8)((uint8)0x01u << PWM_LED_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define PWM_LED_STATUS_TC_INT_EN_MASK              (uint8)((uint8)PWM_LED_STATUS_TC >> 4u)
    #define PWM_LED_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)PWM_LED_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define PWM_LED_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define PWM_LED_RT1_MASK              (uint8)((uint8)0x03u << PWM_LED_RT1_SHIFT)
    #define PWM_LED_SYNC                  (uint8)((uint8)0x03u << PWM_LED_RT1_SHIFT)
    #define PWM_LED_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define PWM_LED_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << PWM_LED_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define PWM_LED_SYNCDSI_EN            (uint8)((uint8)0x0Fu << PWM_LED_SYNCDSI_SHIFT)


#else
    #define PWM_LED_STATUS                (*(reg8 *)   PWM_LED_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define PWM_LED_STATUS_PTR            ((reg8 *)    PWM_LED_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define PWM_LED_STATUS_MASK           (*(reg8 *)   PWM_LED_PWMUDB_genblk8_stsreg__MASK_REG)
    #define PWM_LED_STATUS_MASK_PTR       ((reg8 *)    PWM_LED_PWMUDB_genblk8_stsreg__MASK_REG)
    #define PWM_LED_STATUS_AUX_CTRL       (*(reg8 *)   PWM_LED_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define PWM_LED_CONTROL               (*(reg8 *)   PWM_LED_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define PWM_LED_CONTROL_PTR           ((reg8 *)    PWM_LED_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define PWM_LED_CTRL_ENABLE_SHIFT      (0x07u)
    #define PWM_LED_CTRL_RESET_SHIFT       (0x06u)
    #define PWM_LED_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define PWM_LED_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define PWM_LED_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define PWM_LED_CTRL_ENABLE            (uint8)((uint8)0x01u << PWM_LED_CTRL_ENABLE_SHIFT)
    #define PWM_LED_CTRL_RESET             (uint8)((uint8)0x01u << PWM_LED_CTRL_RESET_SHIFT)
    #define PWM_LED_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << PWM_LED_CTRL_CMPMODE2_SHIFT)
    #define PWM_LED_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << PWM_LED_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define PWM_LED_STATUS_KILL_SHIFT          (0x05u)
    #define PWM_LED_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define PWM_LED_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define PWM_LED_STATUS_TC_SHIFT            (0x02u)
    #define PWM_LED_STATUS_CMP2_SHIFT          (0x01u)
    #define PWM_LED_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define PWM_LED_STATUS_KILL_INT_EN_MASK_SHIFT          (PWM_LED_STATUS_KILL_SHIFT)
    #define PWM_LED_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (PWM_LED_STATUS_FIFONEMPTY_SHIFT)
    #define PWM_LED_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (PWM_LED_STATUS_FIFOFULL_SHIFT)
    #define PWM_LED_STATUS_TC_INT_EN_MASK_SHIFT            (PWM_LED_STATUS_TC_SHIFT)
    #define PWM_LED_STATUS_CMP2_INT_EN_MASK_SHIFT          (PWM_LED_STATUS_CMP2_SHIFT)
    #define PWM_LED_STATUS_CMP1_INT_EN_MASK_SHIFT          (PWM_LED_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define PWM_LED_STATUS_KILL            (uint8)((uint8)0x00u << PWM_LED_STATUS_KILL_SHIFT )
    #define PWM_LED_STATUS_FIFOFULL        (uint8)((uint8)0x01u << PWM_LED_STATUS_FIFOFULL_SHIFT)
    #define PWM_LED_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << PWM_LED_STATUS_FIFONEMPTY_SHIFT)
    #define PWM_LED_STATUS_TC              (uint8)((uint8)0x01u << PWM_LED_STATUS_TC_SHIFT)
    #define PWM_LED_STATUS_CMP2            (uint8)((uint8)0x01u << PWM_LED_STATUS_CMP2_SHIFT)
    #define PWM_LED_STATUS_CMP1            (uint8)((uint8)0x01u << PWM_LED_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define PWM_LED_STATUS_KILL_INT_EN_MASK            (PWM_LED_STATUS_KILL)
    #define PWM_LED_STATUS_FIFOFULL_INT_EN_MASK        (PWM_LED_STATUS_FIFOFULL)
    #define PWM_LED_STATUS_FIFONEMPTY_INT_EN_MASK      (PWM_LED_STATUS_FIFONEMPTY)
    #define PWM_LED_STATUS_TC_INT_EN_MASK              (PWM_LED_STATUS_TC)
    #define PWM_LED_STATUS_CMP2_INT_EN_MASK            (PWM_LED_STATUS_CMP2)
    #define PWM_LED_STATUS_CMP1_INT_EN_MASK            (PWM_LED_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define PWM_LED_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define PWM_LED_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define PWM_LED_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define PWM_LED_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define PWM_LED_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* PWM_LED_UsingFixedFunction */

#endif  /* CY_PWM_PWM_LED_H */


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          