#pragma once

#include <filesystem>

#include "libmfcc/compat/source_location.h"

namespace libmfcc::utils {

    inline std::filesystem::path resolve_from_callsite(
        const std::filesystem::path& p,
        libmfcc::compat::source_location loc = libmfcc::compat::source_location::current())
    {
        if (p.is_absolute()) return std::filesystem::weakly_canonical(p);

        const std::filesystem::path call_file{loc.file_name()};
        const std::filesystem::path call_dir = call_file.parent_path();

        const auto candidate = std::filesystem::weakly_canonical(call_dir / p);

        if (std::filesystem::exists(candidate)) return candidate;

        const auto fallback = std::filesystem::weakly_canonical(std::filesystem::current_path() / p);
        return fallback;
    }

}
