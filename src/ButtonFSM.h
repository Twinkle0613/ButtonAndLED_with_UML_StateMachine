#ifndef ButtonFSM_H
#define ButtonFSM_H
#include "GPIO.h"
#include "Timer.h"
typedef enum{
  IDLE,
  WAIT,
}ButtonState;

typedef struct {
  Button_t* whichButton;
  ButtonState state;
  int interval;
  int output;
  int curState;
  int prevState;
  unsigned int recordedTime;
}ButtonSM;

#endif // ButtonFSM_H
