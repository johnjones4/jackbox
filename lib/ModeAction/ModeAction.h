#ifndef MODE_ACTION_H
#define MODE_ACTION_H

#define N_PINS 4

class ModeAction
{
protected:
  int pins[N_PINS];
public:
  ModeAction(const int _pins[N_PINS]);
  void next();
};

#endif
