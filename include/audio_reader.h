#pragma once
#include <string>
#include "audio_buffer.h"

class IAudioReader {
public:
    virtual ~IAudioReader() = default;
    virtual AudioBuffer load(const std::string& path) = 0;
};

