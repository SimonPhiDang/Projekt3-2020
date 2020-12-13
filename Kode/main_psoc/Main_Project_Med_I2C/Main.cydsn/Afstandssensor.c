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
CY_ISR_PROTO(Timer_int_Handler);


void initDistSens()
{
    
    PWM_Trigger_Start();
    Timer_1_Start();
    Timer_int_1_StartEx(Timer_int_Handler);
    
}

int calcDist()
{
    distance = (65535 - Timer_1_ReadCapture()) * 0.017;
    return distance;
}


CY_ISR(Timer_int_Handler)
{
    Timer_1_ClearFIFO();
}

/* [] END OF FILE */
