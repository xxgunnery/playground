#include <iostream>
#include "raylib-cpp.hpp"

int screenWidth = 800;
int screenHeight = 450;

void UpdateDrawFrame(void);     // Update and Draw one frame

int main()
{
    raylib::Window window(screenWidth, screenHeight, "raylib-cpp [core] example - basic window");

    SetTargetFPS(60);

    // Define the camera to look into our 3d world
    raylib::Camera camera({ 0.2f, 0.4f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f);

    // Main game loop
    while (!window.ShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }

    return 0;
}


void UpdateDrawFrame(void)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first raylib-cpp window!", 160, 200, 20, LIGHTGRAY);

    EndDrawing();
}