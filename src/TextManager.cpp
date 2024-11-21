#include "../include/TextManager.h"

void DrawTextWithManager(GameFont font, std::string Text, Vector2 position, Color color)
{
    DrawTextEx(font.LoadedFont, Text.c_str(), position, font.Size, 0, color);
}
