/*******************************************************************************
* File Name: Done.h  
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

#if !defined(CY_PINS_Done_H) /* Pins Done_H */
#define CY_PINS_Done_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Done_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Done__PORT == 15 && ((Done__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Done_Write(uint8 value);
void    Done_SetDriveMode(uint8 mode);
uint8   Done_ReadDataReg(void);
uint8   Done_Read(void);
void    Done_SetInterruptMode(uint16 position, uint16 mode);
uint8   Done_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Done_SetDriveMode() function.
     *  @{
     */
        #define Done_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Done_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Done_DM_RES_UP          PIN_DM_RES_UP
        #define Done_DM_RES_DWN         PIN_DM_RES_DWN
        #define Done_DM_OD_LO           PIN_DM_OD_LO
        #define Done_DM_OD_HI           PIN_DM_OD_HI
        #define Done_DM_STRONG          PIN_DM_STRONG
        #define Done_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Done_MASK               Done__MASK
#define Done_SHIFT              Done__SHIFT
#define Done_WIDTH              1u

/* Interrupt constants */
#if defined(Done__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Done_SetInterruptMode() function.
     *  @{
     */
        #define Done_INTR_NONE      (uint16)(0x0000u)
        #define Done_INTR_RISING    (uint16)(0x0001u)
        #define Done_INTR_FALLING   (uint16)(0x0002u)
        #define Done_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Done_INTR_MASK      (0x01u) 
#endif /* (Done__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Done_PS                     (* (reg8 *) Done__PS)
/* Data Register */
#define Done_DR                     (* (reg8 *) Done__DR)
/* Port Number */
#define Done_PRT_NUM                (* (reg8 *) Done__PRT) 
/* Connect to Analog Globals */                                                  
#define Done_AG                     (* (reg8 *) Done__AG)                       
/* Analog MUX bux enable */
#define Done_AMUX                   (* (reg8 *) Done__AMUX) 
/* Bidirectional Enable */                                                        
#define Done_BIE                    (* (reg8 *) Done__BIE)
/* Bit-mask for Aliased Register Access */
#define Done_BIT_MASK               (* (reg8 *) Done__BIT_MASK)
/* Bypass Enable */
#define Done_BYP                    (* (reg8 *) Done__BYP)
/* Port wide control signals */                                                   
#define Done_CTL                    (* (reg8 *) Done__CTL)
/* Drive Modes */
#define Done_DM0                    (* (reg8 *) Done__DM0) 
#define Done_DM1                    (* (reg8 *) Done__DM1)
#define Done_DM2                    (* (reg8 *) Done__DM2) 
/* Input Buffer Disable Override */
#define Done_INP_DIS                (* (reg8 *) Done__INP_DIS)
/* LCD Common or Segment Drive */
#define Done_LCD_COM_SEG            (* (reg8 *) Done__LCD_COM_SEG)
/* Enable Segment LCD */
#define Done_LCD_EN                 (* (reg8 *) Done__LCD_EN)
/* Slew Rate Control */
#define Done_SLW                    (* (reg8 *) Done__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Done_PRTDSI__CAPS_SEL       (* (reg8 *) Done__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Done_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Done__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Done_PRTDSI__OE_SEL0        (* (reg8 *) Done__PRTDSI__OE_SEL0) 
#define Done_PRTDSI__OE_SEL1        (* (reg8 *) Done__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Done_PRTDSI__OUT_SEL0       (* (reg8 *) Done__PRTDSI__OUT_SEL0) 
#define Done_PRTDSI__OUT_SEL1       (* (reg8 *) Done__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Done_PRTDSI__SYNC_OUT       (* (reg8 *) Done__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Done__SIO_CFG)
    #define Done_SIO_HYST_EN        (* (reg8 *) Done__SIO_HYST_EN)
    #define Done_SIO_REG_HIFREQ     (* (reg8 *) Done__SIO_REG_HIFREQ)
    #define Done_SIO_CFG            (* (reg8 *) Done__SIO_CFG)
    #define Done_SIO_DIFF           (* (reg8 *) Done__SIO_DIFF)
#endif /* (Done__SIO_CFG) */

/* Interrupt Registers */
#if defined(Done__INTSTAT)
    #define Done_INTSTAT            (* (reg8 *) Done__INTSTAT)
    #define Done_SNAP               (* (reg8 *) Done__SNAP)
    
	#define Done_0_INTTYPE_REG 		(* (reg8 *) Done__0__INTTYPE)
#endif /* (Done__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Done_H */


/* [] END OF FILE */
