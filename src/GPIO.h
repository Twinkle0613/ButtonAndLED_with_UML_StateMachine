#ifndef GPIO_H
#define GPIO_H



typedef enum {OFF = 0, ON = !OFF} FunctionalState;
typedef enum {LOW = 0, HIGH = !LOW} inputState;

typedef struct{
  FunctionalState state;
}LED_t;

typedef struct{
  inputState state;
}Button_t;


Button_t* createButton(void);
LED_t* createLED(void);
int getButton(Button_t* ButtonX);
void turnLED(LED_t* LEDx, FunctionalState state);


#endif // GPIO_H
