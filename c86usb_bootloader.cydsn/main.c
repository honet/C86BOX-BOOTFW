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
#include <project.h>

// -------------------------------------
static uint8_t ledval = 0xff;
void led_init(){
	LEDControl_Write(0xff);
}
void led_on(uint8_t idx){
	ledval &= ~(0x01<<idx);
	LEDControl_Write( ledval );
}
void led_off(uint8_t idx){
	ledval |= (0x01<<idx);
	LEDControl_Write( ledval );
}
void led_set(uint8_t idx, uint8_t sw){
	if(sw)	led_on(idx);
	else	led_off(idx);
}

uint8_t read_dipsw(uint8_t idx)
{
	if (idx>3) return 0;
	if (DipSwReadReg_Read() & (0x01<<idx) )
		return 1;
	else
		return 0;
}

// ----------------------------------------
void main()
{
	led_on(0);
	led_on(1);
	led_on(2);
	led_on(3);
	
	if(read_dipsw(0)){
		// SW OFF
	led_off(3);
		Bootloader_SET_RUN_TYPE(Bootloader_START_APP);
	}else{
		// SW ON
	led_on(3);
		Bootloader_SET_RUN_TYPE(Bootloader_START_BTLDR);
	}
	
	Bootloader_Start();

	/* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
	for(;;)
	{
		// halt, never reach here.
    	led_off(0);
    	led_off(1);
    	led_off(2);
    	led_off(3);
	}
}

/* [] END OF FILE */
