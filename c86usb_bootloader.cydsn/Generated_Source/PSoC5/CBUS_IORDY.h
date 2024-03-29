/*******************************************************************************
* File Name: CBUS_IORDY.h  
* Version 2.5
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CBUS_IORDY_H) /* Pins CBUS_IORDY_H */
#define CY_PINS_CBUS_IORDY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CBUS_IORDY_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_5 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CBUS_IORDY__PORT == 15 && ((CBUS_IORDY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CBUS_IORDY_Write(uint8 value) ;
void    CBUS_IORDY_SetDriveMode(uint8 mode) ;
uint8   CBUS_IORDY_ReadDataReg(void) ;
uint8   CBUS_IORDY_Read(void) ;
uint8   CBUS_IORDY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CBUS_IORDY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CBUS_IORDY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CBUS_IORDY_DM_RES_UP          PIN_DM_RES_UP
#define CBUS_IORDY_DM_RES_DWN         PIN_DM_RES_DWN
#define CBUS_IORDY_DM_OD_LO           PIN_DM_OD_LO
#define CBUS_IORDY_DM_OD_HI           PIN_DM_OD_HI
#define CBUS_IORDY_DM_STRONG          PIN_DM_STRONG
#define CBUS_IORDY_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CBUS_IORDY_MASK               CBUS_IORDY__MASK
#define CBUS_IORDY_SHIFT              CBUS_IORDY__SHIFT
#define CBUS_IORDY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CBUS_IORDY_PS                     (* (reg8 *) CBUS_IORDY__PS)
/* Data Register */
#define CBUS_IORDY_DR                     (* (reg8 *) CBUS_IORDY__DR)
/* Port Number */
#define CBUS_IORDY_PRT_NUM                (* (reg8 *) CBUS_IORDY__PRT) 
/* Connect to Analog Globals */                                                  
#define CBUS_IORDY_AG                     (* (reg8 *) CBUS_IORDY__AG)                       
/* Analog MUX bux enable */
#define CBUS_IORDY_AMUX                   (* (reg8 *) CBUS_IORDY__AMUX) 
/* Bidirectional Enable */                                                        
#define CBUS_IORDY_BIE                    (* (reg8 *) CBUS_IORDY__BIE)
/* Bit-mask for Aliased Register Access */
#define CBUS_IORDY_BIT_MASK               (* (reg8 *) CBUS_IORDY__BIT_MASK)
/* Bypass Enable */
#define CBUS_IORDY_BYP                    (* (reg8 *) CBUS_IORDY__BYP)
/* Port wide control signals */                                                   
#define CBUS_IORDY_CTL                    (* (reg8 *) CBUS_IORDY__CTL)
/* Drive Modes */
#define CBUS_IORDY_DM0                    (* (reg8 *) CBUS_IORDY__DM0) 
#define CBUS_IORDY_DM1                    (* (reg8 *) CBUS_IORDY__DM1)
#define CBUS_IORDY_DM2                    (* (reg8 *) CBUS_IORDY__DM2) 
/* Input Buffer Disable Override */
#define CBUS_IORDY_INP_DIS                (* (reg8 *) CBUS_IORDY__INP_DIS)
/* LCD Common or Segment Drive */
#define CBUS_IORDY_LCD_COM_SEG            (* (reg8 *) CBUS_IORDY__LCD_COM_SEG)
/* Enable Segment LCD */
#define CBUS_IORDY_LCD_EN                 (* (reg8 *) CBUS_IORDY__LCD_EN)
/* Slew Rate Control */
#define CBUS_IORDY_SLW                    (* (reg8 *) CBUS_IORDY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CBUS_IORDY_PRTDSI__CAPS_SEL       (* (reg8 *) CBUS_IORDY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CBUS_IORDY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CBUS_IORDY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CBUS_IORDY_PRTDSI__OE_SEL0        (* (reg8 *) CBUS_IORDY__PRTDSI__OE_SEL0) 
#define CBUS_IORDY_PRTDSI__OE_SEL1        (* (reg8 *) CBUS_IORDY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CBUS_IORDY_PRTDSI__OUT_SEL0       (* (reg8 *) CBUS_IORDY__PRTDSI__OUT_SEL0) 
#define CBUS_IORDY_PRTDSI__OUT_SEL1       (* (reg8 *) CBUS_IORDY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CBUS_IORDY_PRTDSI__SYNC_OUT       (* (reg8 *) CBUS_IORDY__PRTDSI__SYNC_OUT) 


#if defined(CBUS_IORDY__INTSTAT)  /* Interrupt Registers */

    #define CBUS_IORDY_INTSTAT                (* (reg8 *) CBUS_IORDY__INTSTAT)
    #define CBUS_IORDY_SNAP                   (* (reg8 *) CBUS_IORDY__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CBUS_IORDY_H */


/* [] END OF FILE */
