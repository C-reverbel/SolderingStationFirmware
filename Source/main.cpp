#define HIGH 1
#define LOW 0


#include "LCD/LCD.h"
#include "GPIO/FastGPIO.h"

template <uint8_t pin>
void setPinHigh(FastGPIO::Pin<pin> pino){
    pino.setOutputHigh();
}
template <uint8_t pin>
void setPinLow(FastGPIO::Pin<pin> pino){
    pino.setOutputLow();
}

int main(){
    FastGPIO::Pin<13> led;
    FastGPIO::Pin<5> btn_1;

    LiquidCrystal<FastGPIO::Pin<13>><> lcd(led,btn_1);



    //btn_1.setInputPulledUp();

    //setPinLow(led);


    while(1){
        //led.setOutput(btn_1.isInputHigh());
    }
}


