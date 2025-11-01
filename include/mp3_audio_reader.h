#pragma once

#include "audio_reader.h"

class Mp3AudioReader : public IAudioReader {
public:
    AudioBuffer load(const std::string& path) override;
};
