#ifndef MODE_DIRECTION_H
#define MODE_DIRECTION_H
#include <ModeAction.h>

class ModeDirection: public ModeAction
{
protected:
  int delta;
  int index = 0;
private:
  int ratePin;
  int minDelay;
  int maxDelay;
public:
  ModeDirection(const int _pins[N_PINS], int _ratePin, long _minDelay, long _maxDelay, int _delta);
  void next();
  void step();
};

#endif
