#pragma once

#include "audio_buffer.h"

#include <filesystem>

namespace libmfcc::audio
{
    class IAudioReader {
    public:
        virtual ~IAudioReader() = default;
        virtual AudioBuffer load(const std::filesystem::path& inputFile) = 0;
    };
}