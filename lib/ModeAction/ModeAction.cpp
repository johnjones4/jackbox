#ifndef MODE_ACTION_I
#define MODE_ACTION_I
#include "ModeAction.h"
#include <Arduino.h>

ModeAction::ModeAction(const int _pins[N_PINS])
{
  for (int i = 0; i < N_PINS; i++) {
    pins[i] = _pins[i];
    pinMode(pins[i], OUTPUT);
  }
}

long ModeAction::next() {
  return 0;
}

#endif
