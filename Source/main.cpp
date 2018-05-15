
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "GPIO/GPIO.h"
#include "GPIO/FastPWMPin.h"
#include "GPIO/AnalogPin.h"
#include "LCD/LCD.h"
#include "Menu/Menu.h"
#include "Menu/ApplicationMenu.h"
#include "USER_IO/RotaryEncoder.h"
/*
MICROCONTROLLER PINOUT
-----------------------------------------------
Net       | Pad         | Arduino Uno pin
-----------------------------------------------
PTC_READ  | PC0         | A0
DimOut    | PB2/OC1B    | 10 (OC1B)

BTN_1     | PD5         | 5
BTN_2     | PD6         | 6
ENC_A     | PB0         | 8
ENC_B     | PD7         | 7

LCD_RS    | PC2         | A2
LCD_EN    | PC3         | A3
LCD_DB4   | PC5         | A5
LCD_DB5   | PD0         | 0
LCD_DB6   | PC4         | A4
LCD_DB7   | PD1         | 1
-----------------------------------------------

 LCD_TO_ARDUINO CONNECTIONS
-----------------------------------------------
 1      A4
 0      A5
 NC     NC
 NC     NC
 A3     GND
 A2     GND
 5V     GND
 */

/*
 * TODO
 * TIMER
 * PWM              OK
 * ANALOG READ
 * OTHER MENUS
 * PID
 */


int main(){

    uint16_t setTemp = 300;
    uint16_t mesTemp = 350;

    // LCD INITIALIZATION
    Pin rs(IO_C2);
    Pin en(IO_C3);
    Pin d4(IO_C5);
    Pin d5(IO_D0);
    Pin d6(IO_C4);
    Pin d7(IO_D1);

    LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

    // ROTARY ENCODER INITIALIZATION
    Pin rotA(IO_B0);
    Pin rotB(IO_D7);

    RotaryEncoder rotEnc(&rotA, &rotB);

    // BUTTONS INITIALIZATION
    Pin btn1(IO_D5);
    Pin btn2(IO_D6);

    btn1.setAsInputPulledUp();
    btn2.setAsInputPulledUp();

    // MENUS INITIALIZATION
    Menu::attachLCD(&lcd);
    ApplicationMenu appMenu(&setTemp, &mesTemp);


    //todo tirar isso
    FastPWMPin dimOut(OC1B);
    dimOut.startPWM(10e3);
    dimOut.setOutputHigh();

    float pwmVal = 50;

    dimOut.setPWMValue(pwmVal);
    //setTemp = dimOut.pwmParameters.top;

    //todo tirar isso
    AnalogPin ptc_read(IO_C0, FREE_RUNNING);





    appMenu.refreshScreen();

    while(1){

        _delay_ms(100);
        rotEnc.updateState();
        switch (rotEnc.rotaryState){
            case RotaryEncoder::RotaryState::UP:
                pwmVal++;
                break;
            case RotaryEncoder::RotaryState::DOWN:
                pwmVal--;
                break;
            case RotaryEncoder::RotaryState::UP_FAST:
                pwmVal = pwmVal + 10;
                break;
            case RotaryEncoder::RotaryState::DOWN_FAST:
                pwmVal = pwmVal - 10;
                break;
        }
        if(pwmVal > 100)
            pwmVal = 100;
        else if (pwmVal < 0)
            pwmVal = 0;
        dimOut.setPWMValue(pwmVal);
        setTemp = ptc_read.getAnalogValue();
        appMenu.refreshScreen();


//
//        _delay_ms(100);
//        rotEnc.updateState();
//        switch (rotEnc.rotaryState){
//            case RotaryEncoder::RotaryState::UP:
//                setTemp++;
//                break;
//            case RotaryEncoder::RotaryState::DOWN:
//                setTemp--;
//                break;
//            case RotaryEncoder::RotaryState::UP_FAST:
//                setTemp = setTemp + 10;
//                break;
//            case RotaryEncoder::RotaryState::DOWN_FAST:
//                setTemp = setTemp - 10;
//                break;
//        }
//        appMenu.refreshScreen();

    }
}
