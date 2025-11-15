#pragma once

#include "libmfcc/config.h"

namespace libmfcc::features {

    [[nodiscard]] MfccMatrix computeDelta(const MfccMatrix& mfcc, int N = 2);
    [[nodiscard]] MfccMatrix computeDeltaDelta(const MfccMatrix& mfcc, int N = 2);
    [[nodiscard]] MfccMatrix appendDeltas(
        const MfccMatrix& base,
        bool useDelta,
        bool useDeltaDelta,
        int N = 2
    );

}