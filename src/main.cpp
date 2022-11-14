#include <Arduino.h>
#include <ModeAction.h>
#include <ModeBounce.h>
#include <ModeDirection.h>
#include <ModeSolid.h>
#include <ModeSwitch.h>

const int inputPins[N_MODES] = {2,3,4,5};
ModeSwitch selector(inputPins);

#define RATE_PIN A0
#define MIN_DELAY 10
#define MAX_DELAY 1000

const int outputPins[N_PINS] = {8,9,10,11};
ModeSolid solid(outputPins);
ModeDirection forward(outputPins, RATE_PIN, MIN_DELAY, MAX_DELAY, 1);
ModeDirection backwards(outputPins, RATE_PIN, MIN_DELAY, MAX_DELAY, -1);
ModeBounce bounce(outputPins, RATE_PIN, MIN_DELAY, MAX_DELAY);

long delayMillis = 0;
long lastNext = 0;
mode lastMode = mode::MODE_A;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  long now = millis();
  mode m = selector.getCurrentMode();
  if (m != lastMode || now - lastNext >= delayMillis) {
    lastNext = now;
    switch (m)
    {
    case mode::MODE_A:
      delayMillis = solid.next();
      break;
    case mode::MODE_B:
      delayMillis = forward.next();
      break;
    case mode::MODE_C:
      delayMillis = backwards.next();
      break;
    case mode::MODE_D:
      delayMillis = bounce.next();
      break;
    }
  }
}

