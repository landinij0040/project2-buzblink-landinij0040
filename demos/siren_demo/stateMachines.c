#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"


static int x = 500;
static int go_down = 0;
char freq_up_green_led()
{
  buzzer_set_period(2000000/x);
  green_on = 1;
  return 1;

}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;
  switch(go_down){
  case 0: changed = freq_up_green_led();
  }

  
  led_changed = changed;
  led_update();
}


