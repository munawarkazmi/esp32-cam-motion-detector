#include "accuracy_tracker.h"

void AccuracyTracker::startTrial(int durationSec) {
  trialMs  = durationSec * 1000UL;
  startMs  = millis();
  TP = FP = TN = FN = 0;
  running = true;
}

void AccuracyTracker::update(bool detected) {
  if (!running) return;

  // Synthetic ground truth: LED on 2 s every 6 s → 33 % motion
  bool groundTruth = (millis() % 6000UL) < 2000UL;

  if (groundTruth && detected)  TP++;
  else if (groundTruth && !detected) FN++;
  else if (!groundTruth && detected)  FP++;
  else                                 TN++;
}

bool AccuracyTracker::isTrialComplete() const {
  return running && (millis() - startMs >= trialMs);
}

void AccuracyTracker::printReport() const {
  uint32_t total = TP + FP + TN + FN;
  float accuracy = total ? 100.0f * (TP + TN) / total : 0.0f;

  Serial.println(F("\n========== ACCURACY REPORT =========="));
  Serial.printf("TP %lu  FP %lu  TN %lu  FN %lu\r\n", TP, FP, TN, FN);
  Serial.printf("Accuracy: %.1f %% (over %lu events)\r\n", accuracy, total);
  Serial.println(F("=====================================\r\n"));
}

void AccuracyTracker::reset() {
  running = false;
}
