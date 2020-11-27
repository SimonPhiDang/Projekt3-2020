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

#include "i2cKommunikation.h"
#include "project.h"

uint8 byteCnt;   
uint8 wrBuf[3];
uint8 i;

void init_i2c()
{
//    I2C_SlaveInitWriteBuf((uint8 *) wrBuf, 3);
//    I2C_Start();
}

void I2C_Kommunikation()
{
      if(0u != (I2C_SlaveStatus() & I2C_SSTAT_WR_CMPLT)) 
         { 
            byteCnt = I2C_SlaveGetWriteBufSize(); 
            I2C_SlaveClearWriteStatus(); 
            
            if(wrBuf[0] == 0b00000001)
                {
                  //Funktion
                }
            else if (wrBuf[0] == 0b00000010)
            {
                // funktion
            }
            I2C_SlaveClearWriteBuf(); 
         }
}

/* [] END OF FILE */


/* [] END OF FILE */
