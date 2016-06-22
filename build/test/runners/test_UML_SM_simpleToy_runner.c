/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  CMock_Init(); \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
    CMock_Verify(); \
  } \
  CMock_Destroy(); \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include "cmock.h"
#include <setjmp.h>
#include <stdio.h>
#include "mock_Timer.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_getTime_it_should_return_100_150_250_300(void);
extern void test_TaskConfig_initialize_the_stucture_of_Task(void);
extern void test_Releases_state_if_button_is_released_everyting_is_default(void);
extern void test_Releases_state_if_button_is_pressed_LED_will_turn_ON_and_state_will_change_to_Pressed_On(void);
extern void test_pressed_on_state_if_the_button_is_pressed_when_timer_is_expires_(void);
extern void test_pressed_on_state_if__(void);
extern void test_pressed_off_state_if_the_button_is_pressed(void);
extern void test_pressed_off_state_if_the_button_is_release(void);
extern void test_released_on_state_if_the_button_is_pressed(void);
extern void test_released_on_state_if_the_button_is_released(void);
extern void test_released_off_state_if_the_button_is_pressed(void);
extern void test_released_off_state_if_the_button_is_released(void);
extern void test_turning_off_state_if_the_button_is_released(void);
extern void test_turning_off_state_if_the_button_is_pressed(void);
extern void test_TaskConfig_Pressed_Release_Pressed_Test_Task_state_should_in_The_TUnRNING_off_state(void);
extern void test_TaskConfig_Wait_blinking_Test_when_button_is_always_pressed_Task_state_should_move_from_Pressed_ON_to_Pressed_Off_off_state(void);
extern void test_TaskConfig_Wait_blinking_Test_when_button_is_always_release_Task_state_should_move_from_Pressed_ON_to_Pressed_Off_off_state(void);


//=======Mock Management=====
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_Timer_Init();
}
static void CMock_Verify(void)
{
  mock_Timer_Verify();
}
static void CMock_Destroy(void)
{
  mock_Timer_Destroy();
}

//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  CMock_Verify();
  CMock_Destroy();
  tearDown();
  CMock_Init();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("test_UML_SM_simpleToy.c");
  RUN_TEST(test_getTime_it_should_return_100_150_250_300, 35);
  RUN_TEST(test_TaskConfig_initialize_the_stucture_of_Task, 52);
  RUN_TEST(test_Releases_state_if_button_is_released_everyting_is_default, 72);
  RUN_TEST(test_Releases_state_if_button_is_pressed_LED_will_turn_ON_and_state_will_change_to_Pressed_On, 82);
  RUN_TEST(test_pressed_on_state_if_the_button_is_pressed_when_timer_is_expires_, 100);
  RUN_TEST(test_pressed_on_state_if__, 119);
  RUN_TEST(test_pressed_off_state_if_the_button_is_pressed, 138);
  RUN_TEST(test_pressed_off_state_if_the_button_is_release, 159);
  RUN_TEST(test_released_on_state_if_the_button_is_pressed, 178);
  RUN_TEST(test_released_on_state_if_the_button_is_released, 200);
  RUN_TEST(test_released_off_state_if_the_button_is_pressed, 221);
  RUN_TEST(test_released_off_state_if_the_button_is_released, 242);
  RUN_TEST(test_turning_off_state_if_the_button_is_released, 262);
  RUN_TEST(test_turning_off_state_if_the_button_is_pressed, 274);
  RUN_TEST(test_TaskConfig_Pressed_Release_Pressed_Test_Task_state_should_in_The_TUnRNING_off_state, 285);
  RUN_TEST(test_TaskConfig_Wait_blinking_Test_when_button_is_always_pressed_Task_state_should_move_from_Pressed_ON_to_Pressed_Off_off_state, 299);
  RUN_TEST(test_TaskConfig_Wait_blinking_Test_when_button_is_always_release_Task_state_should_move_from_Pressed_ON_to_Pressed_Off_off_state, 316);

  CMock_Guts_MemFreeFinal();
  return (UnityEnd());
}
