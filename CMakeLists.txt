cmake_minimum_required(VERSION 3.16)
project(libmfcc_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)
set(THIRD_DIR ${CMAKE_SOURCE_DIR}/third_party)

set(SOURCES
        # Audio
        ${SRC_DIR}/audio/wav_audio_reader.cpp
        ${SRC_DIR}/audio/mp3_audio_reader.cpp
        ${SRC_DIR}/minimp3_single.cpp

        # DSP
        ${SRC_DIR}/dsp/frame_exctractor.cpp
        ${SRC_DIR}/dsp/window_function.cpp
        ${SRC_DIR}/dsp/fft_transformer.cpp
        ${SRC_DIR}/dsp/dft_transformer.cpp

        # Features
        ${SRC_DIR}/features/mfcc.cpp
)

add_executable(libmfcc_demo
        main.cpp
        ${SOURCES}
)

target_include_directories(libmfcc_demo PRIVATE
        ${INC_DIR}
        ${THIRD_DIR}/minimp3
)

set_target_properties(libmfcc_demo PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(libmfcc_demo PRIVATE -Wall -Wextra -pedantic)
endif()
