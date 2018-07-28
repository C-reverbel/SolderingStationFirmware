#ifndef SOLDERINGSTATIONFIRMWARE_BUTTON_H
#define SOLDERINGSTATIONFIRMWARE_BUTTON_H

#include <stdint.h>
#include "utils/GPIO/GPIO.h"

class Button : public Pin{
public:
    Button(const uint8_t &pin);
    bool isPressed();

};


#endif //SOLDERINGSTATIONFIRMWARE_BUTTON_H
