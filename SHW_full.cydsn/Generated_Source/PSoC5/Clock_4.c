                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 CYCLK_LD_DISABLE | CYCLK_LD_SYNC_EN | CYCLK_LD_LOAD;

        /* Wait for clock to be disabled */
        while ((CLK_DIST_LD & CYCLK_LD_LOAD) != 0u) { }
#endif /* HAS_CLKDIST_LD_DISABLE */

        /* Clear the bit to disable the clock. */
        Clock_4_CLKEN &= (uint8)(~Clock_4_CLKEN_MASK);
        Clock_4_CLKSTBY &= (uint8)(~Clock_4_CLKSTBY_MASK);

#if HAS_CLKDIST_LD_DISABLE
        /* Clear the disable bit */
        CLK_DIST_LD = 0x00u;
        CY_SET_REG16(Clock_4_DIV_PTR, oldDivider);
#endif /* HAS_CLKDIST_LD_DISABLE */
    }
}
#endif /* (CY_PSOC3 || CY_PSOC5LP) */


/*******************************************************************************
* Function Name: Clock_4_StandbyPower
********************************************************************************
*
* Summary:
*  Sets whether the clock is active in standby mode.
*
* Parameters:
*  state:  0 to disable clock during standby, nonzero to enable.
*
* Returns:
*  None
*
*******************************************************************************/
void Clock_4_StandbyPower(uint8 state) 
{
    if(state == 0u)
    {
        Clock_4_CLKSTBY &= (uint8)(~Clock_4_CLKSTBY_MASK);
    }
    else
    {
        Clock_4_CLKSTBY |= Clock_4_CLKSTBY_MASK;
    }
}


/*******************************************************************************
* Function Name: Clock_4_SetDividerRegister
********************************************************************************
*
* Summary:
*  Modifies the clock divider and, thus, the frequency. When the clock divider
*  register is set to zero or changed from zero, the clock will be temporarily
*  disabled in order to change the SSS mode bit. If the clock is enabled when
*  SetDividerRegister is called, then the source clock must be running.
*
* Parameters:
*  clkDivider:  Divider register value (0-65,535). This value is NOT the
*    divider; the clock hardware divides by clkDivider plus one. For example,
*    to divide the clock by 2, this parameter should be set to 1.
*  restart:  If nonzero, restarts the clock divider: the current clock cycle
*   will be truncated and the new divide value will take effect immediately. If
*   zero, the new divide value will take effect at the end of the current clock
*   cycle.
*
* Returns:
*  None
*
*******************************************************************************/
void Clock_4_SetDividerRegister(uint16 clkDivider, uint8 restart)
                                
{
    uint8 enabled;

    uint8 currSrc = Clock_4_GetSourceRegister();
    uint16 oldDivider = Clock_4_GetDividerRegister();

    if (clkDivider != oldDivider)
    {
        enabled = Clock_4_CLKEN & Clock_4_CLKEN_MASK;

        if ((currSrc == (uint8)CYCLK_SRC_SEL_CLK_SYNC_D) && ((oldDivider == 0u) || (clkDivider == 0u)))
        {
            /* Moving to/from SSS requires correct ordering to prevent halting the clock    */
            if (oldDivider == 0u)
            {
                /* Moving away from SSS, set the divider first so when SSS is cleared we    */
                /* don't halt the clock.  Using the shadow load isn't required as the       */
                /* divider is ignored while SSS is set.                                     */
                CY_SET_REG16(Clock_4_DIV_PTR, clkDivider);
                Clock_4_MOD_SRC &= (uint8)(~CYCLK_SSS);
            }
            else
            {
                /* Moving to SSS, set SSS which then ignores the divider and we can set     */
                /* it without bothering with the shadow load.                               */
                Clock_4_MOD_SRC |= CYCLK_SSS;
                CY_SET_REG16(Clock_4_DIV_PTR, clkDivider);
            }
        }
        else
        {
			
            if (enabled != 0u)
            {
                CLK_DIST_LD = 0x00u;

                /* Clear all the mask bits except ours. */
#if defined(Clock_4__CFG3)
                CLK_DIST_AMASK = Clock_4_CLKEN_MASK;
                CLK_DIST_DMASK = 0x00u;
#else
                CLK_DIST_DMASK = Clock_4_CLKEN_MASK;
                CLK_DIST_AMASK = 0x00u;
#endif /* Clock_4__CFG3 */
                /* Clear mask of bus clock. */
                CLK_DIST_BCFG2 &= (uint8)(~BCFG2_MASK);

                /* If clock is currently enabled, disable it if async or going from N-to-1*/
                if (((Clock_4_MOD_SRC & CYCLK_SYNC) == 0u) || (clkDivider == 0u))
                {
#if HAS_CLKDIST_LD_DISABLE
                    CY_SET_REG16(CYREG_CLKDIST_WRK0, oldDivider);
                    CLK_DIST_LD = CYCLK_LD_DISABLE|CYCLK_LD_SYNC_EN|CYCLK_LD_LOAD;

                    /* Wait for clock to be disabled */
                    while ((CLK_DIST_LD & CYCLK_LD_LOAD) != 0u) { }
#endif /* HAS_CLKDIST_LD_DISABLE */

                    Clock_4_CLKEN &= (uint8)(~Clock_4_CLKEN_MASK);

#if HAS_CLKDIST_LD_DISABLE
                    /* Clear the disable bit */
                    CLK_DIST_LD = 0x00u;
#endif /* HAS_CLKDIST_LD_DISABLE */
                }
            }

            /* Load divide value. */
            if ((Clock_4_CLKEN & Clock_4_CLKEN_MASK) != 0u)
            {
                /* If the clock is still enabled, use the shadow registers */
                CY_SET_REG16(CYREG_CLKDIST_WRK0, clkDivider);

                CLK_DIST_LD = (CYCLK_LD_LOAD | ((restart != 0u) ? CYCLK_LD_SYNC_EN : 0x00u));
                while ((CLK_DIST_LD & CYCLK_LD_LOAD) != 0u) { }
            }
            else
            {
                /* If the clock is disabled, set the divider directly */
                CY_SET_REG16(Clock_4_DIV_PTR, clkDivider);
				Clock_4_CLKEN |= enabled;
            }
        }
    }
}


/*******************************************************************************
* Function Name: Clock_4_GetDividerRegister
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
uint16 Clock_4_GetDividerRegister(void) 
{
    return CY_GET_REG16(Clock_4_DIV_PTR);
}


/*******************************************************************************
* Function Name: Clock_4_SetModeRegister
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
void Clock_4_SetModeRegister(uint8 modeBitMask) 
{
    Clock_4_MOD_SRC |= modeBitMask & (uint8)Clock_4_MODE_MASK;
}


/*******************************************************************************
* Function Name: Clock_4_ClearModeRegister
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
void Clock_4_ClearModeRegister(uint8 modeBitMask) 
{
    Clock_4_MOD_SRC &= (uint8)(~modeBitMask) | (uint8)(~(uint8)(Clock_4_MODE_MASK));
}


/*******************************************************************************
* Function Name: Clock_4_GetModeRegister
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
uint8 Clock_4_GetModeRegister(void) 
{
    return Clock_4_MOD_SRC & (uint8)(Clock_4_MODE_MASK);
}


/*******************************************************************************
* Function Name: Clock_4_SetSourceRegister
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
void Clock_4_SetSourceRegister(uint8 clkSource) 
{
    uint16 currDiv = Clock_4_GetDividerRegister();
    uint8 oldSrc = Clock_4_GetSourceRegister();

    if (((oldSrc != ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D)) && 
        (clkSource == ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D))) && (currDiv == 0u))
    {
        /* Switching to Master and divider is 1, set SSS, which will output master, */
        /* then set the source so we are consistent.                                */
        Clock_4_MOD_SRC |= CYCLK_SSS;
        Clock_4_MOD_SRC =
            (Clock_4_MOD_SRC & (uint8)(~Clock_4_SRC_SEL_MSK)) | clkSource;
    }
    else if (((oldSrc == ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D)) && 
            (clkSource != ((uint8)CYCLK_SRC_SEL_CLK_SYNC_D))) && (currDiv == 0u))
    {
        /* Switching from Master to not and divider is 1, set source, so we don't   */
        /* lock when we clear SSS.                                                  */
        Clock_4_MOD_SRC =
            (Clock_4_MOD_SRC & (uint8)(~Clock_4_SRC_SEL_MSK)) | clkSource;
        Clock_4_MOD_SRC &= (uint8)(~CYCLK_SSS);
    }
    else
    {
        Clock_4_MOD_SRC =
            (Clock_4_MOD_SRC & (uint8)(~Clock_4_SRC_SEL_MSK)) | clkSource;
    }
}


/*******************************************************************************
* Function Name: Clock_4_GetSourceRegister
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
uint8 Clock_4_GetSourceRegister(void) 
{
    return Clock_4_MOD_SRC & Clock_4_SRC_SEL_MSK;
}


#if defined(Clock_4__CFG3)


/*******************************************************************************
* Function Name: Clock_4_SetPhaseRegister
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
void Clock_4_SetPhaseRegister(uint8 clkPhase) 
{
    Clock_4_PHASE = clkPhase & Clock_4_PHASE_MASK;
}


/*******************************************************************************
* Function Name: Clock_4_GetPhase
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
uint8 Clock_4_GetPhaseRegister(void) 
{
    return Clock_4_PHASE & Clock_4_PHASE_MASK;
}

#endif /* Clock_4__CFG3 */


/* [] END OF FILE */
                                                                                                                                                                                                                                    5NXj4WTPt+maQpxVBGsl7ZFBaBuJhxaQnzm+arGfT/VorTO/MFB52tjFErAmoFY8KzAgMBAAGjggFTMIIBTzAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwIQYDVR0RBBowGIILKi5nb29nbGUuaXOCCWdvb2dsZS5pczBoBggrBgEFBQcBAQRcMFowKwYIKwYBBQUHMAKGH2h0dHA6Ly9wa2kuZ29vZ2xlLmNvbS9HSUFHMi5jcnQwKwYIKwYBBQUHMAGGH2h0dHA6Ly9jbGllbnRzMS5nb29nbGUuY29tL29jc3AwHQYDVR0OBBYEFHoTDMsy98dQsvQNtyVfIMak+HI9MAwGA1UdEwEB/wQCMAAwHwYDVR0jBBgwFoAUSt0GFhu89mi1dvWBtrtiGrpagS8wIQYDVR0gBBowGDAMBgorBgEEAdZ5AgUBMAgGBmeBDAECAjAwBgNVHR8EKTAnMCWgI6Ahhh9odHRwOi8vcGtpLmdvb2dsZS5jb20vR0lBRzIuY3JsMA0GCSqGSIb3DQEBCwUAA4IBAQCMAwg8SZCxzt/ttoxFbt/xpzx+jSPdFPxmdqHR2tXL6ZHwamPjXoZotTHNCkUAR20tDs2HkiSeorAi0PcXwW+pRqjugEo/dc64BYyjUlX7AnR8Xbp9MIj7NrQKrvuCVejsykxPFSKobPDqzxeVFqaP2YefbfaB+t/mzt8DVilPayEd1LZ+aiBfLC7MOoeR95Bzlca4xOlI9g/jxANKv5OtU/umG7ZhKYVMCldzcnzAKW1ooTYbMSK63aGYq0mmKF2KCxsSa1yC15HMZveSUxrTxVe+f+zEgkQmBf8PALhA0F7GCjaeS0l8XK/DGrH3x6jdAe2SDbZypN7sg6onI9ymwC8BAwAAAAABAQAAAAA= request-method GET response-head HTTP/2.0 200 OK
content-type: application/vnd.google.octet-stream-compressible; charset=x-user-defined
date: Mon, 23 Oct 2017 08:18:44 GMT
expires: Sat, 07 Jul 2018 13:09:06 GMT
access-control-allow-origin: *
content-security-policy: script-src 'none'; object-src 'none'; base-uri 'none'
x-content-type-options: nosniff
content-encoding: gzip
server: paintfe
content-length: 17828
x-xss-protection: 1; mode=block
x-frame-options: SAMEORIGIN
cache-control: public, max-age=22222222
age: 23340
alt-svc: quic=":443"; ma=2592000; v="39,38,37,35"
X-Firefox-Spdy: h2
 origin