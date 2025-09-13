#include <mega32.h>
#include <delay.h>

void main(void)
{
    DDRA = 0xFF;
    DDRB = 0xFF;
    DDRC = 0xFF;
    DDRD = 0xFF;

    while (1)
    {
        int i;

        PORTA = 0xFF;
        delay_ms(310);
        PORTA = 0x00;
        delay_ms(310);

        for(i=7; i>=0; i--)
        {
            PORTB = (1<<i);
            delay_ms(45);
        }
        PORTB = 0x00;

        for(i=0; i<8; i++)
        {
            PORTC = (1<<i);
            delay_ms(260);
        }
        PORTC = 0x00;

        for(i=0; i<8; i++)
        {
            PORTD = (1<<i);
            delay_ms(110);
        }
        PORTD = 0x00;
    }
}
