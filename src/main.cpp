#include <Arduino.h>
#include "controller.hpp"

#define P_YAW A0

#define BTWN(x, a, b) (a <= x && x <= b)

int counter = 0;
c_event ev;

void setup(){
  Serial.begin(9600);
}

#define BYTES(x) ((byte*) &x)

void loop(){
  c_event ev;

  int16_t yaw = analogRead(P_YAW);
  if (yaw >= 668)
    yaw = 670;
  //ev = EVENT(AXIS(yaw, 0), AXS_YAW);
  ev = EVENT(DOWN, BTN_BOMB_BAY);

  Serial.write(BYTES(ev.data), sizeof(c_data));
  Serial.write(BYTES(ev.type), sizeof(byte));
}

