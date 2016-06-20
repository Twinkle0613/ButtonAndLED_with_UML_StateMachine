#include "unity.h"
#include "ButtonFSM.h"
#include "GPIO.h"
#include "mock_Timer.h"
#include "mock_MockFunction.h"
#include <malloc.h>



uint32_t* timePoint = NULL;
uint32_t* buttonStatePointer = NULL;

int fake_readButton(){
  int state  = *buttonStatePointer;
  buttonStatePointer++;
  return state;
}

uint32_t fake_getTime(){
  uint32_t time = *timePoint;
  timePoint++;  
  return time;
}

void setButtonPointerTable(int state[]){
  buttonStatePointer = state;
}

void setTimePointerTable(int timeTable[]){
  timePoint = timeTable;
}

void setUp(void)
{
  getTime_StubWithCallback(fake_getTime);
  readButton_StubWithCallback(fake_readButton);
}

void tearDown(void)
{
}

void  test_getTime_it_should_return_100_150_250_300(void){
  int timeTable[] = {0,100,150,250,300,500};
  setTimePointerTable(timeTable);
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


void test_readButton(void){
  int buttonStateTable[] = {LOW,HIGH,LOW};
  setButtonPointerTable(buttonStateTable);
  TEST_ASSERT_EQUAL(OFF,readButton());
  TEST_ASSERT_EQUAL(ON,readButton());
  TEST_ASSERT_EQUAL(OFF,readButton());
}




void test_buttonConfig(void){
  
  ButtonSM *TaskButtonA = malloc(sizeof(ButtonSM));
  Button_t *buttonA = createButton();
  buttonConfig(TaskButtonA,10000);
  
  TEST_ASSERT_EQUAL(IDLE,TaskButtonA->state);
  TEST_ASSERT_EQUAL(TaskButtonA->interval,10000);
}

void test_buttonFSM_in_IDle_state(void){
  int buttonStateTable[] = {HIGH,LOW,HIGH};
  setButtonPointerTable(buttonStateTable);
  int timeTable[] = {0,100,150,250,300,500};
  setTimePointerTable(timeTable);
  ButtonSM *TaskButtonA = malloc(sizeof(ButtonSM));
  buttonConfig(TaskButtonA,100);
  buttonFSM(TaskButtonA);
  TEST_ASSERT_EQUAL(0,TaskButtonA->recordedTime);
  TEST_ASSERT_EQUAL(WAIT,TaskButtonA->state);
}


void test_buttonFSM_in_Wait_state_prevState_is_equal_curState_the_output_should_be_follow_curState(void){
  int buttonStateTable[] = {HIGH,HIGH,HIGH};
  setButtonPointerTable(buttonStateTable);
  int timeTable[] = {0,100};
  setTimePointerTable(timeTable);
  ButtonSM *TaskButtonA = malloc(sizeof(ButtonSM));
  buttonConfig(TaskButtonA,100);
  buttonFSM(TaskButtonA);
  TEST_ASSERT_EQUAL(0,TaskButtonA->recordedTime);
  TEST_ASSERT_EQUAL(WAIT,TaskButtonA->state);
  buttonFSM(TaskButtonA);
  TEST_ASSERT_EQUAL(HIGH,TaskButtonA->curState);
  TEST_ASSERT_EQUAL(HIGH,TaskButtonA->output);
  TEST_ASSERT_EQUAL(IDLE,TaskButtonA->state);
}

void test_buttonFSM_in_Wait_state_prevState_is_Not_equal_curState_the_output_should_be_follow_curState(void){
  int buttonStateTable[] = {HIGH,LOW,HIGH};
  setButtonPointerTable(buttonStateTable);
  int timeTable[] = {0,100};
  setTimePointerTable(timeTable);
  ButtonSM *TaskButtonA = malloc(sizeof(ButtonSM));
  buttonConfig(TaskButtonA,100);
  buttonFSM(TaskButtonA);
  TEST_ASSERT_EQUAL(0,TaskButtonA->recordedTime);
  TEST_ASSERT_EQUAL(WAIT,TaskButtonA->state);
  buttonFSM(TaskButtonA);
  TEST_ASSERT_EQUAL(LOW,TaskButtonA->curState);
  TEST_ASSERT_EQUAL(LOW,TaskButtonA->prevState);
  //TEST_ASSERT_EQUAL(HIGH,TaskButtonA->output);
  TEST_ASSERT_EQUAL(IDLE,TaskButtonA->state);
}
