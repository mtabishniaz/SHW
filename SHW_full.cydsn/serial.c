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

#include "serial.h"


void INIT_SERIAL()
{
	uart_type = UART_FTDI;
	UART_Start();
	
	
    serial_test[0] = 0x39;
    serial_test[1] = 0x37;
	test8 = 21;
	test16 = 999;
}

void serialResolve(uint8* b)
{
    switch(*b) {

        case SERIAL_TEST:
            serialSend8bit(&serial_test[0], 2, SER_TX_TEST);
            serialSend8bit(&test8, 1, SER_TX_TEST8);
            serialSend16bit(&test16, 1, SER_TX_TEST16);
            break;
		case INIT_TX:
			FLAG_SER_EVENT = true;
			FLAG_SER_TX_INIT = true;
			break;
        default:
            break;
    }
    memset(bufferUart, 0, 64);
}

void serialRead()
{
	uint8 errorStatus;
	if (uart_type == UART_FTDI) {
        int cCount = 0;
        bool reading = true;
        while(reading) {
            /* Read status register. */
            uint8 rxStatus = UART_ReadRxStatus();
            
            /* Check if data is received. */
            if((rxStatus & UART_RX_STS_FIFO_NOTEMPTY) != 0u)    
            {
                /* Read received data */
                bufferUart[cCount++] = UART_ReadRxData();    

                /* Check status on error*/
                if((rxStatus & (UART_RX_STS_BREAK      | UART_RX_STS_PAR_ERROR |
                                UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN)) != 0u)
                {
                    errorStatus |= rxStatus & ( UART_RX_STS_BREAK      | UART_RX_STS_PAR_ERROR | 
                                                UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN);
                    reading = false;
					
                }
                else
                {
                    /* Send data backward */
//                    UART_WriteTxData(0x01);
                    CREG_LED_Write(1);
                    CyDelay(20);
                    CREG_LED_Write(0);
                    
                }
            }
            else {
                reading = false;
            }
            if (cCount > 0) {
//				UART_WriteTxData(0x02);
                serialResolve(bufferUart);
            }
        }

    }
}



void serialSend8bit(uint8* data, uint16 length, uint8 msgID) 
{
    uint16 i;
    uint8 bytes[3];

    for (i=0; i<length; i++) {
        if (length > 1) bytes[0] = SER_MASK_CTRL | SER_MASK_8BIT | SER_MASK_ARRAY | ((data[i] & 0xF0) >> 4);
        else bytes[0] = SER_MASK_CTRL | SER_MASK_8BIT | SER_MASK_SINGLE | ((data[i] & 0xF0) >> 4);
        
        bytes[1] = SER_MASK_DATA | SER_MASK_8BIT | ((data[i] & 0x0F) << 2);
        bytes[2] = msgID;
        
        if (uart_type == UART_FTDI) {
            UART_PutArray(&bytes[0], 3);
        }
//        else {
//            while(USBUART_1_CDCIsReady() == 0u);
//            USBUART_1_PutData(&bytes[0], 3);
//        }
    }
    
}

void serialSend16bit(uint16* data, uint16 length, uint8 msgID) 
{
    uint16 i;
    uint8 bytes[4];

    for (i=0; i<length; i++) {
        if (length > 1) bytes[0] = SER_MASK_CTRL | SER_MASK_16BIT | SER_MASK_ARRAY | ((data[i] & 0xF000) >> 12);
        else bytes[0] = SER_MASK_CTRL | SER_MASK_16BIT | SER_MASK_SINGLE | ((data[i] & 0x0F00) >> 12);
        
        bytes[1] = SER_MASK_DATA | SER_MASK_16BIT | ((data[i] & 0x0FC0) >> 6);
        bytes[2] = SER_MASK_DATA | SER_MASK_16BIT | ((data[i] & 0x003F));
        bytes[3] = msgID;
        
        if (uart_type == UART_FTDI) {
            UART_PutArray(&bytes[0], 4);
        }
//        else {
//            while(USBUART_1_CDCIsReady() == 0u);
//            USBUART_1_PutData(&bytes[0], 4);
//        }
    }

}

void serialSendS16bit(int16* data, uint16 length, uint8 msgID) 
{
    uint16 i;
    uint8 bytes[4];

    for (i=0; i<length; i++) {
		if (data[i] < 0) {
		                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                