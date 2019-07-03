/* Author: whe024
 * Partner(s) Name: Wentao He 
 * Lab Section: A21
 * Assignment: Lab #5  Exercise #2
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {INIT, START, INCR, DECR, RESET} state;
unsigned char temp = 0x00;

void Tick()
{
        switch (state){
                case INIT :
                        state = START;
                break;
                case START :
                	if (~PINA == 0x01){                
				state = INCR;
			}
                        else if( ~PINA == 0x02 ){
                                state = DECR;
                        }
                        else if( ~PINA == 0x03 ){
                                state = RESET;
                        }
                break;
                case INCR :
                                state = START;
                break;
                case DECR :
                                state = START;
                break;
                case RESET :
                        	state = START;
                break;
                default:

                break;
        }

        switch (state){
                case INIT :
                        temp = 0x00;
                break;
                case START :

                break;
                case INCR :
			if (temp < 9){
                           temp++;
			}
                break;
                case DECR :
			if (temp > 0){
                           temp--;
			}
                break;
                case RESET :
                        temp = 0x00;
                break;
                default:

                break;
        }

	PORTC = temp;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
	 Tick();
    }
    return 1;
}
