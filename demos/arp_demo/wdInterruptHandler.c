#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0; // the normal blink 
  static char blink_change = 0; // to dim the led 
  ++blink_count;
  if(blink_count == 125) {
    state_advance();
    blink_count = 0;
  }
  
}
