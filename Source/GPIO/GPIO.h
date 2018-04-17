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

typedef struct IOStruct
{
    uint8_t pinAddr;
    uint8_t portAddr;
    uint8_t ddrAddr;
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
        _FG_PIN(D, 0),
        _FG_PIN(D, 1),
        _FG_PIN(D, 2),
        _FG_PIN(D, 3),
        _FG_PIN(D, 4),
        _FG_PIN(D, 5),
        _FG_PIN(D, 6),
        _FG_PIN(D, 7),
        _FG_PIN(B, 0),
        _FG_PIN(B, 1),
        _FG_PIN(B, 2),
        _FG_PIN(B, 3),
        _FG_PIN(B, 4),
        _FG_PIN(B, 5),
        _FG_PIN(C, 0),
        _FG_PIN(C, 1),
        _FG_PIN(C, 2),
        _FG_PIN(C, 3),
        _FG_PIN(C, 4),
        _FG_PIN(C, 5),
        _FG_PIN(C, 6), // RESET
        _FG_PIN(C, 7), // Null pin (IO_NONE)
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

    Pin(uint8_t pin);

    void setOutputToggle();
    void setOutput(bool value);
    void setAsInputPulledUp();
    void setAsInput();
    void setOutputLow();
    void setOutputHigh();
    bool getInput();



};

#endif //SOLDERINGSTATIONFIRMWARE_GPIO_H
