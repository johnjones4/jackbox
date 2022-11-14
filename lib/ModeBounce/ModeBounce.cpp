#ifndef MODE_BOUNCE_I
#define MODE_BOUNCE_I
#include <ModeBounce.h>

ModeBounce::ModeBounce(const int _pins[N_PINS], int _ratePin, long _minDelay, long _maxDelay) : ModeDirection(_pins, _ratePin, _minDelay, _maxDelay, 1)
{

}

void ModeBounce::step()
{
  index = index + delta;
  if (index < 0) {
    index = 1;
    delta = -delta;
  } else if (index >= N_PINS) {
    index = N_PINS - 2;
    delta = -delta;
  }
}

#endif
