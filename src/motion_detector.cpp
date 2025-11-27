#include "motion_detector.h"
#include <string.h>      // for memcpy
#include <stdlib.h>      // for abs()
#include <algorithm>

MotionDetector::MotionDetector(float threshold)
    : threshold(threshold), firstFrame(true) {
  memset(previous, 0, sizeof(previous));
}

void MotionDetector::init() {
  memset(previous, 0, sizeof(previous));
  firstFrame = true;
}

bool MotionDetector::detect(const uint16_t frame[12][16]) {
  if (firstFrame) {
    memcpy(previous, frame, sizeof(previous));
    firstFrame = false;
    return false;
  }

  int changes = 0;
  const int totalCells = 12 * 16;

  for (int y = 0; y < 12; ++y) {
    for (int x = 0; x < 16; ++x) {
      int diff = abs(static_cast<int>(frame[y][x]) - static_cast<int>(previous[y][x]));
      // Avoid division by zero and use percentage change (robust to lighting)
      float percentChange = diff / static_cast<float>(std::max(previous[y][x], 1u));

      if (percentChange > threshold) {
        ++changes;
      }
    }
  }

  // Copy current frame to previous for next iteration
  memcpy(previous, frame, sizeof(previous));

  // 1 % of cells changing = motion (field-tuned value)
  return (changes >= totalCells * 0.01f);
}
