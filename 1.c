#include <mega32.h>
#include <delay.h>

void main(void)
{
    unsigned char led_position = 0;
    unsigned char active_bargraph = 0;
    unsigned char led_states[3] = {0x00, 0x00, 0x00};

    DDRA = 0xFF;
    DDRB = 0xFF;
    DDRC = 0xFF;
    DDRD = 0x00;

    PORTA = led_states[0];
    PORTB = led_states[1];
    PORTC = led_states[2];

    while (1)
    {
        if (PIND.0 == 1) { // UP
            if (active_bargraph > 0) {
                active_bargraph--;
            }
            delay_ms(200);
        }

        if (PIND.1 == 1) { // DOWN
            if (active_bargraph < 2) {
                active_bargraph++;
            }
            delay_ms(200);
        }

        if (PIND.2 == 1) { // LEFT
            if (led_position > 0) {
                led_position--;
            }
            delay_ms(200);
        }

        if (PIND.3 == 1) { // RIGHT
            if (led_position < 7) {
                led_position++;
            }
            delay_ms(200);
        }

        if (PIND.4 == 1) { // TOGGLE
            led_states[active_bargraph] ^= (1 << led_position);
            delay_ms(200);
        }

        PORTA = led_states[0];
        PORTB = led_states[1];
        PORTC = led_states[2];

        // Blinking cursor to show selected LED
        switch(active_bargraph) {
            case 0: PORTA ^= (1 << led_position); break;
            case 1: PORTB ^= (1 << led_position); break;
            case 2: PORTC ^= (1 << led_position); break;
        }
        delay_ms(150);
        
        // Restore original state
        PORTA = led_states[0];
        PORTB = led_states[1];
        PORTC = led_states[2];

    }
}
