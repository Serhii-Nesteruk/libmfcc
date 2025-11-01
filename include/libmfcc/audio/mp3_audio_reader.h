#pragma once

#include <filesystem>

#include "audio_reader.h"

namespace libmfcc::audio
{
    class Mp3AudioReader : public IAudioReader
    {
    public:
        AudioBuffer load(const std::filesystem::path& inputFile) override;
    };
}
