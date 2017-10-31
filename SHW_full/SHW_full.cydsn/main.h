#if !defined(MAIN_H)
#define MAIN_H
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
#include "serial.h"
#include "dlm.h"
#include "packetman.h"
#include "dimmingcontrol.h"



/* Control register for utils */
#define CREG_DEBUG_LED	0x01
#define CREG_I2C_SCL	0x02
#define CREG_I2C_SDA	0x04
#define CREG_INIT_TX	0x10

	
uint8 sh_test;
uint8 sh_load;
uint8 sh_fifo;
		
	
#endif /* MAIN_H */
/* [] END OF FILE */