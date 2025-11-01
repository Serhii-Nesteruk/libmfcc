#pragma once

#include <vector>

struct AudioBuffer {
    std::vector<float> samples; // normalized [-1.0, 1.0]
    int sampleRate;             // ex. 16000
};
