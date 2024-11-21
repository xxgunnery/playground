#include "raylib.h"

#include <iostream>
#include <string>

#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

struct GameFont
{
    Font LoadedFont;
    int Size;
};

class ResourceManager
{
private:
    void LoadText();
    void LoadModels();

public:
    int smallFontSize = 24;
    int mediumFontSize = 32;
    int bigFontSize = 48;

    GameFont SmallText;
    GameFont MediumText;
    GameFont BigText;

    Model model;
    ModelAnimation *animations;

    void LoadBasicResources();
};

#endif