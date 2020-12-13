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
uint8 wrBuf[8];
uint8 rdBuf[8];
uint8 i;

void init_i2c()
{
    I2C_SlaveInitWriteBuf((uint8 *) wrBuf, 8);
    I2C_SlaveInitReadBuf((uint8 *) wrBuf, 8);
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
                                    rdBuf[0] = 0b00000001;
                                    I2C_SlaveClearWriteBuf();
                                    I2C_SlaveClearReadBuf();
                                    return 1;
                                    break;
                                }
                                case 0b00000010:
                                {
                                    rdBuf[0] = 0b00000010;
                                    I2C_SlaveClearWriteBuf();
                                    I2C_SlaveClearReadBuf();
                                    return 2;
                                    break;
                                }
                                case 0b00000011:
                                {
                                    rdBuf[0] = 0b00000011;
                                    I2C_SlaveClearWriteBuf();
                                    I2C_SlaveClearReadBuf();
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
                                    rdBuf[0] = 0b00000100;
                                    I2C_SlaveClearWriteBuf();
                                    I2C_SlaveClearReadBuf();
                                    return 4;
                                    break;
                                }
                                case 0b00000010:
                                {
                                    rdBuf[0] = 0b00000101;
                                    I2C_SlaveClearWriteBuf();
                                    I2C_SlaveClearReadBuf();
                                    return 5;
                                    break;
                                }
                                case 0b00000011:
                                {
                                    rdBuf[0] = 0b00000110;
                                    I2C_SlaveClearWriteBuf();
                                    I2C_SlaveClearReadBuf();
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
                    
                    
            
//            if(wrBuf[0] == 0b00000001) // hvis der er valgt øl
//                {
//                    if(wrBuf[1] == 0b00000001) // hvis der er valgt bord 1
//                        {  
//                            if(wrBuf[2] == 0b00000001) // hvis der er valgt 1 øl
//                                {
//                                    rdBuf[0] = 0x1;
//                                    I2C_SlaveClearWriteBuf();
//                                    I2C_SlaveClearReadBuf();
//                                    return 1;
//                                }
//                            else if(wrBuf[2] == 0b00000010) // hvis der er valgt 2 øl
//                                {
//                                    rdBuf[0] = 0x2;
//                                    I2C_SlaveClearWriteBuf();
//                                    I2C_SlaveClearReadBuf();
//                                    return 2;
//                                }
//                           else if(wrBuf[2] == 0b00000011) // hvis der er valgt 3 øl
//                            {
//                                rdBuf[0] = 0x3;
//                                I2C_SlaveClearWriteBuf();
//                                I2C_SlaveClearReadBuf();
//                                return 3;
//                            }
//                        }
//                    else if(wrBuf[1] == 0b00000010) // hvis der er valgt bord 2
//                        {
//                            if(wrBuf[2] == 0b00000001) // hvis der er valgt 1 øl
//                                {
//                                    rdBuf[0] = 0x4;
//                                    I2C_SlaveClearWriteBuf();
//                                    I2C_SlaveClearReadBuf();
//                                    return 4;
//                                }
//                            else if(wrBuf[2] == 0b00000010) // hvis der er valgt 2 øl
//                                {
//                                    rdBuf[0] = 0x5;
//                                    I2C_SlaveClearWriteBuf();
//                                    I2C_SlaveClearReadBuf();
//                                    return 5;
//                                }
//                           else if(wrBuf[2] == 0b00000011) // hvis der er valgt 3 øl
//                            {
//                                rdBuf[0] = 0x6;
//                                I2C_SlaveClearWriteBuf();
//                                I2C_SlaveClearReadBuf();
//                                return 6;
//                            }
//                            else
//                            {
//                                I2C_SlaveClearWriteBuf();
//                                I2C_SlaveClearReadBuf();
//                                return 0;
//                            }
//                        }
//                    else
//                        {
//                            I2C_SlaveClearWriteBuf();
//                            I2C_SlaveClearReadBuf();
//                            return 0;
//                        }
//                }
//            else
//            {
//                I2C_SlaveClearWriteBuf(); 
//                I2C_SlaveClearReadBuf();
//                return 0;
//            }
//            I2C_SlaveClearWriteBuf(); 
         }
    return 0;
}

/* [] END OF FILE */


/* [] END OF FILE */
