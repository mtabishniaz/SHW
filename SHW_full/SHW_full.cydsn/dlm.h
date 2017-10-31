#if !defined(DLM_H)
#define DLM_H

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
    
#include <project.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
	
#include "serial.h"

    
/* Macros */    
#define NODE_ID_1       0x01 // COM14
#define NODE_ID_2       0x02 // COM3
#define NODE_ID_3       0x03
    
    
    
/* Function Prototypes */
void INIT_DLM();
void send_device_id();
void setAddress();
void router_send_arp();
void router_send_arp_reply(uint8 dst);  
void router_send_rssi_check();
void router_send_rssi_check_reply();


    
/* Structs */
typedef struct{
    uint8 node;
    uint8 noise;
    uint8 modLevel;
}Link;

typedef struct{
    Link links[3];
    uint8 noise;
}Port;
    
    
/* Globals */    
uint32 deviceID[2];
uint8 deviceAddress;
Port routingTable[3];



#endif /* DLM_H */
/* [] END OF FILE */