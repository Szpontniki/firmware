#pragma once

#include <Adafruit_NeoPixel.h>

constexpr uint32_t LED_PIN = 2;
// TODO: this should probably be configurable later?
constexpr uint32_t LED_COUNT = 4;
constexpr uint32_t ANIMATION_DURATION_MS = 2000;
constexpr uint32_t ANIMATION_THROTTLE_MS = (ANIMATION_DURATION_MS / LED_COUNT);

extern Adafruit_NeoPixel PIXELS;

void setupLEDs();
