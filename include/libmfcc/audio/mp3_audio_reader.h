#pragma once


#include "audio_reader.h"

#include <filesystem>

namespace libmfcc::audio
{
    class Mp3AudioReader : public IAudioReader
    {
    public:
        AudioBuffer load(const std::filesystem::path& inputFile,
                         libmfcc::compat::source_location loc = libmfcc::compat::source_location::current()) override;
    };
}
