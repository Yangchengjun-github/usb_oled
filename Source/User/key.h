#ifndef _KEY_H_
#define _KEY_H_
#include "apt32f102a_gpio.h"
#include "define.h"

void task_key(void);
typedef struct
{
    U8_T key_t1_short_press : 1;
    U8_T key_t1_long_press : 1;
    U8_T key_t2_short_press : 1;
    U8_T key_t2_long_press : 1;
    U8_T key_t3_short_press : 1;
    U8_T key_t3_long_press : 1;

} stKEY_T;
extern stKEY_T stKEY;

#define KEY_SET_LONG stKEY.key_t1_long_press
#define KEY_SET_SHORT stKEY.key_t1_short_press
#define KEY_UP_LONG stKEY.key_t2_long_press
#define KEY_UP_SHORT stKEY.key_t2_short_press
#define KEY_DOWN_LONG stKEY.key_t3_long_press
#define KEY_DOWN_SHORT stKEY.key_t3_short_press

#endif