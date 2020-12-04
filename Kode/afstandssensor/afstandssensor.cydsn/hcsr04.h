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

// Outputs distance to UART
int outputDistanceToUART(int count);

// Toggles LED based on distance
void distanceToggleLED(int distance);

    
#endif

/* [] END OF FILE */
