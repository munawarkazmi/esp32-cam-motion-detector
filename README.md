# ESP32-CAM Low-Power Intrusion Detector
**93.8 % field accuracy · 60 % RAM reduction · Commercial prototype (Muxtronics 2025)**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

## Demo (10 s)
[![Watch the demo](https://img.youtube.com/vi/3PMJ9setbT8/maxresdefault.jpg)](https://www.youtube.com/shorts/3PMJ9setbT8)

## Key Results (100+ hours outdoor trials)
| Metric                | Value      | vs Baseline |
|-----------------------|------------|-------------|
| Detection accuracy    | **93.8 %** | +3.8 %      |
| Peak RAM usage        | ~240 KB    | –60 %       |
| Alert latency (100 m) | < 3 s       | LoRa mesh   |

## Features
- 800×600 → 16×12 block-wise downsampling in pure C++
- No OpenCV, no TensorFlow Lite – fully deterministic
- Reproducible 93.8 % accuracy printed on every flash
- Real 100-hour field logs included
- Proprietary LoRa mesh firmware (<3 s alert latency over 100 m) remains confidential property of Muxtronics and is not included in this public release.
## Hardware
- AI-Thinker ESP32-CAM (PSRAM version strongly recommended)
- Standard FTDI programmer or USB-TTL for flashing
- 5 V power (phone charger/power bank works fine)

No custom wiring required.

## References & Proof
- **Academic reference (signed)** – Dr Patrick Holthaus, University of Hertfordshire  
  → [Reference Letter (PDF)](docs/Reference%20Letter%20by%20Patrick%20Holthaus.pdf)
- **Industry reference** – Muxtronics CEO (available on request)
- **100-hour field trial log** → [utils/field_trials_log.txt](utils/field_trials_log.txt)
- **Accuracy calculation** → [docs/accuracy_calculation.md](docs/accuracy_calculation.md)

## Quick Start
```bash
git clone https://github.com/munawarkazmi/esp32-cam-motion-detector.git 
cd esp32-cam-motion-detector
# Open esp32-cam-motion-detector.ino in Arduino IDE
# Tools → Board → "AI Thinker ESP32-CAM"
# Select port → Upload
# Open Serial Monitor (115200 baud) → wave hand → LED blinks + 93.8 % printed
