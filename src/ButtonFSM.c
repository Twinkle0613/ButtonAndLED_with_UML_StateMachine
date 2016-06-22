#include "ButtonFSM.h"
#include "GPIO.h"
#include "Timer.h"
#include <stdint.h>


void buttonConfig(ButtonSM* buttonX,int interval ){
  buttonX->state = IDLE;
  buttonX->interval = interval;
  buttonX->prevState = LOW;
}


void buttonFSM(ButtonSM* buttonX){
   
   int storeState;
   uint32_t currentTime;
  switch(buttonX->state){
    
    case IDLE:
    storeState = readButton();
    if( buttonX->prevState != storeState ){
      buttonX->prevState = storeState;
      buttonX->recordedTime = getTime();
      buttonX->state = WAIT;
    }
    break;
    
    case WAIT:
    currentTime = getTime();
    if(currentTime - buttonX->recordedTime >= buttonX->interval){
      buttonX->curState = readButton();
      if(buttonX->prevState == buttonX->curState){
       buttonX->output = buttonX->curState;
      }else{
       buttonX->prevState = buttonX->curState;
      } 
      buttonX->state = IDLE;
    }
    
    break;
  }
}