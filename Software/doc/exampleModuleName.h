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
e_emn_enumTypeName; /* e_<prefix>_typeName */

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

/* Control interfaces, provided APIs */
extern void emn_enableSomeFeature(void);
extern void emn_disableSomeFeature(void);
extern void emn_startSomeAction(void);
extern void emn_stopSomeAction(void);

/**/


#endif // _EXAMPLE_MODULE_NAME_H_
