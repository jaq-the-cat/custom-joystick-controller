#include <Arduino.h>

#define true 0x01
#define false 0x00

#define EVENT(type, data) ((c_event) {type, data})
#define AXIS(x, y) ((c_data) {.axis={x, y}})
#define UP         ((c_data) {.is_down=false})
#define DOWN       ((c_data) {.is_down=true})

typedef enum {
  // buttons
  BTN_FLAPS_DOWN,
  BTN_FLAPS_UP,
  BTN_FIRE,
  BTN_BOMB,
  BTN_BOMBS,
  BTN_BOMB_BAY,
  BTN_ROCKET,
  // axis
  AXS_JOY,
  AXS_THROTTLE,
  AXS_YAW,
} c_command_types;

typedef union {
  struct {
    int x, y;
  } axis;
  byte is_down; // 1 if down, 0 if release
} c_data;

typedef struct {
  c_command_types type;
  c_data data;
} c_event;
