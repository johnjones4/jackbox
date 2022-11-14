#ifndef MODESWITCH_I
#define MODESWITCH_I
#include <Arduino.h>
#include "ModeSwitch.h"

ModeSwitch::ModeSwitch(const int _pins[4])
{
  for (int i = 0; i < N_MODES; i++)
  {
    pins[i] = _pins[i];
    pinMode(_pins[i], INPUT_PULLUP);
  }
}

mode ModeSwitch::getCurrentMode() const
{
  for (int i = 0; i < N_MODES; i++)
  {
    if (digitalRead(pins[i]) == LOW)
    {
      return mode(i);
    }
  }
  return mode::MODE_A;
}

#endif
