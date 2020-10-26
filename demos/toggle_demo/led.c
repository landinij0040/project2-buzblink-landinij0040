#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  switch_state_down = 0;
  P1OUT = LED_GREEN;
  led_update();
}

void led_update(){
  if (switch_state_changed) {
    if(switch_state_down == 0){
      char ledFlags = 0; /* by default, no LEDs on */
      if(P1OUT == LED_GREEN){
	ledFlags |= LED_RED;
      }
      if(P1OUT == LED_RED){
	ledFlags |= LED_GREEN;
      }

      P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
      P1OUT |= ledFlags;         // set bits for on leds
    }
    
  }
  switch_state_changed = 0;
}

