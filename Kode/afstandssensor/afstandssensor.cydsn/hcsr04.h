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

#ifndef HCSR04_H
#define HCSR04_H

// Sending trigger to send out ultra sonic waves 
void initDistSens();

// Starts timer and returns counter
int calcDist();

// Returns distance
int getDistance();

// Outputs distance to UART
int outputDistanceToUART(int count);


    
#endif

/* [] END OF FILE */
