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
#include <stdio.h>
#include <stdint.h>
#include "colorSensor.h"

static char str[128] ;
void print(char *str) ;
int main (void)
{
    standardColor();
    UART_1_Start();  
    snprintf(str,sizeof(str),"MAIN"); 
    
 for(;;)
{
    int tal=getColor();
    snprintf(str,sizeof(str),"%d",tal); 
    UART_1_PutString(str) ;
    
    switch(tal)
    {
     case 1:
        {snprintf(str,sizeof(str),"RED\n\r");}
        break;
     case 2:
        {snprintf(str,sizeof(str),"GREEN\n\r");}
        break;   
     case 3:
        {snprintf(str,sizeof(str),"BLUE\n\r");}
        break; 
     case 4:
        {snprintf(str,sizeof(str),"UNKNOWN\n\r");}
        break; 
     default:
        {snprintf(str,sizeof(str),"DEFAULT\n\r");}
        break;
    }
    
    UART_1_PutString(str) ;
 } 


return 0;
    
}



// [] END OF FILE 
