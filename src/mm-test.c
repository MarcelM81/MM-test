/*
===============================================================================
 Name        : mm-test.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "chip.h"

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here


/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
void SysTick_Handler(void)
{
	static int timer1;

	if (++timer1 >= 200) {
			timer1 = 0;
			Chip_GPIO_SetPinToggle(LPC_GPIO, 0, 7);
		}
}



int main(void) {

    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();

    /* Enable and setup SysTick Timer at a periodic rate */
    SysTick_Config(SystemCoreClock / 1000);

    /* Initialize GPIO */
    Chip_GPIO_Init(LPC_GPIO);

    /* Set the PIO_0.7 and PIO_2.6 as output */
    Chip_GPIO_SetPinDIROutput(LPC_GPIO, 0, 7);

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}
