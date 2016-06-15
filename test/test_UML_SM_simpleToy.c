#include "unity.h"
#include "UML_SM_simpleToy.h"
#include "GPIO.h"
#include <malloc.h>
#include "mock_Timer.h"
#include <stdint.h>

uint32_t timeSequence[] = {0,100,150,250,300,500};
uint32_t* timePoint = timeSequence;

uint32_t fake_getTime(){
  uint32_t time = *timePoint;
  timePoint++;
  
  return time;
}

void resetTime(){
  timePoint = timeSequence;
}
void setUp(void)
{
  getTime_StubWithCallback(fake_getTime);
}

void tearDown(void)
{
  
}
/*
 Testing fake_getTime
  - getTime() should return 0,100,150,250,300 sequentially 
*/

void  test_getTime_it_should_return_100_150_250_300(void){
  resetTime();
  int time = getTime();
  TEST_ASSERT_EQUAL(0,time);
  time = getTime();
  TEST_ASSERT_EQUAL(100,time);
    time = getTime();
  TEST_ASSERT_EQUAL(150,time);
    time = getTime();
  TEST_ASSERT_EQUAL(250,time);
    time = getTime();
  TEST_ASSERT_EQUAL(300,time);
}
/*
 Testing TaskConfig() Function

*/
void test_TaskConfig_initialize_the_stucture_of_Task(void){
  TaskState *TaskA = malloc(sizeof(TaskState));
  LED_t *LEDA = createLED();
  Button_t *ButtonA = createButton();
  TaskConfig(TaskA,25000,LEDA,ButtonA);
  TEST_ASSERT_EQUAL(RELEASED,TaskA->state);
  TEST_ASSERT_EQUAL(0,TaskA->recordedTime);
  TEST_ASSERT_EQUAL(25000,TaskA->interval);
  TEST_ASSERT_EQUAL_PTR(LEDA,TaskA->whichLED);
  TEST_ASSERT_EQUAL_PTR(ButtonA,TaskA->whichButton);
  TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
  TEST_ASSERT_EQUAL(LOW,TaskA->whichButton->state);
}
/*
   Testing RELEASED state in buttonAndLed().
   if the button is released, everything is in default.
   if the button is pressed, the LED will turn ON ,the timer will started and the 
   Task state will move from RELEASED to PRESSED_ON.
*/

void test_Releases_state_if_button_is_released_everyting_is_default(void){
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   turnButton(TaskA->whichButton,IS_RELEASE);
   buttonAndLed(TaskA);
   TEST_ASSERT_EQUAL(RELEASED,TaskA->state);
   TEST_ASSERT_EQUAL(0,TaskA->recordedTime);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
}

void test_Releases_state_if_button_is_pressed_LED_will_turn_ON_and_state_will_change_to_Pressed_On(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA);
   TEST_ASSERT_EQUAL(PRESSED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(0,TaskA->recordedTime);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
}

/*
   Testing PRESSED_ON state in buttonAndLed().
   If the button is released, the task state will move from PRESSED_ON to RELEASED_ON.
   If the button is pressed, when timer expires , the LED will turn off and task state will
   move from PRESSED_ON to PRESSED_OFF.
*/

void test_pressed_on_state_if_the_button_is_pressed_when_timer_is_expires_(void){
    resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA); // getTime is 0
   TEST_ASSERT_EQUAL(PRESSED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 100
   TEST_ASSERT_EQUAL(PRESSED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 150
   TEST_ASSERT_EQUAL(PRESSED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 250
   TEST_ASSERT_EQUAL(PRESSED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
}

void test_pressed_on_state_if__(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = PRESSED_ON;
   turnButton(TaskA->whichButton,IS_RELEASE);
   buttonAndLed(TaskA);
   TEST_ASSERT_EQUAL(RELEASED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
}


/*
   testing PRESSED_OFF state in buttonAndLed().
   If the button is released, the task state will move from PRESSED_OFF to RELEASED_OFF.
   if the button is pressed, when timer expires ,the LED will turn On and task state will
   move from PRESSED_OFF to PRESSED_ON.
*/

void test_pressed_off_state_if_the_button_is_pressed(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = PRESSED_OFF;
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA); // getTime is 0
   TEST_ASSERT_EQUAL(PRESSED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 100
   TEST_ASSERT_EQUAL(PRESSED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 150
   TEST_ASSERT_EQUAL(PRESSED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 250
   TEST_ASSERT_EQUAL(PRESSED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
  
}

void test_pressed_off_state_if_the_button_is_release(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = PRESSED_OFF;
   turnButton(TaskA->whichButton,IS_RELEASE);
   buttonAndLed(TaskA);
     TEST_ASSERT_EQUAL(RELEASED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
  
}

/*
   testing RELEASED_ON state in buttonAndLed().
   If the button is released, the task state will move from RELEASED_ON to TURNING_OFF.
   if the button is pressed, when timer expires ,the LED will turn On and task state will
   move from RELEASED_ON to RELEASED_OFF.
*/

void test_released_on_state_if_the_button_is_pressed(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = RELEASED_ON;
   turnButton(TaskA->whichButton,IS_RELEASE);
   buttonAndLed(TaskA); // getTime is 0
   TEST_ASSERT_EQUAL(RELEASED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 100
   TEST_ASSERT_EQUAL(RELEASED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 150
   TEST_ASSERT_EQUAL(RELEASED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 250
   TEST_ASSERT_EQUAL(RELEASED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
  
  
}

void test_released_on_state_if_the_button_is_released(void){
  
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = RELEASED_ON;
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA);
   TEST_ASSERT_EQUAL(TURNING_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
  
}

/*
   testing RELEASED_OFF state in buttonAndLed().
   If the button is released, the task state will move from RELEASED_OFF to TURNING_OFF.
   if the button is pressed, when timer expires ,the LED will turn OFF and task state will
   move from RELEASED_OFF to RELEASED_ON.
*/


void test_released_off_state_if_the_button_is_pressed(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = RELEASED_OFF;
   turnButton(TaskA->whichButton,IS_RELEASE);
   buttonAndLed(TaskA); // getTime is 0
   TEST_ASSERT_EQUAL(RELEASED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 100
   TEST_ASSERT_EQUAL(RELEASED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 150
   TEST_ASSERT_EQUAL(RELEASED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
   buttonAndLed(TaskA); // getTime is 250
   TEST_ASSERT_EQUAL(RELEASED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
  
  
}
void test_released_off_state_if_the_button_is_released(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = RELEASED_OFF;
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA);
   TEST_ASSERT_EQUAL(TURNING_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
  
  
}

/*
   testing TURNING_OFF state in buttonAndLed().
   If the button is released, the task state will move from TURNING_OFF to RELEASED.
   if the button is pressed, the task state not be change.
*/


void test_turning_off_state_if_the_button_is_released(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = TURNING_OFF;
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA);
   TEST_ASSERT_EQUAL(TURNING_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
}


void test_turning_off_state_if_the_button_is_pressed(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   TaskA->state = TURNING_OFF;
   turnButton(TaskA->whichButton,IS_RELEASE);
   buttonAndLed(TaskA);
   TEST_ASSERT_EQUAL(RELEASED,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
}

void test_TaskConfig_Pressed_Release_Pressed_Test_Task_state_should_in_The_TUnRNING_off_state(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA);
   turnButton(TaskA->whichButton,IS_RELEASE);
   buttonAndLed(TaskA);
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA);
   TEST_ASSERT_EQUAL(TURNING_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
}

void test_TaskConfig_Wait_blinking_Test_when_button_is_always_pressed_Task_state_should_move_from_Pressed_ON_to_Pressed_Off_off_state(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA);  //getTime is 0
   buttonAndLed(TaskA);  //getTime is 100
   buttonAndLed(TaskA);  //getTime is 150
   buttonAndLed(TaskA);  //getTime is 250
   TEST_ASSERT_EQUAL(PRESSED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
   buttonAndLed(TaskA);  //getTime is 300
   buttonAndLed(TaskA);  //getTime is 500
   TEST_ASSERT_EQUAL(PRESSED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
}

void test_TaskConfig_Wait_blinking_Test_when_button_is_always_release_Task_state_should_move_from_Pressed_ON_to_Pressed_Off_off_state(void){
   resetTime();
   TaskState *TaskA = malloc(sizeof(TaskState));
   TaskConfig(TaskA,250,createLED(),createButton());
   turnButton(TaskA->whichButton,IS_PRESSED);
   buttonAndLed(TaskA);  //getTime is 0
   turnButton(TaskA->whichButton,IS_RELEASE);
   buttonAndLed(TaskA);  //getTime is 100
   buttonAndLed(TaskA);  //getTime is 150
   buttonAndLed(TaskA);  //getTime is 250
   TEST_ASSERT_EQUAL(RELEASED_ON,TaskA->state);
   TEST_ASSERT_EQUAL(ON,TaskA->whichLED->state);
   buttonAndLed(TaskA);  //getTime is 300
   buttonAndLed(TaskA);  //getTime is 500
   TEST_ASSERT_EQUAL(RELEASED_OFF,TaskA->state);
   TEST_ASSERT_EQUAL(OFF,TaskA->whichLED->state);
}



