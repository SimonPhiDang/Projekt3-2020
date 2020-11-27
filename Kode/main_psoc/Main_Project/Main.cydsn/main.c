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

// Includes af bibloteker
#include "motorStyring.h"
#include "Scale.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //inits
    initMotor(); //Motor
    ADC_init();  //Vægtsensor

    for(;;)
    {
        
    }
}

/* [] END OF FILE */
