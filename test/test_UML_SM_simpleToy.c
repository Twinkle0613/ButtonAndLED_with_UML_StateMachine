#include "unity.h"
#include "UML_SM_simpleToy.h"
#include "GPIO.h"
#include <malloc.h>
#include "Timer.h"
void setUp(void)
{
}

void tearDown(void)
{
  
}

/*
  TaskX->state = RELEASED;
  TaskX->recordedTime = 0;
  TaskX->interval = interval;
  TaskX->whichLED = CreateLED();
  TaskX->whichButton = CreateButton();
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