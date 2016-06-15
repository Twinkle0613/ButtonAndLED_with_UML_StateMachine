#include "mock_Timer.h"
#include "GPIO.h"
#include "UML_SM_simpleToy.h"
#include "unity.h"




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











void test_getTime_it_should_return_100_150_250_300(void){

  resetTime();

  int time = getTime();

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

  time = getTime();

  UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_INT);

    time = getTime();

  UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_INT);

    time = getTime();

  UnityAssertEqualNumber((_U_SINT)((250)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

    time = getTime();

  UnityAssertEqualNumber((_U_SINT)((300)), (_U_SINT)((time)), (((void *)0)), (_U_UINT)46, UNITY_DISPLAY_STYLE_INT);

}









void test_TaskConfig_initialize_the_stucture_of_Task(void){

  TaskState *TaskA = malloc(sizeof(TaskState));

  LED_t *LEDA = createLED();

  Button_t *ButtonA = createButton();

  TaskConfig(TaskA,25000,LEDA,ButtonA);

  UnityAssertEqualNumber((_U_SINT)((RELEASED)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((TaskA->recordedTime)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((25000)), (_U_SINT)((TaskA->interval)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((LEDA)), (_U_SINT)(_UP)((TaskA->whichLED)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((ButtonA)), (_U_SINT)(_UP)((TaskA->whichButton)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LOW)), (_U_SINT)((TaskA->whichButton->state)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

}















void test_Releases_state_if_button_is_released_everyting_is_default(void){

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   turnButton(TaskA->whichButton,LOW);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)77, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((TaskA->recordedTime)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

}



void test_Releases_state_if_button_is_pressed_LED_will_turn_ON_and_state_will_change_to_Pressed_On(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)88, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((TaskA->recordedTime)), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

}

void test_pressed_on_state_if_the_button_is_pressed_when_timer_is_expires_(void){

    resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

}



void test_pressed_on_state_if__(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = PRESSED_ON;

   turnButton(TaskA->whichButton,LOW);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT);

}

void test_pressed_off_state_if_the_button_is_pressed(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = PRESSED_OFF;

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)149, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)154, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);



}



void test_pressed_off_state_if_the_button_is_release(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = PRESSED_OFF;

   turnButton(TaskA->whichButton,LOW);

   buttonAndLed(TaskA);

     UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_INT);



}

void test_released_on_state_if_the_button_is_pressed(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = RELEASED_ON;

   turnButton(TaskA->whichButton,LOW);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)185, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)191, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)192, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)194, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);





}



void test_released_on_state_if_the_button_is_released(void){



   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = RELEASED_ON;

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((TURNING_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);



}

void test_released_off_state_if_the_button_is_pressed(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = RELEASED_OFF;

   turnButton(TaskA->whichButton,LOW);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)234, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT);





}

void test_released_off_state_if_the_button_is_released(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = RELEASED_OFF;

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((TURNING_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_INT);





}

void test_turning_off_state_if_the_button_is_released(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = TURNING_OFF;

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((TURNING_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)269, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)270, UNITY_DISPLAY_STYLE_INT);

}





void test_turning_off_state_if_the_button_is_pressed(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   TaskA->state = TURNING_OFF;

   turnButton(TaskA->whichButton,LOW);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)281, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)282, UNITY_DISPLAY_STYLE_INT);

}



void test_TaskConfig_Pressed_Release_Pressed_Test_it_should_in_TUnRNING_off_state(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   turnButton(TaskA->whichButton,LOW);

   buttonAndLed(TaskA);

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((TURNING_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)295, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)296, UNITY_DISPLAY_STYLE_INT);

}



void test_TaskConfig_Wait_blinking_Test_when_button_is_always_pressed_Task_state_should_move_from_Pressed_ON_to_Pressed_Off_off_state(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   buttonAndLed(TaskA);

   buttonAndLed(TaskA);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)308, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)309, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((PRESSED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)312, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)313, UNITY_DISPLAY_STYLE_INT);

}



void test_TaskConfig_Wait_blinking_Test_when_button_is_always_release_Task_state_should_move_from_Pressed_ON_to_Pressed_Off_off_state(void){

   resetTime();

   TaskState *TaskA = malloc(sizeof(TaskState));

   TaskConfig(TaskA,250,createLED(),createButton());

   turnButton(TaskA->whichButton,HIGH);

   buttonAndLed(TaskA);

   turnButton(TaskA->whichButton,LOW);

   buttonAndLed(TaskA);

   buttonAndLed(TaskA);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_ON)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)326, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT);

   buttonAndLed(TaskA);

   buttonAndLed(TaskA);

   UnityAssertEqualNumber((_U_SINT)((RELEASED_OFF)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)330, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)331, UNITY_DISPLAY_STYLE_INT);

}
