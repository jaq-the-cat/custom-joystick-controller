#include <Arduino.h>
#include "controller.hpp"

#define YAW A0
#define THROTTLE A1
#define VRX A2
#define VRY A3

#define FIRE 5
#define BOMB 3
#define ROCKET 4
#define BAY 2

struct {
  int o, n;
} yaw_s, throttle_s, vrx_s, vry_s,
  fire_s, bomb_s, rocket_s, bay_s;

c_event ev;

void setup() {
  Serial.begin(9600);
}

#define BYTES(x) ((byte*) &x)

#define WRITE_EVENT(type_, data_)\
  ev = EVENT(data_, type_);\
  Serial.write(BYTES(ev.data), sizeof(c_data));\
  Serial.write(BYTES(ev.type), sizeof(byte))

void loop(){
  // Fire
  fire_s.n = digitalRead(FIRE);
  if (fire_s.n != fire_s.o) {
    // started pressing
    WRITE_EVENT(BTN_FIRE, (fire_s.n == HIGH) ? DOWN : UP);
  }
  fire_s.o = fire_s.n;

  // Bomb
  bomb_s.n = digitalRead(BOMB);
  if (bomb_s.n == HIGH && bomb_s.o == LOW) {
    WRITE_EVENT(BTN_BOMB, DOWN);
  }
  bomb_s.o = bomb_s.n;

  // Bombs

  
  // Rocket
  rocket_s.n = digitalRead(ROCKET);
  if (rocket_s.n == HIGH && rocket_s.o == LOW) {
    WRITE_EVENT(BTN_ROCKET, DOWN);
  }
  rocket_s.o = rocket_s.n;

  // Joystick
  vrx_s.n = analogRead(VRX);
  vry_s.n = analogRead(VRY);
  if (vrx_s.n != vrx_s.o || vry_s.n != vry_s.o) {
    WRITE_EVENT( 
      AXS_JOY,
      AXIS(vrx_s.n, vry_s.n));

    vrx_s.o = vrx_s.n;
    vry_s.o = vry_s.n;
  }

  // Throttle
  throttle_s.n = analogRead(THROTTLE);
  if (throttle_s.n != throttle_s.o) {
    WRITE_EVENT(
        AXS_THROTTLE,
        AXIS(0, throttle_s.n));

    throttle_s.o = throttle_s.n;
  }

  // Yaw
  yaw_s.n = analogRead(YAW);
  if (yaw_s.n != yaw_s.o) {
    WRITE_EVENT(
        AXS_YAW,
        AXIS(yaw_s.n, 0));

    yaw_s.o = yaw_s.n;
  }
}
