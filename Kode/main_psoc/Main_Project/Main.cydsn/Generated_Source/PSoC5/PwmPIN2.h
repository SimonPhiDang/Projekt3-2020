/*******************************************************************************
* File Name: PwmPIN2.h  
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

#if !defined(CY_PINS_PwmPIN2_H) /* Pins PwmPIN2_H */
#define CY_PINS_PwmPIN2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PwmPIN2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PwmPIN2__PORT == 15 && ((PwmPIN2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    PwmPIN2_Write(uint8 value);
void    PwmPIN2_SetDriveMode(uint8 mode);
uint8   PwmPIN2_ReadDataReg(void);
uint8   PwmPIN2_Read(void);
void    PwmPIN2_SetInterruptMode(uint16 position, uint16 mode);
uint8   PwmPIN2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the PwmPIN2_SetDriveMode() function.
     *  @{
     */
        #define PwmPIN2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define PwmPIN2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define PwmPIN2_DM_RES_UP          PIN_DM_RES_UP
        #define PwmPIN2_DM_RES_DWN         PIN_DM_RES_DWN
        #define PwmPIN2_DM_OD_LO           PIN_DM_OD_LO
        #define PwmPIN2_DM_OD_HI           PIN_DM_OD_HI
        #define PwmPIN2_DM_STRONG          PIN_DM_STRONG
        #define PwmPIN2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define PwmPIN2_MASK               PwmPIN2__MASK
#define PwmPIN2_SHIFT              PwmPIN2__SHIFT
#define PwmPIN2_WIDTH              1u

/* Interrupt constants */
#if defined(PwmPIN2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in PwmPIN2_SetInterruptMode() function.
     *  @{
     */
        #define PwmPIN2_INTR_NONE      (uint16)(0x0000u)
        #define PwmPIN2_INTR_RISING    (uint16)(0x0001u)
        #define PwmPIN2_INTR_FALLING   (uint16)(0x0002u)
        #define PwmPIN2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define PwmPIN2_INTR_MASK      (0x01u) 
#endif /* (PwmPIN2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PwmPIN2_PS                     (* (reg8 *) PwmPIN2__PS)
/* Data Register */
#define PwmPIN2_DR                     (* (reg8 *) PwmPIN2__DR)
/* Port Number */
#define PwmPIN2_PRT_NUM                (* (reg8 *) PwmPIN2__PRT) 
/* Connect to Analog Globals */                                                  
#define PwmPIN2_AG                     (* (reg8 *) PwmPIN2__AG)                       
/* Analog MUX bux enable */
#define PwmPIN2_AMUX                   (* (reg8 *) PwmPIN2__AMUX) 
/* Bidirectional Enable */                                                        
#define PwmPIN2_BIE                    (* (reg8 *) PwmPIN2__BIE)
/* Bit-mask for Aliased Register Access */
#define PwmPIN2_BIT_MASK               (* (reg8 *) PwmPIN2__BIT_MASK)
/* Bypass Enable */
#define PwmPIN2_BYP                    (* (reg8 *) PwmPIN2__BYP)
/* Port wide control signals */                                                   
#define PwmPIN2_CTL                    (* (reg8 *) PwmPIN2__CTL)
/* Drive Modes */
#define PwmPIN2_DM0                    (* (reg8 *) PwmPIN2__DM0) 
#define PwmPIN2_DM1                    (* (reg8 *) PwmPIN2__DM1)
#define PwmPIN2_DM2                    (* (reg8 *) PwmPIN2__DM2) 
/* Input Buffer Disable Override */
#define PwmPIN2_INP_DIS                (* (reg8 *) PwmPIN2__INP_DIS)
/* LCD Common or Segment Drive */
#define PwmPIN2_LCD_COM_SEG            (* (reg8 *) PwmPIN2__LCD_COM_SEG)
/* Enable Segment LCD */
#define PwmPIN2_LCD_EN                 (* (reg8 *) PwmPIN2__LCD_EN)
/* Slew Rate Control */
#define PwmPIN2_SLW                    (* (reg8 *) PwmPIN2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PwmPIN2_PRTDSI__CAPS_SEL       (* (reg8 *) PwmPIN2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PwmPIN2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PwmPIN2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PwmPIN2_PRTDSI__OE_SEL0        (* (reg8 *) PwmPIN2__PRTDSI__OE_SEL0) 
#define PwmPIN2_PRTDSI__OE_SEL1        (* (reg8 *) PwmPIN2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PwmPIN2_PRTDSI__OUT_SEL0       (* (reg8 *) PwmPIN2__PRTDSI__OUT_SEL0) 
#define PwmPIN2_PRTDSI__OUT_SEL1       (* (reg8 *) PwmPIN2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PwmPIN2_PRTDSI__SYNC_OUT       (* (reg8 *) PwmPIN2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(PwmPIN2__SIO_CFG)
    #define PwmPIN2_SIO_HYST_EN        (* (reg8 *) PwmPIN2__SIO_HYST_EN)
    #define PwmPIN2_SIO_REG_HIFREQ     (* (reg8 *) PwmPIN2__SIO_REG_HIFREQ)
    #define PwmPIN2_SIO_CFG            (* (reg8 *) PwmPIN2__SIO_CFG)
    #define PwmPIN2_SIO_DIFF           (* (reg8 *) PwmPIN2__SIO_DIFF)
#endif /* (PwmPIN2__SIO_CFG) */

/* Interrupt Registers */
#if defined(PwmPIN2__INTSTAT)
    #define PwmPIN2_INTSTAT            (* (reg8 *) PwmPIN2__INTSTAT)
    #define PwmPIN2_SNAP               (* (reg8 *) PwmPIN2__SNAP)
    
	#define PwmPIN2_0_INTTYPE_REG 		(* (reg8 *) PwmPIN2__0__INTTYPE)
#endif /* (PwmPIN2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PwmPIN2_H */


/* [] END OF FILE */
