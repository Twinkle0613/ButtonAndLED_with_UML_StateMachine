#include "UML_SM_simpleToy.h"
#include "GPIO.h"
#include "Timer.h"
#include <stdint.h>
 
#define IS_PRESSED HIGH
#define IS_RELEASE LOW
#define LED_ON ON
#define LED_OFF OFF


void TaskConfig(TaskState* TaskX,int interval,LED_t* whichLED, Button_t* whichButton){
  TaskX->state = RELEASED;
  TaskX->recordedTime = 0;
  TaskX->interval = interval;
  TaskX->whichLED = whichLED;
  TaskX->whichButton = whichButton;
}
void buttonAndLed( TaskState* TaskX ){
  uint32_t currentTime;
  switch(TaskX->state) {
     case RELEASED:
     
     if(getButton(TaskX->whichButton) == IS_PRESSED){
       turnLED(TaskX->whichLED,LED_ON);
       TaskX->recordedTime = getTime();
       TaskX->state = PRESSED_ON;
     }
     
     break;
     
     case PRESSED_ON:
     
     if(getButton(TaskX->whichButton) == IS_PRESSED){
       currentTime = getTime();     
       turnLED(TaskX->whichLED,LED_ON);
       if(currentTime - TaskX->recordedTime >= TaskX->interval){  
        TaskX->recordedTime = currentTime;
        turnLED(TaskX->whichLED,LED_OFF);
        TaskX->state = PRESSED_OFF; 
       }
     }else{
       TaskX->state = RELEASED_ON;
     }
     
     break;
     
     case PRESSED_OFF:
     
     if(getButton(TaskX->whichButton) == IS_PRESSED){
       currentTime = getTime();     
       turnLED(TaskX->whichLED,LED_OFF);
       if(currentTime - TaskX->recordedTime >= TaskX->interval){  
        TaskX->recordedTime = currentTime;
        turnLED(TaskX->whichLED,LED_ON);
        TaskX->state = PRESSED_ON; 
       }
     }else{
       TaskX->state = RELEASED_OFF;
     }
     break;
     
     case RELEASED_ON:
     
     if(getButton(TaskX->whichButton) == IS_RELEASE){
       currentTime = getTime();     
       turnLED(TaskX->whichLED,LED_ON);
       if(currentTime - TaskX->recordedTime >= TaskX->interval){  
        TaskX->recordedTime = currentTime;
        turnLED(TaskX->whichLED,LED_OFF);
        TaskX->state = RELEASED_OFF; 
       }
     }else{
       TaskX->state = TURNING_OFF;
       turnLED(TaskX->whichLED,LED_OFF);
     }
     break;
     
     case RELEASED_OFF:
     
     if(getButton(TaskX->whichButton) == IS_RELEASE){
       currentTime = getTime();     
       turnLED(TaskX->whichLED,LED_OFF);
       if(currentTime - TaskX->recordedTime >= TaskX->interval){  
        TaskX->recordedTime = currentTime;
        turnLED(TaskX->whichLED,LED_ON);
        TaskX->state = RELEASED_ON; 
       }
     }else{
       TaskX->state = TURNING_OFF;
     }
     
     break;
     
     case TURNING_OFF:
     
     if(getButton(TaskX->whichButton) == IS_RELEASE){
       TaskX->state = RELEASED;
     }
     
     break;
    
  }
  
  
}