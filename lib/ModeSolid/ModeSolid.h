#ifndef MODE_SOLID_H
#define MODE_SOLID_H
#include "ModeAction.h"

class ModeSolid: public ModeAction
{
public:
  long next();
  ModeSolid(const int _pins[N_PINS]);
};

#endif
