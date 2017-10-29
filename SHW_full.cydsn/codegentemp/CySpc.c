                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                �              �   �                 �   	   @       �
  p              �                �                  �              �  8                  �   	   @       (  (               �              �  (                  �   	   @       P  @               �                �                  �   	   @       �                  �      0       �  l                     0       L  o                              �  �                    	   @       �  @                   p        <  3                                �  .                               p  0              	              �	  �                                                                                                                                                                                                                                                                                                                                                                           else
        {
            status = CYRET_CANCELED;
        }
    }
    else
    {
        status = CYRET_LOCKED;
    }

    return(status);
}


/*******************************************************************************
* Function Name: CySpcGetTemp
****************************************************************************//**
*  Returns the internal die temperature
*
*  \param uint8 numSamples:
*   Number of samples. Valid values are 1-5, resulting in 2 - 32 samples
*   respectively.
*
* \param uint16 timerPeriod:
*   Number of ADC ACLK cycles. A valid 14 bit value is accepted, higher 2 bits
*   of 16 bit values are ignored.
*
* \param uint8 clkDivSelect:
*   ADC ACLK clock divide value. Valid values are 2 - 225.
*
* \return
*  CYRET_STARTED
*  CYRET_CANCELED
*  CYRET_LOCKED
*
*******************************************************************************/
cystatus CySpcGetTemp(uint8 numSamples)
{
    cystatus status = CYRET_STARTED;

    /* Make sure the SPC is ready to accept command */
    if(CY_SPC_IDLE)
    {
        CY_SPC_CPU_DATA_REG = CY_SPC_KEY_ONE;
        CY_SPC_CPU_DATA_REG = CY_SPC_KEY_TWO(CY_SPC_CMD_GET_TEMP);
        CY_SPC_CPU_DATA_REG = CY_SPC_CMD_GET_TEMP;

        /* Make sure the command was accepted */
        if(CY_SPC_BUSY)
        {
            CY_SPC_CPU_DATA_REG = numSamples;
        }
        else
        {
            status = CYRET_CANCELED;
        }
    }
    else
    {
        status = CYRET_LOCKED;
    }

    return(status);
}


/*******************************************************************************
* Function Name: CySpcLock
****************************************************************************//**
*  Locks the SPC so it can not be used by someone else:
*   - Saves wait-pipeline enable state and enable pipeline (PSoC5)
*
* \return
*  CYRET_SUCCESS - if the resource was free.
*  CYRET_LOCKED  - if the SPC is in use.
*
*******************************************************************************/
cystatus CySpcLock(void)
{
    cystatus status = CYRET_LOCKED;
    uint8 interruptState;

    /* Enter critical section */
    interruptState = CyEnterCriticalSection();

    if(CY_SPC_UNLOCKED == SpcLockState)
    {
        SpcLockState = CY_SPC_LOCKED;
        status = CYRET_SUCCESS;

        #if(CY_PSOC5)

            if(0u != (CY_SPC_CPU_WAITPIPE_REG & CY_SPC_CPU_WAITPIPE_BYPASS))
            {
                /* Enable pipeline registers */
                CY_SPC_CPU_WAITPIPE_REG &= ((uint32)(~CY_SPC_CPU_WAITPIPE_BYPASS));

                /* At least 2 NOP instructions are recommended */
                CY_NOP;
                CY_NOP;
                CY_NOP;

                spcWaitPipeBypass = CY_SPC_CPU_WAITPIPE_BYPASS;
            }

        #endif  /* (CY_PSOC5) */
    }

    /* Exit critical section */
    CyExitCriticalSection(interruptState);

    return(status);
}


/*******************************************************************************
* Function Name: CySpcUnlock
****************************************************************************//**
*  Unlocks the SPC so it can be used by someone else:
*   - Restores wait-pipeline enable state (PSoC5)
*
*******************************************************************************/
void CySpcUnlock(void)
{
    uint8 interruptState;

    /* Enter critical section */
    interruptState = CyEnterCriticalSection();

    /* Release the SPC object */
    SpcLockState = CY_SPC_UNLOCKED;

    #if(CY_PSOC5)

        if(CY_SPC_CPU_WAITPIPE_BYPASS == spcWaitPipeBypass)
        {
            /* Force to bypass pipeline registers */
            CY_SPC_CPU_WAITPIPE_REG |= CY_SPC_CPU_WAITPIPE_BYPASS;

            /* At least 2 NOP instructions are recommended */
            CY_NOP;
            CY_NOP;
            CY_NOP;

            spcWaitPipeBypass = 0u;
        }

    #endif  /* (CY_PSOC5) */

    /* Exit critical section */
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: CySpcGetAlgorithm
****************************************************************************//**
*  Downloads SPC algorithm from SPC SROM into SRAM.
*
* \return
*  CYRET_STARTED
*  CYRET_LOCKED
*
*******************************************************************************/
cystatus CySpcGetAlgorithm(void)
{
    cystatus status = CYRET_STARTED;

    /* Make sure the SPC is ready to accept command */
    if(CY_SPC_IDLE)
    {
        CY_SPC_CPU_DATA_REG = CY_SPC_KEY_ONE;
        CY_SPC_CPU_DATA_REG = CY_SPC_KEY_TWO(CY_SPC_CMD_DWNLD_ALGORITHM);
        CY_SPC_CPU_DATA_REG = CY_SPC_CMD_DWNLD_ALGORITHM;
    }
    else
    {
        status = CYRET_LOCKED;
    }

    return(status);
}

/* [] END OF FILE */

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         