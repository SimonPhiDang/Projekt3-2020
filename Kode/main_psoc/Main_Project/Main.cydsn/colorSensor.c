
/* ========================================
 *
 * Copyright Lucas, 2020
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

#define COUNTER_SIZE 10000
uint32_t freq = 0;
int dataReady = 0;
int Counter_cycle = 0;

#define STRING_LENGTH 128  
extern char str[] ;
void print(char *str) ;

CY_ISR(timer_isr)//Timer i interrupt routine
{
    Counter_Stop();
    Timer_Stop();
    freq = Counter_ReadCounter();
    freq += Counter_cycle * COUNTER_SIZE;
    OE_Write(1);
    Timer_INT_ClearPending();
    dataReady = 1;
}


CY_ISR(counter_isr)//Counter i interrupt routine
{
    Counter_INT_ClearPending();
    Counter_cycle++;
}

void color_init_start(void)//Starter de indbyggede funktioner fra topdesign: UART, Timer, Counter
{
    Timer_INT_StartEx(timer_isr);
    Counter_INT_StartEx(counter_isr);
}

void read_color(void)//Omdanner inputs til frekvens vha. counter og timeren
{
    OE_Write(0);
    Control_Reg_Write(1);
    CyDelay(1);
    Control_Reg_Write(0);
    dataReady = 0;
    Counter_cycle = 0;
    Counter_Start();
    Timer_INT_StartEx(timer_isr);
    Counter_INT_StartEx(counter_isr);
    
    Timer_Start();
}

int get_freq(char color)//Modtager input på baggrund af indstillinger for farvefilter samt scaling. Der er valgt at nedskalere frekvens til 2%
{
    //scaling 2%
    S0_Write(0);
    S1_Write(1);
    
   if(color=='r')//Rød farve-filter tilføjes og frekvensen registeres
    {   
        S2_Write(0);
        S3_Write(0);
        read_color();
    }
    
    else if(color=='g')//Grøn farve-filter tilføjes og frekvensen registeres
    { 
        S2_Write(1);
        S3_Write(1);
        read_color();
    }
    
    else if(color=='b')//Blå farve-filter tilføjes og frekvensen registeres
    {
        S2_Write(0);
        S3_Write(1);
        read_color();
    }
    else if(color=='c')//'Clear' farve-filter tilføjes og frekvensen registeres
    {
        S2_Write(1);
        S3_Write(0);
        read_color();
    }
    
    while(!dataReady)
    {
    ;
    }
    return freq;
}

char str[STRING_LENGTH+1] ; /* print buff */


int getColor()
{
uint freqR, freqG, freqB = 0;
uint countR, countG, countB = 0;
    
    color_init_start();
    read_color();
    

            freqR = get_freq('r')-10;
            freqG = get_freq('g')+10;
            freqB = get_freq('b');
            
            //Nedenstående to sætninger bruges til at se frekvensen på farverne
            //sprintf(str,"Red freq: %u Hz, Green freq: %u, Blue freq: %u\n\n\r",freqR,freqG,freqB);
            //print(str);
            
            //Nedenstående er koden der skal bruges
            
             if(freqR>freqG&&freqR>freqB)
                {
                    if(freqR>=100)
                    {
                        countR ++;
                        if(countR==5)
                        {
                            //Indsæt 'driveForward funktion'
                        sprintf(str,"Red color detected\n\r");
                        print(str);
                        countR = 0;
                        }
                        
                    }
                    else
                    {
                        //Indsæt 'driveLeft funktion'
                        sprintf(str,"Unknown color\n\r");
                        print(str);
                    }      
                }

            else if (freqG>freqR&&freqG>freqB)
                {
                        countG ++;
                        if(countG==5)
                        {
                            //Indsæt
                        sprintf(str,"Green color detected\n\r");
                        print(str);
                        countG = 0;
                        }
                }
                
            else if(freqB>freqG&&freqB>freqR)
                {
                        countB ++;
                        if(countB==5)
                        {
                        sprintf(str,"Blue color detected\n\r");
                        print(str);
                        countB = 0;
                        }
                }
                
                else
                {
                        //Indsæt 'driveLeft funktion'
                    sprintf(str,"Unknown color\n\r");
                    print(str);
                }
                       
        
         

        return 0;
}


// [] END OF FILE 
