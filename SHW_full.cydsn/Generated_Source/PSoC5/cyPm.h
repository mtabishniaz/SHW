                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                rence selection */

} CY_PM_BACKUP_STRUCT;


/***************************************
* Registers
***************************************/

/* Power Mode Wakeup Trim Register 1 */
#define CY_PM_PWRSYS_WAKE_TR1_REG           (* (reg8 *) CYREG_PWRSYS_WAKE_TR1 )
#define CY_PM_PWRSYS_WAKE_TR1_PTR           (  (reg8 *) CYREG_PWRSYS_WAKE_TR1 )

/* Master clock Divider Value Register */
#define CY_PM_CLKDIST_MSTR0_REG             (* (reg8 *) CYREG_CLKDIST_MSTR0 )
#define CY_PM_CLKDIST_MSTR0_PTR             (  (reg8 *) CYREG_CLKDIST_MSTR0 )

/* Master Clock Configuration Register/CPU Divider Value */
#define CY_PM_CLKDIST_MSTR1_REG             (* (reg8 *) CYREG_CLKDIST_MSTR1 )
#define CY_PM_CLKDIST_MSTR1_PTR             (  (reg8 *) CYREG_CLKDIST_MSTR1 )

/* Clock distribution configuration Register */
#define CY_PM_CLKDIST_CR_REG                (* (reg8 *) CYREG_CLKDIST_CR )
#define CY_PM_CLKDIST_CR_PTR                (  (reg8 *) CYREG_CLKDIST_CR )

/* CLK_BUS LSB Divider Value Register */
#define CY_PM_CLK_BUS_LSB_DIV_REG           (* (reg8 *) CYREG_CLKDIST_BCFG0 )
#define CY_PM_CLK_BUS_LSB_DIV_PTR           (  (reg8 *) CYREG_CLKDIST_BCFG0 )

/* CLK_BUS MSB Divider Value Register */
#define CY_PM_CLK_BUS_MSB_DIV_REG           (* (reg8 *) CYREG_CLKDIST_BCFG1 )
#define CY_PM_CLK_BUS_MSB_DIV_PTR           (  (reg8 *) CYREG_CLKDIST_BCFG1 )

/* CLK_BUS Configuration Register */
#define CLK_BUS_CFG_REG                     (* (reg8 *) CYREG_CLKDIST_BCFG2 )
#define CLK_BUS_CFG_PTR                     (  (reg8 *) CYREG_CLKDIST_BCFG2 )

/* Power Mode Control/Status Register */
#define CY_PM_MODE_CSR_REG                  (* (reg8 *) CYREG_PM_MODE_CSR )
#define CY_PM_MODE_CSR_PTR                  (  (reg8 *) CYREG_PM_MODE_CSR )

/* Power System Control Register 1 */
#define CY_PM_PWRSYS_CR1_REG                (* (reg8 *) CYREG_PWRSYS_CR1 )
#define CY_PM_PWRSYS_CR1_PTR                (  (reg8 *) CYREG_PWRSYS_CR1 )

/* Power System Control Register 0 */
#define CY_PM_PWRSYS_CR0_REG                (* (reg8 *) CYREG_PWRSYS_CR0 )
#define CY_PM_PWRSYS_CR0_PTR                (  (reg8 *) CYREG_PWRSYS_CR0 )

/* Internal Low-speed Oscillator Control Register 0 */
#define CY_PM_SLOWCLK_ILO_CR0_REG           (* (reg8 *) CYREG_SLOWCLK_ILO_CR0 )
#define CY_PM_SLOWCLK_ILO_CR0_PTR           (  (reg8 *) CYREG_SLOWCLK_ILO_CR0 )

/* External 32kHz Crystal Oscillator Control Register */
#define CY_PM_SLOWCLK_X32_CR_REG            (* (reg8 *) CYREG_SLOWCLK_X32_CR )
#define CY_PM_SLOWCLK_X32_CR_PTR            (  (reg8 *) CYREG_SLOWCLK_X32_CR )

#if(CY_PSOC3)

    /* MLOGIC Debug Register */
    #define CY_PM_MLOGIC_DBG_REG            (* (reg8 *) CYREG_MLOGIC_DEBUG )
    #define CY_PM_MLOGIC_DBG_PTR            (  (reg8 *) CYREG_MLOGIC_DEBUG )

    /* Port Pin Configuration Register */
    #define CY_PM_PRT1_PC3_REG              (* (reg8 *) CYREG_PRT1_PC3 )
    #define CY_PM_PRT1_PC3_PTR              (  (reg8 *) CYREG_PRT1_PC3 )

#endif /* (CY_PSOC3) */


/* Sleep Regulator Trim Register */
#define CY_PM_PWRSYS_SLP_TR_REG         (* (reg8 *) CYREG_PWRSYS_SLP_TR )
#define CY_PM_PWRSYS_SLP_TR_PTR         (  (reg8 *) CYREG_PWRSYS_SLP_TR )


/* Reset System Control Register */
#define CY_PM_RESET_CR1_REG                 (* (reg8 *) CYREG_RESET_CR1 )
#define CY_PM_RESET_CR1_PTR                 (  (reg8 *) CYREG_RESET_CR1 )

/* Power Mode Wakeup Trim Register 0 */
#define CY_PM_PWRSYS_WAKE_TR0_REG           (* (reg8 *) CYREG_PWRSYS_WAKE_TR0 )
#define CY_PM_PWRSYS_WAKE_TR0_PTR           (  (reg8 *) CYREG_PWRSYS_WAKE_TR0 )

#if(CY_PSOC3)

    /* Power Mode Wakeup Trim Register 2 */
    #define CY_PM_PWRSYS_WAKE_TR2_REG           (* (reg8 *) CYREG_PWRSYS_WAKE_TR2 )
    #define CY_PM_PWRSYS_WAKE_TR2_PTR           (  (reg8 *) CYREG_PWRSYS_WAKE_TR2 )

#endif  /* (CY_PSOC3) */

/* Power Manager Interrupt Status Register */
#define CY_PM_INT_SR_REG                    (* (reg8 *) CYREG_PM_INT_SR )
#define CY_PM_INT_SR_PTR                    (  (reg8 *) CYREG_PM_INT_SR )

/* Active Power Mode Configuration Register 0 */
#define CY_PM_ACT_CFG0_REG                  (* (reg8 *) CYREG_PM_ACT_CFG0 )
#define CY_PM_ACT_CFG0_PTR                  (  (reg8 *) CYREG_PM_ACT_CFG0 )

/* Active Power Mode Configuration Register 1 */
#define CY_PM_ACT_CFG1_REG                  (* (reg8 *) CYREG_PM_ACT_CFG1 )
#define CY_PM_ACT_CFG1_PTR                  (  (reg8 *) CYREG_PM_ACT_CFG1 )

/* Active Power Mode Configuration Register 2 */
#define CY_PM_ACT_CFG2_REG                  (* (reg8 *) CYREG_PM_ACT_CFG2 )
#define CY_PM_ACT_CFG2_PTR                  (  (reg8 *) CYREG_PM_ACT_CFG2 )

/* Boost Control 1 */
#define CY_PM_BOOST_CR1_REG                 (* (reg8 *) CYREG_BOOST_CR1 )
#define CY_PM_BOOST_CR1_PTR                 (  (reg8 *) CYREG_BOOST_CR1 )

/* Timewheel Configuration Register 0 */
#define CY_PM_TW_CFG0_REG                   (* (reg8 *) CYREG_PM_TW_CFG0 )
#define CY_PM_TW_CFG0_PTR                   (  (reg8 *) CYREG_PM_TW_CFG0 )

/* Timewheel Configuration Register 1 */
#define CY_PM_TW_CFG1_REG                   (* (reg8 *) CYREG_PM_TW_CFG1 )
#define CY_PM_TW_CFG1_PTR                   (  (reg8 *) CYREG_PM_TW_CFG1 )

/* Timewheel Configuration Register 2 */
#define CY_PM_TW_CFG2_REG                   (* (reg8 *) CYREG_PM_TW_CFG2 )
#define CY_PM_TW_CFG2_PTR                   (  (reg8 *) CYREG_PM_TW_CFG2 )

/* PLL Status Register */
#define CY_PM_FASTCLK_PLL_SR_REG            (*(reg8 *) CYREG_FASTCLK_PLL_SR )
#define CY_PM_FASTCLK_PLL_SR_PTR            ( (reg8 *) CYREG_FASTCLK_PLL_SR )

/* Internal Main Oscillator Control Register */
#define CY_PM_FASTCLK_IMO_CR_REG            (* (reg8 *) CYREG_FASTCLK_IMO_CR )
#define CY_PM_FASTCLK_IMO_CR_PTR            (  (reg8 *) CYREG_FASTCLK_IMO_CR )

/* PLL Configuration Register */
#define CY_PM_FASTCLK_PLL_CFG0_REG          (* (reg8 *) CYREG_FASTCLK_PLL_CFG0 )
#define CY_PM_FASTCLK_PLL_CFG0_PTR          (  (reg8 *) CYREG_FASTCLK_PLL_CFG0 )

/* External 4-33 MHz Crystal Oscillator Status and Control Register */
#define CY_PM_FASTCLK_XMHZ_CSR_REG          (* (reg8 *) CYREG_FASTCLK_XMHZ_CSR )
#define CY_PM_FASTCLK_XMHZ_CSR_PTR          (  (reg8 *) CYREG_FASTCLK_XMHZ_CSR )

/* Delay block Configuration Register */
#define CY_PM_CLKDIST_DELAY_REG             (* (reg8 *) CYREG_CLKDIST_DLY1 )
#define CY_PM_CLKDIST_DELAY_PTR             (  (reg8 *) CYREG_CLKDIST_DLY1 )


#if(CY_PSOC3)

    /* Cache Control Register */
    #define CY_PM_CACHE_CR_REG              (* (reg8 *) CYREG_CACHE_CR )
    #define CY_PM_CACHE_CR_PTR              (  (reg8 *) CYREG_CACHE_CR )

#else   /* Device is PSoC 5 */

    /* Cache Control Register */
    #define CY_PM_CACHE_CR_REG              (* (reg8 *) CYREG_CACHE_CC_CTL )
    #define CY_PM_CACHE_CR_PTR              (  (reg8 *) CYREG_CACHE_CC_CTL )

#endif  /* (CY_PSOC3) */


/* Power Mode Wakeup Mask Configuration Register 0 */
#define CY_PM_WAKEUP_CFG0_REG           (* (reg8 *) CYREG_PM_WAKEUP_CFG0 )
#define CY_PM_WAKEUP_CFG0_PTR           (  (reg8 *) CYREG_PM_WAKEUP_CFG0 )

/* Power Mode Wakeup Mask Configuration Register 1 */
#define CY_PM_WAKEUP_CFG1_REG           (* (reg8 *) CYREG_PM_WAKEUP_CFG1 )
#define CY_PM_WAKEUP_CFG1_PTR           (  (reg8 *) CYREG_PM_WAKEUP_CFG1 )

/* Power Mode Wakeup Mask Configuration Register 2 */
#define CY_PM_WAKEUP_CFG2_REG           (* (reg8 *) CYREG_PM_WAKEUP_CFG2 )
#define CY_PM_WAKEUP_CFG2_PTR           (  (reg8 *) CYREG_PM_WAKEUP_CFG2 )

/* Boost Control 2 */
#define CY_PM_BOOST_CR2_REG           (* (reg8 *) CYREG_BOOST_CR2 )
#define CY_PM_BOOST_CR2_PTR           (  (reg8 *) CYREG_BOOST_CR2 )

#if(CY_PSOC3)

    /* Interrrupt Controller Configuration and Status Register */
    #define CY_PM_INTC_CSR_EN_REG           (* (reg8 *) CYREG_INTC_CSR_EN )
    #define CY_PM_INTC_CSR_EN_PTR           (  (reg8 *) CYREG_INTC_CSR_EN )

#endif  /* (CY_PSOC3) */


/***************************************
* Register Constants
***************************************/

/* Internal Main Oscillator Control Register */

#define CY_PM_FASTCLK_IMO_CR_FREQ_MASK  (0x07u)    /* IMO frequency mask    */
#define CY_PM_FASTCLK_IMO_CR_FREQ_12MHZ (0x00u)    /* IMO frequency 12 MHz  */
#define CY_PM_FASTCLK_IMO_CR_F2XON      (0x10u)    /* IMO doubler enable    */
#define CY_PM_FASTCLK_IMO_CR_USB        (0x40u)    /* IMO is in USB mode    */

#define CY_PM_MASTER_CLK_SRC_IMO        (0u)
#define CY_PM_MASTER_CLK_SRC_PLL        (1u)
#define CY_PM_MASTER_CLK_SRC_XTAL       (2u)
#define CY_PM_MASTER_CLK_SRC_DSI        (3u)
#define CY_PM_MASTER_CLK_SRC_MASK       (3u)

#define CY_PM_PLL_CFG0_ENABLE           (0x01u)     /* PLL enable             */
#define CY_PM_PLL_STATUS_LOCK           (0x01u)     /* PLL Lock Status        */
#define CY_PM_XMHZ_CSR_ENABLE           (0x01u)     /* Enable X MHz OSC       */
#define CY_PM_XMHZ_CSR_XERR             (0x80u)     /* High indicates failure */
#define CY_PM_BOOST_ENABLE              (0x08u)     /* Boost enable           */
#define CY_PM_ILO_CR0_EN_1K             (0x02u)     /* Enable 1kHz ILO        */
#define CY_PM_ILO_CR0_EN_100K           (0x04u)     /* Enable 100kHz ILO      */
#define CY_PM_ILO_CR0_PD_MODE           (0x10u)     /* Power down mode for ILO*/
#define CY_PM_X32_CR_X32EN              (0x01u)     /* Enable 32kHz OSC       */

#define CY_PM_CTW_IE                    (0x08u)     /* CTW interrupt enable   */
#define CY_PM_CTW_EN                    (0x04u)     /* CTW enable             */
#define CY_PM_FTW_IE                    (0x02u)     /* FTW interrupt enable   */
#define CY_PM_FTW_EN                    (0x01u)     /* FTW enable             */
#define CY_PM_1PPS_EN                   (0x10u)     /* 1PPS enable            */
#define CY_PM_1PPS_IE                   (0x20u)     /* 1PPS interrupt enable  */


#define CY_PM_ACT_EN_CLK_A_MASK         (0x0Fu)
#define CY_PM_ACT_EN_CLK_D_MASK         (0xFFu)

#define CY_PM_DIV_BY_ONE                (0x00u)

/* Internal Main Oscillator Control Register */
#define CY_PM_FASTCLK_IMO_CR_XCLKEN     (0x20u)

/* Clock distribution configuration Register */
#define CY_PM_CLKDIST_IMO_OUT_MASK      (0x30u)
#define CY_PM_CLKDIST_IMO_OUT_IMO       (0x00u)
#define CY_PM_CLKDIST_IMO2X_SRC         (0x40u)

#define CY_PM_CLKDIST_PLL_SRC_MASK      (0x03u)
#define CY_PM_CLKDIST_PLL_SRC_IMO       (0x00u)
#define CY_PM_CLKDIST_PLL_SRC_XTAL      (0x01u)
#define CY_PM_CLKDIST_PLL_SRC_DSI       (0x02u)

/* Waiting for hibernate/sleep regulator to stabilize */
#define CY_PM_MODE_CSR_PWRUP_PULSE_Q    (0x08u)

#define CY_PM_MODE_CSR_ACTIVE           (0x00u)     /* Active power mode      */
#define CY_PM_MODE_CSR_ALT_ACT          (0x01u)     /* Alternate Active power */
#define CY_PM_MODE_CSR_SLEEP            (0x03u)     /* Sleep power mode       */
#define CY_PM_MODE_CSR_HIBERNATE        (0x04u)     /* Hibernate power mode   */
#define CY_PM_MODE_CSR_MASK             (0x07u)

/* I2C regulator backup enable */
#define CY_PM_PWRSYS_CR1_I2CREG_BACKUP  (0x04u)

/* When set, prepares system to disable LDO-A */
#define CY_PM_PWRSYS_CR1_LDOA_ISO       (0x01u)

/* When set, disables analog LDO regulator */
#define CY_PM_PWRSYS_CR1_LDOA_DIS       (0x02u)

#define CY_PM_PWRSYS_WAKE_TR2_VCCD_CLK_DET  (0x04u)

#define CY_PM_FTW_INT                   (0x01u)     /* FTW event has occured  */
#define CY_PM_CTW_INT                   (0x02u)     /* CTW event has occured  */
#define CY_PM_ONEPPS_INT                (0x04u)     /* 1PPS event has occured */

/* Active Power Mode Configuration Register 0 */
#define CY_PM_ACT_CFG0_IMO              (0x10u)     /* IMO enable in Active */

/* Cache Control Register (same mask for all device revisions) */
#define CY_PM_CACHE_CR_CYCLES_MASK      (0xC0u)

/* Bus Clock divider to divide-by-one */
#define CY_PM_BUS_CLK_DIV_BY_ONE        (0x00u)

/* HVI/LVI feature on external analog and digital supply mask */
#define CY_PM_RESET_CR1_HVI_LVI_EN_MASK (0x07u)

/* High-voltage-interrupt feature on external analog supply */
#define CY_PM_RESET_CR1_HVIA_EN         (0x04u)

/* Low-voltage-interrupt feature on external analog supply */
#define CY_PM_RESET_CR1_LVIA_EN         (0x02u)

/* Low-voltage-interrupt feature on external digital supply */
#define CY_PM_RESET_CR1_LVID_EN         (0x01u)

/* Allows system to program delays on clk_sync_d */
#define CY_PM_CLKDIST_DELAY_EN          (0x04u)


#define CY_PM_WAKEUP_SRC_CMPS_MASK      (0x000Fu)

/* Holdoff mask sleep trim */
#define CY_PM_PWRSYS_SLP_TR_HIBSLP_HOLDOFF_MASK     (0x1Fu)

#if(CY_PSOC3)

    /* CPU clock divider mask */
    #define CY_PM_CLKDIST_CPU_DIV_MASK          (0xF0u)

    /* Serial Wire View (SWV) clock enable */
    #define CY_PM_MLOGIC_DBG_SWV_CLK_EN         (0x04u)

    /* Port drive mode */
    #define CY_PM_PRT1_PC3_DM_MASK              (0xf1u)

    /* Mode 6, stong pull-up, strong pull-down */
    #define CY_PM_PRT1_PC3_DM_STRONG            (0x0Cu)

    /* When set, enables buzz wakeups */
    #define CY_PM_PWRSYS_WAKE_TR2_EN_BUZZ       (0x01u)

#endif  /* (CY_PSOC3) */


/* Disables sleep regulator and shorts vccd to vpwrsleep */
#define CY_PM_PWRSYS_SLP_TR_BYPASS          (0x10u)

/* Boost Control 2: Select external precision reference */
#define CY_PM_BOOST_CR2_EREFSEL_EXT     (0x08u)

#if(CY_PSOC3)

    #define CY_PM_PWRSYS_WAKE_TR0       (0xFFu)
    #define CY_PM_PWRSYS_WAKE_TR1       (0x90u)

#endif  /* (CY_PSOC3) */

#if(CY_PSOC5)

    #define CY_PM_PWRSYS_WAKE_TR0       (0xFFu)
    #define CY_PM_PWRSYS_WAKE_TR1       (0xB0u)

#endif  /* (CY_PSOC5) */

#if(CY_PSOC3)

    /* Interrrupt Controller Configuration and Status Register */
    #define CY_PM_INTC_CSR_EN_CLK       (0x01u)

#endif  /* (CY_PSOC3) */


/*******************************************************************************
* Lock Status Flag. If lock is acquired this flag will stay set (regardless of
* whether lock is subsequently lost) until it is read. Upon reading it will
* clear. If lock is still true then the bit will simply set again. If lock
* happens to be false when the clear on read occurs then the bit will stay
* cleared until the next lock event.
*******************************************************************************/
#define CY_PM_FASTCLK_PLL_LOCKED       (0x01u)


/*******************************************************************************
* The following code is OBSOLETE and must not be used starting with cy_boot 3.30
*
* If the obsoleted macro definitions intended for use in the application use the
* following scheme, redefine your own versions of these definitions:
*    #ifdef <OBSOLETED_DEFINE>
*        #undef  <OBSOLETED_DEFINE>
*        #define <OBSOLETED_DEFINE>      (<New Value>)
*    #endif
*
* Note: Redefine obsoleted macro definitions with caution. They might still be
*       used in the application and their modification might lead to unexpected
*       consequences.
*******************************************************************************/
#if(CY_PSOC3)

    /* Was removed as redundant */
    #define CY_PM_FTW_INTERVAL_MASK    (0xFFu)

#endif  /* (CY_PSOC3) */

/* Was removed as redundant */
#define CY_PM_CTW_INTERVAL_MASK         (0x0Fu)

#endif  /* (CY_BOOT_CYPM_H) */


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                  TAYDVR0gBEUwQzA3BglghkgBhv1sAQEwKjAoBggrBgEFBQcCARYcaHR0cHM6Ly93d3cuZGlnaWNlcnQuY29tL0NQUzAIBgZngQwBAgIwgYMGCCsGAQUFBwEBBHcwdTAkBggrBgEFBQcwAYYYaHR0cDovL29jc3AuZGlnaWNlcnQuY29tME0GCCsGAQUFBzAChkFodHRwOi8vY2FjZXJ0cy5kaWdpY2VydC5jb20vRGlnaUNlcnRTSEEySGlnaEFzc3VyYW5jZVNlcnZlckNBLmNydDAMBgNVHRMBAf8EAjAAMIICsAYKKwYBBAHWeQIEAgSCAqAEggKcApoAdgCkuQmQtBhYFIe7E6LMZ3AKPDWYBPkb37jjd80OyA3cEAAAAVjl02IEAAAEAwBHMEUCIQDvWFsUeqWE/xwIYcXPvbb5ExzfHBZTNwfnUf4RPO/lBgIgdOGmr0j7+u8/S+7tfFw71ZEjqpwJELl/sEFuQdPnpwQBLwCsO5rtf6lnR1cV