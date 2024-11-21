#define GRAPHICS_API_OPENGL_33

#include <string>
#include <iostream>

#include "../include/Game.h"

int main()
{
    std::cout << "Starting game..." << std::endl;

    Game Game;
    Game.Init();

    while (!WindowShouldClose())
    {
        Game.Update();
    }

    Game.Cleanup();
    CloseWindow();

    return 0;
}
