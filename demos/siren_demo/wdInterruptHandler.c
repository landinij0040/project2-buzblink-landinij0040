#include <msp430.h>
#include "stateMachines.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0; // the normal blink
  blink_count++;
  if(blink_count  == 12){
    state_advance();
    blink_count = 0 ;
  }
}
