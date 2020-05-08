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
		uint8 tick;	// increase in ISR
	}
	input;
	struct
	{
		uint8 tick;			// a copy in main() from ISR, i.e. increase in main()
		uint8 sync;			// sync with the copy of tick
		uint8 cycleCount;	// count of scheduled cycles
		uint8 errorCount;	// count of schedule errors
	}
	local;
}
t_scheduler;

static t_scheduler scheduler;

void scheduler_init(void)
{
	scheduler.input.tick = 0u;
	scheduler.local.tick = 0u;
	scheduler.local.sync = 0u;
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

	/* check if the input tick is updated for every 1ms or more */
	if( deltaTick )
	{
		/* sync */
		scheduler.local.sync = scheduler.local.tick;

		/* count up schedule cycles */
		scheduler.local.cycleCount++;

		/* check if schedule errors */
		if( deltaTick>1 )
		{
			/* the 1ms interrupt are missed at least once */
			scheduler.local.errorCount++;

			/* TODO: correct the cycle count ??? */

			/* TODO: functional safety reactions */
		}
		else
		{
			/* no errors */
		}

		/* schedule tasks, now only 1ms */
		schedulerHook_task1ms();
	}
	/* no update */
	else
	{
		/* continue idle */
		schedulerHook_idle();
	}
}

/* this function is called from ISR every 1ms */
void scheduler_EventTickUpISR(void)
{
	/* the tick is increased every 1ms */
	scheduler.input.tick++;
}
