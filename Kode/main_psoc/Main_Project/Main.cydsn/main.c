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
//#include "Scale.h"
//#include "colorSensor.h"
//#include "i2cKommunikation.h"
#include "Afstandssensor.h"

int distance;

//float fustageKg;
//
//void handleOrderReceived(uint8_t orderReceived)
//{
//    switch(orderReceived)
//    {
//        case 1:
//        {
//            driveForward();
//            CyDelay(5000);
//            Done_Write(1);
//            driveStop();
//            CyDelay(1000);
//            Done_Write(0);
//            break;
//        }
//        case 2:
//        {
//            driveBackward();
//            CyDelay(5000);
//            Done_Write(1);
//            driveStop();
//            CyDelay(1000);
//            Done_Write(0);
//            break;
//        }
//        default:
//        break;
//    }
//}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    //inits
    //init_i2c(); // I2C kommunikation
    initMotor(); //Motor
    //ADC_init();  //Vægtsensor
    //color_init_start(); //Colorsensor
    initDistSens(); // Afstandssensor
    
    //fustageKg = ADC_Measure(); // Måling af nuværende kg
    
    // Send vægt info til I2C så RPI kan sende til personale grænseflade

 
    
    for(;;)  //Ordre loop
    {
        driveForward();
//        //int i = I2C_Kommunikation();  // Få besked fra I2C RPI
//        //handleOrderReceived(i);  // Handler
          while(distance < 30)  // Når afstand på noget mindre end 30 cm stop og vent
         {
            LED_Write(1);
         }
        
        LED_Write(0);
    }
}

/* [] END OF FILE */
