#pragma once
#include <stdint.h>

class FrameDownsampler {
public:
  FrameDownsampler(int srcW, int srcH, int dstW, int dstH, int blockSize);
  void init();

  // Fixed 16×12 grid for this project → matches the rest of the code perfectly
  void downsample(const uint8_t* src, uint16_t dst[12][16]) const;

  // All parameters are const – they never change after construction
  const int srcW;
  const int srcH;
  const int dstW  = 16;
  const int dstH  = 12;
  const int blockSize;
};
