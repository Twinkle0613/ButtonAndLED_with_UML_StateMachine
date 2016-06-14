#include "Timer.h"
#include "GPIO.h"
#include "UML_SM_simpleToy.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{



}

void test_TaskConfig_initialize_the_stucture_of_Task(void){



  TaskState *TaskA = malloc(sizeof(TaskState));

  LED_t *LEDA = createLED();

  Button_t *ButtonA = createButton();

  TaskConfig(TaskA,25000,LEDA,ButtonA);



  UnityAssertEqualNumber((_U_SINT)((RELEASED)), (_U_SINT)((TaskA->state)), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((TaskA->recordedTime)), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((25000)), (_U_SINT)((TaskA->interval)), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_UP)((LEDA)), (_U_SINT)(_UP)((TaskA->whichLED)), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((ButtonA)), (_U_SINT)(_UP)((TaskA->whichButton)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((TaskA->whichLED->state)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((LOW)), (_U_SINT)((TaskA->whichButton->state)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);



}
