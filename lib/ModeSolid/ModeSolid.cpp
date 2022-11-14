#ifndef MODE_SOLID_I
#define MODE_SOLID_I
#include "ModeAction.h"
#include "ModeSolid.h"
#include <Arduino.h>

ModeSolid::ModeSolid(const int _pins[N_PINS]) : ModeAction(_pins)
{

}

long ModeSolid::next()
{
  for (int i = 0; i < N_PINS; i++) {
    digitalWrite(pins[i], HIGH);
  }
  return 0;
}

#endif
