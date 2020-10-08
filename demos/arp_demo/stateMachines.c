

#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h" 

void state_advance()		/* alternate between toggling red & green */
{
  buzzer_set_period(1528);
}
