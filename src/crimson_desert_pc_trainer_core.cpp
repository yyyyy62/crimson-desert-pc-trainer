#include "../include/crimson_desert_pc_trainer_runtime.hpp"
#include <windows.h>
#include <atomic>

namespace crimson_desert_pc_trainer {
static std::atomic<bool> g_running{true};
void PollHotkeys(bool& menu_open) noexcept {
    if (GetAsyncKeyState(VK_INSERT) & 1) menu_open = !menu_open;
    if (GetAsyncKeyState(VK_END) & 1) g_running.store(false, std::memory_order_relaxed);
}
} // namespace crimson_desert_pc_trainer

int main() {
    bool menu_open = true;
    while (crimson_desert_pc_trainer::g_running.load(std::memory_order_relaxed)) {
        crimson_desert_pc_trainer::PollHotkeys(menu_open);
        Sleep(6);
    }
    return 0;
}
