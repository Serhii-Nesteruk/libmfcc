#include "../include/frame_extractor.h"

FixedFrameExtractor::FixedFrameExtractor(int windowSize, int hopSize)
    : _windowSize(windowSize), _hopSize(hopSize)
{
}

std::vector<Frame> FixedFrameExtractor::extract(const AudioBuffer& audio)
{
    std::vector<Frame> frames;
    const auto& x = audio.samples;
    const auto N = x.size();

    for (std::size_t i = 0; i + _windowSize<= N; i += _hopSize)
    {
        Frame f;
        f.data.resize(_windowSize);
        for (std::size_t j = 0; j < _windowSize; ++j)
            f.data[j] = x[i + j];
        frames.push_back(f);
    }

    return frames;
}
