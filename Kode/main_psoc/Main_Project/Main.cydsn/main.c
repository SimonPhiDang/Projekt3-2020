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
//#include "I2Ckommunikation.h"
#include "project.h"


// Includes af bibloteker
#include "motorStyring.h"
#include "Scale.h"
#include "colorSensor.h"
#include "Afstandssensor.h"

int orderReceived;
int distance;

void handleOrderReceived(int orderReceived);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    
    
    //inits
 //   initMotor(); //Motor
    ADC_init();  //Vægtsensor
 //   init_start(); //Colorsensor
 //   initDistSens();
//    initiere_I2Ckommunikation();
    for(;;)
    {
        float kg = ADC_Measure();
        if(kg > 0.3)
        {
            led_Write(1);
        }
        else
        {
            led_Write(0);
        }
        
        CyDelay(500);
    }
//    CyDelay(3000);
//    standardColor();
//    driveForward();
//    CyDelay(1000);
//    for(;;)
//    {
//        
//        int color = getColor();
//        while(color == 1)
//        {
//            while(distance < 30)
//            {
//                driveStop();
//            }
//            driveForward();
//            break;
//        }
//        while(color == 2)
//        {
//            driveStop();
//            break;
//        }
//        while(color == 3)
//        {
//            while(distance < 30)
//            {
//                driveStop();
//            }
//            driveLeft();
//            break;
//        }
//        while(color == 4)
//        {
//            while(distance < 30)
//            {
//                driveStop();
//            }
//            driveRight();
//            break;
//        }
//        
       // int i = I2C_Kommunikation();
       //  handleOrderReceived(i);
            
    //}
}

void handleOrderReceived(int orderReceived)
{
    switch(orderReceived)
    {
        
        case 1 :
        {
            driveForward();
            CyDelay(5000);
            Done_Write(1);
            driveStop();
            CyDelay(1000);
            Done_Write(0);
            break;
        }
        case 2 :
        {
            driveBackward();
            CyDelay(5000);
            Done_Write(1);
            driveStop();
            CyDelay(1000);
            Done_Write(0);
            break;
        }
        default :
        break;
    }
}



/* [] END OF FILE */