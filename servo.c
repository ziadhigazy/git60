#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "servo.h"


volatile uint16_t servo_pulse = 1500; 


ISR(TIMER1_COMPA_vect)
{
    PORTD |= (1 << PD5);      
    OCR1B = servo_pulse * 2;   
}


ISR(TIMER1_COMPB_vect)
{
    PORTD &= ~(1 << PD5);     
}

void SERVO_Init(void)
{
    DDRD |= (1 << PD5);

    TCCR1A = 0;
    TCCR1B = (1 << WGM12) | (1 << CS11); 

    OCR1A = 40000; 

    TIMSK |= (1 << OCIE1A) | (1 << OCIE1B);

    sei();
}

void SERVO_SetAngle(uint8_t angle)
{
    servo_pulse = 500 + ((uint32_t)angle * 2000 / 180);
}
