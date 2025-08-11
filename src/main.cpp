#include <print>

#define RGFW_IMPLEMENTATION
#define RGFW_DEBUG
#include "RGFW.h"

auto main(int, char **) -> int
{
    RGFW_window *win = RGFW_createWindow(
        "metrobud", 0, 0, 800, 600, RGFW_windowCenter | RGFW_windowNoResize);
    while (RGFW_window_shouldClose(win) == RGFW_FALSE)
    {
        RGFW_pollEvents();
    }

    RGFW_window_close(win);

    return 0;
}
