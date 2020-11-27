/*******************************************************************************
* File Name: in3.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_in3_H) /* Pins in3_H */
#define CY_PINS_in3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "in3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 in3__PORT == 15 && ((in3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    in3_Write(uint8 value);
void    in3_SetDriveMode(uint8 mode);
uint8   in3_ReadDataReg(void);
uint8   in3_Read(void);
void    in3_SetInterruptMode(uint16 position, uint16 mode);
uint8   in3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the in3_SetDriveMode() function.
     *  @{
     */
        #define in3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define in3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define in3_DM_RES_UP          PIN_DM_RES_UP
        #define in3_DM_RES_DWN         PIN_DM_RES_DWN
        #define in3_DM_OD_LO           PIN_DM_OD_LO
        #define in3_DM_OD_HI           PIN_DM_OD_HI
        #define in3_DM_STRONG          PIN_DM_STRONG
        #define in3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define in3_MASK               in3__MASK
#define in3_SHIFT              in3__SHIFT
#define in3_WIDTH              1u

/* Interrupt constants */
#if defined(in3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in in3_SetInterruptMode() function.
     *  @{
     */
        #define in3_INTR_NONE      (uint16)(0x0000u)
        #define in3_INTR_RISING    (uint16)(0x0001u)
        #define in3_INTR_FALLING   (uint16)(0x0002u)
        #define in3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define in3_INTR_MASK      (0x01u) 
#endif /* (in3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define in3_PS                     (* (reg8 *) in3__PS)
/* Data Register */
#define in3_DR                     (* (reg8 *) in3__DR)
/* Port Number */
#define in3_PRT_NUM                (* (reg8 *) in3__PRT) 
/* Connect to Analog Globals */                                                  
#define in3_AG                     (* (reg8 *) in3__AG)                       
/* Analog MUX bux enable */
#define in3_AMUX                   (* (reg8 *) in3__AMUX) 
/* Bidirectional Enable */                                                        
#define in3_BIE                    (* (reg8 *) in3__BIE)
/* Bit-mask for Aliased Register Access */
#define in3_BIT_MASK               (* (reg8 *) in3__BIT_MASK)
/* Bypass Enable */
#define in3_BYP                    (* (reg8 *) in3__BYP)
/* Port wide control signals */                                                   
#define in3_CTL                    (* (reg8 *) in3__CTL)
/* Drive Modes */
#define in3_DM0                    (* (reg8 *) in3__DM0) 
#define in3_DM1                    (* (reg8 *) in3__DM1)
#define in3_DM2                    (* (reg8 *) in3__DM2) 
/* Input Buffer Disable Override */
#define in3_INP_DIS                (* (reg8 *) in3__INP_DIS)
/* LCD Common or Segment Drive */
#define in3_LCD_COM_SEG            (* (reg8 *) in3__LCD_COM_SEG)
/* Enable Segment LCD */
#define in3_LCD_EN                 (* (reg8 *) in3__LCD_EN)
/* Slew Rate Control */
#define in3_SLW                    (* (reg8 *) in3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define in3_PRTDSI__CAPS_SEL       (* (reg8 *) in3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define in3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) in3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define in3_PRTDSI__OE_SEL0        (* (reg8 *) in3__PRTDSI__OE_SEL0) 
#define in3_PRTDSI__OE_SEL1        (* (reg8 *) in3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define in3_PRTDSI__OUT_SEL0       (* (reg8 *) in3__PRTDSI__OUT_SEL0) 
#define in3_PRTDSI__OUT_SEL1       (* (reg8 *) in3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define in3_PRTDSI__SYNC_OUT       (* (reg8 *) in3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(in3__SIO_CFG)
    #define in3_SIO_HYST_EN        (* (reg8 *) in3__SIO_HYST_EN)
    #define in3_SIO_REG_HIFREQ     (* (reg8 *) in3__SIO_REG_HIFREQ)
    #define in3_SIO_CFG            (* (reg8 *) in3__SIO_CFG)
    #define in3_SIO_DIFF           (* (reg8 *) in3__SIO_DIFF)
#endif /* (in3__SIO_CFG) */

/* Interrupt Registers */
#if defined(in3__INTSTAT)
    #define in3_INTSTAT            (* (reg8 *) in3__INTSTAT)
    #define in3_SNAP               (* (reg8 *) in3__SNAP)
    
	#define in3_0_INTTYPE_REG 		(* (reg8 *) in3__0__INTTYPE)
#endif /* (in3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_in3_H */


/* [] END OF FILE */
