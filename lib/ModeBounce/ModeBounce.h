#ifndef MODE_BOUNCE_H
#define MODE_BOUNCE_H
#include <ModeDirection.h>

class ModeBounce: public ModeDirection
{
public:
  void step();
  ModeBounce(const int _pins[N_PINS], int _ratePin, long _minDelay, long _maxDelay);
};

#endif
