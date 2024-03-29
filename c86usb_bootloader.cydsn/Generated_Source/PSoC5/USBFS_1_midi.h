/*******************************************************************************
* File Name: USBFS_1_midi.h
* Version 2.70
*
* Description:
*  Header File for the USBFS MIDI module.
*  Contains prototypes and constant values.
*
* Related Document:
*  Universal Serial Bus Device Class Definition for MIDI Devices Release 1.0
*  MIDI 1.0 Detailed Specification Document Version 4.2
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_USBFS_1_midi_H)
#define CY_USBFS_USBFS_1_midi_H

#include "cytypes.h"
#include "USBFS_1.h"


/***************************************
*    Data Structure Definition
***************************************/

/* The following structure is used to hold status information for
   building and parsing incoming MIDI messages. */
typedef struct
{
    uint8    length;        /* expected length */
    uint8    count;         /* current byte count */
    uint8    size;          /* complete size */
    uint8    runstat;       /* running status */
    uint8    msgBuff[4];    /* message buffer */
} USBFS_1_MIDI_RX_STATUS;


/***************************************
*           MIDI Constants.
***************************************/

#define USBFS_1_ONE_EXT_INTRF              (0x01u)
#define USBFS_1_TWO_EXT_INTRF              (0x02u)

/* Flag definitions for use with MIDI device inquiry */
#define USBFS_1_INQ_SYSEX_FLAG             (0x01u)
#define USBFS_1_INQ_IDENTITY_REQ_FLAG      (0x02u)

/* USB-MIDI Code Index Number Classifications (MIDI Table 4-1) */
#define USBFS_1_CIN_MASK                   (0x0Fu)
#define USBFS_1_RESERVED0                  (0x00u)
#define USBFS_1_RESERVED1                  (0x01u)
#define USBFS_1_2BYTE_COMMON               (0x02u)
#define USBFS_1_3BYTE_COMMON               (0x03u)
#define USBFS_1_SYSEX                      (0x04u)
#define USBFS_1_1BYTE_COMMON               (0x05u)
#define USBFS_1_SYSEX_ENDS_WITH1           (0x05u)
#define USBFS_1_SYSEX_ENDS_WITH2           (0x06u)
#define USBFS_1_SYSEX_ENDS_WITH3           (0x07u)
#define USBFS_1_NOTE_OFF                   (0x08u)
#define USBFS_1_NOTE_ON                    (0x09u)
#define USBFS_1_POLY_KEY_PRESSURE          (0x0Au)
#define USBFS_1_CONTROL_CHANGE             (0x0Bu)
#define USBFS_1_PROGRAM_CHANGE             (0x0Cu)
#define USBFS_1_CHANNEL_PRESSURE           (0x0Du)
#define USBFS_1_PITCH_BEND_CHANGE          (0x0Eu)
#define USBFS_1_SINGLE_BYTE                (0x0Fu)

#define USBFS_1_CABLE_MASK                 (0xF0u)
#define USBFS_1_MIDI_CABLE_00              (0x00u)
#define USBFS_1_MIDI_CABLE_01              (0x10u)

#define USBFS_1_EVENT_BYTE0                (0x00u)
#define USBFS_1_EVENT_BYTE1                (0x01u)
#define USBFS_1_EVENT_BYTE2                (0x02u)
#define USBFS_1_EVENT_BYTE3                (0x03u)
#define USBFS_1_EVENT_LENGTH               (0x04u)

#define USBFS_1_MIDI_STATUS_BYTE_MASK      (0x80u)
#define USBFS_1_MIDI_STATUS_MASK           (0xF0u)
#define USBFS_1_MIDI_SINGLE_BYTE_MASK      (0x08u)
#define USBFS_1_MIDI_NOTE_OFF              (0x80u)
#define USBFS_1_MIDI_NOTE_ON               (0x90u)
#define USBFS_1_MIDI_POLY_KEY_PRESSURE     (0xA0u)
#define USBFS_1_MIDI_CONTROL_CHANGE        (0xB0u)
#define USBFS_1_MIDI_PROGRAM_CHANGE        (0xC0u)
#define USBFS_1_MIDI_CHANNEL_PRESSURE      (0xD0u)
#define USBFS_1_MIDI_PITCH_BEND_CHANGE     (0xE0u)
#define USBFS_1_MIDI_SYSEX                 (0xF0u)
#define USBFS_1_MIDI_EOSEX                 (0xF7u)
#define USBFS_1_MIDI_QFM                   (0xF1u)
#define USBFS_1_MIDI_SPP                   (0xF2u)
#define USBFS_1_MIDI_SONGSEL               (0xF3u)
#define USBFS_1_MIDI_TUNEREQ               (0xF6u)
#define USBFS_1_MIDI_ACTIVESENSE           (0xFEu)

/* MIDI Universal System Exclusive defines */
#define USBFS_1_MIDI_SYSEX_NON_REAL_TIME   (0x7Eu)
#define USBFS_1_MIDI_SYSEX_REALTIME        (0x7Fu)
/* ID of target device */
#define USBFS_1_MIDI_SYSEX_ID_ALL          (0x7Fu)
/* Sub-ID#1*/
#define USBFS_1_MIDI_SYSEX_GEN_INFORMATION (0x06u)
#define USBFS_1_MIDI_SYSEX_GEN_MESSAGE     (0x09u)
/* Sub-ID#2*/
#define USBFS_1_MIDI_SYSEX_IDENTITY_REQ    (0x01u)
#define USBFS_1_MIDI_SYSEX_IDENTITY_REPLY  (0x02u)
#define USBFS_1_MIDI_SYSEX_SYSTEM_ON       (0x01u)
#define USBFS_1_MIDI_SYSEX_SYSTEM_OFF      (0x02u)

#define USBFS_1_CUSTOM_UART_TX_PRIOR_NUM   (0x04u)
#define USBFS_1_CUSTOM_UART_RX_PRIOR_NUM   (0x02u)

#define USBFS_1_ISR_SERVICE_MIDI_OUT         \
        ( (USBFS_1_ENABLE_MIDI_API != 0u) && \
          (USBFS_1_MIDI_OUT_BUFF_SIZE > 0) && (USBFS_1_EP_MM == USBFS_1__EP_DMAAUTO))
#define USBFS_1_ISR_SERVICE_MIDI_IN     \
        ( (USBFS_1_ENABLE_MIDI_API != 0u) && (USBFS_1_MIDI_IN_BUFF_SIZE > 0) )


/***************************************
* External function references
***************************************/

void USBFS_1_callbackLocalMidiEvent(uint8 cable, uint8 *midiMsg)
                                                     ;


/***************************************
*    External references
***************************************/

#if (USBFS_1_MIDI_EXT_MODE >= USBFS_1_ONE_EXT_INTRF)
    #include "MIDI1_UART.h"
#endif /*  USBFS_1_MIDI_EXT_MODE >= USBFS_1_ONE_EXT_INTRF */
#if (USBFS_1_MIDI_EXT_MODE >= USBFS_1_TWO_EXT_INTRF)
    #include "MIDI2_UART.h"
#endif /*  USBFS_1_MIDI_EXT_MODE >= USBFS_1_TWO_EXT_INTRF */
#if(USBFS_1_EP_MM != USBFS_1__EP_MANUAL)
    #include <CyDmac.h>
#endif /*  USBFS_1_EP_MM */


/***************************************
*    Private function prototypes
***************************************/

void USBFS_1_PrepareInBuffer(uint8 ic, const uint8 srcBuff[], uint8 eventLen, uint8 cable)
                                                                 ;
#if (USBFS_1_MIDI_EXT_MODE >= USBFS_1_ONE_EXT_INTRF)
    void USBFS_1_MIDI_Init(void) ;
    uint8 USBFS_1_ProcessMidiIn(uint8 mData, USBFS_1_MIDI_RX_STATUS *rxStat)
                                                                ;
    uint8 USBFS_1_MIDI1_GetEvent(void) ;
    void USBFS_1_MIDI1_ProcessUsbOut(const uint8 epBuf[])
                                                     ;

    #if (USBFS_1_MIDI_EXT_MODE >= USBFS_1_TWO_EXT_INTRF)
        uint8 USBFS_1_MIDI2_GetEvent(void) ;
        void USBFS_1_MIDI2_ProcessUsbOut(const uint8 epBuf[])
                                                    ;
    #endif /*  USBFS_1_MIDI_EXT_MODE >= USBFS_1_TWO_EXT_INTRF */
#endif /*  USBFS_1_MIDI_EXT_MODE >= USBFS_1_ONE_EXT_INTRF */


/***************************************
* External data references
***************************************/

#if defined(USBFS_1_ENABLE_MIDI_STREAMING)

#if (USBFS_1_MIDI_IN_BUFF_SIZE > 0)
    #if (USBFS_1_MIDI_IN_BUFF_SIZE >= 256)
        extern volatile uint16 USBFS_1_midiInPointer;                       /* Input endpoint buffer pointer */
    #else
        extern volatile uint8 USBFS_1_midiInPointer;                        /* Input endpoint buffer pointer */
    #endif /*  USBFS_1_MIDI_IN_BUFF_SIZE >=256 */
    extern volatile uint8 USBFS_1_midi_in_ep;                               /* Input endpoint number */
    extern uint8 USBFS_1_midiInBuffer[USBFS_1_MIDI_IN_BUFF_SIZE];  /* Input endpoint buffer */
#endif /* USBFS_1_MIDI_IN_BUFF_SIZE > 0 */

#if (USBFS_1_MIDI_OUT_BUFF_SIZE > 0)
    extern volatile uint8 USBFS_1_midi_out_ep;                               /* Output endpoint number */
    extern uint8 USBFS_1_midiOutBuffer[USBFS_1_MIDI_OUT_BUFF_SIZE]; /* Output endpoint buffer */
#endif /* USBFS_1_MIDI_OUT_BUFF_SIZE > 0 */

#if (USBFS_1_MIDI_EXT_MODE >= USBFS_1_ONE_EXT_INTRF)
    extern volatile uint8 USBFS_1_MIDI1_InqFlags;                              /* Device inquiry flag */
    #if (USBFS_1_MIDI_EXT_MODE >= USBFS_1_TWO_EXT_INTRF)
        extern volatile uint8 USBFS_1_MIDI2_InqFlags;                          /* Device inquiry flag */
    #endif /*  USBFS_1_MIDI_EXT_MODE >= USBFS_1_TWO_EXT_INTRF */
#endif /*  USBFS_1_MIDI_EXT_MODE >= USBFS_1_ONE_EXT_INTRF */

#endif /* USBFS_1_ENABLE_MIDI_STREAMING */


#endif /*  CY_USBFS_USBFS_1_midi_H */


/* [] END OF FILE */
