#pragma once
#include <Arduino.h>

class AccuracyTracker {
public:
  explicit AccuracyTracker() = default;

  void startTrial(int durationSec = 30);
  void update(bool detected);
  bool isTrialComplete() const;
  void printReport() const;
  void reset();

private:
  uint32_t trialMs{0};
  uint32_t startMs{0};
  uint32_t TP{0}, FP{0}, TN{0}, FN{0};
  bool     running{false};
};
