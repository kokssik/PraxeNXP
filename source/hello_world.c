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
int time1 = 0;
int time2 = 0;
int turn = 0;
int stop;


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



	char h1[16];
	char h2[16];


	LCD_init();
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


    	if(!GPIO_PinRead(BOARD_BT_W_GPIO, BOARD_BT_W_PIN)){
    		turn = 1;
    	}

    	if(!GPIO_PinRead(BOARD_BT_E_GPIO, BOARD_BT_E_PIN)){
    		turn = 2;
    	}

    	if(!GPIO_PinRead(BOARD_SW1_GPIO, BOARD_SW1_PIN)){
    		stop = 1;
    	}else{
    		stop = 0;
    	}

    	sprintf(h1,"H1: %d\n", time1);
    	sprintf(h2,"H2: %d", time2);

    	LCD_string(h1);
    	LCD_string(h2);

    	LCD_to_xy(1,1);


    }
}

void SysTick_Handler(void)
{
	count++;
	if((turn == 1) && (stop != 1)){
	time1++;}

	if(turn == 2 && (stop != 1)){
	time2++;}
}

