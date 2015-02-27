#include <avr/io.h>
#include <util/delay.h>

/*
 * LED pin:	AVR pin:
 *		a		0
 * 		b		1
 *		D.P		2
 *		c		3
 *		d		4
 *		e		5
 *		f		6
 *		g		7
 */
void
led_show_number(int n)
{
	switch (n) {
	case (0):
		/* PORTD = 1 << PIND2 | 1 << PIND7 */
		PORTD = 1 << 2 | 1 << 7;
		break;
	case (1):
		PORTD = 1 << 2 | 1 << 0 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7;
		break;
	case (2):
		PORTD = 1 << 2 | 1 << 6 | 1 << 3;
		break;
	case (3):
		PORTD = 1 << 2 | 1 << 6 | 1 << 5;
		break;
	case (4):
		PORTD = 1 << 2 | 1 << 0 | 1 << 5 | 1 << 4;
		break;
	case (5):
		PORTD = 1 << 2 | 1 << 1 | 1 << 5;
		break;
	case (6):
		PORTD = 1 << 2 | 1 << 1;
		break;
	case (7):
		PORTD = 1 << 2 | 1 << 4 | 1 << 5 | 1 << 6 | 1 << 7;
		break;
	case (8):
		PORTD = 1 << 2;
		break;
	case (9):
		PORTD = 1 << 2 | 1 << 5;
		break;
	}
}

void
blink_leds()
{
	int i;

	for (i = 0; i < 20; i++) {
		/* clear all leds */
		PORTD = 0x00;
		_delay_ms(60);
		/* clear all leds */
		PORTD = 0xff;
		_delay_ms(60);
	}
}

int
main(void)
{
	int i;
	/* write to DDR D */
    DDRD = 0xff;
	/* read from DDR C */
	DDRC = 0x00;

	for (;;) {
		for (i = 0; i < 10; i++) {
			if (bit_is_clear(PINC, 0)) {
				led_show_number(i);
				_delay_ms(500);
			} else {
				/* motion detected */
				blink_leds();
			}
		}
    }

    return (0);
}
