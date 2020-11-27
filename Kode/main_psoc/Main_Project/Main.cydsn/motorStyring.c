/* ========================================
 *
 * Copyright BEERTRESS, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF BEERTRESS.
 *
 * ========================================
*/

#include "motorStyring.h"
#include "project.h"

void initMotor()
{
    PWM1_Start();
    PWM2_Start();
}
void driveForward()
{
    // Sætter direction på DC motor ved hjælp af H-Bro
    in1_Write(1);
    in2_Write(0);
    in3_Write(0);
    in4_Write(1);
    // Starter PWM
    PWM1_Start();
    PWM2_Start();
    // Sætter PWM til 100%
    PWM2_WriteCompare(100);
    PWM1_WriteCompare(100);
}

void driveBackward()
{   
    // Sætter direction på DC motor ved hjælp af H-Bro
    in1_Write(0);
    in2_Write(1);
    in3_Write(3);
    in4_Write(4);
    // Starter PWM
    PWM1_Start();
    PWM2_Start();
    // Sætter PWM til 100%
    PWM2_WriteCompare(100);
    PWM1_WriteCompare(100);
}

void driveLeft()
{
    // Starter PWM i venstre side, stopper PWM i højre.
    PWM1_Start();
    PWM2_Stop();
    // Sætter PWM til 100%
    PWM1_WriteCompare(100);
}


void driveRight()
{
    // Starter PWM i højre side, stopper PWM i venstre.
    PWM1_Stop();
    PWM2_Start();
    // Sætter PWM til 100%
    PWM2_WriteCompare(100);
}

void driveStop()
{
    // Stopper PWM
    PWM1_Stop();
    PWM2_Stop();
}



/* [] END OF FILE */
