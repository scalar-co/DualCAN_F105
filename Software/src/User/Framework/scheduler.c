/*
 * scheduler.c
 *
 *  Created on: May 3, 2020
 *      Author: Administrator
 */

#include "types.h"
#include "scheduler.h"

typedef struct
{
	struct
	{
		uint8 tick;
	}
	input;
	struct
	{
		uint8 tick;
		uint8 sync;
		uint8 cycleCount;
		uint8 errorCount;
	}
	local;
}
t_scheduler;

static t_scheduler scheduler;

void scheduler_init(void)
{
	scheduler.input.tick = 0u;
	scheduler.local.tick = 0u;
	scheduler.local.cycleCount = 0u;
	scheduler.local.errorCount = 0u;

	/* initialize tasks */
	schedulerHook_init();
}

void scheduler_main(void)
{
	uint8 deltaTick;

	/* this line is actually CRITICAL section */
	/* input tick is only written in ISR, but read in main() */
	/* after copy to local, all are written/read in main() */
	scheduler.local.tick = scheduler.input.tick;

	/* calculate delta tick, they are all uint8, no matter overflow */
	deltaTick = scheduler.local.tick - scheduler.local.sync;

	/* check if the input tick is updated for every 1ms */
	if( 1u==deltaTick )
	{
		/* keep cycle count */
		scheduler.local.cycleCount = scheduler.local.sync;

		/* run 1ms tasks */
		schedulerHook_task1ms();
	}
	/* no update */
	else if( 0u==deltaTick )
	{
		/* continue idle */
		schedulerHook_idle();
	}
	/* updated much more */
	else
	{
		/* the 1ms interrupt are missed at least once */
		scheduler.local.errorCount++;

		/* TODO: other safety reactions */
	}

}

/* this function is called from ISR every 1ms */
void scheduler_EventTickUpISR(void)
{
	/* the tick is increased every 1ms */
	scheduler.input.tick++;
}
