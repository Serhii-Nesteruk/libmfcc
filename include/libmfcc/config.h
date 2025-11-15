#pragma once

#include <vector>

namespace libmfcc {

    enum class MelScale {
        HTK,
        Slaney
    };

    struct MfccConfig {
        int sampleRate                 = 16000;         // Hz
        int frameSize                  = 400;           // samples per frame
        int frameStep                  = 160;           // hop size in samples
        int numCoeffs                  = 13;            // number of cepstral coefficients
        int numFilters                 = 26;            // mel filters in filter bank
        float minFreq                  = 0.0f;          // Hz
        float maxFreq                  = 8000.0f;       // Hz (clamped to Nyquist)
        bool includeEnergy             = true;          // prepend log-energy as c0
        bool useDeltas                 = false;         // append delta coefficients
        bool useDeltaDeltas            = false;         // append delta-delta coefficients
        bool usePreEmphasis            = true;          // apply pre-emphasis
        float preEmphasisCoeff         = 0.97f;
        MelScale melScale              = MelScale::Slaney;
    };

    using MfccVector = std::vector<float>;
    using MfccMatrix = std::vector<MfccVector>;

}