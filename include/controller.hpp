#include <Arduino.h>

#define true 0x01
#define false 0x00

#define EVENT(data, type) ((c_event) {data, type})
#define AXIS(x, y) ((c_data) {.axis={(int16_t) x, (int16_t) y}})
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
    int16_t x, y;
  } axis;
  byte is_down; // 1 if down, 0 if release
} c_data;

typedef struct {
  c_data data;
  byte type;
} c_event;
