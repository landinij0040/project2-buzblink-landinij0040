#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0; 
  ++blink_count;
  if(blink_count == 50) {
    state_advance();
    blink_count = 0;
  }
  
}
