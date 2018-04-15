#include <avr/io.h>
#include <util/delay.h>

#include "GPIO/FastGPIO.h"
//#include "LCD/LiquidCrystal.h"


extern "C"
int main (void)
{
    const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
    //LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

    //lcd.begin(8,2);

    FastGPIO::Pin<13>::setOutput(0);
    FastGPIO::Pin<5>::setInputPulledUp();




    while(1) {
        FastGPIO::Pin<13>::setOutputValue(FastGPIO::Pin<5>::isInputHigh());

    }
}