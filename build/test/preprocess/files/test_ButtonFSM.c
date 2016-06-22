#include "mock_MockFunction.h"
#include "mock_Timer.h"
#include "GPIO.h"
#include "ButtonFSM.h"
#include "unity.h"




int timeTable[] = {0,100,150,250,300,500};

uint32_t* timePoint = ((void *)0);

uint32_t* buttonStatePointer = ((void *)0);



int fake_readButton(){

  int state = *buttonStatePointer;

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



void resetTime(void){

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



void test_getTime_it_should_return_100_150_250_300(void){

  resetTime();

  int time = getTime();

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)47, UNITY_DISPLAY_STYLE_INT);

  time = getTime();

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

    time = getTime();

  UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

    time = getTime();

  UnityAssertEqualNumber((_U_SINT)((250)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

    time = getTime();

  UnityAssertEqualNumber((_U_SINT)((300)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

}





void test_readButton(void){

  int buttonStateTable[] = {LOW,HIGH,LOW};

  setButtonPointerTable(buttonStateTable);

  UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((readButton())), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((readButton())), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((readButton())), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

}









void test_buttonConfig(void){



  ButtonSM *TaskButtonA = malloc(sizeof(ButtonSM));

  Button_t *buttonA = createButton();

  buttonConfig(TaskButtonA,10000);

  UnityAssertEqualNumber((_U_SINT)((IDLE)), (_U_SINT)((TaskButtonA->state)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((TaskButtonA->interval)), (_U_SINT)((10000)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonFSM_in_IDle_state(void){

  resetTime();

  int buttonStateTable[] = {HIGH,LOW};

  setButtonPointerTable(buttonStateTable);

  ButtonSM *TaskButtonA = malloc(sizeof(ButtonSM));

  buttonConfig(TaskButtonA,100);

  buttonFSM(TaskButtonA);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((TaskButtonA->recordedTime)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((WAIT)), (_U_SINT)((TaskButtonA->state)), (((void *)0)), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT);

}





void test_buttonFSM_in_Wait_state_prevState_is_equal_curState_the_output_should_be_follow_curState(void){

  int buttonStateTable[] = {HIGH,HIGH};

  setButtonPointerTable(buttonStateTable);

  resetTime();

  ButtonSM *TaskButtonA = malloc(sizeof(ButtonSM));

  buttonConfig(TaskButtonA,100);

  buttonFSM(TaskButtonA);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((TaskButtonA->recordedTime)), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((WAIT)), (_U_SINT)((TaskButtonA->state)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

  buttonFSM(TaskButtonA);

  UnityAssertEqualNumber((_U_SINT)((HIGH)), (_U_SINT)((TaskButtonA->curState)), (((void *)0)), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((HIGH)), (_U_SINT)((TaskButtonA->output)), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((IDLE)), (_U_SINT)((TaskButtonA->state)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

}



void test_buttonFSM_in_Wait_state_prevState_is_Not_equal_curState_the_output_should_be_follow_curState(void){

  int buttonStateTable[] = {HIGH,LOW};

  setButtonPointerTable(buttonStateTable);

  resetTime();

  ButtonSM *TaskButtonA = malloc(sizeof(ButtonSM));

  buttonConfig(TaskButtonA,100);

  buttonFSM(TaskButtonA);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((TaskButtonA->recordedTime)), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((WAIT)), (_U_SINT)((TaskButtonA->state)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

  buttonFSM(TaskButtonA);

  UnityAssertEqualNumber((_U_SINT)((LOW)), (_U_SINT)((TaskButtonA->curState)), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LOW)), (_U_SINT)((TaskButtonA->prevState)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((IDLE)), (_U_SINT)((TaskButtonA->state)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

}
