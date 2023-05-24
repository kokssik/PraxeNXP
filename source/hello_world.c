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


    int stav;



    for(int i = 0; i < 100; i++){
    PRINTF("hello world.\r\n");
    PRINTF("%d",i);
    }
    LCD_init();
    LCD_string("You kow what?\n");
    LCD_string("rwr");
    delay(2000);
    LCD_to_xy(1,1);
    LCD_string("Kus mijn kloten\n");
    LCD_string("     UwU");



    while (1)
    {

        stav = GPIO_PinRead(BOARD_SW4_GPIO, BOARD_SW4_PIN);

        if(stav == 0){
        	GPIO_PinWrite(BOARD_RGB_B_GPIO, BOARD_RGB_B_PIN, LED_ON);
        }else{
        	GPIO_PinWrite(BOARD_RGB_B_GPIO, BOARD_RGB_B_PIN, LED_OFF);
        }


    }
}

void SysTick_Handler(void)
{
	count++;
	GPIO_PinWrite(BOARD_RGB_R_GPIO, BOARD_RGB_R_PIN, LED_ON);
}

