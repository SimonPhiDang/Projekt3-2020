
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

void init_start(void)//Starter de indbyggede funktioner fra topdesign: UART, Timer, Counter
{
    CyGlobalIntEnable;
    UART_1_Start();
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

void print(char *str)
{
    UART_1_PutString(str) ;
}

int getColor()
{
uint freqR_0, freqG_0, freqB_0, freqR, freqG, freqB = 0;
uint countR = 0;
uint countG = 0;
uint countB = 0;
uint countU = 0;

    
    init_start();
    read_color();
    
    freqR_0 = get_freq('r');
    freqG_0 = get_freq('g');
    freqB_0 = get_freq('b');
    
        for(;;)
        {
            
            freqR = get_freq('r');
            freqG = get_freq('g');
            freqB = get_freq('b');
           
            
            //Nedenstående to sætninger bruges til at se frekvensen på farverne
            //sprintf(str,"Red freq: %u Hz, Green freq: %u, Blue freq: %u, Clear freq: %u, R0: %u, G0: %u, B0: %u \n\n\r",freqR,freqG,freqB,freqC,freqR_0,freqG_0,freqB_0);
            //print(str);
            
            //Nedenstående er koden der skal bruges
            
        
            
             if(freqR>freqR_0*1.1)
                {
                    if(freqR>freqG&&freqR>freqB)
                    {
                        countR ++;

                        if(countR==2)
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
                        sprintf(str,"Unknown color in red\n\r");
                        print(str);
                    }    
                }

            else if (freqG>freqG_0+1.1)
            {    
                if (freqG>freqB*0.9)
                {
                        countG ++;
                        if(countG==2)
                        {
                            //Indsæt
                        sprintf(str,"Green color detected\n\r");
                        print(str);
                        countG = 0;
                        }
                }
                else
                {
                      sprintf(str,"Blue color detected\n\r");
                      print(str);               
                }
            }    
            else if (freqB>freqB_0*1.1)
            {
            
            
                if (freqB>freqG)
                {
                        countB ++;
                        if(countB==2)
                        {
                        sprintf(str,"Blue color detected\n\r");
                        print(str);
                        countB = 0;
                        }
                }
             }
           
            else
                {
                    countU ++;
                    if(countU==2)
                     {   //Indsæt 'driveLeft funktion'
                    sprintf(str,"Unknown color\n\r");
                    print(str);
                    countU = 0;}
                }
        }  
        
        

        return 0;
}


// [] END OF FILE 
