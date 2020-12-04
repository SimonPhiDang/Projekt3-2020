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
#include <stdio.h>
#include <stdlib.h>

int distance;
static char outputBuffer[256];
CY_ISR_PROTO(Timer_int_Handler);


void initDistSens()
{
    PWM_Trigger_Start();
    UART_1_Start();
    Timer_Start();
    Timer_int_StartEx(Timer_int_Handler);
}

int calcDist()
{
    distance = (65535 - Timer_ReadCapture()) * 0.017;
    return distance;
}

int outputDistanceToUART(int distance)
{
    snprintf(outputBuffer, sizeof(outputBuffer), "Distance: %d cm \r\n", distance);
    UART_1_PutString(outputBuffer);
    return distance;
}

void distanceToggleLED(int distance)
{
    if(distance < 30)
    {
        LED_Write(1);
    }
    else if(distance > 35)
    {
        LED_Write(0);
    }
}

CY_ISR(Timer_int_Handler)
{
    distance = outputDistanceToUART(calcDist());
    Timer_ClearFIFO();
}

/* [] END OF FILE */
