/*
MICROCONTROLLER PINOUT
-----------------------------------------------
Net       | Pad         | Arduino Uno pin
-----------------------------------------------
PTC_READ  | PC0         | A0
DimOut    | OC1B (PB2)  | 10

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

#include "main.h"

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
    AnalogPin ptcPin(IO_C0, SINGLE_CONVERSION);
    // PWM INITIALIZATION
    FastPWMPin pwmPin(OC1B);
    // MENUS INITIALIZATION
    SolderingStationData applicationData;
    Backend backend(applicationData, ptcPin, pwmPin);
    Frontend frontend(&applicationData, &lcd, &btn1, &btn2, &rotEnc);

    /*
     * /utils
         * /GPIO
         * /LCD
         * /PID
         * /USER_IO
     * /backend
         *
     * /frontend
         * /menu
             * ...
     * /data
     */

    while(1){
        _delay_ms(150);
        backend.readIronTemperature();
        backend.updateTemperatureController();
        frontend.updateUserInputs();
        frontend.updateMenu();
    }
}
