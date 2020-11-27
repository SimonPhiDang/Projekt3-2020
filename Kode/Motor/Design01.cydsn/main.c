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
#include "motorStyring.h"
#include <stdbool.h>
#include <stdio.h>

CY_ISR_PROTO(IsrUART_handler);
void handleByteReceived(uint8_t byteReceived);
uint8 currentSpeed = 0;

CY_ISR(IsrUART_handler)
{
    uint8_t bytesToRead = UART_GetRxBufferSize();
    while (bytesToRead > 0)
    {
        uint8_t byteReceived = UART_ReadRxData();
        UART_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isrUART_StartEx(IsrUART_handler);
    UART_Start();
    initMotor();
    UART_PutString("Beertress Motor Options!\r\n");
    UART_PutString("-----------------------\r\n");
    UART_PutString("Press 1 for FORWARD\r\n");
    UART_PutString("Press 2 for BACKWARD\r\n");
    UART_PutString("Press 3 for STOP\r\n");
    UART_PutString("Press 'L' (lowercase) for LEFT\r\n");
    UART_PutString("Press 'R' (lowercase) for RIGHT\r\n");
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    switch(byteReceived)
    {
        case '1' :
        {
            driveForward();
        }
        break;
        case '2' :
        {
            driveBackward();
        }
        break;
        case '3' :
        {
            driveStop();
        }
        break;
        case 'l' :
        {
            driveLeft();
        }
        break;
        case 'r' :
        {
            driveRight();
        }
        break;
        default :
        {
            // do nothing
        }
        break;
    }
}

/* [] END OF FILE */
