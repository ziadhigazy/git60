#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "servo.h"

int main(void)
{
    SERVO_Init();

    while(1)
    {
        SERVO_SetAngle(0);
        _delay_ms(1000);

        SERVO_SetAngle(90);
        _delay_ms(1000);

        SERVO_SetAngle(180);
        _delay_ms(1000);
    }
}