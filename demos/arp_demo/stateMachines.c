#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
char big_state_change = 0;

char start() // 100 %
{
  red_on = 1;
  return 1;
}

char s0() // 67%
{
  static char state0 = 0;
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
  static char bstate = 0;
  switch(bstate){
  case 0:  // For the 100% state
    big_state_change = 1;
    bstate = 1;
    break; 
  case 1: // For the 67% state
    big_state_change = 2;
    bstate = 2;
    break;
  case 2: // For the 50% state
    big_state_change = 3;
    bstate = 3;
    break;
  case 3:// For the 33% state
    big_state_change = 4;
    bstate = 4;
    break;
  case 4:// For the 0% state
    big_state_change = 0;
    bstate = 0;
    break;
  }
}
