#ifndef UML_SM_simpleToy_H
#define UML_SM_simpleToy_H
#include "GPIO.h"
#include "Timer.h"

typedef enum{
  RELEASED,
  PRESSED_ON,
  PRESSED_OFF,
  RELEASED_ON,
  RELEASED_OFF,
  TURNING_OFF
}FsmState;

typedef struct{
  FsmState state;
  unsigned int recordedTime;
  int interval;
  LED_t* whichLED;
  Button_t* whichButton;
}TaskState;



#endif // UML_SM_simpleToy_H
