#ifndef SOLDERINGSTATIONFIRMWARE_MAIN_H
#define SOLDERINGSTATIONFIRMWARE_MAIN_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "utils/GPIO/GPIO.h"
#include "utils/GPIO/FastPWMPin.h"
#include "utils/GPIO/AnalogPin.h"
#include "utils/LCD/LCD.h"
#include "utils/PID/PID_v1.h"

#include "frontend/USER_IO/RotaryEncoder.h"
#include "frontend/USER_IO/Button.h"
#include "frontend/MenuStructure/MenuItem.h"
#include "frontend/MenuStructure/rootMenu/RootMenu.h"
#include "frontend/MenuStructure/rootMenu/appMenu/AppMenu.h"
#include "frontend/MenuStructure/rootMenu/optionsMenu/OptionsMenu.h"
#include "frontend/MenuStructure/rootMenu/optionsMenu/MinTempOption.h"

#include "backend/Backend.h"
#include "frontend/Frontend.h"

#endif //SOLDERINGSTATIONFIRMWARE_MAIN_H
