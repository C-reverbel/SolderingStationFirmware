
#include <avr/io.h>
#include <util/delay.h>

#include "GPIO/GPIO.h"
#include "LCD/LCD.h"
/*
MICROCONTROLLER PINOUT
-----------------------------------------------
Net       | Pad   | Arduino Uno pin
-----------------------------------------------
BTN_1     | PD5   | 5
BTN_2     | PD6   | 6
ENC_A     | PB0   | 8
ENC_B     | PD7   | 7

LCD_RS    | PC2   | A2
LCD_EN    | PC3   | A3
LCD_DB4   | PC5   | A5
LCD_DB5   | PD0   | 0
LCD_DB6   | PC4   | A4
LCD_DB7   | PD1   | 1
-----------------------------------------------
 */


int main(){

    Pin rs(IO_C2);
    Pin en(IO_C3);
    Pin d4(IO_C5);
    Pin d5(IO_D0);
    Pin d6(IO_C4);
    Pin d7(IO_D1);

    Pin btn(5);
    Pin test(13);

    test.setOutputLow();

    btn.setAsInputPulledUp();

    LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
    lcd.begin(8,2);
    lcd.setCursor(0,0);
    lcd.print("S:350\337C ");
    lcd.setCursor(0,1);
    lcd.print("M:345\337C ");

    while(1){

    }
}

