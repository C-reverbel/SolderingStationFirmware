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
#include "PID/PID_v1.h"

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
 * PWM              OK -- OK p/ timer 1
 * ANALOG READ      OK
 * OTHER MENUS
 * PID              OK -- Falta testar
 */


int main(){

    uint16_t setTemp = 150;
    uint16_t mesTemp = 100;
    uint16_t pwmVal = 10;

    // PID INITIALIZATION
    double Setpoint, Input, Output;
    double Kp=2, Ki=5, Kd=1;
    PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

    // LCD INITIALIZATION
    //todo verificar se eh melhor passar os pinos como referencia
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

    // PWM INITIALIZATION
    FastPWMPin dimOut(OC1B);
    dimOut.startPWM(10e3);
    dimOut.setOutputHigh();
    dimOut.setPWMValue(pwmVal);

    // ADC INITIALIZATION
    AnalogPin ptc_read(IO_C0, SINGLE_CONVERSION);

    lcd.clear();
    appMenu.refreshScreen();

    while(1){
        _delay_ms(100);

        // update rotary encoder
        setTemp += rotEnc.update();
        if(setTemp > 400)
            setTemp = 400;
        else if (setTemp < 100)
            setTemp = 100;

        // read iron temperature and update display
        mesTemp = ptc_read.getAnalogValue();

        // calculate and set PWM value
        Setpoint = (double) setTemp;
        Input = (double) mesTemp;
        myPID.Compute();
        pwmVal = (float) Output;
        dimOut.setPWMValue(pwmVal);

        // refresh screen
        appMenu.refreshScreen();
    }
}
