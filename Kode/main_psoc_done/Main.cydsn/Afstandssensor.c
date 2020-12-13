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
CY_ISR_PROTO(Timer_int_1_Handler);


void initDistSens()
{
    PWM_Trigger_Start();
    Timer_1_Start();
    Timer_int_1_StartEx(Timer_int_1_Handler);
}

int calcDist()
{
    int capture = Timer_1_ReadCapture();
    
    distance = (65535 - capture) * 0.017;
    if(capture > 65250 && capture < 65340)
    {
        distance = 500;
    }
    return distance;
}

int getDistance(distance)
{
    return distance;
}



CY_ISR(Timer_int_1_Handler)
{
    distance = getDistance(calcDist());
    Timer_1_ClearFIFO();
}

/* [] END OF FILE */