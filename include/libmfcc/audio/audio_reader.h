#pragma once

#include "audio_buffer.h"

#include <filesystem>
#include <source_location>

#include "libmfcc/compat/source_location.h"

namespace libmfcc::audio
{
    class IAudioReader
    {
    public:
        virtual ~IAudioReader() = default;
        virtual AudioBuffer load(const std::filesystem::path& inputFile,
                                 libmfcc::compat::source_location loc = libmfcc::compat::source_location::current()) = 0;
    };
}
