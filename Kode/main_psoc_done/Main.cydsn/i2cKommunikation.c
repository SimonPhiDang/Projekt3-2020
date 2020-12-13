 /* All Rights Reserved
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
uint8 wrBuf[8];
uint8 rdBuf[8];
uint8 i;

void initiere_I2Ckommunikation()
{
    I2C_SlaveInitWriteBuf((uint8 *) wrBuf, 8);
    I2C_Start();
}

char I2C_Kommunikation()
{
      if(0u != (I2C_SlaveStatus() & I2C_SSTAT_WR_CMPLT)) 
         {
            byteCnt = I2C_SlaveGetWriteBufSize(); 
            I2C_SlaveClearWriteStatus(); 
            
            switch(wrBuf[0])
            {
                case 0b00000001:
                {
                    switch(wrBuf[1])
                    {
                        case 0b00000001:
                        {
                            switch (wrBuf[2])
                            {
                                case 0b00000001:
                                {
                                    I2C_SlaveClearWriteBuf();
                                    return 1;
                                    break;
                                }
                                case 0b00000010:
                                {
                                    I2C_SlaveClearWriteBuf();
                                    return 2;
                                    break;
                                }
                                case 0b00000011:
                                {
                                    I2C_SlaveClearWriteBuf();
                                    return 3;
                                    break;
                                   
                                }
                                    default:
                                    break;
                            }
                        }
                        case 0b00000010:
                        {
                            switch(wrBuf[2])
                            {
                                case 0b00000001:
                                {
                                    I2C_SlaveClearWriteBuf();
                                    return 4;
                                    break;
                                }
                                case 0b00000010:
                                {
                                    I2C_SlaveClearWriteBuf();
                                    return 5;
                                    break;
                                }
                                case 0b00000011:
                                {
                                    I2C_SlaveClearWriteBuf();
                                    return 6;
                                    break;
                                }
                                    default:
                                    break;
                            }
                        }
                        default:
                        break;
                    }
                }
                default:
                break;
             }
         }
    return 0;
}

/* [] END OF FILE */


/* [] END OF FILE */
