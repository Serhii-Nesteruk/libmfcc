#include "libmfcc/audio/mp3_audio_reader.h"
#include "libmfcc/dsp/frame_extractor.h"
#include "libmfcc/features/mfcc.h"
#include "libmfcc/dsp/dft_transformer.h"
#include "libmfcc/dsp/fft_transformer.h"
#include "libmfcc/dsp/window_functiion.h"

#include <iostream>
#include <filesystem>

int main() {
    using namespace libmfcc;

    std::filesystem::path inputFile("./data/common_voice_en_42698961.mp3");
    audio::Mp3AudioReader reader;
    auto audio = reader.load(inputFile);

    dsp::FixedFrameExtractor extractor(400, 160);
    auto frames = extractor.extract(audio);

    dsp::HammingWindow window(400);
    for (auto& f : frames) window.apply(f.data);

    dsp::FFTTransformer fft;
    dsp::DFTTransformer dft;

    auto mfcc_fft = features::computeMFCC(frames, audio.sampleRate, fft);
    auto mfcc_dft = features::computeMFCC(frames, audio.sampleRate, dft);

    std::cout << "FFT MFCC frames: " << mfcc_fft.size() << "\n";
    std::cout << "DFT MFCC frames: " << mfcc_dft.size() << "\n";

    return 0;
}
