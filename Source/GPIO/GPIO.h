//
// Created by carlos on 17/04/2018.
//

#ifndef SOLDERINGSTATIONFIRMWARE_GPIO_H
#define SOLDERINGSTATIONFIRMWARE_GPIO_H

#pragma once
#include <avr/io.h>
#include <stdint.h>

/* Pin class
 *
 * set a pin as input (with or without pull-up)
 * set a pin as output
 * get pin current value
 * get pin full status (input/output, pull-up/no pull-up, pin current value)
*/

/** @cond */
#define _FG_SBI(mem_addr, bit) asm volatile("sbi %0, %1\n" : \
    : "I" (mem_addr - __SFR_OFFSET), "I" (bit))
#define _FG_CBI(mem_addr, bit) asm volatile("cbi %0, %1\n" : \
    : "I" (mem_addr - __SFR_OFFSET), "I" (bit))
#define _FG_PIN(port, bit) { _SFR_MEM_ADDR(PIN##port), _SFR_MEM_ADDR(PORT##port), \
     _SFR_MEM_ADDR(DDR##port), bit }
/** @endcond */

#define IO_STRUCT_ENTRY(P, B) {&PIN##P, &PORT##P, &DDR##P, B}

typedef struct IOStruct
{
    volatile uint8_t* pinAddr;
    volatile uint8_t* portAddr;
    volatile uint8_t* ddrAddr;
    uint8_t bit;

    volatile uint8_t * pin() const
    {
        return (volatile uint8_t *)(uint16_t)pinAddr;
    }

    volatile uint8_t * port() const
    {
        return (volatile uint8_t *)(uint16_t)portAddr;
    }

    volatile uint8_t * ddr() const
    {
        return (volatile uint8_t *)(uint16_t)ddrAddr;
    }
} IOStruct;
/** @endcond */

const IOStruct pinStructs[] = {
        IO_STRUCT_ENTRY(D, 0),
        IO_STRUCT_ENTRY(D, 1),
        IO_STRUCT_ENTRY(D, 2),
        IO_STRUCT_ENTRY(D, 3),
        IO_STRUCT_ENTRY(D, 4),
        IO_STRUCT_ENTRY(D, 5),
        IO_STRUCT_ENTRY(D, 6),
        IO_STRUCT_ENTRY(D, 7),
        IO_STRUCT_ENTRY(B, 0),
        IO_STRUCT_ENTRY(B, 1),
        IO_STRUCT_ENTRY(B, 2),
        IO_STRUCT_ENTRY(B, 3),
        IO_STRUCT_ENTRY(B, 4),
        IO_STRUCT_ENTRY(B, 5),
        IO_STRUCT_ENTRY(C, 0),
        IO_STRUCT_ENTRY(C, 1),
        IO_STRUCT_ENTRY(C, 2),
        IO_STRUCT_ENTRY(C, 3),
        IO_STRUCT_ENTRY(C, 4),
        IO_STRUCT_ENTRY(C, 5),
        IO_STRUCT_ENTRY(C, 6), // RESET
        IO_STRUCT_ENTRY(C, 7), // Null pin (IO_NONE)
};

#define IO_D0 0
#define IO_D1 1
#define IO_D2 2
#define IO_D3 3
#define IO_D4 4
#define IO_D5 5
#define IO_D6 6
#define IO_D7 7
#define IO_B0 8
#define IO_B1 9
#define IO_B2 10
#define IO_B3 11
#define IO_B4 12
#define IO_B5 13
#define IO_C0 14
#define IO_C1 15
#define IO_C2 16
#define IO_C3 17
#define IO_C4 18
#define IO_C5 19
#define IO_C6 20
#define IO_NONE 21


class Pin{
private:
    uint8_t _pin;

    void setOutputValueToggle();
    void setOutputValue(bool value);
public:

    //static Pin none;

    Pin& operator=(bool state) {
        setOutput(state);
        return *this;
    }

    Pin(uint8_t pin);

    bool isValidPin();
    void setOutputToggle();
    void setOutput(bool value);
    void setAsInputPulledUp();
    void setAsInput();
    void setOutputLow();
    void setOutputHigh();
    bool getInput();



};

#endif //SOLDERINGSTATIONFIRMWARE_GPIO_H
