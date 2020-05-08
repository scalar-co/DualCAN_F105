/*
 * cfg_scheduler.c
 *
 *  Created on: May 3, 2020
 *      Author: Administrator
 */

#include "Framework/scheduler.h"
#include "Framework/types.h"
#include "stm32f1xx_hal.h"

uint32 cnt;

void schedulerHook_init(void)
{
	/* initialize tasks */
	cnt = 0u;
}

void schedulerHook_task1ms(void)
{
	/* polling 1ms tasks */
	cnt++;
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, (cnt&512)? GPIO_PIN_SET: GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (cnt&1024)? GPIO_PIN_SET: GPIO_PIN_RESET);
}

void schedulerHook_idle(void)
{
	/* polling idle tasks */
}
