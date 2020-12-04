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
#include "hcsr04.h"

int distance;


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    initDistSens();
    
    for(;;)
    {
        distanceToggleLED(distance);
    }
}


/* [] END OF FILE */