#include "../include/ResourceManager.h"

void ResourceManager::LoadBasicResources()
{
    LoadText();
    LoadModels();
}

void ResourceManager::LoadText()
{
    std::cout << "Loading fonts!" << std::endl;

    Font smallFont = LoadFontEx("assets/fonts/itim/Itim-Regular.ttf", 24, NULL, 0);
    Font mediumFont = LoadFontEx("assets/fonts/itim/Itim-Regular.ttf", 32, NULL, 0);
    Font bigFont = LoadFontEx("assets/fonts/itim/Itim-Regular.ttf", 48, NULL, 0);

    std::cout << "Loaded fonts!" << std::endl;

    SmallText.LoadedFont = smallFont;
    SmallText.Size = smallFontSize;

    MediumText.LoadedFont = mediumFont;
    MediumText.Size = mediumFontSize;

    BigText.LoadedFont = bigFont;
    BigText.Size = bigFontSize;
}

void ResourceManager::LoadModels()
{
    bool useM3d = false;

    std::string extension = useM3d ? ".m3d" : ".glb";
    std::string modelPath = "assets/models/deer" + extension;

    model = LoadModel(modelPath.c_str()); // Load model from file

    animations = LoadModelAnimations(modelPath.c_str(), &animsCount); // Load model animations from file
}