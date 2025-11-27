#include "frame_downsampler.h"

FrameDownsampler::FrameDownsampler(int srcW, int srcH, int dstW, int dstH, int blockSize)
    : srcW(srcW), srcH(srcH), dstW(dstW), dstH(dstH), blockSize(blockSize) {}

void FrameDownsampler::init() {
  // No dynamic allocation – everything is const
  // Kept for API symmetry with other classes
}

void FrameDownsampler::downsample(const uint8_t* src, uint16_t dst[][16]) const {
  for (int y = 0; y < dstH; ++y) {
    for (int x = 0; x < dstW; ++x) {
      uint32_t sum = 0;
      const int startY = y * blockSize;
      const int startX = x * blockSize;

      for (unsigned int dy = 0; dy < blockSize && (startY + dy) < srcH; ++dy) {
        for (unsigned int dx = 0; dx < blockSize && (startX + dx) < srcW; ++dx) {
          sum += src[(startY + dy) * srcW + (startX + dx)];
        }
      }
      dst[y][x] = sum / (blockSize * blockSize); // floor division intended
    }
  }
}
