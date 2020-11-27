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
#include "colorSensor.h"
#include "i2cKommunikation.h"



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //inits
    init_i2c();
    initMotor(); //Motor
    ADC_init();  //Vægtsensor
    color_init_start(); //Colorsensor

    for(;;)
    {
        
    }
}

/* [] END OF FILE */
