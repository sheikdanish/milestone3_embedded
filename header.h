#include<stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define SET_BIT(PORT,BIT) PORT|= (1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&= ~(1<<BIT)
struct
{
    volatile unsigned lock_flag:1;
        volatile unsigned button_flag:1;
    } fold;
    void init();
    void adjust_lxleft();
    void adjust_lxright();
    void adjust_lydown();
    void adjust_lyup();
