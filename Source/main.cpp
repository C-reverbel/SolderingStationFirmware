#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "GPIO/GPIO.h"
#include "GPIO/FastPWMPin.h"
#include "GPIO/AnalogPin.h"
#include "LCD/LCD.h"
#include "Menu/Menu.h"
#include "Menu/ApplicationMenu.h"
#include "Menu/SelectionMenu.h"
#include "USER_IO/RotaryEncoder.h"
#include "USER_IO/Button.h"
#include "PID/PID_v1.h"

#include "Menu/MenuView.h"
#include "Menu/MenuController.h"
#include "Menu/MenuModel.h"

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

 LCD_TO_ARDUINO CONNECTIONS (for development)
-----------------------------------------------
              __________________________
 1      A4   |  ______________________  |
 0      A5   | |                      | |
 NC     NC   | |                      | |
 NC     NC   | |                      | |
 A3     GND  | |                      | |
 A2     GND  | |______________________| |
 5V     GND  |__________________________|
 */

/*
 * TODO
 * edit selectionMenu to be compatible with MenuView
 * finish handle user IO
 */

int main(){
    // LCD INITIALIZATION
    //todo verificar se eh melhor passar os pinos como referencia
    Pin rs(IO_C2);
    Pin en(IO_C3);
    Pin d4(IO_C5);
    Pin d5(IO_D0);
    Pin d6(IO_C4);
    Pin d7(IO_D1);
    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
    // ROTARY ENCODER INITIALIZATION
    Pin rotA(IO_B0);
    Pin rotB(IO_D7);
    RotaryEncoder rotEnc(&rotA, &rotB);
    // BUTTONS INITIALIZATION
    Button btn1(IO_D5);
    Button btn2(IO_D6);
    // ADC INITIALIZATION
    AnalogPin ptcRead(IO_C0, SINGLE_CONVERSION);
    // PWM INITIALIZATION
    FastPWMPin dimOut(OC1B);
    // MENU VIEW INITIALIZATION
    MenuView menuView(&lcd, &btn1, &btn2, &rotEnc);
    MenuModel menuModel(&ptcRead, &dimOut);
    MenuController menuController(&menuView, &menuModel);

    while(1){
        _delay_ms(100);

        menuController.handleUserInput();
        menuController.updatePWMValue();
        menuController.refreshScreen();
    }
}