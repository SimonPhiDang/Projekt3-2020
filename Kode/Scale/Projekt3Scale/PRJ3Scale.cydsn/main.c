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
#include "ADC2.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    ADC_init();
    
    for(;;)
    {
        float kg = ADC_Measure();
        
        if(kg > 0.5)
        {
            LED_Write(1);
        }
        else
        {
            LED_Write(0);
        }
        
        CyDelay(500);
    }
}

/* [] END OF FILE */