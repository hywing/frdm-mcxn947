/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 * Copyright (c) 2019-2020, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-10-24     Magicoe      first version
 * 2020-01-10     Kevin/Karl   Add PS demo
 * 2020-09-21     supperthomas fix the main.c
 *
 */

#include <rtdevice.h>
#include "drv_pin.h"

#define LEDR_PIN        ((0*32)+10)
#define LEDG_PIN        ((0*32)+27)
#define LEDB_PIN        ((1*32)+2)

static int delay = 1000;

int main(void)
{
#if defined(__CC_ARM)
    rt_kprintf("using armcc, version: %d\n", __ARMCC_VERSION);
#elif defined(__clang__)
    rt_kprintf("using armclang, version: %d\n", __ARMCC_VERSION);
#elif defined(__ICCARM__)
    rt_kprintf("using iccarm, version: %d\n", __VER__);
#elif defined(__GNUC__)
    rt_kprintf("using gcc, version: %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif

    rt_pin_mode(LEDR_PIN, PIN_MODE_OUTPUT);  /* Set GPIO as Output */
	rt_pin_mode(LEDG_PIN, PIN_MODE_OUTPUT);  /* Set GPIO as Output */
	rt_pin_mode(LEDB_PIN, PIN_MODE_OUTPUT);  /* Set GPIO as Output */

#ifdef RT_USING_SDIO
    rt_thread_mdelay(2000);
    if (dfs_mount("sd", "/", "elm", 0, NULL) == 0)
    {
        rt_kprintf("sd mounted to /\n");
    }
    else
    {
        rt_kprintf("sd mount to / failed\n");
    }
#endif

    while (1)
    {
		// Red
        rt_pin_write(LEDR_PIN, PIN_LOW);  
		rt_pin_write(LEDG_PIN, PIN_HIGH);  
		rt_pin_write(LEDB_PIN, PIN_HIGH);  
        rt_thread_mdelay(delay);               
        // Green
        rt_pin_write(LEDR_PIN, PIN_HIGH);   
		rt_pin_write(LEDG_PIN, PIN_LOW);   
		rt_pin_write(LEDB_PIN, PIN_HIGH);    
        rt_thread_mdelay(delay);           
		// Blue
        rt_pin_write(LEDR_PIN, PIN_HIGH);    
		rt_pin_write(LEDG_PIN, PIN_HIGH); 
		rt_pin_write(LEDB_PIN, PIN_LOW);   
        rt_thread_mdelay(delay);               
		// Yellow
        rt_pin_write(LEDR_PIN, PIN_LOW);   
		rt_pin_write(LEDG_PIN, PIN_LOW);    
		rt_pin_write(LEDB_PIN, PIN_HIGH);   
        rt_thread_mdelay(delay);              
		// Pink
        rt_pin_write(LEDR_PIN, PIN_LOW);    
		rt_pin_write(LEDG_PIN, PIN_HIGH);    
		rt_pin_write(LEDB_PIN, PIN_LOW);  
        rt_thread_mdelay(delay);             
		// Cyan
        rt_pin_write(LEDR_PIN, PIN_HIGH);   
		rt_pin_write(LEDG_PIN, PIN_LOW);    
		rt_pin_write(LEDB_PIN, PIN_LOW);    
        rt_thread_mdelay(delay);              
		// White
        rt_pin_write(LEDR_PIN, PIN_LOW);    
		rt_pin_write(LEDG_PIN, PIN_LOW);   
		rt_pin_write(LEDB_PIN, PIN_LOW);
        rt_thread_mdelay(delay);             
    }
}

// end file
