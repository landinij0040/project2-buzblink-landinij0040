

#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h" 

void cNote(void){ //C 
  buzzer_set_period(1528); 
}
void dNote(void){ //D 
  buzzer_set_period(1362); 
}
void eNote(void){ //E 
  buzzer_set_period(1213); 
}
void fNote(void){ //F 
  buzzer_set_period(1145); 
}


void state_advance()		/* alternate between toggling red & green */
{
  static char nextNote = 0;
  switch(nextNote){
  case 0: cNote(); nextNote = 1; break;
  case 1: dNote(); nextNote = 2; break;
  case 2: eNote(); nextNote = 3; break;
  case 3: fNote(); nextNote = 0; break;
    
    
    

  }
}
