#include <Arduino.h>
#include "controller.hpp"

#define BTWN(x, a, b) (a <= x && x <= b)

void setup(){
  Serial.begin(9600);
}

int c = 0;
c_event ev;

#define BYTES(x) ((byte*) &x, sizeof(x))

void loop(){
  c_event ev;
  if (BTWN(c, 0, 24))
    ev = EVENT(BTN_FLAPS_UP, DOWN);
  else if (BTWN(c, 25, 49))
    ev = EVENT(BTN_FLAPS_DOWN, DOWN);
  else if (BTWN(c, 50, 74))
    ev = EVENT(BTN_FIRE, DOWN);
  else if (BTWN(c, 75, 99))
    ev = EVENT(BTN_FIRE, UP);
  else if (BTWN(c, 100, 124))
    ev = EVENT(AXS_JOY, AXIS(512, 512)); // middle
  else if (BTWN(c, 125, 149))
    ev = EVENT(AXS_THROTTLE, AXIS(0, 200));

  Serial.write(BYTES(ev));
}

