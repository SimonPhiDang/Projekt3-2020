/*******************************************************************************
* File Name: PwmPIN.h  
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

#if !defined(CY_PINS_PwmPIN_H) /* Pins PwmPIN_H */
#define CY_PINS_PwmPIN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PwmPIN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PwmPIN__PORT == 15 && ((PwmPIN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PwmPIN_Write(uint8 value);
void    PwmPIN_SetDriveMode(uint8 mode);
uint8   PwmPIN_ReadDataReg(void);
uint8   PwmPIN_Read(void);
void    PwmPIN_SetInterruptMode(uint16 position, uint16 mode);
uint8   PwmPIN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PwmPIN_SetDriveMode() function.
     *  @{
     */
        #define PwmPIN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PwmPIN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PwmPIN_DM_RES_UP          PIN_DM_RES_UP
        #define PwmPIN_DM_RES_DWN         PIN_DM_RES_DWN
        #define PwmPIN_DM_OD_LO           PIN_DM_OD_LO
        #define PwmPIN_DM_OD_HI           PIN_DM_OD_HI
        #define PwmPIN_DM_STRONG          PIN_DM_STRONG
        #define PwmPIN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PwmPIN_MASK               PwmPIN__MASK
#define PwmPIN_SHIFT              PwmPIN__SHIFT
#define PwmPIN_WIDTH              1u

/* Interrupt constants */
#if defined(PwmPIN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PwmPIN_SetInterruptMode() function.
     *  @{
     */
        #define PwmPIN_INTR_NONE      (uint16)(0x0000u)
        #define PwmPIN_INTR_RISING    (uint16)(0x0001u)
        #define PwmPIN_INTR_FALLING   (uint16)(0x0002u)
        #define PwmPIN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PwmPIN_INTR_MASK      (0x01u) 
#endif /* (PwmPIN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PwmPIN_PS                     (* (reg8 *) PwmPIN__PS)
/* Data Register */
#define PwmPIN_DR                     (* (reg8 *) PwmPIN__DR)
/* Port Number */
#define PwmPIN_PRT_NUM                (* (reg8 *) PwmPIN__PRT) 
/* Connect to Analog Globals */                                                  
#define PwmPIN_AG                     (* (reg8 *) PwmPIN__AG)                       
/* Analog MUX bux enable */
#define PwmPIN_AMUX                   (* (reg8 *) PwmPIN__AMUX) 
/* Bidirectional Enable */                                                        
#define PwmPIN_BIE                    (* (reg8 *) PwmPIN__BIE)
/* Bit-mask for Aliased Register Access */
#define PwmPIN_BIT_MASK               (* (reg8 *) PwmPIN__BIT_MASK)
/* Bypass Enable */
#define PwmPIN_BYP                    (* (reg8 *) PwmPIN__BYP)
/* Port wide control signals */                                                   
#define PwmPIN_CTL                    (* (reg8 *) PwmPIN__CTL)
/* Drive Modes */
#define PwmPIN_DM0                    (* (reg8 *) PwmPIN__DM0) 
#define PwmPIN_DM1                    (* (reg8 *) PwmPIN__DM1)
#define PwmPIN_DM2                    (* (reg8 *) PwmPIN__DM2) 
/* Input Buffer Disable Override */
#define PwmPIN_INP_DIS                (* (reg8 *) PwmPIN__INP_DIS)
/* LCD Common or Segment Drive */
#define PwmPIN_LCD_COM_SEG            (* (reg8 *) PwmPIN__LCD_COM_SEG)
/* Enable Segment LCD */
#define PwmPIN_LCD_EN                 (* (reg8 *) PwmPIN__LCD_EN)
/* Slew Rate Control */
#define PwmPIN_SLW                    (* (reg8 *) PwmPIN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PwmPIN_PRTDSI__CAPS_SEL       (* (reg8 *) PwmPIN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PwmPIN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PwmPIN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PwmPIN_PRTDSI__OE_SEL0        (* (reg8 *) PwmPIN__PRTDSI__OE_SEL0) 
#define PwmPIN_PRTDSI__OE_SEL1        (* (reg8 *) PwmPIN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PwmPIN_PRTDSI__OUT_SEL0       (* (reg8 *) PwmPIN__PRTDSI__OUT_SEL0) 
#define PwmPIN_PRTDSI__OUT_SEL1       (* (reg8 *) PwmPIN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PwmPIN_PRTDSI__SYNC_OUT       (* (reg8 *) PwmPIN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PwmPIN__SIO_CFG)
    #define PwmPIN_SIO_HYST_EN        (* (reg8 *) PwmPIN__SIO_HYST_EN)
    #define PwmPIN_SIO_REG_HIFREQ     (* (reg8 *) PwmPIN__SIO_REG_HIFREQ)
    #define PwmPIN_SIO_CFG            (* (reg8 *) PwmPIN__SIO_CFG)
    #define PwmPIN_SIO_DIFF           (* (reg8 *) PwmPIN__SIO_DIFF)
#endif /* (PwmPIN__SIO_CFG) */

/* Interrupt Registers */
#if defined(PwmPIN__INTSTAT)
    #define PwmPIN_INTSTAT            (* (reg8 *) PwmPIN__INTSTAT)
    #define PwmPIN_SNAP               (* (reg8 *) PwmPIN__SNAP)
    
	#define PwmPIN_0_INTTYPE_REG 		(* (reg8 *) PwmPIN__0__INTTYPE)
#endif /* (PwmPIN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PwmPIN_H */


/* [] END OF FILE */
