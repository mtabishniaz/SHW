#if !defined(RXSUBSYSTEM_H)
#define RXSUBSYSTEM_H

/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "dlm.h"

#include <stdint.h>

void INIT_RX_SUBSYSTEM(void);
CY_ISR(ISR_HEADER_READ_h);


uint16 adcValue;

uint8 rxModLevel;
uint16 rxLength;
int16 rxTrackSum;
uint8 rxSrc, rxDst;

uint8 headCnt;
	
	
#endif /* RXSUBSYSTEM_H */
/* [] END OF FILE */