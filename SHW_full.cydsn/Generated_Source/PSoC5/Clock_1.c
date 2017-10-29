                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                #else
                CLK_DIST_DMASK = Clock_1_CLKEN_MASK;
                CLK_DIST_AMASK = 0x00u;
#endif /* Clock_1__CFG3 */
                /* Clear mask of bus clock. */
                CLK_DIST_BCFG2 &= (uint8)(~BCFG2_MASK);

                /* If clock is currently enabled, disable it if async or going from N-to-1*/
                if (((Clock_1_MOD_SRC & CYCLK_SYNC) == 0u) || (clkDivider == 0u))
                {
#if HAS_CLKDIST_LD_DISABLE
                    CY_SET_REG16(CYREG_CLKDIST_WRK0, oldDivider);
                    CLK_DIST_LD = CYCLK_LD_DISABLE|CYCLK_LD_SYNC_EN|CYCLK_LD_LOAD;

                    /* Wait for clock to be disabled */
                    while ((CLK_DIST_LD & CYCLK_LD_LOAD) != 0u) { }
#endif /* HAS_CLKDIST_LD_DISABLE */

                    Clock_1_CLKEN &= (uint8)(~Clock_1_CLKEN_MASK);

#if HAS_CLKDIST_LD_DISABLE
                    /* Clear the disable bit */
                    CLK_DIST_LD = 0x00u;
#endif /* HAS_CLKDIST_LD_DISABLE */
                }
            }

            /* Load divide value. */
            if ((Clock_1_CLKEN & Clock_1_CLKEN_MASK) != 0u)
            {
                /* If the clock is still enabled, use the shadow registers */
                CY_SET_REG16(CYREG_CLKDIST_WRK0, clkDivider);

                CLK_DIST_LD = (CYCLK_LD_LOAD | ((restart != 0u) ? CYCLK_LD_SYNC_EN : 0x00u));
                while ((CLK_DIST_LD & CYCLK_LD_LOAD) != 0u) { }
            }
            else
            {
                /* If the clock is disabled, set the divider directly */
                CY_SET_REG16(Clock_1_DIV_PTR, clkDivider);
				Clock_1_CLKEN |= enabled;
            }
        }
    }
}


/*******************************************************************************
* Function Name: Clock_1_GetDividerRegister
********************************************************************************
*
* Summary:
*  Gets the clock divider register value.
*
* Parameters:
*  None
*
* Returns:
*  Divide value of the clock minus 1. For example, if the clock is set to
*  divide by 2, the return value will be 1.
*
*******************************************************************************/
uint16 Clock_1_GetDividerRegister(void) 
{
    return CY_GET_REG16(Clock_1_DIV_PTR);
}


/*******************************************************************************
* Function Name: Clock_1_SetModeRegister
********************************************************************************
*
* Summary:
*  Sets flags that control the operating mode of the clock. This function only
*  changes flags from 0 to 1; flags that are already 1 will remain unchanged.
*  To clear flags, use the ClearModeRegister function. The clock must be
*  disabled before changing the mode.
*
* Parameters:
*  clkMode: Bit mask containing the bits to set. For PSoC 3 and PSoC 5,
*   clkMode should be a set of the following optional bits or'ed together.
*   - CYCLK_EARLY Enable early phase mode. Rising edge of output clock will
*                 occur when the divider count reaches half of the divide
*                 value.
*   - CYCLK_DUTY  Enable 50% duty cycle output. When enabled, the output clock
*                 is asserted for approximately half of its period. When
*                 disabled, the output clock is asserted for one period of the
*                 source clock.
*   - CYCLK_SYNC  Enable output synchronization to master clock. This should
*                 be enabled for all synchronous clocks.
*   See the Technical Reference Manual for details about setting the mode of
*   the clock. Specifically, see the CLKDIST.DCFG.CFG2 register.
*
* Returns:
*  None
*
*******************************************************************************/
void Clock_1_SetModeRegister(uint8 modeBitMask) 
{
    Clock_1_MOD_SRC |= modeBitMask & (uint8)Clock_1_MODE_MASK;
}


/*******************************************************************************
* Function Name: Clock_1_ClearModeRegister
********************************************************************************
*
* Summary:
*  Clears flags that control the operating mode of the clock. This function
*  only changes flags from 1 to 0; flags that are already 0 will remain
*  unchanged. To set flags, use the SetModeRegister function. The clock must be
*  disabled before changing the mode.
*
* Parameters:
*  clkMode: Bit mask containing the bits to clear. For PSoC 3 and PSoC 5,
*   clkMode should be a set of the following optional bits or'ed together.
*   - CYCLK_EARLY Enable early phase mode. Rising edge of output clock will
*                 occur when the divider count reaches half of the divide
*                 value.
*   - CYCLK_DUTY  Enable 50% duty cycle output. When enabled, the output clock
*                 is asserted for approximately half of its period. When
*                 disabled, the output clock is asserted for one period of the
*                 source clock.
*   - CYCLK_SYNC  Enable output synchronization to master clock. This should
*                 be enabled for all synchronous clocks.
*   See the Technical Reference Manual for details about setting the mode of
*   the clock. Specifically, see the CLKDIST.DCFG.CFG2 register.
*
* Returns:
*  None
*
*******************************************************************************/
void Clock_1_ClearModeRegister(uint8 modeBitMask) 
{
    Clock_1_MOD_SRC &= (uint8)(~modeBitMask) | (uint8)(~(uint8)(Clock_1_MODE_MASK));
}


/*******************************************************************************
* Function Name: Clock_1_GetModeRegister
********************************************************************************
*
* Summary:
*  Gets the clock mode register value.
*
* Parameters:
*  None
*
* Returns:
*  Bit mask representing the enabled mode bits. See the SetModeRegister and
*  ClearModeRegister descriptions for details about the mode bits.
*
*******************************************************************************/
uint8 Clock_1_GetModeRegister(void) 
{
    return Clock_1_MOD_SRC & (uint8)(Clock_1_MODE_MASK);
}


/*******************************************************************************
* Function Name: Clock_1_SetSourceRegister
********************************************************************************
*
* Summary:
*  Sets the input source of the clock. The clock must be disabled before
*  changing the source. The old and new clock sources must be running.
*
* Parameters:
*  clkSource:  For PSoC 3 and PSoC 5 devices, clkSource should be one of the
*   following input sources:
*   - CYCLK_SRC_SEL_SYNC_DIG
*   - CYCLK_SRC_SEL_IMO
*   - CYCLK_SRC_SEL_XTALM
*   - CYCLK_SRC_SEL_ILO
*   - CYCLK_SRC_SEL_PLL
*   - CYCLK_SRC_SEL_XTALK
*   - CYCLK_SRC_SEL_DSI_G
*   - CYCLK_SRC_SEL_DSI_D/CYCLK_SRC_SEL_DSI_A
*   See the Technical Reference Manual for details on clock sources.
*
* Returns:
*  None
*
*******************************************************************************/
void Clock_1_SetSourceRegister(uint8 clkSource) 
{
    uint16 currDiv = Clock_1_GetDividerRegister();
    uint8 oldSrc = Clock_1_GetSourceRegister();

    if (((oldSrc != ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D)) && 
        (clkSource == ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D))) && (currDiv == 0u))
    {
        /* Switching to Master and divider is 1, set SSS, which will output master, */
        /* then set the source so we are consistent.                                */
        Clock_1_MOD_SRC |= CYCLK_SSS;
        Clock_1_MOD_SRC =
            (Clock_1_MOD_SRC & (uint8)(~Clock_1_SRC_SEL_MSK)) | clkSource;
    }
    else if (((oldSrc == ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D)) && 
            (clkSource != ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D))) && (currDiv == 0u))
    {
        /* Switching from Master to not and divider is 1, set source, so we don't   */
        /* lock when we clear SSS.                                                  */
        Clock_1_MOD_SRC =
            (Clock_1_MOD_SRC & (uint8)(~Clock_1_SRC_SEL_MSK)) | clkSource;
        Clock_1_MOD_SRC &= (uint8)(~CYCLK_SSS);
    }
    else
    {
        Clock_1_MOD_SRC =
            (Clock_1_MOD_SRC & (uint8)(~Clock_1_SRC_SEL_MSK)) | clkSource;
    }
}


/*******************************************************************************
* Function Name: Clock_1_GetSourceRegister
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
uint8 Clock_1_GetSourceRegister(void) 
{
    return Clock_1_MOD_SRC & Clock_1_SRC_SEL_MSK;
}


#if defined(Clock_1__CFG3)


/*******************************************************************************
* Function Name: Clock_1_SetPhaseRegister
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
void Clock_1_SetPhaseRegister(uint8 clkPhase) 
{
    Clock_1_PHASE = clkPhase & Clock_1_PHASE_MASK;
}


/*******************************************************************************
* Function Name: Clock_1_GetPhase
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
uint8 Clock_1_GetPhaseRegister(void) 
{
    return Clock_1_PHASE & Clock_1_PHASE_MASK;
}

#endif /* Clock_1__CFG3 */


/* [] END OF FILE */
                                                                                                                                                                                                                                    �� ?p<3ea���0zs_� X19 h@_longj��u nwindgse/��-� �t_ SSE2_enab8T�(z�abo rt_behav<io�$���co@ntrolf�e,t_WBd�Urr�no�!0F"e��or_mod��X�ebf�invalid�_parame`i�_e+_UBm0Toc�=_max_�wa8l	�t��g�ut_formh�!�R3coun�tkuJ!�TU]���)� andler _ seterror mode MSV0CRT.�4jm�p	p8,3.3� maxstdio�	8&rmbc
Q��systim
�_sleeN_snprpintf�_�c 	_l 
�l �5_s�s	0s0sca�n	^��<
��	;�:��w�L�E��J�I���� B)�Mw�B����C����open9B_s��q�_s�pawn���ȩ}�e }���Dp�� �v�$�v��v���vpE�vclitpa|th�% 
D) p�g �li*cH �	��BDpp�a3&����5:h0_s#JG_stat3�2��i64,_!�,��i�	6�4!�usf� /F�a2�5trpcoll)#& r�dat�?t�I5�C �u	rd����(rF�	�=
f!��E�ic���tr��A �� �iA!b""��$!lwr����k  EȅtrA���$�Otrn���R�
B+E�� �)F,�@�L#�ng#C��#n@��#?� b�;�$re��Gtr� 1�� dϛ���{tr� 1O� K�od+t���:rtot:� �}� ��5toͣuA�to�w}��u��u�p�)� d��� ��)U�Mtr��pxfrm� h_�swabW �  CU�h���E|c 9� ��I�GA`� �f_c`%�I@�]?�`C�@���`ys�_PMlist'8r_p�_n�_�telG� "9$Q�� �mpnamV�te� _�.�c� b�gagq zon�_�_p,owP�u� ��8�.ppZ~u� P� Z�w�l��&��w��z�(� _tz�DMd�� _6toav� ��C��wY\w �^wRl�� _ua �� �?`�a ��ma�sk�� _ua �� _ungetc�_nolocXZ�D��Ch@rh��Af�w_�ge�|wc�� ��xq0lin�� ao�addX4unl���d_fil�$Qck3_u!15� �@4&