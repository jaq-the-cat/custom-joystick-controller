#include <Arduino.h>
#include "controller.hpp"

#define BTWN(x, a, b) (a <= x && x <= b)

int counter = 0;
c_event ev;

void setup(){
  Serial.begin(9600);
}

#define BYTES(x) ((byte*) &x)

void loop(){
  c_event ev;
  if (BTWN(counter, 0, 24))
    ev = EVENT(DOWN, BTN_FLAPS_UP);
  else if (BTWN(counter, 25, 49))
    ev = EVENT(DOWN, BTN_FLAPS_DOWN);
  else if (BTWN(counter, 50, 74))
    ev = EVENT(DOWN, BTN_FIRE);
  else if (counter == 75)
    ev = EVENT(UP, BTN_FIRE);
  //else if (BTWN(counter, 76, 124))
    //ev = EVENT(AXS_JOY, AXIS(512, 512)); // middle
  //else if (BTWN(counter, 125, 149))
    //ev = EVENT(AXS_THROTTLE, AXIS(0, 200));
  else
    counter = 0;

  counter++;

  Serial.write(BYTES(ev.data), sizeof(c_data));
  Serial.write(BYTES(ev.type), sizeof(byte));

  delay(100);
}

