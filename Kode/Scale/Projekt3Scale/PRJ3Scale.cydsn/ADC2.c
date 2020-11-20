#include "ADC2.h"
#include "project.h"
#include <stdio.h>

void ADC_init()
{
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();
}

float ADC_Measure()
{
//    char uartBuffer[256];
//    char uartBuffer2[256];  
    
    if (ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT))
        {
            uint16_t result = ADC_SAR_1_GetResult16();
            float kg = 0.0005 * result - 0.0553;
            return kg;
        }
    return 0;
}