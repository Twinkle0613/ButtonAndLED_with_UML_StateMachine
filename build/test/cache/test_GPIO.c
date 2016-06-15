#include "GPIO.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}



void test_createLED_Function_and_it_should_return_a_address_and_the_State_of_LED_is_Disable(void){

 LED_t* LED1 = createLED();

 UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((LED1->state)), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT);

}



void test_turnLED_Function_when_LED1_is_turned_ON_and_OFF(void){

  LED_t* LED1 = createLED();

  turnLED(LED1,ON);

  UnityAssertEqualNumber((_U_SINT)((ON)), (_U_SINT)((LED1->state)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

  turnLED(LED1,OFF);

  UnityAssertEqualNumber((_U_SINT)((OFF)), (_U_SINT)((LED1->state)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_INT);

}



void test_createButton_Function_and_it_should_return_a_address_input_state_is_LOW(void){



  Button_t* buttonA = createButton();

  UnityAssertEqualNumber((_U_SINT)((LOW)), (_U_SINT)((buttonA->state)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);



}



void test_getButton_Function_and_it_should_return_the_state_of_button(void){



    Button_t* buttonA = createButton();

   UnityAssertEqualNumber((_U_SINT)((LOW)), (_U_SINT)((buttonA->state)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

   buttonA->state = HIGH;

   UnityAssertEqualNumber((_U_SINT)((HIGH)), (_U_SINT)((buttonA->state)), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);



}

void test_turnButton(void){



  Button_t* buttonA = createButton();

  turnButton(buttonA,ON);

  UnityAssertEqualNumber((_U_SINT)((HIGH)), (_U_SINT)((buttonA->state)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);



}
