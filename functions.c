#include "header.h"
void adjust_lxleft()
{
    SET_BIT(PORTB,PB3);
    SET_BIT(PORTB,PB2);
    CLR_BIT(PORTB,PB1);
    CLR_BIT(PORTB,PB0); // 12
    _delay_ms(100);

    CLR_BIT(PORTB,PB3);
    SET_BIT(PORTB,PB2);
    SET_BIT(PORTB,PB1);
    CLR_BIT(PORTB,PB0);  // 6
    _delay_ms(100);

    CLR_BIT(PORTB,PB3);
    CLR_BIT(PORTB,PB2);
    SET_BIT(PORTB,PB1);
    SET_BIT(PORTB,PB0); //3
    _delay_ms(100);

    SET_BIT(PORTB,PB3);
    CLR_BIT(PORTB,PB2);
    CLR_BIT(PORTB,PB1);
    SET_BIT(PORTB,PB0);  // 9
    _delay_ms(100);
}
void adjust_lxright()
{
    SET_BIT(PORTB,PB3);
    CLR_BIT(PORTB,PB2);
    CLR_BIT(PORTB,PB1);
    SET_BIT(PORTB,PB0);  // 9
    _delay_ms(100);

    CLR_BIT(PORTB,PB3);
    CLR_BIT(PORTB,PB2);
    SET_BIT(PORTB,PB1);
    SET_BIT(PORTB,PB0); //3
    _delay_ms(100);

    CLR_BIT(PORTB,PB3);
    SET_BIT(PORTB,PB2);
    SET_BIT(PORTB,PB1);
    CLR_BIT(PORTB,PB0);  // 6
    _delay_ms(100);

    SET_BIT(PORTB,PB3);
    SET_BIT(PORTB,PB2);
    CLR_BIT(PORTB,PB1);
    CLR_BIT(PORTB,PB0); // 12
    _delay_ms(100);
}
void adjust_lyup()
{
    SET_BIT(PORTC,PC3);
    SET_BIT(PORTC,PC2);
    CLR_BIT(PORTC,PC1);
    CLR_BIT(PORTC,PC0); // 12
    _delay_ms(100);

    CLR_BIT(PORTC,PC3);
    SET_BIT(PORTC,PC2);
    SET_BIT(PORTC,PC1);
    CLR_BIT(PORTC,PC0);  // 6
    _delay_ms(100);

    CLR_BIT(PORTC,PC3);
    CLR_BIT(PORTC,PC2);
    SET_BIT(PORTC,PC1);
    SET_BIT(PORTC,PC0); //3
    _delay_ms(100);

    SET_BIT(PORTC,PC3);
    CLR_BIT(PORTC,PC2);
    CLR_BIT(PORTC,PC1);
    SET_BIT(PORTC,PC0);  // 9
    _delay_ms(100);
}
void adjust_lydown()
{
    SET_BIT(PORTC,PC3);
    CLR_BIT(PORTC,PC2);
    CLR_BIT(PORTC,PC1);
    SET_BIT(PORTC,PC0);  // 9
    _delay_ms(100);

    CLR_BIT(PORTC,PC3);
    CLR_BIT(PORTC,PC2);
    SET_BIT(PORTC,PC1);
    SET_BIT(PORTC,PC0); //3
    _delay_ms(100);

    CLR_BIT(PORTC,PC3);
    SET_BIT(PORTC,PC2);
    SET_BIT(PORTC,PC1);
    CLR_BIT(PORTC,PC0);  // 6
    _delay_ms(100);

    SET_BIT(PORTC,PC3);
    SET_BIT(PORTC,PC2);
    CLR_BIT(PORTC,PC1);
    CLR_BIT(PORTC,PC0); // 12
    _delay_ms(100);
}

void init()
{
    CLR_BIT(DDRD,PD2); // Interrupt0
    CLR_BIT(DDRD,PD3); // Interrupt1
    SET_BIT(DDRC,PC5); // Fold Signal
    CLR_BIT(DDRD,PD0); // reverse_gear_input
    CLR_BIT(DDRD,PD1); // right_mirror_select
    CLR_BIT(DDRD,PD4); // left_mirror_select

    SET_BIT(DDRB,PB3); // Angle x
    SET_BIT(DDRB,PB2); // Angle x
    SET_BIT(DDRB,PB1); // Angle x
    SET_BIT(DDRB,PB0); // Angle x

    SET_BIT(DDRC,PC3); // Angle y
    SET_BIT(DDRC,PC2); // Angle y
    SET_BIT(DDRC,PC1); // Angle y
    SET_BIT(DDRC,PC0); // Angle y

    CLR_BIT(DDRB,PB6); // UP
    CLR_BIT(DDRB,PB7); // DOWN
    CLR_BIT(DDRD,PD5); // LEFT
    CLR_BIT(DDRD,PD6); // RIGHT

    CLR_BIT(DDRB,PB5); // memory_button
    CLR_BIT(DDRB,PB4); // set_button

    //Configure interrupts
    EIMSK|=(1<<INT0);
    EIMSK|=(1<<INT1);
    EICRA=0x00;
    EICRA|=(1<<ISC01);
    EICRA|=(1<<ISC11);
    sei();
    CLR_BIT(PORTD,PD0); // reverse_gear_input
    CLR_BIT(PORTD,PD1); // right_mirror_select
    CLR_BIT(PORTD,PD4); // left_mirror_select
    CLR_BIT(PORTD,PD5); // memory_button
    CLR_BIT(PORTD,PD6); // set_button
    CLR_BIT(PORTC,PC5); // fold signal

}
