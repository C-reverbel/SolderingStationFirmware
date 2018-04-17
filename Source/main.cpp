
#include <avr/io.h>
#include <util/delay.h>
#include "GPIO/GPIO.h"


int main(){

    Pin led(13);
    Pin btn_1(5);

    btn_1.setAsInputPulledUp();

    while(1){
        led.setOutput(btn_1.getInput());
    }
}


