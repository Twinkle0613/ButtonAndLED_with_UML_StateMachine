#include "unity.h"
#include "GPIO.h"
#include <malloc.h>
void setUp(void)
{
}

void tearDown(void)
{
}

void test_createLED_Function_and_it_should_return_a_address_and_the_State_of_LED_is_Disable(void){
 LED_t* LED1 = createLED();
 TEST_ASSERT_EQUAL(OFF,LED1->state);
}

void test_turnLED_Function_when_LED1_is_turned_ON_and_OFF(void){
  LED_t* LED1 = createLED();
  turnLED(LED1,ON);
  TEST_ASSERT_EQUAL(ON,LED1->state);
  turnLED(LED1,OFF);
  TEST_ASSERT_EQUAL(OFF,LED1->state);
}

void test_createButton_Function_and_it_should_return_a_address_input_state_is_LOW(void){
  
  Button_t* buttonA = createButton();
  TEST_ASSERT_EQUAL(LOW,buttonA->state);
  
}

void test_getButton_Function_and_it_should_return_the_state_of_button(void){
  
    Button_t* buttonA = createButton();
   TEST_ASSERT_EQUAL(LOW,buttonA->state);
   buttonA->state = HIGH;
   TEST_ASSERT_EQUAL(HIGH,buttonA->state);
  
}
void test_turnButton(void){
  
  Button_t* buttonA = createButton();
  turnButton(buttonA,ON);
  TEST_ASSERT_EQUAL(HIGH,buttonA->state);
  
}