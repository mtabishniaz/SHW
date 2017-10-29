                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                FO_LENGTH                        (4u)
#define UART_NUMBER_OF_START_BIT                (1u)
#define UART_MAX_BYTE_VALUE                     (0xFFu)

/* 8X always for count7 implementation */
#define UART_TXBITCTR_BREAKBITS8X   ((UART_BREAK_BITS_TX * UART_OVER_SAMPLE_8) - 1u)
/* 8X or 16X for DP implementation */
#define UART_TXBITCTR_BREAKBITS ((UART_BREAK_BITS_TX * UART_OVER_SAMPLE_COUNT) - 1u)

#define UART_HALF_BIT_COUNT   \
                            (((UART_OVER_SAMPLE_COUNT / 2u) + (UART_USE23POLLING * 1u)) - 2u)
#if (UART_OVER_SAMPLE_COUNT == UART_OVER_SAMPLE_8)
    #define UART_HD_TXBITCTR_INIT   (((UART_BREAK_BITS_TX + \
                            UART_NUMBER_OF_START_BIT) * UART_OVER_SAMPLE_COUNT) - 1u)

    /* This parameter is increased on the 2 in 2 out of 3 mode to sample voting in the middle */
    #define UART_RXBITCTR_INIT  ((((UART_BREAK_BITS_RX + UART_NUMBER_OF_START_BIT) \
                            * UART_OVER_SAMPLE_COUNT) + UART_HALF_BIT_COUNT) - 1u)

#else /* UART_OVER_SAMPLE_COUNT == UART_OVER_SAMPLE_16 */
    #define UART_HD_TXBITCTR_INIT   ((8u * UART_OVER_SAMPLE_COUNT) - 1u)
    /* 7bit counter need one more bit for OverSampleCount = 16 */
    #define UART_RXBITCTR_INIT      (((7u * UART_OVER_SAMPLE_COUNT) - 1u) + \
                                                      UART_HALF_BIT_COUNT)
#endif /* End UART_OVER_SAMPLE_COUNT */

#define UART_HD_RXBITCTR_INIT                   UART_RXBITCTR_INIT


/***************************************
* Global variables external identifier
***************************************/

extern uint8 UART_initVar;
#if (UART_TX_INTERRUPT_ENABLED && UART_TX_ENABLED)
    extern volatile uint8 UART_txBuffer[UART_TX_BUFFER_SIZE];
    extern volatile uint16 UART_txBufferRead;
    extern uint16 UART_txBufferWrite;
#endif /* (UART_TX_INTERRUPT_ENABLED && UART_TX_ENABLED) */
#if (UART_RX_INTERRUPT_ENABLED && (UART_RX_ENABLED || UART_HD_ENABLED))
    extern uint8 UART_errorStatus;
    extern volatile uint8 UART_rxBuffer[UART_RX_BUFFER_SIZE];
    extern volatile uint8 UART_rxBufferRead;
    extern volatile uint8 UART_rxBufferWrite;
    extern volatile uint8 UART_rxBufferLoopDetect;
    extern volatile uint8 UART_rxBufferOverflow;
    #if (UART_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 UART_rxAddressMode;
        extern volatile uint8 UART_rxAddressDetected;
    #endif /* (UART_RXHW_ADDRESS_ENABLED) */
#endif /* (UART_RX_INTERRUPT_ENABLED && (UART_RX_ENABLED || UART_HD_ENABLED)) */


/***************************************
* Enumerated Types and Parameters
***************************************/

#define UART__B_UART__AM_SW_BYTE_BYTE 1
#define UART__B_UART__AM_SW_DETECT_TO_BUFFER 2
#define UART__B_UART__AM_HW_BYTE_BY_BYTE 3
#define UART__B_UART__AM_HW_DETECT_TO_BUFFER 4
#define UART__B_UART__AM_NONE 0

#define UART__B_UART__NONE_REVB 0
#define UART__B_UART__EVEN_REVB 1
#define UART__B_UART__ODD_REVB 2
#define UART__B_UART__MARK_SPACE_REVB 3



/***************************************
*    Initial Parameter Constants
***************************************/

/* UART shifts max 8 bits, Mark/Space functionality working if 9 selected */
#define UART_NUMBER_OF_DATA_BITS    ((8u > 8u) ? 8u : 8u)
#define UART_NUMBER_OF_STOP_BITS    (1u)

#if (UART_RXHW_ADDRESS_ENABLED)
    #define UART_RX_ADDRESS_MODE    (0u)
    #define UART_RX_HW_ADDRESS1     (0u)
    #define UART_RX_HW_ADDRESS2     (0u)
#endif /* (UART_RXHW_ADDRESS_ENABLED) */

#define UART_INIT_RX_INTERRUPTS_MASK \
                                  (uint8)((1 << UART_RX_STS_FIFO_NOTEMPTY_SHIFT) \
                                        | (0 << UART_RX_STS_MRKSPC_SHIFT) \
                                        | (0 << UART_RX_STS_ADDR_MATCH_SHIFT) \
                                        | (0 << UART_RX_STS_PAR_ERROR_SHIFT) \
                                        | (0 << UART_RX_STS_STOP_ERROR_SHIFT) \
                                        | (0 << UART_RX_STS_BREAK_SHIFT) \
                                        | (0 << UART_RX_STS_OVERRUN_SHIFT))

#define UART_INIT_TX_INTERRUPTS_MASK \
                                  (uint8)((0 << UART_TX_STS_COMPLETE_SHIFT) \
                                        | (1 << UART_TX_STS_FIFO_EMPTY_SHIFT) \
                                        | (0 << UART_TX_STS_FIFO_FULL_SHIFT) \
                                        | (0 << UART_TX_STS_FIFO_NOT_FULL_SHIFT))


/***************************************
*              Registers
***************************************/

#ifdef UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_CONTROL_REG \
                            (* (reg8 *) UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
    #define UART_CONTROL_PTR \
                            (  (reg8 *) UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG )
#endif /* End UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(UART_TX_ENABLED)
    #define UART_TXDATA_REG          (* (reg8 *) UART_BUART_sTX_TxShifter_u0__F0_REG)
    #define UART_TXDATA_PTR          (  (reg8 *) UART_BUART_sTX_TxShifter_u0__F0_REG)
    #define UART_TXDATA_AUX_CTL_REG  (* (reg8 *) UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define UART_TXDATA_AUX_CTL_PTR  (  (reg8 *) UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG)
    #define UART_TXSTATUS_REG        (* (reg8 *) UART_BUART_sTX_TxSts__STATUS_REG)
    #define UART_TXSTATUS_PTR        (  (reg8 *) UART_BUART_sTX_TxSts__STATUS_REG)
    #define UART_TXSTATUS_MASK_REG   (* (reg8 *) UART_BUART_sTX_TxSts__MASK_REG)
    #define UART_TXSTATUS_MASK_PTR   (  (reg8 *) UART_BUART_sTX_TxSts__MASK_REG)
    #define UART_TXSTATUS_ACTL_REG   (* (reg8 *) UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)
    #define UART_TXSTATUS_ACTL_PTR   (  (reg8 *) UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG)

    /* DP clock */
    #if(UART_TXCLKGEN_DP)
        #define UART_TXBITCLKGEN_CTR_REG        \
                                        (* (reg8 *) UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define UART_TXBITCLKGEN_CTR_PTR        \
                                        (  (reg8 *) UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG)
        #define UART_TXBITCLKTX_COMPLETE_REG    \
                                        (* (reg8 *) UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
        #define UART_TXBITCLKTX_COMPLETE_PTR    \
                                        (  (reg8 *) UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG)
    #else     /* Count7 clock*/
        #define UART_TXBITCTR_PERIOD_REG    \
                                        (* (reg8 *) UART_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define UART_TXBITCTR_PERIOD_PTR    \
                                        (  (reg8 *) UART_BUART_sTX_sCLOCK_TxBitCounter__PERIOD_REG)
        #define UART_TXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) UART_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define UART_TXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) UART_BUART_sTX_sCLOCK_TxBitCounter__CONTROL_AUX_CTL_REG)
        #define UART_TXBITCTR_COUNTER_REG   \
                                        (* (reg8 *) UART_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
        #define UART_TXBITCTR_COUNTER_PTR   \
                                        (  (reg8 *) UART_BUART_sTX_sCLOCK_TxBitCounter__COUNT_REG)
    #endif /* UART_TXCLKGEN_DP */

#endif /* End UART_TX_ENABLED */

#if(UART_HD_ENABLED)

    #define UART_TXDATA_REG             (* (reg8 *) UART_BUART_sRX_RxShifter_u0__F1_REG )
    #define UART_TXDATA_PTR             (  (reg8 *) UART_BUART_sRX_RxShifter_u0__F1_REG )
    #define UART_TXDATA_AUX_CTL_REG     (* (reg8 *) UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)
    #define UART_TXDATA_AUX_CTL_PTR     (  (reg8 *) UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define UART_TXSTATUS_REG           (* (reg8 *) UART_BUART_sRX_RxSts__STATUS_REG )
    #define UART_TXSTATUS_PTR           (  (reg8 *) UART_BUART_sRX_RxSts__STATUS_REG )
    #define UART_TXSTATUS_MASK_REG      (* (reg8 *) UART_BUART_sRX_RxSts__MASK_REG )
    #define UART_TXSTATUS_MASK_PTR      (  (reg8 *) UART_BUART_sRX_RxSts__MASK_REG )
    #define UART_TXSTATUS_ACTL_REG      (* (reg8 *) UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define UART_TXSTATUS_ACTL_PTR      (  (reg8 *) UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End UART_HD_ENABLED */

#if( (UART_RX_ENABLED) || (UART_HD_ENABLED) )
    #define UART_RXDATA_REG             (* (reg8 *) UART_BUART_sRX_RxShifter_u0__F0_REG )
    #define UART_RXDATA_PTR             (  (reg8 *) UART_BUART_sRX_RxShifter_u0__F0_REG )
    #define UART_RXADDRESS1_REG         (* (reg8 *) UART_BUART_sRX_RxShifter_u0__D0_REG )
    #define UART_RXADDRESS1_PTR         (  (reg8 *) UART_BUART_sRX_RxShifter_u0__D0_REG )
    #define UART_RXADDRESS2_REG         (* (reg8 *) UART_BUART_sRX_RxShifter_u0__D1_REG )
    #define UART_RXADDRESS2_PTR         (  (reg8 *) UART_BUART_sRX_RxShifter_u0__D1_REG )
    #define UART_RXDATA_AUX_CTL_REG     (* (reg8 *) UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG)

    #define UART_RXBITCTR_PERIOD_REG    (* (reg8 *) UART_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define UART_RXBITCTR_PERIOD_PTR    (  (reg8 *) UART_BUART_sRX_RxBitCounter__PERIOD_REG )
    #define UART_RXBITCTR_CONTROL_REG   \
                                        (* (reg8 *) UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define UART_RXBITCTR_CONTROL_PTR   \
                                        (  (reg8 *) UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG )
    #define UART_RXBITCTR_COUNTER_REG   (* (reg8 *) UART_BUART_sRX_RxBitCounter__COUNT_REG )
    #define UART_RXBITCTR_COUNTER_PTR   (  (reg8 *) UART_BUART_sRX_RxBitCounter__COUNT_REG )

    #define UART_RXSTATUS_REG           (* (reg8 *) UART_BUART_sRX_RxSts__STATUS_REG )
    #define UART_RXSTATUS_PTR           (  (reg8 *) UART_BUART_sRX_RxSts__STATUS_REG )
    #define UART_RXSTATUS_MASK_REG      (* (reg8 *) UART_BUART_sRX_RxSts__MASK_REG )
    #define UART_RXSTATUS_MASK_PTR      (  (reg8 *) UART_BUART_sRX_RxSts__MASK_REG )
    #define UART_RXSTATUS_ACTL_REG      (* (reg8 *) UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
    #define UART_RXSTATUS_ACTL_PTR      (  (reg8 *) UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG )
#endif /* End  (UART_RX_ENABLED) || (UART_HD_ENABLED) */

#if(UART_INTERNAL_CLOCK_USED)
    /* Register to enable or disable the digital clocks */
    #define UART_INTCLOCK_CLKEN_REG     (* (reg8 *) UART_IntClock__PM_ACT_CFG)
    #define UART_INTCLOCK_CLKEN_PTR     (  (reg8 *) UART_IntClock__PM_ACT_CFG)

    /* Clock mask for this clock. */
    #define UART_INTCLOCK_CLKEN_MASK    UART_IntClock__PM_ACT_MSK
#endif /* End UART_INTERNAL_CLOCK_USED */


/***************************************
*       Register Constants
***************************************/

#if(UART_TX_ENABLED)
    #define UART_TX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End UART_TX_ENABLED */

#if(UART_HD_ENABLED)
    #define UART_TX_FIFO_CLR            (0x02u) /* FIFO1 CLR */
#endif /* End UART_HD_ENABLED */

#if( (UART_RX_ENABLED) || (UART_HD_ENABLED) )
    #define UART_RX_FIFO_CLR            (0x01u) /* FIFO0 CLR */
#endif /* End  (UART_RX_ENABLED) || (UART_HD_ENABLED) */


/***************************************
* The following code is DEPRECATED and
* should not be used in new projects.
***************************************/

/* UART v2_40 obsolete definitions */
#define UART_WAIT_1_MS      UART_BL_CHK_DELAY_MS   

#define UART_TXBUFFERSIZE   UART_TX_BUFFER_SIZE
#define UART_RXBUFFERSIZE   UART_RX_BUFFER_SIZE

#if (UART_RXHW_ADDRESS_ENABLED)
    #define UART_RXADDRESSMODE  UART_RX_ADDRESS_MODE
    #define UART_RXHWADDRESS1   UART_RX_HW_ADDRESS1
    #define UART_RXHWADDRESS2   UART_RX_HW_ADDRESS2
    /* Backward compatible define */
    #define UART_RXAddressMode  UART_RXADDRESSMODE
#endif /* (UART_RXHW_ADDRESS_ENABLED) */

/* UART v2_30 obsolete definitions */
#define UART_initvar                    UART_initVar

#define UART_RX_Enabled                 UART_RX_ENABLED
#define UART_TX_Enabled                 UART_TX_ENABLED
#define UART_HD_Enabled                 UART_HD_ENABLED
#define UART_RX_IntInterruptEnabled     UART_RX_INTERRUPT_ENABLED
#define UART_TX_IntInterruptEnabled     UART_TX_INTERRUPT_ENABLED
#define UART_InternalClockUsed          UART_INTERNAL_CLOCK_USED
#define UART_RXHW_Address_Enabled       UART_RXHW_ADDRESS_ENABLED
#define UART_OverSampleCount            UART_OVER_SAMPLE_COUNT
#define UART_ParityType                 UART_PARITY_TYPE

#if( UART_TX_ENABLED && (UART_TXBUFFERSIZE > UART_FIFO_LENGTH))
    #define UART_TXBUFFER               UART_txBuffer
    #define UART_TXBUFFERREAD           UART_txBufferRead
    #define UART_TXBUFFERWRITE          UART_txBufferWrite
#endif /* End UART_TX_ENABLED */
#if( ( UART_RX_ENABLED || UART_HD_ENABLED ) && \
     (UART_RXBUFFERSIZE > UART_FIFO_LENGTH) )
    #define UART_RXBUFFER               UART_rxBuffer
    #define UART_RXBUFFERREAD           UART_rxBufferRead
    #define UART_RXBUFFERWRITE          UART_rxBufferWrite
    #define UART_RXBUFFERLOOPDETECT     UART_rxBufferLoopDetect
    #define UART_RXBUFFER_OVERFLOW      UART_rxBufferOverflow
#endif /* End UART_RX_ENABLED */

#ifdef UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG
    #define UART_CONTROL                UART_CONTROL_REG
#endif /* End UART_BUART_sCR_SyncCtl_CtrlReg__CONTROL_REG */

#if(UART_TX_ENABLED)
    #define UART_TXDATA                 UART_TXDATA_REG
    #define UART_TXSTATUS               UART_TXSTATUS_REG
    #define UART_TXSTATUS_MASK          UART_TXSTATUS_MASK_REG
    #define UART_TXSTATUS_ACTL          UART_TXSTATUS_ACTL_REG
    /* DP clock */
    #if(UART_TXCLKGEN_DP)
        #define UART_TXBITCLKGEN_CTR        UART_TXBITCLKGEN_CTR_REG
        #define UART_TXBITCLKTX_COMPLETE    UART_TXBITCLKTX_COMPLETE_REG
    #else     /* Count7 clock*/
        #define UART_TXBITCTR_PERIOD        UART_TXBITCTR_PERIOD_REG
        #define UART_TXBITCTR_CONTROL       UART_TXBITCTR_CONTROL_REG
        #define UART_TXBITCTR_COUNTER       UART_TXBITCTR_COUNTER_REG
    #endif /* UART_TXCLKGEN_DP */
#endif /* End UART_TX_ENABLED */

#if(UART_HD_ENABLED)
    #define UART_TXDATA                 UART_TXDATA_REG
    #define UART_TXSTATUS               UART_TXSTATUS_REG
    #define UART_TXSTATUS_MASK          UART_TXSTATUS_MASK_REG
    #define UART_TXSTATUS_ACTL          UART_TXSTATUS_ACTL_REG
#endif /* End UART_HD_ENABLED */

#if( (UART_RX_ENABLED) || (UART_HD_ENABLED) )
    #define UART_RXDATA                 UART_RXDATA_REG
    #define UART_RXADDRESS1             UART_RXADDRESS1_REG
    #define UART_RXADDRESS2             UART_RXADDRESS2_REG
    #define UART_RXBITCTR_PERIOD        UART_RXBITCTR_PERIOD_REG
    #define UART_RXBITCTR_CONTROL       UART_RXBITCTR_CONTROL_REG
    #define UART_RXBITCTR_COUNTER       UART_RXBITCTR_COUNTER_REG
    #define UART_RXSTATUS               UART_RXSTATUS_REG
    #define UART_RXSTATUS_MASK          UART_RXSTATUS_MASK_REG
    #define UART_RXSTATUS_ACTL          UART_RXSTATUS_ACTL_REG
#endif /* End  (UART_RX_ENABLED) || (UART_HD_ENABLED) */

#if(UART_INTERNAL_CLOCK_USED)
    #define UART_INTCLOCK_CLKEN         UART_INTCLOCK_CLKEN_REG
#endif /* End UART_INTERNAL_CLOCK_USED */

#define UART_WAIT_FOR_COMLETE_REINIT    UART_WAIT_FOR_COMPLETE_REINIT

#endif  /* CY_UART_UART_H */


/* [] END OF FILE */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         