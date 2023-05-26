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
int time1 = 30000;
int time2 = 30000;
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



	char h1[24];
	char h2[24];


	LCD_init();
	LCD_clr();




    while (1)
    {
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


		int min1 = (time1 / 60000);
		int sec1= ((time1 / 1000) - (min1 * 60));
		int min2 = (time2 / 60000);
		int sec2 = ((time2 / 1000) - (min2 * 60));

		sprintf(h1,"H1: %d : %.2d\n", min1, sec1);
    	sprintf(h2,"H2: %d : %.2d\n", min2, sec2);

    	if((time1>0) && (time2 > 0)){
			LCD_string(h1);
			LCD_string(h2);
    	}else if(time1 < 1)
    	{
    		LCD_clr();
    		LCD_string("H1 out of time");
    	}else{
    		LCD_clr();
    		LCD_string("H2 out of time");
    	}


    	LCD_to_xy(1,1);


    }
}

void SysTick_Handler(void)
{
	count++;
	if((turn == 1) && (stop != 1) && (time1 >= 0)){
	time1--;}

	if(turn == 2 && (stop != 1) && (time2 >= 0)){
	time2--;}
}

