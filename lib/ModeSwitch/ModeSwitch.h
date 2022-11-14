#ifndef MODESWITCH_H
#define MODESWITCH_H

#define N_MODES 4

enum mode
{
  MODE_A = 0,
  MODE_B = 1,
  MODE_C = 2,
  MODE_D = 3
};

class ModeSwitch
{
private:
  int pins[4];
public:
  ModeSwitch(const int _pins[4]);
  mode getCurrentMode() const;
};

#endif
