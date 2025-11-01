#pragma once

#include "frame.h"
#include "audio_buffer.h"

#include <vector>

class IFrameExtractor
{
public:
    virtual ~IFrameExtractor() = default;
    virtual std::vector<Frame> extract(const AudioBuffer& audio) = 0;
};

class FixedFrameExtractor : public IFrameExtractor
{
public:
    FixedFrameExtractor(int windowSize, int hopSize);

    [[nodiscard]] std::vector<Frame> extract(const AudioBuffer& audio) override;
private:
    int _windowSize = 0, _hopSize = 0;
};