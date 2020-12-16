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
#include "i2cKommunikation.h"

int orderReceived;
int distance;
uint8 rdBuf[8] = {0};


void handleOrderReceived(int orderReceived);
void beertressWorkWork(int type, int table, int amount);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   
    
    
    //inits
    initMotor(); //Motor
    ADC_init();  //Vægtsensor
    init_Color(); //Colorsensor
    initDistSens(); //Afstandssensor
    initiere_I2Ckommunikation(); //I2C
    
    CyDelay(3000);
    standardColor();

        for(;;)
       {
        int i = newOrder();
        handleOrderReceived(i);   
       }
}

void beertressWorkWork(int type, int table, int amount)
{
    I2C_SlaveInitReadBuf((uint8 *) rdBuf, 8);
    switch(type)
    {
        case 1 :
        {
            int tableCounter = 0;
            driveForward();
            CyDelay(1000);
            for(;;)
            {
                int color = getColor();
                
                if(tableCounter == table)
                {
                    driveStop();
                    CyDelay(1000);
                    
                    int antal = amount*0.346;
                    float vaegt = ADC_Measure();
                    while(vaegt >= 0.246)
                    {
                    }
                    CyDelay(1000);
                    table = 0;
                }
                else if(tableCounter == 3)
                {
                    driveStop();
                    CyDelay(3000);
                    Done_Write(1); // Order done
                    CyDelay(500);
                    while(ADC_Measure() < 0.346) // Empty
                    {
                        rdBuf[0] = 0b00000001;
                    }
                    rdBuf[0] = 0b00000000;
                    Done_Write(0);
                    // I2C_SlaveClearReadBuf();
                    return;
                }
                    
                 while(color == 1) // roed
                 {
                    while(distance < 30)
                    {
                    driveStop();
                    }
                    driveForward();
                    break;
                 }
                  while(color == 2) // groen
                 {
                    while(distance < 30)
                     {
                    driveStop();
                     }
                     driveForward();
                     tableCounter++;
                     CyDelay(500);
                     break;
                 }
                 while(color == 3) // blaa
                 {
                    while(distance < 30)
                     {
                    driveStop();
                     }
                     driveLeft();
                     break;
                 }
                 while(color == 4) // unknown
                 {
                    while(distance < 30)
                     {
                    driveStop();
                     }
                     driveRight();
                     break;
                 }
            }
           
        }
        default :
        break;
    }
}
void handleOrderReceived(int orderReceived)
{
    switch(orderReceived)
    {
        
        case 1 :
        {
            beertressWorkWork(1,1,1);
            break;
        }
        case 2 :
        {
            beertressWorkWork(1,1,2);
            break;
        }
        
         case 3 :
        {
            beertressWorkWork(1,1,3);
            break;
        }
         case 4 :
        {
            beertressWorkWork(1,2,1);
            break;
        }
         case 5 :
        {
            beertressWorkWork(1,2,2);
            break;
        }
         case 6 :
        {
            beertressWorkWork(1,2,3);
            break;
        }
        default :
        break;
    }
}



/* [] END OF FILE */