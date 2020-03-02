#include "header.h"
// Initialize variables & pins
int main(void)
{
    int lxcount=0;
    int lycount=0;
    int tilt_flag=0;
    int lycount_temp=0;
    int i;
    int lxcount_mem=0;
    int rxcount_mem=0;
    int lycount_mem=0;
    int rycount_mem=0;
    uint8_t PIND_READ;
    uint8_t PINB_READ;
    fold.lock_flag=0;
    fold.button_flag=0;
    init();
    while(1)
    {
        PIND_READ = PIND;
        PINB_READ = PINB;
        if(fold.lock_flag == 1) // unlock
        {
            if(fold.button_flag == 1) // unfold
            {
                SET_BIT(PORTC,PC5); // unfold mirrors

                if((PIND_READ&(1<<PD0)))  // reverse gear
                {
                    if(!tilt_flag)
                    {
                        lycount_temp=lycount;
                        for(i=lycount+5; i>0; i--)
                        {
                            adjust_lydown();
                            lycount-=1;
                        }
                        tilt_flag = 1;
                    }
                }
                else
                {
                    if(tilt_flag)
                    {
                        while(lycount!=lycount_temp)
                        {
                            if(lycount<lycount_temp)
                            {
                                lycount+=1;
                                adjust_lyup();
                            }
                        }
                        tilt_flag = 0;
                    }
                    if((PIND_READ&(1<<PD1))) // right mirror select
                    {
                        // joypad input
                    }
                    if((PIND_READ&(1<<PD4))) // left mirror select
                    {
                        if((PINB_READ&(1<<PB6)) && (lycount < 5))
                        {
                            lycount+=1;
                            adjust_lyup();
                        }
                        if((PINB_READ&(1<<PB7)) && (lycount>-5))
                        {
                            lycount-=1;
                            adjust_lydown();
                        }
                        if((PIND_READ&(1<<PD5)) && (lxcount < 5))
                        {
                            lxcount+=1;
                            adjust_lxleft();
                        }
                        if((PIND_READ&(1<<PD6)) && (lxcount>-5))
                        {
                            lxcount-=1;
                            adjust_lxright();
                        }
                    }
                    if((PINB_READ&(1<<PB5))) // set mirror position
                    {
                        while(lycount!=lycount_mem)
                        {
                            if(lycount<lycount_mem)
                            {
                                lycount+=1;
                                adjust_lyup();
                            }
                            if(lycount>lycount_mem)
                            {
                                lycount-=1;
                                adjust_lydown();
                            }
                        }
                        while(lxcount!=lxcount_mem)
                        {
                            if(lxcount<lxcount_mem)
                            {
                                lycount+=1;
                                adjust_lxleft();
                            }
                            if(lxcount>lxcount_mem)
                            {
                                lxcount-=1;
                                adjust_lxright();
                            }
                        }
                    }
                    if((PINB_READ&(1<<PB4))) // save mirror position
                    {
                        lxcount_mem=lxcount;
                        lycount_mem=lycount;
                    }
                }
            }
            else // fold
            {
                CLR_BIT(PORTC,PC5); // fold mirrors
            }
        }
        else // lock
        {
            CLR_BIT(PORTC,PC5); // fold mirrors
        }
    }
    return 0;
}

ISR(INT0_vect)
{
    cli();
    if(fold.lock_flag == 0)
        fold.lock_flag = 1;
    else
        fold.lock_flag = 0;
    sei();
}

ISR(INT1_vect)
{
    cli();
    if(fold.button_flag == 0)
        fold.button_flag = 1;
    else
        fold.button_flag = 0;
    sei();
}
