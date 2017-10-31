#if !defined(TXSUBSYSTEM_H)
#define TXSUBSYSTEM_H

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
#include <stdbool.h>
	
/* Define modulation level M in number of bits per symbol L */
#define M2	1
#define M4	2
#define M8	3
#define M16	4
#define M32	5


/* Prototypes and interrupt handlers */
void INIT_TX_SUBSYSTEM(void);
CY_ISR(ISR_SYM_h);
CY_ISR(ISR_INJ_CHECK_h);
CY_ISR(ISR_INJ_h);
CY_ISR(ISR_TX_DONE_h);

bool FLAG_TX_EVENT;
bool FLAG_TX_DONE;

/* Variables */
uint8 modLevel;
uint8 m2[2]; 
uint8 m4[4];
uint8 m8[8];
uint8 m16[16];
uint8 m32[32];
int8 m2Track[2];
int8 m4Track[4];
int8 m8Track[8];
int8 m16Track[16];
int8 m32Track[32];

int16 trackSum;

uint8 symbolNext;
uint8 lMask;

/* Hamming matrices 
Syndrome decoding method is used.

Generator matrix: (codewords are hard-coded into look-up table LUT_HAM 
uint8_t G[4][7] = {
	{1, 0, 0, 0, 1, 1, 1},
	{0, 1, 0, 0, 1, 1, 0},
	{0, 0, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 0, 1, 1}
};
*/
uint8_t H[3][7];
	/*= {
	{1, 1, 1, 0, 1, 0, 0},
	{1, 1, 0, 1, 0, 1, 0},
	{1, 0, 1, 1, 0, 0, 1}
};*/

uint8_t symTx[31];
uint8_t symCnt;

uint8_t colValH[7];

#endif /* TXSUBSYSTEM_H */
/* [] END OF FILE */