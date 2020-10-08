#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0; // the normal blink 
  static char blink_change = 0; // to dim the led 
  ++blink_count;
  ++blink_change;
  if(blink_count == 1) {
    state_advance();
    blink_count = 0;
  }

  if(blink_change == 250){
    big_state();
    blink_change = 0;
  }
  
}
