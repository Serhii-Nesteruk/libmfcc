#pragma once

#include "libmfcc/config.h"
#include "libmfcc/dsp/frame.h"
#include "libmfcc/dsp/transformer.h"

#include <vector>

namespace libmfcc::features
{
    struct MfccOptions
    {
        int sampleRate = 16000;
        int numFilters = 26;
        int numCoeffs = 13;
        double minFreq = 0.0;
        double maxFreq = 8000.0;
        bool includeEnergy = true;
        MelScale melScale = MelScale::Slaney;
    };

    [[nodiscard]] double hzToMel(double hz, MelScale scale);
    [[nodiscard]] double melToHz(double mel, MelScale scale);

    [[nodiscard]] MfccMatrix computeMFCC(const std::vector<libmfcc::dsp::Frame>& frames,
                       const libmfcc::dsp::ITransformer& transformer,
                       const MfccOptions& options);
}