#pragma once
#include <cstdint>

namespace crimson_desert_pc_trainer {
inline constexpr const char* kModuleName = "crimson-desert-pc-trainer";
inline constexpr const char* kBuildSalt = "cdced3d4e80a4bbf";
struct RuntimeConfig {
    uint32_t target_fps = 144;
    float fov_radius = 65.0f;
    float smooth_factor = 1.45f;
    bool draw_bounds = true;
};
} // namespace crimson_desert_pc_trainer
