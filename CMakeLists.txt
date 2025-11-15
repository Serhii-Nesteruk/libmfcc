cmake_minimum_required(VERSION 3.16)
project(libmfcc VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(THIRD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

set(LIBMfcc_SOURCES
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
        ${SRC_DIR}/features/delta.cpp

        # Facade
        ${SRC_DIR}/libmfcc.cpp
)

add_library(libmfcc ${LIBMfcc_SOURCES})
add_library(libmfcc::libmfcc ALIAS libmfcc)

target_include_directories(libmfcc
        PUBLIC
        $<BUILD_INTERFACE:${INC_DIR}>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${THIRD_DIR}/minimp3)

target_compile_features(libmfcc PUBLIC cxx_std_17)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(libmfcc PRIVATE -Wall -Wextra -pedantic)
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS libmfcc
        EXPORT libmfccTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

install(DIRECTORY ${INC_DIR}/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY ${THIRD_DIR}/minimp3/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/minimp3)

install(EXPORT libmfccTargets
        FILE libmfccTargets.cmake
        NAMESPACE libmfcc::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libmfcc)

configure_package_config_file(
        cmake/libmfccConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/libmfccConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libmfcc)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/libmfccConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/libmfccConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/libmfccConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libmfcc)

option(LIBMFCC_BUILD_EXAMPLES "Build libmfcc example executables" ON)
if (LIBMFCC_BUILD_EXAMPLES)
    add_executable(libmfcc_demo main.cpp)
    target_link_libraries(libmfcc_demo PRIVATE libmfcc::libmfcc)
    set_target_properties(libmfcc_demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

option(LIBMFCC_BUILD_TESTS "Build libmfcc tests" ON)
if (LIBMFCC_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()