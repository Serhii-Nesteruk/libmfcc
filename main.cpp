#include "libmfcc/libmfcc.h"

#include <iostream>
#include <exception>
#include <filesystem>

#include "libmfcc/utils/path.h"

int main()
{
    try
    {
        const std::filesystem::path audioPath{"./data/common_voice_en_42698961.mp3"};
        libmfcc::MfccConfig config;
        config.useDeltas = true;
        config.useDeltaDeltas = true;

        auto mfcc = libmfcc::compute_file_mfcc(audioPath, config);
        std::cout << "Frames: " << mfcc.size() << std::endl;
        std::cout << "Coefficients per frame: " << (mfcc.empty() ? 0 : mfcc.front().size()) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Failed to compute MFCC: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
