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
    
    dprint("Updating LEDs ...");dprintln();
    // set pins as output
    DDRB |= (1<<DDB1); //led 0 (B1)
    DDRB |= (1<<DDB3); //led 1 (B3)
    
    dprint("LED Output pins set.");dprintln();
        
    /***************************
    * led 0 -> off
    * led 1 -> off
    * LEDs for Layer 0 active
    *  
    * LEDs for Layer 1 active
    * led 0 -> on
    * led 1 -> off
    * 
    * LEDs for Layer 2 active
    * led 0 -> off
    * led 1 -> on
    * 
    * LEDs for Layer 3 active
    * led 0 -> on
    * led 1 -> on
    ****************************/
    
    dprint("Setting states ...");dprintln();
    // first, set both low
    PORTB &= ~(1<<PB1);
    PORTB &= ~(1<<PB3);
    
    switch (state) {
        case 0:
            // leave both off
            break;
        case 1:
            // turn on led 0
            PORTB |= (1<<PB1);
            break;
        case 2:
            // turn on led 1
            PORTB |= (1<<PB3);
            break;
        case 3:
            // turn both on
            PORTB |= (1<<PB1);
            PORTB |= (1<<PB3);
            break;
        default:
            break;
    }
    
    dprint("LED updating complete.");dprintln();
}
