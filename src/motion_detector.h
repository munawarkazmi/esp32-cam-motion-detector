#pragma once
#include <stdint.h>

class MotionDetector {
public:
  explicit MotionDetector(float threshold = 0.40f);
  void init();

  // 16 × 12 grid for this project 
  bool detect(const uint16_t frame[12][16]) const;

private:
  const float threshold;

  // Downsampled frame (16 columns × 12 rows = 192 values → ~384 bytes)
  uint16_t previous[12][16] = {};

  bool firstFrame{true};
};
