/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "lcd.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define LED_ON 1
#define LED_OFF 0
int time = 0;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    /* Innit board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

	SysTick->VAL  = 0;

	SysTick->LOAD = 120000;

	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk;



	char h[16];

	sprintf(h,"%d", time);

	LCD_string(h);
	LCD_clr();




    while (1)
    {

    	/*
   		stav = GPIO_PinRead(BOARD_SW4_GPIO, BOARD_SW4_PIN);

        if(stav == 0){
        	GPIO_PinWrite(BOARD_RGB_B_GPIO, BOARD_RGB_B_PIN, LED_ON);
        }else{
        	GPIO_PinWrite(BOARD_RGB_B_GPIO, BOARD_RGB_B_PIN, LED_OFF);
        }
        */

    	sprintf(h,"%d", time);

    	LCD_string(h);

    	LCD_to_xy(1,1);


    }
}

void SysTick_Handler(void)
{
	count++;
	time++;
}

