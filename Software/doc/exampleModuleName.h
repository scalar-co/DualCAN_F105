/* file name:   exampleModuleName.h */
/* file prefix: emn_ */

/* prevent recursive include */
#ifndef _EXAMPLE_MODULE_NAME_H_
#define _EXAMPLE_MODULE_NAME_H_

/* include header files that is really needed */
#include "Framework/types.h"  /* uint8, uint32 */

/* typedef of enum */
typedef enum
{
  E_EMN_INITIAL_VALUE = 0,
  E_EMN_FIRST_VALUE,
  E_EMN_SECOND_VALUE,
  
  E_EMN_NUMBER_OF_VALUES  /* number of the values */
}
e_emn_enumTypeName;

/* typedef of small data struct */
/* usually small data struct is transfered by value */
typedef struct
{
  uint8 stateA:1;
  uint8 stateB:1;
  uint8 stateC:1;
}
t_emn_smallStuctTypeName;

/* typedef of big data struct */
/* usually big data struct is transfered by pointer */
typedef struct
{
  uint32 dataA;
  uint32 dataB;
  uint32 dataC;
}
t_emn_bigStuctTypeName;

/* NOTE !!! NO global variable is used as interfaces */

/* OS interfaces, provided APIs */
extern void emn_init(void);        /* called only after POR, during task initialization */
extern void emn_task1ms(void);     /* called cyclically from scheduler every 1ms */

/* signal/data interfaces, input, provided APIs */
/* other modules call these APIs to deliver data signals into this module */
extern void emn_setFeatureEnable(boolean enable);
extern void emn_setActionState(uint8 state);
extern void emn_setActionData(t_emn_bigStructTypeName * pBigData); /* big data are usually transfered with pointer */
extern void emn_setActionCondition(t_emn_smallStructTypeName smallData); /* small data are usually transfered with value */
extern void emn_EventDataReceived(t_emn_bigStructTypeName * pBigData); /* emphasize this is an event */

/* signal/data interfaces, output, provided APIs */
/* other modules call these APIs to fetch data signals out from this module */
extern boolean emn_getFeatureEnable(void);
extern uint8 emn_getActionState(void);
extern void emn_getActionData(t_emn_bigStructTypeName * pBigData); /* big data are transfered with pointer */
extern t_emn_smallStructTypeName emn_getActionCondition(void); /* small data are transfered with value */

/* signal/data interfaces, output, required APIs */
/* this module calls these APIs to deliver data signals out to other modules */
exern void emnHook_dataReceived(t_emn_bigStructTypeName * pBigData);

/* Control interfaces, input, provided APIs */
/* other modules call these APIs to deliver control states into this module */
extern void emn_enableSomeFeature(void);
extern void emn_disableSomeFeature(void);
extern void emn_startSomeAction(void);
extern void emn_stopSomeAction(void);

/* Event interfaces, output, required APIs */
/* this module calls these APIs to deliver control states out to other modules */
extern void emnHook_enableStateChanged(uint8 newState);
extern void emnHook_actionStarted(void);
extern void emnHook_actionStopped(void);

/* Mixed data/event interfaces, input/output, provided APIs */
extern e_emn_enumTypeName emn_startOneAction(t_emn_bigStructTypeName * pActionData);

/* Service inerfaces, input/output, provided APIs */
/* other module calls the APIs, provide input data, and get out the result */
/* key point: no data of this module is used in this operation, all data are from the caller */
extern boolean emn_compareActionConditions(t_emn_smallStructTypeName condition1, t_emn_smallStructTypeName condition2)

#endif // _EXAMPLE_MODULE_NAME_H_
