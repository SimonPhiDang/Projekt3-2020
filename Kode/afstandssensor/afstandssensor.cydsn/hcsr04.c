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
    //Capturing timer count
    int capture = Timer_ReadCapture();
    
    //Used for testing
    /*snprintf(outputBuffer, sizeof(outputBuffer), "Counter: %d \r\n", capture);
    UART_1_PutString(outputBuffer);*/
    
    //Calculating distance in cm
    distance = (65535 - capture) * 0.017;
    
    //Used to quickly fix problem, when the sensor doesnt register an object
    if(capture > 65250 && capture < 65340)
    {
        distance = 500;
    }
    return distance;
}

int getDistance()
{
    return distance;
}

int outputDistanceToUART(int distance)
{
    snprintf(outputBuffer, sizeof(outputBuffer), "Distance: %d cm \r\n", distance);
    UART_1_PutString(outputBuffer);
    return distance;
}


CY_ISR(Timer_int_Handler)
{
    distance = outputDistanceToUART(calcDist());
    Timer_ClearFIFO();
}

/* [] END OF FILE */
