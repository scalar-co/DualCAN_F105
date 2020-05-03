/*
 * scheduler.h
 *
 *  Created on: May 3, 2020
 *      Author: Administrator
 */

#ifndef FRAMEWORK_SCHEDULER_H_
#define FRAMEWORK_SCHEDULER_H_

/* system interfaces, called from main() */
extern void scheduler_init(void);
extern void scheduler_main(void);

/* interrupt interfaces, called from ISR */
extern void scheduler_EventTickUpISR(void);

/* task interfaces (call out) */
extern void schedulerHook_init(void);
extern void schedulerHook_task1ms(void);
extern void schedulerHook_idle(void);

#endif /* FRAMEWORK_SCHEDULER_H_ */
