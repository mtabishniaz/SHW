                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                _SEL_MSK)) | clkSource;
    }
    else if (((oldSrc == ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D)) && 
            (clkSource != ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D))) && (currDiv == 0u))
    {
        /* Switching from Master to not and divider is 1, set source, so we don't   */
        /* lock when we clear SSS.                                                  */
        UART_IntClock_MOD_SRC =
            (UART_IntClock_MOD_SRC & (uint8)(~UART_IntClock_SRC_SEL_MSK)) | clkSource;
        UART_IntClock_MOD_SRC &= (uint8)(~CYCLK_SSS);
    }
    else
    {
        UART_IntClock_MOD_SRC =
            (UART_IntClock_MOD_SRC & (uint8)(~UART_IntClock_SRC_SEL_MSK)) | clkSource;
    }
}


/*******************************************************************************
* Function Name: UART_IntClock_GetSourceRegister
********************************************************************************
*
* Summary:
*  Gets the input source of the clock.
*
* Parameters:
*  None
*
* Returns:
*  The input source of the clock. See SetSourceRegister for details.
*
*******************************************************************************/
uint8 UART_IntClock_GetSourceRegister(void) 
{
    return UART_IntClock_MOD_SRC & UART_IntClock_SRC_SEL_MSK;
}


#if defined(UART_IntClock__CFG3)


/*******************************************************************************
* Function Name: UART_IntClock_SetPhaseRegister
********************************************************************************
*
* Summary:
*  Sets the phase delay of the analog clock. This function is only available
*  for analog clocks. The clock must be disabled before changing the phase
*  delay to avoid glitches.
*
* Parameters:
*  clkPhase: Amount to delay the phase of the clock, in 1.0ns increments.
*   clkPhase must be from 1 to 11 inclusive. Other values, including 0,
*   disable the clock. clkPhase = 1 produces a 0ns delay and clkPhase = 11 
*   produces a 10ns delay.
*
* Returns:
*  None
*
*******************************************************************************/
void UART_IntClock_SetPhaseRegister(uint8 clkPhase) 
{
    UART_IntClock_PHASE = clkPhase & UART_IntClock_PHASE_MASK;
}


/*******************************************************************************
* Function Name: UART_IntClock_GetPhase
********************************************************************************
*
* Summary:
*  Gets the phase delay of the analog clock. This function is only available
*  for analog clocks.
*
* Parameters:
*  None
*
* Returns:
*  Phase of the analog clock. See SetPhaseRegister for details.
*
*******************************************************************************/
uint8 UART_IntClock_GetPhaseRegister(void) 
{
    return UART_IntClock_PHASE & UART_IntClock_PHASE_MASK;
}

#endif /* UART_IntClock__CFG3 */


/* [] END OF FILE */
                                                                                                                                                  �da1e8� 1ookAppMan��ч-� V-WO8W64


"a dd3ee870 397897f1e09b �67  20fbe5 =7fdf2�����4a4�$ ffc6da7d 27705@xafဌ4844����O�OfO8��5b�N��0ad �9717�ce18��15_�1�net��2�ec b0281829 c35378d07�1dd34d�147�N�	#w\Y�	���"917�	P0 2f058�27Hc94`O04�
a�?O���Dc�	�	�	"54�0cfc390a@Y147e 4d60abc02OE�	�	Powe r-CAD-Su8ite			"d4�	b4f5a3�� 757563`v�50�8e5o			������04d 42c831e3�fd��d�W2�u�O�d5991oD�����Clust�	���������Deplo<ym��?	?	;	WC�N��-���%���mV�5���A��!�OneC �UA�Pb	$�������ì��	l__q_���irectPl�ay-OC-�ƿ�{�͸�D6S impleTCP�$$$"����NM_����="S�WMI-�-Provid�<�*�*�*pSnm>pU����WSh�ell-V2-tb�EEE�)d�V����W$P�ieldWO�7� � � "3��8�3b3faa���� 33a3c3cd10�75d��W  ///"2 aff5d1b1eacd�	97b3 O��099c9��/
/
ervic es-Ta�ute�dCont�u/
/
�/
"8e3�60k 94dfda0fDb1 �35d��c3/
/
��Light/~��="e6 ba75a7ce 078b02ec 05fa8e986f�2�D�Rem oteDeskt�opSuBas/0/	/	="dc14 196cb898�1ab��e64�	�7d6371eo:�m:Unifi1��<sia9"5 22dbee45$ffЬ4cp�6b 5f3b8a2e_