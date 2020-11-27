/*******************************************************************************
* File Name: PwmPIN1.h  
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

#if !defined(CY_PINS_PwmPIN1_H) /* Pins PwmPIN1_H */
#define CY_PINS_PwmPIN1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PwmPIN1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PwmPIN1__PORT == 15 && ((PwmPIN1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PwmPIN1_Write(uint8 value);
void    PwmPIN1_SetDriveMode(uint8 mode);
uint8   PwmPIN1_ReadDataReg(void);
uint8   PwmPIN1_Read(void);
void    PwmPIN1_SetInterruptMode(uint16 position, uint16 mode);
uint8   PwmPIN1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PwmPIN1_SetDriveMode() function.
     *  @{
     */
        #define PwmPIN1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PwmPIN1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PwmPIN1_DM_RES_UP          PIN_DM_RES_UP
        #define PwmPIN1_DM_RES_DWN         PIN_DM_RES_DWN
        #define PwmPIN1_DM_OD_LO           PIN_DM_OD_LO
        #define PwmPIN1_DM_OD_HI           PIN_DM_OD_HI
        #define PwmPIN1_DM_STRONG          PIN_DM_STRONG
        #define PwmPIN1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PwmPIN1_MASK               PwmPIN1__MASK
#define PwmPIN1_SHIFT              PwmPIN1__SHIFT
#define PwmPIN1_WIDTH              1u

/* Interrupt constants */
#if defined(PwmPIN1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PwmPIN1_SetInterruptMode() function.
     *  @{
     */
        #define PwmPIN1_INTR_NONE      (uint16)(0x0000u)
        #define PwmPIN1_INTR_RISING    (uint16)(0x0001u)
        #define PwmPIN1_INTR_FALLING   (uint16)(0x0002u)
        #define PwmPIN1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PwmPIN1_INTR_MASK      (0x01u) 
#endif /* (PwmPIN1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PwmPIN1_PS                     (* (reg8 *) PwmPIN1__PS)
/* Data Register */
#define PwmPIN1_DR                     (* (reg8 *) PwmPIN1__DR)
/* Port Number */
#define PwmPIN1_PRT_NUM                (* (reg8 *) PwmPIN1__PRT) 
/* Connect to Analog Globals */                                                  
#define PwmPIN1_AG                     (* (reg8 *) PwmPIN1__AG)                       
/* Analog MUX bux enable */
#define PwmPIN1_AMUX                   (* (reg8 *) PwmPIN1__AMUX) 
/* Bidirectional Enable */                                                        
#define PwmPIN1_BIE                    (* (reg8 *) PwmPIN1__BIE)
/* Bit-mask for Aliased Register Access */
#define PwmPIN1_BIT_MASK               (* (reg8 *) PwmPIN1__BIT_MASK)
/* Bypass Enable */
#define PwmPIN1_BYP                    (* (reg8 *) PwmPIN1__BYP)
/* Port wide control signals */                                                   
#define PwmPIN1_CTL                    (* (reg8 *) PwmPIN1__CTL)
/* Drive Modes */
#define PwmPIN1_DM0                    (* (reg8 *) PwmPIN1__DM0) 
#define PwmPIN1_DM1                    (* (reg8 *) PwmPIN1__DM1)
#define PwmPIN1_DM2                    (* (reg8 *) PwmPIN1__DM2) 
/* Input Buffer Disable Override */
#define PwmPIN1_INP_DIS                (* (reg8 *) PwmPIN1__INP_DIS)
/* LCD Common or Segment Drive */
#define PwmPIN1_LCD_COM_SEG            (* (reg8 *) PwmPIN1__LCD_COM_SEG)
/* Enable Segment LCD */
#define PwmPIN1_LCD_EN                 (* (reg8 *) PwmPIN1__LCD_EN)
/* Slew Rate Control */
#define PwmPIN1_SLW                    (* (reg8 *) PwmPIN1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PwmPIN1_PRTDSI__CAPS_SEL       (* (reg8 *) PwmPIN1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PwmPIN1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PwmPIN1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PwmPIN1_PRTDSI__OE_SEL0        (* (reg8 *) PwmPIN1__PRTDSI__OE_SEL0) 
#define PwmPIN1_PRTDSI__OE_SEL1        (* (reg8 *) PwmPIN1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PwmPIN1_PRTDSI__OUT_SEL0       (* (reg8 *) PwmPIN1__PRTDSI__OUT_SEL0) 
#define PwmPIN1_PRTDSI__OUT_SEL1       (* (reg8 *) PwmPIN1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PwmPIN1_PRTDSI__SYNC_OUT       (* (reg8 *) PwmPIN1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PwmPIN1__SIO_CFG)
    #define PwmPIN1_SIO_HYST_EN        (* (reg8 *) PwmPIN1__SIO_HYST_EN)
    #define PwmPIN1_SIO_REG_HIFREQ     (* (reg8 *) PwmPIN1__SIO_REG_HIFREQ)
    #define PwmPIN1_SIO_CFG            (* (reg8 *) PwmPIN1__SIO_CFG)
    #define PwmPIN1_SIO_DIFF           (* (reg8 *) PwmPIN1__SIO_DIFF)
#endif /* (PwmPIN1__SIO_CFG) */

/* Interrupt Registers */
#if defined(PwmPIN1__INTSTAT)
    #define PwmPIN1_INTSTAT            (* (reg8 *) PwmPIN1__INTSTAT)
    #define PwmPIN1_SNAP               (* (reg8 *) PwmPIN1__SNAP)
    
	#define PwmPIN1_0_INTTYPE_REG 		(* (reg8 *) PwmPIN1__0__INTTYPE)
#endif /* (PwmPIN1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PwmPIN1_H */


/* [] END OF FILE */
