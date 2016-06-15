#include "GPIO.h"
#include <stdint.h>
#include <malloc.h>


Button_t* createButton(void){
  Button_t* ButtonX = malloc(sizeof(LED_t));
  ButtonX->state = LOW;
  return ButtonX;
}

int getButton(Button_t* ButtonX){
  return(ButtonX->state);
}
LED_t *createLED(void){
  LED_t* LEDx = malloc(sizeof(LED_t));
  LEDx->state = OFF;
  return LEDx;
}
void turnLED(LED_t* LEDx, FunctionalState state){
  LEDx->state = state;
}

void turnButton(Button_t* ButtonX, FunctionalState state){
  ButtonX->state = state;
}