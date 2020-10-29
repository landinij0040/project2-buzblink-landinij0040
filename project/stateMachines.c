#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
char big_state_change = 0; /* To change for each button press */


static int x = 1145;       /* for the siren */

char s1() // LED RED 0%, No Sound
{
  buzzer_set_period(0);
  red_on = 0;
  green_on = 0;
  return 1;
}

char s2() // LED RED 33%, C
{
  green_on = 0;
  static char state2 = 0;
  buzzer_set_period(1528);
  switch (state2) {
  case 0:
    red_on = 1;
    state2 = 1;
    break;
  case 1: 
    red_on = 0;
    state2 = 2;
    break;
  case 2:
    red_on = 0;
    state2 = 0;
    break;
  }
  return 1;		       
}


char s3() // LED RED 67%, D
{
  green_on = 0;
  static char state0 = 0;
  buzzer_set_period(1362);  
  switch (state0) {
  case 0:
    red_on = 1;
    state0 = 1;
    break;
  case 1: 
    red_on = 1;
    state0 = 2;
    break;
  case 2:
    red_on = 0;
    state0 = 0;
    break;
  }
  return 1;			
}    

char freq_up()  // LED GREEN, Siren Up
{ 
  x += 5;
  green_on = 1;
  red_on = 0;
  buzzer_set_period(2000000/x);
  return 1;
}


void state_advance()		/* state changes depending on big_state() */
{
  char changed = 0;
  
  switch(big_state_change){
  case 1: // LED RED 0%, No Sound
    changed = s1();
    x = 1145;
    break;
  case 2: // LED RED 33%, C
    changed = s2();
    x = 1145;
    break;
  case 3: // LED RED 67%, D
    changed = s3();
    x = 1145;
    break;
  case 4: // LED GREEN 100%, Siren
    changed = freq_up();
    break;
  } 
  led_changed = changed;
  led_update();
}
void big_state()
{
  // static char bstate = 0;
  switch(bstate){
  case 1: // LED RED 0%, No Sound
    big_state_change = 1;
    break;
  case 2: // LED RED 33%, C
    big_state_change = 2;
    break;
  case 3:// LED RED 66%, D
    big_state_change = 3;
    break;
  case 4:// LED GREEN 100%, Siren
    big_state_change = 4;
    break;
  }
}
