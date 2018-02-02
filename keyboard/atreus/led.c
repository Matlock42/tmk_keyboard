/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <avr/io.h>
#include "stdint.h"
#include "led.h"


void led_set(uint8_t usb_led)
{
}

// Set up two LEDs as binary counter to 
// indicate the current layer state
void led_layer_set(uint32_t state) {
    // LED 0 is on PB1
    // LED 1 is on PB3
    
    // set pins as output
    DDRB |= (1<<DDB0); //led 0 (B0)
    DDRB |= (1<<DDB1); //led 1 (B3)
        
    // LEDs for Layer 0 active
    // led 0 -> off
    // led 1 -> off
        
    // LEDs for Layer 1 active
    // led 0 -> on
    // led 1 -> off
    
    // LEDs for Layer 2 active
    // led 0 -> off
    // led 1 -> on
    
    // LEDs for Layer 3 active
    // led 0 -> on
    // led 1 -> on
    
    /*
    if ((1<<1 & state) != 0) {
        //dprint("Layer 2: on\n");
        PORTB |= (1<<7);
    } else {
        //dprint("Layer 2: off\n");
        PORTB &= ~(1<<7);
    }
	
     // Led for Layer 4
    if ((1<<4 & state) != 0) {
        //dprint("Layer 2: on\n");
        PORTB |= (1<<3);
    } else {
        //dprint("Layer 2: off\n");
        PORTB &= ~(1<<3);
    }
	
    // Led for Layer 2
    if ((1<<2 & state) != 0) {
        //dprint("Layer 2: on\n");
        PORTB |= (1<<2);
    } else {
        //dprint("Layer 2: off\n");
        PORTB &= ~(1<<2);
    }

    // Led for Layer 3
    if ((1<<3 & state) != 0) {
        //dprint("Layer 2: on\n");
        PORTB |= (1<<1);
    } else {
        //dprint("Layer 2: off\n");
        PORTB &= ~(1<<1);
    }
    */
}
