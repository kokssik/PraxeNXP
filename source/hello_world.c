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
    char ch;
    int stav;

    /* Innit board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    for(int i = 0; i < 100; i++){
    PRINTF("hello world.\r\n");
    PRINTF("%d",i);
    }

    while (1)
    {
        //ch = GETCHAR();
        stav = GPIO_PinRead(BOARD_SW4_GPIO, BOARD_SW4_PIN);

        if(stav == 0){
        	GPIO_PinWrite(BOARD_RGB_B_GPIO, BOARD_RGB_B_PIN, LED_ON);
        }else{
        	GPIO_PinWrite(BOARD_RGB_B_GPIO, BOARD_RGB_B_PIN, LED_OFF);
        }
        //PUTCHAR(ch);

    }
}
