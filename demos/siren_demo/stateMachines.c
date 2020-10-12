#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"


static int x = 500;
static int go_down = 0;
char freq_up_green_led()
{
  if(x != 5000){
    x += 225;
    green_on = 1;
  }else{
    go_down = 1;
    green_on = 0;
  }
  buzzer_set_period(2000000/x);
  return 1;
}

char freq_down_red_led()
{
  if(x != 500){
    x -= 450;
    red_on = 1;
  }else{
    go_down = 0;
    red_on = 0;
  }
  buzzer_set_period(2000000/x);
  return 1;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;
  switch(go_down){
  case 0: changed = freq_up_green_led(); break;
  case 1: changed = freq_down_red_led(); break;
  }

  
  led_changed = changed;
  led_update();
}


