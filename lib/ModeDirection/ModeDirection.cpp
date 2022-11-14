#ifndef MODE_DIRECTION_I
#define MODE_DIRECTION_I
#include "ModeDirection.h"
#include <Arduino.h>

ModeDirection::ModeDirection(const int _pins[N_PINS], int _ratePin, long _minDelay, long _maxDelay, int _delta): ModeAction(_pins)
{
  delta = _delta;
  ratePin = _ratePin;
  minDelay = minDelay;
  maxDelay = maxDelay;
}

void ModeDirection::step()
{
  index = index + delta;
  if (index < 0) {
    index = N_PINS - 1;
  } else if (index >= N_PINS) {
    index = 0;
  }
}

void ModeDirection::next()
{
  int value = analogRead(ratePin);
  float rate = float(value) / 1023.0;
  long delayMillis = (maxDelay - minDelay) * rate + minDelay;
  delay(delayMillis);
  digitalWrite(pins[index], LOW);
  step();
  digitalWrite(pins[index], HIGH);
}

#endif
