//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  buzzer_init();
  enableWDTInterrupts();	/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}
