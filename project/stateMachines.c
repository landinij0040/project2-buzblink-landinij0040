#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
char big_state_change = 0;

char start() // 100 %
{
  buzzer_set_period(1528); // Playing C
  red_on = 1;
  return 1;
}

char s0() // 67%
{
  static char state0 = 0;
  buzzer_set_period(1362); // Playing D 
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
  return 1;			/* always changes an led */
} 

char s1() // 50%
{
  static char state1 = 0;
  buzzer_set_period(1213); // Playing E
  switch (state1) {
  case 0:
    red_on = 1;
    state1 = 1;
    break;
  case 1: 
    red_on = 0;
    state1 = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char s2() // 33%
{
  static char state2 = 0;
  buzzer_set_period(1145); // Playing F
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
  return 1;			/* always changes an led */
}

char end() // 0%
{
  red_on = 0;
  buzzer_set_period(0);
  return 1;

}  

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;
  
  switch(big_state_change){
  case 0: //Start
    changed = start();
    break;
  case 1: // 67%
    changed = s0();
    break;
  case 2:// 50%
    changed = s1();
    break;
  case 3: // 33%
    changed = s2();
    break;
  case 4: // end
    changed = end();
    break;
  } 
  led_changed = changed;
  led_update();
}
void big_state()
{
  // static char bstate = 0;
  switch(bstate){
    //  case 0:  // For the 100% state
      // big_state_change = 1;
    // bstate = 1;
    // break; 
  case 1: // LED 100%, C
    big_state_change = 0;
    break;
  case 2: // LED 67%, D
    big_state_change = 1;
    break;
  case 3:// LED 50%, E
    big_state_change = 2;
    break;
  case 4:// LED 0%, no sound
    big_state_change = 4;
    break;
  }
}
